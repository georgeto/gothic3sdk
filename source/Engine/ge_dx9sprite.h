#ifndef GE_DX9SPRITE_H_INCLUDED
#define GE_DX9SPRITE_H_INCLUDED

class GE_DLLIMPORT eCDX9Sprite :
    public eCAPISprite
{
    public: virtual bEResult Begin( GEU32 );
    public: virtual bEResult Draw( eCAPITexture *, bCRect const *, bCVector const *, bCVector const *, GEU32 );
    public: virtual bEResult DrawTextA( eCAPIFont *, GELPCChar, GEInt, bCRect *, GEU32, GEU32 );
    public: virtual bEResult DrawTextA( eCAPIFont *, GELPCUnicodeChar, GEInt, bCRect *, GEU32, GEU32 );
    public: virtual bEResult Flush( void );
    public: virtual bEResult End( void );
    public: virtual bEResult GetTransform( bCMatrix * );
    public: virtual bEResult SetTransform( bCMatrix const * );
    public: virtual bEResult SetWorldViewLH( bCMatrix const *, bCMatrix const * );
    public: virtual bEResult SetWorldViewRH( bCMatrix const *, bCMatrix const * );
    public: virtual         ~eCDX9Sprite( void );

    protected:
        static GEBool ms_bOptimize;

    public:
        eCDX9Sprite( eCDX9Sprite const & );

    public:
        eCDX9Sprite & operator = ( eCDX9Sprite const & );

    protected:
        static void GE_STDCALL sDisableOptimization( void );
        static void GE_STDCALL sEnableOptimization( void );

    protected:
                 eCDX9Sprite( eCGfxShared::eSSpriteDesc &, IDirect3DDevice9 *, eCDX9Device *, GEBool & );
        bEResult OnLostDevice( void );
        bEResult OnResetDevice( void );

};

#endif
