#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/entity/proxy/ge_entityproxy.h>
#include <Engine/ge_triggerbase_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCTrigger_PS : public eCTriggerBase_PS
{
    // clang-format off
    public: virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance();
    protected: virtual void TriggerTarget(eCEntity *, eCEntity *, eCContactIterator &);
    protected: virtual void UntriggerTarget(eCEntity *, eCEntity *, eCContactIterator &);
    protected: virtual GEBool CanBeActivatedNow(eCEntity *, eCContactIterator &);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCTrigger_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    protected: GEBool IsProcessable() const override;
    public: GEBool IsEditorRelevant() const override;
    public: void OnTrigger(eCEntity *, eCEntity *) override;
    public: void OnUntrigger(eCEntity *, eCEntity *) override;
    public: void OnTouch(eCEntity *, eCContactIterator &) override;
    public: void OnIntersect(eCEntity *, eCContactIterator &) override;
    public: void OnUntouch(eCEntity *, eCContactIterator &) override;
    public: void OnDamage(eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator &) override;
    protected: void OnEnterProcessingRange() override;
    protected: void Trigger(bCString const &) override;
    protected: void OnCacheIn() override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnProcess() override;
    protected: void OnPostRead() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCTrigger_PS, eCTriggerBase_PS)
    GE_PROPERTY(GEBool, IsEnabled, m_bIsEnabled)
    GE_PADDING(1)
    GE_PROPERTY(GEU16, MaxActivationCount, m_u16MaxActivationCount)
    GE_PROPERTY(GEU16, MaxCountPerEntity, m_u16MaxCountPerEntity)
    GE_PROPERTY(GEBool, SendUntrigger, m_bSendUntrigger)
    GE_PROPERTY(GEBool, ReactToTrigger, m_bReactToTrigger)
    GE_PROPERTY(GEBool, ReactToTouch, m_bReactToTouch)
    GE_PROPERTY(GEBool, ReactToDamage, m_bReactToDamage)
    GE_PROPERTY(GEBool, ReactToIntersect, m_bReactToIntersect)
    GE_PROPERTY(GEBool, ReactToStart, m_bReactToStart)
    GE_PROPERTY(GEBool, ReactToLoad, m_bReactToLoad)
    GE_PROPERTY(GEBool, ReactToProcessingRange, m_bReactToProcessingRange)
    GE_PROPERTY(GEBool, ReactToCacheInRange, m_bReactToCacheInRange)
    GE_PADDING(1)
    GE_PROPERTY(bCString, RecognizesEntityName, m_strRecognizesEntityName)
    GE_PROPERTY(GEBool, RecognizesObjects, m_bRecognizesObjects)
    GE_PROPERTY(GEBool, RecognizesPlayers, m_bRecognizesPlayer)
    GE_PROPERTY(GEBool, RecognizesNPCs, m_bRecognizesNPCs)
    GE_PADDING(1)
    GE_PROPERTY(GEU16, RecognizesCollisionGroup, m_u16RecognizesCollGroup)
    GE_PROPERTY(GEU16, RecognizesShapeGroup, m_u16RecognizesShapeGroup)
    GE_ENUMPROP(eEPropertySetType, RecognizesPSType, m_enuRecognizesPSType)
    GE_PROPERTY(bCString, RecognizesEvent, m_strRecognizesEvent)
    GE_PROPERTY(GEFloat, FireDelaySec, m_fFireDelaySec)
    GE_PROPERTY(GEFloat, RetriggerWaitSec, m_fRetriggerWaitSec)
    GE_PROPERTY(GEFloat, AutoUntriggerAfterSec, m_fAutoUntriggerAfterSec)
    GE_PROPERTY(GEInt, DamageTreshold, m_iDamageTreshold)
    GE_PROPERTY(GEFloat, VelocityTresholdMSec, m_fVelocityTresholdMSec)
    GE_PROPERTY(bTObjArray<eCEntityProxy>, EntitiesVisited, m_arrEntitiesVisited)   // Read only
    GE_PROPERTY(bTValArray<GEU16>, EntitiesVisitedCount, m_arrEntitiesVisitedCount) // Read only
    GE_ENUMPROP(eEEventType, LastEventType, m_enuLastEvent)                         // Read only
    GE_PROPERTY(eCEntityProxy, OtherEntity, m_OtherEntity)                          // Read only
    GE_PROPERTY(eCEntityProxy, InflictorEntity, m_InflictorEntity)                  // Read only
    GE_ENUMPROP(eEEventType, RunningEventType, m_enuRunningEventType)               // Read only
    GE_PROPERTY(bCString, TouchType, m_strTouchType)                                // Read only

  public:
    bTPropertyContainer<eEPropertySetType> &AccessRecognizePSType();
    void ClearTriggeredList(eCEntity *);
    void ClearTriggeredList();
    bTPropertyContainer<eEPropertySetType> const &GetRecognizePSType() const;
    void SetRecognizePSType(bTPropertyContainer<eEPropertySetType> const &);

  protected:
    void Invalidate();

  private:
    void ActivateTrigger(eCEntity *, eEEventType, eCContactIterator &);
    void DeactivateTrigger(eCEntity *, eEEventType, eCContactIterator &);

  private:
    GE_UNIMPL_MEMBERS(40)
};

GE_ASSERT_SIZEOF(eCTrigger_PS, 0xe4)

GE_ASSERT_PROPERTY(eCTrigger_PS, m_bIsEnabled, 0x1c, 1)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_u16MaxActivationCount, 0x1e, 2)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_u16MaxCountPerEntity, 0x20, 2)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_bSendUntrigger, 0x22, 1)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_bReactToTrigger, 0x23, 1)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_bReactToTouch, 0x24, 1)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_bReactToDamage, 0x25, 1)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_bReactToIntersect, 0x26, 1)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_bReactToStart, 0x27, 1)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_bReactToLoad, 0x28, 1)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_bReactToProcessingRange, 0x29, 1)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_bReactToCacheInRange, 0x2a, 1)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_strRecognizesEntityName, 0x2c, 4)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_bRecognizesObjects, 0x30, 1)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_bRecognizesPlayer, 0x31, 1)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_bRecognizesNPCs, 0x32, 1)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_u16RecognizesCollGroup, 0x34, 2)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_u16RecognizesShapeGroup, 0x36, 2)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_enuRecognizesPSType, 0x38, 8)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_strRecognizesEvent, 0x40, 4)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_fFireDelaySec, 0x44, 4)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_fRetriggerWaitSec, 0x48, 4)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_fAutoUntriggerAfterSec, 0x4c, 4)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_iDamageTreshold, 0x50, 4)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_fVelocityTresholdMSec, 0x54, 4)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_arrEntitiesVisited, 0x58, 12)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_arrEntitiesVisitedCount, 0x64, 12)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_enuLastEvent, 0x70, 8)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_OtherEntity, 0x78, 28)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_InflictorEntity, 0x94, 28)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_enuRunningEventType, 0xb0, 8)
GE_ASSERT_PROPERTY(eCTrigger_PS, m_strTouchType, 0xb8, 4)
