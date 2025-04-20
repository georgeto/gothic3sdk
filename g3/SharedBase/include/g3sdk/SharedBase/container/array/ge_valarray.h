#pragma once

#include "ge_arraybase.h"

template <typename T>
class bTValArray : public bTArrayBase<T>
{
  public:
    void Add(T const &_e);
    T &AddNew();
    void Clear();
    void CopyFrom(bTValArray<T> const &_s);
    void CopyTo(bTValArray<T> &_d) const;
    void InsertAt(GEInt _i, T const &_e);
    T &InsertNewAt(GEInt _i);
    void Remove(T const &_e);
    void RemoveAll();
    void RemoveAt(GEInt _i);
    void RemoveRange(GEInt _i, GEInt _n);
    void Reserve(GEInt _n);
    void SetAt(GEInt _i, T const &_e);
    void SetCount(GEInt _n);

  public:
    bTValArray<T> &operator=(bTValArray<T> const &_s);

  public:
    bTValArray(bTValArray<T> const &_s);
    explicit bTValArray(GEInt _n);
    bTValArray();
    ~bTValArray();
    GE_DECLARE_ARRAY_STREAM_OPERATORS()
};

#include "ge_valarray.inl"
