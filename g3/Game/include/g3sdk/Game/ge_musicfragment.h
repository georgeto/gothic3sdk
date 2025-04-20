#pragma once

#include <Game/GameEnum.h>
#include <Game/ge_musicstream.h>

#include <Engine.h>

class gCMusicLink;
class gCMusicLinkSequence;
struct gSMusicFragment;
struct gSMusicTrigger;

class GE_DLLIMPORT gCMusicFragment : public gCMusicStream
{
    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~gCMusicFragment() override;
    protected: bEResult PostInitializeProperties() override;
    public: gEMusicStream GetStreamType() const override;
    public: gCMusicStream * Clone() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCMusicFragment, gCMusicStream)
    GE_PROPERTY(bCString, Location, m_strLocation)
    GE_PROPERTY(bCString, Situation, m_strSituation)
    GE_PROPERTY(bCString, DayTime, m_strDayTime)
    GE_PROPERTY(bCString, Variation, m_strVariation)
    GE_PROPERTY(bCString, NextVariation, m_strNextVariation)

  public:
    eCAudioSound *CreateSound() const;
    gCMusicLink *FindLink(gEMusicFragmentPosition) const;
    gCMusicLink *FindLink(gEMusicLink, GEUInt) const;
    gCMusicLink *FindLink(gEMusicTriggerTime, GEUInt) const;
    void GetDescriptor(gSMusicFragment &) const;
    gCMusicLink *GetFirstEntrance() const;
    void GetFollowTrigger(gSMusicTrigger &) const;
    bCString GetID() const;
    gCMusicLink *GetLastExit() const;
    gCMusicLinkSequence &GetLinks();
    gCMusicLinkSequence const &GetLinks() const;
    gCMusicLink *GetLoopEntrance() const;
    GEBool ImportLinks();
    GEBool Matches(gSMusicTrigger const &) const;
    void SetDescriptor(gSMusicFragment const &);

  protected:
    void CreateSyncPoints(eCAudioSound *) const;
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(16)
};

GE_ASSERT_SIZEOF(gCMusicFragment, 0x48)

GE_ASSERT_PROPERTY(gCMusicFragment, m_strLocation, 0x24, 4)
GE_ASSERT_PROPERTY(gCMusicFragment, m_strSituation, 0x28, 4)
GE_ASSERT_PROPERTY(gCMusicFragment, m_strDayTime, 0x2c, 4)
GE_ASSERT_PROPERTY(gCMusicFragment, m_strVariation, 0x30, 4)
GE_ASSERT_PROPERTY(gCMusicFragment, m_strNextVariation, 0x34, 4)
