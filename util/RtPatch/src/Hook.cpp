#include "Hook.h"

#include <g3sdk/util/Memory.h>

mCRestorable::mCRestorable()
{}

mCRestorable::~mCRestorable()
{
    Restore();
}

void mCRestorable::Backup(GELPVoid a_pAddress, GEUInt a_uDataSize)
{
    mSBackupItem BackupItem = {a_pAddress, malloc(a_uDataSize), a_uDataSize};
    ReadMemory(BackupItem.m_pOriginalData, BackupItem.m_pOriginalAddress, BackupItem.m_uOriginalDataSize);
    m_arrBackupItems.Add(BackupItem);
}

void mCRestorable::Restore()
{
    GE_ARRAY_FOR_EACH (BackupItem, m_arrBackupItems)
    {
        WriteMemory(BackupItem.m_pOriginalAddress, BackupItem.m_pOriginalData, BackupItem.m_uOriginalDataSize);
        free(BackupItem.m_pOriginalData);
    }
    m_arrBackupItems.Clear();
}

void mCRestorable::ApplyAsm(asmjit::x86::CodeAsm &a_Assembler, GEUInt a_u32ReplaceSize)
{
    Backup(reinterpret_cast<void *>(a_Assembler.GetCode().baseAddress()), a_u32ReplaceSize);
    G3SCRIPT_ASSERT(WriteAssemblerData(a_Assembler, a_u32ReplaceSize, false, true));
}

mCDataPatch::mCDataPatch(GEU32 a_uDataAddress, GELPCVoid a_pNewData, GEU32 a_uSize)
{
    Patch(a_uDataAddress, a_pNewData, a_uSize);
}

void mCDataPatch::Patch(GEU32 a_uDataAddress, GELPCVoid a_pNewData, GEU32 a_uSize)
{
    Backup(reinterpret_cast<GELPVoid>(a_uDataAddress), a_uSize);
    WriteMemory(reinterpret_cast<GELPVoid>(a_uDataAddress), a_pNewData, a_uSize);
}

mCCodePatch::mCCodePatch(GEU32 a_uAddress, GEU32 a_uReplaceSize, mFCodeSupplier a_CodeSupplier)
{
    Patch(a_uAddress, a_uReplaceSize, a_CodeSupplier);
}

void mCCodePatch::Patch(GEU32 a_uAddress, GEU32 a_uReplaceSize, mFCodeSupplier a_CodeSupplier)
{
    using namespace asmjit;
    using namespace asmjit::x86;

    x86::CodeAsm AsmCode(a_uAddress);
    a_CodeSupplier(AsmCode);

    // Skip the remaining code in the replace size range
    SkipCode(AsmCode, a_uReplaceSize);

    ApplyAsm(AsmCode, a_uReplaceSize);
}

mCSkipCode::mCSkipCode(GEU32 a_uAddress, GEU32 a_uSize)
{
    Backup(reinterpret_cast<GELPVoid>(a_uAddress), a_uSize);
    SkipCode(a_uAddress, a_uSize);
}

mCSkipFunction::mCSkipFunction(GEU32 a_uAddress, GEUInt a_uNumArgs)
{
    using namespace asmjit;
    using namespace asmjit::x86;

    x86::CodeAsm AsmCode(a_uAddress);
    AsmCode.ret(a_uNumArgs * 4);
    ApplyAsm(AsmCode, AsmCode.GetCode().codeSize());
}

mCSkipFunction::mCSkipFunction(GELPVoid a_uAddress, GEUInt a_uNumArgs)
    : mCSkipFunction(reinterpret_cast<GEU32>(a_uAddress), a_uNumArgs)
{}

mCRegisterBase::mCRegisterBase()
    : m_u32Eax(0), m_u32Ecx(0), m_u32Edx(0), m_u32Ebx(0), m_u32Ebp(0), m_u32Esi(0), m_u32Edi(0)
{}

