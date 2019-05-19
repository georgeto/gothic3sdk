#ifndef GE_FONT_H_INCLUDED
#define GE_FONT_H_INCLUDED

class GE_DLLIMPORT eCFont :
    public bCObjectRefBase
{
    protected: virtual bCUnicodeString &        AccessUnicodeText( void );
    protected: virtual bCByteAlphaColor &       AccessTextColor( void );
    protected: virtual bCByteAlphaColor &       AccessBackgroundColor( void );
    protected: virtual bCRect &                 AccessClipRect( void );
    public:    virtual bCString                 GetAnsiText( void ) const;
    public:    virtual bCUnicodeString const &  GetUnicodeText( void ) const;
    public:    virtual bCRect const &           GetClipRect( void ) const;
    public:    virtual void                     GetClipRect( bCRect & ) const;
    public:    virtual bCByteAlphaColor const & GetTextColor( void ) const;
    public:    virtual void                     GetTextColor( bCByteAlphaColor & ) const;
    public:    virtual bCByteAlphaColor const & GetBackgroundColor( void ) const;
    public:    virtual void                     GetBackgroundColor( bCByteAlphaColor & ) const;
    public:    virtual void                     GetText( bCString & ) const;
    public:    virtual void                     GetText( bCUnicodeString & ) const;
    public:    virtual void                     SetText( bCString const & );
    public:    virtual void                     SetText( bCUnicodeString const & );
    public:    virtual void                     SetClipRect( bCRect const & );
    public:    virtual void                     SetTextColor( bCByteAlphaColor const & );
    public:    virtual void                     SetBackgroundColor( bCByteAlphaColor const & );
    public:    virtual void                     AddTextToRenderList( void );
    public:    virtual GEInt                    GetLetterHeight( void ) const = 0;
    public:    virtual GEInt                    GetLetterWidth( GEChar ) const = 0;
    public:    virtual GEInt                    GetLetterWidth( GEUnicodeChar ) const;
    public:    virtual GEInt                    GetTextWidth( bCString const & ) const = 0;
    public:    virtual GEInt                    GetTextWidth( bCUnicodeString const & ) const;
    public:    virtual void                     Process( void );
    public:    virtual void                     Render( void );
    public: using bCObjectBase::Write;
    public:    virtual bEResult                 Write( bCOStream & );
    public:    virtual bEResult                 Read( bCIStream & );
    protected: virtual void                     Destroy( void );
    protected: virtual bEResult                 Create( void );
    public:    virtual                         ~eCFont( void );
    public: using bCObjectBase::CopyFrom;

    public:
        eCFont( eCFont const & );
        eCFont( void );

    public:
        eCFont &    operator =  ( eCFont const & );
        bCOStream & operator >> ( bCOStream & );
        bCIStream & operator << ( bCIStream & );

    public:
        void CopyFrom( eCFont const & );
        void CopyTo( eCFont & ) const;

    protected:
        void Invalidate( void );

    private:
        bCUnicodeString  m_Text;
        bCRect           m_ClipRect;
        bCByteAlphaColor m_TextColor;
        bCByteAlphaColor m_BackgroundColor;

};

GE_ASSERT_SIZEOF( eCFont, 0x38 );

#endif
