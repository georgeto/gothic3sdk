#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCOStream;

class GE_DLLIMPORT bCObjectBase
{
    // clang-format off
    public: virtual GEU16 GetVersion() const;
    public: virtual GEBool IsValid() const;
    private: virtual GEBool Write(bCOStream &) const;
    public: virtual bEResult Write(bCOStream &);
    public: virtual bEResult Read(bCIStream &);
    protected: virtual void Destroy();
    public: virtual bEResult Create();
    public: virtual bEResult CopyFrom(bCObjectBase const &);
    public: virtual GEU32 AddReference();
    public: virtual GEU32 ReleaseReference();
    public: virtual GEU32 GetReferenceCount();
    public: virtual GEU32 const GetProfileLastTicksFirst() const;
    public: virtual GEU32 const GetProfileLastTicksSecond() const;
    public: virtual GEU32 const GetProfileLastTicksThird() const;
    public: virtual ~bCObjectBase();
    // clang-format on

  public:
    bCObjectBase(bCObjectBase const &);
    bCObjectBase();

  public:
    bCObjectBase const &operator=(bCObjectBase const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  protected:
    bEResult CopyTo(bCObjectBase &) const;
    void Invalidate();
};

bCOStream &GE_STDCALL operator<<(bCOStream &, bCObjectBase &);
bCIStream &GE_STDCALL operator>>(bCIStream &, bCObjectBase &);
