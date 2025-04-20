#pragma once

#include <Engine/io/ge_wnd.h>

#include <SharedBase.h>

class eCMenuItem;

class GE_DLLIMPORT eCMenu : public eCWnd
{
    // clang-format off
    public: virtual eCMenuItem * GetActiveItem() const;
    public: virtual void SetActiveItem(eCMenuItem *);
    public: virtual eCMenuItem * GetParentItem() const;
    public: virtual void SetParentItem(eCMenuItem *);
    public: virtual GEBool GetSubMenuOpenedOnce() const;
    public: virtual void SetSubMenuOpenedOnce(GEBool);
    public: virtual GEInt GetNumItems() const;
    public: virtual eCMenuItem * GetItem(GEU32) const;
    public: virtual eCMenuItem * GetItemByName(bCString const &);
    public: virtual GEInt GetItemIndexByName(bCString const &);
    public: virtual eCMenuItem * GetItemByID(GEU32);
    public: virtual eCMenu * GetSubMenuByName(bCString const &);
    public: virtual eCMenu * GetSubMenuByID(GEU32);
    public: virtual eCMenuItem * AddMenuItem(bCString const &, GEU32, bCDelegateBase *, GEU32, eCMenu *);
    public: virtual void AddMenuItem(eCMenuItem *);
    public: virtual void RemoveItem(GEU32);
    public: virtual void RemoveItem(bCString const &);
    public: virtual void RemoveAllItems();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: ~eCMenu() override;
    public: void OnParentNotify(GEU32, GEU32, GEU32, GEI32 *) override;
    protected: void OnRender() override;
    public: bEResult Create(GEU32, bCRect const &, GEU32, eCWnd *) override;
    public: GEInt OnKeyDown(eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const &) override;
    public: void OnLButtonDown(GEU32, bCPoint) override;
    public: void OnMouseMove(GEU32, bCPoint) override;
    public: void OnMouseWheel(GEU32, GEI8, bCPoint) override;
    // clang-format on

  public:
    static eCMenu *GE_STDCALL S_AccessMenuByID(GEU32);
    static eCMenu *GE_STDCALL S_AccessMenuByName(bCString const &);
    static eCMenu const *GE_STDCALL S_GetMenuByID(GEU32);
    static eCMenu const *GE_STDCALL S_GetMenuByName(bCString const &);

  public:
    eCMenu(eCMenu const &);
    eCMenu();

  public:
    eCMenu &operator=(eCMenu const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCMenu const &);
    void CopyTo(eCMenu &) const;

  protected:
    void Invalidate();
};
