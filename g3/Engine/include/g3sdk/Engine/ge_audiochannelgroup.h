#pragma once

#include <Engine/ge_fmod.h>

#include <SharedBase.h>

enum eEAudioResult
{
    eEAudioResult_Ok = 0,
};

class GE_DLLIMPORT eCAudioChannelGroup : public bCObjectRefBase
{
    // clang-format off
    public: void Destroy() override;
    public: ~eCAudioChannelGroup() override;
    // clang-format on

  public:
    eCAudioChannelGroup(eCAudioChannelGroup const &);
    eCAudioChannelGroup();

  public:
    eCAudioChannelGroup &operator=(eCAudioChannelGroup const &);

  public:
    FMOD::ChannelGroup *GetHandle() const;
    eEAudioResult GetPitch(GEFloat &) const;
    eEAudioResult GetVolume(GEFloat &) const;
    eEAudioResult OverrideMute(GEBool);
    eEAudioResult SetPitch(GEFloat);
    eEAudioResult SetVolume(GEFloat);

  protected:
    void Attach(FMOD::ChannelGroup *);
    void Invalidate();
};
