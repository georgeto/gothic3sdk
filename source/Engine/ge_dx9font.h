#ifndef GE_DX9FONT_H_INCLUDED
#define GE_DX9FONT_H_INCLUDED

class IDirect3DDevice9;
class eCDX9Device;
class ID3DXFont;

class GE_DLLIMPORT eCDX9Font :
    public eCAPIFont
{
    public: virtual bEResult GetGlyphData( GEUInt, bCRect &, bCVector2 &, eCAPITexture * &, eCGfxShared::eSGfxLayersDesc & );
    public: virtual bEResult GetTextIndices( bCUnicodeString const &, GEU16 * &, GEU16 & );
    public: virtual bEResult GetTextIndices( bCString const &, GEU16 * &, GEU16 & );
    public: virtual bEResult GetDeviceContext( HDC__ * & );
    public: virtual bEResult DrawTextA( bCUnicodeString, bCRect *, GEU32, GEU32 );
    public: virtual         ~eCDX9Font( void );

    protected:
        static GEBool ms_bOptimize;

    public:
        eCDX9Font( eCDX9Font const & );

    public:
        eCDX9Font & operator = ( eCDX9Font const & );

    protected:
        static void GE_STDCALL sDisableOptimization( void );
        static void GE_STDCALL sEnableOptimization( void );

    protected:
                    eCDX9Font( eCGfxShared::eSFontDesc &, IDirect3DDevice9 *, eCDX9Device *, GEBool & );
        ID3DXFont * GetHandle( void ) const;
        bEResult    OnLostDevice( void );
        bEResult    OnResetDevice( void );

};

#endif
