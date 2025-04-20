#pragma once

#include <SharedBase/math/3d/ge_vector.h>
#include <SharedBase/types/ge_def.h>

class bCIStream;
class bCOStream;

class GE_DLLIMPORT bCRange3
{
  public:
    bCRange3(bCRange3 const &);
    bCRange3();
    ~bCRange3();

  public:
    bCRange3 &operator=(bCRange3 const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);

  public:
    bCVector GetCenter() const;
    void GetCenter(bCVector &) const;
    bCVector GetMagnitude() const;
    void GetMagnitude(bCVector &) const;
    bCVector GetRandom() const;
    void GetRandom(bCVector &) const;
    void SetAverageAndVariance(bCVector const &, bCVector const &);
    void SetMinMax(bCVector const &, bCVector const &);

  private:
    bCVector m_Min;
    bCVector m_Max;
};
