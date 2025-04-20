#pragma once

#include <Engine/ge_dynamiclight_ps.h>
#include <Engine/ge_staticpointlight_ps.h>

#include <SharedBase.h>

class eCShadowMapPointLight;

class GE_DLLIMPORT eCPointLight_PS : public eCDynamicLight_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCPointLight_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    protected: GEBool IsVisual() const override;
    protected: GEBool IsProcessable() const override;
    public: GEBool SupportsRenderDebugOutput() const override;
    public: void Decay() override;
    protected: void OnRenderDebug() override;
    protected: void OnUpdateInternals() override;
    protected: void OnUpdatedWorldMatrix() override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnProcess() override;
    protected: void OnPostRead() override;
    protected: void OnChildrenAvailable(GEU32, GEU32, eCTemplateEntity *) override;
    protected: GEBool IntersectsRay(eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc **) const override;
    protected: GEBool IntersectsVolume(bCVolume &, bCMatrix const &, bTValArray<bCTriangle> *, GEBool) const override;
    public: void UpdateEffectedObjects() override;
    public: GEBool IsBoxInRange(bCBox const &) override;
    public: void UpdateShadowMaps() override;
    public: bEResult ResetResources(GEBool) override;
    public: bEResult RestoreResources(GEBool) override;
    public: void OnEffectedObjectMoved(eCIlluminated_PS *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCPointLight_PS, eCDynamicLight_PS)
    GE_PROPERTY(bCFloatColor, Color, m_Color)
    GE_PROPERTY(bCFloatColor, EffectColor, m_EffectColor)
    GE_PROPERTY(bCFloatColor, SpecularColor, m_SpecularColor)
    GE_PROPERTY(GEFloat, Range, m_fRange)
    GE_PROPERTY(bCVector, PositionOffset, m_vecPositionOffset)
    GE_PROPERTY(GEFloat, Intensity, m_fIntensity)
    GE_ENUMPROP(eEDynamicLightEffect, Effect, m_eEffect)
    GE_PROPERTY(GEFloat, EffectPhase, m_fEffectPhase)
    GE_PROPERTY(GEFloat, EffectPeriod, m_fEffectPeriod)
    GE_PROPERTY(GEBool, CastShadows, m_bCastShadows)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, DecayDuration, m_fDecayDuration)

  public:
    void GetAttenuations(GEFloat &, GEFloat &, GEFloat &);
    GEFloat GetEffectIntensity() const;
    bCVector const &GetPosition();
    void GetShadowCaster(bTValArray<eCEntity *> &);
    eCShadowMapPointLight *GetShadowMap() const;

  protected:
    static GEInt m_iPointLightShadowMaps;
    static eCPrimitivePointLightCenter ms_CenterPrimitive;
    static eCPrimitivePointLightRadius ms_RadiusPrimitive;

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(68)
};

GE_ASSERT_SIZEOF(eCPointLight_PS, 0xc4)

GE_ASSERT_PROPERTY(eCPointLight_PS, m_Color, 0x24, 16)
GE_ASSERT_PROPERTY(eCPointLight_PS, m_EffectColor, 0x34, 16)
GE_ASSERT_PROPERTY(eCPointLight_PS, m_SpecularColor, 0x44, 16)
GE_ASSERT_PROPERTY(eCPointLight_PS, m_fRange, 0x54, 4)
GE_ASSERT_PROPERTY(eCPointLight_PS, m_vecPositionOffset, 0x58, 12)
GE_ASSERT_PROPERTY(eCPointLight_PS, m_fIntensity, 0x64, 4)
GE_ASSERT_PROPERTY(eCPointLight_PS, m_eEffect, 0x68, 8)
GE_ASSERT_PROPERTY(eCPointLight_PS, m_fEffectPhase, 0x70, 4)
GE_ASSERT_PROPERTY(eCPointLight_PS, m_fEffectPeriod, 0x74, 4)
GE_ASSERT_PROPERTY(eCPointLight_PS, m_bCastShadows, 0x78, 1)
GE_ASSERT_PROPERTY(eCPointLight_PS, m_fDecayDuration, 0x7c, 4)
