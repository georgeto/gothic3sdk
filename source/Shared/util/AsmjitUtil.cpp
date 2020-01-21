#include "AsmjitUtil.h"
#include "util/Memory.h"

#include <asmtk/asmtk.h>
#ifdef NDEBUG
#pragma comment(lib, "distorm.lib")
#else
#pragma comment(lib, "distorm_d.lib")
#endif

namespace asmjit {
    namespace x86 {
        void nop(asmjit::X86Assembler &a, size_t number) {
            for(size_t i = 0; i < number; i++)
                a.nop();
        }

        void nopFill(asmjit::X86Assembler &a, size_t number) {
            nop(a, number - a.getOffset());
        }
    }

    namespace
    {
        class AbortErrorHandler : public asmjit::ErrorHandler
        {
        public:
            bool handleError(asmjit::Error, const char* message, asmjit::CodeEmitter*)
            {
                GetAsmjitLogger().logf("AsmJit error: %s\n", message);
                fflush(GetAsmjitLogger().getStream());
                abort();
            }
        };
    }

    X86CodeAsm::X86CodeAsm(uint64_t baseAddress)
    {
        init(baseAddress);
    }

    void X86CodeAsm::init(uint64_t baseAddress)
    {
        static AbortErrorHandler ErrorHandler;

        code.init(CodeInfo(ArchInfo::kTypeX86, 0, baseAddress));
        code.setErrorHandler(&ErrorHandler);
        code.attach(this);
    }

    asmjit::CodeHolder & X86CodeAsm::GetCode()
    {
        return code;
    }

    asmjit::CodeHolder const & X86CodeAsm::GetCode() const
    {
        return code;
    }

    void X86CodeAsm::reset()
    {
        code.reset();
        init();
    }

    void X86CodeAsm::setBaseAddress(uint64_t baseAddress)
    {
        _codeInfo.setBaseAddress(baseAddress);
        code._codeInfo.setBaseAddress(baseAddress);
    }

    #pragma warning( push )
    #pragma warning( disable : 4702 ) // unreachable code
    asmjit::Error HandleError(Error error, const char* message)
    {
        if (error == kErrorOk)
            return kErrorOk;

        if (!message)
            message = DebugUtils::errorAsString(error);

        static AbortErrorHandler handler;
        handler.handleError(error, message, 0);

        return error;
    }
    #pragma warning( pop )
}

asmjit::JitRuntime & GetJitRuntime()
{
    static asmjit::JitRuntime Runtime;
    return Runtime;
}

void * JitRuntimeAdd(asmjit::CodeHolder & code)
{
    void * dst = 0;
    GetJitRuntime().add(&dst, &code);
    return dst;
}

void * JitRuntimeAdd(asmjit::X86CodeAsm & assembler)
{
    return JitRuntimeAdd(assembler.GetCode());
}

void JitRuntimeRelease(void * p)
{
    GetJitRuntime().release(p);
}

asmjit::FileLogger AsmjitFileLogger;
void InitAsmjitLogger(FILE * file)
{
    AsmjitFileLogger.setStream(file);
    AsmjitFileLogger.addOptions(asmjit::Logger::kOptionHexDisplacement);
    AsmjitFileLogger.addOptions(asmjit::Logger::kOptionHexImmediate);
    AsmjitFileLogger.addOptions(asmjit::Logger::kOptionBinaryForm);
}

asmjit::FileLogger & GetAsmjitLogger()
{
    return AsmjitFileLogger;
}

void Parse(asmjit::X86CodeAsm &a)
{
    asmtk::AsmParser p(&a);
    p.parse("cmp eax, eax");
    p.parse("xor ecx, edx");
}

bool WriteAssemblerData(asmjit::X86CodeAsm &a, size_t assertSize, bool resetAssembler, bool fillWithNops)
{
    asmjit::CodeHolder & code = a.GetCode();
    code.sync();

    if(assertSize != 0)
    {
        if(code.getCodeSize() > assertSize)
            return false;

        if(fillWithNops)
            asmjit::x86::nopFill(a, assertSize);
    }

    if(assertSize != 0 && code.getCodeSize() != assertSize)
        return false;

    void* writeAddress = reinterpret_cast<void *>(code.getBaseAddress());
    if(!WriteMemory(writeAddress, a.getBufferData(), code.getCodeSize()))
        return false;

    if(resetAssembler)
        a.reset();

    return true;
}

