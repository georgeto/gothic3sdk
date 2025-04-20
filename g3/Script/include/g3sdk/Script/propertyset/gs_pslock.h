#pragma once

#include "gs_propertymacros.h"

#include <Script/gs_template.h>

#include <Game.h>

class GE_DLLIMPORT PSLock : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSLock, gCLock_PS)
    GS_PROPERTY(GEInt, Difficulty)
    GS_PROPERTY(GEInt, KeyAmount)
    GS_PROPERTY(gELockStatus, Status)

  public:
    Template GetKey() const;
    GEBool IsLocked() const;
    GEBool IsUnlocked() const;
};
