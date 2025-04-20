#pragma once

#include <SharedBase/container/array/ge_objarray.h>

template <typename T>
class bTObjArraySort : public bTObjArray<T>
{
  protected:
    gFCompare m_fComparator;
    GEBool m_bSorted;
    GE_PADDING(3)

  public:
    void Add(T const &_e) = delete;
    T &AddNew() = delete;
    void InsertAt(GEInt _i, T const &_e) = delete;
    T &InsertNewAt(GEInt _i) = delete;
    void SetAt(GEInt _i, T const &_e) = delete;

  public:
    void CopyFrom(bTObjArraySort<T> const &_s);
    GEInt InsertSort(T const &_e);
    GEInt Search(T const &_e);
    void Sort();

  public:
    bTObjArraySort<T> &operator=(bTObjArraySort<T> const &_s);

  public:
    bTObjArraySort(bTObjArraySort<T> const &_s);
    explicit bTObjArraySort(GEInt _n);
    bTObjArraySort();
    ~bTObjArraySort();
};

GE_ASSERT_SIZEOF(bTObjArraySort<GEInt>, 0x14)

#include "ge_objarraysort.inl"
