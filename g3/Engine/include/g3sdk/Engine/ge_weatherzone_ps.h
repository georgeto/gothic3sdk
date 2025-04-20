#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/entity/ge_entitypropertyset.h>
#include <Engine/ge_staticpointlight_ps.h>
#include <Engine/ge_weatherstates.h>

#include <SharedBase.h>

class eCPrimitiveWeatherZoneBox
{
    GE_UNIMPL_STRUCT(eCPrimitiveWeatherZoneBox)
};

class eCPrimitiveWeatherZoneRadius
{
    GE_UNIMPL_STRUCT(eCPrimitiveWeatherZoneRadius)
};

class eCPrimitiveWeatherZoneRect
{
    GE_UNIMPL_STRUCT(eCPrimitiveWeatherZoneRect)
};

class GE_DLLIMPORT eCWeatherZone_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCWeatherZone_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool NotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    protected: GEBool IsVisual() const override;
    protected: void OnEnterProcessingRange() override;
    protected: void OnExitProcessingRange() override;
    protected: void OnRenderDebug() override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnPropertySetAdded() override;
    protected: GEBool IntersectsRay(eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc **) const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCWeatherZone_PS, eCEntityPropertySet)
    GE_ENUMPROP(eEWeatherZoneShape, Shape, m_eShape)
    GE_PROPERTY(GEFloat, InnerRadius, m_fInnerRadius)
    GE_PROPERTY(GEFloat, OuterRadius, m_fOuterRadius)
    GE_PROPERTY(bCVector, InnerExtends, m_vecInnerExtends)
    GE_PROPERTY(bCVector, OuterExtends, m_vecOuterExtends)
    GE_PROPERTY(bCString, WeatherEnvironment, m_strWeatherEnvironment)
    GE_ENUMPROP(eEWeatherZoneOverwrite, LightIntensityOverwrite, m_eLightIntensityOverwrite)
    GE_PROPERTY(GEFloat, LightIntensity, m_fLightIntensity)
    GE_ENUMPROP(eEWeatherZoneOverwrite, LightDiffuseOverwrite, m_eLightDiffuseOverwrite)
    GE_PROPERTY(bCFloatColor, LightDiffuseColor, m_colLightDiffuse)
    GE_ENUMPROP(eEWeatherZoneOverwrite, LightSpecularOverwrite, m_eLightSpecularOverwrite)
    GE_PROPERTY(bCFloatColor, LightSpecularColor, m_colLightSpecular)
    GE_ENUMPROP(eEWeatherZoneOverwrite, AmbientBackLightOverwrite, m_eAmbientBackLightOverwrite)
    GE_PROPERTY(bCFloatColor, AmbientBackLightColor, m_colAmbientBackLight)
    GE_ENUMPROP(eEWeatherZoneOverwrite, AmbientGeneralOverwrite, m_eAmbientGeneralOverwrite)
    GE_PROPERTY(bCFloatColor, AmbientGeneralColor, m_colAmbientGeneral)
    GE_ENUMPROP(eEWeatherZoneOverwrite, AmbientIntensityOverwrite, m_eAmbientIntensityOverwrite)
    GE_PROPERTY(GEFloat, AmbientIntensity, m_fAmbientIntensity)
    GE_ENUMPROP(eEWeatherZoneOverwrite, FogColorOverwrite, m_eFogColorOverwrite)
    GE_PROPERTY(bCFloatColor, FogColor, m_colFogColor)
    GE_ENUMPROP(eEWeatherZoneOverwrite, FogStartrOverwrite, m_eFogStartOverwrite)
    GE_PROPERTY(GEFloat, FogStart, m_fFogStart)
    GE_ENUMPROP(eEWeatherZoneOverwrite, FogEndrOverwrite, m_eFogEndOverwrite)
    GE_PROPERTY(GEFloat, FogEnd, m_fFogEnd)
    GE_ENUMPROP(eEWeatherZoneOverwrite, SkyColorOverwrite, m_eSkyColorOverwrite)
    GE_PROPERTY(bCFloatColor, SkyColor, m_colSkyColor)
    GE_ENUMPROP(eEWeatherZoneOverwrite, HazeColorOverwrite, m_eHazeColorOverwrite)
    GE_PROPERTY(bCFloatColor, HazeColor, m_colHazeColor)
    GE_ENUMPROP(eEWeatherZoneOverwrite, CloudColorOverwrite, m_eCloudColorOverwrite)
    GE_PROPERTY(bCFloatColor, CloudColor, m_colCloudColor)
    GE_ENUMPROP(eEWeatherZoneOverwrite, CloudThicknessrOverwrite, m_eCloudThicknessOverwrite)
    GE_PROPERTY(GEFloat, CloudThickness, m_fCloudThickness)
    GE_PROPERTY(bCString, MusicLocation, m_strMusicLocation)

  public:
    GEBool AddWeatherStateBlending(GEFloat, eCWeatherStates::eCWeatherState &);
    GEFloat GetBlendFactor(bCVector const &) const;

  protected:
    static eCPrimitiveWeatherZoneBox ms_BoxInnerExtendsPrimitive;
    static eCPrimitiveWeatherZoneBox ms_BoxOuterExtendsPrimitive;
    static eCPrimitiveWeatherZoneRadius ms_CircleInnerRadiusPrimitive;
    static eCPrimitiveWeatherZoneRadius ms_CircleOuterRadiusPrimitive;
    static eCPrimitiveWeatherZoneRect ms_RectInnerExtendsPrimitive;
    static eCPrimitiveWeatherZoneRect ms_RectOuterExtendsPrimitive;
    static eCPrimitivePointLightRadius ms_SphereInnerRadiusPrimitive;
    static eCPrimitivePointLightRadius ms_SphereOuterRadiusPrimitive;

  protected:
    void DoOverwrite(eEWeatherZoneOverwrite, GEFloat &, GEFloat const &);
    void DoOverwrite(eEWeatherZoneOverwrite, bCFloatColor &, bCFloatColor const &);
    void DoOverwrites(eCWeatherStates::eCWeatherState &);
    GEFloat GetBoxBlendFactor(bCVector const &) const;
    GEFloat GetCircleBlendFactor(bCVector const &) const;
    GEFloat GetRectBlendFactor(bCVector const &) const;
    GEFloat GetSphereBlendFactor(bCVector const &) const;
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCWeatherZone_PS, 0x140)

GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_eShape, 0x14, 8)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_fInnerRadius, 0x1c, 4)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_fOuterRadius, 0x20, 4)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_vecInnerExtends, 0x24, 12)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_vecOuterExtends, 0x30, 12)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_strWeatherEnvironment, 0x3c, 4)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_eLightIntensityOverwrite, 0x40, 8)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_fLightIntensity, 0x48, 4)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_eLightDiffuseOverwrite, 0x4c, 8)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_colLightDiffuse, 0x54, 16)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_eLightSpecularOverwrite, 0x64, 8)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_colLightSpecular, 0x6c, 16)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_eAmbientBackLightOverwrite, 0x7c, 8)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_colAmbientBackLight, 0x84, 16)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_eAmbientGeneralOverwrite, 0x94, 8)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_colAmbientGeneral, 0x9c, 16)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_eAmbientIntensityOverwrite, 0xac, 8)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_fAmbientIntensity, 0xb4, 4)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_eFogColorOverwrite, 0xb8, 8)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_colFogColor, 0xc0, 16)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_eFogStartOverwrite, 0xd0, 8)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_fFogStart, 0xd8, 4)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_eFogEndOverwrite, 0xdc, 8)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_fFogEnd, 0xe4, 4)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_eSkyColorOverwrite, 0xe8, 8)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_colSkyColor, 0xf0, 16)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_eHazeColorOverwrite, 0x100, 8)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_colHazeColor, 0x108, 16)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_eCloudColorOverwrite, 0x118, 8)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_colCloudColor, 0x120, 16)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_eCloudThicknessOverwrite, 0x130, 8)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_fCloudThickness, 0x138, 4)
GE_ASSERT_PROPERTY(eCWeatherZone_PS, m_strMusicLocation, 0x13c, 4)
