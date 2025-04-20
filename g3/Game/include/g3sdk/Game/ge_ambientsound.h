#pragma once

#include <Engine.h>

struct gSAmbientSound
{
    GE_UNIMPL_STRUCT(gSAmbientSound)
};

class GE_DLLIMPORT gCAmbientSound : public bCObjectRefBase
{
    // clang-format off
    protected: virtual void OnSampleChanged();
    public: virtual gCAmbientSound * Clone() const;
    public: void Destroy() override;
    public: ~gCAmbientSound() override;
    protected: bEResult PostInitializeProperties() override;
    protected: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCAmbientSound, bCObjectRefBase)
    GE_ENUMPROP(eEAmbientClimate, Climate, m_enuClimate)
    GE_ENUMPROP(eEAmbientEnvironment, Environment, m_enuEnvironment)
    GE_ENUMPROP(eEAmbientDayTime, DayTime, m_enuDayTime)
    GE_PROPERTY(bCString, Sample, m_strSample)
    GE_PROPERTY(GEFloat, Volume, m_fVolume)
    GE_PROPERTY(GEFloat, MinDistance, m_fMinDistance)
    GE_PROPERTY(GEFloat, MaxDistance, m_fMaxDistance)
    GE_PROPERTY(GEInt, Weight, m_iWeight)
    GE_PROPERTY(GEU32, Duration, m_u32Duration)

  public:
    void GetDescriptor(gSAmbientSound &) const;
    void SetDescriptor(gSAmbientSound const &);

  protected:
    void Invalidate();
    void UpdateDuration();
};

GE_ASSERT_SIZEOF(gCAmbientSound, 0x3c)

GE_ASSERT_PROPERTY(gCAmbientSound, m_enuClimate, 0xc, 8)
GE_ASSERT_PROPERTY(gCAmbientSound, m_enuEnvironment, 0x14, 8)
GE_ASSERT_PROPERTY(gCAmbientSound, m_enuDayTime, 0x1c, 8)
GE_ASSERT_PROPERTY(gCAmbientSound, m_strSample, 0x24, 4)
GE_ASSERT_PROPERTY(gCAmbientSound, m_fVolume, 0x28, 4)
GE_ASSERT_PROPERTY(gCAmbientSound, m_fMinDistance, 0x2c, 4)
GE_ASSERT_PROPERTY(gCAmbientSound, m_fMaxDistance, 0x30, 4)
GE_ASSERT_PROPERTY(gCAmbientSound, m_iWeight, 0x34, 4)
GE_ASSERT_PROPERTY(gCAmbientSound, m_u32Duration, 0x38, 4)
