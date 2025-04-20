#pragma once

#include <SharedBase.h>

class eCDynamicEntity;
class eCEntity;
class eCPVSPrefetcher3;
class eCSpatialEntity;

template <typename K, typename V>
class bTSkipTree
{
    GE_UNIMPL_STRUCT(bTSkipTree)
};

struct eSCellMapKey
{
    GE_UNIMPL_STRUCT(eSCellMapKey)
};

class GE_DLLIMPORT eCPVSCellItem
{
  public:
    struct eSSkipTreeNode
    {
        GE_UNIMPL_STRUCT(eSSkipTreeNode)
    };

    struct eSStaticHierachyEntity
    {
        GE_UNIMPL_STRUCT(eSStaticHierachyEntity)
    };

    // clang-format off
    public: virtual GEU16 GetVersion() const;
    public: virtual void Destroy();
    public: virtual bEResult Create();
    protected: virtual bEResult CopyFrom(eCPVSCellItem const &);
    public: virtual ~eCPVSCellItem();
    // clang-format on

  public:
    static void GE_STDCALL GetCellIndex(bCPoint &, bCVector const &, GEU32);
    static void GE_STDCALL GetCellIndex(bCPoint &, eCEntity const &, GEU32);
    static bCCriticalSectionWin32 &GE_STDCALL GetCriticalSection();
    static bCPoint GE_STDCALL GetEntity2DCoord(bCVector const &);
    static GEI32 GE_STDCALL GetWorldMapRadius();

  public:
    eCPVSCellItem(eCPVSCellItem const &);
    eCPVSCellItem();

  public:
    eCPVSCellItem const &operator=(eCPVSCellItem const &);

  public:
    void CacheInEntity(eCEntity *, GEU32);
    void CacheOut(GEU32);
    void CacheOutEntity(eCEntity *, GEU32);
    void DisableDatabaseSlot(GEU32);
    void EnableDatabaseSlot(GEU32);
    GEBool ExistsEntity(eCEntity *) const;
    bCBox const &GetCellBox() const;
    eSCellMapKey const &GetCellMapKey() const;
    eCPVSPrefetcher3 *GetCurrentPVSPrefetcher() const;
    bTSmallArray<eCDynamicEntity *> const &GetDynamicEntities() const;
    GEU32 GetDynamicSyncCount() const;
    bCPoint GetEntity2DCoord(eCEntity *);
    bTSmallArray<eCSpatialEntity *> const &GetStaticEntities() const;
    bTSkipTree<bCBox, eSSkipTreeNode> const &GetStaticHierachy() const;
    GEU32 GetStaticSyncCount() const;
    GEBool IsCorrectCell(bCPoint const &) const;
    GEBool IsCorrectCell(bCVector const &) const;
    GEBool IsCorrectCell(eCEntity const *) const;
    GEBool IsInCellIndex(bCRect const &) const;
    GEBool IsRemovedFromAllDatabases() const;
    void RenderOccludees(GEU16, GEU16);
    void SetCellCoords(GEInt, GEInt, GEU32);
    void SetCurrentPVSPrefetcher(eCPVSPrefetcher3 *);

  protected:
    static GEInt ms_iKDTreeSortAxis;

  protected:
    static GEInt GE_CCALL SortKDTree(GELPCVoid, GELPCVoid);

  protected:
    void BuildStaticHierachy(GEU32, eSStaticHierachyEntity *, GEU32, GEU32);
    void BuildStaticHierachy();
    GEBool DisableDatabaseSet(eCEntity *, GEU32);
    GEBool EnableDatabaseSet(eCEntity *, GEU32);
    void Invalidate();
};
