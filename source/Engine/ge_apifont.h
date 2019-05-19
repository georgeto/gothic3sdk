#ifndef GE_APIFONT_H_INCLUDED
#define GE_APIFONT_H_INCLUDED

class eCAPITexture;

class GE_DLLIMPORT eCAPIFont
{
    public: virtual bEResult GetGlyphData( GEUInt, bCRect &, bCVector2 &, eCAPITexture * &, struct eCGfxShared::eSGfxLayersDesc & ) = 0;
    public: virtual bEResult GetTextIndices( bCUnicodeString const &, GEU16 * &, GEU16 & ) = 0;
    public: virtual bEResult GetTextIndices( bCString const &, GEU16 * &, GEU16 & )        = 0;
    public: virtual bEResult GetDeviceContext( struct HDC__ * & )                          = 0;
    public: virtual bEResult DrawTextA( bCUnicodeString, bCRect *, GEU32, GEU32 ) = 0;
    public: virtual         ~eCAPIFont( void );

    public:
        eCAPIFont( eCAPIFont const & );

    public:
        eCAPIFont & operator = ( eCAPIFont const & );

    public:
        GEU32 AddRef( void );
        GEU32 Release( void );

    protected:
        eCAPIFont( void );

};

#endif
