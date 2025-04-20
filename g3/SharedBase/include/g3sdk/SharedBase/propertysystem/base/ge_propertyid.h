#pragma once

#include <SharedBase/container/map/ge_mapbase.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_string.h>
#include <SharedBase/types/ge_types.h>

class bCGuid;
class bCIStream;
class bCMd5;
class bCOStream;

class GE_DLLIMPORT bCPropertyID
{
  public:
    struct bSCore
    {
        GEU32 Data1;
        GEU16 Data2;
        GEU16 Data3;
        GEU8 Data4[8];
    };

  public:
    bCPropertyID(bCPropertyID const &);
    explicit bCPropertyID(bCGuid const &);
    bCPropertyID();
    ~bCPropertyID();

  public:
    bCPropertyID &operator=(bCPropertyID const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(bCPropertyID const &) const;
    GEBool operator!=(bCPropertyID const &) const;

  public:
    void CopyFrom(bCPropertyID const &);
    void CopyTo(bCPropertyID &) const;
    GEBool CreateFromMd5(bCMd5 const &);
    void CreateFromString(bCString const &);
    GEBool CreateRandom();
    void Destroy();
    void ExtractGuid(bCGuid &);
    bSCore const &GetCore() const;
    GEU32 const &GetCount() const;
    bCString GetShortText() const;
    bCString GetText() const;
    bCString GetTextEx() const;
    GEBool IsValid() const;
    GEBool Read(bCIStream &);
    GEBool SetGuid(bCGuid const &);
    GEBool SetText(bCString const &);
    GEBool SetTextEx(bCString const &);
    void Write(bCOStream &);

  protected:
    static void GE_STDCALL DestroyHashList();

  private:
    bSCore &AccessCore();
    GEU32 &AccessCount();
    GEBool Create();
    void Invalidate();
    void SetCore(bSCore const &);
    void SetCount(GEU32 const &);

  private:
    bSCore mCore;
    GEU32 mCount;
};

GE_ASSERT_SIZEOF(bCPropertyID, 0x14)

bCIStream &GE_STDCALL operator>>(bCIStream &, bCPropertyID &);
bCOStream &GE_STDCALL operator<<(bCOStream &, bCPropertyID &);

template <>
GE_DLLIMPORT GEU32 GE_STDCALL g_GetHashValue<bCPropertyID>(bCPropertyID const &);
