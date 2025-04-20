#pragma once

#include <Engine/ge_gfxshared.h>
#include <Engine/ge_vertexprocessor.h>

#include <SharedBase.h>

class eCGfxVertexData;

class GE_DLLIMPORT eCVertexProcessorMain : public eCVertexProcessor
{
  public:
    struct eSVertexInfoDesc
    {
        GE_UNIMPL_STRUCT(eSVertexInfoDesc)
    };

    // clang-format off
    public: virtual GEBool CreateBuffer(bTSmallArray<eSVertexInfoDesc> const &);
    public: GEBool IsValid() const override;
    public: void Destroy() override;
    public: ~eCVertexProcessorMain() override;
    public: GEU32 GetElementSize() const override;
    public: eCGfxShared::eEPoolType GetBufferPoolType() const override;
    public: GEBool DestroyBuffer() override;
    // clang-format on

  public:
    static void GE_STDCALL FillDeclaration(bTSmallArray<eCGfxShared::eSGfxDclElement> &);

  public:
    eCVertexProcessorMain(eCVertexProcessorMain const &);
    eCVertexProcessorMain();

  public:
    eCGfxVertexData *GetVertexBuffer();
    eCGfxVertexData *GetVertexBufferDefaultLightmap();

  protected:
    eCVertexProcessorMain const &operator=(eCVertexProcessorMain const &);

  protected:
    void Invalidate();
};
