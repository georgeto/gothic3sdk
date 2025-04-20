#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCEulerAngles;
class bCIStream;
class bCOStream;
class bCQuaternion;
class bCVector;

class GE_DLLIMPORT bCAxisAngle
{
  public:
    bCAxisAngle(bCAxisAngle const &);
    explicit bCAxisAngle(bCEulerAngles const &);
    explicit bCAxisAngle(bCQuaternion const &);
    bCAxisAngle(bCVector const &, GEFloat);
    bCAxisAngle();
    ~bCAxisAngle();

  public:
    bCAxisAngle &operator=(bCAxisAngle const &);
    bCAxisAngle &operator=(bCEulerAngles const &);
    bCAxisAngle &operator=(bCQuaternion const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(bCAxisAngle const &) const;
    GEBool operator!=(bCAxisAngle const &) const;

  public:
    GEFloat &AccessAngle();
    bCVector &AccessAxis();
    void Clear();
    GEFloat GetAngle() const;
    void GetAngle(GEFloat &) const;
    bCVector const &GetAxis() const;
    void GetAxis(bCVector &) const;
    bCEulerAngles GetEulerAngles() const;
    bCQuaternion GetQuaternion() const;
    GEBool IsEqual(bCAxisAngle const &) const;
    void SetAngle(GEFloat);
    void SetAxis(bCVector const &);
    void SetAxisAngle(bCAxisAngle const &);
    void SetAxisAngle(bCEulerAngles const &);
    void SetAxisAngle(bCQuaternion const &);
    void SetAxisAngle(bCVector const &, GEFloat);
};
