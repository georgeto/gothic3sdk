#pragma once

#include <Engine/ge_vegetation_gridnode.h>

#include <SharedBase.h>

class eCCameraBase;
class eCVegetation_PS;

class GE_DLLIMPORT eCVegetation_Grid : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult Create(eCVegetation_PS *, GEFloat);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCVegetation_Grid() override;
    // clang-format on

  public:
    eCVegetation_Grid(eCVegetation_Grid const &);
    eCVegetation_Grid();

  public:
    void CellIndexToGrid(GEInt, bCPoint &) const;
    void ClearGeometryCache();
    bCVector2 const &GetAlphaDisolve() const;
    bCBox const &GetBoundingBox() const;
    GEInt GetCellCount() const;
    GEInt GetGridHeight() const;
    GEInt GetGridWidth() const;
    eCVegetation_GridNode *GetNodeAt(bCPoint const &) const;
    eCVegetation_GridNode *GetNodeAt(bCVector2 const &) const;
    eCVegetation_GridNode *GetNodeAt(GEInt) const;
    GEFloat GetNodeDimension() const;
    void GetWorldDimension(bCVector2 &) const;
    void GetWorldOffset(bCVector2 &) const;
    void GetWorldRect(bCVector2 &, bCVector2 &) const;
    GEInt GridToCellIndex(bCPoint const &) const;
    void GridToWorldSpace(bCPoint const &, bCVector2 &) const;
    void GridToWorldSpace(bCPoint const &, bCVector2 const &, bCVector2 &) const;
    void InsertEntry(eSVegetationNodeEntry const &);
    GEBool InsertEntryCheckSpacing(eSVegetationNodeEntry const &, GEBool, GEBool);
    GEBool IntersectsMinSpacing(bCPoint const &, eSVegetationNodeEntry const &, GEBool, bTValArray<GEInt> *);
    GEBool IsEmpty() const;
    void RemapMeshID(eSVegetationMeshID, eSVegetationMeshID);
    void RemoveEntries(bCVector2 const &, GEFloat, bTObjArray<eSVegetationMeshID> const *);
    void RemoveEntries(eSVegetationMeshID);
    void RemoveEntry(bCVector const &);
    void Render(eCCameraBase const &);
    void ResizeGrid(bCRect const &, GEBool);
    void SetAlphaDisolve(GEFloat, GEFloat);
    void SetCacheRange(GEFloat);
    void SetNodeDimension(GEFloat);
    void UpdateBounds(GEBool);
    void WorldToGridSpace(bCVector2 const &, bCPoint &) const;
    void WorldToGridSpace(bCVector2 const &, bCPoint &, bCVector2 &) const;

  protected:
    eCVegetation_Grid const &operator=(eCVegetation_Grid const &);

  protected:
    void CacheIn(bCRect const &);
    void CalculateCacheRect(eCCameraBase const &, bCRect &);
    eCVegetation_GridNode *GetOrCreateNodeAt(bCPoint const &);
    eCVegetation_GridNode *GetOrCreateNodeAt(bCVector2 const &);
    eCVegetation_GridNode *GetOrCreateNodeAt(GEInt);
    void Invalidate();
};
