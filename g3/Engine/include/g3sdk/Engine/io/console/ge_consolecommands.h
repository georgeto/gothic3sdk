#pragma once

#include <SharedBase.h>

class eCConsoleData;

enum eEConsoleDataType
{
    // TODO: Enumerator values
};

template <typename K, typename V>
class bTPtrTreeAVL
{
    GE_UNIMPL_STRUCT(bTPtrTreeAVL)
};

class GE_DLLIMPORT eCConsoleCommands
{
    // clang-format off
    public: virtual ~eCConsoleCommands();
    // clang-format on

  public:
    eCConsoleCommands(eCConsoleCommands const &);
    eCConsoleCommands();

  public:
    eCConsoleCommands &operator=(eCConsoleCommands const &);

  public:
    void AddArgument(bCString const &, bCString const &, eEConsoleDataType, GEU64, bCString const &);
    void AddCommand(bCString const &, bCString const &, bCDelegateBase *, GEU64, bCString const &);
    void AddFunction(bCString const &, bCString const &, bCDelegateBase *, GEU64, bCString const &);
    void AddProperty(bCString const &, bCString const &, eEConsoleDataType, bCDelegateBase *, GEU64, bCString const &);
    GEBool AutoComplete(bCString &, GEInt);
    void BeginAddClass(bCString const &, bCString const &, bCDelegateBase *);
    GEBool CheckCommandIsValid(bCString const &, eEConsoleDataType const &);
    void EndAddClass(bCString const &);
    GEBool Execute(bCString const &, bCString &);
    bTPtrTreeAVL<bCString, eCConsoleData *> *GetChildTreeNode(eCConsoleData *, bCDelegateBase const *, bCString &);
    eCConsoleData *GetClassData(bCString const &);
    GEInt GetNumEqualCommands(bCString const &);
    GEInt GetNumEqualCommands(bCString const &, bCString &);
    eCConsoleData *GetRoot();
    bTPtrTreeAVL<bCString, eCConsoleData *> *GetTreeNode(bCString const &, bCString &);
    bTPtrTreeAVL<bCString, eCConsoleData *> *GetTreeNode(bCDelegateBase const *, bCString &);
    void Help();
    void PrintChoices(bCString const &);
    void Remove(bCString const &);
    void Remove(bCDelegateBase *, GEBool);

  private:
    GEBool ExecuteClass(bCString const &, bCString &, eCConsoleData *, bCString &);
    GEBool ExecuteCommand(bCString const &, bCString &, eCConsoleData *);
    GEBool ExecuteFunction(bCString const &, bCString &, eCConsoleData *, bCString &);
    GEBool ExecuteProperty(bCString const &, bCString &, eCConsoleData *, bCString &);
    GEBool ExecuteRecursive(bCString const &, bCString &, eCConsoleData *, bCString &);
    eEConsoleDataType const GetConDataTypeOfString(bCString const &) const;
    bCString const &GetStringOfConDataType(eEConsoleDataType const &) const;
};
