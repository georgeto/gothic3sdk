#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class GE_DLLIMPORT bCFPUAdmin
{
  public:
    static bCFPUAdmin &GE_STDCALL GetInstance();

  public:
    ~bCFPUAdmin();

  public:
    void Create();
    void EnableDenormalFloatExceptions(GEBool);
    void EnableInvalidFloatExceptions(GEBool);
    void EnableOverflowExceptions(GEBool);
    void EnableUnderflowExceptions(GEBool);
    void EnableZeroDevideExceptions(GEBool);
    GEU32 GetCurrentControlWord();
    void PrintStatus();
    void RestoreDefaultControlWord();
    void RestoreSavedControlWord();
    void SaveCurrentControlWord();
    void SetControlWord(GEU32);
    void SetHighPrecision();
    void SetLowPrecision();
    void SetMidPrecision();

  protected:
    bCFPUAdmin(bCFPUAdmin const &);
    bCFPUAdmin();

  protected:
    bCFPUAdmin const &operator=(bCFPUAdmin const &);

  protected:
    void Destroy();
    void Invalidate();

  private:
    void ComputeDefaultControlWord();
};
