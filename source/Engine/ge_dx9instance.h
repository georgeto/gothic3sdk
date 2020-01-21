#ifndef GE_DX9INSTANCE_H_INCLUDED
#define GE_DX9INSTANCE_H_INCLUDED

class eCDX9Instantiator;

// No GE_DLLIMPORT on eCDX9Instance, because otherwise eCDX9Instantiator::CreateInstance uses a 'local vftable'.
class eCDX9Instance :
    public eCAPIInstance
{
    public: virtual bEResult Init( eCGfxShared::eEAPIType );
    public: virtual bEResult Finit( void );
    public: virtual bEResult GetAdapterCount( GEU32 * );
    public: virtual bEResult GetModeCount( GEU32, GEU32 * );
    public: virtual bEResult GetAdapterDisplayMode( GEU32, eCGfxShared::eSGfxModeDesc * );
    public: virtual bEResult GetAdapterDesc( GEU32, eCGfxShared::eSGfxAdapterDesc * );
    public: virtual bEResult GetModeDesc( GEU32, GEU32, eCGfxShared::eSGfxModeDesc * );
    public: virtual bEResult CreateDevice( GEU32, eCAPIDevice::eSAPIStartParameters const &, eCAPIDevice * * );
    public: virtual         ~eCDX9Instance( void );

    public:
        eCDX9Instance( eCDX9Instance const & );

    public:
        eCDX9Instance & operator = ( eCDX9Instance const & );

    protected:
        friend eCDX9Instantiator;
        eCDX9Instance( eCAPIInstance * * );

    private:
        eCGfxShared::eEAPIType m_apiType;
};

GE_ASSERT_SIZEOF( eCDX9Instance, 0x0c )

class eCDX9Instantiator
{
    public:
        static eCDX9Instance * CreateInstance( eCAPIInstance ** a_ppInstance );
};

#endif
