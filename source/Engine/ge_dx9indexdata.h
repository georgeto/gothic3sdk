#ifndef GE_DX9INDEXDATA_H_INCLUDED
#define GE_DX9INDEXDATA_H_INCLUDED

class GE_DLLIMPORT eCDX9IndexData :
    public eCAPIIndexData
{
    public: virtual bEResult LockBuffer( GEUInt, GEUInt, GEU32, GELPByte * );
    public: virtual bEResult UnlockBuffer( void );
    public: virtual bEResult GetDesc( eCGfxShared::eSGfxIndexBufDesc * );
    public: virtual         ~eCDX9IndexData( void );

    public:
        eCDX9IndexData( eCDX9IndexData const & );

    public:
        eCDX9IndexData & operator = ( eCDX9IndexData const & );

    protected:
        static void ( GE_STDCALL * ms_pRegIndexBufferLock )( void );
        static void GE_STDCALL sSetIndexBufferLockCallback( void ( GE_STDCALL* )( void ) );

    protected:
        eCDX9IndexData( eCGfxShared::eSGfxIndexBufDesc const &, IDirect3DDevice9 *, GEBool & );
        eCDX9IndexData( ID3DXMesh * const, IDirect3DDevice9 * );

};

#endif
