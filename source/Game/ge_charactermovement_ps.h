#ifndef GE_CHARACTERMOVEMENT_PS_H_INCLUDED
#define GE_CHARACTERMOVEMENT_PS_H_INCLUDED

struct gSSpatialState;

enum gECharMovementMode
{
    //FIXME: gECharMovementMode constants.
    gECharMovementMode_0          = 0x0,
    gECharMovementMode_1          = 0x1,
    gECharMovementMode_Sneak      = 2,
    gECharMovementMode_Walk       = 3,
    gECharMovementMode_Run        = 4,
    gECharMovementMode_Sprint     = 5,
    gECharMovementMode_JumpSteer  = 6,
    gECharMovementMode_Swim       = 7,
    gECharMovementMode_8          = 8,
    gECharMovementMode_9          = 9,
    gECharMovementMode_Wade       = 10,
    gECharMovementMode_11         = 11,
    gECharMovementMode_Slide      = 12,
    gECharMovementMode_FallSteer  = 13,
    gECharMovementMode_14         = 14,
    gECharMovementMode_15         = 15,
    gECharMovementMode_16         = 16,
    gECharMovementMode_17         = 17,
    gECharMovementMode_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT gCCharacterMovement_PS :
    public gCMovementBase_PS
{
    public:    virtual GEU16             GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult          Write( bCOStream & );
    public:    virtual bEResult          Read( bCIStream & );
    public:    virtual void              Destroy( void );
    public:    virtual bEResult          Create( void );
    public:    virtual bEResult          CopyFrom( bCObjectBase const & );
    public:    virtual                  ~gCCharacterMovement_PS( void );
    public:    virtual bEResult          PostInitializeProperties( void );
    protected: virtual GEBool            OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
    public:    virtual eEPropertySetType GetPropertySetType( void ) const;
    protected: virtual GEBool            IsProcessable( void ) const;
    public:    virtual GEBool            IsEditorRelevant( void ) const;
    public:    virtual void              GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );
    public:    virtual void              OnTouch( eCEntity *, eCContactIterator & );
    public:    virtual void              OnIntersect( eCEntity *, eCContactIterator & );
    public:    virtual void              OnUntouch( eCEntity *, eCContactIterator & );
    protected: virtual void              OnEnterProcessingRange( void );
    protected: virtual void              OnExitProcessingRange( void );
    protected: virtual void              OnPostUpdateInternals( void );
    protected: virtual void              OnUpdatedWorldMatrix( void );
    protected: virtual void              OnProcess( void );
    protected: virtual void              OnPreProcess( void );
    protected: virtual void              OnPostRead( void );
    protected: virtual void              OnPropertySetAdded( void );

    private:
        static GEBool ms_bHeightCorr;

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        static GEBool GE_STDCALL                       S_GetHeightCorr( void );
        static void GE_STDCALL                         S_SetHeightCorr( GEBool );

    public:
        gCCharacterMovement_PS( gCCharacterMovement_PS const & );
        gCCharacterMovement_PS( void );

    public:
        gCCharacterMovement_PS const & operator = ( gCCharacterMovement_PS const & );

