#ifndef GFC_WND_H_INCLUDED
#define GFC_WND_H_INCLUDED

class IFFGUIWindow;
enum EFFGUIScrollBar
{
    // Shows or hides a window's standard horizontal and vertical scroll bars.
    EFFGUIScrollBar_Horz = 0,
    // Shows or hides a scroll bar control. The hwnd parameter must be the handle to the scroll bar control.
    EFFGUIScrollBar_Vert = 1,
    // Shows or hides a window's standard horizontal scroll bars.
    EFFGUIScrollBar_Ctl  = 2,
    // Shows or hides a window's standard vertical scroll bar.
    EFFGUIScrollBar_Both = 3,
};
struct SFFGUIDeleteItem;
struct SFFGUIDrawItem;
struct SFFGUIWndMinMax;
struct SFFGUIMeasureItem;
struct SFFGUINM;
struct SFFGUIWndPosChange;
class CFFGFCScrollBar;
struct SFFGUIScrollInfo;

class GE_DLLIMPORT CFFGFCWnd
{
    public:
        struct SCreateWnd;

    protected: virtual GEInt  MsgProc( IFFGUIWindow *, GEUInt, GEUInt, GEUInt );
    public:    virtual GEBool ContinueModal( void );
    public:    virtual void   EndModalLoop( GEInt );
    public:    virtual void   DoDataExchange( CFFGFCDataExchange * );
    public:    virtual GEBool PreCreateWindow( SCreateWnd & );
    public:    virtual void   PostNcDestroy( void );
    public:    virtual void   OnCreate( void );
    public:    virtual void   OnDestroy( void );
    public:    virtual void   OnClose( void );
    public:    virtual void   OnEnable( GEBool );
    public:    virtual void   OnShowWindow( GEBool );
    public:    virtual void   OnActivate( CFFGFCWnd * );
    public:    virtual void   OnDeactivate( CFFGFCWnd * );
    public:    virtual void   OnSetFocus( CFFGFCWnd * );
    public:    virtual void   OnKillFocus( CFFGFCWnd * );
    public:    virtual void   OnStyleChanged( GEU32, GEU32 );
    public:    virtual void   OnStyleChanging( GEU32, GEU32 );
    public:    virtual void   OnWindowPosChanged( SFFGUIWndPosChange & );
    public:    virtual void   OnWindowPosChanging( SFFGUIWndPosChange & );
    public:    virtual void   OnMove( GEInt, GEInt );
    public:    virtual void   OnMoving( GEUInt, bCRect & );
    public:    virtual void   OnSize( GEInt, GEInt );
    public:    virtual void   OnSizing( GEUInt, bCRect & );
    public:    virtual void   OnGetMinMaxInfo( SFFGUIWndMinMax & );
    public:    virtual void   OnCommand( GEUInt, GEUInt );
    public:    virtual void   OnNotify( GEUInt, GEUInt );
    public:    virtual void   OnNotify( GEInt, SFFGUINM *, GEI32 * );
    public:    virtual void   OnParentNotify( GEUInt, bCPoint *, CFFGFCWnd * );
    public:    virtual void   OnKeyDown( GEUInt, GEUInt, GEUInt );
    public:    virtual void   OnKeyUp( GEUInt, GEUInt, GEUInt );
    public:    virtual void   OnChar( GEUInt, GEUInt, GEUInt );
    public:    virtual void   OnLButtonDown( GEUInt, bCPoint );
    public:    virtual void   OnLButtonUp( GEUInt, bCPoint );
    public:    virtual void   OnLButtonDblClk( GEUInt, bCPoint );
    public:    virtual void   OnRButtonDown( GEUInt, bCPoint );
    public:    virtual void   OnRButtonUp( GEUInt, bCPoint );
    public:    virtual void   OnRButtonDblClk( GEUInt, bCPoint );
    public:    virtual void   OnMButtonDown( GEUInt, bCPoint );
    public:    virtual void   OnMButtonUp( GEUInt, bCPoint );
    public:    virtual void   OnMButtonDblClk( GEUInt, bCPoint );
    public:    virtual void   OnMouseMove( GEUInt, bCPoint );
    public:    virtual void   OnMouseWheel( GEUInt, GEI16, bCPoint );
    public:    virtual void   OnHScroll( GEUInt, GEUInt, CFFGFCScrollBar * );
    public:    virtual void   OnVScroll( GEUInt, GEUInt, CFFGFCScrollBar * );
    public:    virtual void   OnPaint( void );
    public:    virtual void   OnEraseBkgnd( void );
    public:    virtual void   OnNcCreate( void );
    public:    virtual void   OnNcDestroy( void );
    public:    virtual void   OnNcLButtonDown( GEUInt, bCPoint );
    public:    virtual void   OnNcLButtonUp( GEUInt, bCPoint );
    public:    virtual void   OnNcLButtonDblClk( GEUInt, bCPoint );
    public:    virtual void   OnNcRButtonDown( GEUInt, bCPoint );
    public:    virtual void   OnNcRButtonUp( GEUInt, bCPoint );
    public:    virtual void   OnNcRButtonDblClk( GEUInt, bCPoint );
    public:    virtual void   OnNcMButtonDown( GEUInt, bCPoint );
    public:    virtual void   OnNcMButtonUp( GEUInt, bCPoint );
    public:    virtual void   OnNcMButtonDblClk( GEUInt, bCPoint );
    public:    virtual void   OnNcMouseMove( GEUInt, bCPoint );
    public:    virtual void   OnNcPaint( void );
    public:    virtual void   OnDeleteItem( GEU32, SFFGUIDeleteItem & );
    public:    virtual void   OnMeasureItem( GEU32, SFFGUIMeasureItem & );
    public:    virtual void   OnDrawItem( GEU32, SFFGUIDrawItem & );
    public:    virtual void   OnDesktopSized( GEInt, GEInt );
    public:    virtual void   OnThemeChanged( void );
    protected: virtual GEInt  WindowProc( GEUInt, GEUInt, GEUInt );
    public:    virtual       ~CFFGFCWnd( void );