asmjit::x86::Gp const &mCRegisterBase::ToX86Register(mERegisterType a_RegisterType)
{
    using namespace asmjit::x86;

    switch (a_RegisterType)
    {
    case mERegisterType_None: return esp;
    case mERegisterType_Eax:  return eax;
    case mERegisterType_Ecx:  return ecx;
    case mERegisterType_Edx:  return edx;
    case mERegisterType_Ebx:  return ebx;
    case mERegisterType_Ebp:  return ebp;
    case mERegisterType_Esi:  return esi;
    case mERegisterType_Edi:  return edi;
    default:                  return esp;
    }
}

GELPVoid mCBaseHook::m_pLastSelf = 0;

mCBaseHook::mCBaseHook() : m_pCode(0), m_pSelf(0), m_u32Ret(0)
{}

void mCBaseHook::DoRegisterMagic(asmjit::x86::CodeAsm &a_Assembler, mCHookParams const &a_HookParams)
{
    using namespace asmjit;
    using namespace asmjit::x86;

    switch (a_HookParams.m_HookType)
    {
    case mEHookType_OnlyStack: break;

    case mEHookType_ThisCall: {
        // save ecx
        a_Assembler.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_pSelf)), ecx);
        a_Assembler.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_pLastSelf)), ecx);

        if (m_pCode != 0)
        {
            // restore ecx
            x86::CodeAsm AsmRestoreEcx;
            AsmRestoreEcx.mov(ecx, dword_ptr_abs(reinterpret_cast<GEU64>(&m_pSelf)));
            AsmRestoreEcx.jmp(imm(reinterpret_cast<GEI64>(m_pCode)));
            m_pCode = JitRuntimeAdd(AsmRestoreEcx);
        }

        break;
    }

    case mEHookType_Mixed: {
        // save registers
        if (a_HookParams.m_RegisterType & mERegisterType_Eax)
            a_Assembler.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Eax)), eax);
        if (a_HookParams.m_RegisterType & mERegisterType_Ecx)
            a_Assembler.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ecx)), ecx);
        if (a_HookParams.m_RegisterType & mERegisterType_Edx)
            a_Assembler.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Edx)), edx);
        if (a_HookParams.m_RegisterType & mERegisterType_Ebx)
            a_Assembler.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ebx)), ebx);
        if (a_HookParams.m_RegisterType & mERegisterType_Ebp)
            a_Assembler.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ebp)), ebp);
        if (a_HookParams.m_RegisterType & mERegisterType_Esi)
            a_Assembler.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Esi)), esi);
        if (a_HookParams.m_RegisterType & mERegisterType_Edi)
            a_Assembler.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Edi)), edi);

        if (m_pCode != 0)
        {
            // restore hook function registers, after call to original function
            x86::CodeAsm AsmOnReturn;
            AsmOnReturn.mov(ebx, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32EbxRestore)));
            AsmOnReturn.mov(ebp, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32EbpRestore)));
            AsmOnReturn.mov(esi, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32EsiRestore)));
            AsmOnReturn.mov(edi, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32EdiRestore)));
            AsmOnReturn.jmp(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ret)));
            GELPVoid pRestoreHook = JitRuntimeAdd(AsmOnReturn);

            // overwrite return address, before calling original function
            x86::CodeAsm AsmPrepareCall;
            AsmPrepareCall.mov(eax, ptr(esp));
            AsmPrepareCall.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ret)), eax);
            AsmPrepareCall.mov(eax, imm(reinterpret_cast<GEI64>(pRestoreHook)));
            AsmPrepareCall.mov(ptr(esp), eax);
            // restore original function registers
            AsmPrepareCall.mov(eax, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Eax)));
            AsmPrepareCall.mov(ecx, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ecx)));
            AsmPrepareCall.mov(edx, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Edx)));
            AsmPrepareCall.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32EbxRestore)), ebx);
            AsmPrepareCall.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32EbpRestore)), ebp);
            AsmPrepareCall.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32EsiRestore)), esi);
            AsmPrepareCall.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32EdiRestore)), edi);
            AsmPrepareCall.mov(ebx, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ebx)));
            AsmPrepareCall.mov(ebp, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ebp)));
            AsmPrepareCall.mov(esi, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Esi)));
            AsmPrepareCall.mov(edi, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Edi)));
            AsmPrepareCall.jmp(imm(reinterpret_cast<GEI64>(m_pCode)));
            m_pCode = JitRuntimeAdd(AsmPrepareCall);
        }

        break;
    }
    }
}