    public:
        GEFloat &                    AccessAniVelocityInertia( void );
        GEBool &                     AccessApplyGravity( void );
        GEFloat &                    AccessBackwardSpeedMax( void );
        GEBool &                     AccessCanBePushedWhileIdle( void );
        GEBool &                     AccessDoHeightCorrection( void );
        GEFloat &                    AccessFallSteerScaleFactor( void );
        GEFloat &                    AccessFastModifier( void );
        GEBool &                     AccessForceGroundAlignment( void );
        GEFloat &                    AccessForwardSpeedMax( void );
        GEFloat &                    AccessGroundSlopeTransInertia( void );
        GEBool &                     AccessIsQuadruped( void );
        GEFloat &                    AccessJumpStartUpVelocity( void );
        GEFloat &                    AccessJumpSteerScaleFactor( void );
        GEFloat &                    AccessLastFallVelocity( void );
        GEFloat &                    AccessMoveAcceleration( void );
        GEFloat &                    AccessMoveDecceleration( void );
        bCMotion &                   AccessNextStep( void );
        GEFloat &                    AccessQuadrupedSlopeInertia( void );
        GEFloat &                    AccessSensorAdvanceDuration( void );
        GEBool &                     AccessSensorAffectsDirection( void );
        GEFloat &                    AccessSensorInertia( void );
        GEFloat &                    AccessSensorMinSlideAngle( void );
        bCVector &                   AccessSensorPosition( void );
        GEFloat &                    AccessSlideInertia( void );
        GEFloat &                    AccessSlideSpeedMax( void );
        GEFloat &                    AccessSlowModifier( void );
        GEFloat &                    AccessSneakModifier( void );
        GEFloat &                    AccessSteepGroundAngleMax( void );
        GEFloat &                    AccessSteepGroundAngleMin( void );
        GEFloat &                    AccessStepHeight( void );
        GEFloat &                    AccessStrafeSpeedMax( void );
        GEFloat &                    AccessSwimDepth( void );
        GEBool &                     AccessTreatWaterAsSolid( void );
        GEFloat &                    AccessTurnAcceleration( void );
        GEFloat &                    AccessTurnDecceleration( void );
        GEFloat &                    AccessTurnSpeedMax( void );
        GEFloat &                    AccessTurnSpeedModifier( void );
        GEFloat &                    AccessWalkDownSpeedScale( void );
        GEBool                       CanBeHeightCorrected( GEFloat ) const;
        GEBool                       CanFallDown( void ) const;
        GEBool                       CanJump( void ) const;
        GEBool                       CanSensorCorrectDirection( void ) const;
        GEBool                       CanSlide( void ) const;
        GEBool                       CanStandAtGoal( bCMotion const &, GEBool, GEBool, GEBool ) const;
        GEBool                       CanWalkOnFloor( bCVector const & ) const;
        void                         CheckChangedMovementStates( void );
        void                         CheckCharacterGotStuck( void );
        void                         CreateDependantShapes( void );
        void                         EnableCombatMovementFromSPU( GEBool, eCEntityProxy const &, bCVector & );
        void                         EnableCombatRotationFromSPU( GEBool, GEFloat );
        void                         EnableMovementFromSPU( GEBool );
        GEBool                       FindFloorWaterCeiling( bCVector const &, gSSpatialState &, GEBool, GEBool ) const;
        bCVector &                   GetAlignmentLookAt( void );
        bCVector const &             GetAlignmentLookAt( void ) const;
        eCEntity *                   GetAlignmentTarget( void );
        eCEntity const *             GetAlignmentTarget( void ) const;
        GEFloat const &              GetAniVelocityInertia( void ) const;
        GEBool const &               GetApplyGravity( void ) const;
        GEFloat const &              GetBackwardSpeedMax( void ) const;
        GEFloat                      GetBrakingDistance( void ) const;
        GEBool const &               GetCanBePushedWhileIdle( void ) const;
        GEFloat                      GetCharacterHeight( void ) const;
        GEBool                       GetCombatContact( void ) const;
        bCVector                     GetCurrentPosition( void ) const;
        GEFloat                      GetCurrentSpeedModifier( void ) const;
        GEFloat                      GetCurrentVelocity( void ) const;
        GEBool                       GetDebugMode( void );
        GEFloat                      GetDistToCeiling( bCVector const &, GEBool ) const;
        GEFloat                      GetDistToGround( bCVector const &, GEBool ) const;
        GEBool const &               GetDoHeightCorrection( void ) const;
        GEFloat const &              GetFallSteerScaleFactor( void ) const;
        GEFloat const &              GetFastModifier( void ) const;
        GEBool const &               GetForceGroundAlignment( void ) const;
        GEFloat const &              GetForwardSpeedMax( void ) const;
        GEBool                       GetGoalChanged( void ) const;
        GEFloat                      GetGoalGroundOffset( void ) const;
        bCVector                     GetGoalPosition( void ) const;
        GEBool                       GetGoalReached( GEBool, GEBool, GEBool );
        GEFloat const &              GetGroundSlopeTransInertia( void ) const;
        GEFloat                      GetGroundSlopeTransScale( void ) const;
        GEFloat                      GetHalfSpeedTimer( void );
        GEBool                       GetIsProcessing( void );
        GEBool const &               GetIsQuadruped( void ) const;
        GEFloat const &              GetJumpStartUpVelocity( void ) const;
        GEFloat const &              GetJumpSteerScaleFactor( void ) const;
        GEFloat const &              GetLastFallVelocity( void ) const;
        gECharMovementMode           GetLastMovementMode( void ) const;
        bCVector const &             GetLatestGoalPosition( void ) const;
        bCQuaternion const &         GetLatestGoalRotation( void ) const;
        bCVector                     GetLocalAniVelocity( void ) const;
        bCVector                     GetLocalVelocity( void ) const;
        GEFloat const &              GetMoveAcceleration( void ) const;
        GEFloat const &              GetMoveDecceleration( void ) const;
        GEBool                       GetMovementIsControledByNavigation( void ) const;
        GEBool                       GetMovementIsControledByPlayer( void ) const;
        GEBool                       GetMovementIsSelfControled( void ) const;
        gECharMovementMode           GetMovementMode( void ) const;
        gECharMovementMode           GetMovementModeAtPosition( bCVector const & ) const;
        bCMotion const &             GetNextStep( void ) const;
        GEFloat                      GetPredictedDistanceByTime( GEFloat );
        GEFloat const &              GetQuadrupedSlopeInertia( void ) const;
        gCCharacterSensor_PS &       GetSensor( void );
        gCCharacterSensor_PS const & GetSensor( void ) const;
        GEFloat const &              GetSensorAdvanceDuration( void ) const;
        GEBool const &               GetSensorAffectsDirection( void ) const;
        GEFloat const &              GetSensorInertia( void ) const;
        GEFloat const &              GetSensorMinSlideAngle( void ) const;
        GEFloat const &              GetSlideInertia( void ) const;
        GEFloat const &              GetSlideSpeedMax( void ) const;
        GEBool                       GetSlideStartedFrontally( void ) const;
        GEFloat const &              GetSlowModifier( void ) const;
        GEFloat const &              GetSneakModifier( void ) const;
        gSSpatialState &             GetSpatialState( void );
        gSSpatialState const &       GetSpatialState( void ) const;
        GEFloat                      GetSpeedByMode( gECharMovementMode );
        GEFloat const &              GetSteepGroundAngleMax( void ) const;
        GEFloat const &              GetSteepGroundAngleMin( void ) const;
        GEFloat const &              GetStepHeight( void ) const;
        GEFloat                      GetStepSize( bCVector const & ) const;
        GEFloat const &              GetStrafeSpeedMax( void ) const;
        GEFloat const &              GetSwimDepth( void ) const;
        GEBool const &               GetTreatWaterAsSolid( void ) const;
        GEFloat const &              GetTurnAcceleration( void ) const;
        GEFloat const &              GetTurnDecceleration( void ) const;
        GEFloat const &              GetTurnSpeedMax( void ) const;
        GEFloat const &              GetTurnSpeedModifier( void ) const;
        GEFloat const &              GetWalkDownSpeedScale( void ) const;
        GEFloat                      GetWaterDepth( void ) const;
        GEBool                       IsBraking( void ) const;
        GEBool                       IsCombatMovementEnabledFromSPU( void ) const;
        GEBool                       IsCombatRotationEnabledFromSPU( void ) const;
        GEBool                       IsDiving( void ) const;
        GEBool                       IsFalling( void ) const;
        GEBool                       IsFreeLOSAndSurrounding( eCEntity *, GEBool );
        GEBool                       IsInMovingState( void ) const;
        GEBool                       IsJumping( void ) const;
        GEBool                       IsMounted( void ) const;
        GEBool                       IsMovementEnabledFromSPU( void );
        GEBool                       IsRunning( void ) const;
        GEBool                       IsSneaking( void ) const;
        GEBool                       IsSprinting( void ) const;
        GEBool                       IsStanding( void ) const;
        GEBool                       IsSwimming( void ) const;
        GEBool                       IsWalking( void ) const;
        void                         MarkSpatialStateAsUninited( GEBool );
        void                         ProcessSensorMovements( void );
        GEFloat                      PutToGround( GEBool, GEBool );
        void                         ResetIsProcessing( void );
        void                         SetAlignmentLookAt( bCVector const & );
        void                         SetAlignmentTarget( eCEntity const * );
        void                         SetAniVelocityInertia( GEFloat const & );
        void                         SetApplyGravity( GEBool const & );
        void                         SetBackwardSpeedMax( GEFloat const & );
        void                         SetCanBePushedWhileIdle( GEBool const & );
        void                         SetCurrentSpeedModifier( GEFloat );
        void                         SetDebugMode( GEBool );
        void                         SetDoHeightCorrection( GEBool const & );
        void                         SetFallSteerScaleFactor( GEFloat const & );
        void                         SetFastModifier( GEFloat const & );
        void                         SetForceGroundAlignment( GEBool const & );
        void                         SetForwardSpeedMax( GEFloat const & );
        void                         SetGoalGroundEntity( eCEntity * );
        void                         SetGoalGroundOffset( GEFloat );
        void                         SetGoalPose( bCMotion const &, GEBool, GEBool );
        void                         SetGoalPosition( bCVector const &, GEBool, GEBool );
        void                         SetGoalRotation( bCQuaternion const & );
        void                         SetGroundSlopeTransInertia( GEFloat const & );
        void                         SetHalfSpeedTimer( GEFloat );
        void                         SetIsQuadruped( GEBool const & );
        void                         SetJumpStartUpVelocity( GEFloat const & );
        void                         SetJumpSteerScaleFactor( GEFloat const & );
        void                         SetLastFallVelocity( GEFloat const & );
        void                         SetMoveAcceleration( GEFloat const & );
        void                         SetMoveDecceleration( GEFloat const & );
        void                         SetMovementMode( gECharMovementMode );
        void                         SetQuadrupedSlopeInertia( GEFloat const & );
        void                         SetSensorAdvanceDuration( GEFloat const & );
        void                         SetSensorAffectsDirection( GEBool const & );
        void                         SetSensorInertia( GEFloat const & );
        void                         SetSensorMinSlideAngle( GEFloat const & );
        void                         SetSlideInertia( GEFloat const & );
        void                         SetSlideSpeedMax( GEFloat const & );
        void                         SetSlowModifier( GEFloat const & );
        void                         SetSneakModifier( GEFloat const & );
        void                         SetSteepGroundAngleMax( GEFloat const & );
        void                         SetSteepGroundAngleMin( GEFloat const & );
        void                         SetStepHeight( GEFloat const & );
        void                         SetStrafeSpeedMax( GEFloat const & );
        void                         SetSwimDepth( GEFloat const & );
        void                         SetTreatWaterAsSolid( GEBool const & );
        void                         SetTurnAcceleration( GEFloat const & );
        void                         SetTurnDecceleration( GEFloat const & );
        void                         SetTurnSpeedMax( GEFloat const & );
        void                         SetTurnSpeedModifier( GEFloat const & );
        void                         SetWalkDownSpeedScale( GEFloat const & );
        void                         StartControlNPC( void );
        void                         StopControlNPC( void );
        void                         StopMovement( void );

