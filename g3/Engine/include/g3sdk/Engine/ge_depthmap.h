#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCGfxImageData;

enum eEDepthMapFormat
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCDepthMap : public bCObjectRefBase
{
    // clang-format off
    public: virtual void SetSize(GEInt);
    public: virtual void SetupImageDesc(eEDepthMapFormat, eCGfxShared::eSGfxLayersDesc &) const;
    public: virtual bEResult Create(GEInt, GEBool, eEDepthMapFormat, GEU32);
    public: virtual GEBool DestroyRenderTarget();
    public: virtual GEBool CreateRenderTarget(GEBool);
    public: virtual GEBool SetRenderTarget(eCGfxShared::eECubeMapFace);
    public: virtual GEBool ResetRenderTarget();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    protected: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCDepthMap() override;
    // clang-format on

  public:
    eCDepthMap(eCDepthMap const &);
    eCDepthMap();

  public:
    eCDepthMap &operator=(eCDepthMap const &);

  public:
    eEDepthMapFormat GetFormat() const;
    eCGfxImageData *GetImage() const;
    GEInt GetSize() const;
    GEBool IsFormatSupported(eEDepthMapFormat);
    eEDepthMapFormat SetFormat(eEDepthMapFormat);
    void SetStoreDepthBuffer(GEBool);

  protected:
    void Invalidate();
};
