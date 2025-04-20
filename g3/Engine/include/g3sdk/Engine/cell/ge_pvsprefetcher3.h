#pragma once

#include <SharedBase.h>

class eCEntity;
class eCFrustumDatabase;
class eCGeometrySpatialContext;
class eCPVSCellItem;

class GE_DLLIMPORT eCPVSPrefetcher3 : public bCObjectRefBase
{
    // clang-format off
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCPVSPrefetcher3() override;
    // clang-format on

  public:
    using gFContextCacheOutCallback = GEBool(GE_STDCALL *)();

  public:
    GE_PROPERTY_SET(eCPVSPrefetcher3, bCObjectRefBase)

  public:
    GEBool AddNewEntity(eCEntity *);
    GEBool CacheIn(eCEntity *);
    void CacheOut();
    GEBool CacheOut(eCEntity *);
    void ClearCells(eCFrustumDatabase &);
    void EnablePrefetcher(GEBool);
    void ForcePrefetch();
    bCPoint GetAllCellIndices(eCFrustumDatabase &) const;
    void GetAllValidCells(bTSmallArray<eCPVSCellItem *> &);
    GEU32 GetCachedInStaticContexts();
    GEU32 GetCachedInStaticContextsFileMem();
    gFContextCacheOutCallback const GetContextCacheOutCallback(eCGeometrySpatialContext *);
    GEU32 GetDeltaFrameTime() const;
    eCPVSCellItem *GetNonDeactivationCell();
    void GetValidCells(eCFrustumDatabase &, bTSmallArray<eCPVSCellItem *> &);
    GEI32 GetWorldMaximumRadius() const;
    GEBool IsJobRunning() const;
    GEBool Process(eCFrustumDatabase &);
    GEBool Recalibrate(bCVector const &, eCEntity *);
    GEBool RemoveNewAddedEntity(eCEntity *);
    void SetContextCacheOutCallback(GEBool(GE_STDCALL *)(eCGeometrySpatialContext *));
    void WaitForEmptyThreadQueue();

  protected:
    void CalculateRectIndices(eCFrustumDatabase &, bCSphere const &, bCRect &);
    void Execute(eCFrustumDatabase &, bCSphere const &);
    void Invalidate();
    GEBool RecalculateGrid(eCFrustumDatabase &, bCSphere const &, bTSmallArray<eCPVSCellItem *> &);

  private:
    GE_UNIMPL_MEMBERS(0x44)
};

GE_ASSERT_SIZEOF(eCPVSPrefetcher3, 0x50)
