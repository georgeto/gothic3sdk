#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCCriticalSectionWin32;

class GE_DLLIMPORT bCSpieAdmin
{
  public:
    static bCSpieAdmin &GE_STDCALL GetInstance();

  public:
    ~bCSpieAdmin();

  public:
    bCSpieAdmin const &operator=(bCSpieAdmin const &);

  public:
    void Create();
    bCCriticalSectionWin32 &GetCriticalSection();
    GEBool Send(GELPVoid const, GEU32);

  protected:
    bCSpieAdmin(bCSpieAdmin const &);
    bCSpieAdmin();

  protected:
    void Destroy();
    void Invalidate();
};
