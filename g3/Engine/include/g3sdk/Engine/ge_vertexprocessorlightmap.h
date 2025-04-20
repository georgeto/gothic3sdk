#pragma once

#include <Engine/ge_vertexprocessor.h>

#include <SharedBase.h>

class eCGfxVertexData;
class eCLightmap;

class GE_DLLIMPORT eCVertexProcessorLightmap : public eCVertexProcessor
{
  public:
    struct eSBufferDesc
    {
        GE_UNIMPL_STRUCT(eSBufferDesc)
    };

    // clang-format off
    public: GEBool IsValid() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCVertexProcessorLightmap() override;
    public: GEU32 GetElementSize() const override;
    public: eCGfxShared::eEPoolType GetBufferPoolType() const override;
    public: GEBool DestroyBuffer() override;
    // clang-format on

  public:
    eCVertexProcessorLightmap();

  public:
    GEBool CreateBuffer(bTSmallArray<eCLightmap *> const &);
    bTSmallArray<eSBufferDesc> const &GetLightmapDescs() const;
    eCGfxVertexData *GetVertexBuffer();
    GEBool UpdateBuffer();

  protected:
    eCVertexProcessorLightmap(eCVertexProcessorLightmap const &);

  protected:
    eCVertexProcessorLightmap const &operator=(eCVertexProcessorLightmap const &);

  protected:
    void Invalidate();
};
