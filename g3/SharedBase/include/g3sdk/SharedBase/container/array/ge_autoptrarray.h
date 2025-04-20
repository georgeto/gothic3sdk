#pragma once

#include "ge_ptrarray.h"

template <typename T>
class bTAutoPtrArray : public bTPtrArray<T>
{
  public:
    bTAutoPtrArray<T> &operator=(bTAutoPtrArray<T> const &_s) = delete;
    bTAutoPtrArray(bTAutoPtrArray<T> const &_s) = delete;

  public:
    explicit bTAutoPtrArray(GEInt _n);
    bTAutoPtrArray();
    ~bTAutoPtrArray();
};

#include "ge_autoptrarray.inl"
