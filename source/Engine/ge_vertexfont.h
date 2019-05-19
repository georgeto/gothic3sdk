#ifndef GE_VERTEXFONT_H_INCLUDED
#define GE_VERTEXFONT_H_INCLUDED

class GE_DLLIMPORT eCVertexFont :
    public eCFont
{
    public:    virtual eCFontResource * GetFontResource( void );
    public:    virtual GEBool           SetTexture( bCString const & );
    public:    virtual bCString const & GetTexture( void ) const;
    protected: virtual void             Update( void );
    public: using bCObjectBase::Write;
    public:    virtual bEResult         Write( bCOStream & );
    public:    virtual bEResult         Read( bCIStream & );
    protected: virtual void             Destroy( void );
    protected: virtual bEResult         Create( void );
    public:    virtual                 ~eCVertexFont( void );
    public:    virtual void             SetText( bCString const & );
    public:    virtual void             SetText( bCUnicodeString const & );
    public:    virtual void             SetClipRect( bCRect const & );
    public:    virtual void             SetTextColor( bCByteAlphaColor const & );
    public:    virtual void             SetBackgroundColor( bCByteAlphaColor const & );
    public:    virtual GEInt            GetLetterHeight( void ) const;
    public: using eCFont::GetLetterWidth;
    public:    virtual GEInt            GetLetterWidth( GEChar ) const;
    public:    virtual GEInt            GetTextWidth( bCString const & ) const;
    public:    virtual GEInt            GetTextWidth( bCUnicodeString const & ) const;
    public:    virtual void             Render( void );
    public: using bCObjectBase::CopyFrom;

    public:
        eCVertexFont( eCVertexFont const & );
        eCVertexFont( void );

    public:
        eCVertexFont & operator =  ( eCVertexFont const & );
        bCOStream &    operator >> ( bCOStream & );
        bCIStream &    operator << ( bCIStream & );

    public:
        void CopyFrom( eCVertexFont const & );
        void CopyTo( eCVertexFont & ) const;
        void DrawLetters( void );

    protected:
        GEBool CacheIn( void );
        void   Invalidate( void );

};

#endif
