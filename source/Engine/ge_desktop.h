#ifndef GE_DESKTOP_H_INCLUDED
#define GE_DESKTOP_H_INCLUDED

class GE_DLLIMPORT eCDesktop :
    public eCWnd
{
    protected: virtual void     Destroy( void );
    public:    virtual         ~eCDesktop( void );
    public:    virtual void     Render( void );
    public: using eCWnd::Create;
    public:    virtual bEResult Create( GEU32, bCRect const &, GEU32, eCWnd * );

    public:
        static eCDesktop & GE_STDCALL GetInstance( void );

    public:
        eCDesktop( eCDesktop const & );
        eCDesktop( void );

    public:
        eCDesktop & operator = ( eCDesktop const & );

    public:
        void ReSize( void );

    protected:
        void Invalidate( void );

};

#endif
