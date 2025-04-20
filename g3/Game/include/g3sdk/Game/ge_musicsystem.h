#pragma once

#include <SharedBase.h>

class gCMusicLibrary;
class gCMusicSequencer;

class GE_DLLIMPORT gCMusicSystem
{
    // clang-format off
    public: virtual ~gCMusicSystem();
    // clang-format on

  public:
    gCMusicSystem(gCMusicSystem const &);
    gCMusicSystem();

  public:
    gCMusicSystem &operator=(gCMusicSystem const &);

  public:
    gCMusicLibrary &GetLibrary();
    gCMusicLibrary const &GetLibrary() const;
    gCMusicSequencer *GetSequencer() const;
    void Process(GEFloat);

  protected:
    void Create();
    void Destroy();
    void Invalidate();
};
