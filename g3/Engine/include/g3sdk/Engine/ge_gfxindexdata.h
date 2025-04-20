#pragma once

#include <Engine/api/ge_apidevice.h>
#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCAPIIndexData;

class GE_DLLIMPORT eCGfxIndexData : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCGfxIndexData const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxIndexData() override;
    // clang-format on

  public:
    eCGfxIndexData(eCGfxIndexData const &);
    eCGfxIndexData();

  public:
    eCGfxIndexData &operator=(eCGfxIndexData const &);

  public:
    bEResult Create(eCGfxShared::eSGfxIndexBufDesc const &);
    bEResult GetBufferDescription(eCGfxShared::eSGfxIndexBufDesc &) const;
    void Invalidate();
    bEResult LockBuffer(GEUInt, GEUInt, GEU32, GELPByte *);
    bEResult UnlockBuffer();

  protected:
    bEResult CreateBuffer(eCGfxShared::eSGfxIndexBufDesc const &);
    bEResult DestroyBuffer();
    bEResult GetIndexData(eCAPIIndexData *&);
    bEResult SetIndexData(eCAPIIndexData *);

  public:
    eCAPIDevice *m_pDevice;
    GEBool m_bBufferLocked;
    GE_PADDING(0x3)
    eCAPIIndexData *m_pIndexData;
    eCGfxShared::eSGfxIndexBufDesc m_GfxIndexBufDesc;
};

GE_ASSERT_SIZEOF(eCGfxIndexData, 0x28)
