#pragma once

#include <Engine/ge_ipimagefilterbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCIPImageFilterNoise : public eCIPImageFilterBase
{
    // clang-format off
    public: virtual bEResult Create(GEInt, GEInt);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCIPImageFilterNoise() override;
    protected: void OnParseEffectParam(eCGfxShared::eSGfxParameterDesc const &) override;
    protected: void OnParseEffectTechnique(GEInt, eCGfxShared::eSGfxTechniqueDesc const &) override;
    protected: bEResult PreExecuteFilterShader(GEInt) override;
    protected: bEResult UpdateVertexData(GEInt) override;
    protected: bEResult UpdateTargetSize() override;
    // clang-format on

  public:
    eCIPImageFilterNoise(eCIPImageFilterNoise const &);
    eCIPImageFilterNoise();

  public:
    void EnableColorLUT(GEBool);
    void EnableNoise(GEBool);
    GEFloat GetIntensity() const;
    GEFloat GetThreshold() const;
    void SetIntensity(GEFloat);
    void SetThreshold(GEFloat);

  protected:
    eCIPImageFilterNoise const &operator=(eCIPImageFilterNoise const &);

  protected:
    void DestroyLocal();
    void Invalidate();
};
