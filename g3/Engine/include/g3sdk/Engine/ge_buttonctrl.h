#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCButtonCtrl : public eCWnd
{
    // clang-format off
    protected: virtual void RenderText();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCButtonCtrl() override;
    protected: void OnSysColorChange() override;
    protected: void OnRender() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    public: GEInt OnKeyDown(eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const &) override;
    public: void OnLButtonDown(GEU32, bCPoint) override;
    // clang-format on

  public:
    eCButtonCtrl(eCButtonCtrl const &);
    eCButtonCtrl();

  public:
    eCButtonCtrl &operator=(eCButtonCtrl const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCButtonCtrl const &);
    void CopyTo(eCButtonCtrl &) const;
    GELPVoid const GetBitmap() const;
    GEU32 GetButtonStyle() const;
    GEInt GetCheck() const;
    eCCursor const *GetCursor() const;
    GELPVoid const GetIcon() const;
    GEU32 GetState() const;
    void SetButtonStyle(GEU32, GEBool);
    void SetCheck(GEInt);
    void SetCursor(eCCursor *);
    void SetState(GEBool);

  protected:
    void Invalidate();
};
