#pragma once

#include <SharedBase/math/3d/ge_axisangle.h>
#include <SharedBase/math/3d/ge_eulerangles.h>
#include <SharedBase/math/3d/ge_matrix.h>
#include <SharedBase/math/3d/ge_matrix3.h>
#include <SharedBase/math/3d/ge_sphericalrotation.h>
#include <SharedBase/math/3d/ge_vector.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCOStream;

class GE_DLLIMPORT bCQuaternion
{
  public:
    bCQuaternion(bCQuaternion const &);
    explicit bCQuaternion(bCAxisAngle const &);
    explicit bCQuaternion(bCEulerAngles const &);
    explicit bCQuaternion(bCMatrix3 const &);
    explicit bCQuaternion(bCMatrix const &);
    explicit bCQuaternion(bCSphericalRotation const &);
    bCQuaternion(GEFloat, GEFloat, GEFloat, GEFloat);
    bCQuaternion();
    ~bCQuaternion();

  public:
    bCQuaternion &operator=(bCQuaternion const &);
    bCQuaternion &operator=(bCAxisAngle const &);
    bCQuaternion &operator=(bCEulerAngles const &);
    bCQuaternion &operator=(bCMatrix3 const &);
    bCQuaternion &operator=(bCMatrix const &);
    bCQuaternion &operator=(bCSphericalRotation const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(bCQuaternion const &) const;
    GEBool operator!=(bCQuaternion const &) const;
    bCQuaternion operator*(bCQuaternion const &) const;
    bCQuaternion operator*(GEFloat) const;
    bCQuaternion operator-(bCQuaternion const &) const;
    bCQuaternion operator-() const;
    bCQuaternion operator+(bCQuaternion const &) const;
    bCQuaternion operator/(GEFloat) const;
    bCQuaternion operator~() const;
    bCQuaternion &operator*=(bCQuaternion const &);
    bCQuaternion &operator*=(GEFloat);
    bCQuaternion &operator+=(bCQuaternion const &);
    bCQuaternion &operator-=(bCQuaternion const &);
    bCQuaternion &operator/=(GEFloat);

  public:
    GEFloat &AccessW();
    GEFloat &AccessX();
    GEFloat &AccessY();
    GEFloat &AccessZ();
    void Add(bCQuaternion const &);
    void Clear();
    bCAxisAngle GetAxisAngle() const;
    void GetAxisAngle(bCAxisAngle &) const;
    bCQuaternion GetDifference(bCQuaternion const &) const;
    void GetDifference(bCQuaternion &, bCQuaternion const &) const;
    GEFloat GetDotProduct(bCQuaternion const &) const;
    bCEulerAngles GetEulerAngles() const;
    void GetEulerAngles(bCEulerAngles &) const;
    bCQuaternion GetInverted() const;
    void GetInverted(bCQuaternion &) const;
    bCQuaternion GetLerp(bCQuaternion const &, GEFloat) const;
    GEFloat GetMagnitude() const;
    bCMatrix GetMatrix() const;
    void GetMatrix(bCMatrix &) const;
    bCMatrix3 GetMatrix3() const;
    void GetMatrix3(bCMatrix3 &) const;
    bCQuaternion GetNegated() const;
    void GetNegated(bCQuaternion &) const;
    bCQuaternion GetNormalized() const;
    void GetNormalized(bCQuaternion &) const;
    bCQuaternion GetProduct(bCQuaternion const &) const;
    bCQuaternion GetProduct(GEFloat) const;
    void GetProduct(bCQuaternion &, bCQuaternion const &) const;
    void GetProduct(bCQuaternion &, GEFloat) const;
    bCQuaternion GetReverseProduct(bCQuaternion const &) const;
    void GetReverseProduct(bCQuaternion &, bCQuaternion const &) const;
    bCQuaternion GetRotatedAxisX(GEFloat) const;
    void GetRotatedAxisX(bCQuaternion &, GEFloat) const;
    bCQuaternion GetRotatedAxisY(GEFloat) const;
    void GetRotatedAxisY(bCQuaternion &, GEFloat) const;
    bCQuaternion GetRotatedAxisZ(GEFloat) const;
    void GetRotatedAxisZ(bCQuaternion &, GEFloat) const;
    bCQuaternion GetRotatedLocalAxisX(GEFloat) const;
    void GetRotatedLocalAxisX(bCQuaternion &, GEFloat) const;
    bCQuaternion GetRotatedLocalAxisY(GEFloat) const;
    void GetRotatedLocalAxisY(bCQuaternion &, GEFloat) const;
    bCQuaternion GetRotatedLocalAxisZ(GEFloat) const;
    void GetRotatedLocalAxisZ(bCQuaternion &, GEFloat) const;
    bCQuaternion GetSlerp(bCQuaternion const &, GEFloat) const;
    bCSphericalRotation GetSphericalRotation() const;
    void GetSphericalRotation(bCSphericalRotation &) const;
    GEFloat GetSquareMagnitude() const;
    bCQuaternion GetSum(bCQuaternion const &) const;
    void GetSum(bCQuaternion &, bCQuaternion const &) const;
    bCVector GetTransformedVector(bCVector const &) const;
    GEFloat GetW() const;
    void GetW(GEFloat &) const;
    GEFloat GetX() const;
    void GetX(GEFloat &) const;
    GEFloat GetY() const;
    void GetY(GEFloat &) const;
    GEFloat GetZ() const;
    void GetZ(GEFloat &) const;
    void Invert();
    GEBool IsEqual(bCQuaternion const &) const;
    GEBool IsNormalized() const;
    void Multiply(bCQuaternion const &);
    void Multiply(GEFloat);
    void Negate();
    void Normalize();
    void ReverseMultiply(bCQuaternion const &);
    void RotateAxis(bCVector const &, GEFloat);
    void RotateAxisX(GEFloat);
    void RotateAxisY(GEFloat);
    void RotateAxisZ(GEFloat);
    void RotateLocalAxisX(GEFloat);
    void RotateLocalAxisY(GEFloat);
    void RotateLocalAxisZ(GEFloat);
    void SetLerp(bCQuaternion, bCQuaternion const &, GEFloat);
    void SetQuaternion(bCQuaternion const &);
    void SetQuaternion(bCAxisAngle const &);
    void SetQuaternion(bCEulerAngles const &);
    void SetQuaternion(bCMatrix3 const &);
    void SetQuaternion(bCMatrix const &);
    void SetQuaternion(bCSphericalRotation const &);
    void SetQuaternion(bCVector const &, bCVector const &);
    void SetQuaternion(GEFloat, GEFloat, GEFloat, GEFloat);
    void SetSlerp(bCQuaternion, bCQuaternion, GEFloat);
    void SetToProduct(bCQuaternion const &, bCQuaternion const &);
    void SetW(GEFloat);
    void SetX(GEFloat);
    void SetY(GEFloat);
    void SetZ(GEFloat);
    void Sub(bCQuaternion const &);

  private:
    GEFloat m_fX;
    GEFloat m_fY;
    GEFloat m_fZ;
    GEFloat m_fW;
};
