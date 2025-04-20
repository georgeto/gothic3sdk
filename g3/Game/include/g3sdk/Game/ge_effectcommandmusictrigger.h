#pragma once

#include <Game/GameEnum.h>
#include <Game/ge_effectcommand.h>

#include <Engine.h>

struct gSEffectCommand_MusicTrigger
{
    GE_UNIMPL_STRUCT(gSEffectCommand_MusicTrigger)
};

class GE_DLLIMPORT gCEffectCommandMusicTrigger : public gCEffectCommand
{
    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~gCEffectCommandMusicTrigger() override;
    public: gEEffectCommand GetCommandType() const override;
    public: void Execute(eCEntity *, eCEntity *, bCMatrix const *, bTObjMap<GEInt, eCEntityProxy> &, bTObjArray<eCEntityProxy> &, GEBool) const override;
    public: gCEffectCommand * Clone() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCEffectCommandMusicTrigger, gCEffectCommand)
    GE_PROPERTY(bCString, Location, m_strLocation)
    GE_PROPERTY(bCString, Situation, m_strSituation)
    GE_PROPERTY(bCString, DayTime, m_strDayTime)
    GE_PROPERTY(bCString, Variation, m_strVariation)
    GE_ENUMPROP(gEMusicTransition, TransitionMode, m_enuTransition)
    GE_ENUMPROP(gEMusicTriggerTime, Exit, m_enuExit)
    GE_ENUMPROP(gEMusicFragmentPosition, Entrance, m_enuEntrance)
    GE_PROPERTY(GEInt, ConnectIn, m_iConnectIn)
    GE_PROPERTY(GEInt, ConnectOut, m_iConnectOut)
    GE_PROPERTY(bCString, Transition, m_strTransitionID)
    GE_PROPERTY(GEBool, IsStopTrigger, m_bIsStopTrigger)
    GE_PROPERTY(GEBool, DisableTriggers, m_bDenyTriggers)
    GE_PADDING(1)

  public:
    void GetDescriptor(gSEffectCommand_MusicTrigger &) const;
    void SetDescriptor(gSEffectCommand_MusicTrigger const &);

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCEffectCommandMusicTrigger, 0x48)

GE_ASSERT_PROPERTY(gCEffectCommandMusicTrigger, m_strLocation, 0x10, 4)
GE_ASSERT_PROPERTY(gCEffectCommandMusicTrigger, m_strSituation, 0x14, 4)
GE_ASSERT_PROPERTY(gCEffectCommandMusicTrigger, m_strDayTime, 0x18, 4)
GE_ASSERT_PROPERTY(gCEffectCommandMusicTrigger, m_strVariation, 0x1c, 4)
GE_ASSERT_PROPERTY(gCEffectCommandMusicTrigger, m_enuTransition, 0x20, 8)
GE_ASSERT_PROPERTY(gCEffectCommandMusicTrigger, m_enuExit, 0x28, 8)
GE_ASSERT_PROPERTY(gCEffectCommandMusicTrigger, m_enuEntrance, 0x30, 8)
GE_ASSERT_PROPERTY(gCEffectCommandMusicTrigger, m_iConnectIn, 0x38, 4)
GE_ASSERT_PROPERTY(gCEffectCommandMusicTrigger, m_iConnectOut, 0x3c, 4)
GE_ASSERT_PROPERTY(gCEffectCommandMusicTrigger, m_strTransitionID, 0x40, 4)
GE_ASSERT_PROPERTY(gCEffectCommandMusicTrigger, m_bIsStopTrigger, 0x44, 1)
GE_ASSERT_PROPERTY(gCEffectCommandMusicTrigger, m_bDenyTriggers, 0x45, 1)
