#ifndef GE_PROPERTYTYPE_H_INCLUDED
#define GE_PROPERTYTYPE_H_INCLUDED

#pragma warning ( push )
#pragma warning ( disable : 4625 )// copy constructor could not be generated because a base class copy constructor is inaccessible
template< typename OBJECTCLASS, typename CLASS >
class bTPropertyType :
    public bTPropertyTypeOnly< CLASS >
{

    public:    virtual GEU32                            GetMemberOffset( void ) const;
    public:    virtual GEU32                            GetDataSize( void ) const;
    public:    virtual bCString const &                 GetObjectTypeClassName( void ) const;
    public:    virtual bCString const &                 GetPropertyClassName( void ) const;
    public:    virtual bCPropertyObjectTypeBase const * GetObjectType( void ) const;
    public:    virtual GELPVoid                         PropertyInvalidate( bCPropertyObjectBase * a_pPropertyObject );
    public:    virtual GEBool                           HasEnumValues( void ) const;
    public:    virtual GEInt                            GetEnumValueCount() const;
    public:    virtual bCEnumWrapper const *            GetEnumValue( GEInt a_iIndex ) const;
    public:    virtual void                             PropertySet( bCPropertyObjectBase * a_pPropertyObject, GELPCVoid a_pValue );
    public:    virtual GELPCVoid                        PropertyGet( bCPropertyObjectBase const * a_pPropertyObject );
    public:    virtual GELPVoid                         PropertyAccess( bCPropertyObjectBase * a_pPropertyObject );
    public:    virtual GEBool                           PropertyCopy( bCPropertyObjectBase * a_pDestPropertyObject, bCPropertyObjectBase const * a_pSource );
    public:    virtual void                             PropertyWrite( bCOStream &, bCPropertyObjectBase * a_pSource );
    public:    virtual void                             PropertyRead( bCIStream &, bCPropertyObjectBase & a_pPropertyObject );
    public:    virtual void                             PropertyDeprecate( bCIStream &, bCPropertyObjectBase & a_pPropertyObject, bCString const &, bCString const &, GEBool a_bNotify );
    protected: virtual void                             Destroy( void );
    protected: virtual void                             Create( void );
    protected: virtual bCPropertyTypeBase *             DoClone( void ) const;
    protected: virtual void                             CopyFrom( bCPropertyTypeBase const & );
    public:    virtual                                 ~bTPropertyType( void );
    public:    virtual void                             PropertySetter( bCPropertyObjectBase * a_pPropertyObject, CLASS const & a_pValue );
    public:    virtual CLASS const *                    PropertyGetter( bCPropertyObjectBase const * a_pPropertyObject );
    public:    virtual CLASS *                          PropertyAccessor( bCPropertyObjectBase * a_pPropertyObject );

    public:
        bTPropertyType( bCPropertyObjectTypeBase & a_pPropertyObjectType, GEU32 a_u32MemberOffset, bCString const & a_strPropertyName, bCString const & a_strPropertyCategory, bCString const & a_strPropertyDescription, bEPropertyType a_enuPropertyType, GEBool a_bReadOnly );
        bTPropertyType( bCPropertyObjectTypeBase & a_pPropertyObjectType, GEU32 a_u32MemberOffset, bCString const & a_strPropertyName, bCString const & a_strPropertyCategory, bEPropertyType a_enuPropertyType, GEBool a_bReadOnly );
        bTPropertyType( bCPropertyObjectTypeBase & a_pPropertyObjectType, GEU32 a_u32MemberOffset, bCString const & a_strPropertyName, bEPropertyType a_enuPropertyType );

    public:
        void AddEnumValue( bTEnumWrapper < CLASS > * a_pEnumValue );
        void AddDefaultEnumValue( bTEnumWrapper < CLASS > * a_pEnumValue );

    private:
        bTPropertyType< OBJECTCLASS, CLASS > & operator = ( bTPropertyType< OBJECTCLASS, CLASS > const & );  // not defined

    private:
        bCPropertyObjectTypeBase *    m_pPropertyObjectType;
        GEU32                         m_u32MemberOffset;
        bTPtrArray<bCEnumWrapper *> * m_pArrEnumWrappers; // bTEnumWrappers mit gleichen Enums wie Property
};

#include "ge_propertytype.inl"
#pragma warning ( pop )

namespace
{
    typedef bTPropertyType<bCObjectBase, bCObjectBase> bTPropertyType_DUMMY;
    GE_ASSERT_SIZEOF( bTPropertyType_DUMMY, 0x24 );
}

#endif