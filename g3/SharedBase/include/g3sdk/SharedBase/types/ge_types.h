#pragma once

#define GETrue true
#define GEFalse false

#define UNDO_THISCALL_PROLOG __asm pop ecx __asm pop ebp

#define UNDO_CDECL_PROLOG __asm pop ebp

#define UNDO_STDCALL_PROLOG __asm pop ebp

enum bEResult
{
    bEResult_False = GEFalse,
    bEResult_Ok = GETrue,
};

using GEI8 = signed char;
using GEU8 = unsigned char;
using GEI16 = short;
using GEU16 = unsigned short;
using GEI32 = long;
using GEU32 = unsigned long;
using GEInt = int;
using GEUInt = unsigned int;
using GEI64 = __int64;
using GEU64 = unsigned __int64;
using GEBool = bool;
using GEFloat = float;
using GEDouble = double;
using GELPVoid = void *;
using GELPCVoid = void const *;
using GEChar = char;
using GELPChar = char *;
using GELPCChar = char const *;
using GEByte = unsigned char;
using GELPByte = unsigned char *;
using GELPCByte = unsigned char const *;
using GEUnicodeChar = wchar_t;
using GELPUnicodeChar = wchar_t *;
using GELPCUnicodeChar = wchar_t const *;
