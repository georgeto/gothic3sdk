#pragma once

#include <SharedBase/math/3d/ge_vector.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCBox;
class bCIStream;
class bCLine;
class bCMatrix3;
class bCMatrix;
class bCOStream;
class bCPlane;
class bCQuaternion;
class bCRay;
class bCSphere;
class bCStretch;
class bCTriangle;
class bCUnitedRay;

class GE_DLLIMPORT bCFrustum
{
  public:
    bCFrustum(bCFrustum const &);
    explicit bCFrustum(bCBox const &);
    bCFrustum();
    ~bCFrustum();

  public:
    bCFrustum &operator=(bCFrustum const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);
    bCFrustum operator*(bCMatrix3 const &) const;
    bCFrustum operator*(bCMatrix const &) const;
    bCFrustum operator*(GEFloat) const;
    bCFrustum operator-(bCVector const &) const;
    bCFrustum operator-() const;
    bCFrustum operator+(bCVector const &) const;
    bCFrustum operator/(bCMatrix3 const &) const;
    bCFrustum operator/(bCMatrix const &) const;
    bCFrustum operator/(GEFloat) const;
    bCFrustum &operator*=(GEFloat);
    bCFrustum &operator+=(bCVector const &);
    bCFrustum &operator-=(bCVector const &);
    bCFrustum &operator/=(GEFloat);

  public:
    bCPlane &AccessClippingPlane(GEInt);
    void Clear();
    GEBool Contains(bCFrustum const &) const;
    GEBool Contains(bCBox const &) const;
    GEBool Contains(bCSphere const &) const;
    GEBool Contains(bCStretch const &) const;
    GEBool Contains(bCTriangle const &) const;
    GEBool Contains(bCUnitedRay const &) const;
    GEBool Contains(bCVector const &) const;
    GEBool Contains(bCVector const *const) const;
    void CopyFrom(bCFrustum const &);
    void CopyTo(bCFrustum &) const;
    GEBool Cull(bCFrustum const &) const;
    GEBool Cull(bCBox const &) const;
    GEBool Cull(bCLine const &) const;
    GEBool Cull(bCPlane const &) const;
    GEBool Cull(bCRay const &) const;
    GEBool Cull(bCSphere const &) const;
    GEBool Cull(bCStretch const &) const;
    GEBool Cull(bCTriangle const &) const;
    GEBool Cull(bCUnitedRay const &) const;
    GEBool Cull(bCVector const &) const;
    GEBool Cull(bCVector const *const) const;
    bCPlane const &GetClippingPlane(GEInt) const;
    void GetClippingPlane(GEInt, bCPlane &) const;
    GEFloat GetDistance(bCVector const &) const;
    bCFrustum GetInvRotated(bCQuaternion const &) const;
    void GetInvRotated(bCFrustum &, bCQuaternion const &) const;
    bCFrustum GetInvScaled(GEFloat) const;
    void GetInvScaled(bCFrustum &, GEFloat) const;
    bCFrustum GetInvTransformed(bCMatrix3 const &) const;
    bCFrustum GetInvTransformed(bCMatrix const &) const;
    void GetInvTransformed(bCFrustum &, bCMatrix3 const &) const;
    void GetInvTransformed(bCFrustum &, bCMatrix const &) const;
    bCFrustum GetInvTranslated(bCVector const &) const;
    void GetInvTranslated(bCFrustum &, bCVector const &) const;
    bCFrustum GetInverted() const;
    void GetInverted(bCFrustum &) const;
    bCFrustum GetNegated() const;
    void GetNegated(bCFrustum &) const;
    bCFrustum GetNormalized() const;
    bCFrustum GetRotated(bCQuaternion const &) const;
    void GetRotated(bCFrustum &, bCQuaternion const &) const;
    bCFrustum GetScaled(GEFloat) const;
    void GetScaled(bCFrustum &, GEFloat) const;
    bCFrustum GetTransformed(bCMatrix3 const &) const;
    bCFrustum GetTransformed(bCMatrix const &) const;
    void GetTransformed(bCFrustum &, bCMatrix3 const &) const;
    void GetTransformed(bCFrustum &, bCMatrix const &) const;
    bCFrustum GetTranslated(bCVector const &) const;
    void GetTranslated(bCFrustum &, bCVector const &) const;
    bCVector GetVertex(GEInt) const;
    void GetVertex(GEInt, bCVector &) const;
    GEBool Intersects(bCFrustum const &) const;
    GEBool Intersects(bCBox const &) const;
    GEBool Intersects(bCLine const &, GEFloat &) const;
    GEBool Intersects(bCPlane const &) const;
    GEBool Intersects(bCRay const &, GEFloat &) const;
    GEBool Intersects(bCSphere const &) const;
    GEBool Intersects(bCStretch const &, GEFloat &) const;
    GEBool Intersects(bCTriangle const &) const;
    GEBool Intersects(bCUnitedRay const &, GEFloat &) const;
    GEBool Intersects(bCVector const &) const;
    GEBool Intersects(bCVector const *const) const;
    void InvRotate(bCQuaternion const &);
    void InvScale(GEFloat);
    void InvTransform(bCMatrix3 const &);
    void InvTransform(bCMatrix const &);
    void InvTranslate(bCVector const &);
    void Invert();
    void Negate();
    void Normalize();
    void Rotate(bCQuaternion const &);
    void Scale(GEFloat);
    void SetClippingPlane(GEInt, bCPlane const &);
    void SetFrustum(bCFrustum const &);
    void SetFrustum(bCBox const &);
    void SetFrustum(bCMatrix const &);
    void Transform(bCMatrix3 const &);
    void Transform(bCMatrix const &);
    void Translate(bCVector const &);

  protected:
    static GEFloat m_fDummy;
};
