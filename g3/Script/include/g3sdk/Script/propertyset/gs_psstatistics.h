#pragma once

#include <Game.h>

enum EAttrib
{
    // TODO: Enumerator values
};

enum ETrait
{
    // TODO: Enumerator values
};

#include "gs_propertymacros.h"

class GE_DLLIMPORT PSStatistics : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSStatistics, gCStatistics_PS)

  public:
    GEInt GetBaseMaximum(EAttrib) const;
    GEInt GetBaseValue(EAttrib) const;
    GEInt GetMaximum(EAttrib) const;
    GEInt GetTraitValue(ETrait) const;
    GEInt GetValue(EAttrib) const;
    GEBool HasTrait(ETrait) const;
    void SetBaseMaximum(EAttrib, GEInt);
    void SetBaseValue(EAttrib, GEInt);
};
