#pragma once

#include <Engine/ge_enginecomponentbase.h>
#include <Engine/ge_fmod.h>

#include <SharedBase.h>

class eCAudioChannel;
class eCAudioChannelGroup;
class eCAudioSound;
class eCAudioSystem;
struct eSSetupEngine;

enum eEAudioChannelGroup
{
    eEAudioChannelGroup_Master = 0,
    eEAudioChannelGroup_Voice = 1,
    eEAudioChannelGroup_Music = 2,
    eEAudioChannelGroup_FX = 3,
    eEAudioChannelGroup_Ambient = 4,
};

class GE_DLLIMPORT eCAudioModule : public eCEngineComponentBase
{
    // clang-format off
    public: ~eCAudioModule() override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult Shutdown() override;
    public: void Process() override;
    public: void GetDebugLines(bTObjArray<eSModuleDebugLine> &) const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCAudioModule, eCEngineComponentBase)

  public:
    static eCAudioModule &GE_STDCALL GetInstance();

  public:
    void EnableListenerAutoUpdate(GEBool);
    void EnableOcclusionAutoUpdate(GEBool);
    eCAudioChannelGroup *GetChannelGroup(eEAudioChannelGroup) const;
    GEU8 GetChannelGroupPriority(eEAudioChannelGroup) const;
    eCAudioSystem *GetSystem() const;
    GEBool IsListenerAutoUpdateEnabled() const;
    GEBool IsOcclusionAutoUpdateEnabled() const;
    GEBool PlaySample2D(eEAudioChannelGroup, bCString const &, GEFloat, eCAudioChannel *) const;
    GEBool PlaySample3D(eEAudioChannelGroup, bCString const &, bCVector const &, GEFloat, GEFloat, GEFloat,
                        eCAudioChannel *) const;
    GEBool PlayStream2D(eEAudioChannelGroup, bCString const &, GEFloat, eCAudioSound *, eCAudioChannel *) const;
    GEBool PlayStream3D(eEAudioChannelGroup, bCString const &, bCVector const &, GEFloat, GEFloat, GEFloat,
                        eCAudioSound *, eCAudioChannel *) const;
    GEBool UpdateOcclusion(FMOD::Channel *, GEBool) const;

  protected:
    GEBool CreateChannelGroups(eSSetupEngine const &);
    GEBool CreateStream(bCString const &, GEU32, eCAudioSound *) const;
    void DestroyChannelGroups();
    void Invalidate();
    void UpdateListener();
    void UpdateOcclusion();

  private:
    GE_UNIMPL_MEMBERS(52)
};

GE_ASSERT_SIZEOF(eCAudioModule, 0x48)
