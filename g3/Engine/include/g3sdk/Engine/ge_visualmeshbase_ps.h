#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/entity/ge_entitypropertyset.h>
#include <Engine/ge_stringwrapper.h>

#include <SharedBase.h>

class eCResourceDataEntity;

class GE_DLLIMPORT eCVisualMeshBase_PS : public eCEntityPropertySet
{
    // clang-format off
    public: virtual GEBool IsResourceLoaded() const;
    public: virtual eCResourceDataEntity * GetResourceDataEntity();
    public: virtual void SetResourceDataEntity(eCResourceDataEntity *);
    public: virtual eCResourceDataEntity * GetLightmapResourceDataEntity(GEU16, GEBool);
    public: virtual GEBool CopyLightmapsFrom(eCVisualMeshBase_PS *, GEBool);
    protected: virtual void SetLightmapResource(eCResourceDataEntity *, GEU16);
    public: virtual GEBool ConvertFrom(eCVisualMeshBase_PS const &);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCVisualMeshBase_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsVisual() const override;
    public: GEBool IsEditorRelevant() const override;
    public: eCRenderContext * QueryRenderContext() override;
    public: GEBool HasRenderAlphaComponent() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: eCVisualMeshBase_PS * Clone(eCEntity *) const override;
    protected: void OnUpdateInternals() override;
    protected: void OnCacheIn() override;
    protected: void OnCacheOut() override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: GEBool IntersectsRay(eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc **) const override;
    public: GEBool IntersectsVolume(bCVolume &, bCMatrix const &, bTValArray<bCTriangle> *, GEBool) const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCVisualMeshBase_PS, eCEntityPropertySet)
    GE_PROPERTY(bCMeshResourceString, ResourceFileName, m_strResourceFileName)
    GE_ENUMPROP(eEStaticLighingType, StaticLightingType, m_eStaticLightingType)
    GE_ENUMPROP(eELightmapAmbientOcclusion, LightmapAmbientOcclusion, m_eLightmapAmbientOcclusion)
    GE_ENUMPROP(eELightmapType, LightmapType, m_eLightmapType)
    GE_PROPERTY(GEFloat, UnitsPerLightmapTexel, m_fUnitsPerLightmapTexel)
    GE_PROPERTY(GEInt, MaterialSwitch, m_iMaterialSwitch)

  public:
    eCResourceDataEntity *CreateLightmapResource(GEBool, GEU16);

  protected:
    void Invalidate();
    void OnCacheOutLightmaps();

  private:
    GE_UNIMPL_MEMBERS(24)
};

GE_ASSERT_SIZEOF(eCVisualMeshBase_PS, 0x50)

GE_ASSERT_PROPERTY(eCVisualMeshBase_PS, m_strResourceFileName, 0x14, 4)
GE_ASSERT_PROPERTY(eCVisualMeshBase_PS, m_eStaticLightingType, 0x18, 8)
GE_ASSERT_PROPERTY(eCVisualMeshBase_PS, m_eLightmapAmbientOcclusion, 0x20, 8)
GE_ASSERT_PROPERTY(eCVisualMeshBase_PS, m_eLightmapType, 0x28, 8)
GE_ASSERT_PROPERTY(eCVisualMeshBase_PS, m_fUnitsPerLightmapTexel, 0x30, 4)
GE_ASSERT_PROPERTY(eCVisualMeshBase_PS, m_iMaterialSwitch, 0x34, 4)
