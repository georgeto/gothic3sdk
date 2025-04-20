#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class NxVec3;
class bCIStream;
class bCMatrix3;
class bCMatrix;
class bCOStream;
class bCString;

class GE_DLLIMPORT bCVector
{
  public:
    enum bECoordinate
    {
        bECoordinate_X,
        bECoordinate_Y,
        bECoordinate_Z,
        bECoordinate_Count,
        bECoordinate_ForceDWORD = GE_FORCE_DWORD
    };

  public:
    static bCVector GE_STDCALL CrossProduct(bCVector const &, bCVector const &);
    static GEFloat GE_STDCALL DotProduct(bCVector const &, bCVector const &);
    static bCVector const &GE_STDCALL GetForward();
    static bCVector const &GE_STDCALL GetRight();
    static bCVector const &GE_STDCALL GetUnit();
    static bCVector const &GE_STDCALL GetUp();
    static bCVector const &GE_STDCALL GetZero();

  public:
    GEFloat m_fX;
    GEFloat m_fY;
    GEFloat m_fZ;

  public:
    bCVector(bCVector const &);
    explicit bCVector(NxVec3 const &);
    explicit bCVector(GEFloat);
    bCVector(GEFloat, GEFloat, GEFloat);
    explicit bCVector(GEFloat const *const);
    bCVector();
    ~bCVector();

