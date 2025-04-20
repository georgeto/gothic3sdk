#pragma once

#include <SharedBase.h>

struct gSAmbientEnvironment
{
    GE_UNIMPL_STRUCT(gSAmbientEnvironment)
};

class GE_DLLIMPORT gCAmbientEnvironment : public bCObjectRefBase
{
    // clang-format off
    public: virtual gCAmbientEnvironment * Clone() const;
    public: void Destroy() override;
    public: ~gCAmbientEnvironment() override;
    protected: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCAmbientEnvironment, bCObjectRefBase)
    GE_PROPERTY(GEInt, MinNumSounds, m_iMinNumSounds)
    GE_PROPERTY(GEInt, MaxNumSounds, m_iMaxNumSounds)
    GE_PROPERTY(GEFloat, MinSpawnDelay, m_fMinSpawnDelay)
    GE_PROPERTY(GEFloat, MaxSpawnDelay, m_fMaxSpawnDelay)
    GE_PROPERTY(GEFloat, SpawnProbability, m_fSpawnProbability)

  public:
    void GetDescriptor(gSAmbientEnvironment &) const;
    void SetDescriptor(gSAmbientEnvironment const &);

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCAmbientEnvironment, 0x20)

GE_ASSERT_PROPERTY(gCAmbientEnvironment, m_iMinNumSounds, 0xc, 4)
GE_ASSERT_PROPERTY(gCAmbientEnvironment, m_iMaxNumSounds, 0x10, 4)
GE_ASSERT_PROPERTY(gCAmbientEnvironment, m_fMinSpawnDelay, 0x14, 4)
GE_ASSERT_PROPERTY(gCAmbientEnvironment, m_fMaxSpawnDelay, 0x18, 4)
GE_ASSERT_PROPERTY(gCAmbientEnvironment, m_fSpawnProbability, 0x1c, 4)
