#ifndef GE_GUIRENDERER_H_INCLUDED
#define GE_GUIRENDERER_H_INCLUDED

class GE_DLLIMPORT eCGUIRenderer :
    public eCGUISubAdmin
{
    public: virtual GEBool DrawRect( bCRect const *, GEU32 );
    public: virtual GEBool DrawSprite( GEU32, bCRect const *, bCVector const *, bCVector const *, bCMatrix const *, GEU32 );
    public: virtual GEInt  CalcTextRect( GEU32, GELPCUnicodeChar, GEInt, bCRect *, GEU32 );
    public: virtual GEInt  CalcTextRect( GEU32, GELPCChar, GEInt, bCRect *, GEU32 );
    public: virtual GEBool DrawTextA( GEU32, GELPCUnicodeChar, GEInt, bCRect *, GEU32, GEU32 );
    public: virtual GEBool DrawTextA( GEU32, GELPCChar, GEInt, bCRect *, GEU32, GEU32 );
    public: virtual GEBool BeginFrame( GEBool );
    public: virtual GEBool EndFrame( GEBool );
    public: virtual GEBool SetClipRect( bCRect const * );
    public: virtual GEBool SetTransform( bCMatrix const * );
    public: virtual GEBool GetDrawScale( bCVector & ) const;
    public: virtual GEBool SetDrawScale( bCVector const & );
    public: virtual       ~eCGUIRenderer( void );

    public:
        eCGUIRenderer( eCGUIRenderer const & );
        eCGUIRenderer( eCGUIAdmin * );

    public:
        eCGUIRenderer & operator = ( eCGUIRenderer const & );

    public:
        GEBool Create( GEU32 );
        void   Destroy( void );

    protected:
        void ApplyStates( void );
        void Invalidate( void );
        void PopStates( void );
        void PushStates( void );

    public:
        GE_PADDING( 0x5C )
};

GE_ASSERT_SIZEOF( eCGUIRenderer, 0x60 )

#endif
