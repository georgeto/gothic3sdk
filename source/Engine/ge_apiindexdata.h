#ifndef GE_APIINDEXDATA_H_INCLUDED
#define GE_APIINDEXDATA_H_INCLUDED

class GE_DLLIMPORT eCAPIIndexData
{
    public: virtual bEResult LockBuffer( GEUInt, GEUInt, GEU32, GELPByte * ) = 0;
    public: virtual bEResult UnlockBuffer( void ) = 0;
    public: virtual bEResult GetDesc( struct eCGfxShared::eSGfxIndexBufDesc * ) = 0;
    public: virtual         ~eCAPIIndexData( void );

    public:
        eCAPIIndexData( eCAPIIndexData const & );

    public:
        eCAPIIndexData & operator = ( eCAPIIndexData const & );

    public:
        GEU32 AddRef( void );
        GEU32 Release( void );

    protected:
        eCAPIIndexData( void );

    private:
        GEU32 m_u32ReferenceCount;
};

#endif
