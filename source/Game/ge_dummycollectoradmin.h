#ifndef GE_DUMMYCOLLECTORADMIN_H_INCLUDED
#define GE_DUMMYCOLLECTORADMIN_H_INCLUDED

class GE_DLLIMPORT gCDummyCollectorAdmin :
    public eCEngineComponentBase
{
    public: virtual bEResult OnDestroyWorkspace( void );
    public: virtual GEBool   IsValid( void ) const;
    public: using bCObjectBase::Write;
    public: virtual bEResult Write( bCOStream & );
    public: virtual bEResult Read( bCIStream & );
    public: virtual void     Destroy( void );
    public: virtual bEResult Create( void );
    public: virtual         ~gCDummyCollectorAdmin( void );
    public: virtual bEResult Initialize( void );
    public: virtual bEResult PostInitialize( void );
    public: virtual bEResult Shutdown( void );
    public: virtual bEResult WorldActivate( void );
    public: virtual bEResult WorldDeactivate( void );
    public: virtual void     Process( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCDummyCollectorAdmin( gCDummyCollectorAdmin const & );
        gCDummyCollectorAdmin( void );

    public:
        gCDummyCollectorAdmin const & operator = ( gCDummyCollectorAdmin const & );

    public:
        bEResult        AddPropertySetMember( eEPropertySetType, eCEntity &, eCEntity * &, GEInt, GEInt, GEInt );
        void            ClearAllCollections( void );
        bEResult        DeletePropertySetMember( eEPropertySetType, eCEntity &, GEInt );
        bEResult        DeletePropertySetMember( eEPropertySetType, eCEntity &, eCEntity * );
        void            DisableAllPropertySets( void );
        void            EnableApplyToTemplate( GEBool );
        void            EnableApplyToTemplateInstances( GEBool );
        void            EnablePropertyset( eEPropertySetType, bCBox const &, GEBool );
        void            EnablePropertyset( eEPropertySetType, eCEntity const &, GEBool );
        void            EnablePropertyset( eEPropertySetType, GEBool );
        void            EnableRenderingForIndex( eEPropertySetType, eCEntity &, GEInt, GEBool );
        eCEntity *      GetDummyEntityAtIndex( eEPropertySetType, eCEntity &, GEInt ) const;
        GEInt           GetEntityAndMemberIndex( eEPropertySetType, eCEntity const *, eCEntity * & );
        GEU32           GetPropertySetMemberCount( eEPropertySetType, eCEntity & ) const;
        GEBool          GetShowPropertyset_Attribs( void ) const;
        GEBool          GetShowPropertyset_Entities( void ) const;
        GEBool          GetShowPropertyset_Types( void ) const;
        void            Invalidate( void );
        GEBool          IsApplyToTemplateEnabled( void ) const;
        GEBool          IsApplyToTemplateInstancesEnabled( void ) const;
        GEBool          IsCollecting( void ) const;
        void GE_STDCALL OnViewLabels( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnViewLights( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnViewNavigation( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnViewSounds( bCObjectRefBase *, bCEvent * );
        void            RemoveEntity( eCEntity & );
        void            SetShowPropertyset_Attribs( GEBool );
        void            SetShowPropertyset_Entities( GEBool );
        void            SetShowPropertyset_Types( GEBool );

    protected:
        void AddEntitiesFromCollection( gCDummyCollectorBase * );
        void AddEntitiesFromCollections( void );
        void CollectEntity( eCEntity & );
        void CollectProcessingRange( void );
        void CreateDummyEntities( void );
        void DeleteAllCollections( void );
        void LazyCreateCollections( void );
        void OnUpdatedWorldMatrix( eCEntity & );

};

#endif
