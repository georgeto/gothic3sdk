#pragma once

#include <SharedBase.h>

class eCEntity;
class eCFrustumDatabase;
class eCGeometrySpatialContext;
class eCPVSCellItem;
class eCPVSPrefetcher3;
struct eSCellMapKey;

class eCPVSPrefetcherJob;

class eCPrefetcherJobThread
{
    void *vtable;
    bCThreadWin32 m_Thread;
    _RTL_CRITICAL_SECTION m_CriticalSection;
    bool m_bRunning;
    eCPVSPrefetcherJob *m_pJob;
    bool m_bInterrupted;
    bool m_bDone;
};

enum eEPVSPrefetcherJobState
{
    eEPVSPrefetcherJobState_CacheInDynamicEntities = 0x0,
    eEPVSPrefetcherJobState_CacheInHybridEntities = 0x1,
    eEPVSPrefetcherJobState_CacheInStaticContexts1 = 0x2,
    eEPVSPrefetcherJobState_CacheInStaticContexts2 = 0x3,
    eEPVSPrefetcherJobState_CacheInStaticEntities1 = 0x4,
    eEPVSPrefetcherJobState_CacheInStaticEntities2 = 0x5,
    eEPVSPrefetcherJobState_6 = 0x6,
    eEPVSPrefetcherJobState_Done = 0x7,
};

class GE_DLLIMPORT eCPVSPrefetcherJob
{
  public:
    enum eECurrentStagePrefetcher
    {
        // TODO: Enumerator values
    };

  public:
    explicit eCPVSPrefetcherJob(eCFrustumDatabase *);
    ~eCPVSPrefetcherJob();

  public:
    eCPVSPrefetcherJob const &operator=(eCPVSPrefetcherJob const &);

  public:
    void ClearJob();
    bEResult Create(eCPVSPrefetcher3 *, bTSmallArray<eCEntity *> *, bTSmallArray<eCEntity *> *,
                    bTSmallArray<eCGeometrySpatialContext *> *);
    void Destroy();
    void DisableTimeSlice();
    eCPVSCellItem *GetCell(eSCellMapKey const &) const;
    eECurrentStagePrefetcher GetCurrentStage() const;
    GEBool IsEmpty() const;
    GEBool IsFinished() const;
    void Process();
    GEBool RemoveDynamicEntityFromList(eCEntity *);
    void ScanEntities(eCEntity &, bTSmallArray<eCEntity *> &);

  protected:
    static GEU32 ms_u32TimeSliceMSecOperate;

  protected:
    eCPVSPrefetcherJob(eCPVSPrefetcherJob const &);

  protected:
    void CacheInDynamicEntities();
    void CacheInHybridEntities();
    void CacheInStaticContexts();
    void CacheInStaticEntities();
    void Invalidate();
    void ProcessForce();

  public:
    bTSmallArray<eCEntity *> m_arrScannedDynamicEntities;
    bTSmallArray<eCEntity *> m_arrScannedHybridEntities;
    bTSmallArray<eCEntity *> m_arrScannedStaticEntities;
    bTSmallArray<eCGeometrySpatialContext *> m_arrScannedGeometrySpatialContexts;
    eCFrustumDatabase *m_pFrustumDatabase;
    eCPVSPrefetcher3 *m_pPrefetcher;
    GEU32 m_uTotalItemCount;
    GEU32 m_iTotalCachedInCount;
    eCPrefetcherJobThread *m_pThread;
    eEPVSPrefetcherJobState JobState;
    GEBool m_bForce_Or_Loading;
    GE_PADDING(0x1)
    GEU16 m_iSpatialContextsCacheInCount;
    GEU16 m_iStaticEntitiesCachedInCount;
    GEU16 m_iHybridEntitiesCachedInCount;
    GEU16 m_iDynamicEntitiesCachedInCount;
    GEBool m_bUseThreadForStaticEntities;
};

GE_ASSERT_SIZEOF(eCPVSPrefetcherJob, 0x44)
