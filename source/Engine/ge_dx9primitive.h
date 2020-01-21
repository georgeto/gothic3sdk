#ifndef GE_DX9PRIMITIVE_H_INCLUDED
#define GE_DX9PRIMITIVE_H_INCLUDED

class GE_DLLIMPORT eCDX9Primitive :
    public eCAPIPrimitive
{
    public: virtual GEBool                                 SetStream( GEU32, eCAPIVertexData * );
    public: virtual GEBool                                 SetIndexData( eCAPIIndexData * );
    public: virtual GEBool                                 SetVertexDecl( GELPVoid );
    public: virtual GEBool                                 SetFVF( GEU32 );
    public: virtual GEBool                                 SetStreamSrcFrequency( GEU32, GEU32 );
    public: virtual GEU32                                  GetStreamSrcFrequency( GEU32 ) const;
    public: virtual GEBool                                 SetStreamOffset( GEU32, GEU32 );
    public: virtual GEU32                                  GetStreamOffset( GEU32 ) const;
    public: virtual GEBool                                 SetStreamStride( GEU32, GEU32 );
    public: virtual GEU32                                  GetStreamStride( GEU32 ) const;
    public: virtual GEBool                                 SetDrawCallDescription( eCGfxShared::eSGfxDrawCallDesc const & );
    public: virtual eCGfxShared::eSGfxDrawCallDesc const & GetDrawCallDescription( void ) const;
    public: virtual eCGfxShared::eSGfxDrawCallDesc &       GetDrawCallDescription( void );
    public: virtual void                                   EnableStream( GEU32, GEBool );
    public: virtual GEBool                                 IsStreamEnabled( GEU32 ) const;
    public: virtual GEBool                                 Execute( void );
    public: virtual                                       ~eCDX9Primitive( void );

    public:
        eCDX9Primitive( eCDX9Primitive const & );

    public:
        eCDX9Primitive & operator = ( eCDX9Primitive const & );

    public:
        eCDX9Primitive( IDirect3DDevice9 *, eCDX9Device * );

};

#endif
