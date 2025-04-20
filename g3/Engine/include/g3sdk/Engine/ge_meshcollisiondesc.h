#pragma once

#include <Engine/ge_polygeometrycollisiondesc.h>

#include <SharedBase.h>

class eCMeshElement;
class eCResourceMeshComplex_PS;
class eCResourceMesh_PS;

class GE_DLLIMPORT eCMeshCollisionDesc : public eCPolyGeometryCollisionDesc
{
  public:
    struct eSMeshCollisionTriangle
    {
        GE_UNIMPL_STRUCT(eSMeshCollisionTriangle)
    };

    // clang-format off
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCMeshCollisionDesc() override;
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
    eCMeshCollisionDesc(eCMeshCollisionDesc const &);
    eCMeshCollisionDesc();

  public:
    eCResourceMeshComplex_PS const *GetComplexMesh() const;
    bCMatrix const &GetLocalToWorldMatrix() const;
    eCMeshElement const *GetMeshElement(GEInt) const;
    bTValArray<eSMeshCollisionTriangle> const &GetPolygonIndices() const;
    eCResourceMesh_PS const *GetResourceMeshPS() const;
    void SetComplexMesh(eCResourceMeshComplex_PS *);
    void SetLocalToWorldMatrix(bCMatrix const &);
    void TransformLocalRayToWorldRay(bCUnitedRay &);
    void TransformWorldRayToLocalRay(bCUnitedRay &);

  protected:
    eCMeshCollisionDesc const &operator=(eCMeshCollisionDesc const &);

  protected:
    void Invalidate();
};
