#ifndef GE_PHYSICSSCENE_H_INCLUDED
#define GE_PHYSICSSCENE_H_INCLUDED

class NxActor;
class NxActorDesc;
class NxConvexMesh;
class NxStream;
class NxJoint;
class NxJointDesc;
class NxSpringAndDamperEffector;
class NxSpringAndDamperEffectorDesc;
class eCCollisionPairNotification;
class NxPhysicsSDK;
class NxScene;
class NxEffector;
class NxTriangleMesh;

enum eETraceRayHints
{
    eETraceRayHints_TestStaticShapes            = 0x1, // NX_STATIC_SHAPES
    eETraceRayHints_TestDynamicShapes           = 0x2, // NX_DYNAMIC_SHAPES
    eETraceRayHints_TestIfHasItemPropertySet    = 0x10,
    eETraceRayHints_FaceNormal                  = 0x20, // NX_RAYCAST_FACE_NORMAL
    eETraceRayHints_Normal                      = 0x40, // NX_RAYCAST_NORMAL
    eETraceRayHints_Impact                      = 0x80, // NX_RAYCAST_IMPACT
    eETraceRayHints_Distance                    = 0x100, // NX_RAYCAST_DISTANCE
    eETraceRayHints_MaterialIndex               = 0x200,
    eETraceRayHints_UserData                    = 0x400, // fill userdata array
    eETraceRayHints_MaxDistanceNotFromDirection = 0x1000, // Don't use magnitude of direction vector as max distance, but instead use the constant 3.402823466385289e38. It is assumed, that the direction vector is normalized.
    eETraceRayHints_IncludeCollisionGroup17     = 0x4000,
};

