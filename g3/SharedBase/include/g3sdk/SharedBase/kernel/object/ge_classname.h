#pragma once

#include <SharedBase/types/ge_string.h>

template <typename T>
class bTClassName
{
  public:
    static bCString const &GetUnmangled();

  public:
    bTClassName() = delete;
};

#include "ge_classname.inl"
