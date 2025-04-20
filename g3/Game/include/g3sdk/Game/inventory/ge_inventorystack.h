#pragma once

#include <Game/GameEnum.h>
#include <Game/inventory/ge_inventoryslot.h>

#include <Engine.h>

class GE_DLLIMPORT gCInventoryStack : public gCInventorySlot
{
    // clang-format off
    public: void Destroy() override;
    public: ~gCInventoryStack() override;
    public: bEResult PostInitializeProperties() override;
    protected: void OnApplyStats(eCEntity *, eCEntity *) override;
    protected: void OnUnApplyStats(eCEntity *, eCEntity *) override;
    public: gCInventoryStack * Clone() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCInventoryStack, gCInventorySlot)
    GE_PROPERTY(GEInt, Amount, m_iAmount)
    GE_PROPERTY(GEInt, Quality, m_iQuality)
    GE_PROPERTY(GEInt, QuickSlot, m_iQuickSlot) // Read only
    GE_PROPERTY(GEInt, SortIndex, m_iSortIndex) // Read only
    // NOTE: Incorrectly named "Generated" in property meta data.
    GE_ENUMPROP(gEStackType, Type, m_enuType) // Read only
    GE_PROPERTY(GEBool, Learned, m_bLearned)  // Read only
    GE_PADDING(3)
    GE_PROPERTY(GEInt, ActivationCount, m_iActivationCount)    // Read only
    GE_PROPERTY(GEInt, TransactionCount, m_iTransactionAmount) // Read only

  public:
    GEBool CanMerge(gCInventoryStack const &) const;
    GEInt Compare(gCInventoryStack const &) const;
    eCEntity *Drop(eCEntity *);
    GEU32 GetCombinedQuality() const;
    CFFGFCBitmap *GetIcon();
    GEInt GetItemGoldValue() const;
    GEInt GetStackGoldValue() const;
    GEInt GetTransactionAmount() const;
    GEInt GetTransferAmount() const;
    GEInt GetTransferRemainder() const;
    GEBool IsDisposable() const;
    GEBool IsEmpty() const;
    GEBool IsEquipped(eCEntity const *) const;
    GEBool IsEquippedInAlternative(eCEntity const *) const;
    GEBool IsEquippedInPrimary(eCEntity const *) const;
    GEBool IsEquippedToSlot(gESlot) const;
    GEBool IsMergable() const;
    GEBool Merge(gCInventoryStack *);
    GEBool MustSplitBeforeLinking(gESlot, eCEntity *) const;
    void SetTransactionAmount(GEInt);
    gCInventoryStack *Split(GEInt);

  protected:
    void ApplyDefaults();
    GEInt CompareAlchemy(gCInventoryStack const &) const;
    GEInt CompareArmor(gCInventoryStack const &) const;
    GEInt CompareArmorType(gCInventoryStack const &) const;
    GEInt CompareArtefact(gCInventoryStack const &) const;
    GEInt CompareDamage(gCInventoryStack const &) const;
    GEInt CompareDefault(gCInventoryStack const &) const;
    GEInt CompareDocument(gCInventoryStack const &) const;
    GEInt CompareFocusName(gCInventoryStack const &) const;
    GEInt CompareMisc(gCInventoryStack const &) const;
    GEInt CompareName(gCInventoryStack const &) const;
    GEInt ComparePotionType(gCInventoryStack const &) const;
    GEInt CompareProtection(gCInventoryStack const &) const;
    GEInt CompareQuality(gCInventoryStack const &) const;
    GEInt CompareQuickSlot(gCInventoryStack const &) const;
    GEInt CompareRecipe(gCInventoryStack const &) const;
    GEInt CompareSkill(gCInventoryStack const &) const;
    GEInt CompareSlot(gCInventoryStack const &) const;
    GEInt CompareSpell(gCInventoryStack const &) const;
    GEInt CompareTemplate(gCInventoryStack const &) const;
    GEInt CompareType(gCInventoryStack const &) const;
    GEInt CompareValue(gCInventoryStack const &) const;
    GEInt CompareWeapon(gCInventoryStack const &) const;
    GEInt CompareWeaponType(gCInventoryStack const &) const;
    void CreateIcons();
    void GetIconFileNames(bCString &, bCString &) const;
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(16)
};

GE_ASSERT_SIZEOF(gCInventoryStack, 0x70)

GE_ASSERT_PROPERTY(gCInventoryStack, m_iAmount, 0x3c, 4)
GE_ASSERT_PROPERTY(gCInventoryStack, m_iQuality, 0x40, 4)
GE_ASSERT_PROPERTY(gCInventoryStack, m_iQuickSlot, 0x44, 4)
GE_ASSERT_PROPERTY(gCInventoryStack, m_iSortIndex, 0x48, 4)
GE_ASSERT_PROPERTY(gCInventoryStack, m_enuType, 0x4c, 8)
GE_ASSERT_PROPERTY(gCInventoryStack, m_bLearned, 0x54, 1)
GE_ASSERT_PROPERTY(gCInventoryStack, m_iActivationCount, 0x58, 4)
GE_ASSERT_PROPERTY(gCInventoryStack, m_iTransactionAmount, 0x5c, 4)
