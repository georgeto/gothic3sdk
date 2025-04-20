#pragma once

#include <Engine/ge_ipimagefilterbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCIPImageFilterMaskHightLights : public eCIPImageFilterBase
{
    // clang-format off
    public: virtual bEResult Create(GEInt, GEInt);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCIPImageFilterMaskHightLights() override;
    protected: void OnParseEffectParam(eCGfxShared::eSGfxParameterDesc const &) override;
    protected: void OnParseEffectTechnique(GEInt, eCGfxShared::eSGfxTechniqueDesc const &) override;
    protected: bEResult PreExecuteFilterShader(GEInt) override;
    protected: bEResult UpdateVertexData(GEInt) override;
    protected: bEResult UpdateTargetSize() override;
    // clang-format on

  public:
    eCIPImageFilterMaskHightLights(eCIPImageFilterMaskHightLights const &);
    eCIPImageFilterMaskHightLights();

  public:
    void EnableHDR(GEBool);
    GEFloat GetBSIntensity() const;
    GEFloat GetBSThreshold() const;
    GEFloat GetExposure() const;
    GEFloat GetGamma() const;
    GEFloat GetMultiplier() const;
    GEFloat GetThreshold() const;
    GEFloat GetVignette() const;
    void SetBSIntensity(GEFloat);
    void SetBSThreshold(GEFloat);
    void SetExposure(GEFloat);
    void SetGamma(GEFloat);
    void SetMultiplier(GEFloat);
    void SetThreshold(GEFloat);
    void SetVignette(GEFloat);

  protected:
    eCIPImageFilterMaskHightLights const &operator=(eCIPImageFilterMaskHightLights const &);

  protected:
    void DestroyLocal();
    void Invalidate();
};
