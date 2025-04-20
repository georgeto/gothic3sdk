#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSNavigation : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSNavigation, gCNavigation_PS)
    GS_PROPERTY(gEDirection, CurrentAniDirection)
    GS_PROPERTY(GEBool, IsOnDestination)
    GS_PROPERTY(GEU32, IsOnDestinationTimeStamp)
    GS_PROPERTY(bCVector, StartPosition)

  public:
    Entity GetAIGotoDestination() const;
    gEDirection GetAniDirection() const;
    Entity GetCurrentDestinationPoint() const;
    Entity GetCurrentZone() const;
    GEBool GetDCCEnabled() const;
    GEFloat GetDCCRadius() const;
    gEGotoStatus GetGotoStatus() const;
    Entity GetLastZone() const;
    Entity GetRelaxingPoint() const;
    Entity GetSleepingPoint() const;
    Entity GetWorkingPoint() const;
    GEBool HasAnyDestination() const;
    GEBool IsInProcessingRange() const;
    GEBool IsTravelling() const;
    void Reset() const;
    void ResetAll() const;
    GEBool SetCurrentDestinationPoint(Entity &);
    void SetDCCEnabled(GEBool);
    void SetDCCRadius(GEFloat);
    GEBool SetRelaxingPoint(Entity &);
    GEBool SetRoutine(bCString const &);
    GEBool SetSleepingPoint(Entity &);
    GEBool SetWorkingPoint(Entity &);
    GEBool StartGoto(Entity &, Entity &, gEWalkMode);
    GEBool StartGoto(Entity &, bCVector const &, gEWalkMode);
};
