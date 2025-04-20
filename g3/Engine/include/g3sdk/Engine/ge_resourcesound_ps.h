#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class eCAudioSound;
struct eSResourceSoundSample;

class GE_DLLIMPORT eCResourceSound_PS : public eCResourceBase_PS
{
    // clang-format off
    public: virtual GEInt GetSampleCount() const;
    public: virtual GEBool GetSampleDescriptor(GEInt, eSResourceSoundSample &) const;
    public: virtual GEBool SetSampleDescriptor(GEInt, eSResourceSoundSample const &);
    public: virtual GEInt InsertSample(GEInt, eSResourceSoundSample const &);
    public: virtual GEBool RemoveSample(GEInt);
    public: virtual eCAudioSound * GetSound() const;
    public: virtual eCAudioSound * GetSound(GEInt) const;
    public: virtual void ApplyDefaults();
    public: GEU16 GetVersion() const override;
    protected: bEResult Write(bCOStream &) override;
    protected: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceSound_PS() override;
    public: bCString const & GetProprietaryFileExt() const override;
    public: bCString const & GetNativeFileExt() const override;
    public: eCResourceBase_PS::eECacheType GetCacheType() const override;
    public: bEResult DoLoad() override;
    public: bEResult DoUnload() override;
    public: bEResult DoReload() override;
    public: bEResult DoConvert() override;
    public: bEResult DoSave() override;
    public: void CalculateSize() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCResourceSound_PS, eCResourceBase_PS)
    GE_PROPERTY(GEBool, UseStream, m_bUseStream)
    GE_PROPERTY(GEBool, UseHardware, m_bUseHardware)
    GE_PADDING(2)
    GE_PROPERTY(GEFloat, Volume, m_fVolume)
    GE_PROPERTY(GEFloat, Pan, m_fPan)
    GE_PROPERTY(GEFloat, Frequency, m_fFrequency)
    GE_PROPERTY(GEU8, Priority, m_u8Priority)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, VolumeVariance, m_fVolumeVariance)
    GE_PROPERTY(GEFloat, PanVariance, m_fPanVariance)
    GE_PROPERTY(GEFloat, FrequencyVariance, m_fFrequencyVariance)
    GE_ENUMPROP(eESoundLoopMode, LoopMode, m_enuLoopMode)
    GE_PROPERTY(GEI32, LoopRepeats, m_i32LoopRepeats)
    GE_PROPERTY(GEBool, LoopForever, m_bLoopForever)
    GE_PROPERTY(GEBool, Use3D, m_bUse3D)
    GE_PROPERTY(GEBool, UseLinearRollOff, m_bUseLinearRollOff)
    GE_PADDING(1)
    GE_PROPERTY(GEFloat, MinDistance, m_fMinDistance)
    GE_PROPERTY(GEFloat, MaxDistance, m_fMaxDistance)
    GE_PROPERTY(GEFloat, InsideConeAngle, m_fInsideConeAngle)
    GE_PROPERTY(GEFloat, OutsideConeAngle, m_fOutsideConeAngle)
    GE_PROPERTY(GEFloat, OutsideConeVolume, m_fOutsideConeVolume)

  public:
    void RemoveAllSamples();

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCResourceSound_PS, 0x70)

GE_ASSERT_PROPERTY(eCResourceSound_PS, m_bUseStream, 0x2c, 1)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_bUseHardware, 0x2d, 1)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_fVolume, 0x30, 4)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_fPan, 0x34, 4)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_fFrequency, 0x38, 4)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_u8Priority, 0x3c, 1)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_fVolumeVariance, 0x40, 4)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_fPanVariance, 0x44, 4)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_fFrequencyVariance, 0x48, 4)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_enuLoopMode, 0x4c, 8)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_i32LoopRepeats, 0x54, 4)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_bLoopForever, 0x58, 1)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_bUse3D, 0x59, 1)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_bUseLinearRollOff, 0x5a, 1)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_fMinDistance, 0x5c, 4)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_fMaxDistance, 0x60, 4)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_fInsideConeAngle, 0x64, 4)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_fOutsideConeAngle, 0x68, 4)
GE_ASSERT_PROPERTY(eCResourceSound_PS, m_fOutsideConeVolume, 0x6c, 4)
