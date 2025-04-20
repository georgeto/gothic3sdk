#pragma once

#include <Game/GameEnum.h>
#include <Game/ge_charactermovement_ps.h>

#include <Engine.h>

class gCDynamicCollisionCircle_PS;
class gCNavPath_PS;
class gCPrefPath_PSObj;

enum gEGotoStatus
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT gCNavigation_PS : public eCEntityPropertySet
{
  public:
    struct gSObstacleEvadeSwitch
    {
        bCPropertyID m_Evade;
        GEBool m_bValid;
    };

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCNavigation_PS() override;
    public: GEBool OnNotifyPropertyValueChangedEnterEx(GELPCChar, GEBool) override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    public: GEBool SupportsRenderDebugOutput() const override;
    public: bEResult ReadSaveGame(bCIStream &) override;
    public: bEResult WriteSaveGame(bCOStream &) override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void OnSaveGameEntityPostRead() override;
    protected: void OnTouch(eCEntity *, eCContactIterator &) override;
    protected: void OnIntersect(eCEntity *, eCContactIterator &) override;
    protected: void OnUntouch(eCEntity *, eCContactIterator &) override;
    protected: void OnEnterProcessingRange() override;
    protected: void OnExitProcessingRange() override;
    public: void OnRenderDebug() override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnPreProcess() override;
    public: void OnPostRead() override;
    public: void OnPostCopy(eCEntityPropertySet const &) override;
    public: void OnPropertySetAdded() override;
    public: void OnPropertySetRemoved() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCNavigation_PS, eCEntityPropertySet)
    GE_PROPERTY(bCVector, StartPosition, m_vecStartPosition)
    GE_PROPERTY(bCPropertyID, WorkingPoint, m_WorkingPoint)
    GE_PROPERTY(bCPropertyID, RelaxingPoint, m_RelaxingPoint)
    GE_PROPERTY(bCPropertyID, SleepingPoint, m_SleepingPoint)
    GE_PROPERTY(bCString, Routine, m_strRoutine)
    GE_PROPERTY(bTValArray<bCPropertyID>, WorkingPoints, m_arrWorkingPoints)
    GE_PROPERTY(bTValArray<bCPropertyID>, RelaxingPoints, m_arrRelaxingPoints)
    GE_PROPERTY(bTValArray<bCPropertyID>, SleepingPoints, m_arrSleepingPoints)
    GE_PROPERTY(bTObjArray<bCString>, RoutineNames, m_arrRoutineNames)
    GE_PROPERTY(eCEntityProxy, CurrentDestinationPointProxy, m_CurrentDestinationPointProxy)
    GE_PROPERTY(eCEntityProxy, CurrentZoneEntityProxy, m_CurrentZoneEntityProxy)
    GE_PROPERTY(eCEntityProxy, LastZoneEntityProxy, m_LastZoneEntityProxy)
    GE_PROPERTY(bCVector, LastUseableNavigationPosition, m_vecLastUseableNavigationPosition)
    GE_PROPERTY(bCPropertyID, LastUseableNavigationZoneID, m_LastUseableNavigationZoneID)
    GE_PROPERTY(GEBool, LastUseableNavigationZoneIsPath, m_bLastUseableNavigationZoneIsPath)
    GE_PADDING(1)

  public:
    gEDirection &AccessCurrentAniDirection();
    bTValArray<bCVector> &AccessCurrentDestination();
    bTValArray<bCPropertyID> &AccessCurrentDestinationID();
    bTValArray<bCMotion> &AccessCurrentInterPose();
    bTValArray<gCNavPath_PS *> &AccessCurrentNavPath();
    bTValArray<bCMotion> &AccessDestination();
    bTValArray<bCVector> &AccessEvade();
    GEU32 &AccessIsOnDestinationTimeStamp();
    bCPropertyID &AccessLastObstacleID();
    gSObstacleEvadeSwitch &AccessNPCEvadeSwitch();
    bTValArray<bCMotion> &AccessNext();
    gSObstacleEvadeSwitch &AccessObstacleEvadeSwitch();
    bTValArray<bCVector> &AccessPassed();
    eCEntityProxy &AccessReachedTargetEntityProxy();
    GEFloat &AccessUnderWaterDepth();
    eCEntityProxy &AccessWishedTargetEntityProxy();
    GEBool CanCorrectTarget(bCVector const &);
    GEBool FillNextForNavigationPath(bCVector const &, bCVector const &);
    GEBool FillNextForPreferredPath();
    gCCharacterMovement_PS *GetCharacterMovement();
    gEDirection GetCurrentAniDirection() const;
    bTValArray<bCVector> const &GetCurrentDestination() const;
    bTValArray<bCPropertyID> const &GetCurrentDestinationID() const;
    bTValArray<bCMotion> const &GetCurrentInterPose() const;
    bTValArray<gCNavPath_PS *> const &GetCurrentNavPath() const;
    bCVector const &GetCurrentTarget() const;
    gCDynamicCollisionCircle_PS *GetDCC() const;
    bTValArray<bCMotion> const &GetDestination() const;
    GEBool GetDontUseLimitedNavPaths();
    GEBool GetEnabled() const;
    bTValArray<bCVector> const &GetEvade() const;
    GEBool const GetFinalTargetDetected() const;
    bCMotion const &GetGoalPose();
    GEBool GetGoalReached();
    gEGotoStatus GetGotoStatus() const;
    GEBool GetHasFinalTarget() const;
    eCEntity *GetInteractObject() const;
    GEBool GetIsOnDestination() const;
    GEU32 GetIsOnDestinationTimeStamp() const;
    GEBool GetKilledByDeadlock() const;
    GEInt const GetLastNegZoneStake() const;
    bCPropertyID const &GetLastObstacleID() const;
    bCVector const &GetLastUseableNavPosition() const;
    GEBool GetLastUseableNavZoneID(bCPropertyID &) const;
    gCNavPath_PS *GetNavigationPath() const;
    GEBool GetNewInterPose();
    bTValArray<bCMotion> const &GetNext() const;
    gEDirection const GetNextAniDirection() const;
    GEBool const GetOnTheWay() const;
    bTValArray<bCVector> const &GetPassed() const;
    gCPrefPath_PSObj *GetPreferredPathPSObject() const;
    eCEntityProxy const &GetReachedTargetEntityProxy() const;
    eCEntityProxy &GetRelaxingPointProxy();
    eCEntityProxy &GetSleepingPointProxy();
    GEFloat GetUnderWaterDepth() const;
    gECharMovementMode GetWishedMovementMode() const;
    eCEntityProxy const &GetWishedTargetEntityProxy() const;
    eCEntityProxy &GetWorkingPointProxy();
    GEBool HasRoutinePointRoamOrPatrol();
    GEBool IsFoorDetectionFailed();
    GEBool IsInProcessingRange();
    void Reset(GEBool, GEBool, GEBool);
    GEBool RunSimpleMovement();
    void SetCharacterMovement(gCCharacterMovement_PS *);
    void SetCurrentAniDirection(gEDirection);
    void SetCurrentTarget(bCVector const &);
    void SetDCC(gCDynamicCollisionCircle_PS *);
    void SetEnabled(GEBool);
    void SetFinalTargetDetected(GEBool);
    void SetGoalPose(bCMotion const &, GEBool);
    void SetGoalReached();
    void SetGotoStatus(gEGotoStatus);
    void SetHasFinalTarget(GEBool);
    void SetInteractObject(eCEntity *);
    void SetIsOnDestination(GEBool);
    void SetIsOnDestinationTimeStamp(GEU32);
    void SetKilledByDeadlock(GEBool);
    void SetLastNegZoneStake(GEInt);
    void SetLastUseableNavPosition(bCVector const &);
    void SetLastUseableNavZoneID(bCPropertyID const &, GEBool);
    void SetNavigationPath(gCNavPath_PS *);
    void SetNewInterPose(GEBool);
    void SetNextAniDirection(gEDirection);
    void SetOnTheWay(GEBool);
    void SetPreferredPathPSObject(gCPrefPath_PSObj *);
    void SetReachedTargetEntityProxy(eCEntityProxy const &);
    void SetUnderWaterDepth(GEFloat);
    void SetWishedMovementMode(gECharMovementMode);
    void SetWishedTargetEntityProxy(eCEntityProxy const &);
    GEBool TestNextOnPreferredPath();
    GEFloat TestPreferredPathUse(gCPrefPath_PSObj *);
    void UpdateInteractObject();
    void UpdateSimpleMovementTime(GEFloat, GEBool);
    void UpdateZoneIDs();

  protected:
    void GameReset();
    void Invalidate();

  public:
    GEBool m_bIsOnDestination;
    GE_PADDING(2)
    GEInt m_IsOnDestinationTimeStamp;
    bTValArray<bCMotion> m_arrDestination;
    bTValArray<bCVector> m_arrEvade;
    bCPropertyID m_LastObstacleID;
    bTValArray<bCMotion> m_arrNext;
    bTValArray<bCVector> m_arrPassed;
    eCEntityProxy m_WishedTargetEntityProxy;
    eCEntityProxy m_ReachedTargetEntityProxy;
    gEDirection m_enuCurrentAniDirection;
    GEFloat m_fUnderWaterDepth;
    bTValArray<bCVector> m_arrCurrentDestination;
    bTValArray<bCPropertyID> m_arrCurrentDestinationID;
    bTPtrArray<gCNavPath_PS *> m_arrCurrentNavPath;
    bCVector m_CurrentTarget;
    bTValArray<bCMotion> m_arrCurrentInterPose;
    GEInt m_iLastNegZoneStake;
    GEBool m_bOnTheWay;
    GEBool m_bFinalTargetDetected;
    GE_PADDING(2)
    gCPrefPath_PSObj *m_pPreferredPathPSObject;
    GELPVoid m_pNavigationPath;
    GELPVoid m_DCC;
    gCCharacterMovement_PS *m_pCharacterMovement;
    GEChar __UNK_01E4;
    GEBool m_bIsInProcessingRange;
    GEBool m_bIsFoorDetectionFailed;
    GE_PADDING(1)
    GEUInt m_uTimeSinceLastRunNPCNavigation;
    bCMotion m_GoalPose;
    GEBool m_bGoalPoseSet;
    GEBool m_bGoalNotReached;
    GE_PADDING(2)
    gEDirection m_enuNextAniDirection;
    GEChar __UNK_0210;
    GEBool m_bNewInterPose;
    GE_PADDING(2)
    GELPVoid m_pInteractObject;
    gECharMovementMode m_enuWishedMovementMode;
    gEGotoStatus m_enuGotoStatus;
    GEBool m_bHasFinalTarget;
    GE_PADDING(3)
    gSObstacleEvadeSwitch m_ObstacleEvadeSwitch;
    gSObstacleEvadeSwitch m_NPCEvadeSwitch;
    GEBool m_bEnabled;
    GEBool m_bKilledByDeadlock;
    GE_PADDING(2)
    eCEntityProxy m_WorkingPointProxy;
    eCEntityProxy m_RelaxingPointProxy;
    eCEntityProxy m_SleepingPointProxy;
};

