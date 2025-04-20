#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCMatrix;
class bCOStream;

class GE_DLLIMPORT bCVector4
{
  public:
    static GEFloat GE_STDCALL DotProduct(bCVector4 const &, bCVector4 const &);

  public:
    bCVector4(bCVector4 const &);
    explicit bCVector4(GEFloat);
    bCVector4(GEFloat, GEFloat, GEFloat, GEFloat);
    explicit bCVector4(GEFloat const *const);
    bCVector4();
    ~bCVector4();

  public:
    bCVector4 &operator=(bCVector4 const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(bCVector4 const &) const;
    GEBool operator!=(bCVector4 const &) const;
    GEFloat &operator[](GEInt);
    GEFloat const &operator[](GEInt) const;
    bCVector4 operator*(bCMatrix const &) const;
    bCVector4 operator*(GEFloat) const;
    bCVector4 operator-(bCVector4 const &) const;
    bCVector4 operator-() const;
    bCVector4 operator+(bCVector4 const &) const;
    bCVector4 operator/(bCMatrix const &) const;
    bCVector4 operator/(GEFloat) const;
    bCVector4 &operator*=(bCMatrix const &);
    bCVector4 &operator*=(GEFloat);
    bCVector4 &operator+=(bCVector4 const &);
    bCVector4 &operator-=(bCVector4 const &);
    bCVector4 &operator/=(bCMatrix const &);
    bCVector4 &operator/=(GEFloat);

  public:
    GEFloat &AccessCoordinate(GEInt);
    GEFloat (&AccessCoordinates())[4];
    GEFloat &AccessW();
    GEFloat &AccessX();
    GEFloat &AccessY();
    GEFloat &AccessZ();
    void Clear();
    GEFloat const &GetCoordinate(GEInt) const;
    void GetCoordinate(GEInt, GEFloat &) const;
    GEFloat const (&GetCoordinates() const)[4];
    void GetCoordinates(GEFloat &, GEFloat &, GEFloat &, GEFloat &) const;
    void GetCoordinates(GEFloat *const) const;
    GEFloat GetDotProduct(bCVector4 const &) const;
    bCVector4 GetInvScaled(bCVector4 const &) const;
    bCVector4 GetInvScaled(GEFloat) const;
    bCVector4 GetInvTransformed(bCMatrix const &) const;
    bCVector4 GetInvTranslated(bCVector4 const &) const;
    bCVector4 GetInvTranslated(GEFloat) const;
    bCVector4 GetInverted() const;
    GEFloat GetMagnitude() const;
    GEFloat GetMagnitudeApprox() const;
    GEFloat GetMagnitudeNormalize();
    bCVector4 GetNormalized() const;
    bCVector4 GetScaled(bCVector4 const &) const;
    bCVector4 GetScaled(GEFloat) const;
    GEFloat GetSquareMagnitude() const;
    bCVector4 GetTransformed(bCMatrix const &) const;
    bCVector4 GetTranslated(bCVector4 const &) const;
    bCVector4 GetTranslated(GEFloat) const;
    GEFloat GetW() const;
    void GetW(GEFloat &) const;
    GEFloat GetX() const;
    void GetX(GEFloat &) const;
    GEFloat GetY() const;
    void GetY(GEFloat &) const;
    GEFloat GetZ() const;
    void GetZ(GEFloat &) const;
    void InvScale(bCVector4 const &);
    void InvScale(GEFloat);
    void InvTransform(bCMatrix const &);
    void InvTranslate(bCVector4 const &);
    void InvTranslate(GEFloat);
    void Invert();
    GEBool IsEqual(bCVector4 const &) const;
    bCVector4 const &Normalize();
    bCVector4 const &NormalizeApprox();
    bCVector4 const &NormalizeSafe();
    void Scale(bCVector4 const &);
    void Scale(GEFloat);
    void SetCoordinate(GEInt, GEFloat);
    void SetCoordinates(GEFloat, GEFloat, GEFloat, GEFloat);
    void SetCoordinates(GEFloat const *const);
    void SetTransformed(bCVector4 const &, bCMatrix const &);
    void SetVector(bCVector4 const &);
    void SetVector(GEFloat);
    void SetVector(GEFloat, GEFloat, GEFloat, GEFloat);
    void SetW(GEFloat const &);
    void SetX(GEFloat const &);
    void SetY(GEFloat const &);
    void SetZ(GEFloat const &);
    void Transform(bCMatrix const &);
    void Translate(bCVector4 const &);
    void Translate(GEFloat);

  private:
    GEFloat m_fX;
    GEFloat m_fY;
    GEFloat m_fZ;
    GEFloat m_fW;
};
