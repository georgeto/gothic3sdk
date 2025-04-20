#pragma once

#include <SharedBase.h>

class gCMusicFragment;
class gCMusicTransition;

class GE_DLLIMPORT gCMusicChannel : public bCObjectRefBase
{
  public:
    struct SStream
    {
        GE_UNIMPL_STRUCT(SStream)
    };

    // clang-format off
    public: virtual gCMusicChannel * Clone() const;
    public: void Destroy() override;
    public: ~gCMusicChannel() override;
    protected: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCMusicChannel, bCObjectRefBase)

  public:
    GEUInt GetDuration() const;
    gCMusicFragment *GetFragment() const;
    GEU32 GetLength() const;
    GEU32 GetPosition() const;
    bCString GetSample() const;
    GEUInt GetTime() const;
    gCMusicTransition *GetTransition() const;
    GEFloat GetVU() const;
    GEFloat GetVolume() const;
    GEBool IsPaused() const;
    GEBool IsPlaying() const;
    GEBool Pause(GEBool);
    GEBool QueueFragment(gCMusicFragment *, GEUInt);
    GEBool QueueTransition(gCMusicTransition *);
    void SetFadeChannels(gCMusicChannel *, gCMusicChannel *, GEBool, GEBool);
    GEBool StartNextStream();
    GEBool Stop();
    void UpdateEnvelope();

  protected:
    void ApplyFadeVolume(GEFloat);
    GEFloat CalcDstVolume() const;
    GEFloat CalcSrcVolume() const;
    void ClearQueue();
    void Copy(gCMusicChannel const &);
    void Init();
    void Invalidate();
    SStream const *PeekStream() const;
    void UpdateEnvelope(gCMusicChannel *, gCMusicChannel *);

  private:
    GE_UNIMPL_MEMBERS(40)
};

GE_ASSERT_SIZEOF(gCMusicChannel, 0x34)
