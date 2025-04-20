#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSMagic : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSMagic, gCMagic_PS)
    GS_PROPERTY(bCString, AnimActionCast)
    GS_PROPERTY(bCString, AnimActionPowerCast)
    GS_PROPERTY(GEBool, AutoReload)
    GS_PROPERTY(gECastType, CastType)
    GS_PROPERTY(bCString, EffectCasterCast)
    GS_PROPERTY(bCString, EffectCasterHold)
    GS_PROPERTY(bCString, EffectCasterLoad)
    GS_PROPERTY(bCString, EffectCasterPower)
    GS_PROPERTY(bCString, EffectItemCast)
    GS_PROPERTY(bCString, EffectItemHold)
    GS_PROPERTY(bCString, EffectItemLoad)
    GS_PROPERTY(bCString, EffectItemPower)
    GS_PROPERTY(bCString, EffectTargetCast)
    GS_PROPERTY(bCString, EffectTargetLoad)
    GS_PROPERTY(bCString, EffectTargetPower)
    GS_PROPERTY(bCString, FuncOnCast)
    GS_PROPERTY(bCString, FuncOnTargetHit)
    GS_PROPERTY(GEInt, MaxManaCost)
    GS_PROPERTY(GEInt, MinManaCost)
    GS_PROPERTY(GEFloat, ReloadDelaySeconds)
    GS_PROPERTY(gESpellDeity, SpellDeity)
    GS_PROPERTY(gESpellTarget, SpellTarget)
    GS_PROPERTY(gESpellType, SpellType)

  public:
    GEU32 GetReloadDelay() const;
    Entity GetSpawn() const;
    GEBool IsAutoReload() const;
    GEBool IsQuickCast() const;
};
