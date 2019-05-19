#ifndef GE_WORLD_H_INCLUDED
#define GE_WORLD_H_INCLUDED

class gCProject;
class gCSaveGameHeader;

class GE_DLLIMPORT gCWorld :
    public eCProcessibleElement
{
    public:    virtual GEU16                          GetVersion( void ) const;
    public:    virtual void                           Destroy( void );
    public: using eCProcessibleElement::Create;
    public:    virtual bEResult                       Create( void );
    public:    virtual                               ~gCWorld( void );
    public:    virtual bEResult                       PostInitializeProperties( void );
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
    public:    virtual eCProcessibleElement::eEResult Activate( void );
    protected: virtual eCProcessibleElement::eEResult ReleaseData( void );

    public:
        static gCWorld * GE_STDCALL                    GetCurrentWorld( void );
        static void GE_STDCALL                         GetFileExt( bCString & );
        static bCString GE_STDCALL                     GetPlayerCameraName( void );
        static bCString GE_STDCALL                     GetPlayerName( void );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        static bCString GE_STDCALL                     GetSaveGameFolder( void );
        static gCSector * GE_STDCALL                   GetSectorForEntity( eCEntity const * );
        static GEBool GE_STDCALL                       ReadConfigFile( eCConfigFile &, bCString const & );
        static GEBool GE_STDCALL                       RenameConfigFile( bCString const &, bCString const & );
        static GEBool GE_STDCALL                       WriteConfigFile( eCConfigFile &, bCString const & );

    public:
        gCWorld( gCWorld const & );
        gCWorld( void );

    public:
        gCWorld const & operator = ( gCWorld const & );

    public:
        void                           AddToRemovedNativeEntityList( eCEntity * );
        GEBool                         BackupFiles( bCString const &, GEInt, GEBool, GEBool, GEBool );
        GEBool                         BackupFilesExists( bCString const &, GEInt, bCDateTime * );
        eCProcessibleElement::eEResult ClearSystemSector( void );
        eCProcessibleElement::eEResult Create( gCProject &, bCString const & );
        eCEntity *                     CreateChildEntity( eCEntity * );
        eCEntity *                     CreateChildEntityFromTemplate( eCEntity *, eCTemplateEntity * );
        eCDynamicEntity *              CreateDynamicEntity( bTObjArray<bCString> const & );
        eCDynamicEntity *              CreateDynamicEntity( bCString const & );
        eCDynamicEntity *              CreateDynamicEntity( void );
        eCProcessibleElement::eEResult CreateSaveGame( bCString const & );
        eCGfxImageData *               CreateSaveGameImageFromBB( void );
        eCDynamicEntity *              CreateTempDynamicEntity( bTObjArray<bCString> const & );
        eCDynamicEntity *              CreateTempDynamicEntity( bCString const & );
        eCDynamicEntity *              CreateTempDynamicEntity( void );
        GEBool                         DeleteSaveGame( bCString const & );
        GEBool                         DestroyDynamicEntity( eCDynamicEntity * );
        GEBool                         DestroyTempDynamicEntity( eCDynamicEntity * );
        void                           DoLoadLocalConfiguration( void );
        void                           DoSaveLocalConfiguration( void ) const;
        GEBool                         EnableSectorFolder( bCString const &, GEBool );
        GEBool                         ExistsSaveGame( bCString const & );
        bCString const &               GetActiveSector( void ) const;
        gCSaveGameHeader const &       GetCurrentSaveGameHeader( void ) const;
        void ( GE_STDCALL*GetLoadingCallback( void ) const )( GEUInt const &, GEUInt const &, GEUInt const &, GEUInt const & );
        gCProject &                    GetProject( void );
        gCProject const &              GetProject( void ) const;
        bEResult                       GetSaveGameHeader( bCString const &, gCSaveGameHeader & );
        void                           GetSaveGameList( bTObjArray<bCString> & );
        gCSector *                     GetSector( bCString const & );
        gCSector const *               GetSector( bCString const & ) const;
        gCSector *                     GetSectorAt( GEInt );
        gCSector const *               GetSectorAt( GEInt ) const;
        GEInt                          GetSectorCount( void ) const;
        GEInt                          GetSectorIndex( bCString const & ) const;
        gCDynamicLayer &               GetSystemLayer( void );
        gCSector &                     GetSystemSector( void );
        gCDynamicLayer &               GetSystemTempLayer( void );
        eCEntity *                     GetWorldEntity( void );
        eCEntity const *               GetWorldEntity( void ) const;
        GEBool                         GetWorldFiles( bTObjArray<bCString> & ) const;
        void                           GetWorldVersion( GEU32 &, GEU32 &, GEU32 &, GEU32 & );
        GEBool                         HasSystemLayers( void ) const;
        GEBool                         HasSystemSector( void ) const;
        gCSector *                     ImportSector( eCArchiveFile & );
        gCSector *                     ImportSector( bCString const & );
        gCSector *                     InsertNewSector( bCString const &, bCString const & );
        eCProcessibleElement::eEResult InsertSector( gCSector * );
        GEBool                         IsSaveGameModeEnabled( void ) const;
        GEBool                         IsSectorFolderEnabled( bCString const & ) const;
        GEBool                         LoadGameWorld( bCString const &, GEBool );
        void                           RemoveAll( void );
        eCProcessibleElement::eEResult RemoveSector( gCSector * );
        GEBool                         RestartWorld( GEBool );
        GEBool                         RestoreFiles( bCString const & );
        GEBool                         SaveGameWorld( bCString const &, eCGfxImageData *, GELPVoid, GEU32 );
        gCGeometryLayer *              SearchForLayer( eCContextBase const * ) const;
        void                           SetActiveSector( bCString const & );
        void                           SetLoadingCallback( void ( GE_STDCALL* )( GEUInt const &, GEUInt const &, GEUInt const &, GEUInt const & ));
        void                           UnloadCaches( void );

    protected:
        gCDynamicLayer *               CreateSystemLayer( bCString const * );
        gCSector *                     CreateSystemSector( void );
        gCDynamicLayer *               CreateSystemTempLayer( void );
        void                           DoAfterWorldActivate( void );
        void                           Invalidate( void );
        GEBool                         OnLoadDynamicContext( bCIStream &, gCDynamicLayer &, GEBool );
        eCProcessibleElement::eEResult RemoveSectorInternal( gCSector * );
        void                           SetProject( gCProject * );

};

#endif
