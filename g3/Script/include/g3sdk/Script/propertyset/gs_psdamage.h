#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSDamage : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSDamage, gCDamage_PS)
    GS_PROPERTY(GEI32, DamageAmount)
    GS_PROPERTY(GEFloat, DamageHitMultiplier)
    GS_PROPERTY(GEFloat, DamageManaMultiplier)
    GS_PROPERTY(gEDamageType, DamageType)
    GS_PROPERTY(GEInt, ManaUsed)
};
