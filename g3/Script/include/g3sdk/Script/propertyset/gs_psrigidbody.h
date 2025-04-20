#pragma once

#include "gs_propertymacros.h"

#include <Engine.h>

class GE_DLLIMPORT PSRigidBody : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSRigidBody, eCRigidBody_PS)
    GS_PROPERTY(GEFloat, AngularDamping)
    GS_PROPERTY(GEFloat, LinearDamping)

  public:
    void AddForce(bCVector const &);
    void HoverTo(bCVector const &, GEFloat);
    void SetTimeScale(GEFloat);
};
