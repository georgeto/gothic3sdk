#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSMover : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSMover, gCMover_PS)
    GS_PROPERTY(gEMoverState, MoverState)

  public:
    void Toggle();
};
