#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSAnchor : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSAnchor, gCAnchor_PS)
    GS_PROPERTY(gEAnchorType, AnchorType)
    GS_PROPERTY(GEU32, MaxUsers)
    GS_PROPERTY(GEU32, PatrolIndex)
    GS_PROPERTY(GEU32, UserCount)

  public:
    bTObjArray<Entity> GetInteractPoints(GEBool) const;
};