void mCAbstractRegArgHook::PushArguments(asmjit::x86::CodeAsm &a_Assembler, mCAbstractRegArgHookParams const &a_Params,
                                         GEU32 a_u32AdditionalOffset)
{
    using namespace asmjit;
    using namespace asmjit::x86;

    GEU32 u32AdditionalOffset = a_u32AdditionalOffset;
    GE_ARRAY_FOR_EACH_REV (Arg, a_Params.m_arrStackArgs)
    {
        if (Arg.m_enuArgType == mCAbstractRegArgHookParams::mEArgType_RegDirect)
        {
            a_Assembler.push(ToX86Register(Arg.m_Register));

            GEU32 u32Offset = Arg.m_u32Offset;
            if (Arg.m_Register == mERegisterType_None) // esp
                u32Offset += u32AdditionalOffset;

            if (u32Offset != 0)
                a_Assembler.add(dword_ptr(esp), imm(u32Offset));
        }
        else if (Arg.m_enuArgType == mCAbstractRegArgHookParams::mEArgType_RegIndirect)
        {
            GEU32 u32Offset = Arg.m_u32Offset;
            if (Arg.m_Register == mERegisterType_None) // esp
                u32Offset += u32AdditionalOffset;

            a_Assembler.push(dword_ptr(ToX86Register(Arg.m_Register), u32Offset));
        }
        else if (Arg.m_enuArgType == mCAbstractRegArgHookParams::mEArgType_Immediate)
        {
            a_Assembler.push(imm(Arg.m_u32Immediate));
        }

        u32AdditionalOffset += 4;
    }
}

void mCAbstractFunctionHook::PushArgumentsBeforeEntry(asmjit::x86::CodeAsm &a_Assembler,
                                                      mCAbstractFunctionHookParams const &a_HookParams)
{
    using namespace asmjit;
    using namespace asmjit::x86;

    if (a_HookParams.m_bReplaceThis)
    {
        a_Assembler.mov(ecx, imm(a_HookParams.m_ReplaceThisValue));
    }

    if (!a_HookParams.m_arrStackArgs.IsEmpty())
    {
        // Optimize the common case of a this call
        if (a_HookParams.m_arrStackArgs.GetCount() == 1
            && a_HookParams.m_arrStackArgs[0].m_enuArgType == mCAbstractRegArgHookParams::mEArgType_RegDirect
            && a_HookParams.m_arrStackArgs[0].m_Register == mERegisterType_Ecx
            && a_HookParams.m_arrStackArgs[0].m_u32Offset == 0)
        {
            a_Assembler.xchg(dword_ptr(esp), ecx);
            a_Assembler.push(ecx);
        }
        else
        {
            // Move saved return address to make room for arguments
            a_Assembler.xchg(dword_ptr(esp), eax);
            a_Assembler.mov(dword_ptr(esp, a_HookParams.m_arrStackArgs.GetCount() * -4), eax);
            a_Assembler.mov(eax, dword_ptr(esp));
            a_Assembler.add(esp, 4);
            PushArguments(a_Assembler, a_HookParams);
            a_Assembler.sub(esp, 4);
        }
    }
}

