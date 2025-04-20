#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class GE_DLLIMPORT bCValidateMemory
{
  public:
    static bCValidateMemory &GE_STDCALL GetInstance();

  public:
    bCValidateMemory &operator=(bCValidateMemory const &);

  public:
    GEBool GetBreakOnError() const;
    GEBool GetFatalErrorOnError() const;
    GEBool GetTraceOnError() const;
    GEBool GetWarningMessageOnError() const;
    void SetBreakOnError(GEBool);
    void SetFatalErrorOnError(GEBool);
    void SetTraceOnError(GEBool);
    void SetWarningMessageOnError(GEBool);
    void Validate();

  protected:
    bCValidateMemory();
    bCValidateMemory(GEBool, GEBool, GEBool, GEBool);
    ~bCValidateMemory();

  protected:
    void Invalidate();
};
