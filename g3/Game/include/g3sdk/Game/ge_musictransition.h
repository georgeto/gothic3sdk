#pragma once

#include <Game/GameEnum.h>
#include <Game/ge_musicstream.h>

#include <Engine.h>

struct gSMusicTransition
{
    GE_UNIMPL_STRUCT(gSMusicTransition)
};

class GE_DLLIMPORT gCMusicTransition : public gCMusicStream
{
    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~gCMusicTransition() override;
    protected: bEResult PostInitializeProperties() override;
    public: gEMusicStream GetStreamType() const override;
    protected: void OnSampleChanged() override;
    public: gCMusicStream * Clone() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCMusicTransition, gCMusicStream)
    GE_PROPERTY(bCString, ID, m_strID)
    GE_PROPERTY(GEInt, ConnectIn, m_iConnectIn)
    GE_PROPERTY(GEInt, ConnectOut, m_iConnectOut)
    GE_PROPERTY(GEU32, FadeInBegin, m_u32FadeInBegin)
    GE_PROPERTY(GEU32, FadeInEnd, m_u32FadeInEnd)
    GE_PROPERTY(GEU32, FadeOutBegin, m_u32FadeOutBegin)
    GE_PROPERTY(GEU32, FadeOutEnd, m_u32FadeOutEnd)
    GE_PROPERTY(GEU32, Offset, m_u32Offset)
    GE_ENUMPROP(gEMusicTransitionTiming, Timing, m_enuTiming)

  public:
    GEFloat CalcDstVolume(GEUInt) const;
    GEFloat CalcSrcVolume(GEUInt) const;
    eCAudioSound *CreateSound() const;
    void GetDescriptor(gSMusicTransition &) const;
    GEBool ImportOffset();
    GEBool MatchesConnectors(GEInt, GEInt) const;
    void SetDescriptor(gSMusicTransition const &);

  protected:
    void Invalidate();
    void UpdateFading();
};

GE_ASSERT_SIZEOF(gCMusicTransition, 0x4c)

GE_ASSERT_PROPERTY(gCMusicTransition, m_strID, 0x24, 4)
GE_ASSERT_PROPERTY(gCMusicTransition, m_iConnectIn, 0x28, 4)
GE_ASSERT_PROPERTY(gCMusicTransition, m_iConnectOut, 0x2c, 4)
GE_ASSERT_PROPERTY(gCMusicTransition, m_u32FadeInBegin, 0x30, 4)
GE_ASSERT_PROPERTY(gCMusicTransition, m_u32FadeInEnd, 0x34, 4)
GE_ASSERT_PROPERTY(gCMusicTransition, m_u32FadeOutBegin, 0x38, 4)
GE_ASSERT_PROPERTY(gCMusicTransition, m_u32FadeOutEnd, 0x3c, 4)
GE_ASSERT_PROPERTY(gCMusicTransition, m_u32Offset, 0x40, 4)
GE_ASSERT_PROPERTY(gCMusicTransition, m_enuTiming, 0x44, 8)
