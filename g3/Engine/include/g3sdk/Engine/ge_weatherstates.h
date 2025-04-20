#pragma once

#include <SharedBase.h>

class eCColorScale;
class eCFloatScale;

class GE_DLLIMPORT eCWeatherStates : public bCObjectRefBase
{
  public:
    class eCWeatherState
    {
        GE_UNIMPL_STRUCT(eCWeatherState)
    };

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCWeatherStates() override;
    public: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCWeatherStates, bCObjectRefBase)
    GE_PROPERTY(GEInt, ParticlesPerSecond, m_iParticlesPerSecond)
    GE_PROPERTY(bCVector2, SpeedMinMax, m_vecSpeedMinMax)
    GE_PROPERTY(bCVector2, Size, m_vecSize)
    GE_PROPERTY(GEFloat, DirectionScale, m_fDirectionScale)
    GE_PROPERTY(GEInt, CurrentTextureTile, m_iCurrentTextureTile)
    GE_PROPERTY(GEFloat, SpawnPointDizzer, m_fSpawnPointDizzer)
    GE_PROPERTY(GEFloat, JitterPower, m_fJitterPower)
    GE_PROPERTY(GEFloat, JitterSpeed, m_fJitterSpeed)
    GE_PROPERTY(GEFloat, SplashDuration, m_fSplashDuration)
    GE_PROPERTY(GEInt, SplashTextureTile, m_iSplashTextureTile)
    GE_PROPERTY(bCVector2, SplashSizeScale, m_vecSplashSizeScale)
    GE_PROPERTY(bCString, LoopSample, m_strLoopSample) // Read only
    GE_PROPERTY(GEFloat, LoopVolume, m_fLoopVolume)    // Read only

  public:
    eCColorScale &GetAmbientBackLightColor();
    eCColorScale const &GetAmbientBackLightColor() const;
    eCColorScale &GetAmbientGeneralColor();
    eCColorScale const &GetAmbientGeneralColor() const;
    eCFloatScale &GetAmbientIntensity();
    eCFloatScale const &GetAmbientIntensity() const;
    GEFloat GetBlendFactor() const;
    eCColorScale &GetCloudColor();
    eCColorScale const &GetCloudColor() const;
    eCFloatScale &GetCloudThickness();
    eCFloatScale const &GetCloudThickness() const;
    eCWeatherState const &GetCurrentState() const;
    eCColorScale &GetFogColor();
    eCColorScale const &GetFogColor() const;
    eCFloatScale &GetFogEnd();
    eCFloatScale const &GetFogEnd() const;
    eCFloatScale &GetFogStart();
    eCFloatScale const &GetFogStart() const;
    eCFloatScale &GetGlowIntensity();
    eCFloatScale const &GetGlowIntensity() const;
    eCColorScale &GetHazeColor();
    eCColorScale const &GetHazeColor() const;
    eCColorScale &GetLightDiffuseColor();
    eCColorScale const &GetLightDiffuseColor() const;
    eCFloatScale &GetLightIntensity();
    eCFloatScale const &GetLightIntensity() const;
    eCColorScale &GetLightSpecularColor();
    eCColorScale const &GetLightSpecularColor() const;
    bCString const &GetName() const;
    eCFloatScale &GetShadowDensity();
    eCFloatScale const &GetShadowDensity() const;
    eCColorScale &GetSkyColor();
    eCColorScale const &GetSkyColor() const;
    eCFloatScale &GetTemperature();
    eCFloatScale const &GetTemperature() const;
    void SetBlendFactor(GEFloat);
    void SetCurrentDayTime(GEFloat);
    GEBool SetName(bCString const &);
    void UpdateLoopSound();

  protected:
    void Invalidate();
    void StartSound();
    void StopSound();

  private:
    GE_UNIMPL_MEMBERS(368)
};

GE_ASSERT_SIZEOF(eCWeatherStates, 0x1bc)

GE_ASSERT_PROPERTY(eCWeatherStates, m_iParticlesPerSecond, 0xc, 4)
GE_ASSERT_PROPERTY(eCWeatherStates, m_vecSpeedMinMax, 0x10, 8)
GE_ASSERT_PROPERTY(eCWeatherStates, m_vecSize, 0x18, 8)
GE_ASSERT_PROPERTY(eCWeatherStates, m_fDirectionScale, 0x20, 4)
GE_ASSERT_PROPERTY(eCWeatherStates, m_iCurrentTextureTile, 0x24, 4)
GE_ASSERT_PROPERTY(eCWeatherStates, m_fSpawnPointDizzer, 0x28, 4)
GE_ASSERT_PROPERTY(eCWeatherStates, m_fJitterPower, 0x2c, 4)
GE_ASSERT_PROPERTY(eCWeatherStates, m_fJitterSpeed, 0x30, 4)
GE_ASSERT_PROPERTY(eCWeatherStates, m_fSplashDuration, 0x34, 4)
GE_ASSERT_PROPERTY(eCWeatherStates, m_iSplashTextureTile, 0x38, 4)
GE_ASSERT_PROPERTY(eCWeatherStates, m_vecSplashSizeScale, 0x3c, 8)
GE_ASSERT_PROPERTY(eCWeatherStates, m_strLoopSample, 0x44, 4)
GE_ASSERT_PROPERTY(eCWeatherStates, m_fLoopVolume, 0x48, 4)
