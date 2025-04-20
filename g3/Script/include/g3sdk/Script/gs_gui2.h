#pragma once

#include <Game.h>

class Entity;

class GE_DLLIMPORT GUI2
{
  public:
    GUI2();
    ~GUI2();

  public:
    GUI2 &operator=(GUI2 const &);

  public:
    GEBool ClosePage();
    gEGamePage GetActivePage();
    GEBool IsAnyPageOpen();
    GEBool IsMenuOpen();
    void Log(bCUnicodeString const &, gEGameLogType);
    void GE_CCALL LogF(gEGameLogType, GELPCChar, ...);
    GEBool OpenAlchemy(Entity const &);
    GEBool OpenBless(Entity const &);
    GEBool OpenBook(Entity const &);
    GEBool OpenCooking(Entity const &);
    GEBool OpenDialog();
    GEBool OpenFry(Entity const &);
    GEBool OpenInventory();
    GEBool OpenLetter(Entity const &);
    GEBool OpenLoot(Entity const &);
    GEBool OpenMap(Entity const &);
    GEBool OpenMenu();
    GEBool OpenPoison(Entity const &);
    GEBool OpenQuests();
    GEBool OpenSharpen(Entity const &);
    GEBool OpenSkills();
    GEBool OpenSmithing(Entity const &);
    GEBool OpenSpells();
    GEBool OpenTrade(Entity const &);
    void OpenTutorial(bCUnicodeString const &);
    void PrintGameMessage(bCUnicodeString const &, gEGameMessageType);
    void SetCrossHairSize(GEFloat);
    void ShowCrossHair(GEBool);
    void ShowPicture(bCString const &);
    void ShowSubtitle(bCUnicodeString const &);
    void StartSay(Entity const &, bCUnicodeString const &, GEBool);
    void StopSay();
    void ToggleQuickSlots();
    void UpdatePlayer();
};

GE_DLLIMPORT_EXTC GUI2 gui2;
