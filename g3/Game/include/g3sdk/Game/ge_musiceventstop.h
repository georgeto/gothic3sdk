#pragma once

#include <Game/ge_musicevent.h>

#include <SharedBase.h>

class GE_DLLIMPORT gCMusicEventStop : public gCMusicEvent
{
    // clang-format off
    public: GEBool Execute(gCMusicSequencer *) const override;
    public: void GetDescription(bCString &) const override;
    // clang-format on

  public:
    gCMusicEventStop(gSMusicTrigger const &, GEUInt);
    gCMusicEventStop(gCMusicEventStop const &);
    ~gCMusicEventStop();

  public:
    gCMusicEventStop &operator=(gCMusicEventStop const &);

  public:
    void Create(gSMusicTrigger const &, GEUInt);
};
