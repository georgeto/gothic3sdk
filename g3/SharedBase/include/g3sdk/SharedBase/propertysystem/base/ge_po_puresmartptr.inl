#include <SharedBase/propertysystem/factories/ge_propertyobjectsingleton.h>

template <typename CLASS>
GEU16 bTPOPureSmartPtr<CLASS>::Read(bCIStream &a_IStream)
{
    if (!m_pObject)
        Create();
    *m_pObject << a_IStream;
    return 83;
}

template <typename CLASS>
void bTPOPureSmartPtr<CLASS>::Write(bCOStream &a_OStream)
{
    a_OStream << *m_pObject;
}

template <typename CLASS>
void bTPOPureSmartPtr<CLASS>::Destroy()
{
    if (m_pObject && m_pObject->GetReferenceCount() == 1)
        m_pObject->Destroy();
    if (m_pObject)
    {
        m_pObject->SetPropertyObject(nullptr);
        m_pObject->ReleaseVirtualReference();
    }
    m_pObject = nullptr;
}

template <typename CLASS>
void bTPOPureSmartPtr<CLASS>::Create()
{
    Destroy();
    if (IsRoot())
        bCPropertyObjectSingleton::GetInstance().EnableRegistration(this, GEFalse);

    CLASS *pObjRefBase = nullptr;
    if (!IsRoot())
        pObjRefBase = GE_NEW(CLASS);

    if (IsRoot())
        bCPropertyObjectSingleton::GetInstance().EnableRegistration(this, GETrue);

    if (!IsRoot())
    {
        if (pObjRefBase)
        {
            pObjRefBase->Create();
            SetObjectInternal(pObjRefBase);

            if (!IsRoot())
            {
                bCPropertyObjectBase const *pPropertyObject = pObjRefBase->GetPropertyObject();
                pObjRefBase->SetPropertyObject(nullptr);
                pObjRefBase->ReleaseVirtualReference();
                pObjRefBase->SetPropertyObject(pPropertyObject);
            }
        }
        else
        {
            GE_FATAL_ERROR_EX(
                __FUNCDNAME__ "- dynamic_cast<bCObjectRefBase*> objecttype isn¦t derived from bCObjectRefBase !",
                "GEFalse == (NULL != pObjRefBase)")
            // Destroy();
        }
    }
}

template <typename CLASS>
bool bTPOPureSmartPtr<CLASS>::SetObject(bCObjectRefBase *a_pObjRefBase)
{
    CLASS *pObject = dynamic_cast<CLASS *>(a_pObjRefBase);
    if (pObject)
    {
        SetObjectInternal(pObject);
        return GETrue;
    }

    return GEFalse;
}

template <typename CLASS>
void bTPOPureSmartPtr<CLASS>::CopyFrom(bCPropertyObjectBase const &a_Source)
{
    if (!m_pObject)
        Create();
    m_pObject->CopyFrom(*a_Source.GetObject());
}

template <typename CLASS>
bTPOPureSmartPtr<CLASS>::bTPOPureSmartPtr() : m_pObject(nullptr)
{}

template <typename CLASS>
bTPOPureSmartPtr<CLASS>::~bTPOPureSmartPtr()
{
    Destroy();
}

template <typename CLASS>
void bTPOPureSmartPtr<CLASS>::SetObjectInternal(CLASS *a_pObjRefBase)
{
    if (a_pObjRefBase)
        a_pObjRefBase->AddVirtualReference();

    Destroy();
    if (a_pObjRefBase)
        a_pObjRefBase->SetPropertyObject(this);
    m_pObject = a_pObjRefBase;
}
