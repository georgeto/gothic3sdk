template <typename T>
T const &bTObjStack<T>::Peek() const
{
    return GetAt(GetCount() - 1);
}

template <typename T>
T &bTObjStack<T>::Peek()
{
    return AccessAt(GetCount() - 1);
}
