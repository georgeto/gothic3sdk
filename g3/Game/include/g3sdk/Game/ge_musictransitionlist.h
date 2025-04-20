#pragma once

#include <Game/GameEnum.h>

#include <SharedBase.h>

class gCMusicTransition;
struct gSMusicTransition;

class GE_DLLIMPORT gCMusicTransitionList
{
    // clang-format off
    public: virtual ~gCMusicTransitionList();
    // clang-format on

  public:
    gCMusicTransitionList(gCMusicTransitionList const &);
    gCMusicTransitionList();

  public:
    gCMusicTransitionList &operator=(gCMusicTransitionList const &);
    gCMusicTransition *operator[](GEInt) const;

  public:
    void CopyFrom(gCMusicTransitionList const &);
    gCMusicTransition *FindTransition(gEMusicSequence, bCString const &) const;
    gCMusicTransition *FindTransition(gEMusicSequence, GEInt, GEInt) const;
    gCMusicTransition *GetItem(GEInt) const;
    GEInt GetItemCount() const;
    GEInt InsertItem(gSMusicTransition const &);
    GEBool IsValidIndex(GEInt) const;
    void Read(bCIStream &);
    void RemoveAllItems();
    GEBool RemoveItem(GEInt);
    void SortItems();
    void Write(bCOStream &) const;

  protected:
    static GEInt GE_CCALL CompareItems(GELPCVoid, GELPCVoid);

  protected:
    void Destroy();
    GEInt FindTransitions(bCString const &, bTValArray<gCMusicTransition *> &) const;
    GEInt FindTransitions(GEInt, GEInt, bTValArray<gCMusicTransition *> &) const;
    void Invalidate();
    gCMusicTransition *SelectTransition(bTValArray<gCMusicTransition *> &, gEMusicSequence) const;
};
