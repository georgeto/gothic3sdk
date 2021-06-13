#include "util/Memory.h"
#include "util/Hook.h"
#include "util/Util.h"

#include <psapi.h>
#pragma comment(lib, "Psapi.lib")

namespace
{
    LONG WINAPI GenomeUnhandledExceptionFilter(EXCEPTION_POINTERS *ExceptionInfo)
    {
        return bCErrorAdmin::GetInstance().CallExceptionError(static_cast<bSException_Pointers *>(ExceptionInfo));
    }

    LPTOP_LEVEL_EXCEPTION_FILTER WINAPI NopSetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER)
    {
        return NULL;
    }

    class bCErrorAdmin_Helper : public bCErrorAdmin
    {
        public:
            void PrintMessage( bCGothic3EngineDialogs::bEGE3DialogsLogMessageType a_MessageType, GELPCChar a_strMessage, GEBool a_bFatal = GETrue )
            {
                bCErrorAdmin::PrintMessage(a_MessageType, a_strMessage, a_bFatal);
            };
    };

    void PrintModules(bCErrorAdmin_Helper & a_ErrorAdmin)
    {
        HANDLE Process = GetCurrentProcess();
        HMODULE Modules[1024];
        DWORD BytesNeeded;
        if(EnumProcessModules(Process, Modules, sizeof(Modules), &BytesNeeded))
        {
            for(auto i = 0u; i < (BytesNeeded / sizeof(HMODULE)); i++)
            {
                MODULEINFO ModuleInfo;
                if(!GetModuleInformation(Process, Modules[i], &ModuleInfo, sizeof(ModuleInfo)))
                    continue;

                TCHAR ModuleName[MAX_PATH];
                if(!GetModuleBaseName(Process, Modules[i], ModuleName, sizeof(ModuleName)))
                    continue;

                a_ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack,
                    bCString::GetFormattedString("%08X-%08X %s", ModuleInfo.lpBaseOfDll, reinterpret_cast<DWORD>(ModuleInfo.lpBaseOfDll) + ModuleInfo.SizeOfImage, ModuleName));
            }
        }
        else
            a_ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "Failed to enumerate modules.");
    }

    static const GEUInt STACK_ELEMENT_DUMP_COUNT = 0x1000;
    void PrintStackDump(bCErrorAdmin_Helper & a_ErrorAdmin, GEU32 a_StackPointer)
    {
        HANDLE Process = GetCurrentProcess();
        GEU32 * StackPointer = reinterpret_cast<GEU32 *>(a_StackPointer);
        for(GEUInt i = 0; i < STACK_ELEMENT_DUMP_COUNT; i++)
        {
            GEU32 Value;
            if(!ReadProcessMemory(Process, StackPointer + i, &Value, sizeof(Value), NULL))
                break;

            a_ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack,
                bCString::GetFormattedString("%08X %08X", StackPointer + i, Value));
        }
    }

    void bCErrorAdmin_PrintStackFrame(bSException_Pointers * a_pExceptionPointers)
    {
        bCErrorAdmin_Helper & ErrorAdmin = static_cast<bCErrorAdmin_Helper &>(bCErrorAdmin::GetInstance());

        ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "Callstack:");
        ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "------------------------------");

        // Work on a copy, because Get(First)StackTraceString modifies the context record (bug in the original code).
        CONTEXT StackTraceContextRecords = *a_pExceptionPointers->ContextRecord;
        bSException_Pointers StackTraceExceptionPointers;
        StackTraceExceptionPointers.ExceptionRecord = a_pExceptionPointers->ExceptionRecord;
        StackTraceExceptionPointers.ContextRecord = &StackTraceContextRecords;

        ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, GetFirstStackTraceString(0xF, &StackTraceExceptionPointers));
        GELPCChar strStackTraceString = nullptr;
        while((strStackTraceString = GetNextStackTraceString(0xF, &StackTraceExceptionPointers)) != nullptr)
            ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, strStackTraceString);

        ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "");
        ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "Registers:");
        ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "------------------------------");
        ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, GetRegisterString(a_pExceptionPointers));

        ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "");
        ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "Modules:");
        ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "------------------------------");
        PrintModules(ErrorAdmin);

        ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "");
        ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "Stackdump:");
        ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "------------------------------");
        PrintStackDump(ErrorAdmin, a_pExceptionPointers->ContextRecord->Esp);
    }

    void bCErrorAdmin_CallFatalError_PrintStackFrame(bCErrorAdmin_Helper & a_ErrorAdmin)
    {
        a_ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "");
        a_ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "Modules:");
        a_ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "------------------------------");
        PrintModules(a_ErrorAdmin);

        a_ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "");
        a_ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "Stackdump:");
        a_ErrorAdmin.PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType_ErrorCallstack, "------------------------------");
        GEU32 StackPointerProbe;
        PrintStackDump(a_ErrorAdmin, reinterpret_cast<GEU32>(&StackPointerProbe));
    }


	void GE_STDCALL CheckSecurityToken(GEU32 & o_Deadbeef)
	{
		eCArchiveFile * pArchiveFile = mCCallHook::GetLastSelf<eCArchiveFile *>();
		*pArchiveFile >> o_Deadbeef;

		if(o_Deadbeef != 0xDEADBEEF)
		{
			bCErrorAdmin & ErrorAdmin = bCErrorAdmin::GetInstance();
			ErrorAdmin.CallFatalError("eCArchiveFile::Open - warning: can¦t read archivefile '" + pArchiveFile->GetFileName() + "'. Security token test for archivedirectorstructure failed !",
				".\\io\\archivesystem\\ge_archivefile.cpp",
				498);
		}
	}

	void GE_STDCALL NavZone_PrintIllegal(gCNavZone_PS * This, GEInt a_iIllegalPointOffset)
	{
		GE_MESSAGE_WARN(bCString::GetFormattedString("  %s at point %d (%s)", This->GetEntity()->GetID().GetText().GetText(), a_iIllegalPointOffset / 12, VectorToMarvinString(This->GetPoint()[a_iIllegalPointOffset / 12]).GetText()));
	}
}

