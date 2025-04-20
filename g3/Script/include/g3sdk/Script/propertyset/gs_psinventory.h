#pragma once

#include "gs_propertymacros.h"

#include <Script/gs_template.h>

#include <Game.h>

class GE_DLLIMPORT PSInventory : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSInventory, gCInventory_PS)

  public:
    GEBool ActivateSkill(Template const &);
    GEInt ApplyQuality(GEInt, GEU32, GEInt);
    void ArrangeStacks();
    GEBool AssignStackToQuickSlot(GEInt, GEInt);
    void AssureAll();
    GEInt AssureItems(Template const &a_Item, GEU32 a_u32Quality, GEInt a_iAmount);
    GEInt AssureItemsEx(Template const &a_Item, GEU32 a_u32Quality, GEInt a_iAmount, GEInt a_iSlot, GEBool a_bLearn);
    GEBool ConsumeItems(GEInt, GEInt);
    GEInt CreateItems(Template const &a_Item, GEU32 a_u32Quality, GEInt a_iAmount);
    GEBool DeactivateSkill(Template const &);
    GEBool DeleteItems(GEInt, GEInt);
    GEBool DeleteStack(GEInt);
    Entity DropItemFromSlot(gESlot);
    Entity DropItemsFromSlot(gESlot, GEInt);
    Entity DropStack(GEInt, bCMatrix const &);
    GEBool EquipStack(GEInt);
    GEBool EquipStackToSlot(GEInt, gESlot);
    GEBool ExecuteItem(GEInt);
    GEInt FindStackIndex(Template const &, GEInt a_iStartIndexExclusive = -1, GEBool a_bNotLinked = GEFalse) const;
    GEInt FindStackIndex(gESlot) const;
    GEInt FindStackIndexByQuickSlot(GEInt) const;
    GEBool GeneratePlunderInvFromTreasureSets();
    GEBool GenerateTradeInvFromTreasureSets();
    GEInt GetAmount(GEInt) const;
    gEItemCategory GetCategory(GEInt) const;
    Entity GetDefaultItemFromSlot(gESlot) const;
    gESlot GetEquipSlot(gEUseType);
    gESlot GetEquipSlotAlt(gEUseType);
    GEInt GetGeneratedStackCount() const;
    GEInt GetItemAmount(Template const &) const;
    GEInt GetItemAmount(gEUseType) const;
    Entity GetItemFromSlot(gESlot) const;
    GEInt GetLargestStackForTransfer(Template const &, GEInt);
    bCString GetName(GEInt);
    GEU32 GetQuality(GEInt) const;
    GEU32 GetSkillActivationCount(Template const &) const;
    gESlot GetSlotFromStack(GEInt) const;
    GEInt GetStackCount() const;
    Template GetTemplate(GEInt) const;
    Entity GetTemplateItem(GEInt) const;
    Entity GetTreasureSet1() const;
    Entity GetTreasureSet2() const;
    Entity GetTreasureSet3() const;
    Entity GetTreasureSet4() const;
    Entity GetTreasureSet5() const;
    gEUseType GetUseType(GEInt) const;
    GEBool HasItems(Template const &, GEInt) const;
    GEBool HasItems(gEUseType, GEInt) const;
    GEBool HasLearnedSkill(Template const &) const;
    GEBool HasLearnedSpell(Template const &) const;
    GEBool HoldLeftStack(GEInt);
    GEBool HoldRightStack(GEInt);
    // Hat im Gegensatz zu AI_HoldInventory Items keine 'Raushol'-Animation
    GEBool HoldStacks(GEInt a_iIndexLeft, GEInt a_iIndexRight);
    GEInt InsertStack(Entity const &);
    GEBool IsGenerated(GEInt) const;
    GEBool IsGeneratedPlunder() const;
    GEBool IsGeneratedTrade() const;
    GEBool IsPermanent(GEInt) const;
    GEBool IsSkillActive(Template const &) const;
    GEBool IsStackMerchandise(GEInt);
    void MergeStacks();
    GEBool PrintMissingRequirements(int, GEBool) const;
    void PurgeItems(Template const &, GEInt);
    GEBool RefreshTradeInvFromTreasureSets();
    GEBool SetAmount(GEInt, GEU32);
    void SetGeneratedPlunder(GEBool);
    GEInt SetQuality(GEInt, GEU32, GEU32);
    void SortStacks();
    GEInt SplitStack(GEInt a_iItemIndex, GEInt a_iNewStackAmount);
    void StackTradingGold();
    void SwapSlots(gESlot, gESlot);
    GEInt Synthesize(Entity const &, GEInt);
    GEBool TeachSkill(Template const &);
    GEBool TeachSpell(Template const &);
    GEBool TransferAllTo(Entity &);
    GEBool TransferAmountTo(GEInt, GEInt, Entity &);
    GEBool UnEquipStack(GEInt);
    void UpdateVisibility();
    GEBool UseStack(GEInt);
};
