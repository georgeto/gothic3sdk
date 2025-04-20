#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCAPIVertexData
{
    // clang-format off
    public: virtual bEResult LockBuffer(GEUInt, GEUInt, GEU32, GELPByte*) = 0;
    public: virtual bEResult UnlockBuffer() = 0;
    public: virtual bEResult GetDesc(eCGfxShared::eSGfxVertexBufDesc *) = 0;
    public: virtual bEResult SetStride(GEU32) = 0;
    public: virtual ~eCAPIVertexData();
    // clang-format on

  public:
    eCAPIVertexData(eCAPIVertexData const &);

  public:
    eCAPIVertexData &operator=(eCAPIVertexData const &);

  public:
    GEU32 AddRef();
    GEU32 Release();

  protected:
    eCAPIVertexData();

  private:
    GEU32 m_u32ReferenceCount;
};
