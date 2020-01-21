#ifndef GE_GFXINDEXDATA_H_INCLUDED
#define GE_GFXINDEXDATA_H_INCLUDED

class GE_DLLIMPORT eCGfxIndexData :
    public bCObjectRefBase
{
    public: using bCObjectBase::CopyFrom;
    public:    virtual bEResult CopyFrom( eCGfxIndexData const & );
    public: using bCObjectBase::Write;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    public:    virtual void     Destroy( void );
    public:    virtual bEResult Create( void );
    protected: virtual         ~eCGfxIndexData( void );

    public:
        eCGfxIndexData( eCGfxIndexData const & );
        eCGfxIndexData( void );

    public:
        eCGfxIndexData & operator = ( eCGfxIndexData const & );

    public:
        bEResult Create( eCGfxShared::eSGfxIndexBufDesc const & );
        bEResult GetBufferDescription( eCGfxShared::eSGfxIndexBufDesc & ) const;
        void     Invalidate( void );
        bEResult LockBuffer( GEUInt, GEUInt, GEU32, GELPByte * );
        bEResult UnlockBuffer( void );

    protected:
        bEResult CreateBuffer( eCGfxShared::eSGfxIndexBufDesc const & );
        bEResult DestroyBuffer( void );
        bEResult GetIndexData( eCAPIIndexData * & );
        bEResult SetIndexData( eCAPIIndexData * );

};

#endif
