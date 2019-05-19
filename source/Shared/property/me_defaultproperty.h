#ifndef ME_DEFAULTPROPERTY_H_INCLUDED
#define ME_DEFAULTPROPERTY_H_INCLUDED

#include "SharedBase.h"

//
// Property
//
#define ME_DECLARE_DEFAULT_PROPERTY_TYPE( OBJECTCLASS, TYPE, MEMBERNAME ) \
    public:                                                               \
        static mTDefaultPropertyType<OBJECTCLASS, TYPE> ms_PropertyMember_ ## MEMBERNAME;

#define ME_DEFINE_DEFAULT_PROPERTY( OBJECTCLASS, TYPE, MEMBERNAME, PROPERTYNAME ) \
    GE_DEFINE_PROPERTY_ACCESS( TYPE, PROPERTYNAME, MEMBERNAME )                   \
    GE_DECLARE_PROPERTY_MEMBER( TYPE, MEMBERNAME )                                \
    ME_DECLARE_DEFAULT_PROPERTY_TYPE( OBJECTCLASS, TYPE, MEMBERNAME )

#define __ME_DEFINE_DEFAULT_PROPERTY_TYPE( OBJECTCLASS, TYPE, MEMBERNAME, PROPERTYNAME, PROPERTYTYPE, DEFAULTVALUE ) \
    mTDefaultPropertyType<OBJECTCLASS, TYPE> OBJECTCLASS::ms_PropertyMember_ ## MEMBERNAME( OBJECTCLASS::ms_PropertyObjectInstance_ ## OBJECTCLASS.GetTypeInstance(), offsetof( OBJECTCLASS, MEMBERNAME ), #PROPERTYNAME, PROPERTYTYPE, DEFAULTVALUE );

#define ME_DEFINE_DEFAULT_PROPERTY_TYPE( OBJECTCLASS, TYPE, MEMBERNAME, PROPERTYNAME, DEFAULTVALUE ) \
    __ME_DEFINE_DEFAULT_PROPERTY_TYPE( OBJECTCLASS, TYPE, MEMBERNAME, PROPERTYNAME, bEPropertyType_Normal, DEFAULTVALUE )

//
// Enumeration Property
//

#define ME_DEFINE_DEFAULT_ENUMPROP( OBJECTCLASS, ENUM, MEMBERNAME, PROPERTYNAME ) \
    ME_DEFINE_DEFAULT_PROPERTY( OBJECTCLASS, bTPropertyContainer< ENUM >, MEMBERNAME, PROPERTYNAME )

template< typename ENUM >
inline bTPropertyContainer< ENUM > * __WrapEnumPointer( ENUM * a_pDefaultValue );

#define ME_DEFINE_DEFAULT_ENUMPROP_TYPE( OBJECTCLASS, ENUM, MEMBERNAME, PROPERTYNAME, DEFAULTVALUE ) \
    __ME_DEFINE_DEFAULT_PROPERTY_TYPE( OBJECTCLASS, bTPropertyContainer< ENUM >, MEMBERNAME, PROPERTYNAME, bEPropertyType_PropertyContainer, __WrapEnumPointer( DEFAULTVALUE ) )

class mCDefaultPropertyTypeBase
{
    public: virtual GEBool    HasDefaultValue( void ) const = 0;
    public: virtual GELPCVoid GetDefaultValue( void ) const = 0;
};

template< typename OBJECTCLASS, typename CLASS >
class mTDefaultPropertyType :
    public bTPropertyType< OBJECTCLASS, CLASS >,
    public mCDefaultPropertyTypeBase
{
    public:    virtual GEBool    HasDefaultValue( void ) const;
    public:    virtual GELPCVoid GetDefaultValue( void ) const;
    protected: virtual void      Destroy( void );

    public:
        mTDefaultPropertyType( bCPropertyObjectTypeBase & a_pPropertyObjectType, GEU32 a_u32MemberOffset, bCString const & a_strPropertyName, bEPropertyType a_enuPropertyType, CLASS * a_pDefaultValue = 0 );

    public:
        CLASS const * GetDefaultValueType( void ) const;

    private:
        CLASS * m_pDefaultValue;
};

#include "me_defaultproperty.inl"

#endif
