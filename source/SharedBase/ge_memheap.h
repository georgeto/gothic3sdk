#ifndef GE_MEMHEAP_H_INCLUDED
#define GE_MEMHEAP_H_INCLUDED

struct MemPointerArea;
struct MemUsage;
struct MemFragmentation;

class GE_DLLIMPORT MemHeap
{

    private:
        static GEInt *          s_arrEntries;
        static MemPointerArea * s_arrPointerAreas;
        static GEBool           s_bHeapLowFragment;
        static GEChar           s_cLock;
        static GELPVoid         s_hHeap;
        static GEInt const      s_iAreas;
        static GEInt const      s_iMaxEntries;
        static GEInt const      s_iSize;
        static MemHeap *        s_pFirst;
        static GELPVoid         s_pLargeBlock;
        static GEUInt           s_uiActCount;
        static GEUInt           s_uiActMemory;
        static GEUInt           s_uiCountHeapAllocFails;
        static GEUInt           s_uiCountHeapCompactFails;
        static GEUInt           s_uiEntries;
        static GEUInt           s_uiLargeActBlocks;
        static GEUInt           s_uiLargeActMemory;
        static GEUInt           s_uiLargeMaxBlocks;
        static GEUInt           s_uiLargeMaxMemory;
        static GEUInt           s_uiLastCompactSize;
        static GEUInt           s_uiMaxCount;
        static GEUInt           s_uiMaxMemory;
        static GEUInt           s_uiMaxSize;
        static GEUInt           s_uiMinSize;
        static GEUInt           s_uiPointerAreas;

    public:
        static GELPVoid GE_STDCALL         Alloc( GEUInt );
        static GELPVoid GE_STDCALL         AllocShortUsage( GEUInt );
        static GELPVoid GE_STDCALL         AllocShortUsageUnsynced( GEUInt );
        static GELPVoid GE_STDCALL         AllocUnsynced( GEUInt );
        static void GE_STDCALL             Dump( GEDouble );
        static void GE_STDCALL             DumpToString( GELPChar );
        static void GE_STDCALL             Free( GELPVoid );
        static void GE_STDCALL             FreeShortUsage( GELPVoid );
        static void GE_STDCALL             FreeShortUsageUnsynced( GELPVoid );
        static void GE_STDCALL             FreeUnsynced( GELPVoid );
        static GEUInt GE_STDCALL           GetLargestShortUsageBlockSize( void );
        static GEUInt GE_STDCALL           GetLargestShortUsageBlockSizeUnsynced( void );
        static MemPointerArea * GE_STDCALL GetPointerArea( GELPVoid );
        static void GE_STDCALL             GetUsage( MemUsage * );
        static void GE_STDCALL             GetUsageUnsynced( MemUsage * );
        static GELPVoid GE_STDCALL         ReAlloc( GELPVoid, GEUInt );
        static GELPVoid GE_STDCALL         ReAllocUnsynced( GELPVoid, GEUInt );

    public:
        MemHeap & operator = ( MemHeap const & );

    public:
        //MemHeap(void (GE_STDCALL*)(GELPVoid,GELPVoid),GELPVoid (GE_STDCALL*)(GELPVoid,GELPVoid,GEUInt),void (GE_STDCALL*)(_iobuf *),void (GE_STDCALL*)(MemFragmentation *));
        void addPointerArea( GELPVoid, GEUInt, GELPVoid );

    protected:
        static GEInt GE_STDCALL CallExceptionError( _EXCEPTION_POINTERS * );

    private:
        static GELPVoid ( GE_STDCALL**s_arrSimpleAllocs )( void );

};

#endif
