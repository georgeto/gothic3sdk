template< typename CLASS >
GEU16 bTPOPureSmartPtr<CLASS>::Read(bCIStream & a_IStream)
{
    if(!m_pObject)
        Create();
    *m_pObject << a_IStream;
    return 83;
}


template< typename CLASS >
void bTPOPureSmartPtr<CLASS>::Write(bCOStream & a_OStream)
{
    a_OStream << *m_pObject;
}

template< typename CLASS >
void bTPOPureSmartPtr<CLASS>::Destroy(void)
{
    if(m_pObject && m_pObject->GetReferenceCount() == 1)
        m_pObject->Destroy();
    if(m_pObject)
    {
        m_pObject->SetPropertyObject(0);
        m_pObject->ReleaseVirtualReference();
    }
    m_pObject = 0;
}

template< typename CLASS >
void bTPOPureSmartPtr<CLASS>::Create(void)
{
    Destroy();
    if(IsRoot())
        bCPropertyObjectSingleton::GetInstance().EnableRegistration(this, GEFalse);

    CLASS * pObjRefBase = 0;
    if(!IsRoot())
        pObjRefBase = GE_NEW( CLASS );

    if(IsRoot())
        bCPropertyObjectSingleton::GetInstance().EnableRegistration(this, GETrue);

    if(!IsRoot())
    {
        if(pObjRefBase)
        {
            pObjRefBase->Create();
            SetObjectInternal(pObjRefBase);

            if(!IsRoot())
            {
                bCPropertyObjectBase const * pPropertyObject = pObjRefBase->GetPropertyObject();
                pObjRefBase->SetPropertyObject(0);
                pObjRefBase->ReleaseVirtualReference();
                pObjRefBase->SetPropertyObject(pPropertyObject);
            }
        }
        else
        {
            GE_FATAL_ERROR_EX(__FUNCDNAME__"- dynamic_cast<bCObjectRefBase*> objecttype isn¦t derived from bCObjectRefBase !", "GEFalse == (NULL != pObjRefBase)")
            // Destroy();
        }
    }
}

template< typename CLASS >
bool bTPOPureSmartPtr<CLASS>::SetObject(bCObjectRefBase * a_pObjRefBase)
{
    CLASS * pObject = dynamic_cast<CLASS *>(a_pObjRefBase);
    if(pObject)
    {
        SetObjectInternal(pObject);
        return GETrue;
    }

    return GEFalse;
}

template< typename CLASS >
void bTPOPureSmartPtr<CLASS>::CopyFrom(bCPropertyObjectBase const & a_Source)
{
    if(!m_pObject)
        Create();
    m_pObject->CopyFrom(*a_Source.GetObject());

}


template< typename CLASS >
bTPOPureSmartPtr<CLASS>::bTPOPureSmartPtr(void) : m_pObject(0)
{
}

template< typename CLASS >
bTPOPureSmartPtr<CLASS>::~bTPOPureSmartPtr(void)
{
    Destroy();
}


template< typename CLASS >
void bTPOPureSmartPtr<CLASS>::SetObjectInternal(CLASS * a_pObjRefBase)
{
    if(a_pObjRefBase)
        a_pObjRefBase->AddVirtualReference();

    Destroy();
    if(a_pObjRefBase)
        a_pObjRefBase->SetPropertyObject(this);
    m_pObject = a_pObjRefBase;
}
