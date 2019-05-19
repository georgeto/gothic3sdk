template< typename ENUM >
inline bTPropertyContainer< ENUM > * __WrapEnumPointer(ENUM * a_pDefaultValue)
{
    bTPropertyContainer< ENUM > * pWrapped = 0;
    if(a_pDefaultValue != 0)
    {
        pWrapped = GE_NEW(bTPropertyContainer< ENUM >)( *a_pDefaultValue );
        GE_DELETE(a_pDefaultValue);
    }

    return pWrapped;
}

template< typename OBJECTCLASS, typename CLASS >
GEBool mTDefaultPropertyType<OBJECTCLASS, CLASS>::HasDefaultValue( void ) const
{
    return m_pDefaultValue != 0;
}

template< typename OBJECTCLASS, typename CLASS >
GELPCVoid mTDefaultPropertyType<OBJECTCLASS, CLASS>::GetDefaultValue( void ) const
{
    return m_pDefaultValue;
}

template< typename OBJECTCLASS, typename CLASS >
void mTDefaultPropertyType<OBJECTCLASS, CLASS>::Destroy( void )
{
    bTPropertyType<OBJECTCLASS, CLASS>::Destroy();
    GE_DELETE( m_pDefaultValue );
}

template< typename OBJECTCLASS, typename CLASS >
mTDefaultPropertyType<OBJECTCLASS, CLASS>::mTDefaultPropertyType( bCPropertyObjectTypeBase & a_pPropertyObjectType, GEU32 a_u32MemberOffset, bCString const & a_strPropertyName, bEPropertyType a_enuPropertyType, CLASS * a_pDefaultValue )
    : bTPropertyType( a_pPropertyObjectType, a_u32MemberOffset, a_strPropertyName, a_enuPropertyType ), m_pDefaultValue( a_pDefaultValue )
{}


template< typename OBJECTCLASS, typename CLASS >
CLASS const * mTDefaultPropertyType<OBJECTCLASS, CLASS>::GetDefaultValueType(void) const
{
    return m_pDefaultValue;
}
