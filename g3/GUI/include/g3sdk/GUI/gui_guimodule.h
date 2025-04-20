#pragma once

#include <GUI/gui_modulegui.h>

#include <SharedBase.h>

class CFFGUI
{
    GE_UNIMPL_STRUCT(CFFGUI)
};

class GE_DLLIMPORT CFFGUIModule : public CFFUnknown, public virtual IFFModuleGUI
{
    // clang-format off
    protected: virtual GEU32 OnCreate();
    protected: virtual void OnDestroy();
    public: virtual IFFGUIRenderer * GetRenderer() const;
    public: virtual void EndDrag();
    // Overrides for CFFUnknown
    public: ~CFFGUIModule() override;
    // Overrides for IFFUnknown
    public: GEU32 AddRef() override;
    public: GEU32 Release() override;
    public: GEU32 QueryInterface(FFGUID const &, GELPVoid*) override;
    // Overrides for IFFModuleGUI
    public: void SetRenderer(IFFGUIRenderer *) override;
    public: GEBool IsEnabled() const override;
    public: GEBool IsInputEnabled() const override;
    public: GEBool IsRenderEnabled() const override;
    public: void Enable(GEBool) override;
    public: void EnableInput(GEBool) override;
    public: void EnableRender(GEBool) override;
    public: GEBool Process(GEFloat) override;
    public: GEBool Draw() override;
    public: GEBool HandleMessage(GELPVoid, GEUInt, GEUInt, GEUInt) override;
    public: IFFGUIWindow * CreateWnd(GEInt, IFFGUIWindow *, IFFGUIMsgProc *) override;
    public: IFFGUIWindow * CreateWnd(bCString const &, IFFGUIWindow *, IFFGUIMsgProc *) override;
    public: IFFGUIWindow * CreateWnd(bCString const &, bCUnicodeString const &, GEU32, GEInt, GEInt, GEInt, GEInt, IFFGUIWindow *, GEInt, IFFGUIMsgProc *) override;
    public: void DestroyWnd(IFFGUIWindow *) override;
    public: GEInt SendMessage(IFFGUIWindow *, GEUInt, GEUInt, GEUInt) override;
    public: GEInt DefMsgProc(IFFGUIWindow *, GEUInt, GEUInt, GEUInt) override;
    public: IFFGUIWindow * GetDesktopWnd() override;
    public: IFFGUIWindow * GetActiveWnd() override;
    public: IFFGUIWindow * GetFocusWnd() override;
    public: IFFGUIWindow * WindowFromPoint(bCPoint const &, GEU32) override;
    public: void BeginDrag(IFFGUIWindow *) override;
    public: void ShowCursor(GEBool) override;
    public: GEBool ResizeDesktop(GEInt, GEInt) override;
    public: IFFGUIResourceNode * GetFirstResourcePos(EFFGUIResource) const override;
    public: IFFGUIResourceNode * GetNextResourceID(IFFGUIResourceNode *, bCString &, GEInt &) const override;
    public: IFFGUIResourceNode * FindResourceNode(EFFGUIResource, GEInt) const override;
    public: IFFGUIResourceNode * FindResourceNode(EFFGUIResource, bCString const &) const override;
    public: IFFGUIResourceNode * InsertResource(IFFGUIBitmap *, bCString &, GEInt &) override;
    public: IFFGUIResourceNode * InsertResource(IFFGUICursor *, bCString &, GEInt &) override;
    public: IFFGUIResourceNode * InsertResource(IFFGUITheme *, bCString &, GEInt &) override;
    public: IFFGUIResourceNode * InsertResource(IFFGUIWindow *, bCString &, GEInt &) override;
    public: IFFGUIResourceNode * UpdateResourceA(bCString const &, IFFGUIBitmap *) override;
    public: IFFGUIResourceNode * UpdateResourceA(bCString const &, IFFGUICursor *) override;
    public: IFFGUIResourceNode * UpdateResourceA(bCString const &, IFFGUITheme *) override;
    public: IFFGUIResourceNode * UpdateResourceA(bCString const &, IFFGUIWindow *) override;
    public: IFFGUIResourceNode * RenameResource(bCString const &, bCString const &) override;
    public: GEBool DeleteResource(bCString const &) override;
    public: GEBool ReadResources(bCString const &) override;
    public: GEBool WriteResources(bCString &) const override;
    public: IFFGUIBitmap * CreateBitmap() override;
    public: IFFGUIImageList * CreateImageList() override;
    public: void DestroyBitmap(IFFGUIBitmap *) override;
    public: void DestroyImageList(IFFGUIImageList *) override;
    public: GEInt GetThemeCount() const override;
    public: IFFGUITheme * GetThemeAt(GEInt) const override;
    public: IFFGUITheme * GetActiveTheme() const override;
    public: IFFGUITheme * CreateTheme(bCString const &) override;
    public: IFFGUITheme * LoadTheme(bCString const &) override;
    public: GEBool SaveTheme(IFFGUITheme *) override;
    public: GEBool SelectTheme(IFFGUITheme *) override;
    public: void DestroyTheme(IFFGUITheme *) override;
    // clang-format on

  public:
    static CFFGUIModule &GE_STDCALL GetInstance();

  public:
    CFFGUIModule(CFFGUIModule const &);

  public:
    CFFGUIModule &operator=(CFFGUIModule const &);

  public:
    GEFloat GetFrameTime() const;
    CFFGUI &GetGUI();
    GEFloat GetTimeStamp() const;

  protected:
    CFFGUIModule();

  protected:
    GEBool Create();
    void Destroy();
};
