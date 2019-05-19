#ifndef ASMJIT_UTIL_H_INCLUDED
#define ASMJIT_UTIL_H_INCLUDED

#pragma warning( push, 0 )
#include "asmjit/asmjit.h"
#include <distorm/distorm.h>
#pragma warning( pop )

namespace asmjit {
    namespace x86 {
        void nop(asmjit::X86Assembler &a, size_t number);
        void nopFill(asmjit::X86Assembler &a, size_t number);
    }

    class X86CodeAsm : public X86Assembler
    {
        public:
            X86CodeAsm(uint64_t baseAddress = asmjit::Globals::kNoBaseAddress);

        public:
            asmjit::CodeHolder & GetCode();
            asmjit::CodeHolder const & GetCode() const;
            void reset();
            void setBaseAddress(uint64_t baseAddress);

        private:
            void init(uint64_t baseAddress = asmjit::Globals::kNoBaseAddress);

        private:
            asmjit::CodeHolder code;
    };

    asmjit::Error HandleError(Error error, const char* message = 0);
}

asmjit::JitRuntime & GetJitRuntime();
void * JitRuntimeAdd(asmjit::CodeHolder & code);
void * JitRuntimeAdd(asmjit::X86CodeAsm & assembler);
void JitRuntimeRelease(void * p);

void InitAsmjitLogger(FILE * file);
asmjit::FileLogger & GetAsmjitLogger();
bool WriteAssemblerData(asmjit::X86CodeAsm &a, size_t assertSize = 0, bool resetAssembler = false, bool fillWithNops = false);
bool ReadAssemblerData(asmjit::X86CodeAsm & dest, void* srcAddress, size_t size);
asmjit::Error ParseUntilSize(asmjit::X86CodeAsm & dest, void * srcAddress, size_t minSize, size_t maxSize = 0, size_t * outDecodedSize = 0);
bool DecodeInstruction(void * srcAddress, _DInst & decodedInstruction, size_t size = 15);
bool WriteNops(unsigned long srcAdress, size_t size);
bool SkipCode(unsigned long address, size_t size);

bool ReadMemory(void * dest, void * source, size_t size);
bool WriteMemory(void * dest, void const * source, size_t size);

#endif