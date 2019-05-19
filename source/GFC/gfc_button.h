#ifndef GFC_BUTTON_H_INCLUDED
#define GFC_BUTTON_H_INCLUDED

class GE_DLLIMPORT CFFGFCButton :
    public virtual CFFGFCWnd
{
    public: virtual ~CFFGFCButton( void );

    public:
        CFFGFCButton( CFFGFCButton const & );
        CFFGFCButton( void );

    public:
        CFFGFCButton & operator = ( CFFGFCButton const & );

    public:
        GEBool         Create( bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32 );
        IFFGUIBitmap * GetBitmap( void ) const;
        GEU32          GetState( void ) const;
        IFFGUIBitmap * SetBitmap( IFFGUIBitmap * );

};

GE_ASSERT_SIZEOF(CFFGFCButton, 0x14)

#endif
