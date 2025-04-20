#pragma once

#include <SharedBase/io/streams/ge_istream.h>
#include <SharedBase/io/streams/ge_ostream.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

#define GE_DECLARE_ARRAY_ITERATORS()                                                                                   \
  public:                                                                                                              \
    class bCIterator;                                                                                                  \
    class bCConstIterator                                                                                              \
    {                                                                                                                  \
      protected:                                                                                                       \
        GEInt m_iIndex;                                                                                                \
        T *m_pArray;                                                                                                   \
                                                                                                                       \
      public:                                                                                                          \
        T const &operator*() const                                                                                     \
        {                                                                                                              \
            return this->m_pArray[this->m_iIndex];                                                                     \
        }                                                                                                              \
        T const &operator[](GEInt _n) const                                                                            \
        {                                                                                                              \
            return this->m_pArray[this->m_iIndex + _n];                                                                \
        }                                                                                                              \
        bCConstIterator operator++(GEInt)                                                                              \
        {                                                                                                              \
            bCConstIterator _x = *this;                                                                                \
            ++*this;                                                                                                   \
            return _x;                                                                                                 \
        }                                                                                                              \
        bCConstIterator &operator++()                                                                                  \
        {                                                                                                              \
            this->m_iIndex++;                                                                                          \
            return *this;                                                                                              \
        }                                                                                                              \
        bCConstIterator operator--(GEInt)                                                                              \
        {                                                                                                              \
            bCConstIterator _x = *this;                                                                                \
            --*this;                                                                                                   \
            return _x;                                                                                                 \
        }                                                                                                              \
        bCConstIterator &operator--()                                                                                  \
        {                                                                                                              \
            this->m_iIndex--;                                                                                          \
            return *this;                                                                                              \
        }                                                                                                              \
        bCConstIterator &operator+=(GEInt _n)                                                                          \
        {                                                                                                              \
            this->m_iIndex += _n;                                                                                      \
            return *this;                                                                                              \
        }                                                                                                              \
        bCConstIterator &operator-=(GEInt _n)                                                                          \
        {                                                                                                              \
            this->m_iIndex -= _n;                                                                                      \
            return *this;                                                                                              \
        }                                                                                                              \
        bCConstIterator operator+(GEInt _n) const                                                                      \
        {                                                                                                              \
            bCConstIterator _x = *this;                                                                                \
            return _x += _n;                                                                                           \
        }                                                                                                              \
        bCConstIterator operator-(GEInt _n) const                                                                      \
        {                                                                                                              \
            bCConstIterator _x = *this;                                                                                \
            return _x -= _n;                                                                                           \
        }                                                                                                              \
        bCConstIterator operator-(bCConstIterator const &_x) const                                                     \
        {                                                                                                              \
            return (this->m_pArray + this->m_iIndex) - (_x.m_pArray + _x.m_iIndex);                                    \
        }                                                                                                              \
        GEBool operator==(bCConstIterator const &_x) const                                                             \
        {                                                                                                              \
            return (this->m_iIndex == _x.m_iIndex) && (this->m_pArray == _x.m_pArray);                                 \
        }                                                                                                              \
        GEBool operator!=(bCConstIterator const &_x) const                                                             \
        {                                                                                                              \
            return !(*this == _x);                                                                                     \
        }                                                                                                              \
        GEBool operator<(bCConstIterator const &_x) const                                                              \
        {                                                                                                              \
            return (this->m_pArray + this->m_iIndex) < (_x.m_pArray + _x.m_iIndex);                                    \
        }                                                                                                              \
        GEBool operator>(bCConstIterator const &_x) const                                                              \
        {                                                                                                              \
            return _x < *this;                                                                                         \
        }                                                                                                              \
        GEBool operator<=(bCConstIterator const &_x) const                                                             \
        {                                                                                                              \
            return !(_x < *this);                                                                                      \
        }                                                                                                              \
        GEBool operator>=(bCConstIterator const &_x) const                                                             \
        {                                                                                                              \
            return !(*this < _x);                                                                                      \
        }                                                                                                              \
        bCConstIterator(bCIterator const &_x) : m_iIndex(_x.m_iIndex), m_pArray(_x.m_pArray)                           \
        {}                                                                                                             \
        bCConstIterator(T const *_p, GEInt _i) : m_iIndex(_i), m_pArray(const_cast<T *>(_p))                           \
        {}                                                                                                             \
        bCConstIterator() : m_iIndex(0), m_pArray(0)                                                                   \
        {}                                                                                                             \
    };                                                                                                                 \
    class bCIterator : public bCConstIterator                                                                          \
    {                                                                                                                  \
      public:                                                                                                          \
        T &operator*() const                                                                                           \
        {                                                                                                              \
            return this->m_pArray[this->m_iIndex];                                                                     \
        }                                                                                                              \
        T &operator[](GEInt _n) const                                                                                  \
        {                                                                                                              \
            return this->m_pArray[this->m_iIndex + _n];                                                                \
        }                                                                                                              \
        bCIterator operator++(GEInt)                                                                                   \
        {                                                                                                              \
            bCIterator _x = *this;                                                                                     \
            ++*this;                                                                                                   \
            return _x;                                                                                                 \
        }                                                                                                              \
        bCIterator &operator++()                                                                                       \
        {                                                                                                              \
            this->m_iIndex++;                                                                                          \
            return *this;                                                                                              \
        }                                                                                                              \
        bCIterator operator--(GEInt)                                                                                   \
        {                                                                                                              \
            bCIterator _x = *this;                                                                                     \
            --*this;                                                                                                   \
            return _x;                                                                                                 \
        }                                                                                                              \
        bCIterator &operator--()                                                                                       \
        {                                                                                                              \
            this->m_iIndex--;                                                                                          \
            return *this;                                                                                              \
        }                                                                                                              \
        bCIterator &operator+=(GEInt _n)                                                                               \
        {                                                                                                              \
            this->m_iIndex += _n;                                                                                      \
            return *this;                                                                                              \
        }                                                                                                              \
        bCIterator &operator-=(GEInt _n)                                                                               \
        {                                                                                                              \
            this->m_iIndex -= _n;                                                                                      \
            return *this;                                                                                              \
        }                                                                                                              \
        bCIterator operator+(GEInt _n) const                                                                           \
        {                                                                                                              \
            bCIterator _x = *this;                                                                                     \
            return _x += _n;                                                                                           \
        }                                                                                                              \
        bCIterator operator-(GEInt _n) const                                                                           \
        {                                                                                                              \
            bCIterator _x = *this;                                                                                     \
            return _x -= _n;                                                                                           \
        }                                                                                                              \
        bCIterator operator-(bCIterator const &_x) const                                                               \
        {                                                                                                              \
            return (this->m_pArray + this->m_iIndex) - (_x.m_pArray + _x.m_iIndex);                                    \
        }                                                                                                              \
        GEBool operator==(bCIterator const &_x) const                                                                  \
        {                                                                                                              \
            return (this->m_iIndex == _x.m_iIndex) && (this->m_pArray == _x.m_pArray);                                 \
        }                                                                                                              \
        GEBool operator!=(bCIterator const &_x) const                                                                  \
        {                                                                                                              \
            return !(*this == _x);                                                                                     \
        }                                                                                                              \
        GEBool operator<(bCIterator const &_x) const                                                                   \
        {                                                                                                              \
            return (this->m_pArray + this->m_iIndex) < (_x.m_pArray + _x.m_iIndex);                                    \
        }                                                                                                              \
        GEBool operator>(bCIterator const &_x) const                                                                   \
        {                                                                                                              \
            return _x < *this;                                                                                         \
        }                                                                                                              \
        GEBool operator<=(bCIterator const &_x) const                                                                  \
        {                                                                                                              \
            return !(_x < *this);                                                                                      \
        }                                                                                                              \
        GEBool operator>=(bCIterator const &_x) const                                                                  \
        {                                                                                                              \
            return !(*this < _x);                                                                                      \
        }                                                                                                              \
        bCIterator(T *_p, GEInt _i) : bCConstIterator(_p, _i)                                                          \
        {}                                                                                                             \
        bCIterator()                                                                                                   \
        {}                                                                                                             \
    };                                                                                                                 \
    using bCRandomAccessIterator = bCIterator;                                                                         \
    using bCConstRandomAccessIterator = bCConstIterator;

