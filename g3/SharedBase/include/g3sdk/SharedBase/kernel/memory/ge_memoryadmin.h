#pragma once

#include "ge_memheap.h"

#include <SharedBase/kernel/error/ge_error.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class GE_DLLIMPORT bCMemoryAdmin
{
  public:
    static bCMemoryAdmin &GE_STDCALL GetInstance();

  public:
    bCMemoryAdmin();
    explicit bCMemoryAdmin(GEBool);
    ~bCMemoryAdmin();

  public:
    bCMemoryAdmin &operator=(bCMemoryAdmin const &);

  public:
    void DeleteObject(GELPVoid);
    void Destroy();
    void EnableDumpHeapProfiling(GEBool);
    void EnableHeapProfiler(GEBool);
    void EnableMemoryLeakReport(GEBool);
    void Free(GELPVoid);
    GELPVoid Malloc(GEU32);
    GELPVoid NewObject(GEU32);
    GELPVoid Realloc(GELPVoid, GEU32);

  protected:
    void Create();
    void Invalidate();

  private:
    static GEBool ms_bInitialized;
};

inline GELPVoid GE_MALLOC(GEU32 a_u32Size)
{
    return bCMemoryAdmin::GetInstance().Malloc(a_u32Size);
}

inline GELPVoid GE_REALLOC(GELPVoid a_pBlock, GEU32 a_u32Size)
{
    return bCMemoryAdmin::GetInstance().Realloc(a_pBlock, a_u32Size);
}

inline void GE_FREE(GELPVoid a_pBlock)
{
    bCMemoryAdmin::GetInstance().Free(a_pBlock);
}

#ifndef __PLACEMENT_NEW_INLINE
#define __PLACEMENT_NEW_INLINE
inline GELPVoid GE_CCALL operator new(size_t, GELPVoid _p)
{
    return _p;
}
inline void GE_CCALL operator delete(GELPVoid, GELPVoid)
{}
#endif

// NOTE: Clang does not support EXTC import of operator new.
// GE_DLLIMPORT_EXTC GELPVoid GE_STDCALL operator new ( size_t, GEInt );
inline GELPVoid GE_STDCALL operator new(size_t Size, GEInt)
{
    GELPVoid Result = MemHeap::Alloc(Size);
    if (!Result)
        GE_FATAL_ERROR_EX("Constructor: -> couldn´t allocate the specified object using new operator.",
                          "Critical memory error");
    return Result;
}

#define GE_NEW(T) new (0) T

//
// delete
//

inline void operator delete(GELPVoid a_pObject, GEInt)
{
    bCMemoryAdmin::GetInstance().DeleteObject(a_pObject);
}

template <typename TYPE>
inline void GE_DELETE(TYPE *&a_pObject)
{
    if (a_pObject)
    {
        a_pObject->~TYPE();
        bCMemoryAdmin::GetInstance().DeleteObject(a_pObject);
        a_pObject = nullptr;
    }
}
