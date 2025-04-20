#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>
#include <SharedBase/types/ge_windows.h>

class GE_DLLIMPORT bCCriticalSectionWin32
{
  public:
    bCCriticalSectionWin32();
    ~bCCriticalSectionWin32();

  public:
    bCCriticalSectionWin32 &operator=(bCCriticalSectionWin32 const &);

  public:
    void Acquire();
    GEU32 GetLockCount() const;
    void Release();
    void SetSpinCount(GEU32);
    GEBool TryAcquire();

  private:
    CRITICAL_SECTION m_CriticalSection;
};
