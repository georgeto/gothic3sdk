#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSInteraction : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSInteraction, gCInteraction_PS)
    GS_PROPERTY(bCString, EnterROIScript)
    GS_PROPERTY(bCString, ExitROIScript)
    GS_PROPERTY(bCString, UseFunc)
    GS_PROPERTY(gEUseType, UseType)
    GS_PROPERTY(GEBool, UsedByPlayer)

  public:
    Entity GetAnchorPoint() const;
    Entity GetOwner() const;
    Entity GetSpell() const;
    gEUseType GetUseType() const;
    Entity GetUser() const;
    Entity GetZone() const;
    GEBool IsZoneValid() const;
    GEBool SetAnchorPoint(Entity const &);
    GEBool SetOwner(Entity const &);
    void SetSpell(Entity const &);
    GEBool SetUser(Entity const &);
};
