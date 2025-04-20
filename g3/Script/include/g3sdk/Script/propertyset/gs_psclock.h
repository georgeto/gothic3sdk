#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSClock : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSClock, gCClock_PS)

  public:
    GEInt GetDay() const;
    GEInt GetHour() const;
    GEInt GetMinute() const;
    GEU32 GetTimeStampInSeconds() const;
    GEFloat GetWorldTime() const;
    GEInt GetYear() const;
    void SetDay(GEInt) const;
    void SetFactor(GEFloat) const;
    void SetHour(GEInt) const;
    void SetMinute(GEInt) const;
    void SetWorldTime(GEFloat) const;
    void SetYear(GEInt) const;
};
