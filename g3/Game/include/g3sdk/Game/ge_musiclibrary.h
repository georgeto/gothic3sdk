#pragma once

#include <SharedBase.h>

class gCMusicFragmentList;
class gCMusicTransitionList;
class gCMusicTriggerList;

class GE_DLLIMPORT gCMusicLibrary
{
    // clang-format off
    public: virtual ~gCMusicLibrary();
    // clang-format on

  public:
    gCMusicLibrary(gCMusicLibrary const &);
    gCMusicLibrary();

  public:
    gCMusicLibrary &operator=(gCMusicLibrary const &);

  public:
    void CopyFrom(gCMusicLibrary const &);
    void Destroy();
    gCMusicFragmentList &GetFragments();
    gCMusicFragmentList const &GetFragments() const;
    gCMusicTransitionList &GetTransitions();
    gCMusicTransitionList const &GetTransitions() const;
    gCMusicTriggerList &GetTriggers();
    gCMusicTriggerList const &GetTriggers() const;
    GEBool Load(bCString const &);
    void Read(bCIStream &);
    GEBool Save(bCString const &) const;
    void Write(bCOStream &) const;

  protected:
    void Invalidate();
};
