#include <SharedBase/kernel/object/ge_classname.h>
#include <SharedBase/kernel/object/ge_obsoleteclass.h>
#include <SharedBase/propertysystem/types/ge_propertytype.h>
#include <SharedBase/propertysystem/types/ge_propertytypeonly.h>

template <typename CLASS, typename BASECLASS>
bTPropertyObject<CLASS, BASECLASS>::~bTPropertyObject()
{
    Destroy();
}

template <typename CLASS, typename BASECLASS>
void bTPropertyObject<CLASS, BASECLASS>::CopyFrom(bCPropertyObjectBase const &a_Source)
{
    bCPropertyObjectBase::CopyFrom(a_Source);

    bCAccessorProperty AccessorProperty(bCAccessorCreator(this));

    while (GETrue)
    {
        if (AccessorProperty.IsValid())
        {
            AccessorProperty.GetPropertyTypeObject()->PropertyCopy(this, &a_Source);
        }

        if (!AccessorProperty.IsValid() && !AccessorProperty.GetAccessorPropertyObject().HasBaseClass())
            break;

        AccessorProperty++;
    }

    bTPOPureSmartPtr<CLASS>::CopyFrom(a_Source);
}

template <typename CLASS, typename BASECLASS>
bCPropertyObjectBase *bTPropertyObject<CLASS, BASECLASS>::DoClone() const
{
    bTPropertyObject<CLASS, BASECLASS> *pCloneObject = GE_NEW((bTPropertyObject<CLASS, BASECLASS>));
    if (!this->IsRoot())
        pCloneObject->CopyFrom(*this);
    return pCloneObject;
}

template <typename CLASS, typename BASECLASS>
void bTPropertyObject<CLASS, BASECLASS>::Create()
{
    CreateInternal(GEFalse);
}

template <typename CLASS, typename BASECLASS>
void bTPropertyObject<CLASS, BASECLASS>::Destroy()
{
    m_pPropertyObjectType->AccessObjectFactory()->UnregisterPropertyObject(this);
    bTPOPureSmartPtr<CLASS>::Destroy();
}

template <typename CLASS, typename BASECLASS>
void bTPropertyObject<CLASS, BASECLASS>::WriteData(bCOStream &a_OStream)
{
    bCPropertyObjectBase::WriteData(a_OStream);
    a_OStream << 0x1E;

    GEU32 u32ValidProperties = 0;

    {
        // Get amount of valid properties (!= bCObsoleteClass)
        bCAccessorProperty AccessorProperty(bCAccessorCreator(this));
        while (GETrue)
        {
            if (AccessorProperty.IsValid())
            {
                if (!dynamic_cast<bTPropertyTypeOnly<bCObsoleteClass> *>(AccessorProperty.GetPropertyTypeObject()))
                    u32ValidProperties++;
            }

            if (!AccessorProperty.IsValid() && !AccessorProperty.GetAccessorPropertyObject().HasBaseClass())
                break;

            AccessorProperty++;
        }
    }

    a_OStream << u32ValidProperties;
    {
        // Write properties
        bCAccessorProperty AccessorProperty(bCAccessorCreator(this));
        while (GETrue)
        {
            if (AccessorProperty.IsValid())
            {
                bCPropertyTypeBase *pProperty = AccessorProperty.GetPropertyTypeObject();
                if (!dynamic_cast<bTPropertyTypeOnly<bCObsoleteClass> *>(pProperty))
                {
                    a_OStream << pProperty->GetPropertyName();
                    a_OStream << pProperty->GetPropertyClassName();
                    pProperty->PropertyWrite(a_OStream, this);
                }
            }

            if (!AccessorProperty.IsValid() && !AccessorProperty.GetAccessorPropertyObject().HasBaseClass())
                break;

            AccessorProperty++;
        }
    }

    a_OStream << *m_pObject;
}

template <typename CLASS, typename BASECLASS>
GEU16 bTPropertyObject<CLASS, BASECLASS>::ReadData(bCIStream &a_IStream, GEU16 a_u16Version)
{
    bCPropertyObjectBase::ReadData(a_IStream, a_u16Version);
    GEU16 u16PropertyObjectVersion = 0;
    u16PropertyObjectVersion << a_IStream;
    if (!u16PropertyObjectVersion)
        GE_FATAL_ERROR(
            __FUNCDNAME__ " - illegal propertyobject version detected. Can¦t read version ! Filebounds exceeded ?")

    bCAccessorCreator AccessorCreator(this);
    bCAccessorProperty AccessorProperty(AccessorCreator);
    GEBool bFastMode = GETrue; // Assume properties are stored in the same order, as the accessor iterates over them and
                               // there are no obsolete properties
    GEU32 u32PropertyCount;
    u32PropertyCount << a_IStream;

    for (GEU32 i = 0; i < u32PropertyCount; i++)
    {
        bCString strPropertyName;
        strPropertyName << a_IStream;
        bCString strPropertyClassName;
        if (u16PropertyObjectVersion >= 0x1E)
            strPropertyClassName << a_IStream;
        bCPropertyTypeBase *pPropertyType = 0;
        if (bFastMode)
        {
            pPropertyType = AccessorProperty.GetPropertyTypeObject();
            if (AccessorProperty.GetPropertyName() != strPropertyName)
                bFastMode = GEFalse;
            AccessorProperty++;
        }

        if (!bFastMode)
            pPropertyType = bCAccessorProperty(AccessorCreator, strPropertyName).GetPropertyTypeObject();

        if (pPropertyType
            && (u16PropertyObjectVersion < 0x1E || pPropertyType->GetPropertyClassName() == strPropertyClassName))
        {
            pPropertyType->PropertyRead(a_IStream, *this);
        }
        else
        {
            static bCCriticalSectionWin32 Mutex; // warning C4640: construction of local static object is not
                                                 // thread-safe (but also done this way in original code)
            Mutex.Acquire();
            {
                static bTPropertyType<CLASS, bCObsoleteClass> DummyProperty(
                    bTPropertyObjectType<CLASS, BASECLASS>::GetInstance(), 0, "", bEPropertyType_PropertyContainer);
                DummyProperty.PropertyDeprecate(a_IStream, *this, strPropertyName, strPropertyClassName,
                                                pPropertyType != 0);
            }
            Mutex.Release();
        }
    }

    if (!m_pObject)
        Create();

    *m_pObject << a_IStream;

    return u16PropertyObjectVersion;
}

