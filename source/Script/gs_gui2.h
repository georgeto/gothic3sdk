#ifndef GS_GUI2_H_INCLUDED
#define GS_GUI2_H_INCLUDED

enum gEGamePage;
enum gEGameLogType;

class GE_DLLIMPORT GUI2
{
    public:
         GUI2( void );
        ~GUI2( void );

    public:
        GUI2 & operator = ( GUI2 const & );

    public:
        GEBool        ClosePage( void );
        gEGamePage    GetActivePage( void );
        GEBool        IsAnyPageOpen( void );
        GEBool        IsMenuOpen( void );
        void          Log( bCUnicodeString const &, gEGameLogType );
        void GE_CCALL LogF( gEGameLogType, GELPCChar, ... );
        GEBool        OpenAlchemy( Entity const & );
        GEBool        OpenBless( Entity const & );
        GEBool        OpenBook( Entity const & );
        GEBool        OpenCooking( Entity const & );
        GEBool        OpenDialog( void );
        GEBool        OpenFry( Entity const & );
        GEBool        OpenInventory( void );
        GEBool        OpenLetter( Entity const & );
        GEBool        OpenLoot( Entity const & );
        GEBool        OpenMap( Entity const & );
        GEBool        OpenMenu( void );
        GEBool        OpenPoison( Entity const & );
        GEBool        OpenQuests( void );
        GEBool        OpenSharpen( Entity const & );
        GEBool        OpenSkills( void );
        GEBool        OpenSmithing( Entity const & );
        GEBool        OpenSpells( void );
        GEBool        OpenTrade( Entity const & );
        void          OpenTutorial( bCUnicodeString const & );
        void          PrintGameMessage( bCUnicodeString const &, gEGameMessageType );
        void          SetCrossHairSize( GEFloat );
        void          ShowCrossHair( GEBool );
        void          ShowPicture( bCString const & );
        void          ShowSubtitle( bCUnicodeString const & );
        void          StartSay( Entity const &, bCUnicodeString const &, GEBool );
        void          StopSay( void );
        void          ToggleQuickSlots( void );
        void          UpdatePlayer( void );

};

GE_DLLIMPORT_EXTC GUI2 gui2;

#endif
