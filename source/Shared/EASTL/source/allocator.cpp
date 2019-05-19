#include <EABase/eabase.h>
#include <EASTL/internal/config.h>

#include <EASTL/allocator.h>

#include <SharedBase/ge_def.h>
#include <SharedBase/ge_types.h>
#include <SharedBase/ge_memoryadmin.h>

namespace eastl {

    // Constructors
    EASTL_ALLOCATOR_EXPLICIT allocator::allocator(const char* EASTL_NAME(name))
    {
#if EASTL_NAME_ENABLED
      mpName = name;
#endif
    }
    allocator::allocator(const allocator& EASTL_NAME(alloc))
    {
#if EASTL_NAME_ENABLED
      mpName = alloc.mpName;
#endif
    }
    allocator::allocator(const allocator&, const char* EASTL_NAME(name))
    {
#if EASTL_NAME_ENABLED
      mpName = name ? name : EASTL_ALLOCATOR_DEFAULT_NAME;
#endif
    }

    // Assignment
    allocator& allocator::operator=(const allocator& EASTL_NAME(alloc))
    {
#if EASTL_NAME_ENABLED
      mpName = alloc.mpName;
#endif
      return *this; // All considered equal since they're global malloc/free
    }

    // Allocation & Deallocation
    void* allocator::allocate(size_t n, int flags)
    {
      return GE_MALLOC(n);
    }
    void* allocator::allocate(size_t n, size_t alignment, size_t offset, int flags)
    {
      EASTL_ASSERT(alignment <= 8); // 8 (sizeof(double)) is the standard alignment returned by operator new.
      return GE_MALLOC(n);
    }

    void allocator::deallocate(void* p, size_t n)
    {
      GE_FREE(p);
    }

    // Name info
    const char* allocator::get_name() const
    {
#if EASTL_NAME_ENABLED
      return mpName;
#else
      return EASTL_ALLOCATOR_DEFAULT_NAME;
#endif
    }
    void allocator::set_name(const char* EASTL_NAME(name))
    {
#if EASTL_NAME_ENABLED
      mpName = name;
#endif
    }

  // EASTL expects us to define these operators (allocator.h L103)
  bool operator==(const allocator& a, const allocator& b)
  {
    return true; // All are considered equal since they are global malloc/free
  }
  bool operator!=(const allocator& a, const allocator& b)
  {
    return false; // All are considered equal since they are global malloc/free
  }

  // Defines the EASTL API glue, so we can set our allocator as the global default allocator
  allocator  gDefaultAllocator;
  allocator* gpDefaultAllocator = &gDefaultAllocator;

  allocator* GetDefaultAllocator()
  { return gpDefaultAllocator; }

  allocator* SetDefaultAllocator(allocator* pNewAlloc)
  {
    allocator* pOldAlloc = gpDefaultAllocator;
    gpDefaultAllocator = pNewAlloc;
    return pOldAlloc;
  }
};