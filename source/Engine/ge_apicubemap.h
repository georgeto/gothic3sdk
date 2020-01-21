#ifndef GE_APICUBEMAP_H_INCLUDED
#define GE_APICUBEMAP_H_INCLUDED

class GE_DLLIMPORT eCAPICubeMap
{
    public: virtual bEResult LockCubeMapLayer( GEUInt, eCGfxShared::eECubeMapFace, GEU32, GEInt *, GELPVoid * ) = 0;
    public: virtual bEResult UnlockCubeMapLayer( eCGfxShared::eECubeMapFace, GEUInt ) = 0;
    public: virtual bEResult GetRenderTargetHandle( eCGfxShared::eECubeMapFace, GELPVoid * ) = 0;
    public: virtual bEResult SetCubeMap( GEU32 ) = 0;
    public: virtual bEResult GenerateCubeMapMipMaps( GEUInt, eCGfxShared::eECopyFilter ) = 0;
    public: virtual bEResult GetRenderTargetData( eCGfxShared::eECubeMapFace, eCAPITexture * ) = 0;
    public: virtual bEResult SaveTextureToFile( GELPChar const ) = 0;
    public: virtual bEResult SaveTextureToMemory( bCMemoryStream & ) = 0;
    public: virtual         ~eCAPICubeMap( void );

    public:
        eCAPICubeMap( eCAPICubeMap const & );

    public:
        eCAPICubeMap & operator = ( eCAPICubeMap const & );

    public:
        GEU32 AddRef( void );
        GEU32 Release( void );

    protected:
        eCAPICubeMap( void );

    private:
        GEU32 m_u32ReferenceCount;
};

#endif
