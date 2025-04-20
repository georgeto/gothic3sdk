#pragma once

#include <SharedBase/propertysystem/types/ge_propertytypeonly.h>

template <typename OBJECTCLASS, typename CLASS>
class bTPropertyType : public bTPropertyTypeOnly<CLASS>
{
    // clang-format off
    public:    GEU32                            GetMemberOffset( ) const override;
    public:    GEU32                            GetDataSize( ) const override;
    public:    bCString const &                 GetObjectTypeClassName( ) const override;
    public:    bCString const &                 GetPropertyClassName( ) const override;
    public:    bCPropertyObjectTypeBase const * GetObjectType( ) const override;
    public:    GELPVoid                         PropertyInvalidate( bCPropertyObjectBase * a_pPropertyObject ) override;
    public:    GEBool                           HasEnumValues( ) const override;
    public:    GEInt                            GetEnumValueCount() const override;
    public:    bCEnumWrapper const *            GetEnumValue( GEInt a_iIndex ) const override;
    public:    void                             PropertySet( bCPropertyObjectBase * a_pPropertyObject, GELPCVoid a_pValue ) override;
    public:    GELPCVoid                        PropertyGet( bCPropertyObjectBase const * a_pPropertyObject ) override;
    public:    GELPVoid                         PropertyAccess( bCPropertyObjectBase * a_pPropertyObject ) override;
    public:    GEBool                           PropertyCopy( bCPropertyObjectBase * a_pDestPropertyObject, bCPropertyObjectBase const * a_pSource ) override;
    public:    void                             PropertyWrite( bCOStream &, bCPropertyObjectBase * a_pSource ) override;
    public:    void                             PropertyRead( bCIStream &, bCPropertyObjectBase & a_pPropertyObject ) override;
    public:    void                             PropertyDeprecate( bCIStream &, bCPropertyObjectBase & a_pPropertyObject, bCString const &, bCString const &, GEBool a_bNotify ) override;
    protected: void                             Destroy( ) override;
    protected: void                             Create( ) override;
    protected: bCPropertyTypeBase *             DoClone( ) const override;
    protected: void                             CopyFrom( bCPropertyTypeBase const & ) override;
    public:    ~bTPropertyType( ) override;
    public:    void                             PropertySetter( bCPropertyObjectBase * a_pPropertyObject, CLASS const & a_pValue ) override;
    public:    CLASS const *                    PropertyGetter( bCPropertyObjectBase const * a_pPropertyObject ) override;
    public:    CLASS *                          PropertyAccessor( bCPropertyObjectBase * a_pPropertyObject ) override;
    // clang-format on

  public:
    bTPropertyType(bCPropertyObjectTypeBase &a_pPropertyObjectType, GEU32 a_u32MemberOffset,
                   bCString const &a_strPropertyName, bCString const &a_strPropertyCategory,
                   bCString const &a_strPropertyDescription, bEPropertyType a_enuPropertyType, GEBool a_bReadOnly);
    bTPropertyType(bCPropertyObjectTypeBase &a_pPropertyObjectType, GEU32 a_u32MemberOffset,
                   bCString const &a_strPropertyName, bCString const &a_strPropertyCategory,
                   bEPropertyType a_enuPropertyType, GEBool a_bReadOnly);
    bTPropertyType(bCPropertyObjectTypeBase &a_pPropertyObjectType, GEU32 a_u32MemberOffset,
                   bCString const &a_strPropertyName, bEPropertyType a_enuPropertyType);

  public:
    void AddEnumValue(bTEnumWrapper<CLASS> *a_pEnumValue);
    void AddDefaultEnumValue(bTEnumWrapper<CLASS> *a_pEnumValue);

  public:
    bTPropertyType<OBJECTCLASS, CLASS> &operator=(bTPropertyType<OBJECTCLASS, CLASS> const &) = delete;

  private:
    bCPropertyObjectTypeBase *m_pPropertyObjectType;
    GEU32 m_u32MemberOffset;
    bTPtrArray<bCEnumWrapper *> *m_pArrEnumWrappers; // bTEnumWrappers mit gleichen Enums wie Property
};

#include "ge_propertytype.inl"

using bTPropertyType_DUMMY = bTPropertyType<bCObjectBase, bCObjectBase>;
GE_ASSERT_SIZEOF(bTPropertyType_DUMMY, 0x24)
