#pragma once

#include <Game.h>

class Entity;

#include "gs_propertymacros.h"

class GE_DLLIMPORT PSDialog : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSDialog, gCDialog_PS)
    GS_PROPERTY(GEFloat, EndDialogTimestamp)
    GS_PROPERTY(GEBool, MobEnabled)
    GS_PROPERTY(GEBool, PartyEnabled)
    GS_PROPERTY(GEBool, PickedPocket)
    GS_PROPERTY(GEBool, SlaveryEnabled)
    GS_PROPERTY(GEBool, TalkedToPlayer)
    GS_PROPERTY(GEBool, TeachEnabled)
    GS_PROPERTY(gETradeCategory, TradeCategory)
    GS_PROPERTY(GEBool, TradeEnabled)

  public:
    void BeginTalkedToBy(Entity const &);
    void BeginTalkingTo(Entity const &);
    void EndTalkedToBy(Entity const &);
    void EndTalkingTo(Entity const &);
    GEBool IsBeingTalkedTo() const;
    GEBool IsTalking() const;
};