    private:
        GEInt __FIXME_0004;
        GEInt __FIXME_0008;
        GEInt __FIXME_000C;

    public:
        static CFFGFCWnd * GE_STDCALL FromHandle( IFFGUIWindow * );

    public:
        CFFGFCWnd( CFFGFCWnd const & );
        CFFGFCWnd( void );

    public:
        CFFGFCWnd & operator = ( CFFGFCWnd const & );

    public:
        GEBool                AnimateWindow( GEU32, GEU32 );
        void                  BringWindowToTop( void );
        void                  CenterWindow( void );
        void                  ClientToScreen( bCPoint & ) const;
        void                  ClientToScreen( bCRect & ) const;
        GEBool                Create( bCString const &, bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );
        GEBool                Create( bCString const &, bCUnicodeString const &, GEU32, GEInt, GEInt, GEInt, GEInt, CFFGFCWnd *, GEU32 );
        GEBool                Create( bCString const &, CFFGFCWnd * );
        GEBool                Create( GEInt, CFFGFCWnd * );
        void                  Destroy( void );
        GEBool                EnableWindow( GEBool );
        CFFGFCWnd *           GetActiveWindow( void ) const;
        void                  GetClientRect( bCRect & ) const;
        CFFGFCDeviceContext * GetDC( void ) const;
        CFFGFCWnd *           GetDesktopWindow( void ) const;
        GEU32                 GetDlgCtrlID( void ) const;
        CFFGFCWnd *           GetDlgItem( GEU32 ) const;
        CFFGFCWnd *           GetFocus( void ) const;
        IFFGUIWindow *        GetHandle( void ) const;
        GEU32                 GetHotKey( void ) const;
        CFFGFCWnd *           GetParentWindow( void ) const;
        GEBool                GetScrollInfo( EFFGUIScrollBar, SFFGUIScrollInfo & ) const;
        GEU32                 GetStyle( void ) const;
        CFFGFCDeviceContext * GetWindowDC( void ) const;
        void                  GetWindowRect( bCRect & ) const;
        bCUnicodeString       GetWindowTextA( void ) const;
        void                  GetWindowTextA( bCUnicodeString & ) const;
        GEBool                HasFocus( void ) const;
        GEBool                IsActiveWindow( void ) const;
        GEBool                IsAttached( void ) const;
        GEBool                IsIconic( void ) const;
        GEBool                IsMouseOver( void ) const;
        GEBool                IsWindowEnabled( void ) const;
        GEBool                IsWindowVisible( void ) const;
        GEBool                IsZoomed( void ) const;
        GEU32                 ModifyStyle( GEU32, GEU32 );
        void                  MoveWindow( bCRect const & );
        void                  MoveWindow( GEInt, GEInt, GEInt, GEInt );
        GEInt                 RunModalLoop( GEU32 );
        void                  ScreenToClient( bCPoint & ) const;
        void                  ScreenToClient( bCRect & ) const;
        GEInt                 SendMessage( GEUInt, GEUInt, GEUInt ) const;
        void                  SendWindowToBack( void );
        CFFGFCWnd *           SetActiveWindow( void );
        void                  SetDlgCtrlID( GEU32 );
        GEU32                 SetExtendedStyle( GEU32 );
        CFFGFCWnd *           SetFocus( void );
        void                  SetHotKey( GEU32 );
        GEBool                SetScrollInfo( EFFGUIScrollBar, SFFGUIScrollInfo const & );
        void                  SetWindowTextA( bCUnicodeString const & );
        void                  ShowScrollBar( EFFGUIScrollBar, GEBool a_bShow );
        GEBool                ShowWindow( GEBool );
        GEBool                SubclassDlgItem( CFFGFCWnd *, GEU32 );
        GEBool                UpdateData( GEBool );

    protected:
        GEInt DefWindowProcA( GEUInt, GEUInt, GEUInt ) const;
        GEInt Default( void );
        void  SetHandle( IFFGUIWindow * );

};
GE_ASSERT_SIZEOF( CFFGFCWnd, 0x10 );

#endif
