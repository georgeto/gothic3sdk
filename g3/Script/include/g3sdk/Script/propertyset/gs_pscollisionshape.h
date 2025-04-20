#pragma once

#include "gs_propertymacros.h"

#include <Engine.h>

class GE_DLLIMPORT PSCollisionShape : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSCollisionShape, eCCollisionShape_PS)

  public:
    GEBool CreateDynamicShape(eECollisionShapeType, eEShapeGroup, GEFloat);
    GEBool CreateShape(eECollisionShapeType, eEShapeGroup, bCVector, bCVector);
    GEInt GetNumTouchingShapes();
    eEShapeMaterial GetPhysicMaterial();
    bCString GetTouchingBone() const;
    eEShapeGroup GetTouchingShapeGroup(GEU32);
    eEPropertySetType GetType() const;
};
