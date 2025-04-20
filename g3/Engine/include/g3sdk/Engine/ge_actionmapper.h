#pragma once

#include <Engine/io/ge_inputreceiver.h>

#include <SharedBase.h>

class eCMenuItem;

class eCPhysicalKey : public bCObjectRefBase
{
  public:
    eCInpShared::eEKeyboardStateOffset m_enuKeyboardStateOffset;
    GEInt m_iPriority;
    bCUnicodeString m_strLocalizedKeyName;
};
GE_ASSERT_SIZEOF(eCPhysicalKey, 0x18)

class eCLogicalKey
{
    GE_UNIMPL_STRUCT(eCLogicalKey)
};

struct eSActionMapping
{
    GE_UNIMPL_STRUCT(eSActionMapping)
};

class eCActionEvent : public bCEvent
{
  public:
    eCLogicalKey *m_pLogicalKey;
    eCPhysicalKey *m_pPhysicalKey;
    GEBool m_bKeyOn;
    GEBool m_bKeyOnBefore;
    GEInt m_iSomeIndex;
};
GE_ASSERT_SIZEOF(eCActionEvent, 0x28)

struct eSScriptEvent
{
    GE_UNIMPL_STRUCT(eSScriptEvent)
};

class GE_DLLIMPORT eCActionMapper : public eCInputReceiver
{
    // clang-format off
    public: virtual void Process();
    public: virtual void OnStartup();
    public: virtual void OnPreProcess();
    public: virtual void OnPostProcess();
    public: virtual void OnPreRender();
    public: virtual void OnPostRender();
    public: virtual void OnShutDown();
    public: virtual void OnWorldActivated();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCActionMapper() override;
    public: GEInt OnKeyboard(eCInpShared::eSInputMessage const &) override;
    public: GEInt OnMouse(eCInpShared::eSInputMessage const &) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCActionMapper, eCInputReceiver)

  public:
    static eCActionMapper *ms_pInstance;

  public:
    static eCActionMapper &GE_STDCALL GetInstance();

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    // ActionMapper tries to find a keybinding for the event using its name as a key into the DebugControls section of
    // ini/controls.ini. When a_u32SubmenuId is specified the action mapper creates a menu item for the event in the
    // corresponding menu (menus are created in eCApplication::CreateMainMenu). When a_strConsoleCommandName is
    // specified the action mapper creates a console command for the event. Arguments for the a_pDelegateBase:
    //   a_pInvoker can be of any type, most of the time it is a window, the GuiManager or menu item.
    //   a_pEvent is a subclass of eCEvent
    eCMenuItem *AddEvent(bCString const &a_strName, bCDelegateBase *a_pDelegateBase, GEU32 a_u32SubmenuId = 0xFFFFFFFF,
                         GEU32 a_u32EventId = 0xFFFFFFFF, bCString const &a_strConsoleCommandName = g_strDefault,
                         bCString const &a_strConsoleCommandDescription = g_strDefault);
    // Use this function when adding events after eCActionMapper::OnStartup has been executed, to force reexecution of
    // eCActionMapper::ParseEvents. Otherwise Keybindings won't work. (See also RegisterScriptEvent)
    eCMenuItem *AddLazyEvent(bCString const &a_strName, bCDelegateBase *a_pDelegateBase,
                             GEU32 a_u32SubmenuId = 0xFFFFFFFF, GEU32 a_u32EventId = 0xFFFFFFFF,
                             bCString const &a_strConsoleCommandName = g_strDefault,
                             bCString const &a_strConsoleCommandDescription = g_strDefault);
    void ClearOccuredEvents();
    void CopyFrom(eCActionMapper const &);
    void CopyTo(eCActionMapper &) const;
    void EnableDelegates(GEBool);
    GEBool GetDebugMode() const;
    bTPtrArray<eCPhysicalKey *> const &GetMapping(eCLogicalKey const &) const;
    GEBool GetMapping(eCPhysicalKey const &, eCLogicalKey &) const;
    GEU32 GetNumOccuredEvents();
    eCInpShared::eSGameKeyMessage const &GetOccuredEvent(GEU32) const;
    void Invalidate();
    GEBool IsMapped(eCLogicalKey const &) const;
    void ParseEvents(bCString const &, GEBool);
    void ParseScriptEvents();
    void RegisterScriptEvent(eSScriptEvent &);
    void RemoveEvent(bCString const &);
    void SetDebugMode(GEBool);
    eSActionMapping *SetMapping(eCLogicalKey &, bTPtrArray<eCPhysicalKey *> &, GEBool const &, GEFloat const &);

  protected:
    bCString GetEventConfigValue(bCString const &);
    GEU32 OccuredIndexToMapIndex(GEU32) const;

  private:
    GE_UNIMPL_MEMBERS(284)
};

GE_ASSERT_SIZEOF(eCActionMapper, 0x12c)
