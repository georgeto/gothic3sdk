#pragma once

#include <SharedBase.h>

class gCEffectCommand;
struct gSEffectCommand;
struct gSEffectCommand_CreateDecal;
struct gSEffectCommand_EarthQuake;
struct gSEffectCommand_KillEntity;
struct gSEffectCommand_ModifyEntity;
struct gSEffectCommand_MusicTrigger;
struct gSEffectCommand_PlaySound;
struct gSEffectCommand_PlayVoice;
struct gSEffectCommand_SpawnEntity;
struct gSEffectCommand_TriggerEntity;

class GE_DLLIMPORT gCEffectCommandSequence
{
    // clang-format off
    public: virtual ~gCEffectCommandSequence();
    // clang-format on

  public:
    gCEffectCommandSequence(gCEffectCommandSequence const &);
    gCEffectCommandSequence();

  public:
    gCEffectCommandSequence &operator=(gCEffectCommandSequence const &);
    gCEffectCommand *operator[](GEInt) const;

  public:
    void CopyFrom(gCEffectCommandSequence const &);
    GEFloat GetEndTime() const;
    gCEffectCommand *GetItem(GEInt) const;
    GEInt GetItemCount() const;
    GEInt InsertItem(gSEffectCommand const *);
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
    GEInt InsertItem(gSEffectCommand_CreateDecal const &);
    GEInt InsertItem(gSEffectCommand_EarthQuake const &);
    GEInt InsertItem(gSEffectCommand_KillEntity const &);
    GEInt InsertItem(gSEffectCommand_ModifyEntity const &);
    GEInt InsertItem(gSEffectCommand_MusicTrigger const &);
    GEInt InsertItem(gSEffectCommand_PlaySound const &);
    GEInt InsertItem(gSEffectCommand_PlayVoice const &);
    GEInt InsertItem(gSEffectCommand_SpawnEntity const &);
    GEInt InsertItem(gSEffectCommand_TriggerEntity const &);
    void Invalidate();

  private:
    bTPtrArray<gCEffectCommand *> m_Items;
};

GE_ASSERT_SIZEOF(gCEffectCommandSequence, 0x10)
