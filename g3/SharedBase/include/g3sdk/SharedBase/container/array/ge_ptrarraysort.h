#pragma once

#include <SharedBase/container/array/ge_ptrarray.h>

template <typename T>
class bTPtrArraySort : public bTPtrArray<T>
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
    void CopyFrom(bTPtrArraySort<T> const &_s);
    GEInt InsertSort(T const &_e);
    GEInt Search(T const &_e);
    void Sort();

  public:
    bTPtrArraySort<T> &operator=(bTPtrArraySort<T> const &_s);

  public:
    bTPtrArraySort(bTPtrArraySort<T> const &_s);
    explicit bTPtrArraySort(GEInt _n, gFCompare _fComparator = &g_ArraySortDefaultCompare);
    explicit bTPtrArraySort(gFCompare _fComparator = &g_ArraySortDefaultCompare);
    ~bTPtrArraySort();
};

GE_ASSERT_SIZEOF(bTPtrArraySort<GEInt>, 0x14)

#include "ge_ptrarraysort.inl"
