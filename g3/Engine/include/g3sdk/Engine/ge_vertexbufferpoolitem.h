#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCVertexbufferPoolItem : public bCObjectRefBase
{
    // clang-format off
    public: virtual GEBool IsPrefetching() const;
    public: virtual GEBool IsDataAvailable() const = 0;
    public: virtual bCObjectRefBase * GetResourceObject() const = 0;
    protected: ~eCVertexbufferPoolItem() override;
    // clang-format on

  public:
    eCVertexbufferPoolItem(eCVertexbufferPoolItem const &);
    eCVertexbufferPoolItem();

  public:
    eCVertexbufferPoolItem &operator=(eCVertexbufferPoolItem const &);

  public:
    GEU32 AddCacheInCount();
    GEU32 GetCacheInCount() const;
    GEBool IsExecuting() const;
    void LockForExecuting(GEBool);
    void LockForPrefetching(GEBool);
    GEU32 ReleaseCacheInCount();
};
