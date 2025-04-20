#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSDoor : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSDoor, gCDoor_PS)

  public:
    void Close(GEBool);
    GEBool IsClosed() const;
    GEBool IsOpen() const;
    void Open(GEBool);
};
