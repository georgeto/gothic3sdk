#pragma once

#include <Game/GameEnum.h>

#include <SharedBase.h>

struct gSMusicTrigger
{
    GE_UNIMPL_STRUCT(gSMusicTrigger)
};

class GE_DLLIMPORT gCMusicTrigger : public bCObjectRefBase
{
    // clang-format off
    public: virtual gCMusicTrigger * Clone() const;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~gCMusicTrigger() override;
    protected: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCMusicTrigger, bCObjectRefBase)
    GE_PROPERTY(bCString, ID, m_strID)
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
    void GetDescriptor(gSMusicTrigger &) const;
    void SetDescriptor(gSMusicTrigger const &);

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCMusicTrigger, 0x48)

GE_ASSERT_PROPERTY(gCMusicTrigger, m_strID, 0xc, 4)
GE_ASSERT_PROPERTY(gCMusicTrigger, m_strLocation, 0x10, 4)
GE_ASSERT_PROPERTY(gCMusicTrigger, m_strSituation, 0x14, 4)
GE_ASSERT_PROPERTY(gCMusicTrigger, m_strDayTime, 0x18, 4)
GE_ASSERT_PROPERTY(gCMusicTrigger, m_strVariation, 0x1c, 4)
GE_ASSERT_PROPERTY(gCMusicTrigger, m_enuTransition, 0x20, 8)
GE_ASSERT_PROPERTY(gCMusicTrigger, m_enuExit, 0x28, 8)
GE_ASSERT_PROPERTY(gCMusicTrigger, m_enuEntrance, 0x30, 8)
GE_ASSERT_PROPERTY(gCMusicTrigger, m_iConnectIn, 0x38, 4)
GE_ASSERT_PROPERTY(gCMusicTrigger, m_iConnectOut, 0x3c, 4)
GE_ASSERT_PROPERTY(gCMusicTrigger, m_strTransitionID, 0x40, 4)
GE_ASSERT_PROPERTY(gCMusicTrigger, m_bIsStopTrigger, 0x44, 1)
GE_ASSERT_PROPERTY(gCMusicTrigger, m_bDenyTriggers, 0x45, 1)

GE_DLLIMPORT bCString const g_strDefaultMusicDayTime;
GE_DLLIMPORT bCString const g_strDefaultMusicLocation;
GE_DLLIMPORT bCString const g_strDefaultMusicSituation;
GE_DLLIMPORT bCString const g_strDefaultMusicVariation;
