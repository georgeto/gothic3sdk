#pragma once

#include <Game/ge_movementbase_ps.h>

#include <Engine.h>

class gCCharacterSensor_PS;

enum gECharMovementMode
{
    // TODO: Name gECharMovementMode constants.
    gECharMovementMode_0 = 0x0,
    gECharMovementMode_1 = 0x1, // Standing
    gECharMovementMode_Sneak = 2,
    gECharMovementMode_Walk = 3,
    gECharMovementMode_Run = 4,
    gECharMovementMode_Sprint = 5,
    gECharMovementMode_JumpSteer = 6,
    gECharMovementMode_Swim = 7,
    gECharMovementMode_Dive = 8,
    gECharMovementMode_9 = 9,
    gECharMovementMode_Wade = 10,
    gECharMovementMode_11 = 11,
    gECharMovementMode_Slide = 12,
    gECharMovementMode_FallSteer = 13,
    gECharMovementMode_RagDollDead = 14,
    gECharMovementMode_15 = 15,
    gECharMovementMode_16 = 16,
    gECharMovementMode_17 = 17,
    gECharMovementMode_ForceDWORD = GE_FORCE_DWORD
};

struct gSSpatialState
{
    GE_UNIMPL_STRUCT(gSSpatialState)
};

class GE_DLLIMPORT gCCharacterMovement_PS : public gCMovementBase_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCCharacterMovement_PS() override;
    public: bEResult PostInitializeProperties() override;
    protected: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    protected: GEBool IsProcessable() const override;
    public: GEBool IsEditorRelevant() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: GEInt OnAction(eCInpShared::eSGameKeyMessage const &) override;
    public: void OnTouch(eCEntity *, eCContactIterator &) override;
    public: void OnIntersect(eCEntity *, eCContactIterator &) override;
    public: void OnUntouch(eCEntity *, eCContactIterator &) override;
    protected: void OnEnterProcessingRange() override;
    protected: void OnExitProcessingRange() override;
    protected: void OnPostUpdateInternals() override;
    protected: void OnUpdatedWorldMatrix() override;
    protected: void OnProcess() override;
    protected: void OnPreProcess() override;
    protected: void OnPostRead() override;
    protected: void OnPropertySetAdded() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCCharacterMovement_PS, gCMovementBase_PS)
    GE_PROPERTY(GEBool, DoHeightCorrection, m_bDoHeightCorrection)
    GE_PROPERTY(GEBool, ApplyGravity, m_bApplyGravity)
    GE_PROPERTY(GEBool, IsQuadruped, m_bIsQuadruped)
    GE_PADDING(1)
    GE_PROPERTY(GEFloat, QuadrupedSlopeInertia, m_fQuadrupedSlopeInertia)
    GE_PROPERTY(GEFloat, StepHeight, m_fStepHeight)
    GE_PROPERTY(GEFloat, ForwardSpeedMax, m_fSpeedForwardMax)
    GE_PROPERTY(GEFloat, StrafeSpeedMax, m_fSpeedStrafeMax)
    GE_PROPERTY(GEFloat, BackwardSpeedMax, m_fSpeedBackwardMax)
    GE_PROPERTY(GEFloat, TurnSpeedMax, m_fSpeedTurnMax)
    GE_PROPERTY(GEFloat, TurnSpeedModifier, m_fSpeedTurnModifier)
    GE_PROPERTY(GEFloat, MoveAcceleration, m_fMoveAcceleration)
    GE_PROPERTY(GEFloat, MoveDecceleration, m_fMoveDecceleration)
    GE_PROPERTY(GEFloat, TurnAcceleration, m_fTurnAcceleration)
    GE_PROPERTY(GEFloat, TurnDecceleration, m_fTurnDecceleration)
    GE_PROPERTY(GEFloat, SlowModifier, m_fSlowModifier)
    GE_PROPERTY(GEFloat, FastModifier, m_fFastModifier)
    GE_PROPERTY(GEFloat, SneakModifier, m_fSneakModifier)
    GE_PROPERTY(GEFloat, SteepGroundAngleMin, m_fSteepGroundAngleMin)
    GE_PROPERTY(GEFloat, SteepGroundAngleMax, m_fSteepGroundAngleMax)
    GE_PROPERTY(GEFloat, WalkDownSpeedScale, m_fWalkDownSpeedScale)
    GE_PROPERTY(GEBool, SensorAffectsDirection, m_bSensorAffectsDirection)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, SensorMinSlideAngle, m_fSensorMinSlideAngle)
    GE_PROPERTY(GEFloat, SensorAdvanceDuration, m_fSensorAdvanceDuration)
    GE_PROPERTY(GEFloat, SensorInertia, m_fSensorInertia)
    GE_PROPERTY(GEFloat, SlideInertia, m_fSlideInertia)
    GE_PROPERTY(GEFloat, SlideSpeedMax, m_fSlideSpeedMax)
    GE_PROPERTY(GEFloat, GroundSlopeTransInertia, m_fGroundSlopeTransInertia)
    GE_PROPERTY(GEFloat, AniVelocityInertia, m_fAniVelocityInertia)
    GE_PROPERTY(GEBool, ForceGroundAlignment, m_bForceGroundAlignment)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, JumpStartUpVelocity, m_fJumpStartUpVelocity)
    GE_PROPERTY(GEFloat, JumpSteerScaleFactor, m_fJumpSteerScaleFactor)
    GE_PROPERTY(GEFloat, FallSteerScaleFactor, m_fFallSteerScaleFactor)
    GE_PROPERTY(GEFloat, SwimDepth, m_fSwimDepth)
    GE_PROPERTY(GEBool, CanBePushedWhileIdle, m_bCanBePushedWhileIdle)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, LastFallVelocity, m_fLastFallVelocity)
    GE_PROPERTY(GEBool, TreatWaterAsSolid, m_bTreatWaterAsSolid)
    GE_PADDING(1)

  public:
    static GEBool GE_STDCALL S_GetHeightCorr();
    static void GE_STDCALL S_SetHeightCorr(GEBool);

  public:
    bCMotion &AccessNextStep();
    bCVector &AccessSensorPosition();
    GEBool CanBeHeightCorrected(GEFloat) const;
    GEBool CanFallDown() const;
    GEBool CanJump() const;
    GEBool CanSensorCorrectDirection() const;
    GEBool CanSlide() const;
    GEBool CanStandAtGoal(bCMotion const &, GEBool, GEBool, GEBool) const;
    GEBool CanWalkOnFloor(bCVector const &) const;
    void CheckChangedMovementStates();
    void CheckCharacterGotStuck();
    void CreateDependantShapes();
    void EnableCombatMovementFromSPU(GEBool, eCEntityProxy const &, bCVector &);
    void EnableCombatRotationFromSPU(GEBool, GEFloat);
    void EnableMovementFromSPU(GEBool);
    GEBool FindFloorWaterCeiling(bCVector const &, gSSpatialState &, GEBool, GEBool) const;
    bCVector &GetAlignmentLookAt();
    bCVector const &GetAlignmentLookAt() const;
    eCEntity *GetAlignmentTarget();
    eCEntity const *GetAlignmentTarget() const;
    GEFloat GetBrakingDistance() const;
    GEFloat GetCharacterHeight() const;
    GEBool GetCombatContact() const;
    bCVector GetCurrentPosition() const;
    GEFloat GetCurrentSpeedModifier() const;
    GEFloat GetCurrentVelocity() const;
    GEBool GetDebugMode();
    GEFloat GetDistToCeiling(bCVector const &, GEBool) const;
    GEFloat GetDistToGround(bCVector const &, GEBool) const;
    GEBool GetGoalChanged() const;
    GEFloat GetGoalGroundOffset() const;
    bCVector GetGoalPosition() const;
    GEBool GetGoalReached(GEBool, GEBool, GEBool);
    GEFloat GetGroundSlopeTransScale() const;
    GEFloat GetHalfSpeedTimer();
    GEBool GetIsProcessing();
    gECharMovementMode GetLastMovementMode() const;
    bCVector const &GetLatestGoalPosition() const;
    bCQuaternion const &GetLatestGoalRotation() const;
    bCVector GetLocalAniVelocity() const;
    bCVector GetLocalVelocity() const;
    GEBool GetMovementIsControledByNavigation() const;
    GEBool GetMovementIsControledByPlayer() const;
    GEBool GetMovementIsSelfControled() const;
    gECharMovementMode GetMovementMode() const;
    gECharMovementMode GetMovementModeAtPosition(bCVector const &) const;
    bCMotion const &GetNextStep() const;
    GEFloat GetPredictedDistanceByTime(GEFloat);
    gCCharacterSensor_PS &GetSensor();
    gCCharacterSensor_PS const &GetSensor() const;
    GEBool GetSlideStartedFrontally() const;
    gSSpatialState &GetSpatialState();
    gSSpatialState const &GetSpatialState() const;
    GEFloat GetSpeedByMode(gECharMovementMode);
    GEFloat GetStepSize(bCVector const &) const;
    GEFloat GetWaterDepth() const;
    GEBool IsBraking() const;
    GEBool IsCombatMovementEnabledFromSPU() const;
    GEBool IsCombatRotationEnabledFromSPU() const;
    GEBool IsDiving() const;
    GEBool IsFalling() const;
    GEBool IsFreeLOSAndSurrounding(eCEntity *, GEBool);
    GEBool IsInMovingState() const;
    GEBool IsJumping() const;
    GEBool IsMounted() const;
    GEBool IsMovementEnabledFromSPU();
    GEBool IsRunning() const;
    GEBool IsSneaking() const;
    GEBool IsSprinting() const;
    GEBool IsStanding() const;
    GEBool IsSwimming() const;
    GEBool IsWalking() const;
    void MarkSpatialStateAsUninited(GEBool);
    void ProcessSensorMovements();
    GEFloat PutToGround(GEBool, GEBool);
    void ResetIsProcessing();
    void SetAlignmentLookAt(bCVector const &);
    void SetAlignmentTarget(eCEntity const *);
    void SetCurrentSpeedModifier(GEFloat);
    void SetDebugMode(GEBool);
    void SetGoalGroundEntity(eCEntity *);
    void SetGoalGroundOffset(GEFloat);
    void SetGoalPose(bCMotion const &, GEBool, GEBool);
    void SetGoalPosition(bCVector const &, GEBool, GEBool);
    void SetGoalRotation(bCQuaternion const &);
    void SetHalfSpeedTimer(GEFloat);
    void SetMovementMode(gECharMovementMode);
    void StartControlNPC();
    void StopControlNPC();
    void StopMovement();

  protected:
    void AddToCurrentVelocity(bCVector const &);
    void CalcAniVelocity();
    void CalcDistToGoal();
    void CalcGroundSlopeTransScale();
    void CalcNewRotationAngleAndVelocity(bCVector const &, bCVector const &, GEFloat, GEFloat &, GEFloat &, GEBool);
    void CalcNextSteps();
    void CalcQuadrupedDistances();
    void ClearVolatileFrameStates();
    void ContributeFloorActions();
    void ContributeFloorMovements();
    GEBool CorrectGoalMiss();
    void CorrectWeaponTrigger();
    void CreateDependantPSets();
    void GameReset();
    GEFloat GetCurrentMaxSpeedOfDir(bCVector const &) const;
    bCVector GetCurrentWayDirection();
    GEFloat GetPivotBoxCenterOffset() const;
    void InitFirstPose();
    void Invalidate();
    GEBool NeedsComplexStaticCollisionTests() const;
    void OnFloorMaterialChanged(eEShapeMaterial);
    void ProcessControledMovements();
    void ProcessControledRotation();
    void ProcessControledRotationLookAt(bCVector &);
    void ProcessControledRotationToTarget();
    void ProcessControledTranslation();
    GEBool ProcessHeavyBrake(bCVector const &, GEFloat);
    void ProcessMovementAnimation();
    void ProcessMovements();
    void ProcessPhysicsMovements();
    void ProcessQuadrupedXRotation(bCQuaternion &, GEBool);
    void SaveFrameStates();
    void SetCurrentPosition(bCVector const &, GEBool);
    void SetCurrentVelocity(bCVector const &);
    GEBool SetEffectsByMode(gECharMovementMode);
    GEBool SetFlagsByMode(gECharMovementMode);
    GEBool SetShapeByMode(gECharMovementMode);
    GEBool SetSpeedByMode(gECharMovementMode);
    void ShowDebug();
    void ValidateZoneGeometry() const;

  private:
    static GEBool ms_bHeightCorr;

  private:
    GE_UNIMPL_MEMBERS(832)
};

