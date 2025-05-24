#include <SharedBase/types/ge_windows.h>

template <typename T>
void bTArrayBase<T>::Copy(T *_d, T const *_s, GEInt _n)
{
    while (_n--)
        *_d++ = *_s++;
}

template <typename T>
void bTArrayBase<T>::Delete(T *_e, GEInt _n)
{
    for (; _n--; _e++)
        _e->~T();
}

template <typename T>
void bTArrayBase<T>::Move(T *_d, T const *_s, GEInt _n)
{
    if (_n > 0)
        ::memmove(_d, _s, _n * sizeof(T));
}

template <typename T>
void bTArrayBase<T>::New(T *_e, GEInt _n)
{
    // g_ZeroMemory( _e, _n * sizeof( T ) );
    memset(_e, 0, _n * sizeof(T));
    for (; _n--; _e++)
        ::new (_e) T;
}

template <typename T>
void bTArrayBase<T>::Init()
{
    this->m_pArray = nullptr;
    this->m_u32Count = 0;
    this->m_u32Capacity = 0;
}

template <typename T>
bTArrayBase<T>::bTArrayBase()
{
    this->Init();
}

template <typename T>
bTArrayBase<T>::~bTArrayBase()
{}

template <typename T>
T *bTArrayBase<T>::AccessArray()
{
    return this->m_pArray;
}

template <typename T>
T &bTArrayBase<T>::AccessAt(GEInt _i)
{
    return this->m_pArray[_i];
}

template <typename T>
typename bTArrayBase<T>::bCConstIterator bTArrayBase<T>::Begin() const
{
    return bCConstIterator(this->GetArray(), 0);
}

template <typename T>
typename bTArrayBase<T>::bCIterator bTArrayBase<T>::Begin()
{
    return bCIterator(this->AccessArray(), 0);
}

template <typename T>
GEBool bTArrayBase<T>::Contains(T const &_e) const
{
    return this->IndexOf(_e) != bEIndex_Invalid;
}

template <typename T>
T const *bTArrayBase<T>::GetArray() const
{
    return this->m_pArray;
}

template <typename T>
T const &bTArrayBase<T>::GetAt(GEInt _i) const
{
    return this->m_pArray[_i];
}

template <typename T>
void bTArrayBase<T>::GetAt(GEInt _i, T &_e) const
{
    _e = this->GetAt(_i);
}

template <typename T>
GEInt bTArrayBase<T>::GetCapacity() const
{
    return static_cast<GEInt>(this->m_u32Capacity);
}

template <typename T>
GEInt bTArrayBase<T>::GetCount() const
{
    return static_cast<GEInt>(this->m_u32Count);
}

template <typename T>
typename bTArrayBase<T>::bCConstIterator bTArrayBase<T>::End() const
{
    return bCConstIterator(this->GetArray(), this->GetCount());
}

template <typename T>
typename bTArrayBase<T>::bCIterator bTArrayBase<T>::End()
{
    return bCIterator(this->AccessArray(), this->GetCount());
}

template <typename T>
GEBool bTArrayBase<T>::IsEmpty() const
{
    return 0 == this->GetCount();
}

template <typename T>
GEInt bTArrayBase<T>::IndexOf(T const &_e) const
{
    GEInt _i = this->GetCount();
    while (_i--)
        if (_e == this->m_pArray[_i])
            return _i;
    return bEIndex_Invalid;
}

template <typename T>
T const &bTArrayBase<T>::operator[](GEInt _i) const
{
    return this->GetAt(_i);
}

template <typename T>
T &bTArrayBase<T>::operator[](GEInt _i)
{
    return this->AccessAt(_i);
}
