#pragma once

#include <Engine/ge_gfxshared.h>
#include <Engine/ge_vertexbufferpoolitem.h>

#include <SharedBase.h>

class eCLightmap;

class GE_DLLIMPORT eCVertexbufferPoolItemLightmap : public eCVertexbufferPoolItem
{
    // clang-format off
    protected: ~eCVertexbufferPoolItemLightmap() override;
    public: GEBool IsDataAvailable() const override;
    public: bCObjectRefBase * GetResourceObject() const override;
    // clang-format on

  public:
    static void GE_STDCALL AddVertexDeclElements(bTSmallArray<eCGfxShared::eSGfxDclElement> &, GEU16);

  public:
    eCVertexbufferPoolItemLightmap(eCVertexbufferPoolItemLightmap const &);
    explicit eCVertexbufferPoolItemLightmap(eCLightmap *);

  public:
    eCVertexbufferPoolItemLightmap &operator=(eCVertexbufferPoolItemLightmap const &);

  public:
    GEBool CreateBuffers(bTSmallArray<eCLightmap *> const &);
    GEU32 GetBeginVertexClump() const;
    eCLightmap *GetLightmap() const;
    GEBool Rebuild();
    void SetBeginVertexClump(GEU32);
};
