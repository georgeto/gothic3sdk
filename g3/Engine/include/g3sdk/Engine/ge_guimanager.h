#pragma once

#include <Engine/ge_enginecomponentbase.h>

#include <SharedBase.h>

class eCColorScheme;
class eCDesktop;
class eCWnd;

class GE_DLLIMPORT eCGUIManager : public eCEngineComponentBase
{
    // clang-format off
    protected: virtual GEInt OnMouse(eCWnd *, eCInpShared::eSInputMessage const &);
    protected: virtual GEInt OnKeyboard(eCWnd *, eCInpShared::eSInputMessage const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: GEU32 const GetProfileLastTicksFirst() const override;
    public: GEU32 const GetProfileLastTicksSecond() const override;
    public: ~eCGUIManager() override;
    public: eCInputReceiver::eEInputPriority GetInputPriority() const override;
    public: GEInt OnKeyboard(eCInpShared::eSInputMessage const &) override;
    public: GEInt OnMouse(eCInpShared::eSInputMessage const &) override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: void Process() override;
    public: void OnPostRender() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCGUIManager, eCEngineComponentBase)

  public:
    static eCGUIManager &GE_STDCALL AccessGUIManager();
    static eCGUIManager const &GE_STDCALL GetGUIManager();
    static eCGUIManager &GE_STDCALL GetInstance();

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    eCColorScheme &AccessColorScheme();
    eCWnd *AccessWindowByDelegate(bCDelegateBase *, GEBool);
    eCWnd *AccessWindowByID(GEU32);
    eCWnd *AccessWindowByName(bCString const &);
    void AddModalWindow(eCWnd *);
    void CopyFrom(eCGUIManager const &);
    void CopyTo(eCGUIManager &) const;
    GEU32 DoModalMessageBox(bCString const &, bCString const &, GEBool);
    eCWnd *GetActiveWindow();
    eCWnd const *GetActiveWindow() const;
    void GetActiveWindow(eCWnd *&) const;
    eCColorScheme const &GetColorScheme() const;
    eCDesktop *GetDesktopWindow();
    eCDesktop const *GetDesktopWindow() const;
    void GetDesktopWindow(eCDesktop *&) const;
    eCWnd *GetFocus();
    eCWnd const *GetFocus() const;
    GEBool GetShowPointer() const;
    eCWnd const *GetWindowByDelegate(bCDelegateBase *, GEBool) const;
    eCWnd const *GetWindowByID(GEU32) const;
    eCWnd const *GetWindowByName(bCString const &) const;
    void OnSysColorChange();
    void ReSize();
    void RegisterDesktopClick(bCDelegateBase *);
    void RemoveModalWindow(eCWnd *);
    void SetFocus(eCWnd *);
    void SetShowPointer(GEBool);
    eCWnd *WindowFromPoint(bCPoint const &) const;

  protected:
    static eCGUIManager *ms_pCurrentGUIManager;

  protected:
    eCWnd *&AccessActiveWindow();
    eCDesktop *&AccessDesktopWindow();
    eCWnd *&AccessFocus();
    void BringWindowToTop(eCWnd *);
    void CloseSubMenus();
    void FlushQueuedWindows();
    void GetColorScheme(eCColorScheme &) const;
    void Insert(eCWnd *);
    void Invalidate();
    void Remove(eCWnd *, GEBool);
    void SetActiveWindow(eCWnd *);
    void SetColorScheme(eCColorScheme const &);
    void SetDesktopWindow(eCDesktop *);

  private:
    GE_UNIMPL_MEMBERS(164)
};

GE_ASSERT_SIZEOF(eCGUIManager, 0xb8)
