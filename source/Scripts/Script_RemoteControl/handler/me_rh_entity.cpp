#include "me_rh_entity.h"

#include "Game.h"

#include "util/Util.h"

using namespace g3rc;

void mCEntityRequestHandler::HandleRequest()
{
    EntityRequest const & Request = m_RequestContainer->entity_request();

    eCEntity * pEntity = 0;
    if( Request.has_name() )
    {
        pEntity = GetEntityByName( Request.name() );
    }
    else if( Request.has_guid() )
    {
        pEntity = GetEntityByGuid( Request.guid() );
    }
    else if( Request.has_focus() )
    {
        if( gCFocus_PS * pPlayerFocus = GetPropertySet<gCFocus_PS>( gCSession::GetInstance().GetPlayer(), eEPropertySetType_Focus ) )
        {
            pEntity = pPlayerFocus->AccessCurrentEntity().GetEntity();
        }
    }

    if( pEntity )
    {
        if( Request.has_moveto() )
        {
            g3rc::Position const & Pos = Request.moveto();
            bCMatrix WorldMatrix;
            WorldMatrix.SetToRotation( bCEulerAngles( Pos.rotation().yaw(), Pos.rotation().pitch(), Pos.rotation().roll() ) );
            WorldMatrix.ModifyScaling( bCVector( Pos.scale().x(), Pos.scale().y(), Pos.scale().z() ) );
            WorldMatrix.ModifyTranslation( bCVector( Pos.translation().x(), Pos.translation().y(), Pos.translation().z() ) );
            pEntity->SetToWorldMatrix( WorldMatrix );
        }

        if( Request.has_put_to_ground() && Request.put_to_ground() )
        {
            if( !m_putToGround.IsValidKey( pEntity->GetID() ) )
            {
                mCPutToGroundController PutToGroundController( pEntity->GetID() );
                PutToGroundController.EnableDynamicPhysics();
                m_putToGround.SetAt( pEntity->GetID(), PutToGroundController );
            }
        }

        EntityResponse * pResponse = m_ResponseContainer->mutable_entity_response();
        SetEntityResponse( *pResponse, *pEntity );
        return Success();
    }
    else
        return Fail( "Entity konnte nicht gefunden werden." );
}

void mCEntityRequestHandler::Process()
{
    bTObjArray<bCPropertyID> arrFinished;
    for( bTObjMap<bCPropertyID, mCPutToGroundController>::bCIterator Iter = m_putToGround.Begin(); Iter != m_putToGround.End(); Iter++ )
    {
        if( Iter->HasFinished() )
            arrFinished.Add( Iter.GetKey() );
    }

    for( bTObjArray<bCPropertyID>::bCConstIterator Iter = arrFinished.Begin(); Iter != arrFinished.End(); Iter++ )
    {
        m_putToGround[*Iter].RestorePhysics();
        m_putToGround.RemoveAt( *Iter );
    }
}

mCEntityRequestHandler::mCPutToGroundController::mCPutToGroundController()
{}

mCEntityRequestHandler::mCPutToGroundController::mCPutToGroundController( bCPropertyID a_EntityID )
    : m_EntityID( a_EntityID ), m_bCollisionEnabled( GEFalse ), m_bAddedRigidBody( GEFalse ), m_bAddedCollisionShape( GEFalse ), m_OriginalColGroup( eECollisionGroup_Undefined ), m_msEnableTimestamp( 0 )
{}

