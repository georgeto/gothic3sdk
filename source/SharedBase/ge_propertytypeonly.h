#ifndef GE_PROPERTYTYPEONLY_H_INCLUDED
#define GE_PROPERTYTYPEONLY_H_INCLUDED

#pragma warning ( push )
#pragma warning ( disable : 4625 )// copy constructor could not be generated because a base class copy constructor is inaccessible
template< typename CLASS >
class bTPropertyTypeOnly :
    public bCPropertyTypeBase
{
    public: virtual void          PropertySetter( bCPropertyObjectBase * a_pPropertyObject, CLASS const & a_pValue ) = 0;
    public: virtual CLASS const * PropertyGetter( bCPropertyObjectBase const * a_pPropertyObject )                         = 0;
    public: virtual CLASS *       PropertyAccessor( bCPropertyObjectBase * a_pPropertyObject )                       = 0;
    public: virtual              ~bTPropertyTypeOnly( void );

    public:
        bTPropertyTypeOnly( bCString const & a_strPropertyName, bCString const & a_strPropertyCategory, bCString const & a_strPropertyDescription, bEPropertyType a_enuPropertyType, GEBool a_bReadOnly );
        bTPropertyTypeOnly( bCString const & a_strPropertyName, bCString const & a_strPropertyCategory, bEPropertyType a_enuPropertyType, GEBool a_bReadOnly );
        bTPropertyTypeOnly( bCString const & a_strPropertyName, bEPropertyType a_enuPropertyType );
    private:
        bTPropertyTypeOnly< CLASS > & operator = ( bTPropertyTypeOnly< CLASS > const & );  // not defined
};

#include "ge_propertytypeonly.inl"
#pragma warning ( pop )

namespace {
    typedef bTPropertyTypeOnly<bCObjectBase> bTPropertyTypeOnly_DUMMY;
    GE_ASSERT_SIZEOF( bTPropertyTypeOnly_DUMMY, 0x18 );
}

#endif