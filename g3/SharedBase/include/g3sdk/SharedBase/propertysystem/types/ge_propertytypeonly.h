#pragma once

#include <SharedBase/propertysystem/types/ge_propertytypebase.h>

template <typename CLASS>
class bTPropertyTypeOnly : public bCPropertyTypeBase
{
    // clang-format off
    public: virtual void          PropertySetter( bCPropertyObjectBase * a_pPropertyObject, CLASS const & a_pValue ) = 0;
    public: virtual CLASS const * PropertyGetter( bCPropertyObjectBase const * a_pPropertyObject )                         = 0;
    public: virtual CLASS *       PropertyAccessor( bCPropertyObjectBase * a_pPropertyObject )                       = 0;
    public: ~bTPropertyTypeOnly( ) override;
    // clang-format on

  public:
    bTPropertyTypeOnly(bCString const &a_strPropertyName, bCString const &a_strPropertyCategory,
                       bCString const &a_strPropertyDescription, bEPropertyType a_enuPropertyType, GEBool a_bReadOnly);
    bTPropertyTypeOnly(bCString const &a_strPropertyName, bCString const &a_strPropertyCategory,
                       bEPropertyType a_enuPropertyType, GEBool a_bReadOnly);
    bTPropertyTypeOnly(bCString const &a_strPropertyName, bEPropertyType a_enuPropertyType);

  public:
    bTPropertyTypeOnly<CLASS> &operator=(bTPropertyTypeOnly<CLASS> const &) = delete;
};

#include "ge_propertytypeonly.inl"

using bTPropertyTypeOnly_DUMMY = bTPropertyTypeOnly<bCObjectBase>;
GE_ASSERT_SIZEOF(bTPropertyTypeOnly_DUMMY, 0x18)
