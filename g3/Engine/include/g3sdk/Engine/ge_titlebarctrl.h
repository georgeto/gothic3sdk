#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCTitleBarCtrl : public eCWnd
{
    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCTitleBarCtrl() override;
    protected: void OnSize(GEU32, GEInt, GEInt) override;
    protected: void OnParentNotify(GEU32, GEU32, GEU32, GEI32 *) override;
    protected: void OnSysColorChange() override;
    protected: void OnRender() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    public: GEInt OnKeyDown(eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const &) override;
    public: void OnLButtonDblClk(GEU32, bCPoint) override;
    public: void OnLButtonDown(GEU32, bCPoint) override;
    // clang-format on

  public:
    eCTitleBarCtrl(eCTitleBarCtrl const &);
    eCTitleBarCtrl();

  public:
    eCTitleBarCtrl &operator=(eCTitleBarCtrl const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCTitleBarCtrl const &);
    void CopyTo(eCTitleBarCtrl &) const;

  protected:
    bEResult CreateButtons();
    void Invalidate();
};
