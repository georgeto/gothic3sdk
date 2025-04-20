#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>
#include <SharedBase/types/ge_windows.h>

class bCCriticalSectionWin32;

class GE_DLLIMPORT bCSpyAdmin
{
  public:
    static bCSpyAdmin &GE_STDCALL GetInstance();

  public:
    ~bCSpyAdmin();

  public:
    bCSpyAdmin const &operator=(bCSpyAdmin const &);

  public:
    void Create();
    bCCriticalSectionWin32 &GetCriticalSection();
    HWND GetSpyHandle();
    GELPVoid GetSpyMutex();

  protected:
    bCSpyAdmin(bCSpyAdmin const &);
    bCSpyAdmin();

  protected:
    void Destroy();
    void Invalidate();
};
