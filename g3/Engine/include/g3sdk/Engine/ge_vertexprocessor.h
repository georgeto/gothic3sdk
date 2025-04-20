#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCVertexProcessor : public bCObjectRefBase
{
    // clang-format off
    public: virtual GEU32 GetElementSize() const = 0;
    public: virtual eCGfxShared::eEPoolType GetBufferPoolType() const = 0;
    public: virtual GEBool DestroyBuffer() = 0;
    protected: virtual void CopyFrom(eCVertexProcessor const &);
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCVertexProcessor() override;
    // clang-format on

  public:
    eCVertexProcessor();

  public:
    GEU32 GetElementCount() const;
    GEU32 GetSize() const;

  protected:
    eCVertexProcessor(eCVertexProcessor const &);

  protected:
    eCVertexProcessor const &operator=(eCVertexProcessor const &);

  protected:
    void Invalidate();
};
