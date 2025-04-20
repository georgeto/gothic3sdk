#pragma once

#include <Engine/ge_clipboardclient.h>
#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCListBoxCtrl : public eCWnd, public eCClipboardClient
{
  public:
    struct eSItem
    {
        GE_UNIMPL_STRUCT(eSItem)
    };

    // clang-format off
    protected: virtual void RenderText();
    protected: virtual void RenderSelText();
    // Overrides for eCWnd
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCListBoxCtrl() override;
    protected: void OnSize(GEU32, GEInt, GEInt) override;
    protected: void OnParentNotify(GEU32, GEU32, GEU32, GEI32 *) override;
    protected: void OnRender() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    public: GEInt OnKeyDown(eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const &) override;
    public: GEInt OnChar(GEChar, eCInpShared::eSInputMessage const &) override;
    public: void OnLButtonDblClk(GEU32, bCPoint) override;
    public: void OnLButtonDown(GEU32, bCPoint) override;
    public: void OnMouseWheel(GEU32, GEI8, bCPoint) override;
    // Overrides for eCClipboardClient
    public: void Clear() override;
    public: void Copy() override;
    public: void Cut() override;
    public: void Paste() override;
    public: void Undo() override;
    // clang-format on

  public:
    eCListBoxCtrl(eCListBoxCtrl const &);
    eCListBoxCtrl();

  public:
    eCListBoxCtrl &operator=(eCListBoxCtrl const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    GEInt AddString(bCString const &);
    void CopyFrom(eCListBoxCtrl const &);
    void CopyTo(eCListBoxCtrl &) const;
    GEInt DeleteString(GEInt);
    GEInt Dir(GEInt, bCString const &);
    GEInt FindString(GEInt, bCString const &) const;
    GEInt FindStringExact(GEInt, bCString const &) const;
    GEInt GetAnchorIndex() const;
    GEInt GetCaretIndex() const;
    GEInt GetCount();
    GEInt GetCurSel() const;
    GEU32 GetItemData(GEInt) const;
    GELPVoid GetItemDataPtr(GEInt) const;
    GEInt GetItemHeight(GEInt) const;
    GEInt GetItemRect(GEInt, bCRect &) const;
    GEInt GetSelCount() const;
    GEInt GetSelItems(GEInt, GEInt *) const;
    GEInt GetText(GEInt, bCString &) const;
    GEInt GetTopIndex() const;
    GEInt InsertString(GEInt, bCString const &, bCByteAlphaColor const &);
    GEBool IsValidIndex(GEInt) const;
    GEInt ItemFromPoint(bCPoint const &, GEBool &, GEBool &) const;
    void OnCaretIndexChanged();
    void ResetContent();
    GEInt SelItemRange(GEBool, GEInt, GEInt);
    GEInt SelectString(GEInt, bCString const &);
    void SetAnchorIndex(GEInt);
    GEInt SetCaretIndex(GEInt, GEBool);
    void SetColumnWidth(GEInt);
    GEInt SetCurSel(GEInt);
    GEInt SetItemData(GEInt, GEU32);
    GEInt SetItemDataPtr(GEInt, GELPVoid);
    GEInt SetItemHeight(GEInt, GEInt);
    GEInt SetItemText(GEInt, bCString const &);
    GEInt SetSel(GEInt, GEBool);
    GEInt SetTopIndex(GEInt);

  protected:
    bTObjArray<eSItem> &AccessItems();
    bTObjArray<eSItem> const &GetItems() const;
    void GetItems(bTObjArray<eSItem> &) const;
    void Invalidate();
    void MovePageRel(GEInt, GEBool, GEBool);
    void MoveRel(GEInt, GEBool, GEBool);
    void MoveRelX(GEInt, GEBool, GEBool);
    void MoveTo(GEInt, GEBool, GEBool);
    void SetItems(bTObjArray<eSItem> const &);

  private:
    static GEInt GE_CCALL CompareItem(GELPCVoid, GELPCVoid);

  private:
    GEInt CalcMaxLength(bCString const &, GEBool);
};
