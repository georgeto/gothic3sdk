#pragma once

#include <Engine/io/console/ge_consolecommands.h>
#include <Engine/io/console/ge_consoledlg.h>

#include <SharedBase.h>

class eCCommandManager;

#pragma pack(push, 1)
class eCConsoleEventArg
{
  public:
    GEInt field_0;
    GEInt field_4;
    GEInt field_8;
    GEInt field_C;
    GEInt field_10;
    GEInt field_14;
    bCString commandLine;
    GEInt field_1C;
    GEInt field_20;
    GEInt field_24;
    GEBool success;
};
#pragma pack(pop)

struct eSReadmeItem
{
    GE_UNIMPL_STRUCT(eSReadmeItem)
};

class GE_DLLIMPORT eCConsole : public eCConsoleDlg
{
    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    protected: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCConsole() override;
    public: eCInputReceiver::eEInputPriority GetInputPriority() const override;
    public: void Process() override;
    public: void OnParentNotify(GEU32, GEU32, GEU32, GEI32 *) override;
    public: GEInt OnKeyDown(eCInpShared::eEKeyboardStateOffset, eCInpShared::eSInputMessage const &) override;
    protected: void OnFinishedOpening() override;
    protected: void OnFinishedClosing() override;
    protected: GEBool OnExecute(bCString const &, bCString &) override;
    protected: GEBool OnComplete(bCString &) override;
    public: void PrintChoices(bCString const &) override;
    // clang-format on

  public:
    using eCWnd::OnCommand;

  public:
    static eCConsole &GE_STDCALL AccessConsole();
    static eCConsole const &GE_STDCALL GetConsole();

  public:
    eCConsole(eCConsole const &);
    eCConsole();

  public:
    eCConsole &operator=(eCConsole const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void AddArgument(bCString const &, bCString const &, eEConsoleDataType, GEU64, bCString const &);
    void AddCommand(bCString const &a_strName, bCString const &a_strDescription, bCDelegateBase *, GEU64,
                    bCString const &);
    void AddFunction(bCString const &, bCString const &, bCDelegateBase *, GEU64, bCString const &);
    void AddProperty(bCString const &, bCString const &, eEConsoleDataType, bCDelegateBase *, GEU64, bCString const &);
    void BeginAddClass(bCString const &, bCString const &, bCDelegateBase *);
    void Close();
    void CopyFrom(eCConsole const &);
    void CopyTo(eCConsole &) const;
    void EndAddClass(bCString const &);
    bTObjArraySort<eSReadmeItem> const &GetAllCommands() const;
    GEBool IsOpen();
    GEBool IsTyping() const;
    void Open();
    void PrintOutput(bCString const &, bCByteAlphaColor const &);
    void Remove(bCString const &);
    void Remove(bCDelegateBase *, GEBool);
    void SetIsTyping(GEBool);

  protected:
    static eCConsole *ms_pThis;

  protected:
    eCCommandManager &AccessCommandManager();
    eCCommandManager const &GetCommandManager() const;
    void GetCommandManager(eCCommandManager &) const;
    void Invalidate();
    void SetCommandManager(eCCommandManager const &);

  private:
    void GE_STDCALL OnCommand(bCObjectRefBase *, eCConsoleEventArg *);
    void RegisterCommands();
};
