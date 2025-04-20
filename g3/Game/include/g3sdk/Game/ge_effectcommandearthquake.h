#pragma once

#include <Game/ge_effectcommand.h>

#include <Engine.h>

struct gSEffectCommand_EarthQuake
{
    GE_UNIMPL_STRUCT(gSEffectCommand_EarthQuake)
};

class GE_DLLIMPORT gCEffectCommandEarthquake : public gCEffectCommand
{
    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~gCEffectCommandEarthquake() override;
    public: gEEffectCommand GetCommandType() const override;
    public: void Execute(eCEntity *, eCEntity *, bCMatrix const *, bTObjMap<GEInt, eCEntityProxy> &, bTObjArray<eCEntityProxy> &, GEBool) const override;
    public: gCEffectCommand * Clone() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCEffectCommandEarthquake, gCEffectCommand)
    GE_PROPERTY(GEFloat, Radius, m_fRadius)
    GE_PROPERTY(GEFloat, Frequency, m_fFrequency)
    GE_PROPERTY(GEFloat, Duration, m_fDuration)
    GE_PROPERTY(bCVector, Amplitude, m_vecAmplitude)

  public:
    void GetDescriptor(gSEffectCommand_EarthQuake &) const;
    void SetDescriptor(gSEffectCommand_EarthQuake const &);

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCEffectCommandEarthquake, 0x28)

GE_ASSERT_PROPERTY(gCEffectCommandEarthquake, m_fRadius, 0x10, 4)
GE_ASSERT_PROPERTY(gCEffectCommandEarthquake, m_fFrequency, 0x14, 4)
GE_ASSERT_PROPERTY(gCEffectCommandEarthquake, m_fDuration, 0x18, 4)
GE_ASSERT_PROPERTY(gCEffectCommandEarthquake, m_vecAmplitude, 0x1c, 12)
