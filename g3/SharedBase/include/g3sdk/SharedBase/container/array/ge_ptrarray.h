#pragma once

#include "ge_valarray.h"

template <typename T>
class bTPtrArray : public bTValArray<T>
{
  public:
    T &AddNew() = delete;
    T &InsertNewAt(GEInt _i) = delete;

  public:
    void Delete(T const &_e);
    void DeleteAll();
    void DeleteAt(GEInt _i);
    T RemoveAt(GEInt _i);

  public:
    bTPtrArray<T> &operator=(bTPtrArray<T> const &_s);

  public:
    bTPtrArray(bTPtrArray<T> const &_s);
    explicit bTPtrArray(GEInt _n);
    bTPtrArray();
    ~bTPtrArray();
};

#include "ge_ptrarray.inl"
