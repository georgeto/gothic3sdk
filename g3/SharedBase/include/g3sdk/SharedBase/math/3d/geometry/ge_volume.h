#pragma once

#include <SharedBase/types/ge_def.h>

class GE_DLLIMPORT bCVolume
{
    // clang-format off
    protected: virtual void __purecall_0() = 0;
    protected: virtual void __purecall_1() = 0;
    protected: virtual void __purecall_2() = 0;
    protected: virtual void __purecall_3() = 0;
    protected: virtual void __purecall_4() = 0;
    protected: virtual void __purecall_5() = 0;
    protected: virtual void __purecall_6() = 0;
    protected: virtual void __purecall_7() = 0;
    protected: virtual void __purecall_8() = 0;
    protected: virtual void __purecall_9() = 0;
    protected: virtual void __purecall_10() = 0;
    protected: virtual void __purecall_11() = 0;
    protected: virtual void __purecall_12() = 0;
    protected: virtual void __purecall_13() = 0;
    public: virtual ~bCVolume();
    // clang-format on

  public:
    bCVolume(bCVolume const &);
    bCVolume();

  public:
    bCVolume &operator=(bCVolume const &);
};

template <typename T>
class bTVolume : public bCVolume
{
    GE_UNIMPL_STRUCT(bTVolume)
};
