#pragma once

#include <SharedBase.h>

class eCConsoleCommands;
class eCConsoleDlg;
class eCObjectInspectorDlg;
class eCScopeInstance;

enum eEScopeType
{
    // TODO: Enumerator values
};

class eCScope
{
    GE_UNIMPL_STRUCT(eCScope)
};

class eCScopeClass
{
    GE_UNIMPL_STRUCT(eCScopeClass)
};

struct eSDispatchableClass
{
    GE_UNIMPL_STRUCT(eSDispatchableClass)
};

class GE_DLLIMPORT eCCommandManager
{
  public:
    eCCommandManager(eCCommandManager const &);
    eCCommandManager();
    ~eCCommandManager();

  public:
    eCCommandManager &operator=(eCCommandManager const &);
    bCOStream &operator>>(bCOStream &) const;
    bCIStream &operator<<(bCIStream &);

  public:
    eCConsoleCommands &AccessCommands();
    GEBool AddScope(bCString const &, bCString const &, bCString const &);
    GEBool Complete(bCString &, GEInt);
    void CopyFrom(eCCommandManager const &);
    void CopyTo(eCCommandManager &) const;
    GEBool Create();
    eCObjectInspectorDlg *CreateObjectInspector(eCScopeInstance *);
    void Destroy();
    GEBool Execute(bCString const &, bCString &, eCConsoleDlg &);
    eCConsoleCommands const &GetCommands() const;
    void GetCommands(eCConsoleCommands &) const;
    eCScope *GetCurrentScope() const;
    GEInt GetNumEqualCommands(bCString const &);
    eCScope *GetScope(bCString const &) const;
    eCScope *GetScope(bCString const &, eEScopeType) const;
    GEBool KillInstance(eCScopeInstance *);
    void PrintChoices(bCString const &);
    GEBool Read(bCIStream &);
    eCScopeClass *RegisterClassA(eSDispatchableClass const &);
    GEBool SelectScope(bCString const &);
    GEBool SelectScope(eCScope *);
    void SetCommands(eCConsoleCommands const &);
    eCScopeInstance *SpawnInstance(bCString const &, bCString const &, eCConsoleDlg *);
    void Write(bCOStream &) const;

  protected:
    static bCString m_strScopeDelimiter;

  protected:
    static bCString &GE_STDCALL GetScopeDelimiter();

  protected:
    GEBool ExecuteRecursive(bCString const &, bCString &, eCConsoleDlg &, bCVariant &);
    GEBool InternExecute(bCString const &, bCString &, eCConsoleDlg &);
    void Invalidate();
    void PrintClassList(eCScope const *, eCConsoleDlg &, GEInt) const;
    void PrintFilteredScopeList(eCScope const *, eCConsoleDlg &, GEInt, eEScopeType) const;
    void PrintInstanceList(eCScope const *, eCConsoleDlg &, GEInt) const;
    void PrintScope(eCConsoleDlg &) const;
    void PrintScopeList(eCScope const *, eCConsoleDlg &, GEInt) const;
    GEBool ScopeExecute(bCString const &, bCString &, eCConsoleDlg &);
};
