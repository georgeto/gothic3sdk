#pragma once

#include <Engine.h>

class gCAmbientEnvironment;
class gCAmbientSound;

class GE_DLLIMPORT gCAmbientSequencer : public bCObjectRefBase
{
    // clang-format off
    public: void Destroy() override;
    public: ~gCAmbientSequencer() override;
    protected: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCAmbientSequencer, bCObjectRefBase)
    GE_ENUMPROP(eEAmbientClimate, Climate, m_enuClimate)
    GE_ENUMPROP(eEAmbientEnvironment, Environment, m_enuEnvironment)
    GE_ENUMPROP(eEAmbientDayTime, DayTime, m_enuDayTime)

  public:
    void Process(GEFloat);

  protected:
    void DestroyChannels();
    eCAudioChannel *FindChannel();
    eCEntity const *FindObject() const;
    gCAmbientSound *FindSound() const;
    eCAudioChannel *FindWaterChannel();
    gCAmbientEnvironment *GetActiveEnvironment() const;
    GEInt GetCountPlaying() const;
    GEInt GetCountWaterPlaying() const;
    void Init();
    void Invalidate();
    GEBool SpawnSound();
    GEBool UpdateWaterSounds();

  private:
    GE_UNIMPL_MEMBERS(52)
};

GE_ASSERT_SIZEOF(gCAmbientSequencer, 0x58)

GE_ASSERT_PROPERTY(gCAmbientSequencer, m_enuClimate, 0xc, 8)
GE_ASSERT_PROPERTY(gCAmbientSequencer, m_enuEnvironment, 0x14, 8)
GE_ASSERT_PROPERTY(gCAmbientSequencer, m_enuDayTime, 0x1c, 8)
