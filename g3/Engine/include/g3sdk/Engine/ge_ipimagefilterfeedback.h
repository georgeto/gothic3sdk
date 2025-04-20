#pragma once

#include <Engine/ge_ipimagefilterbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCIPImageFilterFeedback : public eCIPImageFilterBase
{
    // clang-format off
    public: virtual bEResult Create(GEInt, GEInt);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCIPImageFilterFeedback() override;
    protected: void OnParseEffectParam(eCGfxShared::eSGfxParameterDesc const &) override;
    protected: void OnParseEffectTechnique(GEInt, eCGfxShared::eSGfxTechniqueDesc const &) override;
    protected: bEResult PreExecuteFilterShader(GEInt) override;
    protected: bEResult UpdateVertexData(GEInt) override;
    protected: bEResult UpdateTargetSize() override;
    // clang-format on

  public:
    eCIPImageFilterFeedback(eCIPImageFilterFeedback const &);
    eCIPImageFilterFeedback();

  public:
    GEFloat GetGrayIntensity() const;
    GEFloat GetGreenIntensity() const;
    GEFloat GetIntensity1() const;
    GEFloat GetIntensity2() const;
    GEFloat GetRedIntensity() const;
    void SetGrayIntensity(GEFloat);
    void SetGreenIntensity(GEFloat);
    void SetIntensity1(GEFloat);
    void SetIntensity2(GEFloat);
    void SetRedIntensity(GEFloat);

  protected:
    eCIPImageFilterFeedback const &operator=(eCIPImageFilterFeedback const &);

  protected:
    void DestroyLocal();
    void Invalidate();
};
