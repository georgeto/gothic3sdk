#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSDamageReceiver : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSDamageReceiver, gCDamageReceiver_PS)
    GS_PROPERTY(GEI32, DamageAmount)
    GS_PROPERTY(gEDamageType, DamageType)
    GS_PROPERTY(GEI32, HitPoints)
    GS_PROPERTY(GEI32, HitPointsMax)
    GS_PROPERTY(GEI32, ManaPoints)
    GS_PROPERTY(GEI32, ManaPointsMax)
    GS_PROPERTY(GEI32, StaminaPoints)
    GS_PROPERTY(GEI32, StaminaPointsMax)

  public:
    Entity GetLastInflictor();
    void SetLastInflictor(Entity &);
};