class GE_DLLIMPORT eCPhysicsScene :
    public eCEngineComponentBase
{
    using bCObjectBase::Write;
    public: virtual bEResult    Write( bCOStream & );
    public: virtual bEResult    Read( bCIStream & );
    public: virtual void        Destroy( void );
    public: virtual bEResult    Create( void );
    public: virtual GEU32 const GetProfileLastTicksFirst( void ) const;
    public: virtual            ~eCPhysicsScene( void );
    public: virtual bEResult    PostInitialize( void );
    public: virtual bEResult    PreShutdown( void );
    public: virtual bEResult    WorldActivate( void );
    public: virtual bEResult    WorldDeactivate( void );
    public: virtual void        PostProcess( void );

    private:
        static eCPhysicsScene * s_pCurrentInstance;

    public:
        static eCPhysicsScene & GE_STDCALL             GetInstance( void );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        static GEBool GE_STDCALL                       g_EntityAdminKillsEntityCallback( eCEntity * );

    public:
        eCPhysicsScene( void );

    public:
        eCPhysicsScene const & operator =  ( eCPhysicsScene const & );
        bCOStream &            operator >> ( bCOStream & );
        bCIStream &            operator << ( bCIStream & );

    public:
        GEBool &                    AccessIsPhysicsEnabled( void );
        void                        AddCCDEntity( eCEntity * );
        void                        AddEditorSimulationEntity( eCEntity & );
        void                        AddHoverEntity( eCEntity * );
        GEBool                      CollectEntitiesInAABB( bCBox const &, GEBool, eCEntity const *, bTPtrArray<eCEntity *> *, GEU32, GEBool, eEPropertySetType, GEU16 ) const;
        GEBool                      CollectEntitiesInCapsule( bCCapsule const &, GEBool, eCEntity const *, bTPtrArray<eCEntity *> *, GEU32, GEBool, eEPropertySetType, GEU16 ) const;
        GEBool                      CollectEntitiesInOBB( bCOrientedBox const &, GEBool, eCEntity const *, bTPtrArray<eCEntity *> *, GEU32, GEBool, eEPropertySetType, GEU16 ) const;
        GEBool                      CollectEntitiesInSphere( bCSphere const &, GEBool, eCEntity const *, bTPtrArray<eCEntity *> *, GEU32, GEBool, eEPropertySetType, GEU16 ) const;
        GEBool                      CollectPolysInAABB( bCBox const &, bTObjArray<bCTriangle> * ) const;
        using eCEngineComponentBase::CopyFrom;
        void                        CopyFrom( eCPhysicsScene const & );
        void                        CopyTo( eCPhysicsScene & ) const;
        NxActor *                   CreateActor( NxActorDesc & );
        NxConvexMesh *              CreateConvexMesh( NxStream & );
        NxActor *                   CreateDefaultActor( eCEntity const & );
        eCEffector *                CreateEffector( eCEntity *, eCEntity *, eCEffectorDesc & );
        eCJoint *                   CreateJoint( eCEntity *, eCEntity *, eCJointDesc & );
        NxJoint *                   CreateJointInternal( NxJointDesc & );
        NxSpringAndDamperEffector * CreateSpringAndDamperEffector( NxSpringAndDamperEffectorDesc & );
        NxTriangleMesh *            CreateTriangleMesh( NxStream & );
        void                        Debug_VisualizeTriangle( bCTriangle & );
        void                        EnableEditorSimulation( eCEntity & );
        void                        EnableEditorSimulation( bTPtrArray<eCEntity *>);
        void                        EnableEditorSimulation( GEBool );
        void                        EntityAdminKillsEntity( eCEntity * );
        eCCollisionPairNotification GetCollisionGroupNotifications( eECollisionGroup, eECollisionGroup ) const;
        GEBool                      GetCollisionGroupsCanCollide( eECollisionGroup, eECollisionGroup ) const;
        GEU32                       GetCollisionGroupsNotifyFlags( eECollisionGroup, eECollisionGroup ) const;
        bCCriticalSectionWin32 &    GetCriticalSection( void );
        GEBool                      GetEntitiesCanCollide( eCEntity &, eCEntity &, GEBool ) const;
        GEBool                      GetEntityPairsCanCollide( eCEntity &, eCEntity & ) const;
        bCVector                    GetGravityVector( void ) const;
        GEBool                      GetGroupsCanCollide( eEShapeGroup, eEShapeGroup ) const;
        void                        GetIgnoreEntities( eCEntity &, bTPtrArray<eCEntity *> & );
        GEBool const &              GetIsPhysicsEnabled( void ) const;
        GEU32                       GetNumRaysCasted( void ) const;
        eCPhysicQueryReport &       GetQueryReport( void );
        GEU32                       GetRayProcessingTime( void ) const;
        NxPhysicsSDK &              GetSDK( void );
        NxScene &                   GetScene( void );
        GEFloat                     GetStateAlpha( void ) const;
        GEBool                      HasEntityFreePlace( eCEntity &, bCMatrix *, GEBool, GEBool, GEFloat ) const;
        GEBool                      HasShapeFreePlace( eCCollisionShape const &, eCEntity const &, bCMatrix *, GEBool, GEBool, GEFloat ) const;
        GEBool                      IsEntityFrozen( eCEntity & ) const;
        GEBool                      IsPlacingEntities( void ) const;
        void GE_STDCALL             OnConsoleCommand( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL             OnDebugMenuClicked( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL             OnDebugMiscMenuClicked( bCObjectRefBase *, bCEvent * );
        NxActor *                   PickActor( GEInt, GEInt, GEFloat, bCVector & );
        eCEntity *                  PickEntity( GEInt, GEInt, GEFloat, bCVector & );
        void                        PutEntityToGround( eCEntity * );
        void                        ReleaseActor( NxActor & );
        void                        ReleaseConvexMesh( NxConvexMesh & );
        void                        ReleaseEffector( eCEffector & );
        void                        ReleaseEffectorInternal( NxEffector & );
        void                        ReleaseJoint( eCJoint & );
        void                        ReleaseJointInternal( NxJoint & );
        void                        ReleaseTriangleMesh( NxTriangleMesh & );
        void                        RemoveCCDEntity( eCEntity * );
        void                        RemoveEditorSimulationEntity( eCEntity & );
        void                        SetCollisionGroupNotifications( eECollisionGroup, eECollisionGroup, eCCollisionPairNotification const & );
        void                        SetEntitiesCanCollide( eCEntity &, eCEntity &, GEBool, GEBool );
        void                        SetGroupsCanCollide( eEShapeGroup, eEShapeGroup, GEBool );
        void                        SetIsPhysicsEnabled( GEBool const & );
        void                        SetQueryFilterCallback( GEBool ( GE_STDCALL* )( eCEntity *, eCCollisionShape * ));
        void                        SetQueryIgnoreEntities( bTPtrArray<eCEntity *> & );
        void                        SetSimulationFPS( GEFloat );
        GEBool                      TraceRayAllHits( bCVector const & a_Origin, bCVector const & a_Direction, eCEntity const * a_pExcludeEntity, GEU32 a_Hints, eCEntity const * = 0, eEPropertySetType a_PropertySetFilter = eEPropertySetType_Unknown, eEShapeGroup a_GroupsMask = eEShapeGroup_Undefined );
        GEBool                      TraceRayFirstHit( bCVector const & a_Origin, bCVector const & a_Direction, eCEntity const * a_pExcludeEntity, GEU32 a_Hints, eCEntity const * = 0, eEPropertySetType a_PropertySetFilter = eEPropertySetType_Unknown, eEShapeGroup a_GroupsMask = eEShapeGroup_Undefined );
        GEBool                      TraceRayNearestHit( bCVector const & a_Origin, bCVector const & a_Direction, eCEntity const * a_pExcludeEntity, GEU32 a_Hints, eCEntity const * = 0, eEPropertySetType a_PropertySetFilter = eEPropertySetType_Unknown, eEShapeGroup a_GroupsMask = eEShapeGroup_Undefined );

    protected:
        void   AddDynamicEntity( eCDynamicEntity * );
        void   AddPhysicObject( eCPhysicObject * );
        void   AddSkeleton( eCPhysicObject * );
        void   DebugRender( void );
        void   Invalidate( void );
        GEBool IsLocked( void );
        void   RemoveDynamicEntity( eCDynamicEntity * );
        void   RemoveSkeleton( eCPhysicObject * );
        void   Simulate( void );

    private:
        void FetchResults( void );
        void FetchResultsOnDemand( void );
        void PlaceEntities( void );
        void SetEntitiesCanCollideInternal( eCEntity &, eCEntity &, GEBool );

};

#endif
