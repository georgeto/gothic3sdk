#pragma once

#include "gs_propertymacros.h"

#include <Engine.h>

class GE_DLLIMPORT PSAnimation : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSAnimation, eCVisualAnimation_PS)

  public:
    void AddForceAtPos(bCVector, bCVector);
    void EnableControllerCollision(GEBool);
    bCString GetResourceName() const;
    GEBool GetSkeletonName(bCString &) const;
    void PauseControllers(GEBool, GEFloat);
    void PullTo(bCVector, GEFloat);
    void SetTimeScale(GEFloat);
};
