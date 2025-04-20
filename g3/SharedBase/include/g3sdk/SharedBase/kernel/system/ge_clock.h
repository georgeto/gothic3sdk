#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

struct bSClockAdjustment
{
    GEFloat fFactor;
    GEUInt uSecondsPerDay;
    GEUInt uDayPerYear;
};

struct bSTimeAndDate
{
    GEUInt uYear;
    GEUInt uDayOfYear;
    GEUInt uSecondsOfDay;
};

class GE_DLLIMPORT bCClock
{
  public:
    bCClock(bCClock const &);
    bCClock();
    ~bCClock();

  public:
    bCClock &operator=(bCClock const &);

  public:
    void Adjust(bSClockAdjustment const &);
    void GetTimeAndDate(bSTimeAndDate &);
    GEBool IsPaused() const;
    void Pause();
    void Resume();
    void Set(bSTimeAndDate const &);

  private:
    bSClockAdjustment m_ClockAdjustment;
    bSTimeAndDate m_TimeAndDate;
    GEInt m_iLastTimestamp;
    GEFloat m_fCurrentTime;
    GEBool m_bPaused;
    GE_PADDING(0x3)
};
