#pragma once

#include <Engine/ge_vertexprocessor.h>

#include <SharedBase.h>

class eCGfxVertexData;

class GE_DLLIMPORT eCVertexProcessorAdditional : public eCVertexProcessor
{
  public:
    struct eSAdditionalElement
    {
        GE_UNIMPL_STRUCT(eSAdditionalElement)
    };

    struct eSVertexInfoDesc
    {
        GE_UNIMPL_STRUCT(eSVertexInfoDesc)
    };

    // clang-format off
    public: virtual GEBool CreateBuffer(bTSmallArray<eSVertexInfoDesc> const &);
    public: GEBool IsValid() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCVertexProcessorAdditional() override;
    public: GEU32 GetElementSize() const override;
    public: eCGfxShared::eEPoolType GetBufferPoolType() const override;
    public: GEBool DestroyBuffer() override;
    // clang-format on

  public:
    eCVertexProcessorAdditional();

  public:
    GEU32 GetBufferSize() const;
    bTObjArray<eSAdditionalElement> const &GetElements() const;
    eCGfxVertexData *GetVertexBuffer();

  protected:
    eCVertexProcessorAdditional(eCVertexProcessorAdditional const &);

  protected:
    eCVertexProcessorAdditional const &operator=(eCVertexProcessorAdditional const &);

  protected:
    void Invalidate();
};
