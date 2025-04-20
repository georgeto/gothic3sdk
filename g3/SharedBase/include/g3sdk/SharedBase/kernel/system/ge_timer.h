#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class GE_DLLIMPORT bCTimer
{
  public:
    static void GE_STDCALL EnableSafeTimer(GEBool);
    // Retrieves the number of milliseconds that have elapsed since the system was started, internally uses
    // GetTickCount().
    static GEU32 GE_STDCALL GetTimeStamp();
    static GEU64 GE_STDCALL QueryPerformanceCounter();
    static GEU64 GE_STDCALL QueryPerformanceFrequency();

  public:
    bCTimer(bCTimer const &);
    bCTimer();
    ~bCTimer();

  public:
    bCTimer &operator=(bCTimer const &);

  public:
    void Adjust(GEFloat);
    void GetLastTime(GEFloat &) const;
    void GetTime(GEFloat &);
    void GetTimeDifference(GEFloat &) const;
    void Pause();
    void Reset();
    void Resume();
    void Set(GEFloat);
};
