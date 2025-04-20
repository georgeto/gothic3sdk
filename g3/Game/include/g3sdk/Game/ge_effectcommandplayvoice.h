#pragma once

#include <Game/ge_effectcommand.h>

#include <Engine.h>

struct gSEffectCommand_PlayVoice
{
    GE_UNIMPL_STRUCT(gSEffectCommand_PlayVoice)
};

class GE_DLLIMPORT gCEffectCommandPlayVoice : public gCEffectCommand
{
    // clang-format off
    public: void Destroy() override;
    public: ~gCEffectCommandPlayVoice() override;
    public: gEEffectCommand GetCommandType() const override;
    public: void Execute(eCEntity *, eCEntity *, bCMatrix const *, bTObjMap<GEInt, eCEntityProxy> &, bTObjArray<eCEntityProxy> &, GEBool) const override;
    public: gCEffectCommand * Clone() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCEffectCommandPlayVoice, gCEffectCommand)
    GE_PROPERTY(GEFloat, Volume, m_fVolume)           // Read only
    GE_PROPERTY(GEFloat, MinDistance, m_fMinDistance) // Read only
    GE_PROPERTY(GEFloat, MaxDistance, m_fMaxDistance) // Read only
    GE_PROPERTY(bCString, Sample, m_strSample)

  public:
    void GetDescriptor(gSEffectCommand_PlayVoice &) const;
    void SetDescriptor(gSEffectCommand_PlayVoice const &);

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCEffectCommandPlayVoice, 0x20)

GE_ASSERT_PROPERTY(gCEffectCommandPlayVoice, m_fVolume, 0x10, 4)
GE_ASSERT_PROPERTY(gCEffectCommandPlayVoice, m_fMinDistance, 0x14, 4)
GE_ASSERT_PROPERTY(gCEffectCommandPlayVoice, m_fMaxDistance, 0x18, 4)
GE_ASSERT_PROPERTY(gCEffectCommandPlayVoice, m_strSample, 0x1c, 4)
