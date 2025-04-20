#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

enum bEMessageCallbackPriority
{
    bEMessageCallbackPriority_Critical,
    bEMessageCallbackPriority_Normal,
    bEMessageCallbackPriority_Low,
    bEMessageCallbackPriority_Count
};

enum bEMessageFilterTypes
{
    bEMessageFilter_OK,
    bEMessageFilter_Info,
    bEMessageFilter_Warn,
    bEMessageFilter_Fault,
    bEMessageFilter_Fatal
};

enum bEMessageTypes
{
    bEMessageType_OK = 1,
    bEMessageType_Info,
    bEMessageType_Warn,
    bEMessageType_Fault,
    bEMessageType_Fatal
};

using GEFMessageCallback = GEBool(GE_STDCALL *)(bEMessageTypes, GELPCChar, GELPCChar, GEU32, GELPCChar, GEInt, GEInt);

class GE_DLLIMPORT bCMessageAdmin
{
  public:
    static bCMessageAdmin &GE_STDCALL GetInstance();

  public:
    bCMessageAdmin();
    ~bCMessageAdmin();

  public:
    bCMessageAdmin &operator=(bCMessageAdmin const &);

  public:
    void EnableLogFile(GEBool);
    bEMessageFilterTypes GetFilterType() const;
    GEBool OnMessage(bEMessageTypes, GELPCChar, GELPCChar, GELPCChar, GEInt, GEInt);
    GEBool RegisterCallback(GEFMessageCallback, bEMessageCallbackPriority, GEU32);
    void SetFilterType(bEMessageFilterTypes);
    GELPCChar StripFilename(GELPCChar);
    GEBool UnregisterCallback(GEFMessageCallback);

  protected:
    GEBool ExecuteCallbackType(bEMessageCallbackPriority, bEMessageTypes, GELPCChar, GELPCChar, GELPCChar, GEInt,
                               GEInt);
    GEInt LookupCallback(GEFMessageCallback) const;

  private:
    void Create();
    void Destroy();
    void Invalidate();
};
