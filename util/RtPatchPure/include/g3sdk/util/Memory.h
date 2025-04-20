#pragma once

#include <g3sdk/SharedBase/types/ge_types.h>
#include <g3sdk/util/AsmjitUtil.h>
#include <g3sdk/util/Error.h>

#define USE_X86_ASSEMBLER(message) USE_X86_ASSEMBLER_N(a, message)

#define USE_X86_ASSEMBLER_N(asm, message)                                                                              \
    using namespace asmjit;                                                                                            \
    using namespace asmjit::x86;                                                                                       \
    x86::CodeAsm asm;                                                                                                  \
    asm.GetCode().setLogger(&GetAsmjitLogger());                                                                       \
    GetAsmjitLogger().logf("\n\n%s\n", message);

#define USE_X86_ASSEMBLER_ADR(baseAddress, message) USE_X86_ASSEMBLER_ADR_N(a, baseAddress, message)

#define USE_X86_ASSEMBLER_ADR_N(asm, baseAddress, message)                                                             \
    USE_X86_ASSEMBLER_N(asm, message)                                                                                  \
    asm.setBaseAddress(baseAddress);

#define VTABLE(CLASS) "??_7" #CLASS "@@6B@"

GELPVoid LoadModule(GELPCChar a_strModule);
GELPVoid GetProcAddress(GELPCChar a_strModule, GELPCChar a_strProc);

inline GEU32 RVA_Generic(GELPCChar a_strModuleName, GEU32 a_uOffset)
{
    return reinterpret_cast<GEU32>(LoadModule(a_strModuleName)) + a_uOffset;
};
inline GEU32 RVA_ScriptGame(GEU32 a_uOffset)
{
    return RVA_Generic("Script_Game.dll", a_uOffset);
};
inline GEU32 RVA_Script(GEU32 a_uOffset)
{
    return RVA_Generic("Script.dll", a_uOffset);
};
inline GEU32 RVA_Game(GEU32 a_uOffset)
{
    return RVA_Generic("Game.dll", a_uOffset);
};
inline GEU32 RVA_Engine(GEU32 a_uOffset)
{
    return RVA_Generic("Engine.dll", a_uOffset);
};
inline GEU32 RVA_Importer(GEU32 a_uOffset)
{
    return RVA_Generic("Importer.dll", a_uOffset);
};
inline GEU32 RVA_SharedBase(GEU32 a_uOffset)
{
    return RVA_Generic("SharedBase.dll", a_uOffset);
};
inline GEU32 RVA_Gui(GEU32 a_uOffset)
{
    return RVA_Generic("GUI.dll", a_uOffset);
};
inline GEU32 RVA_Executable(GEU32 a_uOffset)
{
    return RVA_Generic(nullptr, a_uOffset);
};

inline GELPVoid PROC_ScriptGame(GELPCChar a_strName)
{
    return GetProcAddress("Script_Game.dll", a_strName);
};
inline GELPVoid PROC_Script(GELPCChar a_strName)
{
    return GetProcAddress("Script.dll", a_strName);
};
inline GELPVoid PROC_Game(GELPCChar a_strName)
{
    return GetProcAddress("Game.dll", a_strName);
};
inline GELPVoid PROC_Engine(GELPCChar a_strName)
{
    return GetProcAddress("Engine.dll", a_strName);
};
inline GELPVoid PROC_Importer(GELPCChar a_strName)
{
    return GetProcAddress("Importer.dll", a_strName);
};
inline GELPVoid PROC_SharedBase(GELPCChar a_strName)
{
    return GetProcAddress("SharedBase.dll", a_strName);
};
inline GELPVoid PROC_Gui(GELPCChar a_strName)
{
    return GetProcAddress("GUI.dll", a_strName);
};
inline GELPVoid PROC_Executable(GELPCChar a_strName)
{
    return GetProcAddress(static_cast<GELPCChar>(nullptr), a_strName);
};