GE_ASSERT_SIZEOF(gCNavigation_PS, 0x2b0)

GE_ASSERT_PROPERTY(gCNavigation_PS, m_vecStartPosition, 0x14, 12)
GE_ASSERT_PROPERTY(gCNavigation_PS, m_WorkingPoint, 0x20, 20)
GE_ASSERT_PROPERTY(gCNavigation_PS, m_RelaxingPoint, 0x34, 20)
GE_ASSERT_PROPERTY(gCNavigation_PS, m_SleepingPoint, 0x48, 20)
GE_ASSERT_PROPERTY(gCNavigation_PS, m_strRoutine, 0x5c, 4)
GE_ASSERT_PROPERTY(gCNavigation_PS, m_arrWorkingPoints, 0x60, 12)
GE_ASSERT_PROPERTY(gCNavigation_PS, m_arrRelaxingPoints, 0x6c, 12)
GE_ASSERT_PROPERTY(gCNavigation_PS, m_arrSleepingPoints, 0x78, 12)
GE_ASSERT_PROPERTY(gCNavigation_PS, m_arrRoutineNames, 0x84, 12)
GE_ASSERT_PROPERTY(gCNavigation_PS, m_CurrentDestinationPointProxy, 0x90, 28)
GE_ASSERT_PROPERTY(gCNavigation_PS, m_CurrentZoneEntityProxy, 0xac, 28)
GE_ASSERT_PROPERTY(gCNavigation_PS, m_LastZoneEntityProxy, 0xc8, 28)
GE_ASSERT_PROPERTY(gCNavigation_PS, m_vecLastUseableNavigationPosition, 0xe4, 12)
GE_ASSERT_PROPERTY(gCNavigation_PS, m_LastUseableNavigationZoneID, 0xf0, 20)
GE_ASSERT_PROPERTY(gCNavigation_PS, m_bLastUseableNavigationZoneIsPath, 0x104, 1)
