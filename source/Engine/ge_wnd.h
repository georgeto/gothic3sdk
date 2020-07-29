#ifndef GE_WND_H_INCLUDED
#define GE_WND_H_INCLUDED

class eCCanvas;
class eCTitleBarCtrl;
class eCNotifyEventArg;
class eCScrollBarCtrl;
class eCGUIManager;
class eCCaret;
class eCCursor;
class eCTextItem;
class eCColorScheme {
    public:
        enum eEColorIndex;
};


enum eEWinTextMode;
enum eEWinAlignMode;
enum eEWinAniMode;

class eCWnd;
class eCClickEventArg :
    public bCEvent
{
  bCPoint m_ClickPosition;
  GEBool  m_bMouseButtonState;
  GEBool  m_bMouseButtonLastState;
  GEInt   m_iSomeIndex;
  eCWnd * m_pWindow;
};
GE_ASSERT_SIZEOF( eCClickEventArg, 0x2C )

class GE_DLLIMPORT eCWnd :
    public eCInputReceiver
{
    public:    virtual bCString        GetText( void ) const;
    public:    virtual void            GetText( bCString & ) const;
    public:    virtual bCString        GetTitleBarText( void ) const;
    public:    virtual void            SetID( GEU32 );
    public:    virtual void            SetStyle( GEU32 );
    public:    virtual void            SetStyleEx( GEU32 );
    public:    virtual void            SetFlags( GEU32 );
    public:    virtual void            SetParent( eCWnd * );
    public:    virtual void            SetOwner( eCWnd * );
    public:    virtual void            SetCanvas( eCCanvas * );
    public:    virtual void            SetTitleBar( eCTitleBarCtrl * );
    public:    virtual void            SetFont( eCFont * );
    public:    virtual void            SetPosition( bCPoint const &, GEBool );
    public:    virtual void            SetDimensions( bCPoint const &, GEBool );
    public:    virtual void            SetName( bCString const & );
    public:    virtual void            SetTitleBarText( bCString const & );
    public:    virtual void            SetText( bCString const & );
    public:    virtual void            SetModal( GEBool );
    public:    virtual GEBool          IsModal( void ) const;
    public:    virtual GEU32           DoModal( void );
    public:    virtual GEBool          IsModalFinished( void ) const;
    protected: virtual void            OnActivate( GEU32, eCWnd *, GEBool );
    protected: virtual void            OnMove( GEInt, GEInt );
    protected: virtual void            OnSize( GEU32, GEInt, GEInt );
    protected: virtual void            UpdateCanvas( void );
    protected: virtual void            UpdateFont( void );
    public:    virtual void            Process( void );
    public:    virtual void            UpdateWindow( void );
    protected: virtual GEBool          OnNotify( GEU32, GEU32, GEI32 * );
    protected: virtual void GE_STDCALL OnCommand( bCObjectRefBase *, eCNotifyEventArg * );
    protected: virtual void GE_STDCALL OnEvent( bCObjectRefBase *, bCEvent * );
    protected: virtual void GE_STDCALL OnClick( bCObjectRefBase *, eCClickEventArg * );
    protected: virtual GEBool          OnChildNotify( GEU32, GEU32, GEU32, GEI32 * );
    protected: virtual void            OnParentNotify( GEU32, GEU32, GEU32, GEI32 * );
    protected: virtual void            OnSysColorChange( void );
    public:    virtual void            Render( void );
    protected: virtual void            OnRender( void );
    public:    virtual bEResult        Create( GEU32, bCRect const &, GEU32, eCWnd * );
    public:    virtual GEInt           OnKeyUp( eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const & );
    public:    virtual GEInt           OnKeyDown( eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const & );
    public:    virtual GEInt           OnChar( GEChar, eCInpShared::eSInputMessage const & );
    public:    virtual void            OnLButtonDblClk( GEU32, bCPoint );
    public:    virtual void            OnLButtonDown( GEU32, bCPoint );
    public:    virtual void            OnLButtonUp( GEU32, bCPoint );
    public:    virtual void            OnMButtonDblClk( GEU32, bCPoint );
    public:    virtual void            OnMButtonDown( GEU32, bCPoint );
    public:    virtual void            OnMButtonUp( GEU32, bCPoint );
    public:    virtual void            OnMouseActivate( eCWnd *, GEU32, GEU32 );
    public:    virtual void            OnMouseMove( GEU32, bCPoint );
    public:    virtual void            OnMouseWheel( GEU32, GEI8, bCPoint );
    public:    virtual void            OnMouseIdle( bCPoint const & );
    public:    virtual void            OnMouseLeave( void );
    public:    virtual void            OnRButtonDblClk( GEU32, bCPoint );
    public:    virtual void            OnRButtonDown( GEU32, bCPoint );
    public:    virtual void            OnRButtonUp( GEU32, bCPoint );
    public:    virtual void            OnHScroll( GEU32, GEU32, eCScrollBarCtrl * );
    public:    virtual void            OnVScroll( GEU32, GEU32, eCScrollBarCtrl * );
    public:    virtual void            OnCaptureChanged( eCWnd * );
    public:    virtual void            OnSetCursor( eCWnd *, GEU32, GEU32 );
    public:    virtual void            OnTimer( GEU32 );
    public:    virtual void            OnBeforeToolTipDisplay( bCPoint const &, bCString & );
    public:    virtual void            OnFinishedOpening( void );
    public:    virtual void            OnFinishedClosing( void );
    public: using bCObjectBase::Write;
    public:    virtual bEResult        Write( bCOStream & );
    public:    virtual bEResult        Read( bCIStream & );
    public:    virtual void            Destroy( void );
    public:    virtual bEResult        Create( void );
    public: using eCInputReceiver::CopyFrom;

    protected: virtual                ~eCWnd( void );

    protected:
        static GEFloat        ms_fTimePerCharacter;
        static eCGUIManager & ms_mgrWindows;

    public:
        static eCWnd * GE_STDCALL GetDesktopWindow( void );
        static GEInt GE_STDCALL   GetIDFromString( bCString const & );
        static GEInt GE_STDCALL   GetStyleFromString( bCString const & );
        static void GE_STDCALL    SetTimePerCharacter( GEFloat );

    public:
        eCWnd( eCWnd const & );
        eCWnd( void );

    public:
        eCWnd &     operator =  ( eCWnd const & );
        bCOStream & operator >> ( bCOStream & );
        bCIStream & operator << ( bCIStream & );

    public:
        void                           BringWindowToTop( void );
        void                           CenterWindow( eCWnd * );
        void                           ClearPrintWin( void );
        void                           ClientToDesktop( bCPoint & ) const;
        void                           ClientToDesktop( bCRect & ) const;
        void                           ClientToDesktop( bCPoint * const, int ) const;
        void                           ClipChildren( GEBool );
        void                           ClipSiblings( GEBool );
        GEBool                         ClipsChildren( void ) const;
        GEBool                         ClipsSiblings( void ) const;
        void                           CopyFrom( eCWnd const & );
        void                           CopyTo( eCWnd & ) const;
        void                           DesktopToClient( bCPoint & ) const;
        void                           DesktopToClient( bCRect & ) const;
        void                           DesktopToClient( bCPoint * const, int ) const;
        GEBool                         EnableWindow( GEBool );
        eCCanvas *                     GetCanvas( void );
        eCCanvas const *               GetCanvas( void ) const;
        void                           GetCanvas( eCCanvas * & ) const;
        void                           GetClientRect( bCRect &, GEBool ) const;
        bCPoint                        GetDesktopPosition( void ) const;
        void                           GetDesktopPosition( bCPoint & ) const;
        bCPoint const &                GetDimensions( void ) const;
        void                           GetDimensions( bCPoint & ) const;
        GEU32                          GetFlags( void ) const;
        eCFont *                       GetFont( void );
        eCFont const *                 GetFont( void ) const;
        void                           GetFont( eCFont * & ) const;
        eCScrollBarCtrl *              GetHScrollBarCtrl( void );
        eCScrollBarCtrl const *        GetHScrollBarCtrl( void ) const;
        eCCaret *                      GetHighlightCaret( void );
        eCCaret const *                GetHighlightCaret( void ) const;
        GEU32                          GetID( void ) const;
        void                           GetID( GEU32 & ) const;
        bCString const &               GetName( void ) const;
        eCWnd *                        GetOwner( void );
        eCWnd const *                  GetOwner( void ) const;
        void                           GetOwner( eCWnd * & ) const;
        eCWnd *                        GetParent( void );
        eCWnd const *                  GetParent( void ) const;
        void                           GetParent( eCWnd * & ) const;
        bCPoint const &                GetPosition( void ) const;
        void                           GetPosition( bCPoint & ) const;
        eCWnd *                        GetSafeOwner( void );
        eCWnd const *                  GetSafeOwner( void ) const;
        eCWnd *                        GetSafeParent( void );
        eCWnd const *                  GetSafeParent( void ) const;
        GEU32                          GetStyle( void ) const;
        void                           GetStyle( GEU32 & ) const;
        GEU32                          GetStyleEx( void ) const;
        bTObjArray<eCTextItem> const & GetTextArray( void ) const;
        eCTitleBarCtrl *               GetTitleBar( void ) const;
        bCString const &               GetToolTipText( void ) const;
        eCWnd *                        GetTopLevelParent( void ) const;
        eCScrollBarCtrl *              GetVScrollBarCtrl( void );
        eCScrollBarCtrl const *        GetVScrollBarCtrl( void ) const;
        void                           GetWindowRect( bCRect & ) const;
        GEBool                         IsActive( void ) const;
        GEBool                         IsAnimating( void ) const;
        GEBool                         IsChild( eCWnd * ) const;
        GEBool                         IsEnabled( void ) const;
        GEBool                         IsFocused( void ) const;
        GEBool                         IsMaximized( void ) const;
        GEBool                         IsMinimized( void ) const;
        GEBool                         IsVisible( void ) const;
        GEBool                         LoadLayout( bCString const & );
        void                           MapWindowPoints( eCWnd const *, bCRect & ) const;
        void                           MapWindowPoints( eCWnd const *, bCPoint * const, int ) const;
        GEBool                         MatchesFlag( GEU32 ) const;
        GEBool                         MatchesStyle( GEU32 ) const;
        GEBool                         MatchesStyleEx( GEU32 ) const;
        GEBool                         ModifyFlags( GEU32, GEU32 );
        GEBool                         ModifyStyle( GEU32, GEU32, GEU32 );
        GEBool                         ModifyStyleEx( GEU32, GEU32, GEU32 );
        void                           MoveWindow( bCPoint const &, bCPoint const &, GEBool );
        void                           MoveWindow( bCRect const &, GEBool );
        void                           Print( bCPoint const &, bCString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           Print( bCPoint const &, bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           Print( bCString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           Print( bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintAligned( bCString const &, bCPoint const &, eEWinAlignMode, eEWinAlignMode, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintAligned( bCUnicodeString const &, bCPoint const &, eEWinAlignMode, eEWinAlignMode, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintCX( int, bCString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintCX( int, bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintCXY( bCString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintCXY( bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintCY( int, bCString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintCY( int, bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintStatic( bCPoint, bCString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintStatic( bCPoint, bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintStaticAligned( bCString const &, bCPoint const &, eEWinAlignMode, eEWinAlignMode, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintStaticAligned( bCUnicodeString const &, bCPoint const &, eEWinAlignMode, eEWinAlignMode, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintStaticCX( int, bCString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintStaticCX( int, bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintStaticCXY( bCString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintStaticCXY( bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintStaticCY( int, bCString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintStaticCY( int, bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimed( bCPoint, bCString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimed( bCPoint, bCUnicodeString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedAligned( bCString const &, bCPoint const &, GEFloat, eEWinAlignMode, eEWinAlignMode, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedAligned( bCUnicodeString const &, bCPoint const &, GEFloat, eEWinAlignMode, eEWinAlignMode, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedCX( int, bCString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedCX( int, bCUnicodeString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedCXY( bCString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedCXY( bCUnicodeString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedCY( int, bCString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedCY( int, bCUnicodeString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedWin( bCString const &, bCString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedWin( bCUnicodeString const &, bCUnicodeString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedWinAligned( bCString const &, bCString const &, eEWinAlignMode, eEWinAlignMode, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedWinAligned( bCUnicodeString const &, bCUnicodeString const &, eEWinAlignMode, eEWinAlignMode, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedWinCX( bCString const &, bCString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedWinCX( bCUnicodeString const &, bCUnicodeString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedWinCXY( bCString const &, bCString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedWinCXY( bCUnicodeString const &, bCUnicodeString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedWinCY( bCString const &, bCString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintTimedWinCY( bCUnicodeString const &, bCUnicodeString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintWin( bCString const &, bCByteAlphaColor const *, eEWinTextMode );
        void                           PrintWin( bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode );
        GEBool                         SaveLayout( bCString & );
        eCWnd *                        SetActiveWindow( void );
        void                           SetAniMode( eEWinAniMode const & );
        void                           SetAutoScroll( GEFloat );
        GEBool                         SetBackgroundAlpha( GEU8 );
        eCWnd *                        SetFocus( void );
        void                           SetTextColor( bCByteAlphaColor const & );
        void                           SetToolTipText( bCString const & );
        void                           Show( GEBool, GEBool );
        eCWnd *                        WindowFromPoint( bCPoint const & ) const;

    protected:
        static bCString & GE_STDCALLCleanLine( bCString & );

    protected:
        eCCanvas * &                AccessCanvas( void );
        eCCaret * &                 AccessCaret( void );
        eCWnd *                     AccessChildByID( GEInt );
        eCWnd *                     AccessChildByIndex( GEInt );
        eCWnd *                     AccessChildByName( bCString const & );
        bTPtrArray<eCWnd *> &       AccessChildren( void );
        eCCursor * &                AccessCursor( void );
        bCPoint &                   AccessDimensions( void );
        eCFont * &                  AccessFont( void );
        eCScrollBarCtrl * &         AccessHScrollBarCtrl( void );
        eCCaret * &                 AccessHighlightCaret( void );
        GEU32 &                     AccessID( void );
        eCWnd * &                   AccessOwner( void );
        eCWnd * &                   AccessParent( void );
        bCPoint &                   AccessPosition( void );
        GEU32 &                     AccessStyle( void );
        bTObjArray<eCTextItem> &    AccessTextArray( void );
        eCScrollBarCtrl * &         AccessVScrollBarCtrl( void );
        void                        Activate( GEBool );
        void                        BringChildrenToTop( void );
        void                        CheckAutoScroll( void );
        GEBool                      CreateCanvas( void );
        GEBool                      CreateCarets( void );
        GEBool                      CreateFontA( void );
        GEBool                      CreateScrollBars( void );
        eCTextItem *                CreateTextItem( GEInt, GEInt, bCUnicodeString const &, GEFloat, bCByteAlphaColor const &, eEWinTextMode );
        GEBool                      CreateTitleBar( void );
        eCCaret *                   GetCaret( void );
        eCCaret const *             GetCaret( void ) const;
        void                        GetCaret( eCCaret * & ) const;
        eCWnd const *               GetChildByID( GEInt ) const;
        eCWnd const *               GetChildByIndex( GEInt ) const;
        eCWnd const *               GetChildByName( bCString const & ) const;
        bTPtrArray<eCWnd *> const & GetChildren( void ) const;
        void                        GetChildren( bTPtrArray<eCWnd *> & ) const;
        bCByteAlphaColor const &    GetColor( eCColorScheme::eEColorIndex ) const;
        eCCursor *                  GetCursor( void );
        eCCursor const *            GetCursor( void ) const;
        void                        GetCursor( eCCursor * & ) const;
        void                        GetHScrollBarCtrl( eCScrollBarCtrl * & ) const;
        void                        GetHighlightCaret( eCCaret * & ) const;
        void                        GetVScrollBarCtrl( eCScrollBarCtrl * & ) const;
        void                        Invalidate( void );
        GEBool                      LoadLayout_Recursive( bCString & );
        void                        MarkChildrenDirty( GEBool );
        void                        Maximize( GEBool );
        void                        Minimize( GEBool );
        void                        Notify( GEU32, GEU32, GEU32 );
        void                        PrintWinNextLine( bCUnicodeString const &, GEFloat, bCByteAlphaColor const &, eEWinTextMode, eEWinAlignMode, int );
        void                        RenderTextLines( void );
        GEBool                      SaveLayout_Recursive( bCString &, GEInt );
        void                        SetCaret( eCCaret * );
        void                        SetChildStyle( GEU32 );
        void                        SetChildren( bTPtrArray<eCWnd *> const & );
        void                        SetChildrenFadeAlpha( GEU8 );
        void                        SetCursor( eCCursor * );
        void                        SetHScrollBarCtrl( eCScrollBarCtrl * );
        void                        SetHighlightCaret( eCCaret * );
        void                        SetVScrollBarCtrl( eCScrollBarCtrl * );

    private:
        GEBool NotifyChildren( GEU32, GEU32, GEU32 );
        GEInt  NotifyParent( GEU32, GEU32, GEU32 );

    private:
        GE_PADDING( 0xE0 )
};


GE_ASSERT_SIZEOF( eCWnd, 0xF0 )
#endif