#define GE_DECLARE_ARRAY_STREAM_OPERATORS()                                                                            \
  public:                                                                                                              \
    bCOStream &operator>>(bCOStream &_os) const                                                                        \
    {                                                                                                                  \
        _os << static_cast<GEU8>(1) << this->m_u32Count;                                                               \
        for (GEU32 i = 0; i < this->m_u32Count; i++)                                                                   \
            this->m_pArray[i] >> _os;                                                                                  \
        return _os;                                                                                                    \
    }                                                                                                                  \
                                                                                                                       \
    bCIStream &operator<<(bCIStream &_is)                                                                              \
    {                                                                                                                  \
        GEU8 _v;                                                                                                       \
        _v << _is;                                                                                                     \
        GEU32 _c;                                                                                                      \
        _c << _is;                                                                                                     \
        this->SetCount(static_cast<GEInt>(_c));                                                                        \
        for (GEU32 i = 0; i < this->m_u32Count; i++)                                                                   \
            this->m_pArray[i] << _is;                                                                                  \
        return _is;                                                                                                    \
    }

#define GE_DECLARE_NO_STREAM_OPERATORS(TYPE) GE_DECLARE_NO_STREAM_OPERATORS_TEMPLATE(TYPE, )

#define GE_DECLARE_NO_STREAM_OPERATORS_TEMPLATE(TYPE, TEMPLATE)                                                        \
    TEMPLATE                                                                                                           \
    bCOStream &GE_STDCALL operator>>(TYPE const &,                                                                     \
                                     bCOStream &){GE_FATAL_ERROR("operator " #TYPE " >> bCOStream not implemented!")}  \
                                                                                                                       \
    TEMPLATE bCIStream &GE_STDCALL operator<<(TYPE &, bCIStream &)                                                     \
    {                                                                                                                  \
        GE_FATAL_ERROR("operator " #TYPE " << bCIStream not implemented!")                                             \
    }

#define GE_DECLARE_NO_STREAM_OPERATORS_INLINE(TYPE)                                                                    \
    inline bCOStream &operator>>(bCOStream &)                                                                          \
    {                                                                                                                  \
        GE_FATAL_ERROR("operator " #TYPE " >> bCOStream not implemented!")                                             \
    }                                                                                                                  \
                                                                                                                       \
    inline bCIStream &operator<<(bCIStream &)                                                                          \
    {                                                                                                                  \
        GE_FATAL_ERROR("operator " #TYPE " << bCIStream not implemented!")                                             \
    }

#define GE_ARRAY_FOR_EACH(NAME, ARRAY)                                                                                 \
    if (auto &__ARRAY = ARRAY; GETrue)                                                                                 \
    _Pragma("warning (push)")                                                                                          \
        _Pragma("warning(disable : 4456)") /* declaration of 'i' hides previous local declaration */                   \
        for (decltype(__ARRAY.GetCount()) i = 0; i < __ARRAY.GetCount(); i++)                                          \
            _Pragma("warning (pop)") if (auto &NAME = __ARRAY[i]; GETrue)

#define GE_ARRAY_FOR_EACH_REV(NAME, ARRAY)                                                                             \
    if (auto &__ARRAY = ARRAY; GETrue)                                                                                 \
    _Pragma("warning (push)")                                                                                          \
        _Pragma("warning(disable : 4456)") /* declaration of 'i' hides previous local declaration */                   \
        for (decltype(__ARRAY.GetCount()) i = __ARRAY.GetCount(); i-- > 0;)                                            \
            _Pragma("warning (pop)") if (auto &NAME = __ARRAY[i]; GETrue)

template <typename T>
class bTArrayBase
{
    GE_DECLARE_ARRAY_ITERATORS()
  public:
    enum bEIndex
    {
        bEIndex_Invalid = 0xFFFFFFFFL
    };

  protected:
    T *m_pArray;
    GEU32 m_u32Count;
    GEU32 m_u32Capacity;

  protected:
    static void GE_STDCALL Copy(T *_d, T const *_s, GEInt _n);
    static void GE_STDCALL Delete(T *_e, GEInt _n);
    static void GE_STDCALL Move(T *_d, T const *_s, GEInt _n);
    static void GE_STDCALL New(T *_e, GEInt _n);

  protected:
    void Init();

  protected:
    bTArrayBase<T> &operator=(bTArrayBase<T> const &) = delete;

  protected:
    bTArrayBase(bTArrayBase<T> const &_s) = delete;
    explicit bTArrayBase(GEInt _n) = delete;
    bTArrayBase();
    ~bTArrayBase();

  public:
    T *AccessArray();
    T &AccessAt(GEInt _i);
    bCConstIterator Begin() const;
    bCIterator Begin();
    GEBool Contains(T const &_e) const;
    T const *GetArray() const;
    T const &GetAt(GEInt _i) const;
    void GetAt(GEInt _i, T &_e) const;
    GEInt GetCapacity() const;
    GEInt GetCount() const;
    bCConstIterator End() const;
    bCIterator End();
    GEInt IndexOf(T const &_e) const;
    GEBool IsEmpty() const;

  public:
    T &operator[](GEInt _i);
    T const &operator[](GEInt _i) const;
};

using gFCompare = GEInt(GE_CCALL *)(GELPCVoid, GELPCVoid);
void GE_CCALL g_ArrayInsertionSort(GELPVoid a_pArray, GEUInt a_u32ElementCount, GEUInt a_u32ElementSize,
                                   gFCompare a_fCompare, GEBool a_bUseFallbackIfToUnsorted);
GEInt GE_CCALL g_ArraySortDefaultCompare(GELPCVoid, GELPCVoid);

#include "ge_arraybase.inl"