GEBool mCAbstractFunctionHook::RestoreArgumentsBeforeCall(asmjit::x86::CodeAsm &a_Assembler,
                                                          mCAbstractFunctionHookParams const &a_HookParams)
{
    using namespace asmjit;
    using namespace asmjit::x86;

    if (!a_HookParams.m_arrStackArgs.IsEmpty())
    {
        bTPtrArray<mCAbstractFunctionHookParams::mSRegRelativeArg const *> arrArgRestore;
        GE_ARRAY_FOR_EACH (Arg, a_HookParams.m_arrStackArgs)
        {
            if (!Arg.m_bRestore)
                continue;

            // Only direct register arguments without offset are allowed.
            if (Arg.m_enuArgType != mCAbstractRegArgHookParams::mEArgType_RegDirect || Arg.m_u32Offset != 0)
                return false;

            arrArgRestore.Add(&Arg);
        }

        GE_ARRAY_FOR_EACH_REV (Arg, arrArgRestore)
        {
            GEInt iArgStackOffset = (i + 1) * 4;

            // Use last register argument to move return address.
            if (i == arrArgRestore.GetCount() - 1)
            {
                // Load return address into register.
                a_Assembler.mov(ToX86Register(Arg->m_Register), dword_ptr(esp));

                // Exchange return address with last register argument.
                a_Assembler.xchg(ToX86Register(Arg->m_Register), dword_ptr(esp, iArgStackOffset));
            }
            else
            {
                // Load argument into register.
                a_Assembler.mov(ToX86Register(Arg->m_Register), dword_ptr(esp, iArgStackOffset));
            }
        }

        if (!arrArgRestore.IsEmpty())
            // Adjust stack pointer.
            a_Assembler.add(esp, arrArgRestore.GetCount() * 4);
    }
    return true;
}

mCFunctionHook::mCFunctionHook() : m_bInside(false), m_u32HookRet(0)
{}

GEBool mCFunctionHook::Hook(mCFunctionHookParams const &a_HookParams)
{
    asmjit::x86::CodeAsm assembler;
    GEUInt uRelocateSize = 0;
    if (ParseUntilSize(assembler, a_HookParams.m_pOriginalFunc, JMP_SIZE, 0, &uRelocateSize))
        return false;

    return HookInternal(a_HookParams, assembler, uRelocateSize);
}

