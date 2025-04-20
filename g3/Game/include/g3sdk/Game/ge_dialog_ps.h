#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCDialog_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCDialog_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsProcessable() const override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void OnProcess() override;
    public: void OnPreProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCDialog_PS, eCEntityPropertySet)
    GE_PROPERTY(GEBool, TalkedToPlayer, m_bTalkedToPlayer)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, EndDialogTimestamp, m_fEndDialogTimestamp)
    GE_PROPERTY(GEBool, TradeEnabled, m_bTradeEnabled)
    GE_PADDING(3)
    GE_ENUMPROP(gETradeCategory, TradeCategory, m_enuTradeCategory)
    GE_PROPERTY(GEBool, TeachEnabled, m_bTeachEnabled)
    GE_PROPERTY(GEBool, PartyEnabled, m_bPartyEnabled)
    GE_PROPERTY(GEBool, MobEnabled, m_bMobEnabled)
    GE_PROPERTY(GEBool, SlaveryEnabled, m_bSlaveryEnabled)
    GE_PROPERTY(GEBool, PickedPocket, m_bPickedPocket)
    GE_PADDING(1)

  public:
    GEInt AddTalkedToBy(eCEntity *);
    eCEntity *GetTalkedToBy(GEInt) const;
    GEInt GetTalkedToByCount() const;
    eCEntity *GetTalkingTo() const;
    GEBool RemoveTalkedToBy(eCEntity *);
    void SetTalkingTo(eCEntity *);

  protected:
    void Invalidate();

  private:
    eCEntityProxy m_TalkingTo;
    bTObjArray<eCEntityProxy> m_arrTalkedToBy;
};

GE_ASSERT_SIZEOF(gCDialog_PS, 0x58)

GE_ASSERT_PROPERTY(gCDialog_PS, m_bTalkedToPlayer, 0x14, 1)
GE_ASSERT_PROPERTY(gCDialog_PS, m_fEndDialogTimestamp, 0x18, 4)
GE_ASSERT_PROPERTY(gCDialog_PS, m_bTradeEnabled, 0x1c, 1)
GE_ASSERT_PROPERTY(gCDialog_PS, m_enuTradeCategory, 0x20, 8)
GE_ASSERT_PROPERTY(gCDialog_PS, m_bTeachEnabled, 0x28, 1)
GE_ASSERT_PROPERTY(gCDialog_PS, m_bPartyEnabled, 0x29, 1)
GE_ASSERT_PROPERTY(gCDialog_PS, m_bMobEnabled, 0x2a, 1)
GE_ASSERT_PROPERTY(gCDialog_PS, m_bSlaveryEnabled, 0x2b, 1)
GE_ASSERT_PROPERTY(gCDialog_PS, m_bPickedPocket, 0x2c, 1)
