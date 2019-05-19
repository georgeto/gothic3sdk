#ifndef GE_WINDOW_H_INCLUDED
#define GE_WINDOW_H_INCLUDED

enum eEWindowMode;

class GE_DLLIMPORT eCWindow :
    public eCMessageHandler
{
    public:
        struct eSCreate;

    public:    virtual GEBool   Create( eSCreate const & );
    protected: virtual void     Destroy( void );
    protected: virtual bEResult Create( void );
    public:    virtual         ~eCWindow( void );
    protected: virtual GEInt    OnActivate( GEUInt, GEI32 );
    protected: virtual GEInt    OnDestroy( GEUInt, GEI32 );
    protected: virtual GEInt    OnQuit( GEUInt, GEI32 );
    protected: virtual GEInt    OnPaint( GEUInt, GEI32 );

    public:
        eCWindow( eCWindow const & );
        eCWindow( void );

    public:
        eCWindow & operator =                   ( eCWindow const & );
                   operator HINSTANCE__ *       ( void );
                   operator HWND__ *            ( void );
                   operator HINSTANCE__ * const ( void ) const;
                   operator HWND__ * const      ( void ) const;

    public:
        void             AttachTo( HINSTANCE__ * const, HDC__ * const );
        void             AttachTo( HINSTANCE__ * const, HWND__ * const );
        void             Center( void );
        HDC__ *          GetDeviceContext( void ) const;
        HWND__ *         GetHandle( void ) const;
        HINSTANCE__ *    GetInstance( void ) const;
        bCRect const &   GetPosition( void ) const;
        eEWindowMode     GetWindowMode( void ) const;
        GEBool           IsAttached( void ) const;
        GEBool           IsCreated( void ) const;
        GEBool           IsSubClassed( void ) const;
        void             Restore( void );
        GEI32 GE_STDCALL SendMessageA( GEUInt, GEUInt, GEI32 );
        void             SetPosition( bCRect const & );
        void             SetWindowMode( eEWindowMode );
        void             Validate( void );

    protected:
        static GEI32 GE_STDCALL Receive( HWND__ *, GEUInt, GEUInt, GEI32 );
        static void GE_STDCALL  RegisterWindow( HWND__ *, eCWindow * );

    protected:
        GEBool Create( HINSTANCE__ *, GELPVoid, bCString const &, bCRect const &, eEWindowMode );
        GEBool Create( HINSTANCE__ *, GELPVoid, eEWindowMode );
        void   Invalidate( void );

};

#endif
