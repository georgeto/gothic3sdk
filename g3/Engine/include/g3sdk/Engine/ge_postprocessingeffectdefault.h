#pragma once

#include <Engine/ge_postprocessingeffectbase.h>

#include <SharedBase.h>

class eCGfxImageData;

class GE_DLLIMPORT eCPostProcessingEffectDefault : public eCPostProcessingEffectBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCPostProcessingEffectDefault() override;
    public: eEPostprocessingEffect GetType() const override;
    public: void OnActived() override;
    public: void OnDeactived() override;
    public: bEResult OnResetResources(GEBool) override;
    public: bEResult OnRestoreResources(GEBool) override;
    public: bEResult Execute() override;
    // clang-format on

  public:
    eCPostProcessingEffectDefault(eCPostProcessingEffectDefault const &);
    eCPostProcessingEffectDefault();

  public:
    eCGfxImageData *GetBackBufferTexture() const;
    void SetBackBufferTexture(eCGfxImageData *);

  protected:
    void DestroyLocal();
    void Invalidate();
};
