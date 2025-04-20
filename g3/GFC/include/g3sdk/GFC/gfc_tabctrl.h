#pragma once

#include <GFC/gfc_wnd.h>

#include <SharedBase.h>

class CFFGFCImageList;
class CFFGFCToolTipCtrl;

struct SFFGUITabCtrlItem
{
    UINT mask;
    DWORD dwState;
    DWORD dwStateMask;
    GELPUnicodeChar pszText;
    int cchTextMax;
    int iImage;
    LPARAM lParam;
};

struct SFFGUITabCtrlHitTest
{
    GE_UNIMPL_STRUCT(SFFGUITabCtrlHitTest)
};

class GE_DLLIMPORT CFFGFCTabCtrl : public CFFGFCWnd
{
    // clang-format off
    public: ~CFFGFCTabCtrl() override;
    // clang-format on

  public:
    CFFGFCTabCtrl(CFFGFCTabCtrl const &);
    CFFGFCTabCtrl();

  public:
    CFFGFCTabCtrl &operator=(CFFGFCTabCtrl const &);

  public:
    void AdjustRect(GEBool, bCRect &);
    GEBool Create(bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32);
    GEBool DeleteAllItems();
    GEBool DeleteItem(GEInt);
    void DeselectAll(GEBool);
    GEInt GetCurFocus() const;
    GEInt GetCurSel() const;
    GEU32 GetExtendedStyle() const;
    CFFGFCImageList *GetImageList() const;
    GEBool GetItem(GEInt, SFFGUITabCtrlItem &) const;
    GEInt GetItemCount() const;
    GEBool GetItemRect(GEInt, bCRect &) const;
    GEU32 GetItemState(GEInt, GEU32) const;
    GEInt GetRowCount() const;
    CFFGFCToolTipCtrl *GetToolTips() const;
    GEBool HighlightItem(GEInt, GEBool);
    GEInt HitTest(SFFGUITabCtrlHitTest &) const;
    GEInt InsertItem(GEInt, SFFGUITabCtrlItem const &);
    GEInt InsertItem(GEInt, bCUnicodeString const &);
    GEInt InsertItem(GEInt, bCUnicodeString const &, GEInt);
    GEInt InsertItem(GEU32, GEInt, bCUnicodeString const &, GEInt, GEUInt);
    GEInt InsertItem(GEU32, GEInt, bCUnicodeString const &, GEInt, GEUInt, GEU32, GEU32);
    void SetCurFocus(GEInt);
    GEInt SetCurSel(GEInt);
    GEU32 SetExtendedStyle(GEU32, GEU32);
    CFFGFCImageList *SetImageList(CFFGFCImageList *);
    GEBool SetItem(GEInt, SFFGUITabCtrlItem const &);
    GEBool SetItemExtra(GEInt);
    bCPoint SetItemSize(bCPoint);
    GEBool SetItemState(GEInt, GEU32, GEU32);
    GEInt SetMinTabWidth(GEInt);
    void SetPadding(bCPoint);
    void SetToolTips(CFFGFCToolTipCtrl *);
};
