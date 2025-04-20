#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

struct bSAllocationItem
{
    GE_UNIMPL_STRUCT(bSAllocationItem)
};

class GE_DLLIMPORT bCGothic3EngineDialogs
{
  public:
    enum bEGE3DialogsLogMessageType
    {
        bEGE3DialogsLogMessageType_Error = 1,
        bEGE3DialogsLogMessageType_ErrorHistory,
        bEGE3DialogsLogMessageType_ErrorMemory,
        bEGE3DialogsLogMessageType_ErrorCallstack,
        bEGE3DialogsLogMessageType_FileNotUnique,
        bEGE3DialogsLogMessageType_ForceDWORD = GE_FORCE_DWORD
    };

  public:
    class bCDialogHandle
    {
      public:
        bCDialogHandle &operator=(bCDialogHandle const &);

      public:
        void AddItemToMemoryOverview(bSAllocationItem const *, GEBool);
        GEU16 AddReference();
        GEBool AddText(bEGE3DialogsLogMessageType, GELPCChar);
        GEBool CreateErrorDialog(GEBool);
        GEBool CreateFileNotUniqueDialog();
        GEBool CreateMemoryDialog();
        GEBool DestroyErrorDialog();
        GEBool DestroyFileNotUniqueDialog();
        GEBool DestroyMemoryDialog();
        void GetErrorDialogState(GEBool &, GEBool &);
        GEU16 GetReferenceCount() const;
        GEU16 ReleaseReference();
        GEBool ShowModalErrorDialog();
        GEBool ShowModalFileNotUniqueDialog();
        GEBool ShowModalMemoryDialog();

      protected:
        bCDialogHandle();
        ~bCDialogHandle();

      protected:
        void Invalidate();
    };

  public:
    bCGothic3EngineDialogs();
    ~bCGothic3EngineDialogs();

  public:
    bCGothic3EngineDialogs &operator=(bCGothic3EngineDialogs const &);

  public:
    bCDialogHandle &GetDialogHandle() const;
    GEBool IsLoaded() const;
    GEBool LoadGE3DialogLib(GEBool);
    void UnloadGE3DialogLib();
};
