#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_lightmapbitmap.h>

#include <SharedBase.h>

class eCMeshElement;
class eCResourceDataEntity;
class eCResourceMeshComplex_PS;
class eCVertexbufferPoolItem;

class eCLightmapTexture
{
    GE_UNIMPL_STRUCT(eCLightmapTexture)
};

class GE_DLLIMPORT eCLightmap : public bCObjectRefBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCLightmap() override;
    // clang-format on

  public:
    eCLightmap(eCLightmap const &);
    eCLightmap(eCResourceMeshComplex_PS *, eCResourceDataEntity *, GEInt, GEFloat, eELightmapType);
    eCLightmap();

  public:
    eCLightmap &operator=(eCLightmap const &);

  public:
    void Blur();
    GEBool ClearStaticLight();
    GEBool CopyDefaultValuesFromMesh();
    void FillVertices(GELPChar, GEInt);
    bTObjArray<eCLightmapBitmap> const &GetBitmaps() const;
    eCLightmapTexture *GetLightmapTexture() const;
    eELightmapType GetLightmapType() const;
    eCMeshElement *GetMeshElement(GEBool);
    bTValArray<GEU32> &GetPerVertexColors();
    bTValArray<GEU32> const &GetPerVertexColors() const;
    bTValArray<bCVector> &GetPerVertexIncident();
    bTValArray<bCVector> const &GetPerVertexIncident() const;
    eCResourceDataEntity *GetResourceDataEntity() const;
    GEFloat GetScaling() const;
    GEU32 GetSize() const;
    GEU32 GetTextureSize();
    GEInt GetVertexCount();
    eCVertexbufferPoolItem *GetVertexbufferPoolItem() const;
    void Invalidate();
    GEBool IsDirty();
    void SetDirty(GEBool);
    GEBool SetLightmapTexture(eCLightmapTexture *);
    void SetLightmapType(eELightmapType);
    void SetScaling(GEFloat);
    void SetVertexbufferPoolItem(eCVertexbufferPoolItem *);
    void UnloadResources();
    void UpdateVertexbufferPoolItem();
};
