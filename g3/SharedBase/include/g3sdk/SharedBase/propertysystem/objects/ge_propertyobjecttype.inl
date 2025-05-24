#include <SharedBase/kernel/object/ge_classname.h>
#include <SharedBase/propertysystem/factories/ge_propertyobjectsingleton.h>

#pragma warning(push)
#pragma warning(disable : 4640) // 's_PropertyObjectType' : construction of local static object is not thread safe
template <typename CLASS, typename BASECLASS>
bTPropertyObjectType<CLASS, BASECLASS> &bTPropertyObjectType<CLASS, BASECLASS>::GetInstance()
{
    static bTPropertyObjectType<CLASS, BASECLASS> s_Instance;
    return s_Instance;
}
#pragma warning(pop)

template <typename CLASS, typename BASECLASS>
bTPropertyObjectType<CLASS, BASECLASS>::bTPropertyObjectType()
    : bCPropertyObjectTypeBase(GETrue), m_PropertyObjectFactory(GetClassName())
{
    bCPropertyObjectSingleton::GetInstance().RegisterTemplate(this);
}

template <typename CLASS, typename BASECLASS>
bTPropertyObjectType<CLASS, BASECLASS>::~bTPropertyObjectType()
{}

template <typename CLASS, typename BASECLASS>
void bTPropertyObjectType<CLASS, BASECLASS>::CopyFrom(bCPropertyObjectTypeBase const &a_Source)
{
    GE_IMPROPER_USAGE(
        "It is not allowed to make a copy of propertytype.\nDo not call it from derived class or change access !");
    return bCPropertyObjectTypeBase::CopyFrom(a_Source);
}

template <typename CLASS, typename BASECLASS>
bCPropertyObjectTypeBase *bTPropertyObjectType<CLASS, BASECLASS>::DoClone() const
{
    GE_IMPROPER_USAGE(
        "It is not allowed to make a clone of propertytype.\nDo not call it from derived class or change access !");
    return nullptr;
}

template <typename CLASS, typename BASECLASS>
void bTPropertyObjectType<CLASS, BASECLASS>::Write(bCOStream &)
{
    GE_IMPROPER_USAGE("METHOD Read/Write not used for current implementation!");
}

template <typename CLASS, typename BASECLASS>
GEU16 bTPropertyObjectType<CLASS, BASECLASS>::Read(bCIStream &)
{
    GE_IMPROPER_USAGE("bTPropertyObjectType<CLASS, BASECLASS>::Read");
    return 1;
}

template <typename CLASS, typename BASECLASS>
bCPropertyObjectFactory *bTPropertyObjectType<CLASS, BASECLASS>::AccessObjectFactory()
{
    return &m_PropertyObjectFactory;
}

template <typename CLASS, typename BASECLASS>
bCPropertyObjectFactory const *bTPropertyObjectType<CLASS, BASECLASS>::GetObjectFactory() const
{
    return &m_PropertyObjectFactory;
}

template <typename CLASS, typename BASECLASS>
bCString const &bTPropertyObjectType<CLASS, BASECLASS>::GetBaseClassName() const
{
    return bTClassName<BASECLASS>::GetUnmangled();
}

template <typename CLASS, typename BASECLASS>
bCString const &bTPropertyObjectType<CLASS, BASECLASS>::GetClassName() const
{
    return bTClassName<CLASS>::GetUnmangled();
}
