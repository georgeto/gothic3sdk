#include "Concurrency.h"

#include <process.h>

mCLockGuard::mCLockGuard(bCCriticalSectionWin32 &a_pCriticalSection) : m_pCriticalSection(&a_pCriticalSection)
{
    m_pCriticalSection->Acquire();
}

mCLockGuard::~mCLockGuard()
{
    Release();
}

void mCLockGuard::Release()
{
    if (m_pCriticalSection)
    {
        m_pCriticalSection->Release();
        m_pCriticalSection = 0;
    }
}

GEU32 GE_STDCALL mCThreadPool::ThreadFunc(GELPVoid a_pArg)
{
    bCThreadWin32::bSThreadContext *pContext = static_cast<bCThreadWin32::bSThreadContext *>(a_pArg);
    mCThreadPool *pThreadPool = static_cast<mCThreadPool *>(pContext->pUserData);

    while (!bCErrorAdmin::GetInstance().IsInPanicState())
    {
        DWORD EventIndex = WaitForMultipleObjects(2, &pThreadPool->m_hAbortEvent, FALSE, INFINITE);

        // Abort event received
        if (EventIndex == 0)
            break;

        // WorkItem ready signal received
        if (EventIndex == 1)
        {
            mCThreadPoolWorkerItem *pWorkItem = pThreadPool->RemoveWorkItem();
            if (pWorkItem && !bCErrorAdmin::GetInstance().IsInPanicState())
            {
                pWorkItem->DoWork();
                GE_DELETE(pWorkItem);
            }
            else
            {
                GE_MESSAGE_WARN_EX(__FUNCTION__, "Returned work item was NULL!");
            }
        }
    }

    _endthreadex(bCErrorAdmin::GetInstance().IsInPanicState());
    return 0;
}

void mCThreadPool::GetNumberOfCores(GEU32 &o_NumberOfPhysicalCores, GEU32 &o_NumberOfLogicalCores)
{
    o_NumberOfPhysicalCores = 0;
    o_NumberOfLogicalCores = 0;

    DWORD Size = 0;
    GetLogicalProcessorInformation(NULL, &Size);
    SYSTEM_LOGICAL_PROCESSOR_INFORMATION *Info =
        new SYSTEM_LOGICAL_PROCESSOR_INFORMATION[Size / sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION)];
    if (GetLogicalProcessorInformation(Info, &Size))
    {
        for (GEUInt i = 0; i < Size / sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION); i++)
        {
            if (Info[i].Relationship == RelationProcessorCore)
            {
                o_NumberOfPhysicalCores++;

                ULONG_PTR LogicalMask = Info[i].ProcessorMask;
                while (LogicalMask)
                {
                    if (LogicalMask & 1)
                        o_NumberOfLogicalCores++;
                    LogicalMask >>= 1;
                }
            }
        }
    }
    delete[] Info;
}

GEU32 mCThreadPool::GetDefaultNumberOfThreads(GEU32 a_MaximumNumberOfThreads)
{
    GEU32 NumberOfPhysicalCores;
    GEU32 NumberOfLogicalCores;
    GetNumberOfCores(NumberOfPhysicalCores, NumberOfLogicalCores);

    GEU32 NumberOfThreads;
    if (NumberOfPhysicalCores <= 1)
    {
        NumberOfThreads = 1;
    }
    else
    {
        if (NumberOfLogicalCores > NumberOfPhysicalCores)
        {
            GEU32 LogicalPerPhysical = NumberOfLogicalCores / NumberOfPhysicalCores;
            if (NumberOfLogicalCores > LogicalPerPhysical)
                // Reserve one physical core for the main thread.
                NumberOfThreads = NumberOfLogicalCores - LogicalPerPhysical;
            else
                NumberOfThreads = 1;
        }
        else
        {
            // Reserve one physical core for the main thread.
            NumberOfThreads = NumberOfPhysicalCores - 1;
        }
    }

    // Limit number of threads
    if (a_MaximumNumberOfThreads > 0 && NumberOfThreads > a_MaximumNumberOfThreads)
        NumberOfThreads = a_MaximumNumberOfThreads;

    return NumberOfThreads;
}

