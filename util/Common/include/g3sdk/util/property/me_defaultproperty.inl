template <typename ENUM>
inline bTPropertyContainer<ENUM> *__WrapEnumPointer(ENUM *a_pDefaultValue)
{
    bTPropertyContainer<ENUM> *pWrapped = nullptr;
    if (a_pDefaultValue != nullptr)
    {
        pWrapped = GE_NEW(bTPropertyContainer<ENUM>)(*a_pDefaultValue);
        GE_DELETE(a_pDefaultValue);
    }

    return pWrapped;
}

template <typename OBJECLASS, typename ENUM>
void __CopyEnumValues(bTPropertyType<OBJECLASS, ENUM> &Destination, bTPropertyTypeOnly<ENUM> const &Source)
{
    if (!Source.HasEnumValues())
        return;

    for (GEInt i = 0; i < Source.GetEnumValueCount(); i++)
    {
        bCEnumWrapper const *pEnumValue = Source.GetEnumValue(i);
        Destination.AddEnumValue(GE_NEW(bTEnumWrapper<ENUM>)(pEnumValue->GetValueString(), pEnumValue->GetValue()));
    }
}

template <typename OBJECTCLASS, typename CLASS>
GEBool mTDefaultPropertyType<OBJECTCLASS, CLASS>::HasDefaultValue() const
{
    return m_pDefaultValue != nullptr;
}

template <typename OBJECTCLASS, typename CLASS>
GELPCVoid mTDefaultPropertyType<OBJECTCLASS, CLASS>::GetDefaultValue() const
{
    return m_pDefaultValue;
}

template <typename OBJECTCLASS, typename CLASS>
void mTDefaultPropertyType<OBJECTCLASS, CLASS>::Destroy()
{
    bTPropertyType<OBJECTCLASS, CLASS>::Destroy();
    GE_DELETE(m_pDefaultValue);
}

template <typename OBJECTCLASS, typename CLASS>
mTDefaultPropertyType<OBJECTCLASS, CLASS>::mTDefaultPropertyType(bCPropertyObjectTypeBase &a_pPropertyObjectType,
                                                                 GEU32 a_u32MemberOffset,
                                                                 bCString const &a_strPropertyName,
                                                                 bEPropertyType a_enuPropertyType,
                                                                 CLASS *a_pDefaultValue)
    : bTPropertyType(a_pPropertyObjectType, a_u32MemberOffset, a_strPropertyName, a_enuPropertyType),
      m_pDefaultValue(a_pDefaultValue)
{}

template <typename OBJECTCLASS, typename CLASS>
CLASS const *mTDefaultPropertyType<OBJECTCLASS, CLASS>::GetDefaultValueType() const
{
    return m_pDefaultValue;
}
