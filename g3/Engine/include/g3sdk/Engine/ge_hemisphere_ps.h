#pragma once

#include <Engine/ge_dynamiclight_ps.h>
#include <Engine/ge_shadermaterialadmin.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCHemisphere_PS : public eCDynamicLight_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCHemisphere_PS() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    protected: void OnUpdatedWorldMatrix() override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnProcess() override;
    protected: void OnPostRead() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCHemisphere_PS, eCDynamicLight_PS)
    GE_PROPERTY(bCFloatColor, GeneralAmbient, m_colGeneralAmbient)
    GE_PROPERTY(bCFloatColor, BackLight, m_colBackLight)
    GE_PROPERTY(bCFloatColor, GroundLight, m_colGroundLight)
    GE_PROPERTY(bCEulerAngles, BackLightAxisDirectionOffset, m_BackLightAxisDirectionOffset)
    GE_PROPERTY(GEFloat, Intensity, m_fIntensity)
    GE_PROPERTY(bCFloatColor, SunLight, m_colSunLight)
    GE_PROPERTY(bCEulerAngles, SunLightAxisDirectionOffset, m_SunLightAxisDirectionOffset)

  public:
    bTSphericalHarmonics2<bCVector4> const &GetSphericalHarmonics() const;
    void UpdateSHHemisphere();

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(68)
};

GE_ASSERT_SIZEOF(eCHemisphere_PS, 0xc4)

GE_ASSERT_PROPERTY(eCHemisphere_PS, m_colGeneralAmbient, 0x24, 16)
GE_ASSERT_PROPERTY(eCHemisphere_PS, m_colBackLight, 0x34, 16)
GE_ASSERT_PROPERTY(eCHemisphere_PS, m_colGroundLight, 0x44, 16)
GE_ASSERT_PROPERTY(eCHemisphere_PS, m_BackLightAxisDirectionOffset, 0x54, 12)
GE_ASSERT_PROPERTY(eCHemisphere_PS, m_fIntensity, 0x60, 4)
GE_ASSERT_PROPERTY(eCHemisphere_PS, m_colSunLight, 0x64, 16)
GE_ASSERT_PROPERTY(eCHemisphere_PS, m_SunLightAxisDirectionOffset, 0x74, 12)
