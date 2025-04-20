#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class eCAmbientOcclusionGrid;
class eCLightmap;
class eCResourceMeshComplex_PS;

class GE_DLLIMPORT eCResourceLightmap_PS : public eCResourceBase_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceLightmap_PS() override;
    public: bCString const & GetProprietaryFileExt() const override;
    public: bCString const & GetNativeFileExt() const override;
    public: eCResourceBase_PS::eECacheType GetCacheType() const override;
    public: bEResult DoLoad() override;
    public: bEResult DoUnload() override;
    public: bEResult DoReload() override;
    public: bEResult DoConvert() override;
    public: bEResult DoSave() override;
    protected: void CalculateSize() override;
    public: void OnUpdateInternals() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCResourceLightmap_PS, eCResourceBase_PS)

  public:
    static void GE_STDCALL GetProprietaryFileExt(bCString &);
    static GEBool GE_STDCALL IsNativeFileType(bCString const &);
    static GEBool GE_STDCALL IsProprietaryFileType(bCString const &);

  public:
    GEBool ClearStaticLight();
    GEBool Create(eCResourceMeshComplex_PS *, eELightmapType, GEFloat);
    void CreateAmbientOcclusionGrid();
    void DestroyAmbientOcclusionGrid();
    eCAmbientOcclusionGrid *GetAmbientOcclusionGrid() const;
    eCLightmap *GetLightmap(GEInt) const;
    GEInt GetLightmapCount() const;
    eELightmapType GetLightmapType() const;
    GEFloat GetScaling() const;
    void SetLightmapType(eELightmapType);
    void SetScaling(GEFloat);

  protected:
    void DeleteResources();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(28)
};

GE_ASSERT_SIZEOF(eCResourceLightmap_PS, 0x48)
