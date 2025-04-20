#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCAPIIndexData
{
    // clang-format off
    public: virtual bEResult LockBuffer(GEUInt, GEUInt, GEU32, GELPByte*) = 0;
    public: virtual bEResult UnlockBuffer() = 0;
    public: virtual bEResult GetDesc(eCGfxShared::eSGfxIndexBufDesc *) = 0;
    public: virtual ~eCAPIIndexData();
    // clang-format on

  public:
    eCAPIIndexData(eCAPIIndexData const &);

  public:
    eCAPIIndexData &operator=(eCAPIIndexData const &);

  public:
    GEU32 AddRef();
    GEU32 Release();

  protected:
    eCAPIIndexData();

  private:
    GEU32 m_u32ReferenceCount;
};
