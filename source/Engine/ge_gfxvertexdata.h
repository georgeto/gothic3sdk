#ifndef GE_GFXVERTEXDATA_H_INCLUDED
#define GE_GFXVERTEXDATA_H_INCLUDED

class GE_DLLIMPORT eCGfxVertexData :
    public bCObjectRefBase
{
    public: using bCObjectBase::CopyFrom;
    public:    virtual bEResult CopyFrom( eCGfxVertexData const & );
    public: using bCObjectBase::Write;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    public:    virtual void     Destroy( void );
    public:    virtual bEResult Create( void );
    protected: virtual         ~eCGfxVertexData( void );

    public:
        eCGfxVertexData( eCGfxVertexData const & );
        eCGfxVertexData( void );

    public:
        eCGfxVertexData & operator = ( eCGfxVertexData const & );

    public:
        bEResult Create( eCGfxShared::eSGfxVertexBufDesc const & );
        bEResult GetBufferDescription( eCGfxShared::eSGfxVertexBufDesc & ) const;
        void     Invalidate( void );
        bEResult LockBuffer( GEUInt, GEUInt, GEU32, GELPByte * );
        bEResult UnlockBuffer( void );

    protected:
        bEResult CreateBuffer( eCGfxShared::eSGfxVertexBufDesc const & );
        bEResult DestroyBuffer( void );
        bEResult GetVertexData( eCAPIVertexData * & );
        bEResult SetVertexData( eCAPIVertexData * );

};

#endif
