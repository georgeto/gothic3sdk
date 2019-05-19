template <typename T>
T * mCYamlParser::LoadYaml( bCString const & a_strFile, bTObjArray<bCString> const * a_arrClassPrefixes )
{
    return static_cast<T *>(LoadYaml(a_strFile, bTClassName<T>::GetUnmangled(), a_arrClassPrefixes));
}

template <typename T>
bTPtrArray<T *> * mCYamlParser::LoadYamlSequence( bCString const & a_strFile, bTObjArray<bCString> const * a_arrClassPrefixes )
{
    return static_cast<bTPtrArray<T *> *>(LoadYaml(a_strFile, bTClassName<bTPtrArray<T *>>::GetUnmangled(), a_arrClassPrefixes));
}

template <typename T>
GEBool mCYamlParser::LoadYamlSequence( bCString const & a_strFile, bTPtrArray<T *> & a_oArray, bTObjArray<bCString> const * a_arrClassPrefixes )
{
    bTPtrArray<T *> * pArray = static_cast<bTPtrArray<T *> *>(LoadYaml(a_strFile, bTClassName<bTPtrArray<T *>>::GetUnmangled(), a_arrClassPrefixes));
    if(pArray)
    {
        a_oArray = *pArray;
        GE_DELETE(pArray);
        return GETrue;
    } else
        return GEFalse;
}

template <typename T>
bTObjArray<bTAutoPOSmartPtr<T>> * mCYamlParser::LoadYamlSequenceAuto( bCString const & a_strFile, bTObjArray<bCString> const * a_arrClassPrefixes )
{
    return static_cast<bTObjArray<bTAutoPOSmartPtr<T>> *>(LoadYaml(a_strFile, bTClassName<bTObjArray<bTAutoPOSmartPtr<T>>>::GetUnmangled(), a_arrClassPrefixes));
}
