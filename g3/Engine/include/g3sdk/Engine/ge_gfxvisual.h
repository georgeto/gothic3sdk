#pragma once

#include <Engine/api/ge_apidevice.h>
#include <Engine/api/ge_apiprimitive.h>
#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCGfxIndexData;
class eCGfxShader;
class eCGfxVertexData;
class eCGfxVertexDecl;

class GE_DLLIMPORT eCGfxVisual : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCGfxVisual const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxVisual() override;
    // clang-format on

  public:
    eCGfxVisual(eCGfxVisual const &);
    eCGfxVisual();

  public:
    eCGfxVisual &operator=(eCGfxVisual const &);

  public:
    eCGfxShared::eSGfxDrawCallDesc &AccessDrawCallDescription();
    bEResult AttachIndexData(eCGfxIndexData *);
    bEResult AttachShader(eCGfxShader *);
    bEResult AttachVertexData(GEU32, eCGfxVertexData *);
    bEResult AttachVertexDecl(eCGfxVertexDecl *);
    void DisableFVF();
    void EnableFVF(GEU32);
    void EnableStream(GEU32, GEBool);
    bEResult Execute();
    bEResult GetAttachedIndexData(eCGfxIndexData *&) const;
    bEResult GetAttachedShader(eCGfxShader *&) const;
    bEResult GetAttachedVertexData(GEU32, eCGfxVertexData *&) const;
    bEResult GetAttachedVertexDecl(eCGfxVertexDecl *&) const;
    bEResult GetCullingMode(eCGfxShared::eECullingMode &) const;
    bEResult GetDepthBias(GEFloat &, GEFloat &) const;
    bEResult GetDepthTesting(eCGfxShared::eECmpFunc &) const;
    bEResult GetDepthWrite(eCGfxShared::eEWrite &) const;
    bEResult GetDrawCallDescription(eCGfxShared::eSGfxDrawCallDesc &) const;
    bEResult GetRenderMode(eCGfxShared::eERenderMode &) const;
    GEU32 GetStreamOffset(GEU32) const;
    GEU32 GetStreamSourceFrequency(GEU32) const;
    GEU32 GetStreamStride(GEU32) const;
    bEResult GetZBias(GEU32 &) const;
    void Invalidate();
    GEBool IsStreamEnabled(GEU32) const;
    bEResult SetCullingMode(eCGfxShared::eECullingMode);
    bEResult SetDepthBias(GEFloat, GEFloat);
    bEResult SetDepthTesting(eCGfxShared::eECmpFunc);
    bEResult SetDepthWrite(eCGfxShared::eEWrite);
    bEResult SetDrawCallDescription(eCGfxShared::eSGfxDrawCallDesc const &);
    bEResult SetRenderMode(eCGfxShared::eERenderMode);
    GEBool SetStreamOffset(GEU32, GEU32);
    GEBool SetStreamSourceFrequency(GEU32, GEU32);
    GEBool SetStreamStride(GEU32, GEU32);
    bEResult SetZBias(GEU32);

  public:
    eCAPIPrimitive *m_pPrimitive;
    eCGfxShared::eERenderMode m_RenderMode;
    eCGfxShared::eECullingMode m_CullingMode;
    eCGfxShared::eECmpFunc m_DepthTesting;
    eCGfxShared::eEWrite m_DepthWrite;
    eCAPIDevice *m_pDevice;
    eCGfxVertexData *m_arrVertexData[4];
    eCGfxVertexDecl *m_pVertexDecl;
    eCGfxIndexData *m_IndexData;
    eCGfxShader *m_pShader;
    GEFloat m_fDepthBias;
    GEFloat m_fSlopeScaleDepthBias;
};

GE_ASSERT_SIZEOF(eCGfxVisual, 0x48)
