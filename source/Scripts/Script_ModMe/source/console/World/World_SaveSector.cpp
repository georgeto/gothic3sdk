#include "World_SaveSector.h"

#include "Game.h"

#include "util/Util.h"

bCString CMD_World_Sub::SaveSector( bTObjArray< bCString > a_arrParams )
{
    gCWorld * pWorld = gCWorld::GetCurrentWorld();
    gCSector * pSector = pWorld->GetSector( a_arrParams[ 0 ] );
    if ( !pSector )
        return "$Unknown sector";

    if ( IsPhysical( pSector->GetFilePath() ) )
    {
        if ( !pSector->Save() )
            return "$Failed to save " + GetPhysicalFilePath( pSector->GetFilePath() ) + ".";
    }
    else
        return "$" + pSector->GetFilePath() + " is not physical.";

    GEInt iSkippedFileCount = 0;
    for ( GEInt i = 0, ie = pSector->GetDynamicLayerCount(); i != ie; ++i )
    {
        gCDynamicLayer * pLayer = pSector->GetDynamicLayerAt(i);
        if ( IsPhysical( pLayer->GetFilePath() ) )
        {
            if ( !pLayer->Save() )
                return "$Failed to save " + GetPhysicalFilePath( pLayer->GetFilePath() ) + ".";
        }
        else
            ++iSkippedFileCount;
    }

    return bCString::GetFormattedString( "%s and %i dynamic layer(s) have been successfully saved. Skipped %i non-physical file(s).", pSector->GetFileBaseName(), ( pSector->GetDynamicLayerCount() - iSkippedFileCount ), iSkippedFileCount );
}