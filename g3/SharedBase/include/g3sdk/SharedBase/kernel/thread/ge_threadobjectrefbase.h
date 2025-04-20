#pragma once

#include <SharedBase/kernel/object/ge_objectrefbase.h>
#include <SharedBase/kernel/thread/ge_threadwin32ex.h>

class bCCriticalSectionWin32;

class GE_DLLIMPORT bCThreadObjectRefBase : public bCObjectRefBase, public bCThreadWin32Ex
{
    // clang-format off
    public: ~bCThreadObjectRefBase() override;
    // clang-format on

  public:
    bCThreadObjectRefBase(bCThreadObjectRefBase const &);
    bCThreadObjectRefBase();

  public:
    bCThreadObjectRefBase &operator=(bCThreadObjectRefBase const &);

  public:
    bCCriticalSectionWin32 &GetCriticalSection();
    void ReleaseOwnership();
    GEBool TryToGetOwnership();
};
