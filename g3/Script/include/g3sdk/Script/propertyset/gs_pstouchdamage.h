#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSTouchDamage : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSTouchDamage, gCTouchDamage_PS)
    GS_PROPERTY(GEBool, ResetOnUntouch)

  public:
    void ClearTriggeredList();
    Entity GetInflictor();
};