GEBool mCFunctionHook::HookInternal(mCFunctionHookParams const &a_HookParams, asmjit::x86::CodeAsm &a_pAssembler,
                                    GEUInt a_u32RelocateSize)
{
    GEUInt replacedSize = a_u32RelocateSize;

    if (replacedSize < JMP_SIZE)
        return false;

    using namespace asmjit;
    using namespace asmjit::x86;

    // Move stack arguments back into register when calling the original function.
    x86::CodeAsm AsmBeforeProlog;
    if (!RestoreArgumentsBeforeCall(AsmBeforeProlog, a_HookParams))
        return false;

    // finish original function prolog
    a_pAssembler.jmp(imm(reinterpret_cast<GEI64>(a_HookParams.m_pOriginalFunc) + replacedSize));
    GELPVoid pRelocatedProlog;
    if (!AsmBeforeProlog.IsEmpty())
    {
        HandleError(AsmBeforeProlog.Append(std::move(a_pAssembler)));
        pRelocatedProlog = JitRuntimeAdd(AsmBeforeProlog);
    }
    else
        pRelocatedProlog = JitRuntimeAdd(a_pAssembler);
    m_pCode = pRelocatedProlog;

    x86::CodeAsm AsmOnEnter;
    if (a_HookParams.m_bTransparent)
    {
        // clear inside flag
        x86::CodeAsm AsmOnReturn;
        AsmOnReturn.mov(byte_ptr_abs(reinterpret_cast<GEU64>(&m_bInside)), imm(false));
        AsmOnReturn.jmp(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ret)));
        GELPVoid pOnReturn = JitRuntimeAdd(AsmOnReturn);

        // overwrite return address
        AsmOnEnter.cmp(byte_ptr_abs(reinterpret_cast<GEU64>(&m_bInside)), imm(true));
        // jmp to original function, if hooked function is called from inside hook
        AsmOnEnter.je(imm(pRelocatedProlog));
        // set inside flag
        AsmOnEnter.mov(byte_ptr_abs(reinterpret_cast<GEU64>(&m_bInside)), imm(true));
        AsmOnEnter.mov(eax, ptr(esp));
        AsmOnEnter.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ret)), eax);
        AsmOnEnter.mov(eax, imm(pOnReturn));
        AsmOnEnter.mov(ptr(esp), eax);
        // otherwise jmp to hook

        asmjit::x86::CodeAsm AsmRelocatedPrologNew;
        GEUInt RelocateSizeNew = 0;
        if (ParseUntilSize(AsmRelocatedPrologNew, a_HookParams.m_pNewFunc, JMP_SIZE, 0, &RelocateSizeNew))
            return false;
        AsmRelocatedPrologNew.jmp(imm(reinterpret_cast<GEI64>(a_HookParams.m_pNewFunc) + RelocateSizeNew));
        GELPVoid pRelocatedPrologNew = JitRuntimeAdd(AsmRelocatedPrologNew);

        // clear inside flag
        x86::CodeAsm AsmOnReturnNew;
        AsmOnReturnNew.mov(byte_ptr_abs(reinterpret_cast<GEU64>(&m_bInside)), imm(false));
        AsmOnReturnNew.jmp(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32HookRet)));
        GELPVoid pOnReturnNew = JitRuntimeAdd(AsmOnReturnNew);

        // overwrite return address
        x86::CodeAsm AsmOnEnterNew;
        AsmOnEnterNew.cmp(byte_ptr_abs(reinterpret_cast<GEU64>(&m_bInside)), imm(true));
        // jmp to hook, without setting inside flag
        AsmOnEnterNew.jge(imm(pRelocatedPrologNew));
        // set inside flag, and prepare to clear it on return
        AsmOnEnterNew.mov(byte_ptr_abs(reinterpret_cast<GEU64>(&m_bInside)), imm(true));
        AsmOnEnterNew.mov(eax, ptr(esp));
        AsmOnEnterNew.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32HookRet)), eax);
        AsmOnEnterNew.mov(eax, imm(pOnReturnNew));
        AsmOnEnterNew.mov(ptr(esp), eax);

        // jmp to hook
        AsmOnEnterNew.jmp(imm(pRelocatedPrologNew));
        GELPVoid pHookDestinationNew = JitRuntimeAdd(AsmOnEnterNew);

        // hook hook function
        x86::CodeAsm AsmTrampolineNew(reinterpret_cast<GEU64>(a_HookParams.m_pNewFunc));
        AsmTrampolineNew.jmp(imm(pHookDestinationNew));
        ApplyAsm(AsmTrampolineNew, RelocateSizeNew);
    }

    PushArgumentsBeforeEntry(AsmOnEnter, a_HookParams);

    DoRegisterMagic(AsmOnEnter, a_HookParams);
    AsmOnEnter.jmp(imm(a_HookParams.m_pNewFunc));

    // hook original function
    x86::CodeAsm AsmTrampoline;
    AsmTrampoline.setBaseAddress(reinterpret_cast<GEU64>(a_HookParams.m_pOriginalFunc));
    AsmTrampoline.jmp(imm(JitRuntimeAdd(AsmOnEnter)));
    ApplyAsm(AsmTrampoline, replacedSize);

    return true;
}

mCVtableHook::mCVtableHook()
{}

mCVtableHook::mCVtableHook(mCVtableHookParams const &a_HookParams)
{
    Hook(a_HookParams);
}

