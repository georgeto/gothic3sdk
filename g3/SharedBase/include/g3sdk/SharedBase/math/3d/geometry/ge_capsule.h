#pragma once

#include <SharedBase/math/3d/ge_matrix3.h>
#include <SharedBase/math/3d/ge_vector.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCIStream;
class bCOStream;

class GE_DLLIMPORT bCCapsule
{
  public:
    bCCapsule(bCCapsule const &);
    bCCapsule();
    ~bCCapsule();

  public:
    bCCapsule const &operator=(bCCapsule const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);
    GEBool operator==(bCCapsule const &) const;
    GEBool operator!=(bCCapsule const &) const;

  public:
    bEResult Create();
    void Destroy();
    bCVector &GetCenter();
    bCVector const &GetCenter() const;
    GEFloat GetHeight();
    GEFloat const GetHeight() const;
    bCMatrix3 &GetOrientation();
    bCMatrix3 const &GetOrientation() const;
    GEFloat GetRadius();
    GEFloat const GetRadius() const;
    GEBool IsEqual(bCCapsule const &) const;
    void SetCapsule(bCCapsule const &);
    void SetCapsule(GEFloat, GEFloat, bCVector &, bCMatrix3 &);
    void SetCenter(bCVector const &);
    void SetHeight(GEFloat);
    void SetOrientation(bCMatrix3 const &);
    void SetRadius(GEFloat);

  protected:
    void Invalidate();

  private:
    GEFloat m_fHeight;
    GEFloat m_fRadius;
    bCMatrix3 m_matOrientation;
    bCVector m_vecCenter;
};
