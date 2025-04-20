#pragma once

#include <SharedBase.h>

enum gEMusicStream
{
    // TODO: Enumerator values
};

struct gSMusicStream
{
    GE_UNIMPL_STRUCT(gSMusicStream)
};

class GE_DLLIMPORT gCMusicStream : public bCObjectRefBase
{
    // clang-format off
    public: virtual gEMusicStream GetStreamType() const;
    protected: virtual void OnSampleChanged();
    public: virtual gCMusicStream * Clone() const;
    public: void Destroy() override;
    public: ~gCMusicStream() override;
    protected: bEResult PostInitializeProperties() override;
    protected: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCMusicStream, bCObjectRefBase)
    GE_PROPERTY(bCString, Sample, m_strSample)
    GE_PROPERTY(GEFloat, Volume, m_fVolume)
    GE_PROPERTY(GEU32, LeadInEnd, m_u32LeadInEnd)
    GE_PROPERTY(GEU32, LeadOutBegin, m_u32LeadOutBegin)
    GE_PROPERTY(GEU32, Duration, m_u32Duration)
    GE_PROPERTY(GEBool, Shuffled, m_bShuffled) // Read only
    GE_PADDING(1)

  protected:
    void GetDescriptor(gSMusicStream &) const;
    void Invalidate();
    void SetDescriptor(gSMusicStream const &);
    void UpdateDuration();
};

GE_ASSERT_SIZEOF(gCMusicStream, 0x24)

GE_ASSERT_PROPERTY(gCMusicStream, m_strSample, 0xc, 4)
GE_ASSERT_PROPERTY(gCMusicStream, m_fVolume, 0x10, 4)
GE_ASSERT_PROPERTY(gCMusicStream, m_u32LeadInEnd, 0x14, 4)
GE_ASSERT_PROPERTY(gCMusicStream, m_u32LeadOutBegin, 0x18, 4)
GE_ASSERT_PROPERTY(gCMusicStream, m_u32Duration, 0x1c, 4)
GE_ASSERT_PROPERTY(gCMusicStream, m_bShuffled, 0x20, 1)
