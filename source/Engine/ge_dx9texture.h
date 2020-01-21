#ifndef GE_DX9TEXTURE_H_INCLUDED
#define GE_DX9TEXTURE_H_INCLUDED

class IDirect3DTexture9;

class GE_DLLIMPORT eCDX9Texture :
    public eCAPITexture
{
    public: virtual bEResult LockImageLayer( GEUInt, GEU32, GEInt *, GELPVoid * );
    public: virtual bEResult UnlockImageLayer( GEUInt );
    public: virtual bEResult GetRenderTargetHandle( GELPVoid * );
    public: virtual bEResult SetTexture( GEU32 );
    public: virtual bEResult ComputeNormalMap( eCAPITexture *, eCGfxShared::eENormalMapGen, eCGfxShared::eEChannel, GEFloat );
    public: virtual bEResult ConvertFrom( eCAPITexture *, eCGfxShared::eECopyFilter, GEBool );
    public: virtual bEResult GenerateTextureMipMaps( GEUInt, eCGfxShared::eECopyFilter );
    public: virtual bEResult SaveTextureToFile( GELPChar const );
    public: virtual bEResult SaveTextureToMemory( bCMemoryStream & );
    public: virtual bEResult CopyCurrentRTToImage( eCGfxShared::eETexFilter, bCRect *, bCRect * );
    public: virtual bEResult CopyImageToCurrentRT( eCGfxShared::eETexFilter, bCRect *, bCRect * );
    public: virtual bEResult CopySurface( eCAPITexture * );
    public: virtual bEResult LoadSurfaceFromSurface( GEUInt, GELPCVoid, bCRect const *, eCAPITexture *, GEUInt, GELPCVoid, bCRect const *, GEU32, GEU32 );
    public: virtual bEResult GetRenderTargetData( eCAPITexture * );
    public: virtual         ~eCDX9Texture( void );

    public:
        static GEU32 s_u32CountManaged;
        static GEU32 s_u32CountMemManaged;
        static GEU32 s_u32CountMemNonManaged;
        static GEU32 s_u32CountNonManaged;
        static GEU32 s_u32ErrorCorrected;
        static GEU32 s_u32ErrorNotCorrected;
        static GEU32 s_u32PeekManaged;
        static GEU32 s_u32PeekMemManaged;
        static GEU32 s_u32PeekMemNonManaged;
        static GEU32 s_u32PeekNonManaged;

    protected:
        static GEBool ms_bForceLowestMipMapLevel;
        static GEBool ms_bOptimize;

    public:
        eCDX9Texture( eCDX9Texture const & );

    public:
        eCDX9Texture & operator = ( eCDX9Texture const & );

    protected:
        static GEFloat GE_STDCALL FormatSize( _D3DFORMAT );
        static void ( GE_STDCALL * ms_pRegTextureLock )( void );
        static void ( GE_STDCALL * ms_pRegTextureSwitch )( void );
        static void GE_STDCALL   sDisableOptimization( void );
        static void GE_STDCALL   sEnableOptimization( void );
        static void GE_STDCALL   sForceLowestMipMapLevel( GEBool );
        static GEBool GE_STDCALL sGetForceLowestMipMapLevel( void );
        static void GE_STDCALL   sSetTextureActCallback( void ( GE_STDCALL* )( void ) );
        static void GE_STDCALL   sSetTextureLockCallback( void ( GE_STDCALL* )( void ) );

    protected:
                 eCDX9Texture( eCGfxShared::eSGfxLayersDesc &, GELPVoid, GEUInt, IDirect3DDevice9 *, GEBool & );
                 eCDX9Texture( eCGfxShared::eSGfxLayersDesc &, GELPChar const, IDirect3DDevice9 *, GEBool & );
                 eCDX9Texture( eCGfxShared::eSGfxLayersDesc const &, IDirect3DDevice9 *, GEBool & );
                 eCDX9Texture( IDirect3DTexture9 *, IDirect3DDevice9 *, eCGfxShared::eSGfxLayersDesc & );
        bEResult GetTextureHandle( IDirect3DTexture9 * * );

    private:
        void  Count( void );
        GEU32 GetSize( void );

};

#endif
