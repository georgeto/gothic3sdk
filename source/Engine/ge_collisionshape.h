#ifndef GE_COLLISIONSHAPE_H_INCLUDED
#define GE_COLLISIONSHAPE_H_INCLUDED

class NxShape;

class GE_DLLIMPORT eCCollisionShape :
    public bCObjectRefBase
{
    public:    virtual GEU16    GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    public:    virtual void     Destroy( void );
    public:    virtual bEResult Create( void );
    public:    virtual bEResult CopyFrom( bCObjectBase const & );
    protected: virtual         ~eCCollisionShape( void );
    public:    virtual bEResult PostInitializeProperties( void );

    public:
        static bCString GE_STDCALL                     GetMaterialName( eEShapeMaterial );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCCollisionShape( eCCollisionShape const & );
        eCCollisionShape( void );

    public:
        eCCollisionShape const & operator = ( eCCollisionShape const & );

    public:
        GEFloat &                                         AccessAdaptScale( void );
        GEBool &                                          AccessAdaptToAABB( void );
        GEBool &                                          AccessDisableCollision( void );
        GEBool &                                          AccessDisableResponse( void );
        GEBool &                                          AccessEnableCCD( void );
        GEU16 &                                           AccessFileVersion( void );
        bTPropertyContainer<eEShapeGroup> &               AccessGroup( void );
        GEBool &                                          AccessIgnoredByTraceRay( void );
        GEBool &                                          AccessIsLazyGenerated( void );
        bTPropertyContainer<eEShapeMaterial> &            AccessMaterial( void );
        GEBool &                                          AccessOverrideEntityAABB( void );
        bTPropertyContainer<eEShapeAABBAdapt> &           AccessShapeAABBAdaptMode( void );
        bTPropertyContainer<eECollisionShapeType> &       AccessShapeType( void );
        GEFloat &                                         AccessSkinWidth( void );
        GEBool &                                          AccessTriggersOnIntersect( void );
        GEBool &                                          AccessTriggersOnTouch( void );
        GEBool &                                          AccessTriggersOnUntouch( void );
        GEFloat const &                                   GetAdaptScale( void ) const;
        GEBool const &                                    GetAdaptToAABB( void ) const;
        bCOrientedBox &                                   GetBox( void );
        bCOrientedBox const &                             GetBox( void ) const;
        bCCapsule &                                       GetCapsule( void );
        bCCapsule const &                                 GetCapsule( void ) const;
        bCVector &                                        GetCenter( void );
        bCVector const &                                  GetCenter( void ) const;
        void                                              GetDependencies( bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> & );
        GEFloat                                           GetDepth( void );
        GEFloat const                                     GetDepth( void ) const;
        GEBool const &                                    GetDisableCollision( void ) const;
        GEBool const &                                    GetDisableResponse( void ) const;
        GEBool const &                                    GetEnableCCD( void ) const;
        eCEntity *                                        GetEntity( void ) const;
        GEU16 const &                                     GetFileVersion( void ) const;
        bTPropertyContainer<eEShapeGroup> const &         GetGroup( void ) const;
        GEFloat                                           GetHeight( void );
        GEFloat const                                     GetHeight( void ) const;
        GEBool const &                                    GetIgnoredByTraceRay( void ) const;
        GEBool                                            GetIsCachedIn( void ) const;
        GEBool const &                                    GetIsLazyGenerated( void ) const;
        bCVector &                                        GetLastPosition( void );
        bCVector const &                                  GetLastPosition( void ) const;
        bTPropertyContainer<eEShapeMaterial> const &      GetMaterial( void ) const;
        bCString &                                        GetMeshResourceName( void );
        bCString const &                                  GetMeshResourceName( void ) const;
        bCMatrix3 &                                       GetOrientation( void );
        bCMatrix3 const &                                 GetOrientation( void ) const;
        bCBox &                                           GetOuterAABBLocal( void );
        bCBox const &                                     GetOuterAABBLocal( void ) const;
        GEBool const &                                    GetOverrideEntityAABB( void ) const;
        bCVector &                                        GetPoint( void );
        bCVector const &                                  GetPoint( void ) const;
        NxShape *                                         GetProprietaryShape( void ) const;
        GEU16                                             GetResourceIndex( void ) const;
        bCMatrix3 &                                       GetRuntimeOrientation( void );
        bCMatrix3 const &                                 GetRuntimeOrientation( void ) const;
        bTPropertyContainer<eEShapeAABBAdapt> const &     GetShapeAABBAdaptMode( void ) const;
        bTPropertyContainer<eECollisionShapeType> const & GetShapeType( void ) const;
        GEFloat const &                                   GetSkinWidth( void ) const;
        bCSphere &                                        GetSphere( void );
        bCSphere const &                                  GetSphere( void ) const;
        GEBool const &                                    GetTriggersOnIntersect( void ) const;
        GEBool const &                                    GetTriggersOnTouch( void ) const;
        GEBool const &                                    GetTriggersOnUntouch( void ) const;
        GEFloat                                           GetWidth( void );
        GEFloat const                                     GetWidth( void ) const;
        GEBool                                            IntersectsRay( bCRay const & );
        GEBool                                            IsTrigger( void ) const;
        void                                              SetAdaptScale( GEFloat const & );
        void                                              SetAdaptToAABB( GEBool const & );
        bEResult                                          SetByLocalAABB( bCBox const & );
        void                                              SetCenter( bCVector const & );
        void                                              SetDepth( GEFloat );
        void                                              SetDisableCollision( GEBool const & );
        void                                              SetDisableResponse( GEBool const & );
        void                                              SetEnableCCD( GEBool const & );
        void                                              SetFileVersion( GEU16 const & );
        void                                              SetGroup( bTPropertyContainer<eEShapeGroup> const & );
        void                                              SetHeight( GEFloat );
        void                                              SetIgnoredByTraceRay( GEBool const & );
        void                                              SetIsCachedIn( GEBool );
        void                                              SetIsLazyGenerated( GEBool const & );
        void                                              SetLastPosition( bCVector const & );
        void                                              SetMaterial( bTPropertyContainer<eEShapeMaterial> const & );
        void                                              SetMeshResourceName( bCString & );
        void                                              SetOrientation( bCMatrix3 const & );
        void                                              SetOverrideEntityAABB( GEBool const & );
        void                                              SetProprietaryShape( NxShape * );
        void                                              SetRuntimeOrientation( bCMatrix3 const & );
        bEResult                                          SetShape( eCCollisionShape const & );
        bEResult                                          SetShape( bCCapsule const & );
        bEResult                                          SetShape( bCOrientedBox const & );
        bEResult                                          SetShape( bCSphere const & );
        bEResult                                          SetShape( bCString const &, GEU16, GEBool );
        bEResult                                          SetShape( bCVector const & );
        void                                              SetShapeAABBAdaptMode( bTPropertyContainer<eEShapeAABBAdapt> const & );
        bEResult                                          SetShapeAABBLocal( bCBox const & );
        void                                              SetShapeType( bTPropertyContainer<eECollisionShapeType> const & );
        void                                              SetSkinWidth( GEFloat const & );
        void                                              SetTriggersOnIntersect( GEBool const & );
        void                                              SetTriggersOnTouch( GEBool const & );
        void                                              SetTriggersOnUntouch( GEBool const & );
        void                                              SetWidth( GEFloat );

    protected:
        void CalcShapeAABBLocal( void );
        void Invalidate( void );

};

#endif
