#pragma once

#include <Engine/ge_resourcebase_ps.h>
#include <Engine/ge_threadpool.h>

#include <SharedBase.h>

class eCResourceDataEntity;

class GE_DLLIMPORT eCBaseCache : public bCObjectRefBase
{
  public:
    enum eELoDQualityStage
    {
        // TODO: Enumerator values
    };

    enum eEUpdateCacheInfoOperation
    {
        // TODO: Enumerator values
    };

    struct eSResourceEntry
    {
        eSResourceEntry *NextEntry;
        eSResourceEntry *PrevEntry;
        eCResourceDataEntity *DataEntity;
        eCResourceBase_PS *ResourceEntity;
        GEBool Detached;
    };

    struct eSResourceEntryLinkedList
    {
        eSResourceEntry *Head;
        eSResourceEntry *Tail;
        GEUInt EntryCount;
    };

  public:
    class eCThreadPoolWorkerItem_Do : public eCThreadPool::eCThreadPoolWorkerItem
    {
      public:
        enum eEThreadCallType
        {
            // TODO: Enumerator values
        };

        // clang-format off
            protected: void DoWork() override;
            protected: void Abort() override;
            public: eCResourceBase_PS * AccessResource() override;
            public: eCResourceBase_PS const * GetResource() const override;
            public: ~eCThreadPoolWorkerItem_Do() override;
        // clang-format on

      public:
        eCThreadPoolWorkerItem_Do(eCThreadPoolWorkerItem_Do const &);
        eCThreadPoolWorkerItem_Do(eEThreadCallType, eCResourceDataEntity &);

      public:
        eCResourceDataEntity &GetResourceDataEntity();
        eCResourceDataEntity const &GetResourceDataEntity() const;
        eEThreadCallType GetThreadCallType() const;
    };

    // clang-format off
    public: virtual void SetLoDQualityStage(eELoDQualityStage);
    public: virtual void SetMaximumCacheSize(GEU32);
    protected: virtual GEBool CacheInResource(eCResourceDataEntity &);
    protected: virtual GEBool CacheOutResource(eCResourceDataEntity &, eEResourceCacheBehavior);
    protected: virtual GEBool ConvertResource(eCResourceDataEntity &);
    protected: virtual GEBool SaveResource(eCResourceDataEntity &);
    protected: virtual void UpdateResourceInfo(eCResourceDataEntity const &, eEUpdateCacheInfoOperation);
    public: virtual void Process();
    public: GEU16 GetVersion() const override;
    protected: bEResult Write(bCOStream &) override;
    protected: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCBaseCache() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCBaseCache, bCObjectRefBase)

  public:
    GEU32 GetCurrentJobsInQueue() const;
    eELoDQualityStage GetLoDQualityStage() const;
    GEU32 GetNumElementsInLRU() const;
    void SetThreadNumber(GEU32);
    void WaitForEmptyThreadQue();

  protected:
    void CheckThreadQueue(eCResourceDataEntity &);
    GEBool DeleteResourceEntry(eCResourceDataEntity &);
    void Invalidate();
    void UpdateResourceEntry(eCResourceDataEntity &);

  public:
    unsigned int m_uThreadNumber;
    GEU32 m_LoDQualityStage;
    GEU32 CurTimeStamp;
    eSResourceEntryLinkedList m_Entries;
    bTPtrMap<bCPropertyID, eCResourceDataEntity *> m_IdToEntryMapping;
    eCThreadPool m_ThreadPool;
    bCCriticalSectionWin32 m_CriticalSection;
    unsigned int uMaximumCacheSize;
    GEU32 HardUpperSizeLimit;
    GEU32 WarnSizeLimit;
    GEU32 CurrentCacheSize;
    GEU32 field_9C;
    GEU32 WarnSizeLimit_;
    GEU32 CacheSizeUpdateTimeStamp;
};

GE_ASSERT_SIZEOF(eCBaseCache, 0xa8)

GE_DLLIMPORT_EXTC GEU32 const g_u32TimeDiffElapseThreshold;
