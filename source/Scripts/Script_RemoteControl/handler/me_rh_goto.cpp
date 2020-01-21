#include "me_rh_goto.h"

#include "Game.h"

#include "util/Util.h"

using namespace g3rc;

mCGotoRequestHandler::mCGotoRequestHandler()
    : m_uPutToGroundTries(0)
{
}

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

    if(Request.has_put_to_ground() && Request.put_to_ground())
    {
        m_PutToGroundLocation = TargetPosition;
        m_PutToGroundLocation.SetY(1000000.0f);
        m_uPutToGroundTries = 200;
    }
    else
        m_uPutToGroundTries = 0;

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

void mCGotoRequestHandler::Process()
{
    if(m_uPutToGroundTries > 0)
    {
        m_uPutToGroundTries--;
        eCEntity * pPlayer = gCSession::GetInstance().GetPlayer();
        if(!pPlayer)
            return;

        eCPhysicsScene & PhysicsScene = eCPhysicsScene::GetInstance();
        if(PhysicsScene.TraceRayNearestHit(m_PutToGroundLocation, bCVector(0, -1, 0), pPlayer, eETraceRayHints_TestStaticShapes | eETraceRayHints_TestDynamicShapes | eETraceRayHints_Impact | eETraceRayHints_MaxDistanceNotFromDirection))
        {
            pPlayer->SetWorldPosition( PhysicsScene.GetQueryReport().m_NearestWorldImpact );
            m_uPutToGroundTries = 0;
        }
        else if(m_uPutToGroundTries <= 150 && m_uPutToGroundTries > 108)
        {
            // Move player to bring other "layers" into physics scene
            bCVector PlayerPosition = m_PutToGroundLocation;
            if(m_uPutToGroundTries >= 110)
                // 30000 -> -10000
                PlayerPosition.SetY((static_cast<GEInt>(m_uPutToGroundTries) - 120) * 1000);
            else if(m_uPutToGroundTries == 109)
                PlayerPosition.SetY(0);
            pPlayer->SetWorldPosition(PlayerPosition);
        }
    }
}
