#ifndef GS_PSCHARACTERMOVEMENT_H_INCLUDED
#define GS_PSCHARACTERMOVEMENT_H_INCLUDED

class gCCharacterMovement_PS;
enum gECharMovementMode;

GS_DECLARE_PROPERTYSET( PSCharacterMovement, gCCharacterMovement_PS )
public:
    GS_DECLARE_PROPERTY( CanBePushedWhileIdle, GEBool )
    GS_DECLARE_PROPERTY( ForceGroundAlignment, GEBool )
    GS_DECLARE_PROPERTY( LastFallVelocity,     GEFloat )
    GS_DECLARE_PROPERTY( StepHeight,           GEFloat )

public:
    GEBool             CanJump( void ) const;
    GEBool             CanStandAtPose( bCMatrix const & ) const;
    void               CreateDependantShapes( void );
    GEBool             FindFloorAtPos( bCVector & ) const;
    bCVector           GetAlignmentLookAt( void ) const;
    Entity             GetAlignmentTarget( void ) const;
    GEFloat            GetCeilingY( void ) const;
    eEShapeMaterial    GetFloorMaterial( void ) const;
    GEFloat            GetFloorY( void ) const;
    gECharMovementMode GetLastMovementMode( void ) const;
    gECharMovementMode GetMovementMode( void ) const;
    GEBool             GetSlideStartedFrontally( void ) const;
    GEBool             GetTreatWaterAsSolid( void );
    GEFloat            GetWaterY( void ) const;
    GEBool             IsBraking( void ) const;
    GEBool             IsDiving( void ) const;
    GEBool             IsFalling( void ) const;
    GEBool             IsInMovingState( void ) const;
    GEBool             IsJumping( void ) const;
    GEBool             IsRunning( void ) const;
    GEBool             IsSneaking( void ) const;
    GEBool             IsSprinting( void ) const;
    GEBool             IsStanding( void ) const;
    GEBool             IsSwimming( void ) const;
    GEBool             IsValid( void ) const;
    void               PutToGround( void );
    void               SetAlignmentLookAt( bCVector const & );
    void               SetAlignmentTarget( Entity const & );
    void               SetGroundBias( Entity const & );
    void               SetGroundBias( GEFloat );
    void               SetMovementGoal( Entity const & );
    void               SetMovementGoal( bCMatrix const & );
    void               SetMovementGoal( bCVector const & );
    void               SetMovementMode( gECharMovementMode );
    void               SetTreatWaterAsSolid( GEBool );
    void               StopMovement( void ) const;

};

#endif
