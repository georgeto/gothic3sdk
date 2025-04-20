#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSFocus : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSFocus, gCFocus_PS)
    GS_PROPERTY(gEFocus, CurrentMode)
    GS_PROPERTY(GEBool, EnableRangeRating)
    GS_PROPERTY(gEFocusLookAtKeysFOR, FocusLookAtKeysFOR)
    GS_PROPERTY(gEFocusLookAt, FocusLookAtMode)
    GS_PROPERTY(GEFloat, OverrideCharacterPriority)
    GS_PROPERTY(GEFloat, OverrideInteractPriority)
    GS_PROPERTY(GEFloat, OverrideItemPriority)
    GS_PROPERTY(GEFloat, OverrideRange)

  public:
    Entity FindFocusEntity() const;
    Entity GetCrossHairEntity() const;
    Entity GetFocusEntity(gECombatMode, gEDirection) const;
    Entity GetFocusEntity() const;
    void SetFocusEntity(Entity const &);
};