mCThreadPool::~mCThreadPool()
{
    Destroy();
}

void mCThreadPool::Create()
{
    Create(GetDefaultNumberOfThreads());
}

void mCThreadPool::Create(GEU32 a_NumberOfThreads)
{
    // Already created
    if (!m_arrThreads.IsEmpty())
        return;

    m_hAbortEvent = CreateEvent(0, TRUE, FALSE, NULL);
    m_hSemaphoreWorkItem = CreateSemaphore(0, 0, 0x7FFFFFFF, NULL);

    bCThreadWin32::bSThreadContext Context;
    Context.pUserData = this;

    m_arrThreads.Reserve(a_NumberOfThreads);
    for (GEU32 i = 0; i < a_NumberOfThreads; i++)
    {
        bCThreadWin32 *pThread = GE_NEW(bCThreadWin32)();
        pThread->Create(Context, &mCThreadPool::ThreadFunc);
        pThread->SetPriority(m_Priority);
        m_arrThreads.Add(pThread);
    }
}

void mCThreadPool::Destroy(GEBool a_bAbortWork)
{
    // Thread pool as already destroyed or not created.
    if (m_hAbortEvent == NULL)
        return;

    // Wait until all work items are finished.
    while (!a_bAbortWork && !m_arrWorkQueue.IsEmpty() && !bCErrorAdmin::GetInstance().IsInPanicState())
    {
        Sleep(0);
    }

    if (!SetEvent(m_hAbortEvent))
        GE_MESSAGE_WARN_EX(__FUNCTION__, "Failed to signal abort event to worker threads.");

    // Wait for threads to exit.
    GE_ARRAY_FOR_EACH (Thread, m_arrThreads)
    {
        WaitForSingleObject(Thread->GetHandle(), INFINITE);
    }

    CloseHandle(m_hSemaphoreWorkItem);
    CloseHandle(m_hAbortEvent);
    m_arrThreads.DeleteAll();

    m_hAbortEvent = NULL;
    m_hSemaphoreWorkItem = NULL;
    m_Priority = bCThreadWin32::bEThreadPriority_NORMAL;
}

void mCThreadPool::InsertWorkItem(mCThreadPoolWorkerItem *a_pWorkItem)
{
    mCLockGuard Lock(m_WorkQueueMutex);
    m_arrWorkQueue.Push(a_pWorkItem);
    if (!ReleaseSemaphore(m_hSemaphoreWorkItem, 1, NULL))
        GE_MESSAGE_WARN_EX(__FUNCTION__, "Failed to signal new work item to worker threads.");
}

mCThreadPool::mCThreadPoolWorkerItem *mCThreadPool::RemoveWorkItem()
{
    mCLockGuard Lock(m_WorkQueueMutex);
    return !m_arrWorkQueue.IsEmpty() ? m_arrWorkQueue.Pop() : nullptr;
}

GEUInt mCThreadPool::NumWorkItems()
{
    mCLockGuard Lock(m_WorkQueueMutex);
    return m_arrWorkQueue.Size();
}

GEBool mCThreadPool::ResetWorkQueueSize()
{
    mCLockGuard Lock(m_WorkQueueMutex);
    if (!m_arrWorkQueue.IsEmpty())
        return GEFalse;

    m_arrWorkQueue.Reset();
    return GETrue;
}

void mCThreadPool::SetPriority(bCThreadWin32::bEThreadPriority a_Priority)
{
    m_Priority = a_Priority;
    GE_ARRAY_FOR_EACH (pThread, m_arrThreads)
    {
        pThread->SetPriority(m_Priority);
    }
}

mCThreadPool::mCThreadPoolWorkerItem::~mCThreadPoolWorkerItem()
{}
