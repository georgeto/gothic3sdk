#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

struct _iobuf;
struct _EXCEPTION_POINTERS;

struct MemFragmentation
{
    GE_UNIMPL_STRUCT(MemFragmentation)
};

struct MemPointerArea
{
    GE_UNIMPL_STRUCT(MemPointerArea)
};

struct MemUsage
{
    GEUInt Small_BlocksCurrent;
    GEUInt Small_BlocksMax;
    GEUInt Small_Heaps;
    GEUInt Small_MemoryUsed;
    GEUInt Small_MemoryFree;
    GEUInt Small_MemoryWindows;
    GEUInt Mid_BlocksCurrent;
    GEUInt Mid_BlocksMax;
    GEUInt Mid_Heaps;
    GEUInt Mid_MemoryUsed;
    GEUInt Mid_MemoryFree;
    GEUInt Mid_MemoryWindows;
    GEUInt Large_MemoryLargestFree; // HeapCompact(MemHeap::s_hHeap, 0)
    GEUInt Large_BlocksCurrent;     // MemHeap::s_uiActCount
    GEUInt Large_BlocksMax;         // MemHeap::s_uiMaxCount
    GEUInt Large_MemoryUsed;        // MemHeap::s_uiActMemory
    GEUInt Large_MemoryPeak;        // MemHeap::s_uiMaxMemory
    GEUInt Buffer_MemoryLargestFree;
    GEUInt Buffer_BlocksCurrent; // MemHeap::s_uiLargeActBlocks
    GEUInt Buffer_BlocksMax;     // MemHeap::s_uiLargeMaxBlocks
    GEUInt Buffer_MemoryUsed;    // MemHeap::s_uiLargeActMemory
    GEUInt Buffer_MemoryPeak;    // MemHeap::s_uiLargeMaxMemory
    GEUInt Buffer_MemoryWindows; // 0x6000000
};

class GE_DLLIMPORT MemHeap
{
  public:
    static GELPVoid GE_STDCALL Alloc(GEUInt);
    static GELPVoid GE_STDCALL AllocShortUsage(GEUInt);
    static GELPVoid GE_STDCALL AllocShortUsageUnsynced(GEUInt);
    static GELPVoid GE_STDCALL AllocUnsynced(GEUInt);
    static void GE_STDCALL Dump(GEDouble);
    static void GE_STDCALL DumpToString(GELPChar);
    static void GE_STDCALL Free(GELPVoid);
    static void GE_STDCALL FreeShortUsage(GELPVoid);
    static void GE_STDCALL FreeShortUsageUnsynced(GELPVoid);
    static void GE_STDCALL FreeUnsynced(GELPVoid);
    static GEUInt GE_STDCALL GetLargestShortUsageBlockSize();
    static GEUInt GE_STDCALL GetLargestShortUsageBlockSizeUnsynced();
    static MemPointerArea *GE_STDCALL GetPointerArea(GELPVoid);
    static void GE_STDCALL GetUsage(MemUsage *);
    static void GE_STDCALL GetUsageUnsynced(MemUsage *);
    static GELPVoid GE_STDCALL ReAlloc(GELPVoid, GEUInt);
    static GELPVoid GE_STDCALL ReAllocUnsynced(GELPVoid, GEUInt);

  public:
    MemHeap(void(GE_STDCALL *)(GELPVoid, GELPVoid), GELPVoid(GE_STDCALL *)(GELPVoid, GELPVoid, GEUInt),
            void(GE_STDCALL *)(_iobuf *), void(GE_STDCALL *)(MemFragmentation *));

  public:
    MemHeap &operator=(MemHeap const &);

  public:
    void addPointerArea(GELPVoid, GEUInt, GELPVoid);

  protected:
    static GEInt GE_STDCALL CallExceptionError(_EXCEPTION_POINTERS *);

  private:
    static GEInt *s_arrEntries;
    static MemPointerArea *s_arrPointerAreas;
    static GELPVoid(GE_STDCALL **s_arrSimpleAllocs)();
    static GEBool s_bHeapLowFragment;
    static GEChar s_cLock;
    static GELPVoid s_hHeap;
    static GEInt const s_iAreas;
    static GEInt const s_iMaxEntries;
    static GEInt const s_iSize;
    static MemHeap *s_pFirst;
    static GELPVoid s_pLargeBlock;
    static GEUInt s_uiActCount;
    static GEUInt s_uiActMemory;
    static GEUInt s_uiCountHeapAllocFails;
    static GEUInt s_uiCountHeapCompactFails;
    static GEUInt s_uiEntries;
    static GEUInt s_uiLargeActBlocks;
    static GEUInt s_uiLargeActMemory;
    static GEUInt s_uiLargeMaxBlocks;
    static GEUInt s_uiLargeMaxMemory;
    static GEUInt s_uiLastCompactSize;
    static GEUInt s_uiMaxCount;
    static GEUInt s_uiMaxMemory;
    static GEUInt s_uiMaxSize;
    static GEUInt s_uiMinSize;
    static GEUInt s_uiPointerAreas;
};
