#ifndef GE_SYSTEMFONT_H_INCLUDED
#define GE_SYSTEMFONT_H_INCLUDED

class eCSystemFont :
    public eCFont
{
    public: using bCObjectBase::Write;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    protected: virtual void     Destroy( void );
    protected: virtual bEResult Create( void );
    public:    virtual         ~eCSystemFont( void );
    public:    virtual void     SetText( bCString const & );
    public:    virtual void     SetText( bCUnicodeString const & );
    public:    virtual void     SetClipRect( bCRect const & );
    public:    virtual void     SetTextColor( bCByteAlphaColor const & );
    public:    virtual void     SetBackgroundColor( bCByteAlphaColor const & );
    public:    virtual void     AddTextToRenderList( void );
    public:    virtual GEInt    GetLetterHeight( void ) const;
    public:    virtual GEInt    GetLetterWidth( GEChar ) const;
    public:    virtual GEInt    GetLetterWidth( GEUnicodeChar ) const;
    public:    virtual GEInt    GetTextWidth( bCString const & ) const;
    public:    virtual GEInt    GetTextWidth( bCUnicodeString const & ) const;
    public:    virtual void     Render( void );
    public: using bCObjectBase::CopyFrom;

    public:
        eCSystemFont( eCSystemFont const & );
        eCSystemFont( void );

    public:
        eCSystemFont & operator =  ( eCSystemFont const & );
        bCOStream &    operator >> ( bCOStream & );
        bCIStream &    operator << ( bCIStream & );

    public:
        void                            CopyFrom( eCSystemFont const & );
        void                            CopyTo( eCSystemFont & ) const;
        eCGfxShared::eSFontDesc const & GetDescriptor( void ) const;
        void                            SetDescriptor( eCGfxShared::eSFontDesc const & );

    protected:
        eCGfxShared::eSFontDesc & AccessDescriptor( void );
        eCGfxFont &               AccessFont( void );
        GEBool                    CacheIn( void );
        void                      DrawLetters( void );
        void                      Invalidate( void );
        void                      Update( void );

    private:
        GEBool GetLetterData( GEUInt, GEInt &, GEInt &, bCVector &, bCVector &, bCVector2 &, eCGfxImageData * & );
        GEInt  GetLetterDistance( void ) const;

    private:
        eCGfxFont *m_SubsystemFont;
        eCGfxShared::eSFontDesc m_FontDesc;
        GE_PADDING(56);
        GEU32 field_A4;
        GEU32 field_A8;
        GEU32 field_AC;
        GEU32 field_B0;
        GEU32 field_B4;
        GEU32 m_LetterHeight;
        GEU32 m_LetterWidth;
        GEByte m_Flags;
        GE_PADDING( 3 )
};

GE_ASSERT_SIZEOF( eCSystemFont, 0xBC );

#endif
