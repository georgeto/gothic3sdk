#ifndef GE_COLLISIONSHAPE_PS_H_INCLUDED
#define GE_COLLISIONSHAPE_PS_H_INCLUDED

class GE_DLLIMPORT eCCollisionShape_PS :
    public eCCollisionShapeBase_PS
{
    public: using eCCollisionShapeBase_PS::SetShape;
    public:    virtual bEResult                                   SetShape( bCString const &, GEBool a_bConvex );
    public: using eCCollisionShapeBase_PS::AddShape;
    public:    virtual bEResult                                   AddShape( bCString const &, GEBool a_bConvex );
    public:    virtual bEResult                                   AddShape( eECollisionShapeType, eEShapeGroup, bCVector const &, bCVector const & );
    public:    virtual bEResult                                   AddDynamicShape( eECollisionShapeType, eEShapeGroup, eEShapeAABBAdapt, GEFloat );
    public:    virtual bEResult                                   AddPointShape( eEShapeGroup, bCVector const & );
    public:    virtual NxShape *                                  GetProprietaryShapeAtIndex( GEU32 ) const;
    public:    virtual void                                       RemoveShapes( void );
    public:    virtual void                                       RemoveShapes( eEShapeGroup );
    public:    virtual void                                       RemoveShapes( eECollisionShapeType );
    public:    virtual void                                       RemoveShape( eCCollisionShape * );
    public:    virtual void                                       RemoveShapeAt( GEInt );
    protected: virtual void                                       EnableShapeGroupCollisionInternal( eEShapeGroup, GEBool, GEInt );
    protected: virtual void                                       SetShapeGroupInternal( eEShapeGroup, eEShapeGroup );
    protected: virtual void                                       RemoveShapesInternal( void );
    protected: virtual void                                       RemoveShapesInternal( eEShapeGroup );
    protected: virtual void                                       RemoveShapesInternal( eECollisionShapeType );
    protected: virtual void                                       RemoveShapesInternal( NxShape * );
    public:    virtual void                                       OnPreTouch( eCEntity *, eCContactIterator & );
    public:    virtual void                                       OnPreUntouch( eCEntity *, eCContactIterator & );
    public:    virtual void                                       OnPostTouch( eCEntity *, eCContactIterator & );
    public:    virtual GEU16                                      GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult                                   Write( bCOStream & );
    public:    virtual bEResult                                   Read( bCIStream & );
    public:    virtual void                                       Destroy( void );
    public:    virtual bEResult                                   Create( void );
    public:    virtual bEResult                                   CopyFrom( bCObjectBase const & );
    public:    virtual                                           ~eCCollisionShape_PS( void );
    public:    virtual bEResult                                   PostInitializeProperties( void );
    public:    virtual GEBool                                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
    public:    virtual GEBool                                     IsPhysicRelevant( void ) const;
    public:    virtual GEBool                                     IsEditorRelevant( void ) const;
    public:    virtual bEResult                                   ReadSaveGame( bCIStream & );
    public:    virtual bEResult                                   WriteSaveGame( bCOStream & );
    public:    virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
    public:    virtual void                                       GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );
    protected: virtual void                                       OnExitProcessingRange( void );
    protected: virtual void                                       OnUpdatedWorldMatrix( void );
    protected: virtual void                                       OnUpdatedWorldTreeBoundary( void );
    protected: virtual void                                       OnCacheIn( void );
    protected: virtual void                                       OnCacheOut( void );
    public:    virtual void                                       GetBoundary( bCBox &, GEBool );
    public:    virtual void                                       OnPostRead( void );
    public:    virtual bEResult                                   SetShape( eCCollisionShape * );
    public:    virtual bEResult                                   AddShape( eCCollisionShape * );
    public:    virtual GEU32                                      GetNumShapes( void ) const;
    public:    virtual eCCollisionShape *                         GetShapeAtIndex( GEU32 ) const;

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCCollisionShape_PS( eCCollisionShape_PS const & );
        eCCollisionShape_PS( void );

    public:
        eCCollisionShape_PS const & operator = ( eCCollisionShape_PS const & );

    public:
        GEBool &                                       AccessDisableCollision( void );
        GEBool &                                       AccessDisableResponse( void );
        bTPropertyContainer<eECollisionGroup> &        AccessGroup( void );
        GEBool &                                       AccessIgnoredByTraceRay( void );
        bTPropertyContainer<eEPhysicRangeType> &       AccessRange( void );
        void                                           ClearTouchingShapes( void );
        void                                           EnableShapeGroupCollision( eEShapeGroup, GEBool, GEInt );
        GEBool const &                                 GetDisableCollision( void ) const;
        GEBool const &                                 GetDisableResponse( void ) const;
        bTPropertyContainer<eECollisionGroup> const &  GetGroup( void ) const;
        GEBool const &                                 GetIgnoredByTraceRay( void ) const;
        GEU32                                          GetNumTouchingShapes( void ) const;
        NxShape *                                      GetProprietaryTouchingShape( GEU32 ) const;
        bTPropertyContainer<eEPhysicRangeType> const & GetRange( void ) const;
        bTRefPtrArray<eCCollisionShape *> &            GetShapes( void );
        bTRefPtrArray<eCCollisionShape *> const &      GetShapes( void ) const;
        eEPropertySetType                              GetTouchType( void ) const;
        bCString const &                               GetTouchingBone( void ) const;
        eCCollisionShape *                             GetTouchingShapeAtIndex( GEU32 ) const;
        GEBool const                                   HasConvexMesh( void ) const;
        GEBool const                                   HasGroup( eEShapeGroup ) const;
        GEBool const                                   HasScalableMesh( void ) const;
        GEBool const                                   HasTriangleMesh( void ) const;
        void                                           SetDisableCollision( GEBool const & );
        void                                           SetDisableResponse( GEBool const & );
        void                                           SetGroup( bTPropertyContainer<eECollisionGroup> const & );
        void                                           SetIgnoredByTraceRay( GEBool const & );
        void                                           SetRange( bTPropertyContainer<eEPhysicRangeType> const & );
        void                                           SetShapeGroup( eEShapeGroup, eEShapeGroup );
        void                                           SetShapes( bTRefPtrArray<eCCollisionShape *> const & );
        GEBool                                         TraceRayFirstHit( bCRay & );

    protected:
        void Invalidate( void );
        void OnProprietaryShapesChanged( void );
        void SetProprietaryShapes( void );
        void ShrinkTouchingShapes( void );

};

#endif
