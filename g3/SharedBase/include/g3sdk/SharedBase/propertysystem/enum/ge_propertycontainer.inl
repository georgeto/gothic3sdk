#include <SharedBase/io/streams/ge_istream.h>
#include <SharedBase/io/streams/ge_ostream.h>

template <typename T>
T bTPropertyContainer<T>::s_DefaultValue;

template <typename T>
T &bTPropertyContainer<T>::AccessValue()
{
    return this->m_Value;
}

template <typename T>
T const &bTPropertyContainer<T>::GetValue() const
{
    return this->m_Value;
}

template <typename T>
void bTPropertyContainer<T>::SetValue(T const &a_Value)
{
    this->m_Value = a_Value;
}

template <typename T>
bTPropertyContainer<T>::bTPropertyContainer()
{
    this->m_Value = s_DefaultValue;
}

template <typename T>
bTPropertyContainer<T>::bTPropertyContainer(T const &a_Value)
{
    this->m_Value = a_Value;
}

template <typename T>
bTPropertyContainer<T>::bTPropertyContainer(bTPropertyContainer<T> const &a_Source)
{
    this->m_Value = a_Source.m_Value;
}

template <typename T>
bTPropertyContainer<T>::operator T &()
{
    return this->m_Value;
}

template <typename T>
bTPropertyContainer<T>::operator T const &() const
{
    return this->m_Value;
}

template <typename T>
GEBool bTPropertyContainer<T>::operator==(bTPropertyContainer<T> const &a_Other) const
{
    return a_Other.m_Value == this->m_Value;
}

template <typename T>
GEBool bTPropertyContainer<T>::operator==(T const &a_Value) const
{
    return a_Value == this->m_Value;
}

template <typename T>
GEBool bTPropertyContainer<T>::operator!=(bTPropertyContainer<T> const &a_Other) const
{
    return !(this->operator==(a_Other));
}

template <typename T>
GEBool bTPropertyContainer<T>::operator!=(T const &a_Value) const
{
    return !(this->operator==(a_Value));
}

template <typename T>
bTPropertyContainer<T> &bTPropertyContainer<T>::operator=(bTPropertyContainer<T> const &a_Source)
{
    this->m_Value = a_Source.m_Value;
    return *this;
}

template <typename T>
bEResult bTPropertyContainer<T>::Write(bCOStream &a_OStream)
{
    a_OStream << static_cast<GEU16>(1u);
    a_OStream.Write(&m_Value, sizeof(m_Value));
    return bEResult_Ok;
}

template <typename T>
bEResult bTPropertyContainer<T>::Read(bCIStream &a_IStream)
{
    GEU16 u16Version;
    u16Version << a_IStream;
    a_IStream.Read(&m_Value, sizeof(m_Value));
    return bEResult_Ok;
}

template <typename T>
bEResult bTPropertyContainer<T>::Create()
{
    m_Value = s_DefaultValue;
    return bEResult_Ok;
}

template <typename T>
bEResult bTPropertyContainer<T>::CopyFrom(bCObjectBase const &a_Other)
{
    m_Value = static_cast<bTPropertyContainer const &>(a_Other).m_Value;
    return bEResult_Ok;
}

template <typename T>
bTPropertyContainer<T>::~bTPropertyContainer()
{}