    protected:
        void     AddToCurrentVelocity( bCVector const & );
        void     CalcAniVelocity( void );
        void     CalcDistToGoal( void );
        void     CalcGroundSlopeTransScale( void );
        void     CalcNewRotationAngleAndVelocity( bCVector const &, bCVector const &, GEFloat, GEFloat &, GEFloat &, GEBool );
        void     CalcNextSteps( void );
        void     CalcQuadrupedDistances( void );
        void     ClearVolatileFrameStates( void );
        void     ContributeFloorActions( void );
        void     ContributeFloorMovements( void );
        GEBool   CorrectGoalMiss( void );
        void     CorrectWeaponTrigger( void );
        void     CreateDependantPSets( void );
        void     GameReset( void );
        GEFloat  GetCurrentMaxSpeedOfDir( bCVector const & ) const;
        bCVector GetCurrentWayDirection( void );
        GEFloat  GetPivotBoxCenterOffset( void ) const;
        void     InitFirstPose( void );
        void     Invalidate( void );
        GEBool   NeedsComplexStaticCollisionTests( void ) const;
        void     OnFloorMaterialChanged( eEShapeMaterial );
        void     ProcessControledMovements( void );
        void     ProcessControledRotation( void );
        void     ProcessControledRotationLookAt( bCVector & );
        void     ProcessControledRotationToTarget( void );
        void     ProcessControledTranslation( void );
        GEBool   ProcessHeavyBrake( bCVector const &, GEFloat );
        void     ProcessMovementAnimation( void );
        void     ProcessMovements( void );
        void     ProcessPhysicsMovements( void );
        void     ProcessQuadrupedXRotation( bCQuaternion &, GEBool );
        void     SaveFrameStates( void );
        void     SetCurrentPosition( bCVector const &, GEBool );
        void     SetCurrentVelocity( bCVector const & );
        GEBool   SetEffectsByMode( gECharMovementMode );
        GEBool   SetFlagsByMode( gECharMovementMode );
        GEBool   SetShapeByMode( gECharMovementMode );
        GEBool   SetSpeedByMode( gECharMovementMode );
        void     ShowDebug( void );
        void     ValidateZoneGeometry( void ) const;

};

#endif
