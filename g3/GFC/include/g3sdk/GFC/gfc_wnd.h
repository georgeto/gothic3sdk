#pragma once

#include <GUI.h>

class CFFGFCDataExchange;
class CFFGFCDeviceContext;
class CFFGFCScrollBar;
struct SFFGUIScrollInfo;

enum EFFGUIScrollBar
{
    // Shows or hides a window's standard horizontal and vertical scroll bars.
    EFFGUIScrollBar_Horz = 0,
    // Shows or hides a scroll bar control. The hwnd parameter must be the handle to the scroll bar control.
    EFFGUIScrollBar_Vert = 1,
    // Shows or hides a window's standard horizontal scroll bars.
    EFFGUIScrollBar_Ctl = 2,
    // Shows or hides a window's standard vertical scroll bar.
    EFFGUIScrollBar_Both = 3,
};

struct SFFGUIMeasureItem
{
    GE_UNIMPL_STRUCT(SFFGUIMeasureItem)
};

struct SFFGUIWndMinMax
{
    GE_UNIMPL_STRUCT(SFFGUIWndMinMax)
};

struct SFFGUIWndPosChange
{
    GE_UNIMPL_STRUCT(SFFGUIWndPosChange)
};

struct SFFGUIDeleteItem
{
    GE_UNIMPL_STRUCT(SFFGUIDeleteItem)
};

struct SFFGUIDrawItem
{
    GE_UNIMPL_STRUCT(SFFGUIDrawItem)
};

struct SFFGUINM
{
    GE_UNIMPL_STRUCT(SFFGUINM)
};

class GE_DLLIMPORT CFFGFCWnd : public IFFGUIMsgProc
{
  public:
    struct SCreateWnd
    {
        GE_UNIMPL_STRUCT(SCreateWnd)
    };

    // clang-format off
    public: virtual GEBool ContinueModal();
    public: virtual void EndModalLoop(GEInt);
    public: virtual void DoDataExchange(CFFGFCDataExchange *);
    public: virtual GEBool PreCreateWindow(SCreateWnd &);
    public: virtual void PostNcDestroy();
    public: virtual void OnCreate();
    public: virtual void OnDestroy();
    public: virtual void OnClose();
    public: virtual void OnEnable(GEBool);
    public: virtual void OnShowWindow(GEBool);
    public: virtual void OnActivate(CFFGFCWnd *);
    public: virtual void OnDeactivate(CFFGFCWnd *);
    public: virtual void OnSetFocus(CFFGFCWnd *);
    public: virtual void OnKillFocus(CFFGFCWnd *);
    public: virtual void OnStyleChanged(GEU32, GEU32);
    public: virtual void OnStyleChanging(GEU32, GEU32);
    public: virtual void OnWindowPosChanged(SFFGUIWndPosChange &);
    public: virtual void OnWindowPosChanging(SFFGUIWndPosChange &);
    public: virtual void OnMove(GEInt, GEInt);
    public: virtual void OnMoving(GEUInt, bCRect &);
    public: virtual void OnSize(GEInt, GEInt);
    public: virtual void OnSizing(GEUInt, bCRect &);
    public: virtual void OnGetMinMaxInfo(SFFGUIWndMinMax &);
    public: virtual void OnCommand(GEUInt, GEUInt);
    public: virtual void OnNotify(GEUInt, GEUInt);
    public: virtual void OnNotify(GEInt, SFFGUINM *, GEI32 *);
    public: virtual void OnParentNotify(GEUInt, bCPoint *, CFFGFCWnd *);
    public: virtual void OnKeyDown(GEUInt, GEUInt, GEUInt);
    public: virtual void OnKeyUp(GEUInt, GEUInt, GEUInt);
    public: virtual void OnChar(GEUInt, GEUInt, GEUInt);
    public: virtual void OnLButtonDown(GEUInt, bCPoint);
    public: virtual void OnLButtonUp(GEUInt, bCPoint);
    public: virtual void OnLButtonDblClk(GEUInt, bCPoint);
    public: virtual void OnRButtonDown(GEUInt, bCPoint);
    public: virtual void OnRButtonUp(GEUInt, bCPoint);
    public: virtual void OnRButtonDblClk(GEUInt, bCPoint);
    public: virtual void OnMButtonDown(GEUInt, bCPoint);
    public: virtual void OnMButtonUp(GEUInt, bCPoint);
    public: virtual void OnMButtonDblClk(GEUInt, bCPoint);
    public: virtual void OnMouseMove(GEUInt, bCPoint);
    public: virtual void OnMouseWheel(GEUInt, GEI16, bCPoint);
    public: virtual void OnHScroll(GEUInt, GEUInt, CFFGFCScrollBar *);
    public: virtual void OnVScroll(GEUInt, GEUInt, CFFGFCScrollBar *);
    public: virtual void OnPaint();
    public: virtual void OnEraseBkgnd();
    public: virtual void OnNcCreate();
    public: virtual void OnNcDestroy();
    public: virtual void OnNcLButtonDown(GEUInt, bCPoint);
    public: virtual void OnNcLButtonUp(GEUInt, bCPoint);
    public: virtual void OnNcLButtonDblClk(GEUInt, bCPoint);
    public: virtual void OnNcRButtonDown(GEUInt, bCPoint);
    public: virtual void OnNcRButtonUp(GEUInt, bCPoint);
    public: virtual void OnNcRButtonDblClk(GEUInt, bCPoint);
    public: virtual void OnNcMButtonDown(GEUInt, bCPoint);
    public: virtual void OnNcMButtonUp(GEUInt, bCPoint);
    public: virtual void OnNcMButtonDblClk(GEUInt, bCPoint);
    public: virtual void OnNcMouseMove(GEUInt, bCPoint);
    public: virtual void OnNcPaint();
    public: virtual void OnDeleteItem(GEU32, SFFGUIDeleteItem &);
    public: virtual void OnMeasureItem(GEU32, SFFGUIMeasureItem &);
    public: virtual void OnDrawItem(GEU32, SFFGUIDrawItem &);
    public: virtual void OnDesktopSized(GEInt, GEInt);
    public: virtual void OnThemeChanged();
    protected: virtual GEInt WindowProc(GEUInt, GEUInt, GEUInt);
    public: virtual ~CFFGFCWnd();
    protected: GEInt MsgProc(IFFGUIWindow *, GEUInt, GEUInt, GEUInt) override;
    // clang-format on

