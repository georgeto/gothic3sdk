#include "Entity_LogInventory.h"

#include "Script.h"
#include "util/Util.h"
#include "util/Logging.h"

bCString CMD_Entity_Sub::LogInventory( bTObjArray< bCString > a_arrParams )
{
    Entity FocusEntity = Entity::GetPlayer().Focus.GetFocusEntity();

    if( FocusEntity == None )
        return "$No focused entity found.";

    if( !FocusEntity.IsNPC() )
        return bCString::GetFormattedString("$Focused entity %s isn't an NPC.", FocusEntity.GetName().GetText());

    mCFileLogger & Logger = mCFileLogger::GetInstance("Inventory");
    Logger.LogFormat("\n\nInventar von %s\n", FocusEntity.GetName());
    PSInventory const & Inventory = FocusEntity.Inventory;
    for(GEInt i = 0; i < Inventory->GetStackCount(); i++)
    {
        gCInventoryStack const * pStack = Inventory->GetStack(i);
        eCEntity const * pItem = pStack->GetItem().GetEntity();
        bCString strName;
        if(pItem)
        {
            bCString const & strItemName = pItem->GetName();
            bCString const & strTemplateName = pStack->GetTemplate().GetEntity()->GetName();
            strName = strItemName == strTemplateName ? strItemName : (strItemName + " vs. " + strTemplateName);
        }
        else
        {
            strName = pStack->GetTemplate().GetEntity()->GetName();
        }

        bCString strType = pStack->GetType().GetValue() == gEStackType_Normal ? "Normal" : (pStack->GetType().GetValue() == gEStackType_Treasure ? "Treasure" : "Merchandise");

        Logger.LogFormat("%d - %s x %d%s: Type = %s, Quality = %d, UseType = %d, Slot = %d, QuickSlot = %d, Category = %d, CombinedQuality = %d, Learned = %d, SortIndex = %d, ActivationCount = %d, TransactionAmount = %d, TransactionCount = %d, TransferAmount = %d, TransferRemainder = %d\n", i, strName, pStack->GetAmount(),
            pItem ? "" : " (No Item)", strType, pStack->GetQuality(),
            pStack->GetUseType(), pStack->GetSlot().GetValue(), pStack->GetQuickSlot(), pStack->GetCategory(),
            pStack->GetCombinedQuality(), !!pStack->GetLearned(), pStack->GetSortIndex(),
            pStack->GetActivationCount(), pStack->GetTransactionAmount(), pStack->GetTransactionCount(), pStack->GetTransferAmount(), pStack->GetTransferRemainder());
    }
    return "Written to Inventory.log";
}
