#pragma once

#include <Game/ge_hud.h>

#include <Engine.h>

enum gEHUDEntity
{
    // TODO: Enumerator values
};

enum gEHUDPage
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT gCHUDPage : public CFFGFCView
{
    // clang-format off
    public: virtual GEBool Create(bCRect const &, CFFGFCWnd *, GEU32);
    public: virtual void Open();
    public: virtual void Close();
    public: virtual void SetEntity(eCEntity *, gEHUDEntity);
    public: virtual void OnPageChanged(gEHUDPage, gEHUDPage);
    public: virtual GEBool HandleCancel();
    protected: virtual void CreateControls();
    protected: virtual void PlaceControls();
    protected: virtual void PopulateControls();
    public: void OnCreate() override;
    public: void OnSize(GEInt, GEInt) override;
    public: void OnCommand(GEUInt, GEUInt) override;
    public: void OnNotify(GEInt, SFFGUINM *, GEI32 *) override;
    public: void OnPaint() override;
    public: void OnEraseBkgnd() override;
    public: ~gCHUDPage() override;
    // clang-format on

  public:
    gCHUDPage(gCHUDPage const &);
    gCHUDPage(GEInt, CFFGFCWnd *);
    gCHUDPage();

  public:
    gCHUDPage &operator=(gCHUDPage const &);

  public:
    void PlaySoundA(gEHUDSound);
};
