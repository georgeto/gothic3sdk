#pragma once

#include <Engine/ge_collisiondesc.h>

#include <SharedBase.h>

class eCResourceShaderMaterial_PS;

class GE_DLLIMPORT eCGeometryCollisionDesc : public eCCollisionDesc
{
    // clang-format off
    public: virtual GEU32 GetIntersectionCount() const = 0;
    public: virtual bCVector GetWorldIntersectionPoint(bCUnitedRay const &, GEInt) const = 0;
    public: virtual void GetWorldIntersectionPoint(bCUnitedRay const &, bCVector &, GEInt) const = 0;
    public: virtual GEFloat GetIntersectionDistance(GEInt) const = 0;
    public: virtual eCResourceShaderMaterial_PS * GetIntersectionMaterial(GEInt) const = 0;
    protected: ~eCGeometryCollisionDesc() override;
    // clang-format on

  public:
    eCGeometryCollisionDesc(eCGeometryCollisionDesc const &);
    eCGeometryCollisionDesc();

  public:
    eCGeometryCollisionDesc &operator=(eCGeometryCollisionDesc const &);
};
