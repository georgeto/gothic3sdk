#pragma once

#include <SharedBase/kernel/thread/ge_threadwin32.h>

class GE_DLLIMPORT bCThreadWin32Ex : public bCThreadWin32
{
    // clang-format off
    protected: virtual void __purecall_0() = 0;
    // clang-format on

  public:
    static void GE_STDCALL EnableThreads(GEBool);

  public:
    bCThreadWin32Ex(bCThreadWin32Ex const &);
    bCThreadWin32Ex();
    ~bCThreadWin32Ex();

  public:
    bCThreadWin32Ex &operator=(bCThreadWin32Ex const &);

  public:
    GEBool EndThread();
    void SleepThread(GEU32);
    GEBool StartThread();
    void WaitIfThreadFinished();

  protected:
    static GEBool ms_bEnableThreads;

  protected:
    static GEU32 GE_STDCALL ThreadFunc(GELPVoid);
};
