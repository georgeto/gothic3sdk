#pragma once

#include <SharedBase/math/3d/ge_vector.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCFrustum;
class bCIStream;
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

class GE_DLLIMPORT bCBox
{
  public:
    enum bEIntersection
    {
        // TODO: Enumerator values
    };

  public:
    bCBox(bCBox const &);
    bCBox(bCVector const &, bCVector const &);
    bCBox(bCVector const &, GEFloat);
    bCBox();
    ~bCBox();

  public:
    bCBox &operator=(bCBox const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(bCBox const &) const;
    GEBool operator!=(bCBox const &) const;
    bCBox operator*(bCMatrix3 const &) const;
    bCBox operator*(bCMatrix const &) const;
    bCBox operator*(GEFloat) const;
    bCBox operator-(bCVector const &) const;
    bCBox operator+(bCVector const &) const;
    bCBox operator/(GEFloat) const;
    bCBox &operator*=(bCMatrix3 const &);
    bCBox &operator*=(bCMatrix const &);
    bCBox &operator*=(GEFloat);
    bCBox &operator+=(bCVector const &);
    bCBox &operator-=(bCVector const &);
    bCBox &operator/=(GEFloat);
    bCBox &operator&=(bCBox const &);
    bCBox &operator|=(bCBox const &);
    bCBox &operator|=(bCVector const &);

  public:
    GEFloat &AccessCoordinate(GEInt);
    bCVector &AccessMax();
    bCVector &AccessMin();
    void Clear();
    GEBool Contains(bCBox const &) const;
    GEBool Contains(bCFrustum const &) const;
    GEBool Contains(bCSphere const &) const;
    GEBool Contains(bCStretch const &) const;
    GEBool Contains(bCTriangle const &) const;
    GEBool Contains(bCUnitedRay const &) const;
    GEBool Contains(bCVector const &) const;
    GEBool Contains(bCVector const *const) const;
    GEBool Cull(bCBox const &) const;
    GEBool Cull(bCFrustum const &) const;
    GEBool Cull(bCLine const &) const;
    GEBool Cull(bCPlane const &) const;
    GEBool Cull(bCRay const &) const;
    GEBool Cull(bCSphere const &) const;
    GEBool Cull(bCStretch const &) const;
    GEBool Cull(bCTriangle const &) const;
    GEBool Cull(bCUnitedRay const &) const;
    GEBool Cull(bCVector const &) const;
    GEBool Cull(bCVector const *const) const;
    bCVector GetCenter() const;
    void GetCenter(bCVector &) const;
    bCVector GetCenterGround() const;
    void GetCenterGround(bCVector &) const;
    GEFloat GetCoordinate(GEInt) const;
    void GetCoordinate(GEInt, GEFloat &) const;
    GEFloat GetDepth() const;
    GEFloat GetHeight() const;
    bCBox GetIntersected(bCBox const &) const;
    bEIntersection GetIntersection(bCBox const &) const;
    GEFloat GetIntersectionDistance(bCLine const &) const;
    GEFloat GetIntersectionDistance(bCRay const &) const;
    GEFloat GetIntersectionDistance(bCStretch const &) const;
    bCBox GetInvScaled(bCVector const &) const;
    bCBox GetInvScaled(GEFloat) const;
    bCBox GetInvTranslated(bCVector const &) const;
    bCBox GetInvTranslated(GEFloat) const;
    bCVector GetMagnitude() const;
    void GetMagnitude(bCVector &) const;
    bCVector const &GetMax() const;
    void GetMax(bCVector &) const;
    GEFloat GetMaxExtend() const;
    bCBox GetMerged(bCBox const &) const;
    bCBox GetMerged(bCVector const &) const;
    bCVector const &GetMin() const;
    void GetMin(bCVector &) const;
    GEFloat GetMinExtend() const;
    bCBox GetNormalized() const;
    bCBox GetScaled(bCVector const &) const;
    bCBox GetScaled(GEFloat) const;
    bCBox GetShrunk(bCVector const &) const;
    bCBox GetShrunk(GEFloat) const;
    bCBox GetTransformed(bCMatrix3 const &) const;
    bCBox GetTransformed(bCMatrix const &) const;
    bCBox GetTranslated(bCVector const &) const;
    bCBox GetTranslated(GEFloat) const;
    bCVector GetVertex(GEInt) const;
    void GetVertex(GEInt, bCVector &) const;
    GEFloat GetVolume() const;
    bCBox GetWidened(bCVector const &) const;
    bCBox GetWidened(GEFloat) const;
    GEFloat GetWidth() const;
    void Intersect(bCBox const &);
    GEBool Intersects(bCBox const &) const;
    GEBool Intersects(bCFrustum const &) const;
    GEBool Intersects(bCLine const &, GEFloat &) const;
    GEBool Intersects(bCPlane const &) const;
    GEBool Intersects(bCRay const &, GEFloat &) const;
    GEBool Intersects(bCSphere const &) const;
    GEBool Intersects(bCStretch const &, GEFloat &) const;
    GEBool Intersects(bCTriangle const &) const;
    GEBool Intersects(bCUnitedRay const &, GEFloat &) const;
    GEBool Intersects(bCVector const &) const;
    GEBool Intersects(bCVector const *const) const;
    GEBool IntersectsExclusive(bCBox const &) const;
    GEBool IntersectsSweep(bCBox const &, bCBox const &, bCBox const &, GEFloat &) const;
    GEBool IntersectsSweep(bCBox const &, bCBox const &, GEFloat &) const;
    GEBool IntersectsSweep(bCVector const &, bCBox const &, bCVector const &, GEFloat &) const;
    GEBool IntersectsSweep(bCVector const &, bCBox const &, GEFloat &) const;
    void InvScale(bCVector const &);
    void InvScale(GEFloat);
    void InvTranslate(bCVector const &);
    void InvTranslate(GEFloat);
    void Invalidate();
    GEBool IsEqual(bCBox const &) const;
    GEBool IsNormalized() const;
    GEBool IsValid() const;
    void Merge(bCBox const &);
    void Merge(bCVector const &);
    void Normalize();
    void Scale(bCVector const &);
    void Scale(GEFloat);
    GEBool Separates(bCVector const *, GEInt, bCVector const &) const;
    void SetBox(bCBox const &);
    void SetBox(bCVector const &, bCVector const &);
    void SetBox(bCVector const &, GEFloat);
    void SetCenter(bCVector const &);
    void SetCoordinate(GEInt, GEFloat);
    void SetMax(bCVector const &);
    void SetMin(bCVector const &);
    void Shrink(bCVector const &);
    void Shrink(GEFloat);
    void Transform(bCMatrix3 const &);
    void Transform(bCMatrix const &);
    void Translate(bCVector const &);
    void Translate(GEFloat);
    void Widen(bCVector const &);
    void Widen(GEFloat);

  protected:
    static GEFloat m_fDummy;

  public:
    bCVector m_Min;
    bCVector m_Max;
};
