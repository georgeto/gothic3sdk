#pragma once

#include <SharedBase/math/3d/ge_vector.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCAxisAngle;
class bCEulerAngles;
class bCIStream;
class bCMatrix;
class bCOStream;
class bCQuaternion;

class GE_DLLIMPORT bCMatrix3
{
  public:
    static bCMatrix3 GE_STDCALL GetIdentity();
    static void GE_STDCALL GetIdentity(bCMatrix3 &);

  public:
    explicit bCMatrix3(bCQuaternion &);
    bCMatrix3(bCMatrix3 const &);
    explicit bCMatrix3(bCMatrix const &);
    explicit bCMatrix3(bCQuaternion const &);
    explicit bCMatrix3(GEFloat);
    explicit bCMatrix3(GEFloat const (*const)[3]);
    explicit bCMatrix3(GEFloat const *const);
    explicit bCMatrix3(bCVector const *const);
    bCMatrix3();
    ~bCMatrix3();

  public:
    bCMatrix3 &operator=(bCMatrix3 const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(bCMatrix3 const &) const;
    GEBool operator!=(bCMatrix3 const &) const;
    GEFloat &operator[](GEInt);
    GEFloat operator[](GEInt) const;
    bCMatrix3 operator*(bCMatrix3 const &) const;
    bCMatrix3 operator*(bCAxisAngle const &) const;
    bCMatrix3 operator*(bCEulerAngles const &) const;
    bCMatrix3 operator*(bCQuaternion const &) const;
    bCMatrix3 operator*(GEFloat) const;
    bCVector operator*(bCVector const &) const;
    bCMatrix3 operator-(bCMatrix3 const &) const;
    bCMatrix3 operator-() const;
    bCMatrix3 operator+(bCMatrix3 const &) const;
    bCMatrix3 operator/(GEFloat) const;
    GEFloat &operator()(GEInt, GEInt);
    bCVector &operator()(GEInt);
    bCVector const &operator()(GEInt) const;
    GEFloat operator()(GEInt, GEInt) const;
    bCMatrix3 operator~() const;
    bCMatrix3 &operator*=(bCMatrix3 const &);
    bCMatrix3 &operator*=(bCAxisAngle const &);
    bCMatrix3 &operator*=(bCEulerAngles const &);
    bCMatrix3 &operator*=(bCQuaternion const &);
    bCMatrix3 &operator*=(GEFloat);
    bCMatrix3 &operator+=(bCMatrix3 const &);
    bCMatrix3 &operator-=(bCMatrix3 const &);
    bCMatrix3 &operator/=(GEFloat);

  public:
    GEFloat &AccessElement(GEInt);
    GEFloat &AccessElement(GEInt, GEInt);
    bCVector &AccessRow(GEInt);
    bCVector &AccessXAxis();
    bCVector &AccessYAxis();
    bCVector &AccessZAxis();
    void Add(bCMatrix3 const &);
    void Clear();
    void Divide(GEFloat);
    bCVector GetColumn(GEInt) const;
    void GetColumn(GEInt, bCVector &) const;
    void GetColumn(GEInt, GEFloat *const) const;
    GEFloat GetDeterminant() const;
    GEFloat GetDeterminantAdjoint(GEInt, GEInt) const;
    bCMatrix3 GetDifference(bCMatrix3 const &) const;
    void GetDifference(bCMatrix3 &, bCMatrix3 const &) const;
    GEFloat GetElement(GEInt) const;
    GEFloat GetElement(GEInt, GEInt) const;
    void GetElement(GEInt, GEFloat &) const;
    void GetElement(GEInt, GEInt, GEFloat &) const;
    bCMatrix3 GetInverted() const;
    void GetInverted(bCMatrix3 &) const;
    bCMatrix3 GetNegated() const;
    void GetNegated(bCMatrix3 &) const;
    bCMatrix3 GetOrthogonalized() const;
    void GetOrthogonalized(bCMatrix3 &) const;
    bCMatrix3 GetOrthonormalized() const;
    void GetOrthonormalized(bCMatrix3 &) const;
    bCMatrix3 GetProduct(bCMatrix3 const &) const;
    bCMatrix3 GetProduct(GEFloat) const;
    void GetProduct(bCMatrix3 &, bCMatrix3 const &) const;
    void GetProduct(bCMatrix3 &, GEFloat) const;
    bCMatrix3 GetProductPrefix(bCMatrix3 const &) const;
    void GetProductPrefix(bCMatrix3 &, bCMatrix3 const &) const;
    bCMatrix3 GetQuotient(GEFloat) const;
    void GetQuotient(bCMatrix3 &, GEFloat) const;
    bCMatrix3 GetRotated(bCAxisAngle const &) const;
    bCMatrix3 GetRotated(bCEulerAngles const &) const;
    bCMatrix3 GetRotated(bCQuaternion const &) const;
    void GetRotated(bCMatrix3 &, bCAxisAngle const &) const;
    void GetRotated(bCMatrix3 &, bCEulerAngles const &) const;
    void GetRotated(bCMatrix3 &, bCQuaternion const &) const;
    bCMatrix3 GetRotatedAxisX(GEFloat) const;
    void GetRotatedAxisX(bCMatrix3 &, GEFloat) const;
    bCMatrix3 GetRotatedAxisY(GEFloat) const;
    void GetRotatedAxisY(bCMatrix3 &, GEFloat) const;
    bCMatrix3 GetRotatedAxisZ(GEFloat) const;
    void GetRotatedAxisZ(bCMatrix3 &, GEFloat) const;
    bCMatrix3 GetRotatedLocal(bCAxisAngle const &) const;
    bCMatrix3 GetRotatedLocal(bCEulerAngles const &) const;
    bCMatrix3 GetRotatedLocal(bCQuaternion const &) const;
    void GetRotatedLocal(bCMatrix3 &, bCAxisAngle const &) const;
    void GetRotatedLocal(bCMatrix3 &, bCEulerAngles const &) const;
    void GetRotatedLocal(bCMatrix3 &, bCQuaternion const &) const;
    bCMatrix3 GetRotatedLocalAxisX(GEFloat) const;
    void GetRotatedLocalAxisX(bCMatrix3 &, GEFloat) const;
    bCMatrix3 GetRotatedLocalAxisY(GEFloat) const;
    void GetRotatedLocalAxisY(bCMatrix3 &, GEFloat) const;
    bCMatrix3 GetRotatedLocalAxisZ(GEFloat) const;
    void GetRotatedLocalAxisZ(bCMatrix3 &, GEFloat) const;
    bCVector const &GetRow(GEInt) const;
    void GetRow(GEInt, bCVector &) const;
    void GetRow(GEInt, GEFloat *const) const;
    bCMatrix3 GetSum(bCMatrix3 const &) const;
    void GetSum(bCMatrix3 &, bCMatrix3 const &) const;
    bCMatrix3 GetTransposed() const;
    void GetTransposed(bCMatrix3 &) const;
    bCVector const &GetXAxis() const;
    void GetXAxis(bCVector &) const;
    bCVector const &GetYAxis() const;
    void GetYAxis(bCVector &) const;
    bCVector const &GetZAxis() const;
    void GetZAxis(bCVector &) const;
    void Invert();
    GEBool IsEqual(bCMatrix3 const &) const;
    GEBool IsIdentity() const;
    void LookAt(bCVector const &, bCVector const &);
    void LookAt(bCVector const &);
    void ModifyXAxis(bCVector const &);
    void ModifyYAxis(bCVector const &);
    void ModifyZAxis(bCVector const &);
    void Multiply(bCMatrix3 const &);
    void Multiply(GEFloat);
    void Negate();
    void Orthogonalize();
    void Orthonormalize();
    void ReverseMultiply(bCMatrix3 const &);
    void Rotate(bCAxisAngle const &);
    void Rotate(bCEulerAngles const &);
    void Rotate(bCQuaternion const &);
    void RotateAxisX(GEFloat);
    void RotateAxisY(GEFloat);
    void RotateAxisZ(GEFloat);
    void RotateLocal(bCAxisAngle const &);
    void RotateLocal(bCEulerAngles const &);
    void RotateLocal(bCQuaternion const &);
    void RotateLocalAxisX(GEFloat);
    void RotateLocalAxisY(GEFloat);
    void RotateLocalAxisZ(GEFloat);
    void Scale(bCVector const &);
    void Scale(GEFloat);
    void SetElement(GEInt, GEInt, GEFloat);
    void SetElement(GEInt, GEFloat);
    void SetIdentity();
    void SetMatrix(bCMatrix3 const &);
    void SetMatrix(bCMatrix const &);
    void SetMatrix(GEFloat);
    void SetMatrix(GEFloat const (*const)[3]);
    void SetMatrix(GEFloat const *const);
    void SetMatrix(bCVector const *const);
    void SetRow(GEInt, bCVector const &);
    void SetRow(GEInt, GEFloat const *const);
    void SetToCrossProduct(bCVector const &);
    void SetToInverse(bCMatrix3 const &);
    void SetToProduct(bCMatrix3 const &, bCMatrix3 const &);
    void SetToRotation(bCAxisAngle const &);
    void SetToRotation(bCEulerAngles const &);
    void SetToRotation(bCQuaternion const &);
    void SetToRotationAxisX(GEFloat);
    void SetToRotationAxisY(GEFloat);
    void SetToRotationAxisZ(GEFloat);
    void SetToScaling(bCVector const &);
    void SetToScaling(GEFloat);
    void Sub(bCMatrix3 const &);
    void Transpose();

  private:
    enum bEElement
    {
        bEElement_11,
        bEElement_12,
        bEElement_13,
        bEElement_21,
        bEElement_22,
        bEElement_23,
        bEElement_31,
        bEElement_32,
        bEElement_33,
        bEElement_Count,
        bEElement_ForceDWORD = GE_FORCE_DWORD
    };
    enum bERow
    {
        bERow_XAxis,
        bERow_YAxis,
        bERow_ZAxis,
        bERow_Count,
        bERow_ForceDWORD = GE_FORCE_DWORD
    };
    enum bEColumn
    {
        bEColumn_X,
        bEColumn_Y,
        bEColumn_Z,
        bEColumn_Count,
        bEColumn_ForceDWORD = GE_FORCE_DWORD
    };

  private:
    union
    {
        GEFloat m_fElements[bEElement_Count];
        GEFloat m_fRowColumn[bERow_Count][bEColumn_Count];
    };
};

GE_ASSERT_SIZEOF(bCMatrix3, 0x24)