GEBool mCVtableHook::Hook(mCVtableHookParams const &a_HookParams)
{
    using namespace asmjit;
    using namespace asmjit::x86;

    m_pCode = *reinterpret_cast<GELPVoid *>(a_HookParams.m_pOriginalFunc);

    x86::CodeAsm AsmBeforeProlog;
    if (!RestoreArgumentsBeforeCall(AsmBeforeProlog, a_HookParams))
        return false;

    if (!AsmBeforeProlog.IsEmpty())
    {
        AsmBeforeProlog.jmp(imm(m_pCode));
        m_pCode = JitRuntimeAdd(AsmBeforeProlog);
    }

    x86::CodeAsm AsmTrampoline;
    PushArgumentsBeforeEntry(AsmTrampoline, a_HookParams);
    DoRegisterMagic(AsmTrampoline, a_HookParams);
    AsmTrampoline.jmp(imm(a_HookParams.m_pNewFunc));

    Backup(a_HookParams.m_pOriginalFunc, sizeof(GELPVoid));
    GELPVoid pTrampoline = JitRuntimeAdd(AsmTrampoline);
    return WriteMemory(a_HookParams.m_pOriginalFunc, &pTrampoline, sizeof(GELPVoid));
}

mCCallHook::mCCallHook() : m_u32CallReturnAdr(0)
{}

mCCallHook::mCCallHook(mCCallHookParams const &a_HookParams) : m_u32CallReturnAdr(0)
{
    Hook(a_HookParams);
}

void mCCallHook::Disable()
{
    Restore();
}

GEBool mCCallHook::Hook(mCCallHookParams const &a_HookParams)
{
    if (a_HookParams.m_bExplicitSize)
        return HookInternal(a_HookParams);

    mCCallHookParams HookParams = a_HookParams;
    HookParams.m_uCallSize = 0;
    HookParams.m_uMinRelocateSize = 0;
    HookParams.m_uMaxRelocateSize = 0;

    if (!a_HookParams.m_bInsertCall)
    {
        _DInst inst;
        if (!DecomposeInstruction(reinterpret_cast<GELPVoid>(a_HookParams.m_u32CallAdr), inst))
        {
            asmjit::x86::HandleError(asmjit::kErrorInvalidInstruction);
            return false;
        }

        if (META_GET_FC(inst.meta) != FC_CALL)
        {
            asmjit::x86::HandleError(asmjit::kErrorInvalidInstruction);
            return false;
        }

        HookParams.m_uCallSize = inst.size;
        if (HookParams.m_uCallSize < CALL_SIZE)
            HookParams.m_uMinRelocateSize = CALL_SIZE - HookParams.m_uCallSize;
    }
    else
    {
        HookParams.m_uCallSize = 0;
        HookParams.m_uMinRelocateSize = CALL_SIZE;
    }

    return HookInternal(HookParams);
}

