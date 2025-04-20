#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSCharacterControl : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSCharacterControl, gCCharacterControl_PS)
    GS_PROPERTY(gECharacterControlFOR, ControlFrameOfReference)
    GS_PROPERTY(GEU32, DurationPressedMSecs)
    GS_PROPERTY(GEBool, IsPressed)
    GS_PROPERTY(GEBool, IsPressedBefore)
    GS_PROPERTY(gESessionKey, PressedKey)

  public:
    void SetMovementConstraints(GEFloat);
};
