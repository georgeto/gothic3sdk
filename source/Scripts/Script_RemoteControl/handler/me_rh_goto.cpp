#include "me_rh_goto.h"

#include "Game.h"

#include "util/Util.h"

using namespace g3rc;

void mCGotoRequestHandler::HandleRequest()
{
    GotoRequest const & Request = m_RequestContainer->goto_request();

    GEBool bFoundPosition = GEFalse;
    bCVector TargetPosition;
    if( Request.has_name() )
    {
        if( eCEntity const * pEntity = GetEntityByName( Request.name() ) )
        {
            TargetPosition.SetVector( pEntity->GetWorldPosition() );
            bFoundPosition = GETrue;
        }
    }
    else if( Request.has_guid() )
    {
        if( eCEntity const * pEntity = GetEntityByGuid( Request.guid() ) )
        {
            TargetPosition.SetVector( pEntity->GetWorldPosition() );
            bFoundPosition = GETrue;
        }
    }
    else if( Request.has_position() )
    {
        TargetPosition.SetX( Request.position().x() );
        TargetPosition.SetY( Request.position().y() );
        TargetPosition.SetZ( Request.position().z() );
        bFoundPosition = GETrue;
    }

    if( bFoundPosition )
    {
        if( eCEntity * pPlayer = gCSession::GetInstance().GetPlayer() )
            pPlayer->SetWorldPosition( TargetPosition );
    }
    else
        return FailAndPrintMessage( "Ziel-Entity nicht gefunden." );

    m_ResponseContainer->mutable_void_response();
    return Success();
}
