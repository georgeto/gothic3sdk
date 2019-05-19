#ifndef GFC_LISTCTRL_H_INCLUDED
#define GFC_LISTCTRL_H_INCLUDED

struct SFFGUIListCtrlColumn;
struct SFFGUIListCtrlItem {
    UINT            mask;
    int             iItem;
    int             iSubItem;
    UINT            state;
    UINT            stateMask;
    GELPUnicodeChar pszText;
    int             cchTextMax;
    int             iImage;
    LPARAM          lParam;
};
class EFFGUIState;
struct SFFGUIListCtrlItemColors
{
    /*
        0: Normale Textfarbe
        4: Mouseover Farbe
        6: Normale Hintergrundfarbe
        10: Mouseover Hintergrundfarbe
    */

    public:
            bCFloatAlphaColor mColor[18];
};

struct NMLISTVIEW {
    NMHDR hdr;
    int iItem;
    int iSubItem;
    UINT uNewState;
    UINT uOldState;
    UINT uChanged;
    POINT ptAction;
    LPARAM lParam;
};

class GE_DLLIMPORT CFFGFCListCtrl :
    public CFFGFCWnd
{
    public: virtual ~CFFGFCListCtrl( void );

    public:
        CFFGFCListCtrl( CFFGFCListCtrl const & );
        CFFGFCListCtrl( void );

    public:
        CFFGFCListCtrl & operator = ( CFFGFCListCtrl const & );

    public:
        GEBool            Create( bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );
        void              DeleteAllColumns( void );
        void              DeleteAllItems( void );
        GEBool            DeleteColumn( GEInt );
        GEBool            DeleteItem( GEInt );
        GEBool            GetColumn( GEInt, SFFGUIListCtrlColumn & ) const;
        CFFGFCImageList * GetImageList( GEInt ) const;
        GEInt             GetInsertMark( void ) const;
        GEBool            GetItem( SFFGUIListCtrlItem & ) const;
        GEBool            GetItemBkColor( GEInt, EFFGUIState, bCFloatAlphaColor & ) const;
        GEBool            GetItemColor( GEInt, EFFGUIState, bCFloatAlphaColor & ) const;
        GEBool            GetItemColors( GEInt, SFFGUIListCtrlItemColors & ) const;
        GEInt             GetItemCount( void ) const;
        GELPVoid          GetItemData( GEInt ) const;
        GEInt             GetSelectionMark( void ) const;
        GEInt             HitTest( bCPoint, GEUInt * ) const;
        GEInt             InsertColumn( GEInt, SFFGUIListCtrlColumn const & );
        GEInt             InsertColumn( GEInt, GELPCUnicodeChar, GEInt, GEInt, GEInt );
        GEInt             InsertItem( SFFGUIListCtrlItem const & );
        GEInt             InsertItem( GEInt, GELPCUnicodeChar );
        GEInt             InsertItem( GEInt, GELPCUnicodeChar, GEInt );
        GEBool            SetColumn( GEInt, SFFGUIListCtrlColumn const & );
        CFFGFCImageList * SetImageList( CFFGFCImageList *, GEInt );
        GEInt             SetInsertMark( GEInt );
        GEBool            SetItem( SFFGUIListCtrlItem const & );
        GEBool            SetItemBkColor( GEInt, EFFGUIState, bCFloatAlphaColor const & );
        GEBool            SetItemColor( GEInt, EFFGUIState, bCFloatAlphaColor const & );
        GEBool            SetItemColors( GEInt, SFFGUIListCtrlItemColors const & );
        GEBool            SetItemCount( GEInt );
        GEBool            SetItemData( GEInt, GELPVoid );
        GEBool            SetItemState( GEInt, SFFGUIListCtrlItem const & );
        GEBool            SetItemState( GEInt, GEUInt, GEUInt );
        GEBool            SetItemText( GEInt, GEInt, bCUnicodeString const & );
        GEInt             SetSelectionMark( GEInt );
        void              SortItems( GEInt ( GE_CCALL* )( GEUInt, GEUInt, GEUInt ), GEUInt );

};

#endif
