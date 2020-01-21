#ifndef GE_DX9CUBEMAP_H_INCLUDED
#define GE_DX9CUBEMAP_H_INCLUDED

class GE_DLLIMPORT eCDX9CubeMap :
    public eCAPICubeMap
{
    public: virtual bEResult LockCubeMapLayer( GEUInt, eCGfxShared::eECubeMapFace, GEU32, GEInt *, GELPVoid * );
    public: virtual bEResult UnlockCubeMapLayer( eCGfxShared::eECubeMapFace, GEUInt );
    public: virtual bEResult GetRenderTargetHandle( eCGfxShared::eECubeMapFace, GELPVoid * );
    public: virtual bEResult SetCubeMap( GEU32 );
    public: virtual bEResult GenerateCubeMapMipMaps( GEUInt, eCGfxShared::eECopyFilter );
    public: virtual bEResult GetRenderTargetData( eCGfxShared::eECubeMapFace, eCAPITexture * );
    public: virtual bEResult SaveTextureToFile( GELPChar const );
    public: virtual bEResult SaveTextureToMemory( bCMemoryStream & );
    public: virtual         ~eCDX9CubeMap( void );

    protected:
        static GEBool ms_bOptimize;

    public:
        eCDX9CubeMap( eCDX9CubeMap const & );

    public:
        eCDX9CubeMap & operator = ( eCDX9CubeMap const & );

    protected:
        static void ( GE_STDCALL * ms_pRegCubemapLock )( void );
        static void ( GE_STDCALL * ms_pRegCubemapSwitch )( void );
        static void GE_STDCALL sDisableOptimization( void );
        static void GE_STDCALL sEnableOptimization( void );
        static void GE_STDCALL sSetCubemapActCallback( void ( GE_STDCALL* )( void ) );
        static void GE_STDCALL sSetCubemapLockCallback( void ( GE_STDCALL* )( void ) );

    protected:
        eCDX9CubeMap( eCGfxShared::eSGfxLayersDesc &, GELPVoid, GEUInt, IDirect3DDevice9 *, GEBool & );
        eCDX9CubeMap( eCGfxShared::eSGfxLayersDesc &, GELPChar const, IDirect3DDevice9 *, GEBool & );
        eCDX9CubeMap( eCGfxShared::eSGfxLayersDesc const &, IDirect3DDevice9 *, GEBool & );

    private:
        void  Count( void );
        GEU32 GetSize( void );

};

#endif
