#pragma once

#include <Game/ge_musicevent.h>

#include <SharedBase.h>

class gCMusicFragment;

class GE_DLLIMPORT gCMusicEventFragment : public gCMusicEvent
{
    // clang-format off
    public: GEBool Execute(gCMusicSequencer *) const override;
    public: void GetDescription(bCString &) const override;
    // clang-format on

  public:
    gCMusicEventFragment(gSMusicTrigger const &, gCMusicFragment *, GEUInt, GEUInt);
    gCMusicEventFragment(gCMusicEventFragment const &);
    ~gCMusicEventFragment();

  public:
    gCMusicEventFragment &operator=(gCMusicEventFragment const &);

  public:
    void Create(gSMusicTrigger const &, gCMusicFragment *, GEUInt, GEUInt);
    GEUInt GetEnterTime() const;
    gCMusicFragment *GetFragment() const;
    void SetEnterTime(GEUInt);
    void SetFragment(gCMusicFragment *);
};
