#ifndef GE_DIALOG_H_INCLUDED
#define GE_DIALOG_H_INCLUDED

class GE_DLLIMPORT eCDialog :
    public eCWnd
{
    public: using bCObjectBase::Write;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    public:    virtual void     Destroy( void );
    public:    virtual         ~eCDialog( void );
    protected: virtual void     OnActivate( GEU32, eCWnd *, GEBool );
    protected: virtual void     OnSysColorChange( void );
    public: using eCWnd::Create;
    public:    virtual bEResult Create( GEU32, bCRect const &, GEU32, eCWnd * );
    public: using eCWnd::CopyFrom;

    public:
        eCDialog( eCDialog const & );
        eCDialog( void );

    public:
        eCDialog &  operator =  ( eCDialog const & );
        bCOStream & operator >> ( bCOStream & );
        bCIStream & operator << ( bCIStream & );

    public:
        void  CopyFrom( eCDialog const & );
        void  CopyTo( eCDialog & ) const;
        GEU32 GetDefID( void ) const;
        void  GetDefID( GEU32 & ) const;
        void  GotoDlgCtrl( eCWnd * );
        void  MapDialogRect( bCRect & ) const;
        void  NextDlgCtrl( void );
        void  PrevDlgCtrl( void );
        void  SetDefID( GEU32 );

    protected:
        GEU32 & AccessDefID( void );
        void    Invalidate( void );

};

#endif
