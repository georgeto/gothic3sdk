#ifndef GE_APIVERTEXDATA_H_INCLUDED
#define GE_APIVERTEXDATA_H_INCLUDED

class GE_DLLIMPORT eCAPIVertexData
{
    public: virtual bEResult LockBuffer( GEUInt, GEUInt, GEU32, GELPByte * ) = 0;
    public: virtual bEResult UnlockBuffer( void ) = 0;
    public: virtual bEResult GetDesc( struct eCGfxShared::eSGfxVertexBufDesc * ) = 0;
    public: virtual bEResult SetStride( GEU32 ) = 0;
    public: virtual         ~eCAPIVertexData( void );

    public:
        eCAPIVertexData( eCAPIVertexData const & );

    public:
        eCAPIVertexData & operator = ( eCAPIVertexData const & );

    public:
        GEU32 AddRef( void );
        GEU32 Release( void );

    protected:
        eCAPIVertexData( void );

    private:
        GEU32 m_u32ReferenceCount;
};

#endif
