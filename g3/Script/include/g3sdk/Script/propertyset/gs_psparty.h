#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSParty : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSParty, gCParty_PS)
    GS_PROPERTY(gEPartyMemberType, PartyMemberType)
    GS_PROPERTY(GEBool, Waiting)

  public:
    GEBool Add(Entity);
    void CleanUp();
    bTValArray<eCEntity *> GetMembers(GEBool a_bIncludeSelf) const;
    Entity GetPartyLeader() const;
    GEBool Remove(Entity);
    GEBool SetPartyLeader(Entity);
};