void ApplyHooks()
{
    // Show error dialog also if no frame-based exception is active
    SetUnhandledExceptionFilter(GenomeUnhandledExceptionFilter);
    // Prevent other modules that are loaded later to overwrite our exception handler
    static mCFunctionHook Hook_SetUnhandledExceptionFilter;
    Hook_SetUnhandledExceptionFilter.Hook(GetProcAddress("kernel32.dll", "SetUnhandledExceptionFilter"), &NopSetUnhandledExceptionFilter);

    // Print modules and stack dump
	static mCFunctionHook Hook_bCErrorAdmin_PrintStackFrame;
	Hook_bCErrorAdmin_PrintStackFrame.Hook(PROC_SharedBase("?PrintStackFrame@bCErrorAdmin@@IAEXPAUbSException_Pointers@@@Z"), &bCErrorAdmin_PrintStackFrame);

    // Print modules and stack dump also for bCErrorAdmin::CallFatalError
    static mCCallHook Hook_bCErrorAdmin_CallFatalError_PrintStackFrame;
    Hook_bCErrorAdmin_CallFatalError_PrintStackFrame
        .Prepare(RVA_SharedBase(0xE789), &bCErrorAdmin_CallFatalError_PrintStackFrame)
        .AddRegArg(mCRegisterBase::mERegisterType_Esi) // bCErrorAdmin
        .InsertCall().Hook();

	static mCCallHook Hook_InvalidSecurityToken_B581;
	Hook_InvalidSecurityToken_B581.Hook(RVA_Engine(0xB581), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_20C07;
	Hook_InvalidSecurityToken_20C07.Hook(RVA_Engine(0x20C07), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_22FFD;
	Hook_InvalidSecurityToken_22FFD.Hook(RVA_Engine(0x22FFD), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_23392;
	Hook_InvalidSecurityToken_23392.Hook(RVA_Engine(0x23392), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_25D61;
	Hook_InvalidSecurityToken_25D61.Hook(RVA_Engine(0x25D61), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_26530;
	Hook_InvalidSecurityToken_26530.Hook(RVA_Engine(0x26530), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_4AEC5;
	Hook_InvalidSecurityToken_4AEC5.Hook(RVA_Engine(0x4AEC5), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_4B1FB;
	Hook_InvalidSecurityToken_4B1FB.Hook(RVA_Engine(0x4B1FB), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_50C01;
	Hook_InvalidSecurityToken_50C01.Hook(RVA_Engine(0x50C01), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_511F9;
	Hook_InvalidSecurityToken_511F9.Hook(RVA_Engine(0x511F9), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_5167F;
	Hook_InvalidSecurityToken_5167F.Hook(RVA_Engine(0x5167F), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_56DB3;
	Hook_InvalidSecurityToken_56DB3.Hook(RVA_Engine(0x56DB3), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_5CF51;
	Hook_InvalidSecurityToken_5CF51.Hook(RVA_Engine(0x5CF51), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_5D4EB;
	Hook_InvalidSecurityToken_5D4EB.Hook(RVA_Engine(0x5D4EB), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_909E4;
	Hook_InvalidSecurityToken_909E4.Hook(RVA_Engine(0x909E4), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_91DB1;
	Hook_InvalidSecurityToken_91DB1.Hook(RVA_Engine(0x91DB1), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_920DB;
	Hook_InvalidSecurityToken_920DB.Hook(RVA_Engine(0x920DB), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_9B4D6;
	Hook_InvalidSecurityToken_9B4D6.Hook(RVA_Engine(0x9B4D6), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_A5D5B;
	Hook_InvalidSecurityToken_A5D5B.Hook(RVA_Engine(0xA5D5B), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_AE7F7;
	Hook_InvalidSecurityToken_AE7F7.Hook(RVA_Engine(0xAE7F7), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_AECCF;
	Hook_InvalidSecurityToken_AECCF.Hook(RVA_Engine(0xAECCF), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_DF9CC;
	Hook_InvalidSecurityToken_DF9CC.Hook(RVA_Engine(0xDF9CC), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_108EB4;
	Hook_InvalidSecurityToken_108EB4.Hook(RVA_Engine(0x108EB4), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_10A8D3;
	Hook_InvalidSecurityToken_10A8D3.Hook(RVA_Engine(0x10A8D3), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_10CC7A;
	Hook_InvalidSecurityToken_10CC7A.Hook(RVA_Engine(0x10CC7A), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_10CDB5;
	Hook_InvalidSecurityToken_10CDB5.Hook(RVA_Engine(0x10CDB5), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_10D3B3;
	Hook_InvalidSecurityToken_10D3B3.Hook(RVA_Engine(0x10D3B3), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_111C24;
	Hook_InvalidSecurityToken_111C24.Hook(RVA_Engine(0x111C24), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_136747;
	Hook_InvalidSecurityToken_136747.Hook(RVA_Engine(0x136747), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_1379CD;
	Hook_InvalidSecurityToken_1379CD.Hook(RVA_Engine(0x1379CD), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_138706;
	Hook_InvalidSecurityToken_138706.Hook(RVA_Engine(0x138706), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_1397BC;
	Hook_InvalidSecurityToken_1397BC.Hook(RVA_Engine(0x1397BC), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_13A5B3;
	Hook_InvalidSecurityToken_13A5B3.Hook(RVA_Engine(0x13A5B3), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_13B8E0;
	Hook_InvalidSecurityToken_13B8E0.Hook(RVA_Engine(0x13B8E0), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_13C993;
	Hook_InvalidSecurityToken_13C993.Hook(RVA_Engine(0x13C993), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_13DCA0;
	Hook_InvalidSecurityToken_13DCA0.Hook(RVA_Engine(0x13DCA0), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_13ED05;
	Hook_InvalidSecurityToken_13ED05.Hook(RVA_Engine(0x13ED05), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_13FCFA;
	Hook_InvalidSecurityToken_13FCFA.Hook(RVA_Engine(0x13FCFA), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_140C78;
	Hook_InvalidSecurityToken_140C78.Hook(RVA_Engine(0x140C78), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_1416D8;
	Hook_InvalidSecurityToken_1416D8.Hook(RVA_Engine(0x1416D8), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_142128;
	Hook_InvalidSecurityToken_142128.Hook(RVA_Engine(0x142128), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_142B78;
	Hook_InvalidSecurityToken_142B78.Hook(RVA_Engine(0x142B78), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_1435E4;
	Hook_InvalidSecurityToken_1435E4.Hook(RVA_Engine(0x1435E4), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_1B33E2;
	Hook_InvalidSecurityToken_1B33E2.Hook(RVA_Engine(0x1B33E2), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_1B374B;
	Hook_InvalidSecurityToken_1B374B.Hook(RVA_Engine(0x1B374B), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_1B5082;
	Hook_InvalidSecurityToken_1B5082.Hook(RVA_Engine(0x1B5082), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_1B53CD;
	Hook_InvalidSecurityToken_1B53CD.Hook(RVA_Engine(0x1B53CD), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_1B6ADD;
	Hook_InvalidSecurityToken_1B6ADD.Hook(RVA_Engine(0x1B6ADD), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_1B8B42;
	Hook_InvalidSecurityToken_1B8B42.Hook(RVA_Engine(0x1B8B42), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_1CD478;
	Hook_InvalidSecurityToken_1CD478.Hook(RVA_Engine(0x1CD478), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_1D6208;
	Hook_InvalidSecurityToken_1D6208.Hook(RVA_Engine(0x1D6208), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_1DD322;
	Hook_InvalidSecurityToken_1DD322.Hook(RVA_Engine(0x1DD322), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_1DEBE2;
	Hook_InvalidSecurityToken_1DEBE2.Hook(RVA_Engine(0x1DEBE2), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_1E0874;
	Hook_InvalidSecurityToken_1E0874.Hook(RVA_Engine(0x1E0874), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_1E4338;
	Hook_InvalidSecurityToken_1E4338.Hook(RVA_Engine(0x1E4338), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_1E6728;
	Hook_InvalidSecurityToken_1E6728.Hook(RVA_Engine(0x1E6728), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_21C2CF;
	Hook_InvalidSecurityToken_21C2CF.Hook(RVA_Engine(0x21C2CF), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_21F91C;
	Hook_InvalidSecurityToken_21F91C.Hook(RVA_Engine(0x21F91C), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_21FC31;
	Hook_InvalidSecurityToken_21FC31.Hook(RVA_Engine(0x21FC31), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_22CE1F;
	Hook_InvalidSecurityToken_22CE1F.Hook(RVA_Engine(0x22CE1F), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_22D14E;
	Hook_InvalidSecurityToken_22D14E.Hook(RVA_Engine(0x22D14E), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_28B3EF;
	Hook_InvalidSecurityToken_28B3EF.Hook(RVA_Engine(0x28B3EF), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_28C9E1;
	Hook_InvalidSecurityToken_28C9E1.Hook(RVA_Engine(0x28C9E1), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_29A5C5;
	Hook_InvalidSecurityToken_29A5C5.Hook(RVA_Engine(0x29A5C5), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_29D531;
	Hook_InvalidSecurityToken_29D531.Hook(RVA_Engine(0x29D531), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_2A6CC1;
	Hook_InvalidSecurityToken_2A6CC1.Hook(RVA_Engine(0x2A6CC1), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_2A7399;
	Hook_InvalidSecurityToken_2A7399.Hook(RVA_Engine(0x2A7399), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_2AB443;
	Hook_InvalidSecurityToken_2AB443.Hook(RVA_Engine(0x2AB443), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_InvalidSecurityToken_2ABF43;
	Hook_InvalidSecurityToken_2ABF43.Hook(RVA_Engine(0x2ABF43), &CheckSecurityToken, mCBaseHook::mEHookType_ThisCall);

	static mCCallHook Hook_NavZone_PrintIllegal;
	Hook_NavZone_PrintIllegal
		.Prepare(RVA_Game(0x11465C), &NavZone_PrintIllegal)
		.AddRegArg(mCRegisterBase::mERegisterType_Esi) // NavZone
		.AddRegArg(mCRegisterBase::mERegisterType_Ebp) // IllegalPointOffset
		.InsertCall().Hook();
}


gSScriptInit & GetScriptInit()
{
    static gSScriptInit s_ScriptInit;
    return s_ScriptInit;
}

extern "C" __declspec( dllexport )
gSScriptInit const * GE_STDCALL ScriptInit( void )
{
    ApplyHooks();

    return &GetScriptInit();
}

//
// Entry Point
//

BOOL APIENTRY DllMain( HMODULE hModule, DWORD dwReason, LPVOID )
{
    switch( dwReason )
    {
    case DLL_PROCESS_ATTACH:
        ::DisableThreadLibraryCalls( hModule );
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
