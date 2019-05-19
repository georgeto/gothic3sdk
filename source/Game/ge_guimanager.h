#ifndef GE_G_GUIMANAGER_H_INCLUDED
#define GE_G_GUIMANAGER_H_INCLUDED

enum gEGamePage
{
    gEGamePage_Inventory = 0,
    gEGamePage_Spells = 1,
    gEGamePage_Documents = 2,
    gEGamePage_Skills = 3,
    gEGamePage_Quests = 4,
    gEGamePage_Trade = 5,
    gEGamePage_Dialog = 6,
    gEGamePage_Loot = 7,
    gEGamePage_SynthAlchemy = 8,
    gEGamePage_SynthCooking = 9,
    gEGamePage_SynthSmithing = 10,
    gEGamePage_BlessWeapon = 11,
    gEGamePage_PoisonWeapon = 12,
    gEGamePage_SharpenWeapon = 13,
    gEGamePage_FryMeat = 14,
    gEGamePage_Tutorial = 15,
    gEGamePage_Slideshow = 16
};
enum gEGameLogType;

class GE_DLLIMPORT gCGUIManager
{
    public: virtual ~gCGUIManager( void );

    public:
        gCGUIManager( gCGUIManager const & );
        gCGUIManager( void );

    public:
        gCGUIManager & operator = ( gCGUIManager const & );

    public:
        GEBool     BeginLoot( eCEntity * );
        GEBool     BeginTrade( eCEntity * );
        GEBool     ClearAllEntities( void );
        GEBool     CloseDialog( void );
        GEBool     CloseMenu( void );
        GEBool     ClosePage( void );
        GEBool     Create( void );
        void       Destroy( void );
        gEGamePage GetActivePage( void ) const;
        GEBool     HandleKey( gESessionKey );
        GEBool     HandleMessage( GEUInt, GEUInt, GEInt );
        GEBool     IsAnyPageOpen( void ) const;
        GEBool     IsMenuOpen( void ) const;
        GEBool     IsOpen( void ) const;
        void       Log( bCUnicodeString const &, gEGameLogType );
        void       OnProcess( void );
        GEBool     OpenAlchemy( eCEntity * );
        GEBool     OpenBless( eCEntity * );
        GEBool     OpenBook( eCEntity * );
        GEBool     OpenCooking( eCEntity * );
        GEBool     OpenDialog( void );
        GEBool     OpenFry( eCEntity * );
        GEBool     OpenInventory( void );
        GEBool     OpenLetter( eCEntity * );
        GEBool     OpenMap( eCEntity * );
        GEBool     OpenMenu( void );
        GEBool     OpenPoison( eCEntity * );
        GEBool     OpenQuests( void );
        GEBool     OpenSharpen( eCEntity * );
        GEBool     OpenSkills( void );
        GEBool     OpenSmithing( eCEntity * );
        GEBool     OpenSpells( void );
        GEBool     OpenTutorial( bCUnicodeString const & );
        void       PrintGameMessage( bCUnicodeString const &, gEGameMessageType );
        void       SetCrossHairSize( GEFloat );
        void       ShowCrossHair( GEBool );
        void       ShowPicture( bCString const & );
        void       ShowStartLogo( GEBool );
        void       ShowSubtitle( bCUnicodeString const & );
        void       StartSay( bCUnicodeString const &, bCUnicodeString const &, GEBool );
        void       StopSay( void );
        void       ToggleHUD( void );
        void       ToggleQuickSlots( void );
        void       UpdatePlayer( void );

    protected:
        void       ExportLogSettings( void );
        eCEntity * GetFocus( void ) const;
        eCEntity * GetPlayer( void ) const;
        void       ImportLogSettings( void );
        void       Invalidate( void );
        GEBool     IsAnyMainPageOpen( void ) const;

};

#endif
