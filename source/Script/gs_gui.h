#ifndef GS_GUI_H_INCLUDED
#define GS_GUI_H_INCLUDED

class GE_DLLIMPORT GUI
{
    public:
         GUI( void );
        ~GUI( void );

    public:
        GUI & operator = ( GUI const & );

    public:
        GEBool PrintGameMessage( bCUnicodeString const &, gEGameMessageType );
        GEBool PrintScreen( bCString const &, GEFloat );
        GEBool PrintScreenEnd( void );
        GEBool PrintScreen_Debug( bCString const &, GEFloat );
        GEBool PrintScreen_InfoScript_Say( PSInfoScriptCommand &, GEFloat );

};

GE_DLLIMPORT_EXTC GUI gui;

#endif
