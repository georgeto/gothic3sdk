#ifndef GE_GFXFONT_H_INCLUDED
#define GE_GFXFONT_H_INCLUDED

struct eCAPIDevice;

class GE_DLLIMPORT eCGfxFont :
    public bCObjectRefBase
{
    public:    virtual bEResult Create( eCGfxShared::eSFontDesc const & );
    public: using bCObjectBase::CopyFrom;
    public:    virtual bEResult CopyFrom( eCGfxFont const & );
    public: using bCObjectBase::Write;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    public:    virtual void     Destroy( void );
    public:    virtual bEResult Create( void );
    protected: virtual         ~eCGfxFont( void );

    protected:
        static GEBool      ms_bOptimize;
        static GEBool      ms_bReset;
        static eCGfxFont * ms_pActiveFont;
        static eCGfxFont * ms_pMasterFont;

    public:
        eCGfxFont( eCGfxFont const & );
        eCGfxFont( void );

    public:
        eCGfxFont & operator = ( eCGfxFont const & );

    public:
        bEResult Execute( void );
        bEResult GetDeviceContext( HDC__ * & );
        bEResult GetFontDescription( eCGfxShared::eSFontDesc & ) const;
        bEResult GetGlyphData( GEUInt, bCRect &, bCVector2 &, eCGfxImageData * & );
        bEResult GetTextIndices( bCString const &, GEU16 * &, GEU16 & );
        bEResult GetTextIndices( bCUnicodeString const &, GEU16 * &, GEU16 & );
        void     Invalidate( void );
        bEResult SetText( bCUnicodeString, bCRect const *, GEU32, GEU32 );

    protected:
        static void ( GE_STDCALL* ms_pRegisterFontExecuteCall )( void );
        static void GE_STDCALL        sDisableOptimization( void );
        static void GE_STDCALL        sEnableOptimization( void );
        static eCGfxFont * GE_STDCALL sGetActiveFont( void );
        static eCGfxFont * GE_STDCALL sGetMasterFont( void );
        static void GE_STDCALL        sResetCachedStates( void );
        static void GE_STDCALL        sSetFontExecuteCallback( void ( GE_STDCALL* )( void ));
        static void GE_STDCALL        sSetMasterFont( eCGfxFont * );

    protected:
        bEResult    CreateFontA( eCGfxShared::eSFontDesc const & );
        bEResult    DestroyFont( void );
        eCAPIFont * GetHandle( void ) const;

    private:
        eCAPIDevice *           m_pAPIDevice;
        eCGfxShared::eSFontDesc m_FontDest;
        eCAPIFont *             m_pAPIFont;
        bCUnicodeString         m_strText;
        bCRect                  m_TextRect;
        GEBool                  m_bHasTextRect;
        GE_PADDING( 3 )
        GEUInt m_SetTextParam4;
        GEUInt m_SetTextParam5;
        GEBool m_bUnk1;
        GE_PADDING( 3 )
        bTAutoPtrArray<GELPVoid> m_arrGlyphData;
};

GE_ASSERT_SIZEOF( eCGfxFont, 0x6C )

#endif
