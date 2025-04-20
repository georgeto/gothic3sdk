#pragma once

#include <Game.h>

class Entity;

#include "gs_propertymacros.h"

class GE_DLLIMPORT PSCamera : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSCamera, gCCameraAI_PS)

  public:
    void EnableSpecialBowMode(GEBool);
    void EnableTempFirstPerson(GEBool);
    gECameraMode GetLastMode() const;
    gECameraMode GetMode() const;
    bCVector GetScreenCenterPickPoint() const;
    GEBool IsInFirstPerson() const;
    GEBool IsInSpecialBowMode() const;
    GEBool IsInTempFirstPerson() const;
    void SetDialogRoles(Entity &, Entity &);
    void SetMode(gECameraMode, GEBool, GEBool);
    void StopDialogCamera();
};
