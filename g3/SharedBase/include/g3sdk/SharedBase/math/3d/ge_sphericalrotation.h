#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCOStream;

class GE_DLLIMPORT bCSphericalRotation
{
  public:
    bCSphericalRotation();
    ~bCSphericalRotation();

  public:
    bCSphericalRotation &operator=(bCSphericalRotation const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);

  public:
    GEFloat &AccessAzimuth();
    GEFloat &AccessLatitude();
    GEFloat &AccessLongitude();
    GEFloat GetAzimuth() const;
    void GetAzimuth(GEFloat &) const;
    GEFloat GetLatitude() const;
    void GetLatitude(GEFloat &) const;
    GEFloat GetLongitude() const;
    void GetLongitude(GEFloat &) const;
    void SetAzimuth(GEFloat);
    void SetLatitude(GEFloat);
    void SetLongitude(GEFloat);
};
