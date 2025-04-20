#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCToolTipCtrl : public eCWnd
{
    // clang-format off
    protected: virtual void RenderText();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCToolTipCtrl() override;
    public: void Process() override;
    protected: void OnSysColorChange() override;
    public: void Render() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    eCToolTipCtrl(eCToolTipCtrl const &);
    eCToolTipCtrl();

  public:
    eCToolTipCtrl &operator=(eCToolTipCtrl const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    bCByteAlphaColor &AccessBackgroundColor();
    bCByteAlphaColor &AccessTextColor();
    void CopyFrom(eCToolTipCtrl const &);
    void CopyTo(eCToolTipCtrl &) const;
    bCByteAlphaColor const &GetBackgroundColor() const;
    bCByteAlphaColor const &GetTextColor() const;
    void Hide();
    void SetBackgroundColor(bCByteAlphaColor const &);
    void SetTextColor(bCByteAlphaColor const &);
    void Show(eCWnd &, bCPoint const &);

  protected:
    void Invalidate();
};
