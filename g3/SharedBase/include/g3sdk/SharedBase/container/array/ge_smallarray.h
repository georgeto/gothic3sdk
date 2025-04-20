#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

template <typename T>
class bTSmallArray
{
  public:
    enum bEIndex
    {
        bEIndex_Invalid = 0xFFFFFFFFL
    };

  protected:
    GEU16 m_u16Capacity;
    GEU16 m_u16Count;
    T *m_pArray;

  protected:
    static void GE_STDCALL Copy(T *_d, T const *_s, GEU16 _n);
    static void GE_STDCALL Move(T *_d, T const *_s, GEU16 _n);

  protected:
    void Init();

  public:
    T *AccessArray();
    T &AccessAt(GEU16 _i);
    void Add(T const &_e);
    T &AddNew();
    void Clear();
    void CopyFrom(bTSmallArray<T> const &_s);
    void CopyTo(bTSmallArray<T> &_d) const;
    T const *GetArray() const;
    T const &GetAt(GEU16 _i) const;
    void GetAt(GEU16 _i, T &_e) const;
    GEU16 GetCapacity() const;
    GEU16 GetCount() const;
    GEU16 IndexOf(T const &_e) const;
    void InsertAt(GEU16 _i, T const &_e);
    T &InsertNewAt(GEU16 _i);
    GEBool IsEmpty() const;
    void Remove(T const &_e);
    void RemoveAll();
    void RemoveAt(GEU16 _i);
    void Reserve(GEU16 _n);
    void SetAt(GEU16 _i, T const &_e);
    void SetCount(GEU16 _n);

  public:
    T &operator[](GEU16 _i);
    T const &operator[](GEU16 _i) const;

  public:
    bTSmallArray<T> &operator=(bTSmallArray<T> const &_s);

  public:
    bTSmallArray(bTSmallArray<T> const &_s);
    explicit bTSmallArray(GEU16 _n);
    bTSmallArray();
    ~bTSmallArray();
};

#include "ge_smallarray.inl"

GE_ASSERT_SIZEOF(bTSmallArray<GEInt>, 0x08)
