#pragma once

#include <SharedBase/math/3d/ge_matrix3.h>
#include <SharedBase/math/3d/geometry/ge_triangle.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCBox;
class bCFrustum;
class bCIStream;
class bCMatrix;
class bCOStream;
class bCPlane;
class bCSphere;
class bCVector;

class GE_DLLIMPORT bCLine
{
  public:
    bCLine(bCLine const &);
    bCLine();
    ~bCLine();

  public:
    bCLine &operator=(bCLine const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);
    bCLine operator*(bCMatrix3 const &) const;
    bCLine operator*(bCMatrix const &) const;
    bCLine operator-(bCVector const &) const;
    bCLine operator+(bCVector const &) const;
    bCLine operator/(bCMatrix3 const &) const;
    bCLine operator/(bCMatrix const &) const;
    bCLine &operator+=(bCVector const &);
    bCLine &operator-=(bCVector const &);

  public:
    bCVector &AccessDirection();
    bCVector &AccessOrigin();
    void Clear();
    void CopyFrom(bCLine const &);
    void CopyTo(bCLine &) const;
    bCVector const &GetDirection() const;
    void GetDirection(bCVector &) const;
    GEFloat GetIntersectionDistance(bCBox const &) const;
    GEFloat GetIntersectionDistance(bCPlane const &) const;
    GEFloat GetIntersectionDistance(bCSphere const &) const;
    GEFloat GetIntersectionDistance(bCTriangle const &) const;
    bCLine GetInvTransformed(bCMatrix3 const &) const;
    bCLine GetInvTransformed(bCMatrix const &) const;
    void GetInvTransformed(bCLine &, bCMatrix3 const &) const;
    void GetInvTransformed(bCLine &, bCMatrix3) const;
    bCLine GetInvTranslated(bCVector const &) const;
    void GetInvTranslated(bCLine &, bCVector const &) const;
    bCVector const &GetOrigin() const;
    void GetOrigin(bCVector &) const;
    bCLine GetTransformed(bCMatrix3 const &) const;
    bCLine GetTransformed(bCMatrix const &) const;
    void GetTransformed(bCLine &, bCMatrix3 const &) const;
    void GetTransformed(bCLine &, bCMatrix3) const;
    bCLine GetTranslated(bCVector const &) const;
    void GetTranslated(bCLine &, bCVector const &) const;
    GEBool Intersects(bCBox const &, GEFloat &) const;
    GEBool Intersects(bCFrustum const &, GEFloat &) const;
    GEBool Intersects(bCPlane const &, GEFloat &) const;
    GEBool Intersects(bCSphere const &, GEFloat &) const;
    GEBool Intersects(bCTriangle const &, GEFloat &) const;
    GEBool Intersects(bCTriangle const &, bCTriangle::bESides, GEFloat &) const;
    GEBool Intersects(bCVector const *const, GEFloat &) const;
    GEBool Intersects(bCVector const *const, bCTriangle::bESides, GEFloat &) const;
    void InvTransform(bCMatrix3 const &);
    void InvTransform(bCMatrix const &);
    void InvTranslate(bCVector const &);
    void SetDirection(bCVector const &);
    void SetLine(bCLine const &);
    void SetLine(bCVector const &, bCVector const &);
    void SetOrigin(bCVector const &);
    void Transform(bCMatrix3 const &);
    void Transform(bCMatrix const &);
    void Translate(bCVector const &);

  protected:
    static GEFloat m_fDummy;
};
