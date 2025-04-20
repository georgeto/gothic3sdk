template <typename T>
bTAutoPtrArray<T>::bTAutoPtrArray(GEInt _n) : bTPtrArray<T>(_n)
{}

template <typename T>
bTAutoPtrArray<T>::bTAutoPtrArray() : bTPtrArray<T>()
{}

template <typename T>
bTAutoPtrArray<T>::~bTAutoPtrArray()
{
    this->DeleteAll();
}
