#ifndef GFC_SCROLLBAR_H_INCLUDED
#define GFC_SCROLLBAR_H_INCLUDED

struct SFFGUIScrollBarInfo;
struct SFFGUIScrollInfo
{
    GEUInt fMask;
    GEInt  nMin;
    GEInt  nMax;
    GEUInt nPage;
    GEInt  nPos;
    GEInt  nTrackPos;
};


class GE_DLLIMPORT CFFGFCScrollBar :
    public CFFGFCWnd
{
    public: virtual ~CFFGFCScrollBar( void );

    public:
        CFFGFCScrollBar( CFFGFCScrollBar const & );
        CFFGFCScrollBar( void );

    public:
        CFFGFCScrollBar & operator = ( CFFGFCScrollBar const & );

    public:
        GEBool Create( bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );
        GEBool EnableScrollBar( GEU32 );
        GEBool GetScrollBarInfo( SFFGUIScrollBarInfo & ) const;
        GEBool GetScrollInfo( SFFGUIScrollInfo & ) const;
        GEInt  GetScrollLimit( void ) const;
        GEInt  GetScrollPos( void ) const;
        void   GetScrollRange( GEInt *, GEInt * ) const;
        void   SetScrollInfo( SFFGUIScrollInfo & );
        void   SetScrollPos( GEInt );
        void   SetScrollRange( GEInt, GEInt );
        void   ShowScrollBar( GEBool );

};

#endif
