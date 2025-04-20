#pragma once

#include <Game/ge_musicevent.h>

#include <SharedBase.h>

class gCMusicTransition;

class GE_DLLIMPORT gCMusicEventTransition : public gCMusicEvent
{
    // clang-format off
    public: GEBool Execute(gCMusicSequencer *) const override;
    public: GEInt CompareTo(gCMusicEvent const *) const override;
    public: GEInt CompareFrom(gCMusicEvent const *) const override;
    public: void GetDescription(bCString &) const override;
    // clang-format on

  public:
    gCMusicEventTransition(gSMusicTrigger const &, gCMusicTransition *, GEUInt, GEUInt, GEBool, GEBool);
    gCMusicEventTransition(gCMusicEventTransition const &);
    ~gCMusicEventTransition();

  public:
    gCMusicEventTransition &operator=(gCMusicEventTransition const &);

  public:
    void Create(gSMusicTrigger const &, gCMusicTransition *, GEUInt, GEUInt, GEBool, GEBool);
    void EnableFadeIn(GEBool);
    void EnableFadeOut(GEBool);
    GEUInt GetEnterTime() const;
    gCMusicTransition *GetTransition() const;
    GEBool IsFadeInEnabled() const;
    GEBool IsFadeOutEnabled() const;
    void SetEnterTime(GEUInt);
    void SetTransition(gCMusicTransition *);
};
