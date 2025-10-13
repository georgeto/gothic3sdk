#pragma once

#include <Game/GameEnum.h>
#include <Game/inventory/ge_inventorylistener.h>

#include <Engine.h>

class gCArmorSet_PS;
class gCInventorySlot;
class gCTreasureSet_PS;

enum gEInventoryFindQuality
{
    gEInventoryFindQuality_Ignore = 0,
    gEInventoryFindQuality_Equal = 1,
    gEInventoryFindQuality_Highest = 2,
    gEInventoryFindQuality_Lowset = 3
};

class GE_DLLIMPORT gCInventory_PS : public eCEntityPropertySet, public gCInventoryListener
{
  public:
    struct SMissingAttrib
    {
        bCString MissingAttribName;
        // Number of missing attribute points, i.e. the difference to the required value.
        GEInt MissingAttribValue;
    };

    struct SMissingSkill
    {
        eCTemplateEntity *MissingSkill;
    };

    enum EEvent
    {
        // TODO: Enumerator values
    };

    // clang-format off
    public: virtual void AddListener(gCInventoryListener *);
    public: virtual void RemoveListener(gCInventoryListener *);
    // Overrides for eCEntityPropertySet
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCInventory_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    public: GEBool SupportsRenderDebugOutput() const override;
    public: bEResult ReadSaveGame(bCIStream &) override;
    public: bEResult WriteSaveGame(bCOStream &) override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: void GetOnScreenDebugLines(GEU32, bTObjArray<eSPropertySetDebugLine> &) const override;
    public: void OnPostRead() override;
    public: void OnChildrenAvailable(GEU32, GEU32, eCTemplateEntity *) override;
    // Overrides for gCInventoryListener
    public: void OnStackCreate(GEInt, gCInventoryStack const *) override;
    public: void OnStackChange(GEInt, gCInventoryStack const *) override;
    public: void OnStackDelete(GEInt, gCInventoryStack const *) override;
    public: void OnSortInventory() override;
    public: void OnDestroyInventory() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCInventory_PS, eCEntityPropertySet)
    GE_PROPERTY(GEBool, GeneratedPlunder, m_bGeneratedPlunder)
    GE_PROPERTY(GEBool, GeneratedTrade, m_bGeneratedTrade)
    GE_PADDING(2)
    GE_PROPERTY(bCString, TreasureSet1, m_strTreasureSet1)
    GE_PROPERTY(bCString, TreasureSet2, m_strTreasureSet2)
    GE_PROPERTY(bCString, TreasureSet3, m_strTreasureSet3)
    GE_PROPERTY(bCString, TreasureSet4, m_strTreasureSet4)
    GE_PROPERTY(bCString, TreasureSet5, m_strTreasureSet5)

  public:
    static GEBool GE_STDCALL IsSkinnedSlot(gESlot);

  public:
    GEBool ActivateSkill(eCTemplateEntity const *);
    GEInt AssureItems(bCPropertyID const &, GEU32, GEU32);
    GEBool CanEquip(GEInt, bTObjArray<SMissingAttrib> &, bTValArray<SMissingSkill> &) const;
    GEBool CanLearnSkill(eCTemplateEntity const *) const;
    GEBool ConsumeItems(GEInt, GEU32);
    GEInt CreateItems(bCPropertyID const &, GEU32, GEU32);
    GEInt CreateItems(eCTemplateEntity const *, GEU32, GEU32);
    GEInt CreateItems(eCTemplateEntity const *, GEU32, GEU32, gEStackType);
    GEInt CreateStack();
    GEBool DeactivateSkill(eCTemplateEntity const *);
    GEBool DeleteItems(GEInt, GEU32);
    GEBool DeleteStack(GEInt);
    eCEntity *DropItemsFromSlot(gESlot, GEInt, bCMatrix const *);
    eCEntity *DropItemsFromStack(GEInt, GEInt, bCMatrix const *);
    eCEntity *DropSlot(gESlot, bCMatrix const *);
    eCEntity *DropStack(GEInt, bCMatrix const *);
    void Dump() const;
    GEBool EquipStack(GEInt);
    GEBool EquipStackToSlot(GEInt, gESlot);
    gCInventoryStack const *FindStack(
        bCPropertyID const &, gEInventoryFindQuality = gEInventoryFindQuality_Ignore, GEU32 a_u32Quality = 0,
        GEInt a_iStartIndexExclusive = -1) const; // Nur bei gEInventoryFindQuality_Equal ist a_u32Quality relevant
    gCInventoryStack const *FindStack(bCString const &, gEInventoryFindQuality = gEInventoryFindQuality_Ignore,
                                      GEU32 a_u32Quality = 0, GEInt a_iStartIndexExclusive = -1) const;
    gCInventoryStack const *FindStack(eCTemplateEntity const *, gEInventoryFindQuality = gEInventoryFindQuality_Ignore,
                                      GEU32 a_u32Quality = 0, GEInt a_iStartIndexExclusive = -1) const;
    gCInventoryStack const *FindStack(gESlot) const;
    gCInventoryStack const *FindStack(gEUseType, gEInventoryFindQuality = gEInventoryFindQuality_Ignore,
                                      GEU32 a_u32Quality = 0, GEInt a_iStartIndexExclusive = -1) const;
    GEInt FindStackIndex(bCPropertyID const &, gEInventoryFindQuality = gEInventoryFindQuality_Ignore,
                         GEU32 a_u32Quality = 0, GEInt a_iStartIndexExclusive = -1) const;
    GEInt FindStackIndex(bCString const &, gEInventoryFindQuality = gEInventoryFindQuality_Ignore,
                         GEU32 a_u32Quality = 0, GEInt a_iStartIndexExclusive = -1) const;
    GEInt FindStackIndex(eCTemplateEntity const *, gEInventoryFindQuality = gEInventoryFindQuality_Ignore,
                         GEU32 a_u32Quality = 0, GEInt a_iStartIndexExclusive = -1) const;
    GEInt FindStackIndex(gESlot) const;
    GEInt FindStackIndex(gEUseType, gEInventoryFindQuality = gEInventoryFindQuality_Ignore, GEU32 a_u32Quality = 0,
                         GEInt a_iStartIndexExclusive = -1) const;
    GEInt FindStackIndexByHotKey(GEU32) const;
    GEBool GeneratePlunderInvFromTreasureSets();
    GEBool GenerateTradeInvFromTreasureSets();
    void GetDefaultItem(gESlot, bCPropertyID &) const;
    gCInventorySlot *GetDefaultSlot(gESlot);
    gCInventorySlot const *GetDefaultSlot(gESlot) const;
    void GetEquipSlots(gEUseType, gESlot &, gESlot &, gESlot &) const;
    gESlot GetLeftEquipSlot(GEInt);
    gESlot GetRightEquipSlot(GEInt);
    GEInt GetSkillActivationCount(eCTemplateEntity const *) const;
    gCInventoryStack *GetStack(GEInt);
    gCInventoryStack const *GetStack(GEInt) const;
    gEItemCategory GetStackCategory(GEInt) const;
    GEInt GetStackCount() const;
    eCEntity *GetStackFromSlot(gESlot) const;
    gEUseType GetStackUseType(GEInt) const;
    GEInt GetTransactionAmount(GEInt) const;
    gCTreasureSet_PS *GetTreasureSetPS(gETreasureDistribution) const;
    gCTreasureSet_PS *GetTreasureSetPS1() const;
    gCTreasureSet_PS *GetTreasureSetPS2() const;
    gCTreasureSet_PS *GetTreasureSetPS3() const;
    gCTreasureSet_PS *GetTreasureSetPS4() const;
    gCTreasureSet_PS *GetTreasureSetPS5() const;
    GEBool HasLearnedSkill(eCTemplateEntity const *) const;
    GEBool HasLearnedSpell(eCTemplateEntity const *) const;
    GEBool HasTreasureSet(gETreasureDistribution) const;
    GEBool HoldStackLeftHand(GEInt);
    GEBool HoldStackRightHand(GEInt);
    GEBool HoldStacks(GEInt a_iIndexLeft, GEInt a_iIndexRight);
    GEInt InsertStack(eCEntity *);
    GEBool IsDisplaySlot(gESlot) const;
    GEBool IsDisplayStack(GEInt) const;
    GEBool IsEquipped(gCArmorSet_PS const *) const;
    GEBool IsSkillActive(eCTemplateEntity const *) const;
    GEBool IsValidIndex(GEInt) const;
    GEBool LearnSkill(eCTemplateEntity const *);
    GEBool LearnSpell(eCTemplateEntity const *);
    GEBool LearnStack(GEInt);
    GEBool LinkStackToSlot(GEInt, gESlot, GEBool);
    void MergeStacks();
    GEBool PerformTransaction(gCInventory_PS *, gEStackType, gEStackType);
    GEBool RefreshTradeInvFromTreasureSets();
    void SetDefaultItem(gESlot, bCPropertyID const &);
    GEBool SetStackAmount(GEInt, GEU32);
    void SetStackHotKey(GEInt, GEU32);
    GEBool SetStackQuality(GEInt, GEU32);
    GEBool SetTransactionAmount(GEInt, GEInt);
    GEBool ShowSlot(GEBool, gESlot);
    void SortStacks();
    GEBool SplitStack(GEInt a_iItemIndex, GEU32 a_uNewStackAmount, GEInt &);
    GEBool TransferAllTo(gCInventory_PS *, gEStackType);
    GEBool TransferItemsTo(gCInventory_PS *, GEInt, GEInt, gEStackType);
    GEBool TransferStackTo(gCInventory_PS *, GEInt, gEStackType);
    GEBool UnEquipStack(GEInt);
    GEInt UnlinkStackFromSlot(gESlot);
    GEBool UpdateVisibility();

  protected:
    GEBool ClearDefaultItems();
    GEInt FindListenerIndex(gCInventoryListener *) const;
    void Invalidate();
    GEBool IsArmorPieceEquipped(eCTemplateEntity const *) const;
    GEBool LinkDefaultItemToSlot(gESlot);
    GEBool LinkDefaultItems();
    void NotifyListeners(EEvent, GEInt, gCInventoryStack const *);
    void NotifyQuestManager(eCEntity const *, eCEntity const *, bCPropertyID const &, GEInt);
    GEBool PatchDefaultItems();
    GEBool PatchTreasureSets();
    void PurgeListeners();
    GEBool ReadV3(bCIStream &);
    GEBool ReadV4(bCIStream &);
    GEBool ReadV5(bCIStream &);
    GEBool ReadV6(bCIStream &);
    GEBool ReadV7(bCIStream &);
    GEBool ReadV8(bCIStream &);
    GEBool ReadV9(bCIStream &);
    GEBool TransferTransactionItemsTo(gCInventory_PS *, gEStackType);
    GEBool UnlinkDefaultItemFromSlot(gESlot);
    GEBool UnlinkDefaultItems();

  private:
    GEInt FindSkillStackIndex(eCTemplateEntity const *) const;
    GEInt FindSpellStackIndex(eCTemplateEntity const *) const;

  private:
    friend class gCInventory_PS_AH;

  private:
    GE_UNIMPL_MEMBERS(184)
};

