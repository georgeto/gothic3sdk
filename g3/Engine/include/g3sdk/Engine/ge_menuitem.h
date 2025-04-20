#pragma once

#include <Engine/ge_buttonctrl.h>

#include <SharedBase.h>

class eCMenu;

class GE_DLLIMPORT eCMenuItem : public eCButtonCtrl
{
    // clang-format off
    public: virtual eCMenu * GetSubMenu() const;
    public: virtual void SetSubMenu(eCMenu *);
    public: virtual eCMenu * GetParentMenu() const;
    public: virtual void SetParentMenu(eCMenu *);
    public: virtual GEBool GetIsChecked() const;
    public: virtual void SetIsChecked(GEBool);
    public: virtual void SetCheck(GEInt);
    public: virtual GEBool GetIsGrayed() const;
    public: virtual void SetIsGrayed(GEBool);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCMenuItem() override;
    public: void Process() override;
    protected: void OnRender() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    public: GEInt OnKeyDown(eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const &) override;
    public: void OnLButtonDown(GEU32, bCPoint) override;
    public: void OnMouseIdle(bCPoint const &) override;
    public: void OnMouseLeave() override;
    // clang-format on

  public:
    eCMenuItem(eCMenuItem const &);
    eCMenuItem();

  public:
    eCMenuItem &operator=(eCMenuItem const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCMenuItem const &);
    void CopyTo(eCMenuItem &) const;
    bCString const GetMenuItemName() const;

  protected:
    void Invalidate();
};
