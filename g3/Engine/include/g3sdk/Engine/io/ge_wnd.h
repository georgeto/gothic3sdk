#pragma once

#include <Engine/ge_colorscheme.h>
#include <Engine/io/ge_inpshared.h>
#include <Engine/io/ge_inputreceiver.h>

#include <SharedBase.h>

class eCCanvas;
class eCCaret;
class eCCursor;
class eCFont;
class eCGUIManager;
class eCScrollBarCtrl;
class eCTitleBarCtrl;
class eCWnd;

enum eEWinAlignMode
{
    // TODO: Enumerator values
};

enum eEWinTextMode
{
    // TODO: Enumerator values
};

class eCCaretIndexChangedArg
{
    GE_UNIMPL_STRUCT(eCCaretIndexChangedArg)
};

class eCKeyDownEventArg
{
    GE_UNIMPL_STRUCT(eCKeyDownEventArg)
};

class eCNotifyEventArg
{
    GE_UNIMPL_STRUCT(eCNotifyEventArg)
};

enum eEWinAniMode
{
    // TODO: Enumerator values
};

class eCClickEventArg : public bCEvent
{
  public:
    bCPoint m_ClickPosition;
    GEBool m_bMouseButtonState;
    GEBool m_bMouseButtonLastState;
    GEInt m_iSomeIndex;
    eCWnd *m_pWindow;
};
GE_ASSERT_SIZEOF(eCClickEventArg, 0x2C)

class GE_DLLIMPORT eCWnd : public eCInputReceiver
{
  public:
    class eCTextItem
    {
        GE_UNIMPL_STRUCT(eCTextItem)
    };

