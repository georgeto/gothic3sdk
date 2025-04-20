#pragma once

#include <Engine.h>

class Entity;

#include "gs_propertymacros.h"

class GE_DLLIMPORT PSTrigger : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSTrigger, eCTrigger_PS)

  public:
    void Trigger(Entity &);
    void Untrigger(Entity &);
};
