#include "AsmjitUtil.h"

#include "Memory.h"

#define NOMINMAX
#include <utility>

#include <windows.h>

#pragma warning(push)
#pragma warning(disable : 4458)
#include <asmtk/asmtk.h>
#pragma warning(pop)
#ifdef NDEBUG
#pragma comment(lib, "distorm.lib")
#else
#pragma comment(lib, "distorm_d.lib")
#endif

ASMJIT_BEGIN_SUB_NAMESPACE(x86)

void nop(Assembler &a, size_t number)
{
    for (size_t i = 0; i < number; i++)
        a.nop();
}

void nopFill(Assembler &a, size_t number)
{
    nop(a, number - a.offset());
}

namespace
{
class AbortErrorHandler : public asmjit::ErrorHandler
{
  public:
    void handleError(asmjit::Error, const char *message, asmjit::BaseEmitter *) override
    {
        if (GetAsmjitLogger().file())
        {
            GetAsmjitLogger().logf("AsmJit error: %s\n", message);
            fflush(GetAsmjitLogger().file());
        }
        CallFatalError("AsmJit error!", message);
    }
};
} // namespace

CodeAsm::CodeAsm(uint64_t baseAddress)
{
    init(baseAddress);
}

asmjit::Error CodeAsm::Append(CodeAsm &&a_CodeAsm)
{
    if (a_CodeAsm.code.hasBaseAddress())
        return kErrorInvalidArgument;

    ASMJIT_PROPAGATE(a_CodeAsm.code.flatten());
    size_t codeSize = a_CodeAsm.code.codeSize();
    void *buffer = malloc(codeSize);
    ASMJIT_PROPAGATE(a_CodeAsm.code.relocateToBase((uint64_t)buffer));
    // Code size may decrease after calling relocateToBase.
    if (codeSize < a_CodeAsm.code.codeSize())
        codeSize = a_CodeAsm.code.codeSize();
    ASMJIT_PROPAGATE(a_CodeAsm.code.copyFlattenedData(buffer, codeSize));
    asmjit::Error result = ParseUntilSize(*this, buffer, codeSize, codeSize);
    free(buffer);
    return result;
}

void CodeAsm::init(uint64_t baseAddress)
{
    static AbortErrorHandler ErrorHandler;

    code.init(Environment(Arch::kX86), baseAddress);
    code.setErrorHandler(&ErrorHandler);
    code.attach(this);
}

asmjit::CodeHolder &CodeAsm::GetCode()
{
    return code;
}

asmjit::CodeHolder const &CodeAsm::GetCode() const
{
    return code;
}

bool CodeAsm::IsEmpty() const
{
    return code.codeSize() == 0;
}

void CodeAsm::reset()
{
    code.reset();
    init();
}

void CodeAsm::setBaseAddress(uint64_t baseAddress)
{
    code._baseAddress = baseAddress;
}

#pragma warning(push)
#pragma warning(disable : 4702) // unreachable code
asmjit::Error HandleError(Error error, const char *message)
{
    if (error == kErrorOk)
        return kErrorOk;

    if (!message)
        message = DebugUtils::errorAsString(error);

    static AbortErrorHandler handler;
    handler.handleError(error, message, 0);

    return error;
}
#pragma warning(pop)

ASMJIT_END_SUB_NAMESPACE

asmjit::JitRuntime &GetJitRuntime()
{
    static asmjit::JitRuntime Runtime;
    return Runtime;
}

void *JitRuntimeAdd(asmjit::CodeHolder &code)
{
    void *dst = 0;
    GetJitRuntime().add(&dst, &code);
    return dst;
}

void *JitRuntimeAdd(asmjit::x86::CodeAsm &assembler)
{
    return JitRuntimeAdd(assembler.GetCode());
}

void JitRuntimeRelease(void *p)
{
    GetJitRuntime().release(p);
}

asmjit::FileLogger AsmjitFileLogger;
void InitAsmjitLogger(FILE *file)
{
    using namespace asmjit;
    AsmjitFileLogger.setFile(file);
    AsmjitFileLogger.addFlags(FormatFlags::kMachineCode | FormatFlags::kHexImms | FormatFlags::kHexOffsets);
}

asmjit::FileLogger &GetAsmjitLogger()
{
    return AsmjitFileLogger;
}

bool WriteAssemblerData(asmjit::x86::CodeAsm &a, size_t assertSize, bool resetAssembler, bool fillWithNops)
{
    asmjit::CodeHolder &code = a.GetCode();

    if (assertSize != 0)
    {
        if (code.codeSize() > assertSize)
            return false;

        if (fillWithNops)
            asmjit::x86::nopFill(a, assertSize);
    }

    if (assertSize != 0 && code.codeSize() != assertSize)
        return false;

    void *writeAddress = reinterpret_cast<void *>(static_cast<uint32_t>(code.baseAddress()));
    if (!WriteMemory(writeAddress, a.bufferData(), code.codeSize()))
        return false;

    if (resetAssembler)
        a.reset();

    return true;
}

