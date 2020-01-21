#include "Entity_Equip.h"

#include "Script.h"
#include "util/Util.h"

bCString CMD_Entity_Sub::Equip( bTObjArray< bCString > a_arrParams )
{
    Entity FocusEntity = Entity::GetPlayer().Focus.GetFocusEntity();

    if( FocusEntity == None )
        return "$No focused entity found.";

    if( !FocusEntity.IsNPC() )
        return bCString::GetFormattedString("$Focused entity %s isn't an NPC.", FocusEntity.GetName().GetText());

    Template Item( a_arrParams[0] );
    if( !Item.IsValid() )
        return bCString::GetFormattedString("$Unable to find the item %s.", a_arrParams[0] );

    GEInt iStackIndex = FocusEntity.Inventory.FindStackIndex( Item, -1, GETrue );

    if( iStackIndex == -1 )
    {
        eCSceneAdmin* pSceneAdmin = dynamic_cast< eCSceneAdmin * >( eCModuleAdmin::GetInstance().FindModule( "eCSceneAdmin" ));
        if( pSceneAdmin == 0 )
            return "$Unable to find scene admin.";

        eCTemplateEntity* pTemplateEntity = pSceneAdmin->GetTemplateEntityByName( a_arrParams[0] );
        if( pTemplateEntity == 0 )
            return bCString::GetFormattedString("$Unable to find the item %s.", a_arrParams[0] );

        Entity TemplateEntity( pTemplateEntity );
        if( !TemplateEntity.Item.IsValid() )
            return bCString::GetFormattedString("$Unable to find the item %s.", a_arrParams[0] );

        iStackIndex = FocusEntity.Inventory.CreateItems(Item, TemplateEntity.Item.GetQuality(), 1);
    }

    if( FocusEntity.Inventory.EquipStack(iStackIndex))
        return bCString::GetFormattedString("Equipped %s with %s.", FocusEntity.GetName(), a_arrParams[0] );
    return bCString::GetFormattedString("Equipping %s with %s failed. Is the Item equipable?", FocusEntity.GetName(), a_arrParams[0] );
}
