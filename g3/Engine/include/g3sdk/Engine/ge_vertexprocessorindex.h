#pragma once

#include <Engine/ge_vertexprocessor.h>

#include <SharedBase.h>

class eCGfxIndexData;

class GE_DLLIMPORT eCVertexProcessorIndex : public eCVertexProcessor
{
  public:
    struct eSIndexInfoDesc
    {
        GE_UNIMPL_STRUCT(eSIndexInfoDesc)
    };

    // clang-format off
    public: GEBool IsValid() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCVertexProcessorIndex() override;
    public: GEU32 GetElementSize() const override;
    public: eCGfxShared::eEPoolType GetBufferPoolType() const override;
    public: GEBool DestroyBuffer() override;
    // clang-format on

  public:
    eCVertexProcessorIndex();

  public:
    GEBool CreateBuffer(bTSmallArray<eSIndexInfoDesc> &);
    eCGfxIndexData *GetIndexBuffer();

  protected:
    eCVertexProcessorIndex(eCVertexProcessorIndex const &);

  protected:
    eCVertexProcessorIndex const &operator=(eCVertexProcessorIndex const &);

  protected:
    void Invalidate();
};
