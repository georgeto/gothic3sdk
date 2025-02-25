#ifndef GE_SESSION_H_INCLUDED
#define GE_SESSION_H_INCLUDED

class gCSessionKeys;
class gCScreenOutputCtrl;

class GE_DLLIMPORT gCSession :
    public eCEngineComponentBase
{
    public:    virtual GEBool                           HandleMessage( GEUInt, GEUInt, GEInt );
    public: using bCObjectBase::CopyFrom;
    public:    virtual void                             CopyFrom( gCSession const & );
    public: using bCObjectBase::Write;
    public:    virtual bEResult                         Write( bCOStream & );
    public:    virtual bEResult                         Read( bCIStream & );
    public:    virtual void                             Destroy( void );
    public:    virtual bEResult                         Create( void );
    public:    virtual                                 ~gCSession( void );
    protected: virtual eCInputReceiver::eEInputPriority GetInputPriority( void ) const;
    protected: virtual GEInt                            OnAction( eCInpShared::eSGameKeyMessage const & );
    protected: virtual GEInt                            OnKeyboard( eCInpShared::eSInputMessage const & );
    protected: virtual GEInt                            OnMouse( eCInpShared::eSInputMessage const & );
    public:    virtual bEResult                         PostInitialize( void );
    public:    virtual bEResult                         PreShutdown( void );
    public:    virtual bEResult                         WorldActivate( void );
    public:    virtual bEResult                         WorldDeactivate( void );
    public:    virtual void                             Process( void );
    public:    virtual void                             OnPostRender( void );

    protected:
        static gCSession * ms_pCurrentSession;

    public:
        static gCSession & GE_STDCALL                  AccessSession( void );
        static gCSession & GE_STDCALL                  GetInstance( void );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );
        static gCSession const & GE_STDCALL            GetSession( void );
        static GEBool GE_STDCALL                       PrefetchEntityCallback( GEInt, GEInt );

    public:
        gCSession( void );

    public:
        gCSession const & operator =  ( gCSession const & );
        bCOStream &       operator >> ( bCOStream & );
        bCIStream &       operator << ( bCIStream & );

    public:
        gCSessionKeys &                              AccessSessionKeys( void ) const;
        bTPropertyContainer<gESession_State> &       AccessState( void );
        GEBool                                       CanPlayerMove( void ) const;
        GEBool                                       CopyCheckFailed( void ) const;
        gCCameraAI_PS *                              GetCamera_PS( void );
        gCCameraAI_PS const *                        GetCamera_PS( void ) const;
        gCSessionCheats const &                      GetCheats( void ) const;
        eCEntity *                                   GetEditorEntity( void ) const;
        gCGUIManager *                               GetGUIManager( void ) const;
        eCDynamicEntity *                            GetHero( void );
        eCDynamicEntity const *                      GetHero( void ) const;
        eCDynamicEntity *                            GetPlayer( void );
        eCDynamicEntity const *                      GetPlayer( void ) const;
        gCScreenOutputCtrl *                         GetScreenOutputCtrl( void );
        gCSessionInfo const &                        GetSessionInfo( void ) const;
        gCSessionKeys const &                        GetSessionKeys( void ) const;
        bTPropertyContainer<gESession_State> const & GetState( void ) const;
        GEBool                                       GiveAllItems( GEBool, GEU32, GEU32, bCString const & ) const;
        GEBool                                       GiveItems( bCString const &, GEU32, GEU32 ) const;
        void                                         GotoLoadedPosition( eCEntity *, GEBool );
        void                                         GotoStartPosition( GEBool );
        void                                         Invalidate( void );
        GEBool const                                 IsGameRunning( void ) const;
        GEBool const                                 IsInTestMode( void ) const;
        GEBool                                       IsPaused( void ) const;
        GEBool                                       IsSaveAllowed( void ) const;
        void                                         OpenMenu( void );
        void                                         Pause( void );
        void                                         Resume( void );
        GEBool                                       SetAttrib( bCString const &, GEInt );
        void                                         SetControlsCustomWaitForKeyCallback( GELPVoid, GELPVoid );
        void                                         SetState( bTPropertyContainer<gESession_State> const & );
        void                                         SetTestMode( GEBool );
        eCEntity *                                   SpawnEntity( bCString const &, bCVector, GEBool );
        void                                         Start( gESession_StartMode );
        void                                         StartControlNPC( gCEntity * );
        void                                         Stop( void );
        void                                         StopControlNPC( GEBool );
        GEBool                                       Teach( bCString const & ) const;

    protected:
        gCSession( gCSession const & );

    protected:
        void            CreateCameraEntity( void );
        void            CreatePlayerEntity( void );
        void GE_STDCALL OnBeamPlayerForward( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnChangeGameTime( bCObjectRefBase *, eCConsoleEventArg * );
        void GE_STDCALL OnCheat( bCObjectRefBase *, eCConsoleEventArg * );
        void GE_STDCALL OnConsoleCommand( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnControlEntity( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnDisposeItem( bCObjectRefBase *, eCConsoleEventArg * );
        void GE_STDCALL OnGameMenuClicked( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnGiveItem( bCObjectRefBase *, eCConsoleEventArg * );
        void GE_STDCALL OnGotoCamera( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnGotoEntity( bCObjectRefBase *, eCConsoleEventArg * );
        void GE_STDCALL OnResetCamera( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnResetPlayer( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnSingleStep( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnSpawnEntity( bCObjectRefBase *, eCConsoleEventArg * );
        void GE_STDCALL OnTeach( bCObjectRefBase *, eCConsoleEventArg * );
        void GE_STDCALL OnToggleDebugMode( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnToggleEditMode( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnToggleFixedCam( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnToggleFreeFlyCam( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnToggleShowAI( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnToggleShowNames( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnToggleShowTime( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnTriggerEntity( bCObjectRefBase *, eCConsoleEventArg * );
        void GE_STDCALL OnUntriggerEntity( bCObjectRefBase *, eCConsoleEventArg * );
        void GE_STDCALL OnViewMenuClicked( bCObjectRefBase *, bCEvent * );
        void GE_STDCALL OnWatchEntity( bCObjectRefBase *, bCEvent * );
        void            SetPlayer( eCDynamicEntity * );

    private:
        void DeregisterEvents( void );
        void RegisterEvents( void );
        void TransferDebugEvents( eCEntity & );

};

#endif