  public:
    explicit operator NxVec3 &();
    explicit operator NxVec3 const &() const;
    bCVector &operator=(bCVector const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(bCVector const &) const;
    GEBool operator!=(bCVector const &) const;
    GEFloat &operator[](GEInt);
    GEFloat const &operator[](GEInt) const;
    bCVector operator*(bCMatrix const &) const;
    bCVector operator*(GEFloat) const;
    bCVector operator-(bCVector const &) const;
    bCVector operator-() const;
    bCVector operator+(bCVector const &) const;
    bCVector operator/(bCMatrix const &) const;
    bCVector operator/(GEFloat) const;
    bCVector &operator*=(bCMatrix3 const &);
    bCVector &operator*=(bCMatrix const &);
    bCVector &operator*=(GEFloat);
    bCVector &operator+=(bCVector const &);
    bCVector &operator-=(bCVector const &);
    bCVector &operator/=(bCMatrix3 const &);
    bCVector &operator/=(bCMatrix const &);
    bCVector &operator/=(GEFloat);

  public:
    GEFloat &AccessCoordinate(GEInt);
    GEFloat (&AccessCoordinates())[3];
    GEFloat &AccessX();
    GEFloat &AccessY();
    GEFloat &AccessZ();
    void Clear();
    void CrossProduct(bCVector const &);
    void Decompose(bCVector const &, bCVector &, bCVector &) const;
    GEFloat GetAngleDeg(bCVector const &) const;
    GEFloat GetAngleRad(bCVector const &) const;
    GEFloat GetAngleUnitDeg(bCVector const &) const;
    GEFloat GetAngleUnitRad(bCVector const &) const;
    void GetAziElev(GEFloat &, GEFloat &) const;
    void GetAziElevApprox(GEFloat &, GEFloat &) const;
    void GetAziElevUnit(GEFloat &, GEFloat &) const;
    GEFloat const &GetCoordinate(GEInt) const;
    void GetCoordinate(GEInt, GEFloat &) const;
    GEFloat const (&GetCoordinates() const)[3];
    void GetCoordinates(GEFloat &, GEFloat &, GEFloat &) const;
    void GetCoordinates(GEFloat *const) const;
    bCVector GetCrossProduct(bCVector const &) const;
    GEFloat GetDotProduct(bCVector const &) const;
    bCVector GetInvScaled(bCVector const &) const;
    bCVector GetInvScaled(GEFloat) const;
    bCVector GetInvTransformed(bCMatrix3 const &) const;
    bCVector GetInvTransformed(bCMatrix const &) const;
    bCVector GetInvTransformedDirection(bCMatrix const &) const;
    bCVector GetInvTranslated(bCVector const &) const;
    bCVector GetInvTranslated(GEFloat) const;
    bCVector GetInverted() const;
    bCVector GetLerp(bCVector const &, GEFloat) const;
    GEFloat GetMagnitude() const;
    GEFloat GetMagnitude2D(bECoordinate) const;
    GEFloat GetMagnitudeApprox() const;
    GEFloat GetMagnitudeNormalize();
    bCVector GetNormalized() const;
    bCVector GetNormalizedSafe() const;
    bCVector GetRemovedByDimension(bECoordinate) const;
    bCVector GetRemovedByDimensionKeepMagnitude(bECoordinate) const;
    bCVector GetRemovedByDimensionNormalize(bECoordinate) const;
    bCVector GetScaled(bCVector const &) const;
    bCVector GetScaled(GEFloat) const;
    bCVector GetSlerp(bCVector const &, GEFloat) const;
    GEFloat GetSquareMagnitude() const;
    GEFloat GetSquareMagnitude2D(bECoordinate) const;
    bCVector GetTransformed(bCMatrix3 const &) const;
    bCVector GetTransformed(bCMatrix const &) const;
    bCVector GetTransformedDirection(bCMatrix const &) const;
    bCVector GetTranslated(bCVector const &) const;
    bCVector GetTranslated(GEFloat) const;
    GEFloat GetX() const;
    void GetX(GEFloat &) const;
    GEFloat GetY() const;
    void GetY(GEFloat &) const;
    GEFloat GetZ() const;
    void GetZ(GEFloat &) const;
    GEBool HasZeroMagnitude() const;
    GEBool HasZeroMagnitude2D(bECoordinate) const;
    GEBool HasZeroMagnitude2DApprox(bECoordinate) const;
    GEBool HasZeroMagnitudeApprox() const;
    void InvScale(bCVector const &);
    void InvScale(GEFloat);
    void InvTransform(bCMatrix3 const &);
    void InvTransform(bCMatrix const &);
    void InvTransformDirection(bCMatrix const &);
    void InvTranslate(bCVector const &);
    void InvTranslate(GEFloat);
    void Invert();
    GEBool IsEqual(bCVector const &) const;
    GEBool IsValid(bCString const &) const;
    bCVector const &Normalize();
    bCVector const &NormalizeApprox();
    bCVector const &NormalizeSafe();
    void PrintDebug(bCString const &) const;
    bCVector Reflect(bCVector const &) const;
    void RemoveDimension(bECoordinate);
    GEBool RemoveDimensionKeepMagnitude(bECoordinate);
    void RemoveDimensionNormalize(bECoordinate);
    void Scale(bCVector const &);
    void Scale(GEFloat);
    void SetCoordinate(GEInt, GEFloat);
    void SetCoordinates(GEFloat, GEFloat, GEFloat);
    void SetCoordinates(GEFloat const *const);
    void SetCrossProduct(bCVector const &, bCVector const &);
    void SetLerp(bCVector const &, bCVector const &, GEFloat);
    void SetSlerp(bCVector, bCVector, GEFloat);
    void SetTransformed(bCVector const &, bCMatrix3 const &);
    void SetTransformed(bCVector const &, bCMatrix const &);
    void SetTransformedDirection(bCVector const &, bCMatrix const &);
    void SetTransposedTransformed(bCVector const &, bCMatrix3 const &);
    void SetVector(bCVector const &);
    void SetVector(NxVec3 const &);
    void SetVector(GEFloat);
    void SetVector(GEFloat, GEFloat, GEFloat);
    void SetX(GEFloat const &);
    void SetY(GEFloat const &);
    void SetZ(GEFloat const &);
    void Transform(bCMatrix3 const &);
    void Transform(bCMatrix const &);
    void TransformDirection(bCMatrix const &);
    void Translate(bCVector const &);
    void Translate(GEFloat);
    void TransposedTransform(bCMatrix3 const &);
};

GE_ASSERT_SIZEOF(bCVector, 0xc)
