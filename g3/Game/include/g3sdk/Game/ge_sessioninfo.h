#pragma once

#include <SharedBase.h>

class gCSessionCheats;

class GE_DLLIMPORT gCSessionInfo : public bCObjectRefBase
{
    // clang-format off
    public: virtual void CopyFrom(gCSessionInfo const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~gCSessionInfo() override;
    public: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCSessionInfo, bCObjectRefBase)
    GE_PROPERTY(bCString, Name, m_strName)
    GE_PROPERTY(GEFloat, NumHoursPlayed, m_fNumHoursPlayed)
    GE_PROPERTY(GEBool, PlayerHasCheated, m_bPlayerHasCheated)
    GE_PADDING(1)

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    gCSessionCheats &GetCheats();
    gCSessionCheats const &GetCheats() const;
    void Invalidate();
    void Process();

  private:
    GE_UNIMPL_MEMBERS(16)
};

GE_ASSERT_SIZEOF(gCSessionInfo, 0x28)

GE_ASSERT_PROPERTY(gCSessionInfo, m_strName, 0xc, 4)
GE_ASSERT_PROPERTY(gCSessionInfo, m_fNumHoursPlayed, 0x10, 4)
GE_ASSERT_PROPERTY(gCSessionInfo, m_bPlayerHasCheated, 0x14, 1)
