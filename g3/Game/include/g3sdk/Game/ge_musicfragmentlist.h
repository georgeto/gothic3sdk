#pragma once

#include <Game/GameEnum.h>

#include <SharedBase.h>

class gCMusicFragment;
struct gSMusicFragment;
struct gSMusicTrigger;

class GE_DLLIMPORT gCMusicFragmentList
{
    // clang-format off
    public: virtual ~gCMusicFragmentList();
    // clang-format on

  public:
    gCMusicFragmentList(gCMusicFragmentList const &);
    gCMusicFragmentList();

  public:
    gCMusicFragmentList &operator=(gCMusicFragmentList const &);
    gCMusicFragment *operator[](GEInt) const;

  public:
    void CopyFrom(gCMusicFragmentList const &);
    gCMusicFragment *FindFragment(gEMusicSequence, gSMusicTrigger const &) const;
    GEInt FindFragments(gSMusicTrigger const &, bTValArray<gCMusicFragment *> &) const;
    gCMusicFragment *GetItem(GEInt) const;
    GEInt GetItemCount() const;
    GEInt InsertItem(gSMusicFragment const &);
    GEBool IsValidIndex(GEInt) const;
    void Read(bCIStream &);
    void RemoveAllItems();
    GEBool RemoveItem(GEInt);
    gCMusicFragment *SelectFragment(bTValArray<gCMusicFragment *> &, gEMusicSequence) const;
    void SortItems();
    void Write(bCOStream &) const;

  protected:
    static GEInt GE_CCALL CompareItems(GELPCVoid, GELPCVoid);

  protected:
    void Destroy();
    void Invalidate();
};
