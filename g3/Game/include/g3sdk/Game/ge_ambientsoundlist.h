#pragma once

#include <Engine.h>

class gCAmbientSound;
struct gSAmbientSound;

class GE_DLLIMPORT gCAmbientSoundList
{
    // clang-format off
    public: virtual ~gCAmbientSoundList();
    // clang-format on

  public:
    gCAmbientSoundList(gCAmbientSoundList const &);
    gCAmbientSoundList();

  public:
    gCAmbientSoundList &operator=(gCAmbientSoundList const &);
    gCAmbientSound *operator[](GEInt) const;

  public:
    void CopyFrom(gCAmbientSoundList const &);
    gCAmbientSound *FindSound(eEAmbientClimate, eEAmbientEnvironment, eEAmbientDayTime) const;
    gCAmbientSound *GetItem(GEInt) const;
    GEInt GetItemCount() const;
    GEInt InsertItem(gSAmbientSound const &);
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
    GEInt FindSounds(eEAmbientClimate, eEAmbientEnvironment, eEAmbientDayTime, bTValArray<gCAmbientSound *> &) const;
    void Invalidate();
    gCAmbientSound *SelectSound(bTValArray<gCAmbientSound *> &) const;
};
