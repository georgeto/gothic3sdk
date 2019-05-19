#include "me_rh_heartbeat.h"

#include "Game.h"

using namespace g3rc;

void mCHeartbeatRequestHandler::HandleRequest()
{
    HearbeatResponse * pResponse = m_ResponseContainer->mutable_heartbeat_response();

    gCGUIManager const * pGuiManager = gCSession::GetInstance().GetGUIManager();
    if( pGuiManager && pGuiManager->IsMenuOpen() )
        pResponse->set_status( HearbeatResponse_Status_MENU );
    else
        pResponse->set_status( HearbeatResponse_Status_INGAME );

    return Success();
}
