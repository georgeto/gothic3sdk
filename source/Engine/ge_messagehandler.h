#ifndef GE_MESSAGEHANDLER_H_INCLUDED
#define GE_MESSAGEHANDLER_H_INCLUDED

class GE_DLLIMPORT eCMessageHandler :
    public bCObjectRefBase
{
    public:    virtual HWND__ * GetWindowHandle( void );
    public:    virtual void     SetWindowHandle( HWND__ * );
    public:    virtual void     Idle( void );
    public:    virtual GEInt    LoopMessages( void );
    public:    virtual void     ProcessNextMessage( tagMSG &, GEBool &, GEBool &, GEBool );
    public:    virtual GEInt    ProcessNextMessage( void );
    public:    virtual GEInt    HandleMessage( GEUInt, GEUInt, GEI32 );
    public:    virtual GEInt    HandleMessage( HWND__ *, GEUInt, GEUInt, GEI32 );
    public:    virtual GEInt    OnMessage( GEUInt, GEUInt, GEI32 );
    protected: virtual GEInt    OnIdle( GEUInt, GEI32 );
    protected: virtual GEInt    OnEngine( GEUInt, GEI32 );
    protected: virtual GEInt    OnUser( GEUInt, GEI32 );
    protected: virtual GEInt    OnGameApplication( GEUInt, GEI32 );
    protected: virtual GEInt    OnActivate( GEUInt, GEI32 );
    protected: virtual GEInt    OnActivateApp( GEUInt, GEI32 );
    protected: virtual GEInt    OnCancelMode( GEUInt, GEI32 );
    protected: virtual GEInt    OnChildActivate( GEUInt, GEI32 );
    protected: virtual GEInt    OnClose( GEUInt, GEI32 );
    protected: virtual GEInt    OnCompacting( GEUInt, GEI32 );
    protected: virtual GEInt    OnCreate( GEUInt, GEI32 );
    protected: virtual GEInt    OnDestroy( GEUInt, GEI32 );
    protected: virtual GEInt    OnEnable( GEUInt, GEI32 );
    protected: virtual GEInt    OnEnterSizeMove( GEUInt, GEI32 );
    protected: virtual GEInt    OnExitSizeMove( GEUInt, GEI32 );
    protected: virtual GEInt    OnGetIcon( GEUInt, GEI32 );
    protected: virtual GEInt    OnGetMinMaxInfo( GEUInt, GEI32 );
    protected: virtual GEInt    OnGetText( GEUInt, GEI32 );
    protected: virtual GEInt    OnGetTextLength( GEUInt, GEI32 );
    protected: virtual GEInt    OnInputLangChange( GEUInt, GEI32 );
    protected: virtual GEInt    OnInputLangChangeRequest( GEUInt, GEI32 );
    protected: virtual GEInt    OnMove( GEUInt, GEI32 );
    protected: virtual GEInt    OnMoving( GEUInt, GEI32 );
    protected: virtual GEInt    OnNcAvtivate( GEUInt, GEI32 );
    protected: virtual GEInt    OnNcCalcSize( GEUInt, GEI32 );
    protected: virtual GEInt    OnNcCreate( GEUInt, GEI32 );
    protected: virtual GEInt    OnNcDestroy( GEUInt, GEI32 );
    protected: virtual GEInt    OnParentNotify( GEUInt, GEI32 );
    protected: virtual GEInt    OnQueryDragIcon( GEUInt, GEI32 );
    protected: virtual GEInt    OnQueryOpen( GEUInt, GEI32 );
    protected: virtual GEInt    OnQuit( GEUInt, GEI32 );
    protected: virtual GEInt    OnSetIcon( GEUInt, GEI32 );
    protected: virtual GEInt    OnSetText( GEUInt, GEI32 );
    protected: virtual GEInt    OnSettingChange( GEUInt, GEI32 );
    protected: virtual GEInt    OnShowWindow( GEUInt, GEI32 );
    protected: virtual GEInt    OnSize( GEUInt, GEI32 );
    protected: virtual GEInt    OnSizing( GEUInt, GEI32 );
    protected: virtual GEInt    OnStyleChanged( GEUInt, GEI32 );
    protected: virtual GEInt    OnStyleChanging( GEUInt, GEI32 );
    protected: virtual GEInt    OnUserChanged( GEUInt, GEI32 );
    protected: virtual GEInt    OnWindowPosChanged( GEUInt, GEI32 );
    protected: virtual GEInt    OnWindowPosChanging( GEUInt, GEI32 );
    protected: virtual GEInt    OnDisplayChange( GEUInt, GEI32 );
    protected: virtual GEInt    OnEraseBackground( GEUInt, GEI32 );
    protected: virtual GEInt    OnIconEraseBackground( GEUInt, GEI32 );
    protected: virtual GEInt    OnNcPaint( GEUInt, GEI32 );
    protected: virtual GEInt    OnPaint( GEUInt, GEI32 );
    protected: virtual GEInt    OnPaintIcon( GEUInt, GEI32 );
    protected: virtual GEInt    OnPrint( GEUInt, GEI32 );
    protected: virtual GEInt    OnPrintClient( GEUInt, GEI32 );
    protected: virtual GEInt    OnSetReDraw( GEUInt, GEI32 );
    protected: virtual GEInt    OnSyncPaint( GEUInt, GEI32 );
    protected: virtual GEInt    OnPaletteChanged( GEUInt, GEI32 );
    protected: virtual GEInt    OnPaletteIsChanging( GEUInt, GEI32 );
    protected: virtual GEInt    OnQueryNewPalette( GEUInt, GEI32 );
    protected: virtual GEInt    OnSysColorChange( GEUInt, GEI32 );
    protected: virtual GEInt    OnCaptureChanged( GEUInt, GEI32 );
    protected: virtual GEInt    OnMouseButtonLeftClickDouble( GEUInt, GEI32 );
    protected: virtual GEInt    OnMouseButtonLeftDown( GEUInt, GEI32 );
    protected: virtual GEInt    OnMouseButtonLeftUp( GEUInt, GEI32 );
    protected: virtual GEInt    OnMouseButtonMiddleClickDouble( GEUInt, GEI32 );
    protected: virtual GEInt    OnMouseButtonMiddleDown( GEUInt, GEI32 );
    protected: virtual GEInt    OnMouseButtonMiddleUp( GEUInt, GEI32 );
    protected: virtual GEInt    OnMouseActivate( GEUInt, GEI32 );
    protected: virtual GEInt    OnMouseMove( GEUInt, GEI32 );
    protected: virtual GEInt    OnMouseWheel( GEUInt, GEI32 );
    protected: virtual GEInt    OnNcHitTest( GEUInt, GEI32 );
    protected: virtual GEInt    OnNcMouseButtonLeftClickDouble( GEUInt, GEI32 );
    protected: virtual GEInt    OnNcMouseButtonLeftDown( GEUInt, GEI32 );
    protected: virtual GEInt    OnNcMouseButtonLeftUp( GEUInt, GEI32 );
    protected: virtual GEInt    OnNcMouseButtonMiddleClickDouble( GEUInt, GEI32 );
    protected: virtual GEInt    OnNcMouseButtonMiddleDown( GEUInt, GEI32 );
    protected: virtual GEInt    OnNcMouseButtonMiddleUp( GEUInt, GEI32 );
    protected: virtual GEInt    OnNcMouseMove( GEUInt, GEI32 );
    protected: virtual GEInt    OnNcMouseButtonRightClickDouble( GEUInt, GEI32 );
    protected: virtual GEInt    OnNcMouseButtonRightDown( GEUInt, GEI32 );
    protected: virtual GEInt    OnNcMouseButtonRightUp( GEUInt, GEI32 );
    protected: virtual GEInt    OnMouseButtonRightClickDouble( GEUInt, GEI32 );
    protected: virtual GEInt    OnMouseButtonRightDown( GEUInt, GEI32 );
    protected: virtual GEInt    OnMouseButtonRightUp( GEUInt, GEI32 );
    protected: virtual GEInt    OnChar( GEUInt, GEI32 );
    protected: virtual GEInt    OnDeadChar( GEUInt, GEI32 );
    protected: virtual GEInt    OnGetHotKey( GEUInt, GEI32 );
    protected: virtual GEInt    OnHotKey( GEUInt, GEI32 );
    protected: virtual GEInt    OnKeyDown( GEUInt, GEI32 );
    protected: virtual GEInt    OnKeyUp( GEUInt, GEI32 );
    protected: virtual GEInt    OnKillFocus( GEUInt, GEI32 );
    protected: virtual GEInt    OnSetFocus( GEUInt, GEI32 );
    protected: virtual GEInt    OnSetHotKey( GEUInt, GEI32 );
    protected: virtual GEInt    OnSysChar( GEUInt, GEI32 );
    protected: virtual GEInt    OnSysDeadChar( GEUInt, GEI32 );
    protected: virtual GEInt    OnSysKeyDown( GEUInt, GEI32 );
    protected: virtual GEInt    OnSysKeyUp( GEUInt, GEI32 );
    protected: virtual GEInt    OnCommand( GEUInt, GEI32 );
    protected: virtual GEInt    OnSysCommand( GEUInt, GEI32 );
    protected: virtual GEInt    OnContextMenu( GEUInt, GEI32 );
    protected: virtual GEInt    OnDrawItem( GEUInt, GEI32 );
    protected: virtual GEInt    OnEnterMenuLoop( GEUInt, GEI32 );
    protected: virtual GEInt    OnInitMenu( GEUInt, GEI32 );
    protected: virtual GEInt    OnInitMenuPopUp( GEUInt, GEI32 );
    protected: virtual GEInt    OnMeasureItem( GEUInt, GEI32 );
    protected: virtual GEInt    OnMenuChar( GEUInt, GEI32 );
    protected: virtual GEInt    OnMenuSelect( GEUInt, GEI32 );
    protected: virtual GEInt    OnNextMenu( GEUInt, GEI32 );
    protected: virtual GEInt    OnAskClipBoardFormatName( GEUInt, GEI32 );
    protected: virtual GEInt    OnChangeClipBoardChain( GEUInt, GEI32 );
    protected: virtual GEInt    OnClear( GEUInt, GEI32 );
    protected: virtual GEInt    OnCopy( GEUInt, GEI32 );
    protected: virtual GEInt    OnCut( GEUInt, GEI32 );
    protected: virtual GEInt    OnDestroyClipBoard( GEUInt, GEI32 );
    protected: virtual GEInt    OnDrawClipBoard( GEUInt, GEI32 );
    protected: virtual GEInt    OnHorizontalScrollClipBoard( GEUInt, GEI32 );
    protected: virtual GEInt    OnPaintClipBoard( GEUInt, GEI32 );
    protected: virtual GEInt    OnPaste( GEUInt, GEI32 );
    protected: virtual GEInt    OnRenderAllFormats( GEUInt, GEI32 );
    protected: virtual GEInt    OnRenderFormat( GEUInt, GEI32 );
    protected: virtual GEInt    OnSizeClipBoard( GEUInt, GEI32 );
    protected: virtual GEInt    OnVerticalScrollClipBoard( GEUInt, GEI32 );
    protected: virtual GEInt    OnTimer( GEUInt, GEI32 );
    protected: virtual GEInt    OnCopyData( GEUInt, GEI32 );
    public:    virtual         ~eCMessageHandler( void );

    public:
        eCMessageHandler( eCMessageHandler const & );
        eCMessageHandler( void );

    public:
        eCMessageHandler & operator = ( eCMessageHandler const & );

    public:
        void ActivateIdle( GEBool );
        void Enable( GEBool );
        void Redirect( GEBool );
        void Terminate( GEBool );

};

#endif
