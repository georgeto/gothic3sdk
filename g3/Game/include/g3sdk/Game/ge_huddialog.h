#pragma once

#include <Game/ge_hud.h>

#include <GFC.h>

class GE_DLLIMPORT gCHUDDialog : public CFFGFCDialog
{
    // clang-format off
    public: ~gCHUDDialog() override;
    // clang-format on

  public:
    gCHUDDialog(gCHUDDialog const &);
    gCHUDDialog(GEInt, CFFGFCWnd *);
    gCHUDDialog();

  public:
    gCHUDDialog &operator=(gCHUDDialog const &);

  public:
    void PlaySoundA(gEHUDSound);
};
