#ifndef GFC_LISTBOX_H_INCLUDED
#define GFC_LISTBOX_H_INCLUDED

class GE_DLLIMPORT CFFGFCListBox :
    public CFFGFCWnd
{
    public: virtual ~CFFGFCListBox( void );

    public:
        CFFGFCListBox( CFFGFCListBox const & );
        CFFGFCListBox( void );

    public:
        CFFGFCListBox & operator = ( CFFGFCListBox const & );

    public:
        GEInt    AddString( bCUnicodeString const & );
        GEBool   Create( bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );
        GEInt    DeleteString( GEInt );
        GEInt    FindString( bCUnicodeString const & ) const;
        GEInt    FindStringExact( bCUnicodeString const & ) const;
        GEInt    GetAnchorIndex( void ) const;
        GEInt    GetCaretIndex( void ) const;
        GEInt    GetCount( void ) const;
        GEInt    GetCurSel( void ) const;
        GEU32    GetItemData( GEInt ) const;
        GELPVoid GetItemDataPtr( GEInt ) const;
        GEInt    GetItemHeight( GEInt ) const;
        GEInt    GetItemRect( GEInt, bCRect & ) const;
        GEInt    GetSel( GEInt ) const;
        GEInt    GetSelCount( void ) const;
        void     GetText( GEInt, bCUnicodeString & ) const;
        GEInt    GetTextLen( GEInt ) const;
        GEInt    GetTopIndex( void ) const;
        GEInt    InsertString( GEInt, bCUnicodeString const & );
        GEInt    ItemFromPoint( bCPoint ) const;
        void     ResetContent( void );
        GEInt    SelItemRange( GEBool, GEInt, GEInt );
        GEInt    SelectString( bCUnicodeString const & );
        GEInt    SetAnchorIndex( GEInt );
        GEInt    SetCaretIndex( GEInt );
        GEInt    SetCurSel( GEInt );
        GEInt    SetItemData( GEInt, GEU32 );
        GEInt    SetItemDataPtr( GEInt, GELPVoid );
        GEInt    SetItemHeight( GEInt, GEInt );
        GEInt    SetSel( GEInt, GEBool );
        GEInt    SetTopIndex( GEInt );

};

#endif
