#pragma warning ( push )
#pragma warning ( disable : 4640 )
template <typename ENUMCLASS>
bTObjMap<bCString, ENUMCLASS> & bTEnumWrapper<ENUMCLASS>::GetMapStringToValue()
{
    static bTObjMap<bCString, ENUMCLASS> s_mapStringToValue;
    return s_mapStringToValue;
}

template <typename ENUMCLASS>
bTObjMap<ENUMCLASS, bCString> & bTEnumWrapper<ENUMCLASS>::GetMapValueToString()
{
    static bTObjMap<ENUMCLASS, bCString> s_mapValueToString;
    return s_mapValueToString;
}
#pragma warning ( pop )

template <typename ENUMCLASS>
bTEnumWrapper<ENUMCLASS>::bTEnumWrapper(bCString const & a_strValue, GEU32 a_u32Value)
{
    reinterpret_cast<GEU32 &>(m_EnumValue.AccessValue()) = a_u32Value;
    GetMapStringToValue()[a_strValue].CopyFrom(m_EnumValue);
    GetMapValueToString()[m_EnumValue] = a_strValue;
}

template <typename ENUMCLASS>
bCString const & bTEnumWrapper<ENUMCLASS>::GetValueString () const
{
    bCString const & Result = GetMapValueToString()[m_EnumValue];
    if(Result.IsEmpty())
    {
        GE_IMPROPER_USAGE("Value of enumeration not found in translation map; written archive may not stay compatible with future versions.")
        bCString strGeneratedName = bCString::GetFormattedString("%d", m_EnumValue.GetValue());
        GetMapStringToValue()[strGeneratedName].CopyFrom(m_EnumValue);
        GetMapValueToString()[m_EnumValue] = strGeneratedName;
        return GetMapValueToString()[m_EnumValue];
    } else
        return Result;
}

template <typename ENUMCLASS>
GEU32 bTEnumWrapper<ENUMCLASS>::GetValue () const
{
    return static_cast<GEU32>(m_EnumValue.GetValue());
}

template <typename ENUMCLASS>
bTEnumWrapper<ENUMCLASS>::~bTEnumWrapper (void)
{
}