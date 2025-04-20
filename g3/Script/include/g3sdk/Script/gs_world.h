#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT World
{
  public:
    World();
    ~World();

  public:
    World &operator=(World const &);

  public:
    GEBool EnableSectorFolder(bCString const &, GEBool);
    GEBool GetSectorStatus(bCString const &);
    GEBool SetSectorStatus(bCString const &, GEBool);
};

GE_DLLIMPORT_EXTC World world;
