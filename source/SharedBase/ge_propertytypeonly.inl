template< typename CLASS >
bTPropertyTypeOnly<CLASS>::bTPropertyTypeOnly(bCString const & a_strPropertyName, bEPropertyType a_enuPropertyType)
    : bCPropertyTypeBase(a_strPropertyName, a_enuPropertyType)
{

}

template< typename CLASS >
bTPropertyTypeOnly<CLASS>::bTPropertyTypeOnly(bCString const & a_strPropertyName, bCString const & a_strPropertyCategory, bEPropertyType a_enuPropertyType, GEBool a_bReadOnly)
     : bCPropertyTypeBase(a_strPropertyName, a_strPropertyCategory, a_enuPropertyType, a_bReadOnly)
{

}

template< typename CLASS >
bTPropertyTypeOnly<CLASS>::bTPropertyTypeOnly(bCString const & a_strPropertyName, bCString const & a_strPropertyCategory, bCString const & a_strPropertyDescription, bEPropertyType a_enuPropertyType, GEBool a_bReadOnly)
    : bCPropertyTypeBase(a_strPropertyName, a_strPropertyCategory, a_strPropertyDescription, a_enuPropertyType,  a_bReadOnly)
{

}

template< typename CLASS >
bTPropertyTypeOnly<CLASS>::~bTPropertyTypeOnly(void)
{
}