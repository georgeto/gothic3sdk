#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/entity/ge_entitypropertyset.h>

#include <SharedBase.h>

class eCAudioSound;

class GE_DLLIMPORT eCAudioEmitter_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCAudioEmitter_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    protected: GEBool IsProcessable() const override;
    public: GEBool SupportsRenderDebugOutput() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    protected: void OnTouch(eCEntity *, eCContactIterator &) override;
    protected: void OnEnterProcessingRange() override;
    protected: void OnExitProcessingRange() override;
    protected: GEBool IsAutoKillEnabled() const override;
    public: void Decay() override;
    public: void GetOnScreenDebugLines(GEU32, bTObjArray<eSPropertySetDebugLine> &) const override;
    protected: void OnUpdatedWorldMatrix() override;
    protected: void OnCacheIn() override;
    protected: void OnCacheOut() override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCAudioEmitter_PS, eCEntityPropertySet)
    GE_PROPERTY(bCString, Sound, m_strSound)
    GE_PROPERTY(GEBool, Enabled, m_bEnabled)
    GE_PROPERTY(GEBool, AutoReset, m_bAutoReset)
    GE_PROPERTY(GEBool, AutoKill, m_bAutoKill)
    GE_PROPERTY(GEBool, UseStream, m_bUseStream)
    GE_PROPERTY(GEFloat, Volume, m_fVolume)
    GE_PROPERTY(GEFloat, MinDistance, m_fMinDistance)
    GE_PROPERTY(GEFloat, MaxDistance, m_fMaxDistance)
    GE_ENUMPROP(eEAudioEmitterMode, SpawningMode, m_enuSpawningMode)
    GE_PROPERTY(bCRange1, SecondsBetweenRepeats, m_rngSecondsBetweenRepeats)
    GE_PROPERTY(bCRange1, RepeatProbability, m_rngRepeatProbability)
    GE_PROPERTY(GEBool, UseMaxRepeats, m_bUseMaxRepeats)
    GE_PADDING(3)
    GE_PROPERTY(bCRange1, MaxNumRepeats, m_rngMaxNumRepeats)

  public:
    void ApplyDefaults();
    void Reset();

  protected:
    GEBool CreateChannel();
    GEBool CreateSound();
    eCAudioSound *GetSound();
    void Invalidate();
    void OnSoundChanged();
    void SpawnSound();

  private:
    GE_UNIMPL_MEMBERS(32)
};

GE_ASSERT_SIZEOF(eCAudioEmitter_PS, 0x6c)

GE_ASSERT_PROPERTY(eCAudioEmitter_PS, m_strSound, 0x14, 4)
GE_ASSERT_PROPERTY(eCAudioEmitter_PS, m_bEnabled, 0x18, 1)
GE_ASSERT_PROPERTY(eCAudioEmitter_PS, m_bAutoReset, 0x19, 1)
GE_ASSERT_PROPERTY(eCAudioEmitter_PS, m_bAutoKill, 0x1a, 1)
GE_ASSERT_PROPERTY(eCAudioEmitter_PS, m_bUseStream, 0x1b, 1)
GE_ASSERT_PROPERTY(eCAudioEmitter_PS, m_fVolume, 0x1c, 4)
GE_ASSERT_PROPERTY(eCAudioEmitter_PS, m_fMinDistance, 0x20, 4)
GE_ASSERT_PROPERTY(eCAudioEmitter_PS, m_fMaxDistance, 0x24, 4)
GE_ASSERT_PROPERTY(eCAudioEmitter_PS, m_enuSpawningMode, 0x28, 8)
GE_ASSERT_PROPERTY(eCAudioEmitter_PS, m_rngSecondsBetweenRepeats, 0x30, 8)
GE_ASSERT_PROPERTY(eCAudioEmitter_PS, m_rngRepeatProbability, 0x38, 8)
GE_ASSERT_PROPERTY(eCAudioEmitter_PS, m_bUseMaxRepeats, 0x40, 1)
GE_ASSERT_PROPERTY(eCAudioEmitter_PS, m_rngMaxNumRepeats, 0x44, 8)
