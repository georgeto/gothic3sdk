#pragma once

#include <Game.h>

class PSInfoScriptCommand;

class GE_DLLIMPORT GUI
{
  public:
    GUI();
    ~GUI();

  public:
    GUI &operator=(GUI const &);

  public:
    GEBool PrintGameMessage(bCUnicodeString const &, gEGameMessageType);
    GEBool PrintScreen(bCString const &, GEFloat);
    GEBool PrintScreenEnd();
    GEBool PrintScreen_Debug(bCString const &, GEFloat);
    GEBool PrintScreen_InfoScript_Say(PSInfoScriptCommand &, GEFloat);
};

GE_DLLIMPORT_EXTC GUI gui;
