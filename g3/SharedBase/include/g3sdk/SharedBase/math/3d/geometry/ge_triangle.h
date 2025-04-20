#pragma once

#include <SharedBase/math/3d/ge_matrix3.h>
#include <SharedBase/math/3d/ge_vector.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCBox;
class bCFrustum;
class bCIStream;
class bCLine;
class bCMatrix;
class bCOStream;
class bCPlane;
class bCRay;
class bCSphere;
class bCStretch;
class bCUnitedRay;

class GE_DLLIMPORT bCTriangle
{
  public:
    enum bESides
    {
        // TODO: Enumerator values
    };

  public:
    bCTriangle(bCTriangle const &);
    bCTriangle(bCVector const &, bCVector const &, bCVector const &);
    explicit bCTriangle(bCVector *const);
    bCTriangle();
    ~bCTriangle();

  public:
    bCTriangle &operator=(bCTriangle const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);
    bCVector &operator[](GEInt);
    bCVector const &operator[](GEInt) const;
    bCTriangle operator*(bCMatrix3 const &) const;
    bCTriangle operator*(bCMatrix const &) const;
    bCTriangle operator/(bCMatrix3 const &) const;
    bCTriangle operator/(bCMatrix const &) const;

  public:
    bCVector &AccessA();
    bCVector &AccessB();
    bCVector &AccessC();
    bCVector &AccessVector(GEInt);
    bCVector (&AccessVectors())[3];
    bCVector CalcNormal() const;
    void CalcNormal(bCVector &) const;
    void Clear();
    void CopyFrom(bCTriangle const &);
    void CopyTo(bCTriangle &) const;
    GEBool Cull(bCTriangle const &) const;
    GEBool Cull(bCBox const &) const;
    GEBool Cull(bCFrustum const &) const;
    GEBool Cull(bCLine const &) const;
    GEBool Cull(bCPlane const &) const;
    GEBool Cull(bCRay const &) const;
    GEBool Cull(bCSphere const &) const;
    GEBool Cull(bCStretch const &) const;
    GEBool Cull(bCUnitedRay const &) const;
    GEBool Cull(bCVector const *const) const;
    bCVector const &GetA() const;
    void GetA(bCVector &) const;
    bCVector const &GetB() const;
    void GetB(bCVector &) const;
    bCVector const &GetC() const;
    void GetC(bCVector &) const;
    void GetCenter(bCVector &);
    GEFloat GetIntersectionDistance(bCLine const &) const;
    GEFloat GetIntersectionDistance(bCRay const &) const;
    GEFloat GetIntersectionDistance(bCStretch const &) const;
    bCTriangle GetInvTransformed(bCMatrix3 const &) const;
    bCTriangle GetInvTransformed(bCMatrix const &) const;
    void GetInvTransformed(bCTriangle &, bCMatrix3 const &) const;
    void GetInvTransformed(bCTriangle &, bCMatrix3) const;
    bCTriangle GetInvTranslated(bCVector const &) const;
    void GetInvTranslated(bCTriangle &, bCVector const &) const;
    bCTriangle GetTransformed(bCMatrix3 const &) const;
    bCTriangle GetTransformed(bCMatrix const &) const;
    void GetTransformed(bCTriangle &, bCMatrix3 const &) const;
    void GetTransformed(bCTriangle &, bCMatrix3) const;
    bCTriangle GetTranslated(bCVector const &) const;
    void GetTranslated(bCTriangle &, bCVector const &) const;
    bCVector const &GetVector(GEInt) const;
    bCVector const (&GetVectors() const)[3];
    GEBool Intersects(bCTriangle const &) const;
    GEBool Intersects(bCBox const &) const;
    GEBool Intersects(bCFrustum const &) const;
    GEBool Intersects(bCLine const &, GEFloat &) const;
    GEBool Intersects(bCLine const &, bESides, GEFloat &) const;
    GEBool Intersects(bCPlane const &) const;
    GEBool Intersects(bCRay const &, GEFloat &) const;
    GEBool Intersects(bCRay const &, bESides, GEFloat &) const;
    GEBool Intersects(bCSphere const &) const;
    GEBool Intersects(bCStretch const &, GEFloat &) const;
    GEBool Intersects(bCStretch const &, bESides, GEFloat &) const;
    GEBool Intersects(bCUnitedRay const &, GEFloat &) const;
    GEBool Intersects(bCUnitedRay const &, bESides, GEFloat &) const;
    GEBool Intersects(bCVector const *const) const;
    void InvTransform(bCMatrix3 const &);
    void InvTransform(bCMatrix const &);
    void InvTranslate(bCVector const &);
    GEBool IsDegenerated() const;
    GEBool Separates(bCVector const *, GEInt, bCVector const &) const;
    void SetA(bCVector const &);
    void SetB(bCVector const &);
    void SetC(bCVector const &);
    void SetTriangle(bCTriangle const &);
    void SetTriangle(bCVector const &, bCVector const &, bCVector const &);
    void SetTriangle(bCVector *const);
    void Transform(bCMatrix3 const &);
    void Transform(bCMatrix const &);
    void Translate(bCVector const &);

  protected:
    static GEFloat m_fDummy;
};
