#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSArena : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSArena, gCArena_PS)
    GS_PROPERTY(gEArenaStatus, Status)
};
