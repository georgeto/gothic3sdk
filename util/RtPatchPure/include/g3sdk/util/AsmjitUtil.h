#pragma once

#pragma warning(push, 0)
#include "asmjit/asmjit.h"

#include <distorm.h>
#pragma warning(pop)

ASMJIT_BEGIN_SUB_NAMESPACE(x86)

void nop(Assembler &a, size_t number);
void nopFill(Assembler &a, size_t number);

class CodeAsm : public Assembler
{
  public:
    CodeAsm(uint64_t baseAddress = asmjit::Globals::kNoBaseAddress);

  public:
    asmjit::Error Append(CodeAsm &&a_CodeAsm);
    asmjit::CodeHolder &GetCode();
    asmjit::CodeHolder const &GetCode() const;
    bool IsEmpty() const;
    void reset();
    void setBaseAddress(uint64_t baseAddress);

  private:
    void init(uint64_t baseAddress = asmjit::Globals::kNoBaseAddress);

  private:
    asmjit::CodeHolder code;
};

asmjit::Error HandleError(Error error, const char *message = nullptr);

ASMJIT_END_SUB_NAMESPACE

asmjit::JitRuntime &GetJitRuntime();
void *JitRuntimeAdd(asmjit::CodeHolder &code);
void *JitRuntimeAdd(asmjit::x86::CodeAsm &assembler);
void JitRuntimeRelease(void *p);

void InitAsmjitLogger(FILE *file);
asmjit::FileLogger &GetAsmjitLogger();
bool WriteAssemblerData(asmjit::x86::CodeAsm &a, size_t assertSize = 0, bool resetAssembler = false,
                        bool fillWithNops = false);
bool ReadAssemblerData(asmjit::x86::CodeAsm &dest, void *srcAddress, size_t size);
asmjit::Error ParseUntilSize(asmjit::x86::CodeAsm &dest, void *srcAddress, size_t minSize, size_t maxSize = 0,
                             size_t *outDecodedSize = nullptr);
asmjit::Error ParseUntilSize(asmjit::x86::CodeAsm &dest, size_t baseAddress, void *dataBuffer, size_t minSize,
                             size_t maxSize = 0, size_t *outDecodedSize = nullptr);
bool DecodeInstruction(void *srcAddress, _DecodedInst &decodedInstruction, size_t size = 15);
bool DecomposeInstruction(void *srcAddress, _DInst &decomposedInstruction, size_t size = 15);
bool WriteNops(unsigned long srcAdress, size_t size);
bool SkipCode(unsigned long address, size_t size);
void SkipCode(asmjit::x86::CodeAsm &code, size_t size);

bool ReadMemory(void *dest, void *source, size_t size);
bool WriteMemory(void *dest, void const *source, size_t size);
