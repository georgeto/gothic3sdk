#ifndef GE_GUIENTITYRENDERER_H_INCLUDED
#define GE_GUIENTITYRENDERER_H_INCLUDED

class GE_DLLIMPORT gCGUIEntityRenderer
{
    public:
        enum EMode {};
        enum EAttitude;

        struct SFocusName
        {
            eCEntity * pEntity;
            GEFloat    fAlpha;
        };

    public: virtual ~gCGUIEntityRenderer( void );

    public:
        gCGUIEntityRenderer( gCGUIEntityRenderer const & );
        gCGUIEntityRenderer( eCGUIAdmin * );

    public:
        gCGUIEntityRenderer & operator = ( gCGUIEntityRenderer const & );

    public:
        GEBool AddFocusName( eCEntity const *, GEFloat );
        GEBool BeginFrame( GEBool );
        GEBool Create( void );
        void   Destroy( void );
        GEBool DrawFocusNames( void );
        GEBool EndFrame( GEBool );
        EMode  GetMode( void ) const;
        void   SetMode( EMode );

    protected:
        GEBool    CalcTextRect( eCEntity const *, bCUnicodeString const &, bCRect &, GEFloat & );
        GEBool    DrawFocusName( eCEntity const *, GEFloat );
        EAttitude GetAttitude( eCEntity const * ) const;
        void      Invalidate( void );
        GEBool    IsDead( eCEntity const * ) const;
        GEBool    IsFocus( eCEntity const * ) const;

    public:
        eCGUIRenderer          m_Renderer;
        bTObjArray<SFocusName> m_arrFocusNames;
        GEU32                  m_FontIndex;
        EMode                  m_RenderMode;
};

GE_ASSERT_SIZEOF( gCGUIEntityRenderer, 0x78 )

#endif
