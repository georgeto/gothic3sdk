#pragma once

#include <Engine/ge_dynamiclight_ps.h>

#include <SharedBase.h>

class eCShadowMapDirectionalLight;
class eCShadowMapDirectionalLightLsPSM;

class GE_DLLIMPORT eCDirectionalLight_PS : public eCDynamicLight_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCDirectionalLight_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    protected: void OnRender(GEI16) override;
    protected: void OnUpdatedWorldMatrix() override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnProcess() override;
    protected: void OnPostRead() override;
    public: void UpdateShadowMaps() override;
    public: void OnShadowSettingsChanged() override;
    public: bEResult ResetResources(GEBool) override;
    public: bEResult RestoreResources(GEBool) override;
    public: void OnEffectedObjectRemoved(eCIlluminated_PS *) override;
    public: void OnEffectedObjectAdded(eCIlluminated_PS *) override;
    public: void OnEffectedObjectMoved(eCIlluminated_PS *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCDirectionalLight_PS, eCDynamicLight_PS)
    GE_PROPERTY(bCFloatColor, Color, m_Color)
    GE_PROPERTY(bCFloatColor, SpecularColor, m_SpecularColor)
    GE_PROPERTY(GEFloat, Intensity, m_fIntensity)
    GE_PROPERTY(bCEulerAngles, DirectionOffset, m_DirectionOffset)
    GE_PROPERTY(GEBool, CastShadows, m_bCastShadows)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, ShadowDensity, m_fShadowDensity)

  public:
    bCVector const &GetDirection();
    eCShadowMapDirectionalLightLsPSM *GetLsPSM() const;
    bCVector const &GetShadowMapDirection();
    bTValArray<eCShadowMapDirectionalLight *> const GetShadowMaps() const;

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(80)
};

GE_ASSERT_SIZEOF(eCDirectionalLight_PS, 0xac)

GE_ASSERT_PROPERTY(eCDirectionalLight_PS, m_Color, 0x24, 16)
GE_ASSERT_PROPERTY(eCDirectionalLight_PS, m_SpecularColor, 0x34, 16)
GE_ASSERT_PROPERTY(eCDirectionalLight_PS, m_fIntensity, 0x44, 4)
GE_ASSERT_PROPERTY(eCDirectionalLight_PS, m_DirectionOffset, 0x48, 12)
GE_ASSERT_PROPERTY(eCDirectionalLight_PS, m_bCastShadows, 0x54, 1)
GE_ASSERT_PROPERTY(eCDirectionalLight_PS, m_fShadowDensity, 0x58, 4)
