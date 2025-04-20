#pragma once

#include <SharedBase/math/3d/ge_vector4.h>
#include <SharedBase/types/ge_def.h>

class bCIStream;
class bCOStream;

class GE_DLLIMPORT bCRange4
{
  public:
    bCRange4(bCRange4 const &);
    bCRange4();
    ~bCRange4();

  public:
    bCRange4 &operator=(bCRange4 const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);

  public:
    bCVector4 GetCenter() const;
    void GetCenter(bCVector4 &) const;
    bCVector4 GetMagnitude() const;
    void GetMagnitude(bCVector4 &) const;
    bCVector4 GetRandom() const;
    void GetRandom(bCVector4 &) const;
    void SetAverageAndVariance(bCVector4 const &, bCVector4 const &);
    void SetMinMax(bCVector4 const &, bCVector4 const &);
};
