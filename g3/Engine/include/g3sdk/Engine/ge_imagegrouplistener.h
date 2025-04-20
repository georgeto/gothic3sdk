#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCImageGroupListener
{
    // clang-format off
    protected: virtual void __purecall_0() = 0;
    // clang-format on

  public:
    eCImageGroupListener(eCImageGroupListener const &);
    eCImageGroupListener();

  public:
    eCImageGroupListener &operator=(eCImageGroupListener const &);
};
