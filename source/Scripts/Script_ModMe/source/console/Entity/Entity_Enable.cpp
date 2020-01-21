#include "Entity_Enable.h"

#include "Script.h"
#include "util/Util.h"

bCString CMD_Entity_Sub::Enable( bTObjArray< bCString > a_arrParams )
{
    eCSceneAdmin* pSceneAdmin = dynamic_cast< eCSceneAdmin * >( eCModuleAdmin::GetInstance().FindModule( "eCSceneAdmin" ));
    if( pSceneAdmin == 0 )
        return "$Unable to find scene admin.";

    eCEntity * pEntity = pSceneAdmin->GetEntityByName(a_arrParams[0]);

    if( !pEntity )
        return bCString::GetFormattedString("$Unable to find entity with the name %s.", a_arrParams[0]);

    GEBool bEnable = a_arrParams[1].GetBool();

    if(pEntity->IsEnabled() == bEnable)
        return bCString::GetFormattedString("$Status of entity %s was already %s.", pEntity->GetName(), bEnable ? "on" : "off");

    pEntity->Enable(bEnable);
    return bCString::GetFormattedString("Changed status of entity %s to %s.", pEntity->GetName(), bEnable ? "on" : "off");
}
