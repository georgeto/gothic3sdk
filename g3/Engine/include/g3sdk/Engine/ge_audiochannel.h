#pragma once

#include <Engine/ge_audiochannelgroup.h>
#include <Engine/ge_fmod.h>

#include <SharedBase.h>

enum eEAudioSpeaker
{
    // TODO: Enumerator values
};

enum eEAudioTimeUnit
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCAudioChannel : public bCObjectRefBase
{
    // clang-format off
    public: void Destroy() override;
    public: ~eCAudioChannel() override;
    // clang-format on

  public:
    eCAudioChannel(eCAudioChannel const &);
    eCAudioChannel();

  public:
    eCAudioChannel &operator=(eCAudioChannel const &);

  public:
    GEFloat GetAudibility() const;
    eEAudioResult GetCone(GEFloat &, GEFloat &, GEFloat &) const;
    eEAudioResult GetConeOrientation(bCVector &) const;
    eEAudioResult GetDelay(GEU64 &, GEU64 &) const;
    eEAudioResult GetDirectOcclusion(GEFloat &) const;
    GEU32 GetDuration(eEAudioTimeUnit) const;
    eEAudioResult GetFrequency(GEFloat &) const;
    FMOD::Channel *GetHandle() const;
    eEAudioResult GetLocation(bCVector &) const;
    eEAudioResult GetLoopCount(GEI32 &) const;
    eEAudioResult GetLoopMode(GEU32 &) const;
    eEAudioResult GetMinMaxDistance(GEFloat &, GEFloat &) const;
    eEAudioResult GetPan(GEFloat &) const;
    GEU32 GetPosition(eEAudioTimeUnit) const;
    eEAudioResult GetPriority(GEU8 &) const;
    eEAudioResult GetReverbOcclusion(GEFloat &) const;
    eEAudioResult GetSpeakerLevels(eEAudioSpeaker, GEFloat *, GEInt) const;
    eEAudioResult GetVelocity(bCVector &) const;
    eEAudioResult GetVolume(GEFloat &) const;
    eEAudioResult GetWaveData(GEFloat *, GEInt, GEInt) const;
    GEBool IsMuted() const;
    GEBool IsPaused() const;
    GEBool IsPlaying() const;
    GEBool IsVirtual() const;
    eEAudioResult Mute(GEBool);
    void OnEndOfSound(FMOD::Channel *);
    void OnSyncPoint(FMOD::Channel *, GEInt);
    eEAudioResult Pause(GEBool);
    eEAudioResult SetChannelGroup(eCAudioChannelGroup *);
    eEAudioResult SetCone(GEFloat, GEFloat, GEFloat);
    eEAudioResult SetConeOrientation(bCVector const &);
    eEAudioResult SetDelay(GEU64, GEU64);
    eEAudioResult SetFrequency(GEFloat);
    eEAudioResult SetLocation(bCVector const &);
    eEAudioResult SetLoopCount(GEI32);
    eEAudioResult SetLoopMode(GEU32);
    eEAudioResult SetMinMaxDistance(GEFloat, GEFloat);
    eEAudioResult SetPan(GEFloat);
    eEAudioResult SetPosition(eEAudioTimeUnit, GEU32);
    eEAudioResult SetPriority(GEU8);
    eEAudioResult SetSpeakerLevels(eEAudioSpeaker, GEFloat const *, GEInt);
    eEAudioResult SetVelocity(bCVector const &);
    eEAudioResult SetVolume(GEFloat);
    eEAudioResult Stop();
    GEBool UpdateOcclusion();

  protected:
    void Attach(FMOD::Channel *);
    void Invalidate();
};
