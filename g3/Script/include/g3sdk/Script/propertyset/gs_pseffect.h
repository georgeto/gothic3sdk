#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSEffect : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSEffect, gCEffect_PS)

  public:
    GEBool IsRuntimeEffectStarted(bCString const &);
    GEBool StartEffect(bCString const &, GEBool a_bDecayPrevious);
    GEBool StartRuntimeEffect(bCString const &);
    GEBool StopAllRuntimeEffects(GEBool);
    void StopEffect(GEBool);
    GEBool StopRuntimeEffect(bCString const &, GEBool a_bDecay);
};
