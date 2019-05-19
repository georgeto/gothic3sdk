#ifndef GE_GUIMANAGER_H_INCLUDED
#define GE_GUIMANAGER_H_INCLUDED

class GE_DLLIMPORT eCGUIManager :
    public eCEngineComponentBase
{
    protected: virtual GEInt                            OnMouse( eCWnd *, eCInpShared::eSInputMessage const & );
    protected: virtual GEInt                            OnKeyboard( eCWnd *, eCInpShared::eSInputMessage const & );
    public: using bCObjectBase::Write;
    public:    virtual bEResult                         Write( bCOStream & );
    public:    virtual bEResult                         Read( bCIStream & );
    public:    virtual void                             Destroy( void );
    public:    virtual bEResult                         Create( void );
    public:    virtual GEU32 const                      GetProfileLastTicksFirst( void ) const;
    public:    virtual GEU32 const                      GetProfileLastTicksSecond( void ) const;
    public:    virtual                                 ~eCGUIManager( void );
    public:    virtual eCInputReceiver::eEInputPriority GetInputPriority( void ) const;
    public:    virtual GEInt                            OnKeyboard( eCInpShared::eSInputMessage const & );
    public:    virtual GEInt                            OnMouse( eCInpShared::eSInputMessage const & );
    public:    virtual bEResult                         Initialize( void );
    public:    virtual bEResult                         PostInitialize( void );
    public:    virtual bEResult                         PreShutdown( void );
    public:    virtual void                             Process( void );
    public:    virtual void                             OnPostRender( void );
    public: using eCEngineComponentBase::CopyFrom;

    protected:
        static eCGUIManager * ms_pCurrentGUIManager;

    public:
        static eCGUIManager & GE_STDCALL               AccessGUIManager( void );
        static eCGUIManager const & GE_STDCALL         GetGUIManager( void );
        static eCGUIManager & GE_STDCALL               GetInstance( void );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCGUIManager( eCGUIManager const & );
        eCGUIManager( void );

    public:
        eCGUIManager const & operator =  ( eCGUIManager const & );
        bCOStream &          operator >> ( bCOStream & );
        bCIStream &          operator << ( bCIStream & );

    public:
        eCColorScheme &       AccessColorScheme( void );
        eCWnd *               AccessWindowByDelegate( bCDelegateBase *, GEBool );
        eCWnd *               AccessWindowByID( GEU32 );
        eCWnd *               AccessWindowByName( bCString const & );
        void                  AddModalWindow( eCWnd * );
        void                  CopyFrom( eCGUIManager const & );
        void                  CopyTo( eCGUIManager & ) const;
        GEU32                 DoModalMessageBox( bCString const &, bCString const &, GEBool );
        eCWnd *               GetActiveWindow( void );
        eCWnd const *         GetActiveWindow( void ) const;
        void                  GetActiveWindow( eCWnd * & ) const;
        eCColorScheme const & GetColorScheme( void ) const;
        eCDesktop *           GetDesktopWindow( void );
        eCDesktop const *     GetDesktopWindow( void ) const;
        void                  GetDesktopWindow( eCDesktop * & ) const;
        eCWnd *               GetFocus( void );
        eCWnd const *         GetFocus( void ) const;
        GEBool                GetShowPointer( void ) const;
        eCWnd const *         GetWindowByDelegate( bCDelegateBase *, GEBool ) const;
        eCWnd const *         GetWindowByID( GEU32 ) const;
        eCWnd const *         GetWindowByName( bCString const & ) const;
        void                  OnSysColorChange( void );
        void                  ReSize( void );
        void                  RegisterDesktopClick( bCDelegateBase * );
        void                  RemoveModalWindow( eCWnd * );
        void                  SetFocus( eCWnd * );
        void                  SetShowPointer( GEBool );
        eCWnd *               WindowFromPoint( bCPoint const & ) const;

    protected:
        eCWnd * &     AccessActiveWindow( void );
        eCDesktop * & AccessDesktopWindow( void );
        eCWnd * &     AccessFocus( void );
        void          BringWindowToTop( eCWnd * );
        void          CloseSubMenus( void );
        void          FlushQueuedWindows( void );
        void          GetColorScheme( eCColorScheme & ) const;
        void          Insert( eCWnd * );
        void          Invalidate( void );
        void          Remove( eCWnd *, GEBool );
        void          SetActiveWindow( eCWnd * );
        void          SetColorScheme( eCColorScheme const & );
        void          SetDesktopWindow( eCDesktop * );

};

#endif
