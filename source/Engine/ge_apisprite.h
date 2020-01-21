#ifndef GE_APISPRITE_H_INCLUDED
#define GE_APISPRITE_H_INCLUDED

class GE_DLLIMPORT eCAPISprite
{
    public: virtual bEResult Begin( GEU32 ) = 0;
    public: virtual bEResult Draw( eCAPITexture *, bCRect const *, bCVector const *, bCVector const *, GEU32 ) = 0;
    public: virtual bEResult DrawTextA( eCAPIFont *, GELPCChar, GEInt, bCRect *, GEU32, GEU32 ) = 0;
    public: virtual bEResult DrawTextA( eCAPIFont *, GELPCUnicodeChar, GEInt, bCRect *, GEU32, GEU32 ) = 0;
    public: virtual bEResult Flush( void ) = 0;
    public: virtual bEResult End( void ) = 0;
    public: virtual bEResult GetTransform( bCMatrix * ) = 0;
    public: virtual bEResult SetTransform( bCMatrix const * ) = 0;
    public: virtual bEResult SetWorldViewLH( bCMatrix const *, bCMatrix const * ) = 0;
    public: virtual bEResult SetWorldViewRH( bCMatrix const *, bCMatrix const * ) = 0;
    public: virtual         ~eCAPISprite( void );

    public:
        eCAPISprite( eCAPISprite const & );

    public:
        eCAPISprite & operator = ( eCAPISprite const & );

    public:
        GEU32 AddRef( void );
        GEU32 Release( void );

    protected:
        eCAPISprite( void );

    private:
        GEU32 m_u32ReferenceCount;
};

#endif
