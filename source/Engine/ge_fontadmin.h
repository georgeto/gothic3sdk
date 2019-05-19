#ifndef GE_FONTADMIN_H_INCLUDED
#define GE_FONTADMIN_H_INCLUDED

class eCFontResource;

class GE_DLLIMPORT eCFontAdmin :
    public bCObjectRefBase
{
    public: using bCObjectBase::Write;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    protected: virtual void     Destroy( void );
    protected: virtual bEResult Create( void );
    public:    virtual         ~eCFontAdmin( void );
    public: using bCObjectBase::CopyFrom;

    public:
        static eCFontAdmin & GE_STDCALL GetInstance( void );

    public:
        eCFontAdmin( eCFontAdmin const & );
        eCFontAdmin( void );

    public:
        eCFontAdmin & operator =  ( eCFontAdmin const & );
        bCOStream &   operator >> ( bCOStream & );
        bCIStream &   operator << ( bCIStream & );

    public:
        void             CopyFrom( eCFontAdmin const & );
        void             CopyTo( eCFontAdmin & ) const;
        eCFontResource * CreateFontResource( bCString const & );
        eCGfxFont *      CreateSubsystemFont( eCGfxShared::eSFontDesc );
        void             ReleaseSubsystemFont( eCGfxFont * );

    protected:
        void Invalidate( void );

};

#endif
