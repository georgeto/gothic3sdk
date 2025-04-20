#pragma once

#include <Game/GameEnum.h>

#include <SharedBase.h>

class gCMusicLink;
struct gSMusicLink;

struct gSMusicFragment
{
    GE_UNIMPL_STRUCT(gSMusicFragment)
};

class GE_DLLIMPORT gCMusicLinkSequence
{
    // clang-format off
    public: virtual ~gCMusicLinkSequence();
    // clang-format on

  public:
    gCMusicLinkSequence(gCMusicLinkSequence const &);
    gCMusicLinkSequence();

  public:
    gCMusicLinkSequence &operator=(gCMusicLinkSequence const &);
    gCMusicLink *operator[](GEInt) const;

  public:
    void CopyFrom(gCMusicLinkSequence const &);
    gCMusicLink *FindFirstEntrance() const;
    gCMusicLink *FindLastExit() const;
    gCMusicLink *FindLoopEntrance() const;
    gCMusicLink *FindNextExit(GEUInt, GEBool) const;
    gCMusicLink *FindNextLink(gEMusicLink, GEUInt) const;
    gCMusicLink *FindRandomEntrance() const;
    void GetDescriptor(gSMusicFragment &) const;
    gCMusicLink *GetItem(GEInt) const;
    GEInt GetItemCount() const;
    GEInt InsertItem(gSMusicLink const &);
    GEBool IsValidIndex(GEInt) const;
    void Read(bCIStream &);
    void RemoveAllItems();
    GEBool RemoveItem(GEInt);
    void SetDescriptor(gSMusicFragment const &);
    void SortItems();
    void Write(bCOStream &) const;

  protected:
    static GEInt GE_CCALL CompareItems(GELPCVoid, GELPCVoid);

  protected:
    void Destroy();
    void FindEntrances(bTValArray<gCMusicLink *> &) const;
    void Invalidate();
};
