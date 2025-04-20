#pragma once

#include <SharedBase/container/array/ge_objarray.h>

template <typename T>
class bTObjStack : public bTObjArray<T>
{
  public:
    T const &Peek() const;
    T &Peek();
};

#include "ge_objstack.inl"
