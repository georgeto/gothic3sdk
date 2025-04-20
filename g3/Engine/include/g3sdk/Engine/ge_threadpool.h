#pragma once

#include <SharedBase.h>

class eCResourceBase_PS;

class GE_DLLIMPORT eCThreadPool : public bCObjectBase
{
  public:
    class eCThreadPoolWorkerItem
    {
        // clang-format off
            protected: virtual void DoWork() = 0;
            protected: virtual void Abort() = 0;
            public: virtual eCResourceBase_PS * AccessResource() = 0;
            public: virtual eCResourceBase_PS const * GetResource() const = 0;
            public: virtual ~eCThreadPoolWorkerItem();
        // clang-format on

      public:
        eCThreadPoolWorkerItem(eCThreadPoolWorkerItem const &);
        eCThreadPoolWorkerItem();

      public:
        eCThreadPoolWorkerItem &operator=(eCThreadPoolWorkerItem const &);

      public:
        GEBool IsProcessing();
        void Work();
    };

    struct eSThreadQueueArray
    {
        int field_0;
        signed int field_4;
        signed int field_8;
        signed int field_C;
        bool field_10;
    };
    GE_ASSERT_SIZEOF(eSThreadQueueArray, 0x14)

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCThreadPool() override;
    // clang-format on

  public:
    static void GE_STDCALL EnableAllThreads(GEBool);
    static GEU32 GE_STDCALL GetGlobalNumberOfJobsInQueue();
    static GEU32 GE_STDCALL GetGlobalNumberOfThreadsWorking();
    static GEBool GE_STDCALL IsThreadingEnabled();
    static GEU32 GE_STDCALL g_ThreadFunc(GELPVoid);

  public:
    eCThreadPool(eCThreadPool const &);
    eCThreadPool();

  public:
    void CopyFrom(eCThreadPool const &);
    GEBool Create(GEU32);
    GEU32 GetNumOfJobsInQueueObject() const;
    GEU32 GetNumberOfThreadsWorking() const;
    GEBool InsertWorkItem(eCThreadPoolWorkerItem *);
    eCThreadPoolWorkerItem *RemoveWorkItem();
    void SetPriority(bCThreadWin32::bEThreadPriority);
    GEBool WaitForEmptyThreadQueue();
    GEBool WaitForIdleThreads();

  protected:
    static GEBool ms_bEnableThreads;
    static GEU32 ms_u32NumOfJobsInQueue;
    static GEU32 ms_u32NumOfThreadsProcessing;

  protected:
    eCThreadPool const &operator=(eCThreadPool const &);

  protected:
    void Invalidate();

  private:
    eSThreadQueueArray *m_arrWorkQueue;
    bTPtrArray<bCThreadWin32 *> m_arrThreads;
    HANDLE m_hAbortEvent;
    HANDLE m_hSemaphore;
    bCCriticalSectionWin32 m_WorkItemList_CriticalSection;
    GEInt m_iPriority;
    unsigned int m_uNumOfJobsInQueueObject;
    unsigned int m_uNumberOfThreadsWorking;
};
GE_ASSERT_SIZEOF(eCThreadPool, 0x40)
