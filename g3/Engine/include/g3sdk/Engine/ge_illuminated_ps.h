#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/entity/ge_entitypropertyset.h>

#include <SharedBase.h>

class eCLightSet;
class eCShadowMapDirectionalLight;
class eCTerrainShadowMap;
struct eSShaderMaterialIllumination;

class GE_DLLIMPORT eCIlluminated_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    protected: bEResult Write(bCOStream &) override;
    protected: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCIlluminated_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    protected: void OnUpdatedWorldMatrix() override;
    protected: void OnCacheIn() override;
    protected: void OnCacheOut() override;
    protected: void OnPropertySetAdded() override;
    protected: void OnPropertySetRemoved() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCIlluminated_PS, eCEntityPropertySet)
    GE_PROPERTY(GEBool, EnableDynamicLighting, m_bEnableDynamicLighting)
    GE_PROPERTY(GEBool, EnableAmbient, m_bEnableAmbient)
    GE_PADDING(2)
    GE_ENUMPROP(eEStaticIlluminated, StaticIlluminated, m_eStaticIlluminated)
    GE_PROPERTY(GEBool, CastShadows, m_bCastShadows)
    GE_PROPERTY(GEBool, ReciveShadows, m_bReciveShadows)
    GE_PADDING(2)
    GE_ENUMPROP(eEDirectionalShadowType, DirectionalShadowType, m_eDirectionalShadowType)
    GE_PROPERTY(GEBool, ReciveTreeShadows, m_bReciveTreeShadows)
    GE_PROPERTY(GEBool, CastStaticShadows, m_bCastStaticShadows)
    GE_PROPERTY(GEBool, ReciveStaticShadows, m_bReciveStaticShadows)
    GE_PADDING(1)

  public:
    void ClearStaticLightData();
    eCShadowMapDirectionalLight *GetDirectionalShadowMap() const;
    eCLightSet const *GetLightSet() const;
    eSShaderMaterialIllumination &GetShaderMaterialIllumination();
    eSShaderMaterialIllumination const &GetShaderMaterialIllumination() const;
    eCTerrainShadowMap *GetTerrainShadowMap() const;
    void SetDSMOcclusionQuery(GELPVoid);
    void SetDirectionalShadowMap(eCShadowMapDirectionalLight *);
    void SetLightSet(eCLightSet *);
    void UpdateIllumination();

  protected:
    void Invalidate();

  public:
    GE_UNIMPL_MEMBERS(9)
    GEU8 m_uStaticLightCount;
    GE_PADDING(2)
    GEU8 m_StaticLightData[0x70]; // 7 x bCVector4
    GE_UNIMPL_MEMBERS(16)
};

GE_ASSERT_SIZEOF(eCIlluminated_PS, 0xbc)

GE_ASSERT_PROPERTY(eCIlluminated_PS, m_bEnableDynamicLighting, 0x14, 1)
GE_ASSERT_PROPERTY(eCIlluminated_PS, m_bEnableAmbient, 0x15, 1)
GE_ASSERT_PROPERTY(eCIlluminated_PS, m_eStaticIlluminated, 0x18, 8)
GE_ASSERT_PROPERTY(eCIlluminated_PS, m_bCastShadows, 0x20, 1)
GE_ASSERT_PROPERTY(eCIlluminated_PS, m_bReciveShadows, 0x21, 1)
GE_ASSERT_PROPERTY(eCIlluminated_PS, m_eDirectionalShadowType, 0x24, 8)
GE_ASSERT_PROPERTY(eCIlluminated_PS, m_bReciveTreeShadows, 0x2c, 1)
GE_ASSERT_PROPERTY(eCIlluminated_PS, m_bCastStaticShadows, 0x2d, 1)
GE_ASSERT_PROPERTY(eCIlluminated_PS, m_bReciveStaticShadows, 0x2e, 1)
