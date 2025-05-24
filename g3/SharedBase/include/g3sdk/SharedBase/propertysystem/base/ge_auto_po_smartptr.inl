#include <SharedBase/kernel/object/ge_classname.h>
#include <SharedBase/propertysystem/acessors/ge_accessorcreator.h>

template <typename CLASS>
void bTAutoPOSmartPtr<CLASS>::CopyFrom(bTAutoPOSmartPtr<CLASS> const &a_Source)
{
    Destroy();
    SetPropertyObject(a_Source.m_pPropertyObject);
}

template <typename CLASS>
void bTAutoPOSmartPtr<CLASS>::Create()
{
    Destroy();
    bCAccessorCreator Creator(bTClassName<CLASS>::GetUnmangled());
    SetPropertyObject(static_cast<bTPOPureSmartPtr<CLASS> *>(static_cast<bCPropertyObjectBase *>(Creator)));
}

template <typename CLASS>
void bTAutoPOSmartPtr<CLASS>::Destroy()
{
    if (m_pPropertyObject)
    {
        m_pPropertyObject->ReleaseReference();
        m_pPropertyObject = nullptr;
    }
}

template <typename CLASS>
void bTAutoPOSmartPtr<CLASS>::SetPropertyObject(bTPOPureSmartPtr<CLASS> *a_Source)
{
    Destroy();
    if (a_Source)
        a_Source->AddReference();
    m_pPropertyObject = a_Source;
}

template <typename CLASS>
bTAutoPOSmartPtr<CLASS>::bTAutoPOSmartPtr()
{
    Create();
}

template <typename CLASS>
bTAutoPOSmartPtr<CLASS>::bTAutoPOSmartPtr(CLASS &a_Object)
{
    m_pPropertyObject = reinterpret_cast<bTPOPureSmartPtr<CLASS> *>(a_Object.GetPropertyObject());
    if (m_pPropertyObject)
        m_pPropertyObject->AddReference();
}

template <typename CLASS>
bTAutoPOSmartPtr<CLASS>::~bTAutoPOSmartPtr()
{
    Destroy();
}

template <typename CLASS>
bTAutoPOSmartPtr<CLASS> &bTAutoPOSmartPtr<CLASS>::operator=(bTAutoPOSmartPtr<CLASS> const &a_Source)
{
    this->CopyFrom(a_Source);
    return *this;
}

template <typename CLASS>
bTAutoPOSmartPtr<CLASS>::operator CLASS *()
{
    return reinterpret_cast<CLASS *>(m_pPropertyObject->GetObject());
}

template <typename CLASS>
bTAutoPOSmartPtr<CLASS>::operator CLASS const *() const
{
    return reinterpret_cast<CLASS const *>(m_pPropertyObject->GetObject());
}

template <typename CLASS>
CLASS *bTAutoPOSmartPtr<CLASS>::operator->()
{
    return reinterpret_cast<CLASS *>(m_pPropertyObject->GetObject());
}

template <typename CLASS>
CLASS const *bTAutoPOSmartPtr<CLASS>::operator->() const
{
    return reinterpret_cast<CLASS const *>(m_pPropertyObject->GetObject());
}

template <typename CLASS>
bCIStream &bTAutoPOSmartPtr<CLASS>::operator<<(bCIStream &a_IStream)
{
    GEU16 u16Version;
    u16Version << a_IStream;
    GEBool bHasPropertyObject;
    bHasPropertyObject << a_IStream;

    if (bHasPropertyObject)
    {
        Create();
        m_pPropertyObject->Read(a_IStream);
    }
    else
    {
        Destroy();
    }

    return a_IStream;
}

template <typename CLASS>
bCOStream &bTAutoPOSmartPtr<CLASS>::operator>>(bCOStream &a_OStream)
{
    static_cast<GEU16>(1) >> a_OStream;
    static_cast<GEBool>(m_pPropertyObject != nullptr) >> a_OStream;
    if (m_pPropertyObject)
        m_pPropertyObject->Write(a_OStream);
    return a_OStream;
}
