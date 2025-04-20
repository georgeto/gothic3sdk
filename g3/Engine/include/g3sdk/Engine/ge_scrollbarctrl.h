#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCScrollBarCtrl : public eCWnd
{
    // clang-format off
    protected: virtual void UpdateSlider();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCScrollBarCtrl() override;
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
    eCScrollBarCtrl(eCScrollBarCtrl const &);
    eCScrollBarCtrl();

  public:
    eCScrollBarCtrl &operator=(eCScrollBarCtrl const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCScrollBarCtrl const &);
    void CopyTo(eCScrollBarCtrl &) const;
    GEBool EnableScrollBar(GEU32);
    GEInt GetScrollLimit() const;
    GEInt GetScrollPos() const;
    void GetScrollPos(GEInt &) const;
    bCPoint const &GetScrollRange() const;
    void GetScrollRange(GEInt &, GEInt &) const;
    void GetScrollRange(bCPoint &) const;
    void SetScrollPos(GEInt);
    void SetScrollRange(bCPoint const &);
    void SetScrollRange(GEInt, GEInt);

  protected:
    GEInt &AccessScrollPos();
    bCPoint &AccessScrollRange();
    bEResult CreateButtons();
    void Invalidate();
};
