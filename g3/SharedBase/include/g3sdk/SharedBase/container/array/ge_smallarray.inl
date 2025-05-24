#include <SharedBase/types/ge_windows.h>

template <typename T>
void bTSmallArray<T>::Copy(T *_d, T const *_s, GEU16 _n)
{
    while (_n--)
        *_d++ = *_s++;
}

template <typename T>
void bTSmallArray<T>::Move(T *_d, T const *_s, GEU16 _n)
{
    if (_n > 0)
        ::memmove(_d, _s, _n * sizeof(T));
}

template <typename T>
void bTSmallArray<T>::Init()
{
    this->m_pArray = nullptr;
    this->m_u16Count = 0;
    this->m_u16Capacity = 0;
}

template <typename T>
T *bTSmallArray<T>::AccessArray()
{
    return this->m_pArray;
}

template <typename T>
T &bTSmallArray<T>::AccessAt(GEU16 _i)
{
    return this->m_pArray[_i];
}

template <typename T>
void bTSmallArray<T>::Add(T const &_e)
{
    GEU16 const _i = this->GetCount();
    this->SetCount(_i + 1);
    this->SetAt(_i, _e);
}

template <typename T>
T &bTSmallArray<T>::AddNew()
{
    GEU16 const _i = this->GetCount();
    this->SetCount(_i + 1);
    return this->AccessAt(_i);
}

template <typename T>
void bTSmallArray<T>::Clear()
{
    if (this->m_pArray)
        GE_FREE(this->m_pArray);
    this->Init();
}

template <typename T>
void bTSmallArray<T>::CopyFrom(bTSmallArray<T> const &_s)
{
    if (this != &_s)
    {
        this->SetCount(_s.GetCount());
        for (GEU16 i = 0; i < this->GetCount(); i++)
            this->SetAt(i, _s.GetAt(i));
    }
}

template <typename T>
void bTSmallArray<T>::CopyTo(bTSmallArray<T> &_d) const
{
    _d.CopyFrom(*this);
}

template <typename T>
T const *bTSmallArray<T>::GetArray() const
{
    return this->m_pArray;
}

template <typename T>
T const &bTSmallArray<T>::GetAt(GEU16 _i) const
{
    return this->m_pArray[_i];
}

template <typename T>
void bTSmallArray<T>::GetAt(GEU16 _i, T &_e) const
{
    _e = this->GetAt(_i);
}

template <typename T>
GEU16 bTSmallArray<T>::GetCapacity() const
{
    return static_cast<GEU16>(this->m_u16Capacity);
}

template <typename T>
GEU16 bTSmallArray<T>::GetCount() const
{
    return static_cast<GEU16>(this->m_u16Count);
}

template <typename T>
GEU16 bTSmallArray<T>::IndexOf(T const &_e) const
{
    GEU16 _i = this->GetCount();
    while (_i--)
        if (_e == this->m_pArray[_i])
            return _i;
    return bEIndex_Invalid;
}

template <class T>
void bTSmallArray<T>::InsertAt(GEU16 _i, T const &_e)
{
    GEU16 const _c = this->GetCount();
    if (_c == _i)
    {
        this->Add(_e);
    }
    else
    {
        this->SetCount(_c + 1);
        bTSmallArray<T>::Move(this->m_pArray + _i + 1, this->m_pArray + _i, _c - _i);
        this->SetAt(_i, _e);
    }
}

template <typename T>
T &bTSmallArray<T>::InsertNewAt(GEU16 _i)
{
    GEU16 const _c = this->GetCount();
    if (_c == _i)
    {
        return this->AddNew();
    }
    else
    {
        this->SetCount(_c + 1);
        bTSmallArray<T>::Move(this->m_pArray + _i + 1, this->m_pArray + _i, _c - _i);
        return this->AccessAt(_i);
    }
}

template <typename T>
GEBool bTSmallArray<T>::IsEmpty() const
{
    return 0 == this->GetCount();
}

template <typename T>
void bTSmallArray<T>::Remove(T const &_e)
{
    this->RemoveAt(this->IndexOf(_e));
}

template <typename T>
void bTSmallArray<T>::RemoveAll()
{
    this->Clear();
}

template <typename T>
void bTSmallArray<T>::RemoveAt(GEU16 _i)
{
    GEU16 const _u = this->GetCount() - 1;
    if ((0 <= _i) && (_i <= _u))
    {
        bTSmallArray<T>::Move(this->m_pArray + _i, this->m_pArray + _i + 1, _u - _i);
        this->m_u16Count--;
    }
}

template <typename T>
void bTSmallArray<T>::Reserve(GEU16 _n)
{
    if (_n > this->GetCapacity())
    {
        this->m_pArray = static_cast<T *>(GE_REALLOC(this->m_pArray, _n * sizeof(T)));
        // g_ZeroMemory( this->m_pArray + this->GetCapacity(), sizeof( T ) * static_cast< GEU16 >( _n -
        // this->GetCapacity() ) );
        memset(this->m_pArray + this->GetCapacity(), 0, sizeof(T) * static_cast<GEU16>(_n - this->GetCapacity()));
        this->m_u16Capacity = static_cast<GEU16>(_n);
    }
}

template <typename T>
void bTSmallArray<T>::SetAt(GEU16 _i, T const &_e)
{
    T *_x = this->AccessArray() + _i;
    bTSmallArray<T>::Copy(_x, &_e, 1);
}

template <typename T>
void bTSmallArray<T>::SetCount(GEU16 _n)
{
    if (0 == _n)
        this->Clear();
    else
    {
        GEU16 const _c = this->GetCount();
        if (_n > _c)
        {
            this->Reserve(_n);
            this->m_u16Count = static_cast<GEU16>(_n);
        }
        else if (_n < _c)
        {
            // g_ZeroMemory( this->m_pArray + _n, static_cast< GEU16 >( _c - _n ) );
            memset(this->m_pArray + _n, 0, static_cast<GEU16>(_c - _n));
            this->m_u16Count = static_cast<GEU16>(_n);
        }
    }
}

template <typename T>
bTSmallArray<T> &bTSmallArray<T>::operator=(bTSmallArray<T> const &_s)
{
    this->CopyFrom(_s);
    return *this;
}

template <typename T>
bTSmallArray<T>::bTSmallArray(bTSmallArray<T> const &_s)
{
    this->Init();
    this->CopyFrom(_s);
}

template <typename T>
bTSmallArray<T>::bTSmallArray(GEU16 _n)
{
    this->Init();
    this->Reserve(_n);
}

template <typename T>
bTSmallArray<T>::bTSmallArray()
{
    this->Init();
}

template <typename T>
bTSmallArray<T>::~bTSmallArray()
{
    this->Clear();
}

template <typename T>
T const &bTSmallArray<T>::operator[](GEU16 _i) const
{
    return this->GetAt(_i);
}

template <typename T>
T &bTSmallArray<T>::operator[](GEU16 _i)
{
    return this->AccessAt(_i);
}