GEBool mCCallHook::HookInternal(mCCallHookParams const &a_HookParams)
{
    if (a_HookParams.m_uCallSize + a_HookParams.m_uMinRelocateSize < CALL_SIZE)
        return false;

    m_pCode = a_HookParams.m_pOriginalFunc;

    using namespace asmjit;
    using namespace asmjit::x86;

    // RelocateSize will be added later on
    GEUInt uTotalSize = a_HookParams.m_uCallSize;

    // Prolog
    x86::CodeAsm AsmProlog;
    // Push saved registers before stack args
    GE_ARRAY_FOR_EACH (SavedRegister, a_HookParams.m_arrSavedRegisters)
    {
        AsmProlog.push(ToX86Register(SavedRegister));
    }

    if (!a_HookParams.m_arrStackArgs.IsEmpty())
    {
        PushArguments(AsmProlog, a_HookParams, a_HookParams.m_arrSavedRegisters.GetCount() * 4);
    }

    // Epilog
    x86::CodeAsm AsmEpilog;
    // Restore registers after return from call
    if (a_HookParams.m_bRestoreRegister)
    {
        // Only needed for eax/ecx/edx, compiler will do it for the other registers
        if (a_HookParams.m_RegisterType & mERegisterType_Eax)
            AsmEpilog.mov(eax, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Eax)));
        if (a_HookParams.m_RegisterType & mERegisterType_Ecx)
            AsmEpilog.mov(ecx, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ecx)));
        if (a_HookParams.m_RegisterType & mERegisterType_Edx)
            AsmEpilog.mov(edx, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Edx)));
        if (a_HookParams.m_RegisterType & mERegisterType_Ebx)
            AsmEpilog.mov(ebx, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ebx)));
        if (a_HookParams.m_RegisterType & mERegisterType_Ebp)
            AsmEpilog.mov(ebp, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ebp)));
        if (a_HookParams.m_RegisterType & mERegisterType_Esi)
            AsmEpilog.mov(esi, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Esi)));
        if (a_HookParams.m_RegisterType & mERegisterType_Edi)
            AsmEpilog.mov(edi, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Edi)));
    }

    if (a_HookParams.m_bTestOnReturn)
    {
        AsmEpilog.test(al, al);
    }

    if (a_HookParams.m_ReturnInReg != mERegisterType_None)
    {
        AsmEpilog.mov(ToX86Register(a_HookParams.m_ReturnInReg), eax);
    }

    if (a_HookParams.m_bCleanArgsFromStack && !a_HookParams.m_arrStackArgs.IsEmpty())
    {
        AsmEpilog.add(esp, a_HookParams.m_arrStackArgs.GetCount() * 4);
    }

    // Restore saved registers
    GE_ARRAY_FOR_EACH_REV (SavedRegister, a_HookParams.m_arrSavedRegisters)
    {
        AsmEpilog.pop(ToX86Register(SavedRegister));
    }

    if (a_HookParams.m_u32TrueReturnAdr != 0)
    {
        AsmEpilog.jnz(imm(a_HookParams.m_u32TrueReturnAdr));
    }

    if (a_HookParams.m_u32FalseReturnAdr != 0)
    {
        AsmEpilog.jz(imm(a_HookParams.m_u32FalseReturnAdr));
    }

    x86::CodeAsm AsmRelocatedInst;
    if (a_HookParams.m_uMinRelocateSize > 0)
    {
        GEUInt uRelocateSize;
        if (ParseUntilSize(AsmRelocatedInst,
                           reinterpret_cast<GELPByte>(a_HookParams.m_u32CallAdr) + a_HookParams.m_uCallSize,
                           a_HookParams.m_uMinRelocateSize, a_HookParams.m_uMaxRelocateSize, &uRelocateSize))
            return false;
        uTotalSize += uRelocateSize;
    }

    // Variable return address
    GEU32 uCallReturnAdr = a_HookParams.m_u32CallAdr + uTotalSize;
    if (a_HookParams.m_bVariableReturnAddress)
    {
        GEU32 uDefautVariableReturnAddress = uCallReturnAdr;
        if (!AsmRelocatedInst.IsEmpty())
        {
            AsmRelocatedInst.jmp(imm(uCallReturnAdr));
            uDefautVariableReturnAddress = reinterpret_cast<GEU32>(JitRuntimeAdd(AsmRelocatedInst));
        }

        // Prolog: Load default return address
        AsmProlog.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32CallReturnAdr)), imm(uDefautVariableReturnAddress));

        // Epilog: Jump to variable return address
        AsmEpilog.jmp(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32CallReturnAdr)));
    }
    else
    {
        if (!AsmRelocatedInst.IsEmpty())
        {
            if (HandleError(AsmEpilog.Append(std::move(AsmRelocatedInst))))
                return GEFalse;
        }

        if (!AsmEpilog.IsEmpty())
            AsmEpilog.jmp(imm(uCallReturnAdr));
    }

    DoRegisterMagic(AsmProlog, a_HookParams);

    // Hook call site
    x86::CodeAsm AsmHook(a_HookParams.m_u32CallAdr);

    // Align jmp/call instruction to end of replaced code
    if (a_HookParams.m_bAlignToEnd)
        asmjit::x86::nopFill(AsmHook, uTotalSize - CALL_SIZE);

    if (!AsmProlog.IsEmpty() || !AsmEpilog.IsEmpty())
    {
        // Push return address to stack
        if (AsmEpilog.IsEmpty())
            // Call returns to the end of the call site
            AsmProlog.push(imm(uCallReturnAdr));
        else
            // Call returns to the epilog
            AsmProlog.push(imm(JitRuntimeAdd(AsmEpilog)));
        AsmProlog.jmp(imm(a_HookParams.m_pNewFunc));

        AsmHook.jmp(imm(JitRuntimeAdd(AsmProlog)));
    }
    else
    {
        AsmHook.call(imm(a_HookParams.m_pNewFunc));

        // Add jump instruction or nops to skip replaced code
        SkipCode(AsmHook, uTotalSize);
    }

    ApplyAsm(AsmHook, uTotalSize);

    return true;
}

