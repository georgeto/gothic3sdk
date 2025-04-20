#pragma once

#include <Engine/ge_polygeometrycollisiondesc.h>

#include <SharedBase.h>

class eCResourceDataEntity;
class eCResourceSpeedTree_PS;

class GE_DLLIMPORT eCSpeedTreeCollisionDesc : public eCPolyGeometryCollisionDesc
{
    // clang-format off
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCSpeedTreeCollisionDesc() override;
    public: eCCollisionDesc::eECollisionDescType GetCollisionDescType() override;
    public: GEU32 GetIntersectionCount() const override;
    public: bCVector GetWorldIntersectionPoint(bCUnitedRay const &, GEInt) const override;
    public: void GetWorldIntersectionPoint(bCUnitedRay const &, bCVector &, GEInt) const override;
    public: GEFloat GetIntersectionDistance(GEInt) const override;
    public: eCResourceShaderMaterial_PS * GetIntersectionMaterial(GEInt) const override;
    public: bCTriangle GetLocalPolygon(GEInt) const override;
    public: GEBool GetLocalPolygon(bCTriangle &, GEInt) const override;
    public: bCTriangle GetWorldPolygon(GEInt) const override;
    public: GEBool GetWorldPolygon(bCTriangle &, GEInt) const override;
    // clang-format on

  public:
    eCSpeedTreeCollisionDesc(eCSpeedTreeCollisionDesc const &);
    eCSpeedTreeCollisionDesc();

  public:
    bCMatrix const &GetLocalToWorldMatrix() const;
    eCResourceSpeedTree_PS const *GetResourceSpeedTreePS() const;
    void SetLocalToWorldMatrix(bCMatrix const &);
    void SetResourceSpeedTreeEntity(eCResourceDataEntity *);
    void TransformLocalRayToWorldRay(bCUnitedRay &);
    void TransformWorldRayToLocalRay(bCUnitedRay &);

  protected:
    eCSpeedTreeCollisionDesc const &operator=(eCSpeedTreeCollisionDesc const &);

  protected:
    void Invalidate();
};
