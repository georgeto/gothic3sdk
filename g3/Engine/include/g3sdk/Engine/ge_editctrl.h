#pragma once

#include <Engine/ge_clipboardclient.h>
#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCEditCtrl : public eCWnd, public eCClipboardClient
{
    // clang-format off
    protected: virtual void RenderText();
    protected: virtual void RenderSelText();
    // Overrides for eCWnd
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCEditCtrl() override;
    public: bCString GetText() const override;
    public: void GetText(bCString &) const override;
    public: void SetText(bCString const &) override;
    public: GEBool IsModalFinished() const override;
    public: void Process() override;
    protected: void OnRender() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    public: GEInt OnKeyDown(eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const &) override;
    public: GEInt OnChar(GEChar, eCInpShared::eSInputMessage const &) override;
    public: void OnLButtonDblClk(GEU32, bCPoint) override;
    public: void OnLButtonDown(GEU32, bCPoint) override;
    // Overrides for eCClipboardClient
    public: void Clear() override;
    public: void Copy() override;
    public: void Cut() override;
    public: void Paste() override;
    public: void Undo() override;
    // clang-format on

  public:
    eCEditCtrl(eCEditCtrl const &);
    eCEditCtrl();

  public:
    eCEditCtrl &operator=(eCEditCtrl const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void ClearSel();
    void CopyFrom(eCEditCtrl const &);
    void CopyTo(eCEditCtrl &) const;
    GEInt GetCursorPos() const;
    void GetCursorPos(GEInt &) const;
    GEInt GetLimit() const;
    void GetLimit(GEInt &) const;
    GEChar GetPasswordChar() const;
    void GetPasswordChar(GEChar &) const;
    void GetSel(GEInt &, GEInt &) const;
    void GetSelText(bCString &) const;
    GEBool IsBrowsingAutoCompletion() const;
    GEBool IsModified() const;
    GEBool IsOverwrite() const;
    GEBool IsReadOnly() const;
    GEBool IsSelEmpty() const;
    void SetBrowsingAutoCompletion(GEBool);
    void SetCursorPos(GEInt);
    void SetLimit(GEInt);
    void SetModified(GEBool);
    void SetOverwrite(GEBool);
    void SetPasswordChar(GEChar);
    void SetReadOnly(GEBool);
    void SetSel(GEInt, GEInt);

  protected:
    GEInt &AccessCursorPos();
    GEInt &AccessLimit();
    GEChar &AccessPasswordChar();
    GEInt &AccessSelEnd();
    GEInt &AccessSelStart();
    GEInt GetSelEnd() const;
    void GetSelEnd(GEInt &) const;
    GEInt GetSelStart() const;
    void GetSelStart(GEInt &) const;
    void GetVisible(GEInt &, GEInt &) const;
    bCString GetVisibleText() const;
    void InsertText(bCString const &);
    void Invalidate();
    void MoveRel(GEInt, GEBool);
    void MoveRelWord(GEInt, GEBool);
    void MoveTo(GEInt, GEBool);
    void ReplaceSelText(bCString const &);
    void UpdateText(GEChar);
};
