#pragma once

#include <Engine/ge_audiochannel.h>
#include <Engine/ge_audiochannelgroup.h>
#include <Engine/ge_audiomodule.h>

#include <SharedBase.h>

enum eEAudioSoundFormat
{
    // TODO: Enumerator values
};

enum eEAudioSoundType
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCAudioSound : public bCObjectRefBase
{
  public:
    struct SCreateFromFile
    {
      public:
        SCreateFromFile(SCreateFromFile const &);
        SCreateFromFile();
        ~SCreateFromFile();

      public:
        SCreateFromFile &operator=(SCreateFromFile const &);
    };

    // clang-format off
    public: void Destroy() override;
    public: ~eCAudioSound() override;
    // clang-format on

  public:
    eCAudioSound(eCAudioSound const &);
    eCAudioSound();

  public:
    eCAudioSound &operator=(eCAudioSound const &);

  public:
    eEAudioResult AddSyncPoint(GEU32, eEAudioTimeUnit);
    bEResult Create(SCreateFromFile const &);
    eEAudioResult DeleteAllSyncPoints();
    eEAudioResult DeleteSyncPoint(GEInt);
    eEAudioResult GetCone(GEFloat &, GEFloat &, GEFloat &) const;
    eEAudioResult GetDefaults(GEFloat &, GEFloat &, GEFloat &, GEU8 &) const;
    eEAudioResult GetDefaults(GEFloat *, GEFloat *, GEFloat *, GELPByte) const;
    eEAudioResult GetFormat(eEAudioSoundType *, eEAudioSoundFormat *, GEInt *, GEInt *) const;
    GEU32 GetLength(eEAudioTimeUnit) const;
    eEAudioResult GetLoopCount(GEI32 &) const;
    eEAudioResult GetMinMaxDistance(GEFloat &, GEFloat &) const;
    eEAudioResult GetMode(GEU32 &) const;
    GEInt GetSyncPointCount() const;
    eEAudioResult GetSyncPointInfo(GEInt, eEAudioTimeUnit, GEU32 &, bCString &) const;
    eEAudioResult GetVariations(GEFloat &, GEFloat &, GEFloat &) const;
    eEAudioResult Lock(GEU32, GEU32, GELPVoid *, GELPVoid *, GEUInt *, GEUInt *);
    eEAudioResult ModifyMode(GEU32, GEU32);
    eEAudioResult Play(GEInt, GEBool, eCAudioChannel &);
    eEAudioResult Play(GEInt, GEBool, eCAudioChannel *, eEAudioChannelGroup);
    eEAudioResult SetCone(GEFloat, GEFloat, GEFloat);
    eEAudioResult SetDefaults(GEFloat, GEFloat, GEFloat, GEU8);
    eEAudioResult SetDefaults(GEFloat const *, GEFloat const *, GEFloat const *, GELPCByte);
    eEAudioResult SetLoopCount(GEI32);
    eEAudioResult SetMinMaxDistance(GEFloat, GEFloat);
    eEAudioResult SetMode(GEU32);
    eEAudioResult SetVariations(GEFloat, GEFloat, GEFloat);
    eEAudioResult Unlock(GELPVoid, GELPVoid, GEUInt, GEUInt);

  protected:
    void Invalidate();
};