  public:
    static CFFGFCWnd *GE_STDCALL FromHandle(IFFGUIWindow *);

  public:
    CFFGFCWnd(CFFGFCWnd const &);
    CFFGFCWnd();

  public:
    CFFGFCWnd &operator=(CFFGFCWnd const &);

  public:
    GEBool AnimateWindow(GEU32, GEU32);
    void BringWindowToTop();
    void CenterWindow();
    void ClientToScreen(bCPoint &) const;
    void ClientToScreen(bCRect &) const;
    GEBool Create(bCString const &, bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32);
    GEBool Create(bCString const &, bCUnicodeString const &, GEU32, GEInt, GEInt, GEInt, GEInt, CFFGFCWnd *, GEU32);
    GEBool Create(bCString const &, CFFGFCWnd *);
    GEBool Create(GEInt, CFFGFCWnd *);
    void Destroy();
    GEBool EnableWindow(GEBool);
    CFFGFCWnd *GetActiveWindow() const;
    void GetClientRect(bCRect &) const;
    CFFGFCDeviceContext *GetDC() const;
    CFFGFCWnd *GetDesktopWindow() const;
    GEU32 GetDlgCtrlID() const;
    CFFGFCWnd *GetDlgItem(GEU32) const;
    CFFGFCWnd *GetFocus() const;
    IFFGUIWindow *GetHandle() const;
    GEU32 GetHotKey() const;
    CFFGFCWnd *GetParentWindow() const;
    GEBool GetScrollInfo(EFFGUIScrollBar, SFFGUIScrollInfo &) const;
    GEU32 GetStyle() const;
    CFFGFCDeviceContext *GetWindowDC() const;
    void GetWindowRect(bCRect &) const;
    bCUnicodeString GetWindowTextA() const;
    void GetWindowTextA(bCUnicodeString &) const;
    GEBool HasFocus() const;
    GEBool IsActiveWindow() const;
    GEBool IsAttached() const;
    GEBool IsIconic() const;
    GEBool IsMouseOver() const;
    GEBool IsWindowEnabled() const;
    GEBool IsWindowVisible() const;
    GEBool IsZoomed() const;
    GEU32 ModifyStyle(GEU32, GEU32);
    void MoveWindow(bCRect const &);
    void MoveWindow(GEInt, GEInt, GEInt, GEInt);
    GEInt RunModalLoop(GEU32);
    void ScreenToClient(bCPoint &) const;
    void ScreenToClient(bCRect &) const;
    GEInt SendMessage(GEUInt, GEUInt, GEUInt) const;
    void SendWindowToBack();
    CFFGFCWnd *SetActiveWindow();
    void SetDlgCtrlID(GEU32);
    GEU32 SetExtendedStyle(GEU32);
    CFFGFCWnd *SetFocus();
    void SetHotKey(GEU32);
    GEBool SetScrollInfo(EFFGUIScrollBar, SFFGUIScrollInfo const &);
    void SetWindowTextA(bCUnicodeString const &);
    void ShowScrollBar(EFFGUIScrollBar, GEBool a_bShow);
    GEBool ShowWindow(GEBool);
    GEBool SubclassDlgItem(CFFGFCWnd *, GEU32);
    GEBool UpdateData(GEBool);

  protected:
    GEInt DefWindowProcA(GEUInt, GEUInt, GEUInt) const;
    GEInt Default();
    void SetHandle(IFFGUIWindow *);

  private:
    GEInt __FIXME_0004;
    GEInt __FIXME_0008;
    GEInt __FIXME_000C;
};

GE_ASSERT_SIZEOF(CFFGFCWnd, 0x10)
