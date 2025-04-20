#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT gCSessionCheats : public bCObjectRefBase
{
    // clang-format off
    public: virtual void CopyFrom(gCSessionCheats const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~gCSessionCheats() override;
    public: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCSessionCheats, bCObjectRefBase)
    GE_PROPERTY(GEBool, CheatGodEnabled, m_bCheatGodEnabled)
    GE_PROPERTY(GEBool, CheatInvisibleEnabled, m_bCheatInvisibleEnabled)
    GE_PADDING(1)

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void Invalidate();
    void Process();
};

GE_ASSERT_SIZEOF(gCSessionCheats, 0x10)

GE_ASSERT_PROPERTY(gCSessionCheats, m_bCheatGodEnabled, 0xc, 1)
GE_ASSERT_PROPERTY(gCSessionCheats, m_bCheatInvisibleEnabled, 0xd, 1)
