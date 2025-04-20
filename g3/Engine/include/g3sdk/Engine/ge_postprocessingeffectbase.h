#pragma once

#include <SharedBase.h>

class eCIPImageFilterBase;

enum eEPostprocessingEffect
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCPostProcessingEffectBase : public bCObjectRefBase
{
    // clang-format off
    public: virtual eEPostprocessingEffect GetType() const = 0;
    public: virtual void OnActived();
    public: virtual void OnDeactived();
    public: virtual bEResult OnResetResources(GEBool);
    public: virtual bEResult OnRestoreResources(GEBool);
    public: virtual bEResult Execute();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCPostProcessingEffectBase() override;
    // clang-format on

  public:
    eCPostProcessingEffectBase(eCPostProcessingEffectBase const &);
    eCPostProcessingEffectBase();

  protected:
    void DestroyLocal();
    eCIPImageFilterBase *GetImageFilter() const;
    void Invalidate();
    void SetImageFilter(eCIPImageFilterBase *);
};
