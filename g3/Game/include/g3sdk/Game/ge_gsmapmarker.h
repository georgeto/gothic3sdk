#pragma once

#include <SharedBase.h>

struct GE_DLLIMPORT gSMapMarker
{
  public:
    gSMapMarker(gSMapMarker const &);
    gSMapMarker();
    ~gSMapMarker();

  public:
    gSMapMarker &operator=(gSMapMarker const &);
};
