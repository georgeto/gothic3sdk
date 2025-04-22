#pragma once

#include <SharedBase.h>

class IFFGUIMsgProc;
class IFFGUIRenderer;

enum EFFGUIResource
{
    // TODO: Enumerator values
};

class IFFGUIBitmap
{
    GE_UNIMPL_STRUCT(IFFGUIBitmap)
};

class IFFGUICursor
{
    GE_UNIMPL_STRUCT(IFFGUICursor)
};

class IFFGUIImageList
{
    GE_UNIMPL_STRUCT(IFFGUIImageList)
};

class IFFGUIResourceNode
{
    GE_UNIMPL_STRUCT(IFFGUIResourceNode)
};

class IFFGUITheme
{
    GE_UNIMPL_STRUCT(IFFGUITheme)
};

class IFFGUIWindow
{
    GE_UNIMPL_STRUCT(IFFGUIWindow)
};

class IFFGUIDeviceContext
{
    GE_UNIMPL_STRUCT(IFFGUIDeviceContext)
};

class IFFModuleGUI : public virtual IFFUnknown
{
    // clang-format off
    public: virtual void SetRenderer(IFFGUIRenderer *) = 0;
    public: virtual GEBool IsEnabled() const = 0;
    public: virtual GEBool IsInputEnabled() const = 0;
    public: virtual GEBool IsRenderEnabled() const = 0;
    public: virtual void Enable(GEBool) = 0;
    public: virtual void EnableInput(GEBool) = 0;
    public: virtual void EnableRender(GEBool) = 0;
    public: virtual GEBool Process(GEFloat) = 0;
    public: virtual GEBool Draw() = 0;
    public: virtual GEBool HandleMessage(GELPVoid, GEUInt, GEUInt, GEUInt) = 0;
    public: virtual IFFGUIWindow * CreateWnd(GEInt, IFFGUIWindow *, IFFGUIMsgProc *) = 0;
    public: virtual IFFGUIWindow * CreateWnd(bCString const &, IFFGUIWindow *, IFFGUIMsgProc *) = 0;
    public: virtual IFFGUIWindow * CreateWnd(bCString const &, bCUnicodeString const &, GEU32, GEInt, GEInt, GEInt, GEInt, IFFGUIWindow *, GEInt, IFFGUIMsgProc *) = 0;
    public: virtual void DestroyWnd(IFFGUIWindow *) = 0;
    public: virtual GEInt SendMessage(IFFGUIWindow *, GEUInt, GEUInt, GEUInt) = 0;
    public: virtual GEInt DefMsgProc(IFFGUIWindow *, GEUInt, GEUInt, GEUInt) = 0;
    public: virtual IFFGUIWindow * GetDesktopWnd() = 0;
    public: virtual IFFGUIWindow * GetActiveWnd() = 0;
    public: virtual IFFGUIWindow * GetFocusWnd() = 0;
    public: virtual IFFGUIWindow * WindowFromPoint(bCPoint const &, GEU32) = 0;
    public: virtual void BeginDrag(IFFGUIWindow *) = 0;
    public: virtual void ShowCursor(GEBool) = 0;
    public: virtual GEBool ResizeDesktop(GEInt, GEInt) = 0;
    public: virtual IFFGUIResourceNode * GetFirstResourcePos(EFFGUIResource) const = 0;
    public: virtual IFFGUIResourceNode * GetNextResourceID(IFFGUIResourceNode *, bCString &, GEInt &) const = 0;
    public: virtual IFFGUIResourceNode * FindResourceNode(EFFGUIResource, GEInt) const = 0;
    public: virtual IFFGUIResourceNode * FindResourceNode(EFFGUIResource, bCString const &) const = 0;
    public: virtual IFFGUIResourceNode * InsertResource(IFFGUIBitmap *, bCString &, GEInt &) = 0;
    public: virtual IFFGUIResourceNode * InsertResource(IFFGUICursor *, bCString &, GEInt &) = 0;
    public: virtual IFFGUIResourceNode * InsertResource(IFFGUITheme *, bCString &, GEInt &) = 0;
    public: virtual IFFGUIResourceNode * InsertResource(IFFGUIWindow *, bCString &, GEInt &) = 0;
    public: virtual IFFGUIResourceNode * UpdateResourceA(bCString const &, IFFGUIBitmap *) = 0;
    public: virtual IFFGUIResourceNode * UpdateResourceA(bCString const &, IFFGUICursor *) = 0;
    public: virtual IFFGUIResourceNode * UpdateResourceA(bCString const &, IFFGUITheme *) = 0;
    public: virtual IFFGUIResourceNode * UpdateResourceA(bCString const &, IFFGUIWindow *) = 0;
    public: virtual IFFGUIResourceNode * RenameResource(bCString const &, bCString const &) = 0;
    public: virtual GEBool DeleteResource(bCString const &) = 0;
    public: virtual GEBool ReadResources(bCString const &) = 0;
    public: virtual GEBool WriteResources(bCString &) const = 0;
    public: virtual IFFGUIBitmap * CreateBitmap() = 0;
    public: virtual IFFGUIImageList * CreateImageList() = 0;
    public: virtual void DestroyBitmap(IFFGUIBitmap *) = 0;
    public: virtual void DestroyImageList(IFFGUIImageList *) = 0;
    public: virtual GEInt GetThemeCount() const = 0;
    public: virtual IFFGUITheme * GetThemeAt(GEInt) const = 0;
    public: virtual IFFGUITheme * GetActiveTheme() const = 0;
    public: virtual IFFGUITheme * CreateTheme(bCString const &) = 0;
    public: virtual IFFGUITheme * LoadTheme(bCString const &) = 0;
    public: virtual GEBool SaveTheme(IFFGUITheme *) = 0;
    public: virtual GEBool SelectTheme(IFFGUITheme *) = 0;
    public: virtual void DestroyTheme(IFFGUITheme *) = 0;
    // clang-format on
};