    // clang-format off
    public: virtual bCString GetText() const;
    public: virtual void GetText(bCString &) const;
    public: virtual bCString GetTitleBarText() const;
    public: virtual void SetID(GEU32);
    public: virtual void SetStyle(GEU32);
    public: virtual void SetStyleEx(GEU32);
    public: virtual void SetFlags(GEU32);
    public: virtual void SetParent(eCWnd *);
    public: virtual void SetOwner(eCWnd *);
    public: virtual void SetCanvas(eCCanvas *);
    public: virtual void SetTitleBar(eCTitleBarCtrl *);
    public: virtual void SetFont(eCFont *);
    public: virtual void SetPosition(bCPoint const &, GEBool);
    public: virtual void SetDimensions(bCPoint const &, GEBool);
    public: virtual void SetName(bCString const &);
    public: virtual void SetTitleBarText(bCString const &);
    public: virtual void SetText(bCString const &);
    public: virtual void SetModal(GEBool);
    public: virtual GEBool IsModal() const;
    public: virtual GEU32 DoModal();
    public: virtual GEBool IsModalFinished() const;
    protected: virtual void OnActivate(GEU32, eCWnd *, GEBool);
    protected: virtual void OnMove(GEInt, GEInt);
    protected: virtual void OnSize(GEU32, GEInt, GEInt);
    protected: virtual void UpdateCanvas();
    protected: virtual void UpdateFont();
    public: virtual void Process();
    public: virtual void UpdateWindow();
    protected: virtual GEBool OnNotify(GEU32, GEU32, GEI32 *);
    protected: virtual void GE_STDCALL OnCommand(bCObjectRefBase *, eCNotifyEventArg *);
    protected: virtual void GE_STDCALL OnEvent(bCObjectRefBase *, bCEvent *);
    protected: virtual void GE_STDCALL OnClick(bCObjectRefBase *, eCClickEventArg *);
    protected: virtual GEBool OnChildNotify(GEU32, GEU32, GEU32, GEI32 *);
    protected: virtual void OnParentNotify(GEU32, GEU32, GEU32, GEI32 *);
    protected: virtual void OnSysColorChange();
    public: virtual void Render();
    protected: virtual void OnRender();
    public: virtual bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *);
    public: virtual GEInt OnKeyUp(eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const &);
    public: virtual GEInt OnKeyDown(eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const &);
    public: virtual GEInt OnChar(GEChar, eCInpShared::eSInputMessage const &);
    public: virtual void OnLButtonDblClk(GEU32, bCPoint);
    public: virtual void OnLButtonDown(GEU32, bCPoint);
    public: virtual void OnLButtonUp(GEU32, bCPoint);
    public: virtual void OnMButtonDblClk(GEU32, bCPoint);
    public: virtual void OnMButtonDown(GEU32, bCPoint);
    public: virtual void OnMButtonUp(GEU32, bCPoint);
    public: virtual void OnMouseActivate(eCWnd *, GEU32, GEU32);
    public: virtual void OnMouseMove(GEU32, bCPoint);
    public: virtual void OnMouseWheel(GEU32, GEI8, bCPoint);
    public: virtual void OnMouseIdle(bCPoint const &);
    public: virtual void OnMouseLeave();
    public: virtual void OnRButtonDblClk(GEU32, bCPoint);
    public: virtual void OnRButtonDown(GEU32, bCPoint);
    public: virtual void OnRButtonUp(GEU32, bCPoint);
    public: virtual void OnHScroll(GEU32, GEU32, eCScrollBarCtrl *);
    public: virtual void OnVScroll(GEU32, GEU32, eCScrollBarCtrl *);
    public: virtual void OnCaptureChanged(eCWnd *);
    public: virtual void OnSetCursor(eCWnd *, GEU32, GEU32);
    public: virtual void OnTimer(GEU32);
    public: virtual void OnBeforeToolTipDisplay(bCPoint const &, bCString &);
    public: virtual void OnFinishedOpening();
    public: virtual void OnFinishedClosing();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCWnd() override;
    // clang-format on

  public:
    static eCWnd *GE_STDCALL GetDesktopWindow();
    static GEInt GE_STDCALL GetIDFromString(bCString const &);
    static GEInt GE_STDCALL GetStyleFromString(bCString const &);
    static void GE_STDCALL SetTimePerCharacter(GEFloat);

  public:
    eCWnd(eCWnd const &);
    eCWnd();

  public:
    eCWnd &operator=(eCWnd const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void BringWindowToTop();
    void CenterWindow(eCWnd *);
    void ClearPrintWin();
    void ClientToDesktop(bCPoint &) const;
    void ClientToDesktop(bCRect &) const;
    void ClientToDesktop(bCPoint *const, GEInt) const;
    void ClipChildren(GEBool);
    void ClipSiblings(GEBool);
    GEBool ClipsChildren() const;
    GEBool ClipsSiblings() const;
    void CopyFrom(eCWnd const &);
    void CopyTo(eCWnd &) const;
    void DesktopToClient(bCPoint &) const;
    void DesktopToClient(bCRect &) const;
    void DesktopToClient(bCPoint *const, GEInt) const;
    GEBool EnableWindow(GEBool);
    eCCanvas *GetCanvas();
    eCCanvas const *GetCanvas() const;
    void GetCanvas(eCCanvas *&) const;
    void GetClientRect(bCRect &, GEBool) const;
    bCPoint GetDesktopPosition() const;
    void GetDesktopPosition(bCPoint &) const;
    bCPoint const &GetDimensions() const;
    void GetDimensions(bCPoint &) const;
    GEU32 GetFlags() const;
    eCFont *GetFont();
    eCFont const *GetFont() const;
    void GetFont(eCFont *&) const;
    eCScrollBarCtrl *GetHScrollBarCtrl();
    eCScrollBarCtrl const *GetHScrollBarCtrl() const;
    eCCaret *GetHighlightCaret();
    eCCaret const *GetHighlightCaret() const;
    GEU32 GetID() const;
    void GetID(GEU32 &) const;
    bCString const &GetName() const;
    eCWnd *GetOwner();
    eCWnd const *GetOwner() const;
    void GetOwner(eCWnd *&) const;
    eCWnd *GetParent();
    eCWnd const *GetParent() const;
    void GetParent(eCWnd *&) const;
    bCPoint const &GetPosition() const;
    void GetPosition(bCPoint &) const;
    eCWnd *GetSafeOwner();
    eCWnd const *GetSafeOwner() const;
    eCWnd *GetSafeParent();
    eCWnd const *GetSafeParent() const;
    GEU32 GetStyle() const;
    void GetStyle(GEU32 &) const;
    GEU32 GetStyleEx() const;
    bTObjArray<eCTextItem> const &GetTextArray() const;
    eCTitleBarCtrl *GetTitleBar() const;
    bCString const &GetToolTipText() const;
    eCWnd *GetTopLevelParent() const;
    eCScrollBarCtrl *GetVScrollBarCtrl();
    eCScrollBarCtrl const *GetVScrollBarCtrl() const;
    void GetWindowRect(bCRect &) const;
    GEBool IsActive() const;
    GEBool IsAnimating() const;
    GEBool IsChild(eCWnd *) const;
    GEBool IsEnabled() const;
    GEBool IsFocused() const;
    GEBool IsMaximized() const;
    GEBool IsMinimized() const;
    GEBool IsVisible() const;
    GEBool LoadLayout(bCString const &);
    void MapWindowPoints(eCWnd const *, bCRect &) const;
    void MapWindowPoints(eCWnd const *, bCPoint *const, GEInt) const;
    GEBool MatchesFlag(GEU32) const;
    GEBool MatchesStyle(GEU32) const;
    GEBool MatchesStyleEx(GEU32) const;
    GEBool ModifyFlags(GEU32, GEU32);
    GEBool ModifyStyle(GEU32, GEU32, GEU32);
    GEBool ModifyStyleEx(GEU32, GEU32, GEU32);
    void MoveWindow(bCPoint const &, bCPoint const &, GEBool);
    void MoveWindow(bCRect const &, GEBool);
    void Print(bCPoint const &, bCString const &, bCByteAlphaColor const *, eEWinTextMode);
    void Print(bCPoint const &, bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode);
    void Print(bCString const &, bCByteAlphaColor const *, eEWinTextMode);
    void Print(bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode);
    void PrintAligned(bCString const &, bCPoint const &, eEWinAlignMode, eEWinAlignMode, bCByteAlphaColor const *,
                      eEWinTextMode);
    void PrintAligned(bCUnicodeString const &, bCPoint const &, eEWinAlignMode, eEWinAlignMode,
                      bCByteAlphaColor const *, eEWinTextMode);
    void PrintCX(GEInt, bCString const &, bCByteAlphaColor const *, eEWinTextMode);
    void PrintCX(GEInt, bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode);
    void PrintCXY(bCString const &, bCByteAlphaColor const *, eEWinTextMode);
    void PrintCXY(bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode);
    void PrintCY(GEInt, bCString const &, bCByteAlphaColor const *, eEWinTextMode);
    void PrintCY(GEInt, bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode);
    void PrintStatic(bCPoint, bCString const &, bCByteAlphaColor const *, eEWinTextMode);
    void PrintStatic(bCPoint, bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode);
    void PrintStaticAligned(bCString const &, bCPoint const &, eEWinAlignMode, eEWinAlignMode, bCByteAlphaColor const *,
                            eEWinTextMode);
    void PrintStaticAligned(bCUnicodeString const &, bCPoint const &, eEWinAlignMode, eEWinAlignMode,
                            bCByteAlphaColor const *, eEWinTextMode);
    void PrintStaticCX(GEInt, bCString const &, bCByteAlphaColor const *, eEWinTextMode);
    void PrintStaticCX(GEInt, bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode);
    void PrintStaticCXY(bCString const &, bCByteAlphaColor const *, eEWinTextMode);
    void PrintStaticCXY(bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode);
    void PrintStaticCY(GEInt, bCString const &, bCByteAlphaColor const *, eEWinTextMode);
    void PrintStaticCY(GEInt, bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode);
    void PrintTimed(bCPoint, bCString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode);
    void PrintTimed(bCPoint, bCUnicodeString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode);
    void PrintTimedAligned(bCString const &, bCPoint const &, GEFloat, eEWinAlignMode, eEWinAlignMode,
                           bCByteAlphaColor const *, eEWinTextMode);
    void PrintTimedAligned(bCUnicodeString const &, bCPoint const &, GEFloat, eEWinAlignMode, eEWinAlignMode,
                           bCByteAlphaColor const *, eEWinTextMode);
    void PrintTimedCX(GEInt, bCString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode);
    void PrintTimedCX(GEInt, bCUnicodeString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode);
    void PrintTimedCXY(bCString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode);
    void PrintTimedCXY(bCUnicodeString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode);
    void PrintTimedCY(GEInt, bCString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode);
    void PrintTimedCY(GEInt, bCUnicodeString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode);
    void PrintTimedWin(bCString const &, bCString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode);
    void PrintTimedWin(bCUnicodeString const &, bCUnicodeString const &, GEFloat, bCByteAlphaColor const *,
                       eEWinTextMode);
    void PrintTimedWinAligned(bCString const &, bCString const &, eEWinAlignMode, eEWinAlignMode, GEFloat,
                              bCByteAlphaColor const *, eEWinTextMode);
    void PrintTimedWinAligned(bCUnicodeString const &, bCUnicodeString const &, eEWinAlignMode, eEWinAlignMode, GEFloat,
                              bCByteAlphaColor const *, eEWinTextMode);
    void PrintTimedWinCX(bCString const &, bCString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode);
    void PrintTimedWinCX(bCUnicodeString const &, bCUnicodeString const &, GEFloat, bCByteAlphaColor const *,
                         eEWinTextMode);
    void PrintTimedWinCXY(bCString const &, bCString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode);
    void PrintTimedWinCXY(bCUnicodeString const &, bCUnicodeString const &, GEFloat, bCByteAlphaColor const *,
                          eEWinTextMode);
    void PrintTimedWinCY(bCString const &, bCString const &, GEFloat, bCByteAlphaColor const *, eEWinTextMode);
    void PrintTimedWinCY(bCUnicodeString const &, bCUnicodeString const &, GEFloat, bCByteAlphaColor const *,
                         eEWinTextMode);
    void PrintWin(bCString const &, bCByteAlphaColor const *, eEWinTextMode);
    void PrintWin(bCUnicodeString const &, bCByteAlphaColor const *, eEWinTextMode);
    GEBool SaveLayout(bCString &);
    eCWnd *SetActiveWindow();
    void SetAniMode(eEWinAniMode const &);
    void SetAutoScroll(GEFloat);
    GEBool SetBackgroundAlpha(GEU8);
    eCWnd *SetFocus();
    void SetTextColor(bCByteAlphaColor const &);
    void SetToolTipText(bCString const &);
    void Show(GEBool, GEBool);
    eCWnd *WindowFromPoint(bCPoint const &) const;

  protected:
    static GEFloat ms_fTimePerCharacter;
    static eCGUIManager &ms_mgrWindows;

  protected:
    static bCString &GE_STDCALL CleanLine(bCString &);

  protected:
    eCCanvas *&AccessCanvas();
    eCCaret *&AccessCaret();
    eCWnd *AccessChildByID(GEInt);
    eCWnd *AccessChildByIndex(GEInt);
    eCWnd *AccessChildByName(bCString const &);
    bTPtrArray<eCWnd *> &AccessChildren();
    eCCursor *&AccessCursor();
    bCPoint &AccessDimensions();
    eCFont *&AccessFont();
    eCScrollBarCtrl *&AccessHScrollBarCtrl();
    eCCaret *&AccessHighlightCaret();
    GEU32 &AccessID();
    eCWnd *&AccessOwner();
    eCWnd *&AccessParent();
    bCPoint &AccessPosition();
    GEU32 &AccessStyle();
    bTObjArray<eCTextItem> &AccessTextArray();
    eCScrollBarCtrl *&AccessVScrollBarCtrl();
    void Activate(GEBool);
    void BringChildrenToTop();
    void CheckAutoScroll();
    GEBool CreateCanvas();
    GEBool CreateCarets();
    GEBool CreateFontA();
    GEBool CreateScrollBars();
    eCTextItem *CreateTextItem(GEInt, GEInt, bCUnicodeString const &, GEFloat, bCByteAlphaColor const &, eEWinTextMode);
    GEBool CreateTitleBar();
    eCCaret *GetCaret();
    eCCaret const *GetCaret() const;
    void GetCaret(eCCaret *&) const;
    eCWnd const *GetChildByID(GEInt) const;
    eCWnd const *GetChildByIndex(GEInt) const;
    eCWnd const *GetChildByName(bCString const &) const;
    bTPtrArray<eCWnd *> const &GetChildren() const;
    void GetChildren(bTPtrArray<eCWnd *> &) const;
    bCByteAlphaColor const &GetColor(eCColorScheme::eEColorIndex) const;
    eCCursor *GetCursor();
    eCCursor const *GetCursor() const;
    void GetCursor(eCCursor *&) const;
    void GetHScrollBarCtrl(eCScrollBarCtrl *&) const;
    void GetHighlightCaret(eCCaret *&) const;
    void GetVScrollBarCtrl(eCScrollBarCtrl *&) const;
    void Invalidate();
    GEBool LoadLayout_Recursive(bCString &);
    void MarkChildrenDirty(GEBool);
    void Maximize(GEBool);
    void Minimize(GEBool);
    void Notify(GEU32, GEU32, GEU32);
    void PrintWinNextLine(bCUnicodeString const &, GEFloat, bCByteAlphaColor const &, eEWinTextMode, eEWinAlignMode,
                          GEInt);
    void RenderTextLines();
    GEBool SaveLayout_Recursive(bCString &, GEInt);
    void SetCaret(eCCaret *);
    void SetChildStyle(GEU32);
    void SetChildren(bTPtrArray<eCWnd *> const &);
    void SetChildrenFadeAlpha(GEU8);
    void SetCursor(eCCursor *);
    void SetHScrollBarCtrl(eCScrollBarCtrl *);
    void SetHighlightCaret(eCCaret *);
    void SetVScrollBarCtrl(eCScrollBarCtrl *);

  private:
    GEBool NotifyChildren(GEU32, GEU32, GEU32);
    GEInt NotifyParent(GEU32, GEU32, GEU32);

  private:
    GE_UNIMPL_MEMBERS(0xe0)
};

GE_ASSERT_SIZEOF(eCWnd, 0xf0)
