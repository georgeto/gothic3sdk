#ifndef GE_ACTIONMAPPER_H_INCLUDED
#define GE_ACTIONMAPPER_H_INCLUDED

class eCPhysicalKey :
    public bCObjectRefBase
{
    eCInpShared::eEKeyboardStateOffset m_enuKeyboardStateOffset;
    GEInt                              m_iPriority;
    bCUnicodeString                    m_strLocalizedKeyName;
};
GE_ASSERT_SIZEOF( eCPhysicalKey, 0x18 )

class eCMenuItem;
class eCLogicalKey;
struct eSScriptEvent;
struct eSActionMapping;

class eCActionEvent :
    public bCEvent
{
    public:
        eCLogicalKey *  m_pLogicalKey;
        eCPhysicalKey * m_pPhysicalKey;
        GEBool          m_bKeyOn;
        GEBool          m_bKeyOnBefore;
        GEInt           m_iSomeIndex;
};
GE_ASSERT_SIZEOF( eCActionEvent, 0x28 )


class GE_DLLIMPORT eCActionMapper :
    public eCInputReceiver
{
    public: virtual void     Process( void );
    public: virtual void     OnStartup( void );
    public: virtual void     OnPreProcess( void );
    public: virtual void     OnPostProcess( void );
    public: virtual void     OnPreRender( void );
    public: virtual void     OnPostRender( void );
    public: virtual void     OnShutDown( void );
    public: virtual void     OnWorldActivated( void );
    public: using bCObjectBase::Write;
    public: virtual bEResult Write( bCOStream & );
    public: virtual bEResult Read( bCIStream & );
    public: virtual void     Destroy( void );
    public: virtual bEResult Create( void );
    public: virtual bEResult CopyFrom( bCObjectBase const & );
    public: virtual         ~eCActionMapper( void );
    public: virtual GEInt    OnKeyboard( eCInpShared::eSInputMessage const & );
    public: virtual GEInt    OnMouse( eCInpShared::eSInputMessage const & );

    public:
        static eCActionMapper * ms_pInstance;

    public:
        static eCActionMapper & GE_STDCALL             GetInstance( void );
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        eCActionMapper( eCActionMapper const & );
        eCActionMapper( void );

    public:
        eCActionMapper const & operator =  ( eCActionMapper const & );
        bCOStream &            operator >> ( bCOStream & );
        bCIStream &            operator << ( bCIStream & );

    public:
        // ActionMapper tries to find a keybinding for the event using its name as a key into the DebugControls section of ini/controls.ini.
        // When a_u32SubmenuId is specified the action mapper creates a menu item for the event in the corresponding menu (menus are created in eCApplication::CreateMainMenu).
        // When a_strConsoleCommandName is specified the action mapper creates a console command for the event.
        // Arguments for the a_pDelegateBase:
        //   a_pInvoker can be of any type, most of the time it is a window, the GuiManager or menu item.
        //   a_pEvent is a subclass of eCEvent
        eCMenuItem *                          AddEvent( bCString const & a_strName, bCDelegateBase * a_pDelegateBase, GEU32 a_u32SubmenuId = 0xFFFFFFFF, GEU32 a_u32EventId = 0xFFFFFFFF, bCString const & a_strConsoleCommandName = g_strDefault, bCString const & a_strConsoleCommandDescription = g_strDefault );
        // Use this function when adding events after eCActionMapper::OnStartup has been executed, to force reexecution of eCActionMapper::ParseEvents. Otherwise Keybindings won't work. (See also RegisterScriptEvent)
        eCMenuItem *                          AddLazyEvent( bCString const & a_strName, bCDelegateBase * a_pDelegateBase, GEU32 a_u32SubmenuId = 0xFFFFFFFF, GEU32 a_u32EventId = 0xFFFFFFFF, bCString const & a_strConsoleCommandName = g_strDefault, bCString const & a_strConsoleCommandDescription = g_strDefault );
        void                                  ClearOccuredEvents( void );
        void                                  CopyFrom( eCActionMapper const & );
        void                                  CopyTo( eCActionMapper & ) const;
        void                                  EnableDelegates( GEBool );
        GEBool                                GetDebugMode( void ) const;
        bTPtrArray<eCPhysicalKey *> const &   GetMapping( eCLogicalKey const & ) const;
        GEBool                                GetMapping( eCPhysicalKey const &, eCLogicalKey & ) const;
        GEU32                                 GetNumOccuredEvents( void );
        eCInpShared::eSGameKeyMessage const & GetOccuredEvent( GEU32 ) const;
        void                                  Invalidate( void );
        GEBool                                IsMapped( eCLogicalKey const & ) const;
        void                                  ParseEvents( bCString const &, GEBool );
        void                                  ParseScriptEvents( void );
        void                                  RegisterScriptEvent( eSScriptEvent & );
        void                                  RemoveEvent( bCString const & );
        void                                  SetDebugMode( GEBool );
        eSActionMapping *                     SetMapping( eCLogicalKey &, bTPtrArray<eCPhysicalKey *> &, GEBool const &, GEFloat const & );

    protected:
        bCString GetEventConfigValue( bCString const & );
        GEU32    OccuredIndexToMapIndex( GEU32 ) const;

};

#endif
