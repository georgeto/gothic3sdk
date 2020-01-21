#ifndef GE_DX9VERTEXDATA_H_INCLUDED
#define GE_DX9VERTEXDATA_H_INCLUDED

struct ID3DXMesh;
class IDirect3DDevice9;

class GE_DLLIMPORT eCDX9VertexData :
    public eCAPIVertexData
{
    public: virtual bEResult LockBuffer( GEUInt, GEUInt, GEU32, GELPByte * );
    public: virtual bEResult UnlockBuffer( void );
    public: virtual bEResult GetDesc( eCGfxShared::eSGfxVertexBufDesc * );
    public: virtual bEResult SetStride( GEU32 );
    public: virtual         ~eCDX9VertexData( void );

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

    public:
        eCDX9VertexData( eCDX9VertexData const & );

    public:
        eCDX9VertexData & operator = ( eCDX9VertexData const & );

    protected:
        static void ( GE_STDCALL * ms_pRegVertexBufferLock )( void );
        static void GE_STDCALL sSetVertexBufferLockCallback( void ( GE_STDCALL* )( void ) );

    protected:
        eCDX9VertexData( eCGfxShared::eSGfxVertexBufDesc const &, IDirect3DDevice9 *, GEBool & );
        eCDX9VertexData( ID3DXMesh * const, IDirect3DDevice9 * );

};

#endif
