#pragma once

#include <SharedBase/math/2d/ge_vector2.h>
#include <SharedBase/types/ge_def.h>

class bCIStream;
class bCOStream;

class GE_DLLIMPORT bCRange2
{
  public:
    bCRange2(bCRange2 const &);
    bCRange2();
    ~bCRange2();

  public:
    bCRange2 &operator=(bCRange2 const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);

  public:
    bCVector2 GetCenter() const;
    void GetCenter(bCVector2 &) const;
    bCVector2 GetMagnitude() const;
    void GetMagnitude(bCVector2 &) const;
    bCVector2 GetRandom() const;
    void GetRandom(bCVector2 &) const;
    void SetAverageAndVariance(bCVector2 const &, bCVector2 const &);
    void SetMinMax(bCVector2 const &, bCVector2 const &);
};
