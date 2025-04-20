#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>
#include <SharedBase/types/ge_windows.h>

class GE_DLLIMPORT bCThreadWin32
{
  public:
    enum bEThreadPriority
    {
        bEThreadPriority_LOWEST = 0xFFFFFFFE,
        bEThreadPriority_BELOW_NORMAL = 0xFFFFFFFF,
        bEThreadPriority_NORMAL = 0x00000000,
        bEThreadPriority_HIGHEST = 0x00000002,
        bEThreadPriority_ABOVE_NORMAL = 0x00000001,
        bEThreadPriority_ERROR_RETURN = 0x7FFFFFFF,
        bEThreadPriority_TIME_CRITICAL = 0x0000000F,
        bEThreadPriority_IDLE = 0xFFFFFFF1,
    };

  public:
    struct bSThreadContext
    {
      public:
        bSThreadContext();

      public:
        bSThreadContext &operator=(bSThreadContext const &);

      public:
        GEInt iThreadIdentifier;
        GELPVoid pUserData;
    };

  public:
    bCThreadWin32();
    ~bCThreadWin32();

  public:
    bCThreadWin32 &operator=(bCThreadWin32 const &);

  public:
    GEBool Create(bSThreadContext const &, GEU32(GE_STDCALL *)(GELPVoid));
    void Destroy();
    GELPVoid GetHandle() const;
    GEBool IsValid() const;
    void SetPriority(bEThreadPriority);

  private:
    HANDLE m_Handle;
    bSThreadContext m_Context;
};

GE_ASSERT_SIZEOF(bCThreadWin32, 0xc)
