#ifndef GE_HUDPAGE_H_INCLUDED
#define GE_HUDPAGE_H_INCLUDED

class GE_DLLIMPORT gCHUDPage :
    public CFFGFCView
{
    public:    virtual GEBool Create( bCRect const &, CFFGFCWnd *, GEU32 );
    public:    virtual void   Open( void );
    public:    virtual void   Close( void );
    public:    virtual void   OnPageChanged( gEHUDPage, gEHUDPage );
    public:    virtual void   SetEntity( eCEntity *, gEHUDEntity );
    public:    virtual GEBool HandleCancel( void );
    public:    virtual void   OnPaint( void );
    protected: virtual void   PlaceControls( void );
    protected: virtual void   PopulateControls( void );
    public:    virtual void   OnCreate( void );
    public:    virtual void   OnSize( GEInt, GEInt );
    public:    virtual void   OnCommand( GEUInt, GEUInt );
    public:    virtual void   OnNotify( GEInt, SFFGUINM *, GEI32 * );
    protected: virtual void   CreateControls( void );
    public:    virtual void   OnEraseBkgnd( void );
    public:    virtual       ~gCHUDPage( void );

    public:
        gCHUDPage( gCHUDPage const & );
        gCHUDPage( void );

    public:
        gCHUDPage & operator = ( gCHUDPage const & );

    public:
             gCHUDPage( GEInt, CFFGFCWnd * );
        void PlaySoundA( gEHUDSound );

};

#endif
