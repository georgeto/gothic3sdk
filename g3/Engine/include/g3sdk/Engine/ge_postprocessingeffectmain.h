#pragma once

#include <Engine/ge_postprocessingeffectbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCPostProcessingEffectMain : public eCPostProcessingEffectBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCPostProcessingEffectMain() override;
    public: eEPostprocessingEffect GetType() const override;
    public: void OnActived() override;
    public: void OnDeactived() override;
    public: bEResult OnResetResources(GEBool) override;
    public: bEResult OnRestoreResources(GEBool) override;
    public: bEResult Execute() override;
    // clang-format on

  public:
    eCPostProcessingEffectMain(eCPostProcessingEffectMain const &);
    eCPostProcessingEffectMain();

  public:
    GEFloat GetBloomAberration() const;
    GEFloat GetBloomIntensity() const;
    GEFloat GetBloomThreshold() const;
    GEFloat GetDOFMaxBlur() const;
    GEFloat GetFeedbackGrayIntensity() const;
    GEFloat GetFeedbackGreenIntensity() const;
    GEFloat GetFeedbackIntensity1() const;
    GEFloat GetFeedbackIntensity2() const;
    GEFloat GetFeedbackRedIntensity() const;
    bCVector2 const &GetFocalRange() const;
    GEFloat GetHDRIBlueShiftIntensity() const;
    GEFloat GetHDRIBlueShiftThreshold() const;
    GEFloat GetHDRIExposure() const;
    GEFloat GetHDRIGamma() const;
    GEFloat GetHDRIVignette() const;
    GEFloat GetNoiseIntensity() const;
    GEFloat GetNoiseThreshold() const;
    void SetBloomAberration(GEFloat);
    void SetBloomIntensity(GEFloat);
    void SetBloomThreshold(GEFloat);
    void SetDOFMaxBlur(GEFloat);
    void SetFeedbackGrayIntensity(GEFloat);
    void SetFeedbackGreenIntensity(GEFloat);
    void SetFeedbackIntensity1(GEFloat);
    void SetFeedbackIntensity2(GEFloat);
    void SetFeedbackRedIntensity(GEFloat);
    void SetFocalRange(bCVector2 const &);
    void SetHDRIBlueShiftIntensity(GEFloat);
    void SetHDRIBlueShiftThreshold(GEFloat);
    void SetHDRIExposure(GEFloat);
    void SetHDRIGamma(GEFloat);
    void SetHDRIVignette(GEFloat);
    void SetNoiseIntensity(GEFloat);
    void SetNoiseThreshold(GEFloat);

  protected:
    void DestroyLocal();
    void Invalidate();
};
