#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/entity/ge_entitypropertyset.h>
#include <Engine/ge_stringwrapper.h>

#include <SharedBase.h>

class eCResourceDataEntity;
class eCResourceSpeedTree_PS;
class eCWraper_SpeedTreeRT;

class GE_DLLIMPORT eCSpeedTree_PS : public eCEntityPropertySet
{
    // clang-format off
    public: virtual GEBool IsResourceLoaded() const;
    public: virtual GEBool ConvertFrom(eCSpeedTree_PS const &);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCSpeedTree_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsVisual() const override;
    public: eCRenderContext * QueryRenderContext() override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: eCSpeedTree_PS * Clone(eCEntity *) const override;
    protected: void OnEnterProcessingRange() override;
    protected: void OnExitProcessingRange() override;
    protected: void OnUpdateInternals() override;
    protected: void OnCacheIn() override;
    protected: void OnCacheOut() override;
    public: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnPostRead() override;
    public: GEBool IntersectsRay(eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc **) const override;
    public: GEBool IntersectsVolume(bCVolume &, bCMatrix const &, bTValArray<bCTriangle> *, GEBool) const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCSpeedTree_PS, eCEntityPropertySet)
    GE_PROPERTY(bCSpeedTreeResourceString, ResourceFilePath, m_strResourceFilePath)
    GE_PROPERTY(GEBool, EnableWind, m_bEnableWind)
    GE_PROPERTY(GEBool, InfluenceGlobalAmbientOcclusion, m_bInfluenceGlobalAmbientOcclusion)
    GE_PADDING(2)
    GE_ENUMPROP(eEAmbientEnvironment, AmbientEnvironment, m_enuAmbientEnvironment)

  public:
    GEBool CreateEntityCollsionGeometry(GEBool);
    eCWraper_SpeedTreeRT *GetSpeedTreeInstance() const;
    eCResourceSpeedTree_PS *GetSpeedTreeResource() const;
    void Render();
    void RenderTerrainShadow();
    void UpdateLoD();

  protected:
    void Invalidate();
    void SetResourceDataEntity(eCResourceDataEntity *);

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(eCSpeedTree_PS, 0x30)

GE_ASSERT_PROPERTY(eCSpeedTree_PS, m_strResourceFilePath, 0x14, 4)
GE_ASSERT_PROPERTY(eCSpeedTree_PS, m_bEnableWind, 0x18, 1)
GE_ASSERT_PROPERTY(eCSpeedTree_PS, m_bInfluenceGlobalAmbientOcclusion, 0x19, 1)
GE_ASSERT_PROPERTY(eCSpeedTree_PS, m_enuAmbientEnvironment, 0x1c, 8)