GE_ASSERT_SIZEOF(gCCharacterMovement_PS, 0x3dc)

GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_bDoHeightCorrection, 0x14, 1)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_bApplyGravity, 0x15, 1)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_bIsQuadruped, 0x16, 1)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fQuadrupedSlopeInertia, 0x18, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fStepHeight, 0x1c, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fSpeedForwardMax, 0x20, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fSpeedStrafeMax, 0x24, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fSpeedBackwardMax, 0x28, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fSpeedTurnMax, 0x2c, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fSpeedTurnModifier, 0x30, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fMoveAcceleration, 0x34, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fMoveDecceleration, 0x38, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fTurnAcceleration, 0x3c, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fTurnDecceleration, 0x40, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fSlowModifier, 0x44, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fFastModifier, 0x48, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fSneakModifier, 0x4c, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fSteepGroundAngleMin, 0x50, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fSteepGroundAngleMax, 0x54, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fWalkDownSpeedScale, 0x58, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_bSensorAffectsDirection, 0x5c, 1)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fSensorMinSlideAngle, 0x60, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fSensorAdvanceDuration, 0x64, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fSensorInertia, 0x68, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fSlideInertia, 0x6c, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fSlideSpeedMax, 0x70, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fGroundSlopeTransInertia, 0x74, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fAniVelocityInertia, 0x78, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_bForceGroundAlignment, 0x7c, 1)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fJumpStartUpVelocity, 0x80, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fJumpSteerScaleFactor, 0x84, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fFallSteerScaleFactor, 0x88, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fSwimDepth, 0x8c, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_bCanBePushedWhileIdle, 0x90, 1)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_fLastFallVelocity, 0x94, 4)
GE_ASSERT_PROPERTY(gCCharacterMovement_PS, m_bTreatWaterAsSolid, 0x98, 1)
