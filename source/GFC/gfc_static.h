#ifndef GFC_STATIC_H_INCLUDED
#define GFC_STATIC_H_INCLUDED

class GE_DLLIMPORT CFFGFCStatic :
    public CFFGFCWnd
{
    public: virtual ~CFFGFCStatic( void );

    public:
        CFFGFCStatic( CFFGFCStatic const & );
        CFFGFCStatic( void );

    public:
        CFFGFCStatic & operator = ( CFFGFCStatic const & );

    public:
        GEBool         Create( bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );
        IFFGUIBitmap * GetBitmap( void ) const;
        IFFGUIBitmap * SetBitmap( IFFGUIBitmap * );

};

#endif
