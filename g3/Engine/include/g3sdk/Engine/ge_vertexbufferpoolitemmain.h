#pragma once

#include <Engine/ge_gfxshared.h>
#include <Engine/ge_vertexbufferpoolitem.h>
#include <Engine/ge_vertexprocessoradditional.h>
#include <Engine/ge_vertexprocessormain.h>

#include <SharedBase.h>

class eCFrustumElementItem;
class eCIlluminated_PS;
class eCMeshElement;
class eCResourceDataEntity;
class eCResourceShaderMaterial_PS;
class eCVertexbufferPoolItemLightmap;

class GE_DLLIMPORT eCVertexbufferPoolItemMain : public eCVertexbufferPoolItem
{
    // clang-format off
    protected: ~eCVertexbufferPoolItemMain() override;
    public: GEBool IsDataAvailable() const override;
    public: bCObjectRefBase * GetResourceObject() const override;
    // clang-format on

  public:
    static void GE_STDCALL ExecuteAllInstances();

  public:
    explicit eCVertexbufferPoolItemMain(eCMeshElement &);

  public:
    void AddInstance(eCFrustumElementItem &, eCVertexbufferPoolItemLightmap *, GEFloat, GEInt);
    GEBool CreateBuffers(bTSmallArray<eCVertexProcessorMain::eSVertexInfoDesc> const &,
                         bTSmallArray<eCVertexProcessorAdditional::eSVertexInfoDesc> const &,
                         bTValArray<GEU32> const &);
    GEBool Execute(eCIlluminated_PS *, eCVertexbufferPoolItemLightmap *, GEInt);
    GEBool ExecuteZPass();
    eCVertexProcessorAdditional *GetAdditionalBuffer() const;
    GEInt GetIndexBufferCount() const;
    GEInt GetIndexBufferStartIndex() const;
    eCVertexProcessorMain *GetMainBuffer() const;
    eCResourceShaderMaterial_PS *GetMaterial();
    eCMeshElement *GetMeshElement();
    eCResourceDataEntity *GetResourceDataEntity();
    bTValArray<bCVector2> *GetUVArray(GEInt, GEBool);
    GEBool HasMainBuffer() const;
    GEBool IsMasked() const;
    GEBool IsSolid() const;
    GEBool MustSupportBumpMaps() const;
    GEBool Prefetch(GEBool, bTSmallArray<eCGfxShared::eSGfxDclElement> &, GEU32, GEU32);
    void SetIndexBufferCount(GEInt);
    void SetIndexBufferStartIndex(GEInt);
    void SetMaterialEntity(eCResourceDataEntity *);
    void SetVertexCount(GEU32);
    void SetVertexOffset(GEU32);
    GEBool SupportsInstancing() const;

  protected:
    static bTValArray<eCVertexbufferPoolItemMain *> ms_arrInstancePooltItems;

  protected:
    static GEInt GE_CCALL SortInstances(GELPCVoid, GELPCVoid);
    static GEInt GE_CCALL SortPoolItems(GELPCVoid, GELPCVoid);

  protected:
    void ExecuteInstance();
};
