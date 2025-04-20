#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSProjectile : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSProjectile, gCProjectile_PS)
    GS_PROPERTY(GEFloat, DecayDuration)
    GS_PROPERTY(gEProjectilePath, PathStyle)
    GS_PROPERTY(GEFloat, ShootVelocity)
    GS_PROPERTY(bCVector, TargetDirection)
    GS_PROPERTY(eCEntityProxy, TargetEntity)
    GS_PROPERTY(bCVector, TargetPosition)
    GS_PROPERTY(GEU32, TargetUpdateMSec)
    GS_PROPERTY(gEProjectileTouchBehavior, TouchBehavior)

  public:
    Entity GetTarget() const;
    GEBool IsFlying() const;
    void SetTarget(Entity const &);
    void Shoot();
};
