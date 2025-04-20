#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCVertexbufferPool
{
    // clang-format off
    public: virtual void Destroy();
    public: virtual bEResult Create();
    public: virtual ~eCVertexbufferPool();
    // clang-format on

  public:
    eCVertexbufferPool();

  public:
    GEU32 GetCurrentBufferUsage() const;
    void PostInitialize();
    void PreShutdown();

  protected:
    eCVertexbufferPool(eCVertexbufferPool const &);

  protected:
    eCVertexbufferPool const &operator=(eCVertexbufferPool const &);

  protected:
    void Invalidate();
};
