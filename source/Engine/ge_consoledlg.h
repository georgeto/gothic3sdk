#ifndef GE_CONSOLEDLG_H_INCLUDED
#define GE_CONSOLEDLG_H_INCLUDED

class GE_DLLIMPORT eCConsoleDlg :
    public eCDialog
{
    public:    virtual bCString Execute( bCString const & );
    protected: virtual GEBool   OnExecute( bCString const &, bCString & );
    protected: virtual GEBool   OnComplete( bCString & );
    public:    virtual void     PrintChoices( bCString const & );
    public: using bCObjectBase::Write;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    protected: virtual void     Destroy( void );
    public:    virtual         ~eCConsoleDlg( void );
    protected: virtual void     OnSize( GEU32, GEInt, GEInt );
    protected: virtual GEBool   OnChildNotify( GEU32, GEU32, GEU32, GEI32 * );
    public: using eCWnd::Create;
    public:    virtual bEResult Create( GEU32, bCRect const &, GEU32, eCWnd * );
    public:    virtual GEInt    OnKeyDown( eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const & );
    public: using eCInputReceiver::CopyFrom;

    public:
        eCConsoleDlg( eCConsoleDlg const & );
        eCConsoleDlg( void );

    public:
        eCConsoleDlg & operator =  ( eCConsoleDlg const & );
        bCOStream &    operator >> ( bCOStream & );
        bCIStream &    operator << ( bCIStream & );

    public:
        void CopyFrom( eCConsoleDlg const & );
        void CopyTo( eCConsoleDlg & ) const;
        void PrintHistory( void );
        void PrintOutput( bCString const &, bCByteAlphaColor const & );
        void ReSize( void );

    protected:
        bTObjArray<bCString> &       AccessHistory( void );
        void                         Complete( void );
        void                         Execute( void );
        bTObjArray<bCString> const & GetHistory( void ) const;
        void                         GetHistory( bTObjArray<bCString> & ) const;
        void                         GotoEntry( GEInt );
        void                         Invalidate( void );
        void                         NextEntry( void );
        void                         PrevEntry( void );
        void                         SetHistory( bTObjArray<bCString> const & );

};

#endif
