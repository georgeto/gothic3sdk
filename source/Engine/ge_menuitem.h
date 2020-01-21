#ifndef GE_MENUITEM_H_INCLUDED
#define GE_MENUITEM_H_INCLUDED

class GE_DLLIMPORT eCMenuItem :
    public eCButtonCtrl
{
    public:    virtual eCMenu * GetSubMenu( void ) const;
    public:    virtual void     SetSubMenu( eCMenu * );
    public:    virtual eCMenu * GetParentMenu( void ) const;
    public:    virtual void     SetParentMenu( eCMenu * );
    public:    virtual GEBool   GetIsChecked( void ) const;
    public:    virtual void     SetIsChecked( GEBool );
    public:    virtual void     SetCheck( GEInt );
    public:    virtual GEBool   GetIsGrayed( void ) const;
    public:    virtual void     SetIsGrayed( GEBool );
    public: using bCObjectBase::Write;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    public:    virtual void     Destroy( void );
    public:    virtual         ~eCMenuItem( void );
    public:    virtual void     Process( void );
    protected: virtual void     OnRender( void );
    public: using eCWnd::Create;
    public:    virtual bEResult Create( GEU32, bCRect const &, GEU32, eCWnd * );
    public:    virtual GEInt    OnKeyDown( eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const & );
    public:    virtual void     OnLButtonDown( GEU32, bCPoint );
    public:    virtual void     OnMouseIdle( bCPoint const & );
    public:    virtual void     OnMouseLeave( void );

    public:
        eCMenuItem( eCMenuItem const & );
        eCMenuItem( void );

    public:
        eCMenuItem & operator =  ( eCMenuItem const & );
        bCOStream &  operator >> ( bCOStream & );
        bCIStream &  operator << ( bCIStream & );

    public:
        using eCInputReceiver::CopyFrom;
        void           CopyFrom( eCMenuItem const & );
        void           CopyTo( eCMenuItem & ) const;
        bCString const GetMenuItemName( void ) const;

    protected:
        void Invalidate( void );

};

#endif
