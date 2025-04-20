#pragma once

#include <SharedBase.h>

class gCMusicSequencer;
struct gSMusicTrigger;

class GE_DLLIMPORT gCMusicEvent
{
    // clang-format off
    public: virtual GEBool Execute(gCMusicSequencer *) const = 0;
    public: virtual GEInt CompareTo(gCMusicEvent const *) const;
    public: virtual GEInt CompareFrom(gCMusicEvent const *) const;
    public: virtual void GetDescription(bCString &) const = 0;
    // clang-format on

  public:
    gCMusicEvent(gCMusicEvent const &);
    gCMusicEvent();
    ~gCMusicEvent();

  public:
    gCMusicEvent &operator=(gCMusicEvent const &);

  public:
    GEUInt GetExitTime() const;
    gSMusicTrigger const &GetTrigger() const;
    GEBool IsDue(GEUInt) const;
    void SetExitTime(GEUInt);
};
