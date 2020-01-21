#include "World_SaveLayer.h"

#include "Game.h"

#include "util/Util.h"

bCString CMD_World_Sub::SaveLayer( bTObjArray< bCString > a_arrParams )
{
    gCLayerBase * pLayer = GetLayer( a_arrParams[ 0 ] );
    if ( !pLayer )
        return "$Dynamic layer not found.";
    eCArchiveFile File = eCArchiveManager::GetInstance().GetFile( pLayer->GetFilePath() );
    if ( File.IsReadOnly() )
        return "$" + File.GetFileName() + " is not physical.";

    if ( !pLayer->Save() )
        return "$Could not write to " + File.GetFilePath() + "." ;
    return File.GetFilePath() + " has been saved.";
}