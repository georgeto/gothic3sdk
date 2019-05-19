#ifndef GE_TYPES_H_INCLUDED
#define GE_TYPES_H_INCLUDED

#define GETrue true
#define GEFalse false

#define UNDO_THISCALL_PROLOG __asm pop ecx \
                             __asm pop ebp

#define UNDO_CDECL_PROLOG __asm pop ebp

#define UNDO_STDCALL_PROLOG __asm pop ebp

enum bEResult
{
    bEResult_False = GEFalse,
    bEResult_Ok    = GETrue,
};

typedef signed char           GEI8;
typedef unsigned char         GEU8;
typedef short                 GEI16;
typedef unsigned short        GEU16;
typedef long                  GEI32;
typedef unsigned long         GEU32;
typedef int                   GEInt;
typedef unsigned int          GEUInt;
typedef __int64               GEI64;
typedef unsigned __int64      GEU64;
typedef bool                  GEBool;
typedef float                 GEFloat;
typedef double                GEDouble;
typedef void *                GELPVoid;
typedef void const *          GELPCVoid;
typedef char                  GEChar;
typedef char *                GELPChar;
typedef char const *          GELPCChar;
typedef unsigned char         GEByte;
typedef unsigned char *       GELPByte;
typedef unsigned char const * GELPCByte;
typedef wchar_t               GEUnicodeChar;
typedef wchar_t *             GELPUnicodeChar;
typedef wchar_t const *       GELPCUnicodeChar;

#endif
