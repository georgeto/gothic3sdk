#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class eCContextMenuEntrySelectedArg
{
    GE_UNIMPL_STRUCT(eCContextMenuEntrySelectedArg)
};

class GE_DLLIMPORT eCPropertySetCtrl : public eCWnd
{
    // clang-format off
    protected: virtual void RenderText();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCPropertySetCtrl() override;
    public: void Process() override;
    public: void Render() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCPropertySetCtrl, eCWnd)

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCPropertySetCtrl const &);
    void CopyTo(eCPropertySetCtrl &) const;
    bCObjectRefBase const *GetPropertySet() const;
    void GE_STDCALL OnCaretIndexChangedData(bCObjectRefBase *, eCCaretIndexChangedArg *);
    void GE_STDCALL OnCaretIndexChangedNames(bCObjectRefBase *, eCCaretIndexChangedArg *);
    void GE_STDCALL OnClickListData(bCObjectRefBase *, eCClickEventArg *);
    void GE_STDCALL OnClickListNames(bCObjectRefBase *, eCClickEventArg *);
    void GE_STDCALL OnCommandEdit(bCObjectRefBase *, eCNotifyEventArg *);
    void GE_STDCALL OnContextMenuEntrySelected(bCObjectRefBase *, eCContextMenuEntrySelectedArg *);
    void GE_STDCALL OnKeyDownEdit(bCObjectRefBase *, eCKeyDownEventArg *);
    void GE_STDCALL OnNotifyListPropertyData(bCObjectRefBase *, eCNotifyEventArg *);
    void GE_STDCALL OnNotifyListPropertyNames(bCObjectRefBase *, eCNotifyEventArg *);
    void SetPropertySet(bCObjectRefBase *);

  protected:
    static GEInt GE_STDCALL GetLengthOfLongestPropertyName(bCObjectRefBase const &);

  protected:
    GEInt GetListBoxIndexByPropertyName(bCString const &);
    bCAccessorProperty *GetPropertyByName(bCString const &);
    void Invalidate();
    void ModifyToolTip(GEU32, GEU32);
    void PostSelectProperty();
    GEBool ShowContextMenu(bCPoint const &, bCPoint const &);
    GEBool ToggleProperty(bCString const &);
    GEBool UpdateProperty(bCString const &, bCString const &);
    GEBool UpdateProperty(bCString const &);
    GEBool UpdateProperty(bCAccessorProperty *);

  private:
    GE_UNIMPL_MEMBERS(1412)
};

GE_ASSERT_SIZEOF(eCPropertySetCtrl, 0x674)
