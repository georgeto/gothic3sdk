#pragma once

#include <Game/GameEnum.h>

#include <SharedBase.h>

class gCMusicChannel;
class gCMusicEvent;
class gCMusicEventFragment;
class gCMusicEventStop;
class gCMusicEventTransition;
class gCMusicFragment;
class gCMusicFragmentList;
class gCMusicLink;
class gCMusicTransition;
class gCMusicTransitionList;
struct gSMusicTrigger;

enum gEMusicChannel
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT gCMusicSequencer : public bCObjectRefBase
{
  public:
    struct STransition
    {
        GE_UNIMPL_STRUCT(STransition)
    };

    // clang-format off
    public: virtual gCMusicSequencer * Clone() const;
    public: void Destroy() override;
    public: ~gCMusicSequencer() override;
    protected: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCMusicSequencer, bCObjectRefBase)
    GE_PROPERTY(GEBool, AcceptTriggers, m_bAcceptTriggers)
    GE_PADDING(3)
    GE_PROPERTY(bCString, Location, m_strLocation)   // Read only
    GE_PROPERTY(bCString, Situation, m_strSituation) // Read only
    GE_PROPERTY(bCString, DayTime, m_strDayTime)     // Read only
    GE_ENUMPROP(gEMusicSequence, FragmentSequence, m_enuFragmentSequence)
    GE_ENUMPROP(gEMusicSequence, TransitionSequence, m_enuTransitionSequence)

  public:
    void ForceNextEvent();
    gCMusicChannel *GetChannel(gEMusicChannel) const;
    bTValArray<gCMusicEvent *> const &GetEvents() const;
    gSMusicTrigger const &GetLastTrigger() const;
    GEBool IsInState(gSMusicTrigger const &) const;
    GEBool IsPaused() const;
    GEBool IsPlaying() const;
    void Pause(GEBool);
    gCMusicEvent const *PeekEvent() const;
    void Process(GEFloat);
    void Stop();
    GEBool Trigger(gSMusicTrigger const &);

  protected:
    GEBool ApplyState(gSMusicTrigger const &);
    void Copy(gCMusicSequencer const &);
    void DeleteAllEvents();
    void DeleteEvent(gCMusicEvent const *);
    GEBool Execute(gCMusicEventFragment const *);
    GEBool Execute(gCMusicEventStop const *);
    GEBool Execute(gCMusicEventTransition const *);
    GEBool ExecuteTrigger(gSMusicTrigger const &);
    GEBool FindFallback(gSMusicTrigger const &, STransition &) const;
    gCMusicFragment *FindFragment(gSMusicTrigger const &) const;
    GEBool FindLinks(gSMusicTrigger const &, STransition &) const;
    gCMusicTransition *FindTransition(gSMusicTrigger const &, gCMusicLink const *, gCMusicLink const *) const;
    GEBool FindTransition(gSMusicTrigger const &, STransition &) const;
    void FlipChannels();
    gCMusicFragmentList const *GetFragmentList() const;
    GEUInt GetPrimaryDuration() const;
    gCMusicFragment *GetPrimaryFragment() const;
    GEUInt GetPrimaryTime() const;
    gCMusicTransitionList const *GetTransitionList() const;
    void Init();
    void Invalidate();
    GEBool IsTransitionPlaying() const;
    GEBool QueueFragment(gSMusicTrigger const &, gCMusicFragment *, GEUInt, GEUInt);
    GEBool QueueStop(gSMusicTrigger const &, GEUInt);
    GEBool QueueTransition(gSMusicTrigger const &, gCMusicTransition *, GEUInt, GEBool, GEBool);
    void SortEvents();
    void StartDueEvents();
    GEBool TriggerFollow(gCMusicFragment const *);
    void UpdateChannels();

  private:
    GE_UNIMPL_MEMBERS(76)
};

GE_ASSERT_SIZEOF(gCMusicSequencer, 0x78)

GE_ASSERT_PROPERTY(gCMusicSequencer, m_bAcceptTriggers, 0xc, 1)
GE_ASSERT_PROPERTY(gCMusicSequencer, m_strLocation, 0x10, 4)
GE_ASSERT_PROPERTY(gCMusicSequencer, m_strSituation, 0x14, 4)
GE_ASSERT_PROPERTY(gCMusicSequencer, m_strDayTime, 0x18, 4)
GE_ASSERT_PROPERTY(gCMusicSequencer, m_enuFragmentSequence, 0x1c, 8)
GE_ASSERT_PROPERTY(gCMusicSequencer, m_enuTransitionSequence, 0x24, 8)
