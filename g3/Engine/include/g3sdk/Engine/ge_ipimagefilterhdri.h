#pragma once

#include <Engine/ge_ipimagefilterbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCIPImageFilterHDRI : public eCIPImageFilterBase
{
    // clang-format off
    public: virtual bEResult Create(GEInt, GEInt);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCIPImageFilterHDRI() override;
    protected: void OnParseEffectParam(eCGfxShared::eSGfxParameterDesc const &) override;
    protected: void OnParseEffectTechnique(GEInt, eCGfxShared::eSGfxTechniqueDesc const &) override;
    protected: bEResult PreExecuteFilterShader(GEInt) override;
    protected: bEResult UpdateVertexData(GEInt) override;
    protected: bEResult UpdateTargetSize() override;
    // clang-format on

  public:
    eCIPImageFilterHDRI(eCIPImageFilterHDRI const &);
    eCIPImageFilterHDRI();

  public:
    void EnableBloom(GEBool);
    void EnableHDR(GEBool);
    GEFloat GetAberration() const;
    GEFloat GetBSIntensity() const;
    GEFloat GetBSThreshold() const;
    GEFloat GetExposure() const;
    GEFloat GetGamma() const;
    GEFloat GetVignette() const;
    void SetAberration(GEFloat);
    void SetBSIntensity(GEFloat);
    void SetBSThreshold(GEFloat);
    void SetExposure(GEFloat);
    void SetGamma(GEFloat);
    void SetVignette(GEFloat);

  protected:
    eCIPImageFilterHDRI const &operator=(eCIPImageFilterHDRI const &);

  protected:
    void DestroyLocal();
    void Invalidate();
};
