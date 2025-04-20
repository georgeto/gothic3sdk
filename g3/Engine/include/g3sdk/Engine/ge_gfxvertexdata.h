#pragma once

#include <Engine/api/ge_apidevice.h>
#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCAPIVertexData;

class GE_DLLIMPORT eCGfxVertexData : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCGfxVertexData const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxVertexData() override;
    // clang-format on

  public:
    eCGfxVertexData(eCGfxVertexData const &);
    eCGfxVertexData();

  public:
    eCGfxVertexData &operator=(eCGfxVertexData const &);

  public:
    bEResult Create(eCGfxShared::eSGfxVertexBufDesc const &);
    bEResult GetBufferDescription(eCGfxShared::eSGfxVertexBufDesc &) const;
    void Invalidate();
    bEResult LockBuffer(GEUInt, GEUInt, GEU32, GELPByte *);
    bEResult UnlockBuffer();

  protected:
    bEResult CreateBuffer(eCGfxShared::eSGfxVertexBufDesc const &);
    bEResult DestroyBuffer();
    bEResult GetVertexData(eCAPIVertexData *&);
    bEResult SetVertexData(eCAPIVertexData *);

  public:
    eCAPIDevice *m_pDevice;
    GEBool m_bBufferLocked;
    GE_PADDING(0x3)
    eCAPIVertexData *m_pVertexData;
    eCGfxShared::eSGfxVertexBufDesc m_GfxVertexBufDesc;
};

GE_ASSERT_SIZEOF(eCGfxVertexData, 0x2c)
