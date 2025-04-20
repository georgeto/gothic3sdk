#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/entity/proxy/ge_templateentityproxy.h>

#include <SharedBase.h>

class eCMeshCollisionDesc;
class eCResourceDataEntity;
class eCVertexStructArrayBase;
class eCVertexbufferPoolItem;
struct eSRayIntersectionDesc;

struct eSLightmapUVGroup
{
    GE_UNIMPL_STRUCT(eSLightmapUVGroup)
};

class eCSpatialHierarchy
{
    GE_UNIMPL_STRUCT(eCSpatialHierarchy)
};

struct eSLightmapGroup
{
    GE_UNIMPL_STRUCT(eSLightmapGroup)
};

class GE_DLLIMPORT eCMeshElement : public bCObjectRefBase
{
  public:
    enum eEProjectionPlane
    {
        // TODO: Enumerator values
    };

    // clang-format off
    public: virtual void CalcBoundary();
    public: virtual GEBool IntersectsRay(eSRayIntersectionDesc &, bCMatrix const &, eCMeshCollisionDesc **, GEInt) const;
    public: virtual GEBool IntersectsVolume(bCVolume &, bCMatrix const &, bTValArray<bCTriangle> *, GEBool) const;
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCMeshElement() override;
    // clang-format on

  public:
    eCMeshElement(eCMeshElement const &);
    eCMeshElement();

  public:
    eCMeshElement &operator=(eCMeshElement const &);

  public:
    GEBool BuildSpatialHierarchy(GEBool);
    void CalculateSize();
    GEBool CreateLightmapUVGroups(GEBool);
    eCVertexStructArrayBase *CreateStreamArray(eEVertexStreamArrayType);
    GEBool DeleteStreamArray(eEVertexStreamArrayType);
    GEBool DestroyLightmapUVGroups();
    bCBox const &GetBoundingBox() const;
    void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &);
    GEU32 GetFVF() const;
    eSLightmapGroup const &GetLightmapPerVertexGroup() const;
    bTObjArray<eSLightmapUVGroup> &GetLightmapUVGroups();
    bTObjArray<eSLightmapUVGroup> const &GetLightmapUVGroups() const;
    bCString const &GetMaterialFileName() const;
    bCString const &GetMaterialName() const;
    eCResourceDataEntity *GetResourceDataEntity();
    GEU32 GetSize() const;
    GEBool GetSmoothNormal(bCVector &, GEU32, bCVector const &);
    eCSpatialHierarchy const &GetSpatialHierarchy() const;
    eCVertexStructArrayBase *GetStreamArray(GEU32);
    eCVertexStructArrayBase *GetStreamArray(eEVertexStreamArrayType);
    eCVertexStructArrayBase const *GetStreamArray(GEU32) const;
    eCVertexStructArrayBase const *GetStreamArray(eEVertexStreamArrayType) const;
    GEU32 GetTriangleCount() const;
    GEBool GetTriangleIndices(GEU32, GEU32 *const) const;
    GEBool GetTriangles(bTValArray<bCTriangle> &) const;
    eCVertexbufferPoolItem *GetVertexbufferPoolItem() const;
    GEBool HasStreamArray(eEVertexStreamArrayType) const;
    GEBool SetMaterialFile(bCString const &);
    void SetResourceDataEntity(eCResourceDataEntity *);
    GEBool SetStreamArray(eCVertexStructArrayBase const &);
    void SetVertexbufferPoolItem(eCVertexbufferPoolItem *);
    void UnloadResources();

  protected:
    static GEInt GE_CCALL SortLightmapUVGroups(GELPCVoid, GELPCVoid);

  protected:
    GEInt DublicateVertexAddLast(GEInt);
    eEProjectionPlane FindProjectionPlane(bCTriangle const &) const;
    GEBool GetVertexTriangleMap(bTObjArray<bTValArray<GEU32>> &);
    void GroupTriangleNeighbors(GEU32, bTValArray<GEU32> &, bTValArray<GEU32> const &,
                                bTObjArray<bTValArray<GEU32>> const &, bTValArray<eEProjectionPlane> const &);
    void Invalidate();
};
