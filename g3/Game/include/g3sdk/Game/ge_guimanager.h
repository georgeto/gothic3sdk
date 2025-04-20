#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

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

enum gEGameLogType
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT gCGUIManager
{
    // clang-format off
    public: virtual ~gCGUIManager();
    // clang-format on

  public:
    gCGUIManager(gCGUIManager const &);
    gCGUIManager();

  public:
    gCGUIManager &operator=(gCGUIManager const &);

  public:
    GEBool BeginLoot(eCEntity *);
    GEBool BeginTrade(eCEntity *);
    GEBool ClearAllEntities();
    GEBool CloseDialog();
    GEBool CloseMenu();
    GEBool ClosePage();
    GEBool Create();
    void Destroy();
    gEGamePage GetActivePage() const;
    GEBool HandleKey(gESessionKey);
    GEBool HandleMessage(GEUInt, GEUInt, GEInt);
    GEBool IsAnyPageOpen() const;
    GEBool IsMenuOpen() const;
    GEBool IsOpen() const;
    void Log(bCUnicodeString const &, gEGameLogType);
    void OnProcess();
    GEBool OpenAlchemy(eCEntity *);
    GEBool OpenBless(eCEntity *);
    GEBool OpenBook(eCEntity *);
    GEBool OpenCooking(eCEntity *);
    GEBool OpenDialog();
    GEBool OpenFry(eCEntity *);
    GEBool OpenInventory();
    GEBool OpenLetter(eCEntity *);
    GEBool OpenMap(eCEntity *);
    GEBool OpenMenu();
    GEBool OpenPoison(eCEntity *);
    GEBool OpenQuests();
    GEBool OpenSharpen(eCEntity *);
    GEBool OpenSkills();
    GEBool OpenSmithing(eCEntity *);
    GEBool OpenSpells();
    GEBool OpenTutorial(bCUnicodeString const &);
    void PrintGameMessage(bCUnicodeString const &, gEGameMessageType);
    void SetCrossHairSize(GEFloat);
    void ShowCrossHair(GEBool);
    void ShowPicture(bCString const &);
    void ShowStartLogo(GEBool);
    void ShowSubtitle(bCUnicodeString const &);
    void StartSay(bCUnicodeString const &, bCUnicodeString const &, GEBool);
    void StopSay();
    void ToggleHUD();
    void ToggleQuickSlots();
    void UpdatePlayer();

  protected:
    void ExportLogSettings();
    eCEntity *GetFocus() const;
    eCEntity *GetPlayer() const;
    void ImportLogSettings();
    void Invalidate();
    GEBool IsAnyMainPageOpen() const;
};
