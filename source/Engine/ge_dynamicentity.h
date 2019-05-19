#ifndef GE_DYNAMICENTITY_H_INCLUDED
#define GE_DYNAMICENTITY_H_INCLUDED

class GE_DLLIMPORT eCDynamicEntity :
    public eCEntity
{
    public:
        enum eECreatureClass;

    public:    virtual eECreatureClass          GetCreatureClass( void ) const;
    public:    virtual void                     EnableMovementControlByPhysics( GEBool );
    public:    virtual GEBool                   IsMovementControledByPhysics( void ) const;
    public:    virtual void                     DoDamage( eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator & );
    public:    virtual void                     OnTrigger( eCEntity *, eCEntity * );
    public:    virtual void                     OnUntrigger( eCEntity *, eCEntity * );
    public:    virtual void                     OnTouch( eCEntity *, eCContactIterator & );
    public:    virtual void                     OnIntersect( eCEntity *, eCContactIterator & );
    public:    virtual void                     OnUntouch( eCEntity *, eCContactIterator & );
    public:    virtual void                     OnDamage( eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator & );
    protected: virtual void                     DoSaveGameEntityPostRead( void );
    public:    virtual GEU16                    GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult                 Write( bCOStream & );
    public:    virtual bEResult                 Read( bCIStream & );
    public:    virtual void                     Destroy( void );
    public:    virtual bEResult                 Create( void );
    public:    virtual bEResult                 CopyFrom( bCObjectBase const & );
    protected: virtual                         ~eCDynamicEntity( void );
    protected: virtual eCDynamicEntity *        DoClone( void ) const;
    public:    virtual bCVector                 GetLinearVelocity( void ) const;
    public:    virtual void                     SetLinearVelocity( bCVector const & );
    public:    virtual GEBool                   IsDummy( void ) const;
    protected: virtual void                     OnUpdatedWorldMatrix( void );
    protected: virtual void                     OnUpdatedWorldTreeBoundary( void );
    public:    virtual void                     Decay( void );
    public:    virtual GEBool                   IsAutoKillEnabled( void ) const;
    public:    virtual void                     SetCreator( eCTemplateEntity * );
    public:    virtual eCTemplateEntity const * GetCreator( void ) const;
    public:    virtual GEBool                   HasCreator( void ) const;
    public:    virtual void                     CopyEntityPrivateData( eCEntity const &, GEBool );
    protected: virtual GEInt                    OnAction( eCInpShared::eSGameKeyMessage const & );
    protected: virtual GEInt                    OnMouse( eCInpShared::eSInputMessage const & );
    protected: virtual void                     OnProcess( void );
    protected: virtual void                     OnPreProcess( void );
    protected: virtual void                     OnPostProcess( void );
    protected: virtual void                     OnDeinitialize( void );
    protected: virtual void                     OnPostRead( void );
    public:    virtual void                     OnCacheIn( void );
    public:    virtual void                     OnCacheOut( void );
    public:    virtual void                     Render( GEI16 );
    public:    virtual void                     RenderAlpha( GEI16 );

    public:
        void                 EnableCollisionResponse( GEBool );
        bCPropertyID const & GetCreatorID( void ) const;
        GEU16                GetVisualizedRotAxes( void ) const;
        GEU16                GetVisualizedTransAxes( void ) const;
        GEBool               HasCollisionResponse( void ) const;
        GEBool               HasDrawName( void ) const;
        GEBool               IsNativeSaveGameEntity( void ) const;
        bEResult             ReadSaveGame( bCIStream & );
        void                 SetDrawName( GEU8 );
        bEResult             SetMeshVisual( bCString const &, GEBool );
        void                 SetVisualizedRotAxes( GEU16 );
        void                 SetVisualizedTransAxes( GEU16 );
        bEResult             WriteSaveGame( bCOStream & );

    protected:
        eCDynamicEntity( eCDynamicEntity const & );
        eCDynamicEntity( void );

    protected:
        eCDynamicEntity const & operator = ( eCDynamicEntity const & );

    protected:
        void Invalidate( void );

};

#endif
