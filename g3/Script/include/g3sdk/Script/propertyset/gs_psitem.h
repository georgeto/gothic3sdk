#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSItem : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSItem, gCItem_PS)

  public:
    GEBool ExecuteScript() const;
    GEU32 GetAmount() const;
    gEItemCategory GetCategory() const;
    GEInt GetGoldValue() const;
    GEU32 GetQuality() const;
    Entity GetSkill() const;
    Entity GetSpell() const;
    GEBool IsDropped() const;
    GEBool IsEquipped() const;
    GEBool IsFullBody() const;
    GEBool IsMissionItem() const;
    GEBool IsRobe() const;
    void ModifyQuality(GEU32, GEU32);
    void SetAmount(GEU32);
};