GE_ASSERT_SIZEOF(gCInventory_PS, 0xe8)

GE_ASSERT_PROPERTY(gCInventory_PS, m_bGeneratedPlunder, 0x18, 1)
GE_ASSERT_PROPERTY(gCInventory_PS, m_bGeneratedTrade, 0x19, 1)
GE_ASSERT_PROPERTY(gCInventory_PS, m_strTreasureSet1, 0x1c, 4)
GE_ASSERT_PROPERTY(gCInventory_PS, m_strTreasureSet2, 0x20, 4)
GE_ASSERT_PROPERTY(gCInventory_PS, m_strTreasureSet3, 0x24, 4)
GE_ASSERT_PROPERTY(gCInventory_PS, m_strTreasureSet4, 0x28, 4)
GE_ASSERT_PROPERTY(gCInventory_PS, m_strTreasureSet5, 0x2c, 4)

class gCInventory_PS_AH
{
  public:
    static inline GEInt FindSkillStackIndex(gCInventory_PS const *a_pInventory, eCTemplateEntity const *a_pSkill)
    {
        return a_pInventory->FindSkillStackIndex(a_pSkill);
    };

    static inline GEInt FindSpellStackIndex(gCInventory_PS const *a_pInventory, eCTemplateEntity const *a_pSpell)
    {
        return a_pInventory->FindSpellStackIndex(a_pSpell);
    };
};
