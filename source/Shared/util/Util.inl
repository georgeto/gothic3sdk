template< typename T >
T Min(T a_Value1, T a_Value2)
{
    return a_Value1 < a_Value2 ? a_Value1 : a_Value2;
}

template< typename T >
T Max(T a_Value1, T a_Value2)
{
    return a_Value1 > a_Value2 ? a_Value1 : a_Value2;
}

template< typename T >
bCString GetEnumPrefix()
{
    return bTClassName<T>::GetUnmangled() + "_";
}

template< typename T >
bCString EnumToString( bTPropertyTypeOnly<bTPropertyContainer<T>> const & a_PropertyType, T a_enuValue, GEBool a_bPrefix )
{
    if(a_PropertyType.HasEnumValues())
    {
        for(GEInt i = 0; i < a_PropertyType.GetEnumValueCount(); i++)
        {
            bCEnumWrapper const * pEnumValue = a_PropertyType.GetEnumValue(i);
            if(pEnumValue->GetValue() == static_cast<GEU32>(a_enuValue))
            {
                bCString strEnumValue = pEnumValue->GetValueString();
                if(!a_bPrefix)
                    strEnumValue.Replace(GetEnumPrefix<T>(), "");
                return strEnumValue;
            }
        }
    }

    return "<INVALID ENUM VALUE>";
}

template< typename T >
GEBool StringToEnum( T & a_oEnuValue, bTPropertyTypeOnly<bTPropertyContainer<T>> const & a_PropertyType, bCString a_strValue, GEBool a_bPrefix )
{
    if(a_PropertyType.HasEnumValues())
    {
        if (a_bPrefix)
            a_strValue = GetEnumPrefix<T>() + a_strValue;

        for(GEInt i = 0; i < a_PropertyType.GetEnumValueCount(); i++)
        {
            bCEnumWrapper const * pEnumValue = a_PropertyType.GetEnumValue(i);
            if(pEnumValue->GetValueString() == a_strValue)
            {
                a_oEnuValue = static_cast<T>(pEnumValue->GetValue());
                return GETrue;
            }
        }
    }

    return GEFalse;
}

template< typename T >
T StringToEnum( bTPropertyTypeOnly<bTPropertyContainer<T>> const & a_PropertyType, bCString a_strValue, T a_enuDefaultValue, GEBool a_bPrefix )
{
    T enuResult;
    if(StringToEnum(enuResult, a_PropertyType, a_strValue, a_bPrefix))
        return enuResult;
    else
        return a_enuDefaultValue;
}

