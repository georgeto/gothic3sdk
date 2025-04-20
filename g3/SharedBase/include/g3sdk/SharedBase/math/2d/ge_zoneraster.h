#pragma once

#include <SharedBase/container/array/ge_valarray.h>
#include <SharedBase/math/3d/ge_vector.h>

class GE_DLLIMPORT bCZoneRaster
{
  public:
    bCZoneRaster(bCZoneRaster const &);
    explicit bCZoneRaster(bTValArray<bCVector> const &);
    ~bCZoneRaster();

  public:
    bCZoneRaster &operator=(bCZoneRaster const &);
};
