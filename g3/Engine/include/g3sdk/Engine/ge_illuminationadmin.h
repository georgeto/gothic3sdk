#pragma once

#include <Engine/ge_enginecomponentbase.h>
#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCDynamicLight_PS;
class eCEntity;
class eCGfxImageData;
class eCIlluminated_PS;
class eCLightSet;
class eCLightmap;
class eCLightmapTexture;
class eCStaticLight_PS;
class eCTerrainShadowMap;
struct eSShaderMaterialIllumination;

class GE_DLLIMPORT eCIlluminationAdmin : public eCEngineComponentBase
{
  public:
    enum eEIlluminationMovingLight
    {
        // TODO: Enumerator values
    };

    struct eSIllumination
    {
        GE_UNIMPL_STRUCT(eSIllumination)
    };

    // clang-format off
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: GEU32 const GetProfileLastTicksFirst() const override;
    public: ~eCIlluminationAdmin() override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult Shutdown() override;
    public: bEResult ResetResources(GEBool) override;
    public: bEResult RestoreResources(GEBool) override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCIlluminationAdmin, eCEngineComponentBase)

  public:
    static GEInt GE_CCALL SortWightedLights(GELPCVoid, GELPCVoid);

  public:
    eCGfxImageData *AllocateShadowMapImage(eCGfxShared::eSGfxLayersDesc const &);
    void DeleteShadowMapBuffer();
    bEResult DeregisterDynamicLightPS(eCDynamicLight_PS *);
    bEResult DeregisterStaticLightPS(eCStaticLight_PS *);
    void EnableDefaultIllumination(GEBool);
    void EnableDetailShadows(GEBool);
    void EnableRenderStaticLights(GEBool);
    void EnableStaticShadows(GEBool);
    void EnableTerrainShadows(GEBool);
    void FreeShadowMapImage(eCGfxImageData *);
    GEBool GetCachedInStaticLights(bCBox const &, bTValArray<eCStaticLight_PS *> &);
    GEBool GetCachedInStaticLights(eCEntity *, bTValArray<eCStaticLight_PS *> &);
    GEBool GetDynamicAOValueFromGrid(bCVector const &, GEFloat &);
    GEInt GetDynamicStaticLightData(bCBox const &, bCVector4 *);
    void GetEffectedDynamicLights(eCIlluminated_PS *);
    GEBool GetEnabledDefaultIllumination();
    void GetIlluminationAt(bCBox const &, eSShaderMaterialIllumination &);
    eCLightSet *GetLightSet(GEU32);
    bCString const &GetLightmapPath() const;
    GEInt GetLightmapTextureCount() const;
    GEInt GetLightmapTextureIndex(eCLightmapTexture *) const;
    eEIlluminationMovingLight GetMovingLight() const;
    GELPVoid GetShadowMapDepthBuffer(GEInt);
    eCGfxImageData *GetShadowMapWorkingBuffer(GEInt);
    eCTerrainShadowMap *GetTerrainShadowMap() const;
    GEU32 GetUsedShadowMapTotalBytes() const;
    GEBool InsertLightmap(eCLightmap *);
    void Invalidate();
    GEBool IsDetailShadowsEnabled() const;
    GEBool IsRenderStaticLightsEnabled() const;
    GEBool IsStaticShadowsEnabled() const;
    GEBool IsTerrainShadowsEnabled() const;
    void GE_STDCALL OnCycleMovingLight(bCObjectRefBase *, bCEvent *);
    eCLightSet *QueryLightSet(bTValArray<eCDynamicLight_PS *> const &);
    bEResult RegisterDynamicLightPS(eCDynamicLight_PS *);
    bEResult RegisterStaticLightPS(eCStaticLight_PS *);
    GEBool RemoveLightmap(eCLightmap *);
    bEResult SetMovingLight(eEIlluminationMovingLight);
    void UpdateShadowMaps();
    void UpdateSkydomeCubemap();

  protected:
    void AddLightSet(eCLightSet *);
    GEBool FindAOGrid(bCVector const &, eCEntity *, GEFloat &);
    void OptimizeLightSets();
    void RemoveLightSet(eCLightSet *);

  private:
    GE_UNIMPL_MEMBERS(188)
};

GE_ASSERT_SIZEOF(eCIlluminationAdmin, 0xd0)
