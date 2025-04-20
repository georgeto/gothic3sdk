#pragma once

#include <SharedBase.h>

struct eSVegetationMeshID
{
    GE_UNIMPL_STRUCT(eSVegetationMeshID)
};

struct eSVegetationNodeEntry
{
    GE_UNIMPL_STRUCT(eSVegetationNodeEntry)
};

class GE_DLLIMPORT eCVegetation_GridNode : public bCObjectRefBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCVegetation_GridNode() override;
    // clang-format on

  public:
    eCVegetation_GridNode(eCVegetation_GridNode const &);
    eCVegetation_GridNode();

  public:
    void CacheIn(GEU32);
    void CacheOut();
    bCBox const &GetBoundingBox() const;
    GEU32 GetCacheTimeStamp() const;
    eSVegetationNodeEntry const &GetEntry(GEInt) const;
    GEInt GetEntryCount() const;
    GEBool IsCachedIn() const;
    void UpdateBounds();

  protected:
    static eCVegetation_GridNode *ms_CurrentSortingGridNode;

  protected:
    static GEInt GE_CCALL SortCompareEntry(GELPCVoid, GELPCVoid);

  protected:
    eCVegetation_GridNode const &operator=(eCVegetation_GridNode const &);

  protected:
    GEInt AddEntry(eSVegetationNodeEntry const &);
    void CacheInGeometry();
    void CacheOutGeometry();
    eSVegetationNodeEntry &GetEntry(GEInt);
    GEBool IntersectsMinSpacing(eSVegetationNodeEntry const &, GEBool, bTValArray<GEInt> *);
    void Invalidate();
    GEBool ReCache();
    void RemapMeshID(eSVegetationMeshID, eSVegetationMeshID);
    void RemoveEntries(bCVector2 const &, GEFloat, bTObjArray<eSVegetationMeshID> const *);
    void RemoveEntries(eSVegetationMeshID);
    void RemoveEntry(bCVector const &);
    void RemoveEntryAt(GEInt);
    void Render();
    void SortEntries();
    void UpdateBounds(eSVegetationNodeEntry const &);
};
