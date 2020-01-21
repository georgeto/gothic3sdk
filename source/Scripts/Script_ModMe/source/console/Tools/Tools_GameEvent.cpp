#include "Tools_GameEvent.h"

#include "Script.h"
#include "util/Util.h"

bCString CMD_Tools_Sub::ClearGameEvent( bTObjArray< bCString > a_arrParams )
{
    Entity player = Entity::GetPlayer();

    bTObjArray<bCString> Result;
    bTObjArray<bCString> arrGameEvents = SplitString(a_arrParams[0], ";");
    for(GEInt i = 0; i < arrGameEvents.GetCount(); i++)
    {
        bCString const & strGameEvent = arrGameEvents[i];
        if( !player.PlayerMemory.IsSetGameEvent( strGameEvent ) )
        {
            Result.Add(bCString::GetFormattedString( "%s was not set.", strGameEvent ));
        }
        else if( player.PlayerMemory.ClearGameEvent( strGameEvent ) )
        {
            Result.Add(bCString::GetFormattedString( "%s has been cleared.", strGameEvent ));
        }
        else
        {
            return bCString::GetFormattedString( "$Could not clear %s.", strGameEvent );
        }
    }

    return JoinString(Result, 0, "\n");
}

bCString CMD_Tools_Sub::GameEventAC( bTObjArray< bCString > a_arrParams )
{
    eCEntity const * pPlayer = gCSession::GetInstance().GetPlayer();
    if( pPlayer == 0 )
        return JoinString( a_arrParams );

    gCPlayerMemory_PS const * pPlayerMemory = dynamic_cast< gCPlayerMemory_PS const * >( pPlayer->GetPropertySet( eEPropertySetType_PlayerMemory ) );
    if( pPlayerMemory == 0)
        return JoinString( a_arrParams );

    bTObjArray< bCString > const & arrGameEvents = pPlayerMemory->GetPlayerKnows();
    AutoCompleteString( arrGameEvents, a_arrParams[0], mCCommandHandler::GetInstance().IsAutoCompleteBackward() );

    return JoinString( a_arrParams );
}

bCString CMD_Tools_Sub::SetGameEvent( bTObjArray< bCString > a_arrParams )
{
    Entity player = Entity::GetPlayer();

    bTObjArray<bCString> Result;
    bTObjArray<bCString> arrGameEvents = SplitString(a_arrParams[0], ";");
    for(GEInt i = 0; i < arrGameEvents.GetCount(); i++)
    {
        bCString const & strGameEvent = arrGameEvents[i];
        if( player.PlayerMemory.IsSetGameEvent( strGameEvent ) )
        {
            Result.Add(bCString::GetFormattedString( "%s was already set.", strGameEvent ));
        }
        else if( player.PlayerMemory.SetGameEvent( strGameEvent ) )
        {
            Result.Add(bCString::GetFormattedString( "%s has been set.", strGameEvent ));
        }
        else
        {
            return bCString::GetFormattedString( "$Could not set %s.", strGameEvent );
        }
    }

    return JoinString(Result, 0, "\n");
}

bCString CMD_Tools_Sub::IsSetGameEvent( bTObjArray< bCString > a_arrParams )
{
    Entity player = Entity::GetPlayer();

    bTObjArray<bCString> Result;
    bTObjArray<bCString> arrGameEvents = SplitString(a_arrParams[0], ";");
    for(GEInt i = 0; i < arrGameEvents.GetCount(); i++)
    {
        bCString const & strGameEvent = arrGameEvents[i];
        if( player.PlayerMemory.IsSetGameEvent( strGameEvent ))
            Result.Add(bCString::GetFormattedString( "%s is set.", strGameEvent ));
        else
            Result.Add(bCString::GetFormattedString( "%s is not set.", strGameEvent ));
    }

    return JoinString(Result, 0, "\n");
}
