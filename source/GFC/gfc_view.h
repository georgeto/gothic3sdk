#ifndef GFC_VIEW_H_INCLUDED
#define GFC_VIEW_H_INCLUDED

class GE_DLLIMPORT CFFGFCView :
    public CFFGFCWnd
{
    public:    virtual GEBool OnInitDialog( void );
    protected: virtual GEInt  WindowProc( GEUInt, GEUInt, GEUInt );
    public:    virtual       ~CFFGFCView( void );

    public:
        CFFGFCView( CFFGFCView const & );
        CFFGFCView( void );

    public:
        CFFGFCView & operator = ( CFFGFCView const & );

    public:
               CFFGFCView( GEInt, CFFGFCWnd * );
               CFFGFCView( GELPCChar, CFFGFCWnd * );
        using CFFGFCWnd::Create;
        GEBool Create( bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );

};

#endif
