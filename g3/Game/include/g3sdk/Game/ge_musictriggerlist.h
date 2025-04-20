#pragma once

#include <SharedBase.h>

class gCMusicTrigger;
struct gSMusicTrigger;

class GE_DLLIMPORT gCMusicTriggerList
{
    // clang-format off
    public: virtual ~gCMusicTriggerList();
    // clang-format on

  public:
    gCMusicTriggerList(gCMusicTriggerList const &);
    gCMusicTriggerList();

  public:
    gCMusicTriggerList &operator=(gCMusicTriggerList const &);
    gCMusicTrigger *operator[](GEInt) const;

  public:
    void CopyFrom(gCMusicTriggerList const &);
    gCMusicTrigger *GetItem(GEInt) const;
    GEInt GetItemCount() const;
    GEInt InsertItem(gSMusicTrigger const &);
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
    void Invalidate();
};
