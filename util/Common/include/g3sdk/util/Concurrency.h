#pragma once

#include <g3sdk/SharedBase.h>

class mCLockGuard
{
  public:
    mCLockGuard(bCCriticalSectionWin32 &a_pCriticalSection);
    ~mCLockGuard();
    void Release();

    mCLockGuard &operator=(mCLockGuard &) = delete;
    mCLockGuard(mCLockGuard &) = delete;

  private:
    bCCriticalSectionWin32 *m_pCriticalSection;
};

template <typename T>
class mTPtrRingBuffer
{
  public:
    mTPtrRingBuffer(GEInt a_iInitialCapacity = 16)
    {
        Reset(a_iInitialCapacity);
    };

    void Push(T a_Element)
    {
        // First push the element (important in case of resizing)
        m_arrBuffer[m_iWriter] = a_Element;

        GEInt iWriterNext = Increment(m_iWriter);
        if (iWriterNext == m_iReader)
        {
            GEInt iReaderMoved = m_iReader + m_arrBuffer.GetCount();
            // Buffer is almost full, resize
            m_arrBuffer.SetCount(m_arrBuffer.GetCount() * 2);
            // Move tail elements and reader
            memcpy(&m_arrBuffer[iReaderMoved], &m_arrBuffer[m_iReader],
                   (m_arrBuffer.GetCount() - iReaderMoved) * sizeof(T));
            m_iReader = iReaderMoved;
        }
        m_iWriter = iWriterNext;
    }

    T Pop()
    {
        GEInt iElement = m_iReader;
        m_iReader = Increment(m_iReader);
        return m_arrBuffer[iElement];
    }

    GEBool IsEmpty()
    {
        return m_iReader == m_iWriter;
    }

    GEUInt Size()
    {
        if (m_iReader <= m_iWriter)
            return m_iWriter - m_iReader;
        else
            return m_arrBuffer.GetCount() - (m_iReader - m_iWriter);
    }

    void Reset(GEInt a_iInitialCapacity = 16)
    {
        m_iReader = 0;
        m_iWriter = 0;
        m_arrBuffer.SetCount(a_iInitialCapacity);
    }

  private:
    inline GEInt Increment(GEInt a_iCounter)
    {
        return (a_iCounter + 1) % m_arrBuffer.GetCount();
    }

  private:
    bTPtrArray<T> m_arrBuffer;
    // Points to next unread element
    GEInt m_iReader;
    // Points to next free element
    GEInt m_iWriter;
};

class mCThreadPool
{
  public:
    class mCThreadPoolWorkerItem
    {
      public:
        virtual ~mCThreadPoolWorkerItem() = 0;
        virtual void DoWork() = 0;
    };

  public:
    static GEU32 GE_STDCALL ThreadFunc(GELPVoid a_pArg);
    static void GetNumberOfCores(GEU32 &o_NumberOfPhysicalCores, GEU32 &o_NumberOfLogicalCores);
    static GEU32 GetDefaultNumberOfThreads(GEU32 a_MaximumNumberOfThreads = 16);

  public:
    ~mCThreadPool();
    // Creates a thread pool with Max(NumberOfProcessors - 1, 1) threads.
    void Create();
    void Create(GEU32 a_NumberOfThreads);
    void Destroy(GEBool a_bAbortWork = GEFalse);
    void InsertWorkItem(mCThreadPoolWorkerItem *a_pWorkItem);
    mCThreadPoolWorkerItem *RemoveWorkItem();
    GEUInt NumWorkItems();
    // Can only be used if the work queue is empty.
    GEBool ResetWorkQueueSize();
    void SetPriority(bCThreadWin32::bEThreadPriority a_Priority);

  private:
    bTPtrArray<bCThreadWin32 *> m_arrThreads;
    bCThreadWin32::bEThreadPriority m_Priority = bCThreadWin32::bEThreadPriority_NORMAL;
    HANDLE m_hAbortEvent = nullptr;
    HANDLE m_hSemaphoreWorkItem = nullptr;
    mTPtrRingBuffer<mCThreadPoolWorkerItem *> m_arrWorkQueue;
    bCCriticalSectionWin32 m_WorkQueueMutex;
};
