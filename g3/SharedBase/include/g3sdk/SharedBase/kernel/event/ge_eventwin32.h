#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class GE_DLLIMPORT bCEventWin32
{
  public:
    bCEventWin32();
    ~bCEventWin32();

  public:
    bCEventWin32 &operator=(bCEventWin32 const &);

  public:
    GELPVoid GetHandle() const;
    GEBool IsValid() const;
    void Pulse();
    void Signal();
    void Unsignal();
    void WaitForSignal(GEI32);

  protected:
    GEBool Create();
    void Destroy();
};
