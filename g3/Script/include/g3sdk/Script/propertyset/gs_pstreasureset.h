#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSTreasureSet : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSTreasureSet, gCTreasureSet_PS)
    GS_PROPERTY(GEU32, MaxTransferStacks)
    GS_PROPERTY(GEU32, MinTransferStacks)
    GS_PROPERTY(gETreasureDistribution, TreasureDistribution)
};