bool ReadAssemblerData(asmjit::X86CodeAsm &dest, void* srcAddress, size_t size)
{
    asmjit::CodeHolder & code = dest.GetCode();
    code.sync();

    size_t OldOffset = dest.getOffset();
    code.growBuffer(&code.getSectionEntry(0)->_buffer, size);

    if(!ReadMemory(dest.getBufferData() + OldOffset, srcAddress, size))
        return false;
    code.getSectionEntry(0)->_buffer._length += size;
    dest.setOffset(OldOffset + size);

    return true;
}

asmjit::Error ParseUntilSize(asmjit::X86CodeAsm & dest, void * srcAddress, size_t minSize, size_t maxSize, size_t * outDecodedSize)
{
    asmtk::AsmParser parser(&dest);

    _OffsetType offset = reinterpret_cast<_OffsetType>(srcAddress);
    size_t decodedSize = 0;
    while(decodedSize < minSize)
    {
        unsigned int decodedInstructionsCount = 0;
        _DecodedInst decodedInstructions[15];
        _DecodeResult res = distorm_decode(offset, reinterpret_cast<const unsigned char*>(offset), (minSize - decodedSize) + 14, Decode32Bits, decodedInstructions, 15, &decodedInstructionsCount);
        if(res != DECRES_SUCCESS && res != DECRES_MEMORYERR)
            return dest.setLastError(asmjit::kErrorInvalidInstruction);

        for(unsigned int i = 0; i < decodedInstructionsCount && decodedSize < minSize; i++)
        {
            _DecodedInst & inst = decodedInstructions[i];
            char instText[128] = { 0 };
            strcat_s(instText, sizeof(instText), reinterpret_cast<char const *>(inst.mnemonic.p));
            strcat_s(instText, sizeof(instText), " ");
            strcat_s(instText, sizeof(instText), reinterpret_cast<char const *>(inst.operands.p));
            ASMJIT_PROPAGATE(dest.setLastError(parser.parse(instText)));

            offset += inst.size;
            decodedSize += inst.size;

            if(maxSize && decodedSize > maxSize)
                return dest.setLastError(asmjit::kErrorCodeTooLarge);
        }
    }

    if(outDecodedSize)
        *outDecodedSize = decodedSize;

    return asmjit::kErrorOk;
}

bool DecodeInstruction(void * srcAddress, _DInst & decodedInstruction, size_t size)
{
    unsigned int decodedInstructionsCount = 0;

    _CodeInfo ci;
    ci.code = reinterpret_cast<const uint8_t *>(srcAddress);
    ci.codeLen = size;
    ci.codeOffset = reinterpret_cast<_OffsetType>(srcAddress);
    ci.dt = Decode32Bits;
    ci.features = DF_NONE;
    _DecodeResult res = distorm_decompose(&ci, &decodedInstruction, 1, &decodedInstructionsCount);
    return (res == DECRES_SUCCESS || res == DECRES_MEMORYERR) && decodedInstructionsCount == 1;
}

bool WriteNops(unsigned long srcAdress, size_t size)
{
    asmjit::X86CodeAsm assembler(srcAdress);
    asmjit::x86::nop(assembler, size);
    return WriteAssemblerData(assembler, size);
}

bool SkipCode(unsigned long address, size_t size)
{
    asmjit::X86CodeAsm assembler(address);
    SkipCode(assembler, size);
    return WriteAssemblerData(assembler, size);
}

void SkipCode(asmjit::X86CodeAsm & code, size_t size)
{
    if(size <= code.GetCode().getCodeSize())
        return;

    size_t remainingSize = size - code.GetCode().getCodeSize();
    if(remainingSize >= 16)
    {
        code.jmp(asmjit::imm(code.GetCode().getBaseAddress() + size));
    }

    asmjit::x86::nopFill(code, size);
}

bool ReadMemory(void * dest, void * source, size_t size)
{
    DWORD OldProtect = 0;
    if(!VirtualProtect(source, size, PAGE_EXECUTE_WRITECOPY, &OldProtect))
        return false;
    memcpy(dest, source, size);
    VirtualProtect(source, size, OldProtect, &OldProtect);

    return true;
}

bool WriteMemory(void * dest, void const * source, size_t size)
{
    DWORD OldProtect = 0;
    if(!VirtualProtect(dest, size, PAGE_EXECUTE_WRITECOPY, &OldProtect))
        return false;
    memcpy(dest, source, size);
    VirtualProtect(dest, size, OldProtect, &OldProtect);

    return true;
}
