#pragma once

#include <Game/ge_hud.h>

#include <Engine.h>

enum gEHUDMenu
{
    gEHUDMenu_Main = 0,
    gEHUDMenu_Load = 1,
    gEHUDMenu_Save = 2,
    gEHUDMenu_Options = 3,
    gEHUDMenu_OptionsAudio = 4,
    gEHUDMenu_OptionsVideo = 5,
    gEHUDMenu_OptionsPerformance = 6,
    gEHUDMenu_OptionsPerformanceCustom = 7,
    gEHUDMenu_OptionsControls = 8,
    gEHUDMenu_OptionsControlsCustom = 9,
    gEHUDMenu_Difficulty = 10,
    gEHUDMenu_Credits = 11,
    gEHUDMenu_Intro = 12,
    gEHUDMenu_Loading = 13,
    gEHUDMenu_COUNT
};

class GE_DLLIMPORT gCHUDMenu : public CFFGFCView
{
    // clang-format off
    public: virtual GEBool RequiresRestart() const;
    public: virtual void CancelRestart();
    public: virtual void SaveOptions(eCConfigFile &);
    public: virtual void ResetValues();
    public: virtual void Open();
    public: virtual void Close();
    public: virtual void OnMenuChanged(gEHUDMenu, gEHUDMenu);
    public: virtual GEBool HandleCancel();
    public: void OnPaint() override;
    public: void OnEraseBkgnd() override;
    public: ~gCHUDMenu() override;
    // clang-format on

  public:
    gCHUDMenu(gCHUDMenu const &);
    gCHUDMenu(GEInt, CFFGFCWnd *);
    gCHUDMenu();

  public:
    gCHUDMenu &operator=(gCHUDMenu const &);

  public:
    void PlaySoundA(gEHUDSound);

  protected:
    void Mute(GEBool);
    void MuteMusic(GEBool);
    void OpenMenu(gEHUDMenu);
};
