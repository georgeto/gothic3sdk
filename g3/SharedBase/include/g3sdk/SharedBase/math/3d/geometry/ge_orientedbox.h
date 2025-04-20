#pragma once

#include <SharedBase/math/3d/ge_vector.h>
#include <SharedBase/math/3d/geometry/ge_box.h>
#include <SharedBase/math/3d/geometry/ge_plane.h>
#include <SharedBase/math/3d/geometry/ge_sphere.h>
#include <SharedBase/math/3d/geometry/ge_stretch.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCFrustum;
class bCIStream;
class bCMatrix3;
class bCMatrix;
class bCOStream;
class bCTriangle;
class bCUnitedRay;

class GE_DLLIMPORT bCOrientedBox
{
  public:
    bCOrientedBox(bCOrientedBox const &);
    bCOrientedBox(bCBox const &, bCMatrix3 const &);
    bCOrientedBox();
    ~bCOrientedBox();

  public:
    bCOrientedBox &operator=(bCOrientedBox const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(bCOrientedBox const &) const;
    GEBool operator!=(bCOrientedBox const &) const;
    bCOrientedBox operator*(bCMatrix3 const &) const;
    bCOrientedBox operator*(bCMatrix const &) const;
    bCOrientedBox operator*(GEFloat) const;
    bCOrientedBox operator-(bCVector const &) const;
    bCOrientedBox operator+(bCVector const &) const;
    bCOrientedBox operator/(GEFloat) const;
    bCOrientedBox &operator*=(bCMatrix3 const &);
    bCOrientedBox &operator*=(bCMatrix const &);
    bCOrientedBox &operator*=(GEFloat);
    bCOrientedBox &operator+=(bCVector const &);
    bCOrientedBox &operator-=(bCVector const &);
    bCOrientedBox &operator/=(GEFloat);
    bCOrientedBox &operator|=(bCOrientedBox const &);

  public:
    bCVector &AccessAxis(GEInt);
    bCVector &AccessCenter();
    bCVector &AccessExtent();
    bCMatrix3 &AccessOrientation();
    GEBool Contains(bCOrientedBox const &) const;
    GEBool Contains(bCBox const &) const;
    GEBool Contains(bCFrustum const &) const;
    GEBool Contains(bCSphere const &) const;
    GEBool Contains(bCStretch const &) const;
    GEBool Contains(bCTriangle const &) const;
    GEBool Contains(bCUnitedRay const &) const;
    GEBool Contains(bCVector const &) const;
    void Create(bCOrientedBox const &);
    void Create(bCBox const &, bCMatrix3 const &);
    bCVector const &GetAxis(GEInt) const;
    bCVector const &GetCenter() const;
    bCBox GetCircumAxisBox() const;
    void GetCircumAxisBox(bCBox &) const;
    bCSphere GetCircumSphere() const;
    void GetCircumSphere(bCSphere &) const;
    GEFloat GetDepth() const;
    bCStretch GetEdge(GEInt) const;
    void GetEdge(GEInt, bCStretch &) const;
    void GetEdges(bCStretch *const) const;
    bCVector const &GetExtent() const;
    GEFloat GetHeight() const;
    bCSphere GetInSphere() const;
    void GetInSphere(bCSphere &) const;
    bCOrientedBox GetInvScaled(bCVector const &) const;
    bCOrientedBox GetInvScaled(GEFloat) const;
    void GetInvScaled(bCOrientedBox &, bCVector const &) const;
    void GetInvScaled(bCOrientedBox &, GEFloat) const;
    bCOrientedBox GetInvTransformed(bCMatrix3 const &) const;
    bCOrientedBox GetInvTransformed(bCMatrix const &) const;
    void GetInvTransformed(bCOrientedBox &, bCMatrix3 const &) const;
    void GetInvTransformed(bCOrientedBox &, bCMatrix const &) const;
    bCOrientedBox GetInvTranslated(bCVector const &) const;
    bCOrientedBox GetInvTranslated(GEFloat) const;
    void GetInvTranslated(bCOrientedBox &, bCVector const &) const;
    void GetInvTranslated(bCOrientedBox &, GEFloat) const;
    bCVector GetMagnitude() const;
    void GetMagnitude(bCVector &) const;
    bCOrientedBox GetMerged(bCOrientedBox const &) const;
    void GetMerged(bCOrientedBox &, bCOrientedBox const &) const;
    bCMatrix3 const &GetOrientation() const;
    bCPlane GetPlane(GEInt) const;
    void GetPlane(GEInt, bCPlane &) const;
    void GetPlanes(bCPlane *const) const;
    void GetProjectedExtent(bCVector const &, GEFloat &, GEFloat &) const;
    bCOrientedBox GetScaled(bCVector const &) const;
    bCOrientedBox GetScaled(GEFloat) const;
    void GetScaled(bCOrientedBox &, bCVector const &) const;
    void GetScaled(bCOrientedBox &, GEFloat) const;
    bCOrientedBox GetTransformed(bCMatrix3 const &) const;
    bCOrientedBox GetTransformed(bCMatrix const &) const;
    void GetTransformed(bCOrientedBox &, bCMatrix3 const &) const;
    void GetTransformed(bCOrientedBox &, bCMatrix const &) const;
    bCOrientedBox GetTranslated(bCVector const &) const;
    bCOrientedBox GetTranslated(GEFloat) const;
    void GetTranslated(bCOrientedBox &, bCVector const &) const;
    void GetTranslated(bCOrientedBox &, GEFloat) const;
    bCVector GetVertex(GEInt) const;
    void GetVertex(GEInt, bCVector &) const;
    void GetVertices(bCVector *const) const;
    GEFloat GetVolume() const;
    GEFloat GetWidth() const;
    GEBool Intersects(bCOrientedBox const &) const;
    GEBool Intersects(bCBox const &) const;
    GEBool Intersects(bCPlane const &) const;
    GEBool Intersects(bCSphere const &) const;
    void InvScale(bCVector const &);
    void InvScale(GEFloat);
    void InvTransform(bCMatrix3 const &);
    void InvTransform(bCMatrix const &);
    void InvTranslate(bCVector const &);
    void InvTranslate(GEFloat);
    void Invalidate();
    GEBool IsEqual(bCOrientedBox const &) const;
    GEBool IsValid() const;
    void Merge(bCOrientedBox const &);
    void Scale(bCVector const &);
    void Scale(GEFloat);
    void SetAxis(GEInt, bCVector const &);
    void SetCenter(bCVector const &);
    void SetExtent(bCVector const &);
    void SetInnerBoxFromPoints(bCVector const *, GEInt);
    void SetOrientation(bCMatrix3 const &);
    void SetOuterBoxFromPoints(bCVector const *, GEInt);
    void Transform(bCMatrix3 const &);
    void Transform(bCMatrix const &);
    void Translate(bCVector const &);
    void Translate(GEFloat);

  private:
    bCVector m_vecCenter;
    bCVector m_vecExtent;
    bCMatrix3 m_matOrientation;
};
