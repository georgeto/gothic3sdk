#ifndef GFC_TABCTRL_H_INCLUDED
#define GFC_TABCTRL_H_INCLUDED

struct SFFGUITabCtrlItem {
    UINT            mask;
    DWORD           dwState;
    DWORD           dwStateMask;
    GELPUnicodeChar pszText;
    int             cchTextMax;
    int             iImage;
    LPARAM          lParam;
};
struct SFFGUITabCtrlHitTest;

class GE_DLLIMPORT CFFGFCTabCtrl :
    public CFFGFCWnd
{
    public: virtual ~CFFGFCTabCtrl( void );

    public:
        CFFGFCTabCtrl( CFFGFCTabCtrl const & );
        CFFGFCTabCtrl( void );

    public:
        CFFGFCTabCtrl & operator = ( CFFGFCTabCtrl const & );

    public:
        void                AdjustRect( GEBool, bCRect & );
        GEBool              Create( bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );
        GEBool              DeleteAllItems( void );
        GEBool              DeleteItem( GEInt );
        void                DeselectAll( GEBool );
        GEInt               GetCurFocus( void ) const;
        GEInt               GetCurSel( void ) const;
        GEU32               GetExtendedStyle( void ) const;
        CFFGFCImageList *   GetImageList( void ) const;
        GEBool              GetItem( GEInt, SFFGUITabCtrlItem & ) const;
        GEInt               GetItemCount( void ) const;
        GEBool              GetItemRect( GEInt, bCRect & ) const;
        GEU32               GetItemState( GEInt, GEU32 ) const;
        GEInt               GetRowCount( void ) const;
        CFFGFCToolTipCtrl * GetToolTips( void ) const;
        GEBool              HighlightItem( GEInt, GEBool );
        GEInt               HitTest( SFFGUITabCtrlHitTest & ) const;
        GEInt               InsertItem( GEInt, SFFGUITabCtrlItem const & );
        GEInt               InsertItem( GEInt, bCUnicodeString const & );
        GEInt               InsertItem( GEInt, bCUnicodeString const &, GEInt );
        GEInt               InsertItem( GEU32, GEInt, bCUnicodeString const &, GEInt, GEUInt );
        GEInt               InsertItem( GEU32, GEInt, bCUnicodeString const &, GEInt, GEUInt, GEU32, GEU32 );
        void                SetCurFocus( GEInt );
        GEInt               SetCurSel( GEInt );
        GEU32               SetExtendedStyle( GEU32, GEU32 );
        CFFGFCImageList *   SetImageList( CFFGFCImageList * );
        GEBool              SetItem( GEInt, SFFGUITabCtrlItem const & );
        GEBool              SetItemExtra( GEInt );
        bCPoint             SetItemSize( bCPoint );
        GEBool              SetItemState( GEInt, GEU32, GEU32 );
        GEInt               SetMinTabWidth( GEInt );
        void                SetPadding( bCPoint );
        void                SetToolTips( CFFGFCToolTipCtrl * );

};

#endif
