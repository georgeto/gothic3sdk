#pragma once

#include <Engine/entity/ge_entitypropertyset.h>
#include <Engine/ge_stringwrapper.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCPrecipitation_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCPrecipitation_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsVisual() const override;
    protected: GEBool IsProcessable() const override;
    public: GEBool IsEditorRelevant() const override;
    protected: GEBool HasRenderAlphaComponent() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    protected: void OnRenderAlpha(GEI16) override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCPrecipitation_PS, eCEntityPropertySet)
    GE_PROPERTY(bCImageResourceString, Texture, m_strTexture)
    GE_PROPERTY(GEFloat, PrecipitationCubeSize, m_fPrecipitationCubeSize)
    GE_PROPERTY(GEU32, MaxParticles, m_u32MaxParticles)
    GE_PROPERTY(GEInt, ParticlesPerSecond, m_iParticlesPerSecond)
    GE_PROPERTY(bCVector, Direction, m_vecDirection)
    GE_PROPERTY(bCVector2, SpeedMinMax, m_vecSpeedMinMax)
    GE_PROPERTY(bCVector2, Size, m_vecSize)
    GE_PROPERTY(GEU32, MaxSpawnPoints, m_u32MaxSpawnPoints)
    GE_PROPERTY(GEFloat, DirectionScale, m_fDirectionScale)
    GE_PROPERTY(GEInt, TextureTileCountU, m_iTextureTileCountU)
    GE_PROPERTY(GEInt, TextureTileCountV, m_iTextureTileCountV)
    GE_PROPERTY(GEInt, CurrentTextureTile, m_iCurrentTextureTile)
    GE_PROPERTY(GEFloat, SpawnPointDizzer, m_fSpawnPointDizzer)
    GE_PROPERTY(GEFloat, JitterPower, m_fJitterPower)
    GE_PROPERTY(GEFloat, JitterSpeed, m_fJitterSpeed)
    GE_PROPERTY(GEFloat, SplashDuration, m_fSplashDuration)
    GE_PROPERTY(GEInt, SplashTextureTile, m_iSplashTextureTile)
    GE_PROPERTY(bCVector2, SplashSizeScale, m_vecSplashSizeScale)

  public:
    GEInt GetNumParticlesAlive() const;
    void OnResetResources();

  protected:
    GEBool CreateShader();
    void Invalidate();
    void Update(bCVector const &);

  private:
    GE_UNIMPL_MEMBERS(100)
};

GE_ASSERT_SIZEOF(eCPrecipitation_PS, 0xd4)

GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_strTexture, 0x14, 4)
GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_fPrecipitationCubeSize, 0x18, 4)
GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_u32MaxParticles, 0x1c, 4)
GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_iParticlesPerSecond, 0x20, 4)
GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_vecDirection, 0x24, 12)
GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_vecSpeedMinMax, 0x30, 8)
GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_vecSize, 0x38, 8)
GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_u32MaxSpawnPoints, 0x40, 4)
GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_fDirectionScale, 0x44, 4)
GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_iTextureTileCountU, 0x48, 4)
GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_iTextureTileCountV, 0x4c, 4)
GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_iCurrentTextureTile, 0x50, 4)
GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_fSpawnPointDizzer, 0x54, 4)
GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_fJitterPower, 0x58, 4)
GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_fJitterSpeed, 0x5c, 4)
GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_fSplashDuration, 0x60, 4)
GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_iSplashTextureTile, 0x64, 4)
GE_ASSERT_PROPERTY(eCPrecipitation_PS, m_vecSplashSizeScale, 0x68, 8)
