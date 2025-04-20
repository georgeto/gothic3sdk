#pragma once

#include <GFC/gfc_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT CFFGFCListBox : public CFFGFCWnd
{
    // clang-format off
    public: ~CFFGFCListBox() override;
    // clang-format on

  public:
    CFFGFCListBox(CFFGFCListBox const &);
    CFFGFCListBox();

  public:
    CFFGFCListBox &operator=(CFFGFCListBox const &);

  public:
    GEInt AddString(bCUnicodeString const &);
    GEBool Create(bCUnicodeString const &, GEU32, bCRect const &, CFFGFCWnd *, GEU32);
    GEInt DeleteString(GEInt);
    GEInt FindString(bCUnicodeString const &) const;
    GEInt FindStringExact(bCUnicodeString const &) const;
    GEInt GetAnchorIndex() const;
    GEInt GetCaretIndex() const;
    GEInt GetCount() const;
    GEInt GetCurSel() const;
    GEU32 GetItemData(GEInt) const;
    GELPVoid GetItemDataPtr(GEInt) const;
    GEInt GetItemHeight(GEInt) const;
    GEInt GetItemRect(GEInt, bCRect &) const;
    GEInt GetSel(GEInt) const;
    GEInt GetSelCount() const;
    void GetText(GEInt, bCUnicodeString &) const;
    GEInt GetTextLen(GEInt) const;
    GEInt GetTopIndex() const;
    GEInt InsertString(GEInt, bCUnicodeString const &);
    GEInt ItemFromPoint(bCPoint) const;
    void ResetContent();
    GEInt SelItemRange(GEBool, GEInt, GEInt);
    GEInt SelectString(bCUnicodeString const &);
    GEInt SetAnchorIndex(GEInt);
    GEInt SetCaretIndex(GEInt);
    GEInt SetCurSel(GEInt);
    GEInt SetItemData(GEInt, GEU32);
    GEInt SetItemDataPtr(GEInt, GELPVoid);
    GEInt SetItemHeight(GEInt, GEInt);
    GEInt SetSel(GEInt, GEBool);
    GEInt SetTopIndex(GEInt);
};
