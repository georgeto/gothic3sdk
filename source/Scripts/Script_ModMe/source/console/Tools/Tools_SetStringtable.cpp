#include "Tools_SetStringtable.h"

#include "Script.h"
#include "util/Util.h"

bCString CMD_Tools_Sub::SetStringtable( bTObjArray< bCString > a_arrParams )
{
    //Stringtable key
    const bCString& Key = a_arrParams[0];

    //Stringtable entry
    eCLocTable::SEntry Entry;
    Entry.Text = JoinString( a_arrParams, 1 );
    Entry.StageDirection = bCUnicodeString();

    GEBool bExistsKey = eCLocAdmin::GetInstance().ExistsID( Key );

    if(eCLocAdmin::GetInstance().SetString( Key, Entry )) {
        return bCString::GetFormattedString( "%s the entry '%s'.", bExistsKey ? "Replaced" : "Inserted", Key.GetText() );
    } else {
        return bCString::GetFormattedString("$Could not %s the entry '%s'.", bExistsKey ? "replace" : "insert", Key.GetText() );
    }
}
