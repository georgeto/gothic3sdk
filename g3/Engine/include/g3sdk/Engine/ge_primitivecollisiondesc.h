#pragma once

#include <Engine/ge_geometrycollisiondesc.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCPrimitiveCollisionDesc : public eCGeometryCollisionDesc
{
    // clang-format off
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCPrimitiveCollisionDesc() override;
    public: eCCollisionDesc::eECollisionDescType GetCollisionDescType() override;
    public: GEU32 GetIntersectionCount() const override;
    public: bCVector GetWorldIntersectionPoint(bCUnitedRay const &, GEInt) const override;
    public: void GetWorldIntersectionPoint(bCUnitedRay const &, bCVector &, GEInt) const override;
    public: GEFloat GetIntersectionDistance(GEInt) const override;
    public: eCResourceShaderMaterial_PS * GetIntersectionMaterial(GEInt) const override;
    // clang-format on

  public:
    eCPrimitiveCollisionDesc(eCPrimitiveCollisionDesc const &);
    eCPrimitiveCollisionDesc();

  public:
    bTValArray<GEFloat> &GetIntersectionDistances();
    bTValArray<GEFloat> const &GetIntersectionDistances() const;
    void SetIntersectionDistances(bTValArray<GEFloat> &);
    void SetIntersectionMaterial(eCResourceShaderMaterial_PS *);

  protected:
    eCPrimitiveCollisionDesc const &operator=(eCPrimitiveCollisionDesc const &);

  protected:
    void Invalidate();
};
