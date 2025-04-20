#pragma once

#include <Engine/ge_enginecomponentbase.h>
#include <Engine/ge_postprocessingeffectbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCPostProcessingAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: virtual bEResult Execute();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCPostProcessingAdmin() override;
    public: bCGuid const & GetID() const override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult ResetResources(GEBool) override;
    public: bEResult RestoreResources(GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCPostProcessingAdmin, eCEngineComponentBase)

  public:
    GEBool ActivateEffect(eEPostprocessingEffect);
    void Enabled(GEBool);
    eEPostprocessingEffect GetActiveEffect() const;
    eCPostProcessingEffectBase *GetEffect(eEPostprocessingEffect) const;
    GEBool IsEnabled() const;
    GEBool IsVideoPlaying() const;
    GEBool PlayVideo(bCString const &);
    GEBool StopVideo();

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(28)
};

GE_ASSERT_SIZEOF(eCPostProcessingAdmin, 0x30)
