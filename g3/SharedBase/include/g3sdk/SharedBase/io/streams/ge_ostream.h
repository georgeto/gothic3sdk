#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCDateTime;
class bCGuid;
class bCString;
class bCUnicodeString;
class bCVariant;

class GE_DLLIMPORT bCOStream
{
    // clang-format off
    public: virtual GEU32 Write(GELPCVoid, GEU32);
    public: virtual GEU32 Write(bCString const &);
    public: virtual ~bCOStream();
    // clang-format on

  public:
    bCOStream(bCOStream const &);
    bCOStream();

  public:
    bCOStream &operator=(bCOStream const &);
    bCOStream &operator<<(bCDateTime const &);
    bCOStream &operator<<(bCGuid const &);
    bCOStream &operator<<(bCString const &);
    bCOStream &operator<<(bCUnicodeString const &);
    bCOStream &operator<<(bCVariant const &);
    bCOStream &operator<<(GEI8);
    bCOStream &operator<<(GEChar);
    bCOStream &operator<<(GEU8);
    bCOStream &operator<<(GEI16);
    bCOStream &operator<<(GEU16);
    bCOStream &operator<<(GEInt);
    bCOStream &operator<<(GEUInt);
    bCOStream &operator<<(GEI32);
    bCOStream &operator<<(GEU32);
    bCOStream &operator<<(GEFloat);
    bCOStream &operator<<(GEDouble);
    bCOStream &operator<<(GEI64);
    bCOStream &operator<<(GEU64);
    bCOStream &operator<<(GEBool);

  public:
    GEU32 Write(bCDateTime const &);
    GEU32 Write(bCGuid const &);
    GEU32 Write(bCUnicodeString const &);
    GEU32 Write(bCVariant const &);
    GEU32 Write(GEI8);
    GEU32 Write(GEChar);
    GEU32 Write(GEU8);
    GEU32 Write(GEI16);
    GEU32 Write(GEU16);
    GEU32 Write(GEInt);
    GEU32 Write(GEUInt);
    GEU32 Write(GEI32);
    GEU32 Write(GEU32);
    GEU32 Write(GEFloat);
    GEU32 Write(GEDouble);
    GEU32 Write(GEI64);
    GEU32 Write(GEU64);
    GEU32 Write(GEBool);
    GEU32 WriteLine(bCString const &);
};

bCOStream &GE_STDCALL operator>>(bCDateTime const &, bCOStream &);
bCOStream &GE_STDCALL operator>>(bCGuid const &, bCOStream &);
bCOStream &GE_STDCALL operator>>(bCString const &, bCOStream &);
bCOStream &GE_STDCALL operator>>(bCUnicodeString const &, bCOStream &);
bCOStream &GE_STDCALL operator>>(bCVariant const &, bCOStream &);
bCOStream &GE_STDCALL operator>>(GEI8, bCOStream &);
bCOStream &GE_STDCALL operator>>(GEChar, bCOStream &);
bCOStream &GE_STDCALL operator>>(GEU8, bCOStream &);
bCOStream &GE_STDCALL operator>>(GEI16, bCOStream &);
bCOStream &GE_STDCALL operator>>(GEU16, bCOStream &);
bCOStream &GE_STDCALL operator>>(GEInt, bCOStream &);
bCOStream &GE_STDCALL operator>>(GEUInt, bCOStream &);
bCOStream &GE_STDCALL operator>>(GEI32, bCOStream &);
bCOStream &GE_STDCALL operator>>(GEU32, bCOStream &);
bCOStream &GE_STDCALL operator>>(GEFloat, bCOStream &);
bCOStream &GE_STDCALL operator>>(GEDouble, bCOStream &);
bCOStream &GE_STDCALL operator>>(GEI64, bCOStream &);
bCOStream &GE_STDCALL operator>>(GEU64, bCOStream &);
bCOStream &GE_STDCALL operator>>(GEBool, bCOStream &);
