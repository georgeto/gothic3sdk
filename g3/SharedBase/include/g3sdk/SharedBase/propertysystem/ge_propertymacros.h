#pragma once

#include <SharedBase/kernel/error/ge_error.h>
#include <SharedBase/types/ge_def.h>

//
// Property Object
//

#define GE_DECLARE_PROPERTY_OBJECT(CLASS, BASECLASS)                                                                   \
  public:                                                                                                              \
    static bCPropertyObjectBase const *GE_STDCALL GetRootObject();                                                     \
                                                                                                                       \
  public:                                                                                                              \
    CLASS();                                                                                                           \
    CLASS(CLASS const &);                                                                                              \
                                                                                                                       \
  public:                                                                                                              \
    CLASS const &operator=(CLASS const &);                                                                             \
                                                                                                                       \
  private:                                                                                                             \
    static bTPropertyObject<CLASS, BASECLASS> ms_PropertyObjectInstance_##CLASS;

#define GE_DEFINE_PROPERTY_OBJECT(CLASS, BASECLASS)                                                                    \
    bCPropertyObjectBase const *GE_STDCALL CLASS::GetRootObject()                                                      \
    {                                                                                                                  \
        static bCPropertyObjectBase const *s_pRootObject =                                                             \
            bCPropertyObjectSingleton::GetInstance().GetRootObject(#CLASS);                                            \
        return s_pRootObject;                                                                                          \
    }                                                                                                                  \
    CLASS::CLASS()                                                                                                     \
    {}                                                                                                                 \
    CLASS::CLASS(CLASS const &)                                                                                        \
    {}                                                                                                                 \
    CLASS const &CLASS::operator=(CLASS const &a_Other)                                                                \
    {                                                                                                                  \
        if (this->GetPropertyObject() && a_Other.GetPropertyObject())                                                  \
            *this->GetPropertyObject() = *a_Other.GetPropertyObject();                                                 \
        else                                                                                                           \
            this->CopyFrom(a_Other);                                                                                   \
        return *this;                                                                                                  \
    }                                                                                                                  \
    bTPropertyObject<CLASS, BASECLASS> CLASS::ms_PropertyObjectInstance_##CLASS(GETrue);

//
// Property
//

#define GE_DECLARE_PROPERTY_MEMBER(TYPE, MEMBERNAME)                                                                   \
  protected:                                                                                                           \
    TYPE MEMBERNAME;

#define GE_DECLARE_PROPERTY_GETTER(TYPE, PROPERTYNAME)                                                                 \
  public:                                                                                                              \
    TYPE const &Get##PROPERTYNAME() const;

#define GE_DECLARE_PROPERTY_SETTER(TYPE, PROPERTYNAME)                                                                 \
  public:                                                                                                              \
    void Set##PROPERTYNAME(TYPE const &a_Value);

#define GE_DECLARE_PROPERTY_GETSET(TYPE, PROPERTYNAME)                                                                 \
    GE_DECLARE_PROPERTY_GETTER(TYPE, PROPERTYNAME)                                                                     \
    GE_DECLARE_PROPERTY_SETTER(TYPE, PROPERTYNAME)

#define GE_DECLARE_PROPERTY_ACCESS(TYPE, PROPERTYNAME)                                                                 \
    GE_DECLARE_PROPERTY_GETSET(TYPE, PROPERTYNAME)                                                                     \
  public:                                                                                                              \
    TYPE &Access##PROPERTYNAME();

#define GE_DECLARE_PROPERTY_TYPE(OBJECTCLASS, TYPE, MEMBERNAME)                                                        \
  public:                                                                                                              \
    static bTPropertyType<OBJECTCLASS, TYPE> ms_PropertyMember_##MEMBERNAME;

// NOTE: GE_DECLARE_PROPERTY ends with protected scope.
#define GE_DECLARE_PROPERTY(TYPE, MEMBERNAME, PROPERTYNAME)                                                            \
    GE_DECLARE_PROPERTY_ACCESS(TYPE, PROPERTYNAME)                                                                     \
    GE_DECLARE_PROPERTY_MEMBER(TYPE, MEMBERNAME)

#define GE_DEFINE_PROPERTY_GETTER(TYPE, PROPERTYNAME, MEMBERNAME)                                                      \
  public:                                                                                                              \
    TYPE const &Get##PROPERTYNAME() const                                                                              \
    {                                                                                                                  \
        return this->MEMBERNAME;                                                                                       \
    }

#define GE_DEFINE_PROPERTY_SETTER(TYPE, PROPERTYNAME, MEMBERNAME)                                                      \
  public:                                                                                                              \
    void Set##PROPERTYNAME(TYPE const &a_Value)                                                                        \
    {                                                                                                                  \
        NotifyPropertyValueChangedEnterEx(#PROPERTYNAME, GEFalse);                                                     \
        this->MEMBERNAME = a_Value;                                                                                    \
        NotifyPropertyValueChangedExitEx(#PROPERTYNAME, GEFalse);                                                      \
    }

#define GE_DEFINE_PROPERTY_GETSET(TYPE, PROPERTYNAME, MEMBERNAME)                                                      \
    GE_DEFINE_PROPERTY_GETTER(TYPE, PROPERTYNAME, MEMBERNAME)                                                          \
    GE_DEFINE_PROPERTY_SETTER(TYPE, PROPERTYNAME, MEMBERNAME)

#define GE_DEFINE_PROPERTY_ACCESS(TYPE, PROPERTYNAME, MEMBERNAME)                                                      \
    GE_DEFINE_PROPERTY_GETSET(TYPE, PROPERTYNAME, MEMBERNAME)                                                          \
  public:                                                                                                              \
    TYPE &Access##PROPERTYNAME()                                                                                       \
    {                                                                                                                  \
        return this->MEMBERNAME;                                                                                       \
    }

#define GE_DEFINE_INLINE_PROPERTY_ACCESS(TYPE, PROPERTY_NAME, MEMBER_NAME)                                             \
  public:                                                                                                              \
    GE_NO_DLLIMPORT                                                                                                    \
    inline TYPE &Access##PROPERTY_NAME()                                                                               \
    {                                                                                                                  \
        return this->MEMBER_NAME;                                                                                      \
    }                                                                                                                  \
                                                                                                                       \
  public:                                                                                                              \
    GE_NO_DLLIMPORT                                                                                                    \
    inline TYPE const &Get##PROPERTY_NAME() const                                                                      \
    {                                                                                                                  \
        return this->MEMBER_NAME;                                                                                      \
    }                                                                                                                  \
    GE_DECLARE_PROPERTY_SETTER(TYPE, PROPERTY_NAME)

// NOTE: GE_DEFINE_PROPERTY ends with protected scope.
#define GE_DEFINE_PROPERTY(OBJECTCLASS, TYPE, MEMBERNAME, PROPERTYNAME)                                                \
    GE_DEFINE_PROPERTY_ACCESS(TYPE, PROPERTYNAME, MEMBERNAME)                                                          \
    GE_DECLARE_PROPERTY_WRAPPER(TYPE, PROPERTYNAME)                                                                    \
    GE_DECLARE_PROPERTY_MEMBER(TYPE, MEMBERNAME)                                                                       \
    GE_DECLARE_PROPERTY_TYPE(OBJECTCLASS, TYPE, MEMBERNAME)

#define __GE_DEFINE_PROPERTY_TYPE(OBJECTCLASS, TYPE, MEMBERNAME, PROPERTYNAME, PROPERTYTYPE)                           \
    bTPropertyType<OBJECTCLASS, TYPE> OBJECTCLASS::ms_PropertyMember_##MEMBERNAME(                                     \
        OBJECTCLASS::ms_PropertyObjectInstance_##OBJECTCLASS.GetTypeInstance(), offsetof(OBJECTCLASS, MEMBERNAME),     \
        #PROPERTYNAME, PROPERTYTYPE);

#define GE_DEFINE_PROPERTY_TYPE(OBJECTCLASS, TYPE, MEMBERNAME, PROPERTYNAME)                                           \
    __GE_DEFINE_PROPERTY_TYPE(OBJECTCLASS, TYPE, MEMBERNAME, PROPERTYNAME, bEPropertyType_Normal)

//
// Enumeration Property
//

#define GE_DECLARE_ENUMPROP_MEMBER(ENUM, MEMBERNAME) GE_DECLARE_PROPERTY_MEMBER(bTPropertyContainer<ENUM>, MEMBERNAME)

#define GE_DECLARE_ENUMPROP_GETTER(ENUM, PROPERTYNAME)                                                                 \
    GE_DECLARE_PROPERTY_GETTER(bTPropertyContainer<ENUM>, PROPERTYNAME)

#define GE_DECLARE_ENUMPROP_SETTER(ENUM, PROPERTYNAME)                                                                 \
    GE_DECLARE_PROPERTY_SETTER(bTPropertyContainer<ENUM>, PROPERTYNAME)

#define GE_DECLARE_ENUMPROP_GETSET(ENUM, PROPERTYNAME)                                                                 \
    GE_DECLARE_PROPERTY_GETSET(bTPropertyContainer<ENUM>, PROPERTYNAME)

#define GE_DECLARE_ENUMPROP_ACCESS(ENUM, PROPERTYNAME)                                                                 \
    GE_DECLARE_PROPERTY_ACCESS(bTPropertyContainer<ENUM>, PROPERTYNAME)

// NOTE: GE_DECLARE_ENUMPROP ends with protected scope.
#define GE_DECLARE_ENUMPROP(ENUM, MEMBERNAME, PROPERTYNAME)                                                            \
    GE_DECLARE_PROPERTY(bTPropertyContainer<ENUM>, MEMBERNAME, PROPERTYNAME)

// NOTE: GE_DEFINE_ENUMPROP ends with protected scope.
#define GE_DEFINE_ENUMPROP(OBJECTCLASS, ENUM, MEMBERNAME, PROPERTYNAME)                                                \
    GE_DEFINE_PROPERTY(OBJECTCLASS, bTPropertyContainer<ENUM>, MEMBERNAME, PROPERTYNAME)

#define GE_DEFINE_ENUMPROP_TYPE(OBJECTCLASS, ENUM, MEMBERNAME, PROPERTYNAME)                                           \
    __GE_DEFINE_PROPERTY_TYPE(OBJECTCLASS, bTPropertyContainer<ENUM>, MEMBERNAME, PROPERTYNAME,                        \
                              bEPropertyType_PropertyContainer)

#define GE_DEFINE_ENUM_VALUE(OBJECTCLASS, MEMBERNAME, VALUE)                                                           \
    GE_STATIC_BLOCK                                                                                                    \
    {                                                                                                                  \
        OBJECTCLASS::ms_PropertyMember_##MEMBERNAME.AddEnumValue(                                                      \
            GE_NEW(bTEnumWrapper<bTPropertyContainer<decltype(VALUE)>>)(#VALUE, VALUE));                               \
    }

#define GE_DEFINE_DEFAULT_ENUM_VALUE(OBJECTCLASS, MEMBERNAME, VALUE)                                                   \
    GE_STATIC_BLOCK                                                                                                    \
    {                                                                                                                  \
        OBJECTCLASS::ms_PropertyMember_##MEMBERNAME.AddDefaultEnumValue(                                               \
            GE_NEW(bTEnumWrapper<bTPropertyContainer<decltype(VALUE)>>)(#VALUE, VALUE));                               \
    }

//
// Property wrapper
//
#ifndef __INTELLISENSE__
#define GE_DECLARE_PROPERTY_WRAPPER(TYPE, PROPERTY_NAME)                                                               \
  public:                                                                                                              \
    GE_NO_DLLIMPORT                                                                                                    \
    inline TYPE const &_Get##PROPERTY_NAME() const                                                                     \
    {                                                                                                                  \
        return Get##PROPERTY_NAME();                                                                                   \
    }                                                                                                                  \
                                                                                                                       \
    GE_NO_DLLIMPORT                                                                                                    \
    inline void _Put##PROPERTY_NAME(TYPE const &a_Value)                                                               \
    {                                                                                                                  \
        Set##PROPERTY_NAME(a_Value);                                                                                   \
    }                                                                                                                  \
    __declspec(property(get = _Get##PROPERTY_NAME, put = _Put##PROPERTY_NAME)) TYPE PROPERTY_NAME;
#else
#define GE_DECLARE_PROPERTY_WRAPPER(TYPE, PROPERTY_NAME)                                                               \
    __declspec(property(get = _Get##PROPERTY_NAME, put = _Put##PROPERTY_NAME)) TYPE PROPERTY_NAME;
#endif

//
// Import and declare
//
#define GE_PROPERTY_SET(CLASS, BASECLASS)                                                                              \
    using THIS_CLASS = CLASS;                                                                                          \
    using BASE_CLASS = BASECLASS;                                                                                      \
    GE_DECLARE_PROPERTY_OBJECT(CLASS, BASECLASS)

#define GE_PROPERTY(TYPE, PROPERTY_NAME, MEMBER_NAME)                                                                  \
    GE_DECLARE_PROPERTY_TYPE(THIS_CLASS, TYPE, MEMBER_NAME)                                                            \
    GE_DEFINE_INLINE_PROPERTY_ACCESS(TYPE, PROPERTY_NAME, MEMBER_NAME)                                                 \
    GE_DECLARE_PROPERTY_WRAPPER(TYPE, PROPERTY_NAME)                                                                   \
    GE_DECLARE_PROPERTY_MEMBER(TYPE, MEMBER_NAME)

#define GE_ENUMPROP(TYPE, PROPERTY_NAME, MEMBER_NAME) GE_PROPERTY(bTPropertyContainer<TYPE>, PROPERTY_NAME, MEMBER_NAME)

#define GE_OBJECTPROP(CLASS, BASECLASS, PROPERTY_NAME, MEMBER_NAME)                                                    \
    using bTPropertyObject##_##CLASS##_##BASECLASS = bTPropertyObject<CLASS, BASECLASS>;                               \
    GE_PROPERTY(bTPropertyObject##_##CLASS##_##BASECLASS, PROPERTY_NAME, MEMBER_NAME)

#define GE_ASSERT_PROPERTY(CLASS, MEMBER_NAME, OFFSET, SIZE)                                                           \
    _GE_ASSERT_PROPERTY(CLASS, MEMBER_NAME, OFFSET, SIZE,                                                              \
                        GE_PASTE_TOKENS(__import_assert_property_##CLASS##_, __COUNTER__),                             \
                        GE_PASTE_TOKENS(__import_assert_property_##CLASS##_, __COUNTER__))

#define _GE_ASSERT_PROPERTY(CLASS, MEMBER_NAME, OFFSET, SIZE, HELPER_DERIVE, HELPER_CHECK)                             \
    class HELPER_DERIVE : public CLASS                                                                                 \
    {                                                                                                                  \
        friend class HELPER_CHECK;                                                                                     \
    };                                                                                                                 \
    class HELPER_CHECK                                                                                                 \
    {                                                                                                                  \
        static_assert(offsetof(HELPER_DERIVE, MEMBER_NAME) == OFFSET, "Unexpected member offset: " #MEMBER_NAME);      \
        static_assert(sizeof(HELPER_DERIVE::MEMBER_NAME) == SIZE, "Unexpected member size: " #MEMBER_NAME);            \
        GE_STATIC_ASSERT_EQUALS(CLASS, offsetof(HELPER_DERIVE, MEMBER_NAME), OFFSET);                                  \
        GE_STATIC_ASSERT_EQUALS(CLASS, sizeof(HELPER_DERIVE::MEMBER_NAME), SIZE);                                      \
    };

//
// Helpers
//
#define GE_ERROR_PURE_VIRTUAL()                                                                                        \
    GE_FATAL_ERROR_EX(__FUNCTION__, "The method detected an improper usage!\nHint: Pure virtual method call!")
