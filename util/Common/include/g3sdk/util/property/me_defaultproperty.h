#pragma once

#include <g3sdk/SharedBase.h>

#define ME_PROPERTY_SET(CLASS, BASECLASS)                                                                              \
    using THIS_CLASS = CLASS;                                                                                          \
    using BASE_CLASS = BASECLASS;                                                                                      \
    GE_DECLARE_PROPERTY_OBJECT(CLASS, BASECLASS)

//
// Property
//
#define ME_DECLARE_DEFAULT_PROPERTY_TYPE(OBJECTCLASS, TYPE, MEMBERNAME)                                                \
  public:                                                                                                              \
    static mTDefaultPropertyType<OBJECTCLASS, TYPE> ms_PropertyMember_##MEMBERNAME;

#define ME_DEFINE_DEFAULT_PROPERTY(TYPE, MEMBERNAME, PROPERTYNAME)                                                     \
    GE_DEFINE_PROPERTY_ACCESS(TYPE, PROPERTYNAME, MEMBERNAME)                                                          \
    GE_DECLARE_PROPERTY_WRAPPER(TYPE, PROPERTYNAME)                                                                    \
    GE_DECLARE_PROPERTY_MEMBER(TYPE, MEMBERNAME)                                                                       \
    ME_DECLARE_DEFAULT_PROPERTY_TYPE(THIS_CLASS, TYPE, MEMBERNAME)

#define __ME_DEFINE_DEFAULT_PROPERTY_TYPE(OBJECTCLASS, MEMBERNAME, PROPERTYNAME, PROPERTYTYPE, DEFAULTVALUE)           \
    decltype(OBJECTCLASS::ms_PropertyMember_##MEMBERNAME) OBJECTCLASS::ms_PropertyMember_##MEMBERNAME(                 \
        OBJECTCLASS::ms_PropertyObjectInstance_##OBJECTCLASS.GetTypeInstance(), offsetof(OBJECTCLASS, MEMBERNAME),     \
        #PROPERTYNAME, PROPERTYTYPE, DEFAULTVALUE);

#define ME_DEFINE_DEFAULT_PROPERTY_TYPE(OBJECTCLASS, MEMBERNAME, PROPERTYNAME, DEFAULTVALUE)                           \
    __ME_DEFINE_DEFAULT_PROPERTY_TYPE(OBJECTCLASS, MEMBERNAME, PROPERTYNAME, bEPropertyType_Normal, DEFAULTVALUE)

//
// Enumeration Property
//

#define ME_DEFINE_DEFAULT_ENUMPROP(ENUM, PROPERTYNAME)                                                                 \
    ME_DEFINE_DEFAULT_PROPERTY(bTPropertyContainer<ENUM>, m_enu##PROPERTYNAME, PROPERTYNAME)

template <typename ENUM>
inline bTPropertyContainer<ENUM> *__WrapEnumPointer(ENUM *a_pDefaultValue);

template <typename OBJECLASS, typename ENUM>
void __CopyEnumValues(bTPropertyType<OBJECLASS, ENUM> &Destination, bTPropertyTypeOnly<ENUM> const &Source);

#define ME_DEFINE_DEFAULT_ENUMPROP_TYPE(OBJECTCLASS, PROPERTYNAME, DEFAULTVALUE)                                       \
    __ME_DEFINE_DEFAULT_PROPERTY_TYPE(OBJECTCLASS, m_enu##PROPERTYNAME, PROPERTYNAME,                                  \
                                      bEPropertyType_PropertyContainer, __WrapEnumPointer(DEFAULTVALUE))

#define ME_COPY_ENUM_VALUES(OBJECTCLASS, PROPERTYNAME, SOURCE_PROPERTY_TYPE)                                           \
    GE_STATIC_BLOCK                                                                                                    \
    {                                                                                                                  \
        __CopyEnumValues(OBJECTCLASS::ms_PropertyMember_##m_enu##PROPERTYNAME, SOURCE_PROPERTY_TYPE);                  \
    }

//
// String Property
//
#define ME_DEFINE_DEFAULT_STRPROP(PROPERTYNAME) ME_DEFINE_DEFAULT_PROPERTY(bCString, m_str##PROPERTYNAME, PROPERTYNAME)

#define ME_DEFINE_DEFAULT_STRPROP_TYPE(OBJECTCLASS, PROPERTYNAME, DEFAULTVALUE)                                        \
    ME_DEFINE_DEFAULT_PROPERTY_TYPE(OBJECTCLASS, m_str##PROPERTYNAME, PROPERTYNAME, DEFAULTVALUE)

class mCDefaultPropertyTypeBase
{
  public:
    virtual GEBool HasDefaultValue() const = 0;

  public:
    virtual GELPCVoid GetDefaultValue() const = 0;
};

template <typename OBJECTCLASS, typename CLASS>
class mTDefaultPropertyType : public bTPropertyType<OBJECTCLASS, CLASS>, public mCDefaultPropertyTypeBase
{
  public:
    virtual GEBool HasDefaultValue() const;

  public:
    virtual GELPCVoid GetDefaultValue() const;

  protected:
    virtual void Destroy();

  public:
    mTDefaultPropertyType(bCPropertyObjectTypeBase &a_pPropertyObjectType, GEU32 a_u32MemberOffset,
                          bCString const &a_strPropertyName, bEPropertyType a_enuPropertyType,
                          CLASS *a_pDefaultValue = 0);

  public:
    CLASS const *GetDefaultValueType() const;

  private:
    CLASS *m_pDefaultValue;
};

#include "me_defaultproperty.inl"
