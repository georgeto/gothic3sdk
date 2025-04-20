#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCOStream;

class GE_DLLIMPORT bCRange1
{
  public:
    bCRange1 &operator=(bCRange1 const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);

  public:
    GEFloat GetCenter() const;
    void GetCenter(GEFloat &) const;
    GEFloat GetMagnitude() const;
    void GetMagnitude(GEFloat &) const;
    GEFloat GetRandom() const;
    void GetRandom(GEFloat &) const;
    GEInt GetRandomInt() const;
    void GetRandomInt(GEInt &) const;
    void SetAverageAndVariance(GEFloat, GEFloat);
    void SetMinMax(GEFloat, GEFloat);

  private:
    GEFloat m_fMin;
    GEFloat m_fMax;
};
