#include "me_rh_spawn.h"

#include "Game.h"

#include "util/Util.h"

using namespace g3rc;

void mCSpawnRequestHandler::HandleRequest()
{
    SpawnRequest const & Request = m_RequestContainer->spawn_request();

    GEBool bFoundPosition = GEFalse;
    bCVector TargetPosition;
    if( Request.has_entity_name() )
    {
        if( eCEntity const * pEntity = GetEntityByName( Request.entity_name() ) )
        {
            TargetPosition.SetVector( pEntity->GetWorldPosition() );
            bFoundPosition = GETrue;
        }
    }
    else if( Request.has_entity_guid() )
    {
        if( eCEntity const * pEntity = GetEntityByGuid( Request.entity_guid() ) )
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
        eCEntity const * pTemplate = 0;
        if( Request.has_template_name() )
        {
            pTemplate = GetTemplateEntityByName( Request.template_name() );
        }
        else if( Request.has_template_guid() )
        {
            pTemplate = GetEntityByGuid( Request.template_guid(), eEGetEntityTypeHint_TemplateEntity );
        }

        if( pTemplate )
        {
            eCEntity * pSpawnedEntity = gCWorld::GetCurrentWorld()->CreateDynamicEntity();
            eCTemplateEntity const * pRealTemplate;
            if( pTemplate->GetChildrenCount() == 1 )
                pRealTemplate = static_cast<eCTemplateEntity const *>( pTemplate->GetChildAt( 0 ) );
            else
                pRealTemplate = static_cast<eCTemplateEntity const *>( pTemplate );
            pSpawnedEntity->CreateFromTemplate( *pRealTemplate );
            pSpawnedEntity->SetLocalPosition( TargetPosition );

            EntityResponse * pResponse = m_ResponseContainer->mutable_entity_response();
            SetEntityResponse( *pResponse, *pSpawnedEntity );
            return Success();
        }
        else
            return FailAndPrintMessage( "Template konnte nicht gefunden werden." );
    }
    else
        return FailAndPrintMessage( "Spawn-Position konnte nicht ermittelt werden." );
}
