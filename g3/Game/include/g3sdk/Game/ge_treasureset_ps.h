#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class gCInventory_PS;

class GE_DLLIMPORT gCTreasureSet_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~gCTreasureSet_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsVisual() const override;
    public: void GetBoundary(bCBox &, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCTreasureSet_PS, eCEntityPropertySet)
    GE_ENUMPROP(gETreasureDistribution, TreasureDistribution, m_enuTreasureDistribution)
    GE_PROPERTY(GEU32, MinTransferStacks, m_iMinTransferStacks)
    GE_PROPERTY(GEU32, MaxTransferStacks, m_iMaxTransferStacks)

  public:
    GEBool GeneratePlunderInventory(gCInventory_PS *);
    GEBool GenerateTradeInventory(gCInventory_PS *);
    GEBool RefreshTradeInventory(gCInventory_PS *);

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCTreasureSet_PS, 0x24)

GE_ASSERT_PROPERTY(gCTreasureSet_PS, m_enuTreasureDistribution, 0x14, 8)
GE_ASSERT_PROPERTY(gCTreasureSet_PS, m_iMinTransferStacks, 0x1c, 4)
GE_ASSERT_PROPERTY(gCTreasureSet_PS, m_iMaxTransferStacks, 0x20, 4)
