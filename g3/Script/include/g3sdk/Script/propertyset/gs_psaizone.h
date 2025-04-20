#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSAIZone : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSAIZone, gCAIZone_PS)
    GS_PROPERTY(eCEntityProxy, Owner)
    GS_PROPERTY(gESecurityLevel, SecurityLevel)
    GS_PROPERTY(gEZoneType, Type)
};
