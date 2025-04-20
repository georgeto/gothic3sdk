#pragma once

#include <Engine/ge_audiochannelgroup.h>
#include <Engine/ge_fmod.h>

#include <SharedBase.h>

enum eEAudioSpeakerMode
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCAudioSystem : public bCObjectRefBase
{
  public:
    struct SCreate
    {
        GE_UNIMPL_STRUCT(SCreate)
    };

    // clang-format off
    public: void Destroy() override;
    public: ~eCAudioSystem() override;
    // clang-format on

  public:
    eCAudioSystem(eCAudioSystem const &);
    eCAudioSystem();

  public:
    eCAudioSystem &operator=(eCAudioSystem const &);

  public:
    bEResult Create(SCreate const &);
    eEAudioResult GetCPUUsage(GEFloat &, GEFloat &, GEFloat &, GEFloat &, GEFloat &) const;
    eEAudioResult GetChannelCounts(GEInt &, GEInt &, GEInt &) const;
    FMOD::System *GetHandle() const;
    eEAudioResult GetPlayingChannelCount(GEInt &) const;
    eEAudioResult GetRAMUsage(GEInt &, GEInt &, GEInt &) const;
    eEAudioResult GetSpeakerMode(eEAudioSpeakerMode &) const;
    eEAudioResult SetListenerAttributes(GEInt, bCMatrix const &, bCVector const *);
    eEAudioResult SetListenerAttributes(GEInt, bCVector const *, bCVector const *, bCVector const *, bCVector const *);
    eEAudioResult SetSpeakerMode(eEAudioSpeakerMode);
    eEAudioResult Update();

  protected:
    static GELPVoid GE_STDCALL FModAllocMemory(GEUInt, GEUInt, GELPCChar);
    static void GE_STDCALL FModFreeMemory(GELPVoid, GEUInt, GELPCChar);
    static GELPVoid GE_STDCALL FModReallocMemory(GELPVoid, GEUInt, GEUInt, GELPCChar);

  protected:
    void Invalidate();
};
