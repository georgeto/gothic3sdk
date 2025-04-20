#pragma once

#include <SharedBase/kernel/error/ge_gothic3enginedialogs.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>
#include <SharedBase/types/ge_windows.h>

enum bEErrorPositionHandling
{
    bEErrorCallbackType_Pre,
    bEErrorCallbackType_Post,
    bEErrorCallbackType_Count,
    bEErrorCallbackType_ForceDWORD = GE_FORCE_DWORD
};

enum bEErrorType
{
    bEErrorType_Exception,
    bEErrorType_Fatal,
    bEErrorType_Fault,
    bEErrorType_ForceDWORD = GE_FORCE_DWORD
};

struct bSException_Pointers : public EXCEPTION_POINTERS
{};

class GE_DLLIMPORT bCErrorAdmin
{
  public:
    static bCErrorAdmin &GE_STDCALL GetInstance();

  public:
    ~bCErrorAdmin();

  public:
    void AddHistoryEntry(GELPCChar);
    GEInt CallExceptionError(bSException_Pointers *);
    GE_NORETURN void CallFatalError(GELPCChar a_strModule, GELPCChar a_strDescription, GELPCChar a_strFileName,
                                    GEInt a_iLine);
    GE_NORETURN void CallFatalError(GELPCChar a_strModule, GELPCChar a_strFileName, GEInt a_iLine);
    void CallFaultError(GELPCChar a_strModule, GELPCChar a_strDescription, GELPCChar a_strFileName, GEInt a_iLine);
    void CallFaultError(GELPCChar a_strModule, GELPCChar a_strFileName, GEInt a_iLine);
    void Create();
    void DebugBreak();
    void EnableWriteMiniDump(GEBool);
    GEBool GenerateDump(bSException_Pointers *);
    GEBool IsDebuggerPresent() const;
    GEBool IsInPanicState() const;
    GEBool IsLocked() const;
    void LockSystem();
    GEBool RegisterCallback(GEBool(GE_STDCALL *)(bEErrorType, GEU32), bEErrorPositionHandling, GEU32);
    void GE_CCALL TraceF(GELPChar, ...);
    void UnlockSystem();
    GEBool UnregisterCallback(GEBool(GE_STDCALL *)(bEErrorType, GEU32));

  protected:
    bCErrorAdmin(bCErrorAdmin const &);
    bCErrorAdmin();

  protected:
    bCErrorAdmin const &operator=(bCErrorAdmin const &);

  protected:
    void Destroy();
    void ExecuteErrorCallbacks(bEErrorPositionHandling, bEErrorType);
    void Invalidate();
    GEInt LookupCallback(bEErrorPositionHandling, GEBool(GE_STDCALL *)(bEErrorType, GEU32)) const;
    void PrintHistoryEntries();
    void PrintMemoryDumpStats();
    void PrintMessage(bCGothic3EngineDialogs::bEGE3DialogsLogMessageType, GELPCChar, GEBool);
    void PrintStackFrame(bSException_Pointers *);
};

GELPCChar GE_STDCALL GetFirstStackTraceString(GEU32, _EXCEPTION_POINTERS *);
GEInt GE_STDCALL GetFirstStackTraceStringVB(GEU32, _EXCEPTION_POINTERS *, GELPChar, GEUInt);

GELPCChar GE_STDCALL GetNextStackTraceString(GEU32, _EXCEPTION_POINTERS *);
GEInt GE_STDCALL GetNextStackTraceStringVB(GEU32, _EXCEPTION_POINTERS *, GELPChar, GEUInt);

GELPCChar GE_STDCALL GetRegisterString(_EXCEPTION_POINTERS *);
GEInt GE_STDCALL GetRegisterStringVB(_EXCEPTION_POINTERS *, GELPChar, GEUInt);

GEInt GE_STDCALL AddCrashHandlerLimitModule(HINSTANCE);
GEInt GE_STDCALL AddDiagAssertModule(HINSTANCE);
GEInt GE_STDCALL DiagAssert(GEU32, GELPCChar, GELPCChar, GEU32);
void GE_CCALL DiagOutput(GELPCChar, ...);
GELPCChar GE_STDCALL GetFaultReason(_EXCEPTION_POINTERS *);
GEInt GE_STDCALL GetFaultReasonVB(_EXCEPTION_POINTERS *, GELPChar, GEUInt);
GEUInt GE_STDCALL GetLimitModuleCount();
GEInt GE_STDCALL GetLimitModulesArray(HINSTANCE *, GEUInt);
GEInt GE_STDCALL SetCrashHandlerFilter(GEI32(GE_STDCALL *)(_EXCEPTION_POINTERS *));
GEU32 GE_STDCALL SetDiagAssertOptions(GEU32);

GE_DLLIMPORT_EXTC GEChar g_carrMsgBuffer[1024];
void GE_STDCALL SetMessageBuffer(GELPChar);
