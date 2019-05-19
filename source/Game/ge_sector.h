#ifndef GE_SECTOR_H_INCLUDED
#define GE_SECTOR_H_INCLUDED

class gCGeometryLayerProcessStrategy;

#pragma warning( push )
#pragma warning( disable : 4263 )// member function does not override any base class virtual member function
#pragma warning( disable : 4264 )// no override available for virtual member function from base 'eCProcessibleElement'; function is hidden

class GE_DLLIMPORT gCSector :
    public eCProcessibleElement
{
    public:    virtual GEU16                          GetVersion( void ) const;
    public: using bCObjectBase::Write;
    public:    virtual bEResult                       Write( bCOStream & );
    public:    virtual bEResult                       Read( bCIStream & );
    public:    virtual void                           Destroy( void );
    public:    virtual bEResult                       Create( void );
    public:    virtual                               ~gCSector( void );
    public:    virtual bEResult                       PostInitializeProperties( void );
    public:    virtual GEBool                         OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
    public:    virtual GEBool                         IsDataAvailable( void ) const;
    public:    virtual bCString                       GetFileExt( void ) const;
    public:    virtual bCString                       GetFileType( void ) const;
    public:    virtual bCString                       GetDataFileExt( void ) const;
    public:    virtual bCString                       GetDataFileType( void ) const;
    public:    virtual GEU16                          GetFileVersion( void ) const;
    protected: virtual eCProcessibleElement::eEResult DoLoadData( bCIStream & );
    protected: virtual eCProcessibleElement::eEResult DoSaveData( bCOStream &, bCString const & );
    protected: virtual void                           OnModify( void );
    protected: virtual void                           OnActivate( void );
    protected: virtual GEBool                         CanGotoState( eCProcessibleElement::eEState );
    protected: virtual void                           UpdateState( void );
    protected: virtual eCProcessibleElement::eEResult ReleaseData( void );

    protected:
        static GEBool         ms_bEnableLayerActivation;
        static GEBool         ms_bStaticLayerSpeedUp;
        static bCString const ms_strDynamicEntitySector;

    public:
        static void GE_STDCALL                         EnableSectorActivation( GEBool );
        static void GE_STDCALL                         EnableSectorSpeedup( GEBool );
        static void GE_STDCALL                         GetFileExt( bCString & );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCSector( gCSector const & );
        gCSector( void );

    public:
        gCSector const & operator = ( gCSector const & );

    public:
        gCDynamicLayer *                              AccessDynamicLayer( bCString const & );
        bTRefPtrArray<bCPropertyObjectBase *> &       AccessEntityLayers( void );
        GEBool &                                      AccessFreezed( void );
        gCGeometryLayer *                             AccessGeometryLayer( bCString const & );
        gCGeometryLayerProcessStrategy * &            AccessGeometryLayerProcessStrategy( void );
        bTRefPtrArray<bCPropertyObjectBase *> &       AccessGeometryLayers( void );
        GEBool &                                      AccessLocked( void );
        GEBool &                                      AccessMarked( void );
        GEFloat &                                     AccessObjectCullFactor( void );
        GEFloat &                                     AccessVisualLoDFactor( void );
        gCWorld &                                     AccessWorld( void );
      //bTPOSmartPtr<gCWorld> &                       AccessWorldPtr( void );
        GEBool                                        BackupFiles( bCString const &, GEInt, GEBool, GEBool, bTObjArray<bCString> & );
        GEBool                                        BackupFilesExists( bCString const &, GEInt );
        void                                          CollectContexts( bTSmallArray<eCContextBase *> & ) const;
        GEBool                                        ContainsEntity( eCEntity const & ) const;
        eCProcessibleElement::eEResult                Create( gCWorld &, bCString const &, bCString const & );
        GEBool                                        Enable( GEBool );
        gCDynamicLayer const *                        GetDynamicLayer( bCString const & ) const;
        gCDynamicLayer *                              GetDynamicLayerAt( GEInt );
        gCDynamicLayer const *                        GetDynamicLayerAt( GEInt ) const;
        GEInt                                         GetDynamicLayerCount( void ) const;
        GEInt                                         GetDynamicLayerIndex( bCString const & ) const;
        bTRefPtrArray<bCPropertyObjectBase *> const & GetEntityLayers( void ) const;
        GEBool const &                                GetFreezed( void ) const;
        gCGeometryLayer const *                       GetGeometryLayer( bCString const & ) const;
        gCGeometryLayer *                             GetGeometryLayerAt( GEInt );
        gCGeometryLayer const *                       GetGeometryLayerAt( GEInt ) const;
        GEInt                                         GetGeometryLayerCount( void ) const;
        GEInt                                         GetGeometryLayerIndex( bCString const & ) const;
        gCGeometryLayerProcessStrategy *              GetGeometryLayerProcessStrategy( void ) const;
        bTRefPtrArray<bCPropertyObjectBase *> const & GetGeometryLayers( void ) const;
        GEBool const &                                GetLocked( void ) const;
        GEBool const &                                GetMarked( void ) const;
        GEFloat const &                               GetObjectCullFactor( void ) const;
        GEFloat const &                               GetVisualLoDFactor( void ) const;
        gCWorld const &                               GetWorld( void ) const;
      //bTPOSmartPtr<gCWorld> const &                 GetWorldPtr( void ) const;
        gCDynamicLayer *                              ImportDynamicLayer( eCArchiveFile & );
        gCDynamicLayer *                              ImportDynamicLayer( bCString const & );
        gCGeometryLayer *                             ImportGeometryLayer( eCArchiveFile & );
        gCGeometryLayer *                             ImportGeometryLayer( bCString const & );
        eCProcessibleElement::eEResult                InsertDynamicLayer( gCDynamicLayer * );
        eCProcessibleElement::eEResult                InsertGeometryLayer( gCGeometryLayer * );
        gCDynamicLayer *                              InsertNewDynamicLayer( bCString const &, gEEntityType );
        gCGeometryLayer *                             InsertNewGeometryLayer( bCString const &, gEGeometryType );
        GEBool                                        IsEnabled( void ) const;
        GEBool                                        IsReadOnly( void ) const;
        GEBool                                        IsSysSector( void ) const;
        GEFloat                                       QueryProgress( void );
        GEBool                                        RemoveAll( void );
        eCProcessibleElement::eEResult                RemoveDynamicLayer( gCDynamicLayer * );
        eCProcessibleElement::eEResult                RemoveGeometryLayer( gCGeometryLayer * );
        GEBool                                        RestoreFiles( bCString const & );
        void                                          SetEntityLayers( bTRefPtrArray<bCPropertyObjectBase *> const & );
        void                                          SetFreezed( GEBool const & );
        void                                          SetGeometryLayerProcessStrategy( gCGeometryLayerProcessStrategy * );
        void                                          SetGeometryLayers( bTRefPtrArray<bCPropertyObjectBase *> const & );
        void                                          SetLocked( GEBool const & );
        void                                          SetMarked( GEBool const & );
        void                                          SetObjectCullFactor( GEFloat const & );
        void                                          SetVisualLoDFactor( GEFloat const & );
      //void                                          SetWorldPtr( bTPOSmartPtr<gCWorld> const & );
        void                                          UnloadCaches( void );

    protected:
        static void GE_STDCALL CopyFileToBackup( bCString const &, bCString const &, bTObjArray<bCString> & );

    protected:
        GEBool                         ContainsEntity( eCEntity const *, eCEntity const & ) const;
        void                           Invalidate( void );
        GEBool                         OnEnable( GEBool );
        eCProcessibleElement::eEResult RemoveDynamicLayerInternal( gCDynamicLayer * );
        void                           SetWorld( bCPropertyObjectBase const * );
        void                           SetWorld( gCWorld const * );

};

#pragma warning( pop )

#endif
