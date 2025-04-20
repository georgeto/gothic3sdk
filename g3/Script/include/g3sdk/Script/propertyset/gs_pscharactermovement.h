#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSCharacterMovement : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSCharacterMovement, gCCharacterMovement_PS)
    GS_PROPERTY(GEBool, CanBePushedWhileIdle)
    GS_PROPERTY(GEBool, ForceGroundAlignment)
    GS_PROPERTY(GEFloat, LastFallVelocity)
    GS_PROPERTY(GEFloat, StepHeight)

  public:
    GEBool CanJump() const;
    GEBool CanStandAtPose(bCMatrix const &) const;
    void CreateDependantShapes();
    GEBool FindFloorAtPos(bCVector &) const;
    bCVector GetAlignmentLookAt() const;
    Entity GetAlignmentTarget() const;
    GEFloat GetCeilingY() const;
    eEShapeMaterial GetFloorMaterial() const;
    GEFloat GetFloorY() const;
    gECharMovementMode GetLastMovementMode() const;
    gECharMovementMode GetMovementMode() const;
    GEBool GetSlideStartedFrontally() const;
    GEBool GetTreatWaterAsSolid();
    GEFloat GetWaterY() const;
    GEBool IsBraking() const;
    GEBool IsDiving() const;
    GEBool IsFalling() const;
    GEBool IsInMovingState() const;
    GEBool IsJumping() const;
    GEBool IsRunning() const;
    GEBool IsSneaking() const;
    GEBool IsSprinting() const;
    GEBool IsStanding() const;
    GEBool IsSwimming() const;
    void PutToGround();
    void SetAlignmentLookAt(bCVector const &);
    void SetAlignmentTarget(Entity const &);
    void SetGroundBias(Entity const &);
    void SetGroundBias(GEFloat);
    void SetMovementGoal(Entity const &);
    void SetMovementGoal(bCMatrix const &);
    void SetMovementGoal(bCVector const &);
    void SetMovementMode(gECharMovementMode);
    void SetTreatWaterAsSolid(GEBool);
    void StopMovement() const;
};
