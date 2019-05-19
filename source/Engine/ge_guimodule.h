#ifndef GE_GUIMODULE_H_INCLUDED
#define GE_GUIMODULE_H_INCLUDED

class GE_DLLIMPORT IFFGFCClient
{
    public: virtual GEBool DoModalFrame( void ) = 0;
};

class GE_DLLIMPORT eCGUIModule :
    public eCEngineComponentBase,
    public IFFGFCClient
{
    public: virtual GEU32 const GetProfileLastTicksFirst( void ) const;
    public: virtual            ~eCGUIModule( void );
    public: virtual bEResult    Initialize( void );
    public: virtual bEResult    PostInitialize( void );
    public: virtual bEResult    PreShutdown( void );
    public: virtual bEResult    Shutdown( void );
    public: virtual void        OnAppInitialized( void );
    public: virtual void        OnPostRender( void );
    public: virtual GEBool      DoModalFrame( void );

    public:
        static eCGUIModule & GE_STDCALL                GetInstance( void );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCGUIModule( eCGUIModule const & );
        eCGUIModule( void );

    public:
        eCGUIModule const & operator = ( eCGUIModule const & );

    public:
        GEBool       ActivateTheme( bCString const & );
        void         EnableDrawScale( GEBool );
        void         EnableInput( GEBool );
        void         EnableMouseScale( GEBool );
        eCGUIAdmin & GetAdmin( void );
        bCPoint      GetVirtualResolution( void ) const;
        GEBool       HandleMessage( GELPVoid, GEUInt, GEUInt, GEI32 );
        GEBool       IsDrawScaleEnabled( void ) const;
        GEBool       IsMouseScaleEnabled( void ) const;
        GEBool       ReSize( void );
        void         Render( void );
        void         RenderEdit( HWND__ *, GEU32 );
        void         SetVirtualResolution( bCPoint const & );
        void         ShowCursor( GEBool );
        void         ToVirtualCoords( GEUInt, GEUInt &, GEI32 & ) const;

    protected:
        GEBool Draw( void );
        void   Invalidate( void );
        GEBool LoadResources( void );

};

#endif
