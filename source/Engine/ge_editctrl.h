#ifndef GE_EDITCTRL_H_INCLUDED
#define GE_EDITCTRL_H_INCLUDED

class GE_DLLIMPORT eCEditCtrl :
    public eCWnd,
    public eCClipboardClient
{
    protected: virtual void     RenderText( void );
    protected: virtual void     RenderSelText( void );
    public: using bCObjectBase::Write;
    public:    virtual bEResult Write( bCOStream & );
    public:    virtual bEResult Read( bCIStream & );
    public:    virtual void     Destroy( void );
    public:    virtual         ~eCEditCtrl( void );
    public:    virtual void     GetText( bCString & ) const;
    public:    virtual bCString GetText( void ) const;
    public:    virtual void     SetText( bCString const & );
    public:    virtual GEBool   IsModalFinished( void ) const;
    public:    virtual void     Process( void );
    protected: virtual void     OnRender( void );
    public: using eCWnd::Create;
    public:    virtual bEResult Create( GEU32, bCRect const &, GEU32, eCWnd * );
    public:    virtual GEInt    OnKeyDown( eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const & );
    public:    virtual GEInt    OnChar( GEChar, eCInpShared::eSInputMessage const & );
    public:    virtual void     OnLButtonDblClk( GEU32, bCPoint );
    public:    virtual void     OnLButtonDown( GEU32, bCPoint );
    public:    virtual void     Clear( void );
    public:    virtual void     Copy( void );
    public:    virtual void     Cut( void );
    public:    virtual void     Paste( void );
    public:    virtual void     Undo( void );

    public:
        eCEditCtrl( eCEditCtrl const & );
        eCEditCtrl( void );

    public:
        eCEditCtrl & operator =  ( eCEditCtrl const & );
        bCOStream &  operator >> ( bCOStream & );
        bCIStream &  operator << ( bCIStream & );

    public:
        void   ClearSel( void );
        public: using eCInputReceiver::CopyFrom;
        void   CopyFrom( eCEditCtrl const & );
        void   CopyTo( eCEditCtrl & ) const;
        GEInt  GetCursorPos( void ) const;
        void   GetCursorPos( GEInt & ) const;
        GEInt  GetLimit( void ) const;
        void   GetLimit( GEInt & ) const;
        GEChar GetPasswordChar( void ) const;
        void   GetPasswordChar( GEChar & ) const;
        void   GetSel( GEInt &, GEInt & ) const;
        void   GetSelText( bCString & ) const;
        GEBool IsBrowsingAutoCompletion( void ) const;
        GEBool IsModified( void ) const;
        GEBool IsOverwrite( void ) const;
        GEBool IsReadOnly( void ) const;
        GEBool IsSelEmpty( void ) const;
        void   SetBrowsingAutoCompletion( GEBool );
        void   SetCursorPos( GEInt );
        void   SetLimit( GEInt );
        void   SetModified( GEBool );
        void   SetOverwrite( GEBool );
        void   SetPasswordChar( GEChar );
        void   SetReadOnly( GEBool );
        void   SetSel( GEInt, GEInt );

    protected:
        GEInt &  AccessCursorPos( void );
        GEInt &  AccessLimit( void );
        GEChar & AccessPasswordChar( void );
        GEInt &  AccessSelEnd( void );
        GEInt &  AccessSelStart( void );
        GEInt    GetSelEnd( void ) const;
        void     GetSelEnd( GEInt & ) const;
        GEInt    GetSelStart( void ) const;
        void     GetSelStart( GEInt & ) const;
        void     GetVisible( GEInt &, GEInt & ) const;
        bCString GetVisibleText( void ) const;
        void     InsertText( bCString const & );
        void     Invalidate( void );
        void     MoveRel( GEInt, GEBool );
        void     MoveRelWord( GEInt, GEBool );
        void     MoveTo( GEInt, GEBool );
        void     ReplaceSelText( bCString const & );
        void     UpdateText( GEChar );

};

#endif