template <typename CLASS, typename BASECLASS>
void bTPropertyObject<CLASS, BASECLASS>::Write(bCOStream &a_OStream)
{
    if (bCPOStream *pPOStream = dynamic_cast<bCPOStream *>(&a_OStream))
    {
        bCPropertyObjectBase::Write(a_OStream);
        bCPOStream TmpStream;
        if (pPOStream->IsForcedLegacyMode())
            TmpStream.ForceLegacyMode();
        WriteData(TmpStream);
        TmpStream.SetPosition(0, bEStreamSeekMode_Begin);
        a_OStream << TmpStream.GetSize();
        a_OStream.Write(TmpStream.AccessBuffer(0), static_cast<GEU32>(TmpStream.GetSize()));
    }
    else
    {
        bCPropertyObjectBase::Write(a_OStream);
        bSStreamSnapshot Snapshot = WriteSizeDummy(a_OStream);
        WriteData(a_OStream);
        ReplaceSizeDummy(Snapshot);
    }
}

template <typename CLASS, typename BASECLASS>
GEU16 bTPropertyObject<CLASS, BASECLASS>::Read(bCIStream &a_IStream)
{
    GEU16 u16Version = bCPropertyObjectBase::Read(a_IStream);
    GEU32 u32Size;
    u32Size << a_IStream;

    if (bTClassName<CLASS>::GetUnmangled() == bTClassName<bCObsoleteClass>::GetUnmangled())
    {
        GELPVoid pMemory = bCMemoryAdmin::GetInstance().Malloc(u32Size);
        a_IStream.Read(pMemory, u32Size);
        bCMemoryAdmin::GetInstance().Free(pMemory);
    }
    else
    {
        ReadData(a_IStream, u16Version);
    }

    return u16Version;
}

template <typename CLASS, typename BASECLASS>
bCPropertyObjectTypeBase const *bTPropertyObject<CLASS, BASECLASS>::GetType() const
{
    return m_pPropertyObjectType;
}

template <typename CLASS, typename BASECLASS>
bCString const &bTPropertyObject<CLASS, BASECLASS>::GetDescription() const
{
    return m_pPropertyObjectType->GetDescription();
}

template <typename CLASS, typename BASECLASS>
bCString const &bTPropertyObject<CLASS, BASECLASS>::GetBaseClassName() const
{
    return bTClassName<BASECLASS>::GetUnmangled();
}

template <typename CLASS, typename BASECLASS>
bCString const &bTPropertyObject<CLASS, BASECLASS>::GetClassName() const
{
    return bTClassName<CLASS>::GetUnmangled();
}

template <typename CLASS, typename BASECLASS>
CLASS *bTPropertyObject<CLASS, BASECLASS>::GetObject() const
{
    return m_pObject;
}

template <typename CLASS, typename BASECLASS>
void bTPropertyObject<CLASS, BASECLASS>::CreateInternal(GEBool a_bRoot)
{
    m_u32Bitfield ^= (m_u32Bitfield ^ static_cast<GEU32>(a_bRoot)) & 1; // SetRoot(a_bRoot)
    bTPOPureSmartPtr<CLASS>::Create();
    m_pPropertyObjectType->AccessObjectFactory()->RegisterPropertyObject(this);
    if (!IsRoot())
    {
        bCAccessorProperty AccessorProperty(bCAccessorCreator(this));
        while (AccessorProperty.IsValid())
        {
            AccessorProperty.GetPropertyTypeObject()->PropertyInvalidate(this);
            AccessorProperty++;
        }

        if (GetObject())
            GetObject()->PostInitializeProperties();
    }
}

template <typename CLASS, typename BASECLASS>
bTPropertyObject<CLASS, BASECLASS>::bTPropertyObject(GEBool a_bRoot)
{
    if (!a_bRoot)
        m_u32Bitfield &= 0xFFFFFFFB;
    m_pPropertyObjectType = &bTPropertyObjectType<CLASS, BASECLASS>::GetInstance();
    m_pObject = 0;
    CreateInternal(a_bRoot);
}

template <typename CLASS, typename BASECLASS>
bTPropertyObject<CLASS, BASECLASS> &bTPropertyObject<CLASS, BASECLASS>::operator=(
    bTPropertyObject<CLASS, BASECLASS> const &a_Source)
{
    CopyFrom(a_Source);
}
