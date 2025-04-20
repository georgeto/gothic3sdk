#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCAxisAngle;
class bCIStream;
class bCMatrix;
class bCOStream;
class bCQuaternion;
class bCVector;

class GE_DLLIMPORT bCEulerAngles
{
  public:
    bCEulerAngles(bCEulerAngles const &);
    explicit bCEulerAngles(bCAxisAngle const &);
    explicit bCEulerAngles(bCQuaternion const &);
    explicit bCEulerAngles(bCVector const &);
    bCEulerAngles(GEFloat, GEFloat, GEFloat);
    bCEulerAngles();
    ~bCEulerAngles();

  public:
    bCEulerAngles &operator=(bCEulerAngles const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(bCEulerAngles const &) const;
    GEBool operator!=(bCEulerAngles const &) const;
    GEFloat &operator[](GEInt);
    GEFloat operator[](GEInt) const;
    bCEulerAngles const operator*(GEFloat) const;
    bCEulerAngles const operator-(bCEulerAngles const &) const;
    bCEulerAngles const operator-() const;
    bCEulerAngles const operator+(bCEulerAngles const &) const;
    bCEulerAngles &operator*=(GEFloat);
    bCEulerAngles &operator+=(bCEulerAngles const &);
    bCEulerAngles &operator-=(bCEulerAngles const &);

  public:
    GEFloat &AccessPitch();
    GEFloat &AccessRoll();
    GEFloat &AccessYaw();
    void Clear();
    bCAxisAngle GetAxisAngle() const;
    GEFloat GetPitch() const;
    void GetPitch(GEFloat &) const;
    bCQuaternion GetQuaternion() const;
    GEFloat GetRoll() const;
    void GetRoll(GEFloat &) const;
    GEFloat GetYaw() const;
    void GetYaw(GEFloat &) const;
    void SetEulerAngles(bCEulerAngles const &);
    void SetEulerAngles(bCAxisAngle const &);
    void SetEulerAngles(bCMatrix const &);
    void SetEulerAngles(bCQuaternion const &);
    void SetEulerAngles(GEFloat, GEFloat, GEFloat);
    void SetPitch(GEFloat);
    void SetRoll(GEFloat);
    void SetYaw(GEFloat);

  private:
    GEFloat m_fYaw;
    GEFloat m_fPitch;
    GEFloat m_fRoll;
};
