#pragma once

#include <Game/GameEnum.h>

#include <SharedBase.h>

struct gSMusicLink
{
    GE_UNIMPL_STRUCT(gSMusicLink)
};

class GE_DLLIMPORT gCMusicLink : public bCObjectRefBase
{
    // clang-format off
    public: virtual gCMusicLink * Clone() const;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~gCMusicLink() override;
    protected: bEResult PostInitializeProperties() override;
    protected: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCMusicLink, bCObjectRefBase)
    GE_PROPERTY(GEU32, Offset, m_u32Offset)
    GE_PROPERTY(GEInt, ConnectIn, m_iConnectIn)
    GE_PROPERTY(GEInt, ConnectOut, m_iConnectOut)
    GE_PROPERTY(GEBool, IsPriority, m_bIsPriority)
    GE_PADDING(3)
    GE_ENUMPROP(gEMusicLink, Type, m_enuType)

  public:
    void GetDescriptor(gSMusicLink &) const;
    void SetDescriptor(gSMusicLink const &);

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCMusicLink, 0x24)

GE_ASSERT_PROPERTY(gCMusicLink, m_u32Offset, 0xc, 4)
GE_ASSERT_PROPERTY(gCMusicLink, m_iConnectIn, 0x10, 4)
GE_ASSERT_PROPERTY(gCMusicLink, m_iConnectOut, 0x14, 4)
GE_ASSERT_PROPERTY(gCMusicLink, m_bIsPriority, 0x18, 1)
GE_ASSERT_PROPERTY(gCMusicLink, m_enuType, 0x1c, 8)
