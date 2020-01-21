#ifndef GE_APIINSTANCE_H_INCLUDED
#define GE_APIINSTANCE_H_INCLUDED

class GE_DLLIMPORT eCAPIInstance
{
    public: virtual bEResult Init( eCGfxShared::eEAPIType ) = 0;
    public: virtual bEResult Finit( void ) = 0;
    public: virtual bEResult GetAdapterCount( GEU32 * ) = 0;
    public: virtual bEResult GetModeCount( GEU32, GEU32 * ) = 0;
    public: virtual bEResult GetAdapterDisplayMode( GEU32, struct eCGfxShared::eSGfxModeDesc * ) = 0;
    public: virtual bEResult GetAdapterDesc( GEU32, struct eCGfxShared::eSGfxAdapterDesc * ) = 0;
    public: virtual bEResult GetModeDesc( GEU32, GEU32, struct eCGfxShared::eSGfxModeDesc * ) = 0;
    public: virtual bEResult CreateDevice( GEU32, struct eCAPIDevice::eSAPIStartParameters const &, eCAPIDevice * * ) = 0;
    public: virtual         ~eCAPIInstance( void );

    public:
        eCAPIInstance( eCAPIInstance const & );

    public:
        eCAPIInstance & operator = ( eCAPIInstance const & );

    public:
        GEU32 AddRef( void );
        GEU32 Release( void );

    protected:
        eCAPIInstance( void );

    private:
        GEU32 m_u32ReferenceCount;
};

#endif
