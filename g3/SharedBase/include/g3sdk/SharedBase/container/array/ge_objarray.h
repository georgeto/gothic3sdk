#pragma once

#include "ge_arraybase.h"

template <typename T>
class bTObjArray : public bTArrayBase<T>
{
  public:
    void Add(T const &_e);
    T &AddNew();
    void Clear();
    void CopyFrom(bTObjArray<T> const &_s);
    void CopyTo(bTObjArray<T> &_d) const;
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
    bTObjArray<T> &operator=(bTObjArray<T> const &_s);

  public:
    bTObjArray(bTObjArray<T> const &_s);
    explicit bTObjArray(GEInt _n);
    bTObjArray();
    ~bTObjArray();
    GE_DECLARE_ARRAY_STREAM_OPERATORS()
};

#include "ge_objarray.inl"