bool ReadAssemblerData(asmjit::x86::CodeAsm &dest, void *srcAddress, size_t size)
{
    asmjit::CodeHolder &code = dest.GetCode();

    size_t OldOffset = dest.offset();
    code.growBuffer(&code.textSection()->buffer(), size);

    if (!ReadMemory(dest.bufferData() + OldOffset, srcAddress, size))
        return false;
    code.textSection()->buffer()._size += size;
    dest.setOffset(OldOffset + size);

    return true;
}

asmjit::Error ParseUntilSize(asmjit::x86::CodeAsm &dest, void *srcAddress, size_t minSize, size_t maxSize,
                             size_t *outDecodedSize)
{
    return ParseUntilSize(dest, reinterpret_cast<uint32_t>(srcAddress), srcAddress, minSize, maxSize, outDecodedSize);
}

asmjit::Error ParseUntilSize(asmjit::x86::CodeAsm &dest, size_t baseAddress, void *dataBuffer, size_t minSize,
                             size_t maxSize, size_t *outDecodedSize)
{
    asmtk::AsmParser parser(&dest);

    _OffsetType offset = baseAddress;
    size_t decodedSize = 0;
    while (decodedSize < minSize)
    {
        unsigned int decodedInstructionsCount = 0;
        _DecodedInst decodedInstructions[15];
        _DecodeResult res = distorm_decode(
            offset, reinterpret_cast<const unsigned char *>(dataBuffer) + (offset - baseAddress),
            (minSize - decodedSize) + 14, Decode32Bits, decodedInstructions, 15, &decodedInstructionsCount);
        if (res != DECRES_SUCCESS && res != DECRES_MEMORYERR)
            return dest.reportError(asmjit::kErrorInvalidInstruction);

        for (unsigned int i = 0; i < decodedInstructionsCount && decodedSize < minSize; i++)
        {
            _DecodedInst &inst = decodedInstructions[i];
            char instText[128] = {0};
            strcat_s(instText, sizeof(instText), reinterpret_cast<char const *>(inst.mnemonic.p));
            strcat_s(instText, sizeof(instText), " ");
            strcat_s(instText, sizeof(instText), reinterpret_cast<char const *>(inst.operands.p));
            if (asmtk::Error err = parser.parse(instText))
                return dest.reportError(err);

            offset += inst.size;
            decodedSize += inst.size;

            if (maxSize && decodedSize > maxSize)
                return dest.reportError(asmjit::kErrorTooLarge);
        }
    }

    if (outDecodedSize)
        *outDecodedSize = decodedSize;

    return asmjit::kErrorOk;
}

bool DecodeInstruction(void *srcAddress, _DecodedInst &decodedInstruction, size_t size)
{
    unsigned int decodedInstructionsCount = 0;

    _DecodeResult res =
        distorm_decode(reinterpret_cast<uint32_t>(srcAddress), reinterpret_cast<const unsigned char *>(srcAddress),
                       size, Decode32Bits, &decodedInstruction, 1, &decodedInstructionsCount);
    return (res == DECRES_SUCCESS || res == DECRES_MEMORYERR) && decodedInstructionsCount == 1;
}

bool DecomposeInstruction(void *srcAddress, _DInst &decomposedInstruction, size_t size)
{
    unsigned int decomposedInstructionsCount = 0;

    _CodeInfo ci;
    ci.code = reinterpret_cast<const uint8_t *>(srcAddress);
    ci.codeLen = size;
    ci.codeOffset = reinterpret_cast<uint32_t>(srcAddress);
    ci.dt = Decode32Bits;
    ci.features = DF_NONE;
    _DecodeResult res = distorm_decompose(&ci, &decomposedInstruction, 1, &decomposedInstructionsCount);
    return (res == DECRES_SUCCESS || res == DECRES_MEMORYERR) && decomposedInstructionsCount == 1;
}

bool WriteNops(unsigned long srcAdress, size_t size)
{
    asmjit::x86::CodeAsm assembler(srcAdress);
    asmjit::x86::nop(assembler, size);
    return WriteAssemblerData(assembler, size);
}

bool SkipCode(unsigned long address, size_t size)
{
    asmjit::x86::CodeAsm assembler(address);
    SkipCode(assembler, size);
    return WriteAssemblerData(assembler, size);
}

void SkipCode(asmjit::x86::CodeAsm &code, size_t size)
{
    if (size <= code.GetCode().codeSize())
        return;

    size_t remainingSize = size - code.GetCode().codeSize();
    if (remainingSize >= 16)
    {
        code.jmp(asmjit::imm(code.GetCode().baseAddress() + size));
    }

    asmjit::x86::nopFill(code, size);
}

bool ReadMemory(void *dest, void *source, size_t size)
{
    MEMORY_BASIC_INFORMATION Info;
    if (VirtualQuery(source, &Info, sizeof(Info)) != sizeof(Info))
        return false;

    if (Info.State != MEM_COMMIT)
        return false;

    memcpy(dest, source, size);
    return true;
}

bool WriteMemory(void *dest, void const *source, size_t size)
{
    DWORD OldProtect = 0;
    if (!VirtualProtect(dest, size, PAGE_EXECUTE_WRITECOPY, &OldProtect))
        return false;
    memcpy(dest, source, size);
    VirtualProtect(dest, size, OldProtect, &OldProtect);

    return true;
}
