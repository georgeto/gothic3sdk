#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class eCImageList;

class GE_DLLIMPORT eCTabCtrl : public eCWnd
{
  public:
    struct SEntry
    {
        GE_UNIMPL_STRUCT(SEntry)
    };

    struct SHit
    {
        GE_UNIMPL_STRUCT(SHit)
    };

    struct SItem
    {
        GE_UNIMPL_STRUCT(SItem)
    };

    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCTabCtrl() override;
    public: void OnSize(GEU32, GEInt, GEInt) override;
    public: void OnRender() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    eCTabCtrl(eCTabCtrl const &);
    eCTabCtrl();

  public:
    eCTabCtrl &operator=(eCTabCtrl const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void AdjustRect(GEBool, bCRect &);
    void CopyFrom(eCTabCtrl const &);
    void CopyTo(eCTabCtrl &) const;
    GEBool DeleteAllItems();
    GEBool DeleteItem(GEInt);
    void DeselectAll();
    GEInt GetCurFocus() const;
    GEInt GetCurSel() const;
    eCImageList *GetImageList() const;
    GEBool GetItem(GEInt, SItem &) const;
    GEInt GetItemCount() const;
    GEBool GetItemRect(GEInt, bCRect &) const;
    GEU32 GetItemState(GEInt, GEU32) const;
    GEInt GetRowCount() const;
    GEBool HighlightItem(GEInt, GEBool);
    GEInt HitTest(SHit &) const;
    GEInt InsertItem(GEInt, SItem const &);
    GEInt InsertItem(GEInt, bCString const &);
    GEInt InsertItem(GEInt, bCString const &, GEInt);
    GEInt InsertItem(GEU32, GEInt, bCString const &, GEInt, GEU32);
    GEInt InsertItem(GEU32, GEInt, bCString const &, GEInt, GEU32, GEU32, GEU32);
    void SetCurFocus(GEInt);
    GEInt SetCurSel(GEInt);
    eCImageList *SetImageList(eCImageList *);
    GEBool SetItem(GEInt, SItem &);
    bCPoint SetItemSize(GEInt, bCPoint);
    GEBool SetItemState(GEInt, GEU32, GEU32);
    GEBool SetMinTabWidth(GEInt);
    void SetPadding(bCPoint);

  protected:
    static void GE_STDCALL Fill(SEntry const &, SItem &);
    static void GE_STDCALL Fill(SItem const &, SEntry &);

  protected:
    void Create(SEntry &);
    void Destroy(SEntry &);
    void Invalidate();
};