mCCaller::mCCaller() : m_pFunction(0)
{}

mCCaller::mCCaller(mSCallerParams const &a_CallerParams) : m_pFunction(0)
{
    Init(a_CallerParams);
}

GEBool mCCaller::Init(mSCallerParams const &a_CallerParams)
{
    using namespace asmjit;
    using namespace asmjit::x86;

    // TODO: Optimize

    // restore caller function registers
    x86::CodeAsm AsmRestoreCallerReg;
    AsmRestoreCallerReg.mov(ebx, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32EbxRestore)));
    AsmRestoreCallerReg.mov(ebp, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32EbpRestore)));
    AsmRestoreCallerReg.mov(esi, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32EsiRestore)));
    AsmRestoreCallerReg.mov(edi, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32EdiRestore)));
    AsmRestoreCallerReg.jmp(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ret)));
    GELPVoid pRestoreCallerRegisters = JitRuntimeAdd(AsmRestoreCallerReg);

    // overwrite return address
    x86::CodeAsm AsmPrepareCall;
    AsmPrepareCall.mov(eax, ptr(esp));
    AsmPrepareCall.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ret)), eax);
    AsmPrepareCall.mov(eax, imm(reinterpret_cast<GEI64>(pRestoreCallerRegisters)));
    AsmPrepareCall.mov(ptr(esp), eax);

    // save caller function registers
    AsmPrepareCall.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32EbxRestore)), ebx);
    AsmPrepareCall.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32EbpRestore)), ebp);
    AsmPrepareCall.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32EsiRestore)), esi);
    AsmPrepareCall.mov(dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32EdiRestore)), edi);

    // load registers
    if (a_CallerParams.m_RegisterType & mERegisterType_Eax)
        AsmPrepareCall.mov(eax, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Eax)));
    if (a_CallerParams.m_RegisterType & mERegisterType_Ecx)
        AsmPrepareCall.mov(ecx, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ecx)));
    if (a_CallerParams.m_RegisterType & mERegisterType_Edx)
        AsmPrepareCall.mov(edx, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Edx)));
    if (a_CallerParams.m_RegisterType & mERegisterType_Ebx)
        AsmPrepareCall.mov(ebx, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ebx)));
    if (a_CallerParams.m_RegisterType & mERegisterType_Ebp)
        AsmPrepareCall.mov(ebp, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Ebp)));
    if (a_CallerParams.m_RegisterType & mERegisterType_Esi)
        AsmPrepareCall.mov(esi, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Esi)));
    if (a_CallerParams.m_RegisterType & mERegisterType_Edi)
        AsmPrepareCall.mov(edi, dword_ptr_abs(reinterpret_cast<GEU64>(&m_u32Edi)));

    // jump to function
    AsmPrepareCall.jmp(imm(a_CallerParams.m_u32FunctionAdr));
    m_pFunction = JitRuntimeAdd(AsmPrepareCall);

    return GETrue;
}
