#ifndef GE_CONSOLE_H_INCLUDED
#define GE_CONSOLE_H_INCLUDED

#pragma pack(push, 1)
class eCConsoleEventArg
{
    public:
        GEInt    field_0;
        GEInt    field_4;
        GEInt    field_8;
        GEInt    field_C;
        GEInt    field_10;
        GEInt    field_14;
        bCString commandLine;
        GEInt    field_1C;
        GEInt    field_20;
        GEInt    field_24;
        GEBool   success;
};
#pragma pack(pop)

class GE_DLLIMPORT eCConsole :
    public eCConsoleDlg
{
    public: using bCObjectBase::Write;
    public:    virtual bEResult                         Write( bCOStream & );
    public:    virtual bEResult                         Read( bCIStream & );
    protected: virtual void                             Destroy( void );
    public: using eCConsoleDlg::Create;
    public:    virtual bEResult                         Create( void );
    public:    virtual                                 ~eCConsole( void );
    public:    virtual eCInputReceiver::eEInputPriority GetInputPriority( void ) const;
    public:    virtual void                             Process( void );
    public:    virtual void                             OnParentNotify( GEU32, GEU32, GEU32, GEI32 * );
    public:    virtual GEInt                            OnKeyDown( eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const & );
    protected: virtual void                             OnFinishedOpening( void );
    protected: virtual void                             OnFinishedClosing( void );
    protected: virtual GEBool                           OnExecute( bCString const &, bCString & );
    protected: virtual GEBool                           OnComplete( bCString & );
    public:    virtual void                             PrintChoices( bCString const & );
    public: using eCInputReceiver::CopyFrom;
    public: using eCWnd::OnCommand;

    protected:
        static eCConsole * ms_pThis;

    public:
        static eCConsole & GE_STDCALL       AccessConsole( void );
        static eCConsole const & GE_STDCALL GetConsole( void );

    public:
        eCConsole( eCConsole const & );
        eCConsole( void );

    public:
        eCConsole & operator =  ( eCConsole const & );
        bCOStream & operator >> ( bCOStream & );
        bCIStream & operator << ( bCIStream & );

    public:
        void   AddArgument( bCString const &, bCString const &, eEConsoleDataType, GEU64, bCString const & );
        void   AddCommand( bCString const & a_strName, bCString const & a_strDescription, bCDelegateBase *, GEU64, bCString const & );
        void   AddFunction( bCString const &, bCString const &, bCDelegateBase *, GEU64, bCString const & );
        void   AddProperty( bCString const &, bCString const &, eEConsoleDataType, bCDelegateBase *, GEU64, bCString const & );
        void   BeginAddClass( bCString const &, bCString const &, bCDelegateBase * );
        void   Close( void );
        void   CopyFrom( eCConsole const & );
        void   CopyTo( eCConsole & ) const;
        void   EndAddClass( bCString const & );
        //bTObjArraySort<eSReadmeItem> const & GetAllCommands(void)const;
        GEBool IsOpen( void );
        GEBool IsTyping( void ) const;
        void   Open( void );
        void   PrintOutput( bCString const &, bCByteAlphaColor const & );
        void   Remove( bCString const & );
        void   Remove( bCDelegateBase *, GEBool );
        void   SetIsTyping( GEBool );

    protected:
        eCCommandManager &       AccessCommandManager( void );
        eCCommandManager const & GetCommandManager( void ) const;
        void                     GetCommandManager( eCCommandManager & ) const;
        void                     Invalidate( void );
        void                     SetCommandManager( eCCommandManager const & );

    private:
        void GE_STDCALL OnCommand( bCObjectRefBase *, eCConsoleEventArg * );
        void            RegisterCommands( void );

};

#endif
