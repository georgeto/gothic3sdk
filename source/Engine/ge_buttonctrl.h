#ifndef GE_BUTTONCTRL_H_INCLUDED
#define GE_BUTTONCTRL_H_INCLUDED

class GE_DLLIMPORT eCButtonCtrl :
    public eCWnd
{
    protected: virtual void     RenderText( void );
    public: using bCObjectBase::Write;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    public:    virtual void     Destroy( void );
    public:    virtual         ~eCButtonCtrl( void );
    protected: virtual void     OnSysColorChange( void );
    protected: virtual void     OnRender( void );
    public: using eCWnd::Create;
    public:    virtual bEResult Create( GEU32, bCRect const &, GEU32, eCWnd * );
    public:    virtual GEInt    OnKeyDown( eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const & );
    public:    virtual void     OnLButtonDown( GEU32, bCPoint );

    public:
        eCButtonCtrl( eCButtonCtrl const & );
        eCButtonCtrl( void );

    public:
        eCButtonCtrl & operator =  ( eCButtonCtrl const & );
        bCOStream &    operator >> ( bCOStream & );
        bCIStream &    operator << ( bCIStream & );

    public:
        using eCInputReceiver::CopyFrom;
        void             CopyFrom( eCButtonCtrl const & );
        void             CopyTo( eCButtonCtrl & ) const;
        GELPVoid         GetBitmap( void ) const;
        GEU32            GetButtonStyle( void ) const;
        GEInt            GetCheck( void ) const;
        eCCursor const * GetCursor( void ) const;
        GELPVoid         GetIcon( void ) const;
        GEU32            GetState( void ) const;
        void             SetButtonStyle( GEU32, GEBool );
        void             SetCheck( GEInt );
        void             SetCursor( eCCursor * );
        void             SetState( GEBool );

    protected:
        void Invalidate( void );

};

#endif
