#pragma once

#include <SharedBase/math/2d/ge_vector2.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCBox;
class bCFrustum;
class bCIStream;
class bCInfDoubleCylinder;
class bCLine;
class bCMatrix3;
class bCMatrix;
class bCOStream;
class bCPlane;
class bCRay;
class bCSphere;
class bCStretch;
class bCTriangle;
class bCUnitedRay;
class bCVector;

class GE_DLLIMPORT bCInfCylinder
{
  public:
    bCInfCylinder(bCInfCylinder const &);
    bCInfCylinder(bCVector const &, GEFloat);
    bCInfCylinder();
    ~bCInfCylinder();

  public:
    bCInfCylinder const &operator=(bCInfCylinder const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(bCInfCylinder const &) const;
    GEBool operator!=(bCInfCylinder const &) const;
    bCInfCylinder operator*(bCMatrix3 const &) const;
    bCInfCylinder operator*(bCMatrix const &) const;
    bCInfCylinder operator*(GEFloat) const;
    bCInfCylinder operator-(bCVector const &) const;
    bCInfCylinder operator+(bCVector const &) const;
    bCInfCylinder operator/(GEFloat) const;
    bCInfCylinder &operator*=(bCMatrix3 const &);
    bCInfCylinder &operator*=(bCMatrix const &);
    bCInfCylinder &operator*=(GEFloat);
    bCInfCylinder &operator+=(bCVector const &);
    bCInfCylinder &operator-=(bCVector const &);
    bCInfCylinder &operator/=(GEFloat);
    bCInfCylinder &operator&=(bCInfCylinder const &);
    bCInfCylinder &operator|=(bCInfCylinder const &);
    bCInfCylinder &operator|=(bCVector const &);

  public:
    bCVector &AccessPosition();
    GEFloat &AccessRadius();
    GEBool Contains(bCInfCylinder const &) const;
    GEBool Contains(bCBox const &) const;
    GEBool Contains(bCFrustum const &) const;
    GEBool Contains(bCInfDoubleCylinder const &) const;
    GEBool Contains(bCStretch const &) const;
    GEBool Contains(bCTriangle const &) const;
    GEBool Contains(bCUnitedRay const &) const;
    GEBool Contains(bCVector const &) const;
    GEBool Contains(bCVector const *const) const;
    GEBool Cull(bCInfCylinder const &) const;
    GEBool Cull(bCBox const &) const;
    GEBool Cull(bCFrustum const &) const;
    GEBool Cull(bCInfDoubleCylinder const &) const;
    GEBool Cull(bCLine const &) const;
    GEBool Cull(bCPlane const &) const;
    GEBool Cull(bCRay const &) const;
    GEBool Cull(bCSphere const &) const;
    GEBool Cull(bCStretch const &) const;
    GEBool Cull(bCTriangle const &) const;
    GEBool Cull(bCUnitedRay const &) const;
    GEBool Cull(bCVector const &, GEBool) const;
    GEBool Cull(bCVector const *const) const;
    bCInfCylinder GetIntersected(bCInfCylinder const &) const;
    GEFloat GetIntersectionDistance(bCRay const &) const;
    bCInfCylinder GetInvScaled(GEFloat) const;
    bCInfCylinder GetInvTranslated(bCVector const &) const;
    bCInfCylinder GetInvTranslated(GEFloat) const;
    bCInfCylinder GetMerged(bCInfCylinder const &) const;
    bCInfCylinder GetMerged(bCVector const &) const;
    bCVector const &GetPosition() const;
    void GetPosition(bCVector &) const;
    GEFloat GetRadius() const;
    void GetRadius(GEFloat &) const;
    bCInfCylinder GetScaled(GEFloat) const;
    bCInfCylinder GetShrunk(GEFloat) const;
    bCInfCylinder GetTransformed(bCMatrix3 const &) const;
    bCInfCylinder GetTransformed(bCMatrix const &) const;
    bCInfCylinder GetTranslated(bCVector const &) const;
    bCInfCylinder GetTranslated(GEFloat) const;
    GEFloat GetVolume() const;
    bCInfCylinder GetWidened(GEFloat) const;
    void Intersect(bCInfCylinder const &);
    GEBool Intersects(bCInfCylinder const &) const;
    GEBool Intersects(bCBox const &) const;
    GEBool Intersects(bCFrustum const &) const;
    GEBool Intersects(bCInfDoubleCylinder const &) const;
    GEBool Intersects(bCLine const &, GEFloat &) const;
    GEBool Intersects(bCPlane const &) const;
    GEBool Intersects(bCRay const &, GEFloat &) const;
    GEBool Intersects(bCStretch const &, GEFloat &, bCVector2 &, GEBool, GEBool) const;
    GEBool Intersects(bCTriangle const &) const;
    GEBool Intersects(bCUnitedRay const &, GEFloat &) const;
    GEBool Intersects(bCVector const &) const;
    GEBool Intersects(bCVector const *const) const;
    void InvScale(GEFloat);
    void InvTranslate(bCVector const &);
    void InvTranslate(GEFloat);
    void Invalidate();
    GEBool IsEqual(bCInfCylinder const &) const;
    GEBool IsValid() const;
    void Merge(bCInfCylinder const &);
    void Merge(bCVector const &);
    void Scale(GEFloat);
    GEBool Separates(bCBox const &, bCVector const &) const;
    GEBool Separates(bCVector const *, GEInt, bCVector const &) const;
    void SetInfCylinder(bCInfCylinder const &);
    void SetInfCylinder(bCVector const &, GEFloat);
    void SetPosition(bCVector const &);
    void SetRadius(GEFloat);
    void Shrink(GEFloat);
    void Transform(bCMatrix3 const &);
    void Transform(bCMatrix const &);
    void Translate(bCVector const &);
    void Translate(GEFloat);
    void Widen(GEFloat);

  protected:
    static GEBool m_bDummy;
    static GEFloat m_fDummy;
    static bCVector2 m_vecDummy;
};
