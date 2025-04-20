#pragma once

#include <SharedBase/math/2d/ge_vector2.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCBox;
class bCFrustum;
class bCIStream;
class bCInfCylinder;
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

class GE_DLLIMPORT bCInfDoubleCylinder
{
  public:
    bCInfDoubleCylinder(bCInfDoubleCylinder const &);
    bCInfDoubleCylinder(bCVector const &, GEFloat, bCVector const &, GEFloat);
    bCInfDoubleCylinder();
    ~bCInfDoubleCylinder();

  public:
    bCInfDoubleCylinder const &operator=(bCInfDoubleCylinder const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(bCInfDoubleCylinder const &) const;
    GEBool operator!=(bCInfDoubleCylinder const &) const;
    bCInfDoubleCylinder operator*(bCMatrix3 const &) const;
    bCInfDoubleCylinder operator*(bCMatrix const &) const;
    bCInfDoubleCylinder operator*(GEFloat) const;
    bCInfDoubleCylinder operator-(bCVector const &) const;
    bCInfDoubleCylinder operator+(bCVector const &) const;
    bCInfDoubleCylinder operator/(GEFloat) const;
    bCInfDoubleCylinder &operator*=(bCMatrix3 const &);
    bCInfDoubleCylinder &operator*=(bCMatrix const &);
    bCInfDoubleCylinder &operator*=(GEFloat);
    bCInfDoubleCylinder &operator+=(bCVector const &);
    bCInfDoubleCylinder &operator-=(bCVector const &);
    bCInfDoubleCylinder &operator/=(GEFloat);
    bCInfDoubleCylinder &operator&=(bCInfDoubleCylinder const &);
    bCInfDoubleCylinder &operator|=(bCInfDoubleCylinder const &);
    bCInfDoubleCylinder &operator|=(bCVector const &);

  public:
    bCVector &AccessPositionA();
    bCVector &AccessPositionB();
    GEFloat &AccessRadiusA();
    GEFloat &AccessRadiusB();
    GEBool Contains(bCInfDoubleCylinder const &) const;
    GEBool Contains(bCBox const &) const;
    GEBool Contains(bCFrustum const &) const;
    GEBool Contains(bCInfCylinder const &) const;
    GEBool Contains(bCStretch const &) const;
    GEBool Contains(bCTriangle const &) const;
    GEBool Contains(bCUnitedRay const &) const;
    GEBool Contains(bCVector const &) const;
    GEBool Contains(bCVector const *const) const;
    GEBool Cull(bCInfDoubleCylinder const &) const;
    GEBool Cull(bCBox const &) const;
    GEBool Cull(bCFrustum const &) const;
    GEBool Cull(bCInfCylinder const &) const;
    GEBool Cull(bCLine const &) const;
    GEBool Cull(bCPlane const &) const;
    GEBool Cull(bCRay const &) const;
    GEBool Cull(bCSphere const &) const;
    GEBool Cull(bCStretch const &) const;
    GEBool Cull(bCTriangle const &) const;
    GEBool Cull(bCUnitedRay const &) const;
    GEBool Cull(bCVector const &, GEBool) const;
    GEBool Cull(bCVector const *const) const;
    bCInfDoubleCylinder GetIntersected(bCInfDoubleCylinder const &) const;
    GEFloat GetIntersectionDistance(bCRay const &) const;
    bCInfDoubleCylinder GetInvScaled(GEFloat) const;
    bCInfDoubleCylinder GetInvTranslated(bCVector const &) const;
    bCInfDoubleCylinder GetInvTranslated(GEFloat) const;
    bCInfDoubleCylinder GetMerged(bCInfDoubleCylinder const &) const;
    bCInfDoubleCylinder GetMerged(bCVector const &) const;
    bCVector const &GetPositionA() const;
    void GetPositionA(bCVector &) const;
    bCVector const &GetPositionB() const;
    void GetPositionB(bCVector &) const;
    GEFloat GetRadiusA() const;
    void GetRadiusA(GEFloat &) const;
    GEFloat GetRadiusB() const;
    void GetRadiusB(GEFloat &) const;
    bCInfDoubleCylinder GetScaled(GEFloat) const;
    bCInfDoubleCylinder GetShrunk(GEFloat) const;
    bCInfDoubleCylinder GetTransformed(bCMatrix3 const &) const;
    bCInfDoubleCylinder GetTransformed(bCMatrix const &) const;
    bCInfDoubleCylinder GetTranslated(bCVector const &) const;
    bCInfDoubleCylinder GetTranslated(GEFloat) const;
    GEFloat GetVolume() const;
    bCInfDoubleCylinder GetWidened(GEFloat) const;
    void Intersect(bCInfDoubleCylinder const &);
    GEBool Intersects(bCInfDoubleCylinder const &) const;
    GEBool Intersects(bCBox const &) const;
    GEBool Intersects(bCFrustum const &) const;
    GEBool Intersects(bCInfCylinder const &) const;
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
    GEBool IsEqual(bCInfDoubleCylinder const &) const;
    GEBool IsValid() const;
    void Merge(bCInfDoubleCylinder const &);
    void Merge(bCVector const &);
    void Scale(GEFloat);
    GEBool Separates(bCBox const &, bCVector const &) const;
    GEBool Separates(bCVector const *, GEInt, bCVector const &) const;
    void SetInfDoubleCylinder(bCInfDoubleCylinder const &);
    void SetInfDoubleCylinder(bCVector const &, GEFloat, bCVector const &, GEFloat);
    void SetPositionA(bCVector const &);
    void SetPositionB(bCVector const &);
    void SetRadiusA(GEFloat);
    void SetRadiusB(GEFloat);
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