void mCEntityRequestHandler::mCPutToGroundController::EnableDynamicPhysics()
{
    eCEntity * pEntity = GetEntity();
    if( !pEntity )
        return;

    // if(!pEntity->HasPropertySet(eEPropertySetType_CollisionShape) && !pEntity->HasPropertySet(eEPropertySetType_MeshVisual))
    // return;

    if( !pEntity->HasPropertySet( eEPropertySetType_RigidBody ) )
    {
        bCPropertyObjectBase * pRigidBody = bCPropertyObjectSingleton::GetInstance().QueryNewObject( bTClassName<eCRigidBody_PS>::GetUnmangled() );
        pEntity->AddPropertySet( pRigidBody );
        m_bAddedRigidBody = GETrue;
    }

    if( !pEntity->HasPropertySet( eEPropertySetType_CollisionShape ) )
    {
        bCPropertyObjectBase * pColShapePS = bCPropertyObjectSingleton::GetInstance().QueryNewObject( bTClassName<eCCollisionShape_PS>::GetUnmangled() );
        pEntity->AddPropertySet( pColShapePS );
        m_bAddedCollisionShape = GETrue;
    }

    eCCollisionShape_PS * pColShapePS = GetPropertySet<eCCollisionShape_PS>( pEntity, eEPropertySetType_CollisionShape );
    if( m_bAddedCollisionShape )
    {
        bCOrientedBox BoxShape( pEntity->GetLocalNodeBoundary(), bCMatrix3::GetIdentity() );
        pColShapePS->AddShape( eECollisionShapeType_Box, eEShapeGroup_Dynamic, BoxShape.GetCenter(), BoxShape.GetExtent() );

        /*
        eCVisualMeshBase_PS * pMesh = GetPropertySet<eCVisualMeshBase_PS>(pEntity, eEPropertySetType_MeshVisual);
        bCString strMeshName = pMesh->GetResourceFileName();
        bCString strColMeshName = strMeshName;
        strColMeshName.Replace(".xcmsh", ".xnvmsh");
        bCString strColMeshPath = "Data/_compiledPhysic/" + strColMeshName;

        eCResourceAdmin * pResourceAdmin = FindModule<eCResourceAdmin>();
        eCResourceDataEntity * pMeshData = pResourceAdmin->QueryResourceDataEntity(strMeshName, eEResourceCacheBehavior_Immediate);
        eCResourceDataEntity * pColShapeData = pResourceAdmin->QueryNewResourceDataEntity();

        if(pMeshData && pColShapeData)
        {
            pColShapeData->CreateResourceFromType(bTClassName<eCResourceCollisionMesh_PS>::GetUnmangled());
            eCResourceCollisionMesh_PS * pColShape = dynamic_cast<eCResourceCollisionMesh_PS *>(pColShapeData->SearchResourcePropertySet());
            if(pColShape)
            {
                pColShape->Compute(pMeshData, GEFalse, 0, 0, 1.0f);
                pColShapeData->Save(strColMeshPath, eEResourceCacheBehavior_Immediate);
            }
        }

        pColShapePS->AddShape(strColMeshName, GEFalse);
        */


    }

    m_OriginalColGroup = pColShapePS->GetGroup();
    pColShapePS->AccessGroup().SetValue( eECollisionGroup_Dynamic );

    m_arrOriginalShapeColGroup.Clear();
    bTRefPtrArray<eCCollisionShape *> & arrShapes = pColShapePS->GetShapes();
    for( GEInt i = 0; i < arrShapes.GetCount(); i++ )
    {
        m_arrOriginalShapeColGroup.Add( arrShapes[i]->GetGroup() );
        arrShapes[i]->AccessGroup().SetValue( eEShapeGroup_Dynamic );
    }

    // Reevaluate collision state of entity
    m_bCollisionEnabled = pEntity->HasCollision();
    pEntity->EnableCollision( GEFalse );
    pEntity->EnableCollision( GETrue );

    m_msEnableTimestamp = bCTimer::GetTimeStamp();

    // PhysicsScene.EnableEditorSimulation(*pEntity);
    // eCPhysicsScene & PhysicsScene = eCPhysicsScene::GetInstance();
    /*if(PhysicsScene.TraceRayNearestHit(pEntity->GetWorldPosition(), bCVector(0, -2000, 0), pEntity, eETraceRayHints_TestStaticShapes | eETraceRayHints_TestDynamicShapes | eETraceRayHints_Impact))
    {
        eCPhysicQueryReport & Report = PhysicsScene.GetQueryReport();
        pEntity->SetWorldPosition(Report.m_NearestWorldImpact);
    }
    */
}

void mCEntityRequestHandler::mCPutToGroundController::RestorePhysics()
{
    eCEntity * pEntity = GetEntity();
    if( !pEntity )
        return;

    if( m_bAddedRigidBody )
    {
        pEntity->RemovePropertySet( pEntity->GetPropertySet( eEPropertySetType_RigidBody ) );
    }

    if( !m_bAddedCollisionShape )
    {
        eCCollisionShape_PS * pColShapePS = GetPropertySet<eCCollisionShape_PS>( pEntity, eEPropertySetType_CollisionShape );
        pColShapePS->AccessGroup().SetValue( m_OriginalColGroup );

        bTRefPtrArray<eCCollisionShape *> & arrShapes = pColShapePS->GetShapes();
        for( GEInt i = 0; i < arrShapes.GetCount(); i++ )
        {
            arrShapes[i]->AccessGroup().SetValue( m_arrOriginalShapeColGroup[i] );
        }
    }
    else
        pEntity->RemovePropertySet( pEntity->GetPropertySet( eEPropertySetType_CollisionShape ) );


    // Reevaluate collision state of entity
    pEntity->EnableCollision( GEFalse );
    pEntity->EnableCollision( m_bCollisionEnabled );
}

GEBool mCEntityRequestHandler::mCPutToGroundController::HasFinished()
{
    // Terminate when 5 seconds have passed, and the entity still reached no stable position.
    if( bCTimer::GetTimeStamp() - m_msEnableTimestamp >= 5000 )
        return GETrue;

    // TODO: Detect if entity has reached a stable position.
    // eCEntity * pEntity = GetEntity();
    // if(eCRigidBody_PS * pRigidBody = GetPropertySet<eCRigidBody_PS>(pEntity, eEPropertySetType_RigidBody))
    // {
    // pRigidBody->GetAngularVelocity()
    // }

    return GEFalse;
}

eCEntity * mCEntityRequestHandler::mCPutToGroundController::GetEntity()
{
    return dynamic_cast<eCEntity *>( FindModule<eCSceneAdmin>()->GetEntity( m_EntityID, eEGetEntityTypeHint_Entity ) );
}
