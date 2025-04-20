#include <SharedBase/io/streams/ge_memorystream.h>
#include <SharedBase/kernel/object/ge_classname.h>
#include <SharedBase/kernel/object/ge_objectrefbase.h>
#include <SharedBase/kernel/object/ge_obsoleteclass.h>
#include <SharedBase/propertysystem/objects/ge_propertyobjectbase.h>

template <typename OBJECTCLASS, typename CLASS>
GEU32 bTPropertyType<OBJECTCLASS, CLASS>::GetMemberOffset() const
{
    return this->m_u32MemberOffset;
}

template <typename OBJECTCLASS, typename CLASS>
GEU32 bTPropertyType<OBJECTCLASS, CLASS>::GetDataSize() const
{
    return sizeof(CLASS);
}

template <typename OBJECTCLASS, typename CLASS>
bCString const &bTPropertyType<OBJECTCLASS, CLASS>::GetObjectTypeClassName() const
{
    return this->m_pPropertyObjectType->GetClassName();
}

template <typename OBJECTCLASS, typename CLASS>
bCString const &bTPropertyType<OBJECTCLASS, CLASS>::GetPropertyClassName() const
{
    return bTClassName<CLASS>::GetUnmangled();
}

template <typename OBJECTCLASS, typename CLASS>
bCPropertyObjectTypeBase const *bTPropertyType<OBJECTCLASS, CLASS>::GetObjectType() const
{
    return m_pPropertyObjectType;
}

template <typename OBJECTCLASS, typename CLASS>
GELPVoid bTPropertyType<OBJECTCLASS, CLASS>::PropertyInvalidate(bCPropertyObjectBase *a_pPropertyObject)
{
    if (a_pPropertyObject)
        return PropertyAccessor(a_pPropertyObject);
    return 0;
}

template <typename OBJECTCLASS, typename CLASS>
GEBool bTPropertyType<OBJECTCLASS, CLASS>::HasEnumValues() const
{
    return this->m_pArrEnumWrappers != 0;
}

template <typename OBJECTCLASS, typename CLASS>
GEInt bTPropertyType<OBJECTCLASS, CLASS>::GetEnumValueCount() const
{
    return HasEnumValues() ? this->m_pArrEnumWrappers->GetCount() : -1;
}

template <typename OBJECTCLASS, typename CLASS>
bCEnumWrapper const *bTPropertyType<OBJECTCLASS, CLASS>::GetEnumValue(GEInt a_iIndex) const
{
    if (HasEnumValues() && a_iIndex < this->m_pArrEnumWrappers->GetCount())
        return this->m_pArrEnumWrappers->GetAt(a_iIndex);

    return 0;
}

template <typename OBJECTCLASS, typename CLASS>
void bTPropertyType<OBJECTCLASS, CLASS>::PropertySet(bCPropertyObjectBase *a_pPropertyObject, GELPCVoid a_pValue)
{
    if (a_pValue)
        PropertySetter(a_pPropertyObject, *reinterpret_cast<CLASS const *>(a_pValue));
}

template <typename OBJECTCLASS, typename CLASS>
GELPCVoid bTPropertyType<OBJECTCLASS, CLASS>::PropertyGet(bCPropertyObjectBase const *a_pPropertyObject)
{
    return a_pPropertyObject ? this->m_u32MemberOffset + reinterpret_cast<GELPCByte>(a_pPropertyObject->GetObject())
                             : 0;
}

template <typename OBJECTCLASS, typename CLASS>
GELPVoid bTPropertyType<OBJECTCLASS, CLASS>::PropertyAccess(bCPropertyObjectBase *a_pPropertyObject)
{
    return a_pPropertyObject ? this->m_u32MemberOffset + reinterpret_cast<GELPByte>(a_pPropertyObject->GetObject()) : 0;
}

template <typename OBJECTCLASS, typename CLASS>
GEBool bTPropertyType<OBJECTCLASS, CLASS>::PropertyCopy(bCPropertyObjectBase *a_pDestPropertyObject,
                                                        bCPropertyObjectBase const *a_pSource)
{
    if (a_pDestPropertyObject && a_pSource && GetPropertyClassName() != bTClassName<bCObsoleteClass>::GetUnmangled())
    {
        PropertySetter(a_pDestPropertyObject, *PropertyGetter(a_pSource));
        return GETrue;
    }
    else
        return GEFalse;
}

template <typename OBJECTCLASS, typename CLASS>
void bTPropertyType<OBJECTCLASS, CLASS>::PropertyWrite(bCOStream &a_OutStream, bCPropertyObjectBase *a_pSource)
{
    if (!a_pSource)
        GE_FATAL_ERROR_EX(__FUNCDNAME__ " - Propertysource must not NULL ! ", "GEFalse == (NULL != pObjRefBase)");

    this->Write(a_OutStream);
    if (bCPOStream *pPOStream = dynamic_cast<bCPOStream *>(&a_OutStream))
    {
        bCPOStream TmpStream;
        if (pPOStream->IsForcedLegacyMode())
            TmpStream.ForceLegacyMode();
        *(PropertyAccessor(a_pSource)) >> a_OutStream;
        TmpStream.SetPosition(0, bEStreamSeekMode_Begin);
        a_OutStream << TmpStream.GetSize();
        a_OutStream.Write(TmpStream.AccessBuffer(0), static_cast<GEU32>(TmpStream.GetSize()));
    }
    else
    {
        bSStreamSnapshot Snapshot = WriteSizeDummy(a_OutStream);
        *PropertyAccessor(a_pSource) >> a_OutStream;
        ReplaceSizeDummy(Snapshot);
    }
}

template <typename OBJECTCLASS, typename CLASS>
void bTPropertyType<OBJECTCLASS, CLASS>::PropertyRead(bCIStream &a_InStream, bCPropertyObjectBase &a_pPropertyObject)
{
    this->Read(a_InStream);
    GEU32 Size;
    Size << a_InStream;
    if (a_pPropertyObject.GetObject())
        a_pPropertyObject.GetObject()->NotifyPropertyValueChangedEnterEx(GetPropertyName(), GETrue);

    *PropertyAccessor(&a_pPropertyObject) << a_InStream;

    if (a_pPropertyObject.GetObject())
        a_pPropertyObject.GetObject()->NotifyPropertyValueChangedExitEx(GetPropertyName(), GETrue);
}

template <typename OBJECTCLASS, typename CLASS>
void bTPropertyType<OBJECTCLASS, CLASS>::PropertyDeprecate(bCIStream &a_InStream,
                                                           bCPropertyObjectBase &a_pPropertyObject,
                                                           bCString const &a_strUnk1, bCString const &a_strUnk2,
                                                           GEBool a_bNotify)
{
    this->Read(a_InStream);
    GEU32 u32Size;
    a_InStream >> u32Size;
    GELPVoid pBuffer = bCMemoryAdmin::GetInstance().Malloc(u32Size);
    a_InStream.Read(pBuffer, u32Size);
    if (a_bNotify)
    {
        bCMemoryStream MemoryStream;
        MemoryStream.Write(pBuffer, u32Size);
        MemoryStream.SetPosition(0, bEStreamSeekMode_Begin);
        a_pPropertyObject.GetObject()->NotifyPropertyDeprecated(a_strUnk1, a_strUnk2, MemoryStream, 0);
    }
    bCMemoryAdmin::GetInstance().Free(pBuffer);
}

template <typename OBJECTCLASS, typename CLASS>
void bTPropertyType<OBJECTCLASS, CLASS>::Destroy()
{
    bCPropertyTypeBase::Destroy();
    if (HasEnumValues())
        GE_DELETE(this->m_pArrEnumWrappers);
    this->m_pPropertyObjectType->UnregisterPropertyTemplate(this);
}

template <typename OBJECTCLASS, typename CLASS>
void bTPropertyType<OBJECTCLASS, CLASS>::Create()
{
    bCPropertyTypeBase::Create();
    this->m_pPropertyObjectType->RegisterPropertyTemplate(this);
}

template <typename OBJECTCLASS, typename CLASS>
bCPropertyTypeBase *bTPropertyType<OBJECTCLASS, CLASS>::DoClone() const
{
    GE_MESSAGEF_WARN(
        "The method %s detected an improper usage! \nHint:%s ", __FUNCDNAME__,
        "It is not allowed to make a clone of propertytype.\nDo not call it from derived class or change access !");
    return 0;
}

template <typename OBJECTCLASS, typename CLASS>
void bTPropertyType<OBJECTCLASS, CLASS>::CopyFrom(bCPropertyTypeBase const &a_Source)
{
    GE_MESSAGEF_WARN(
        "The method %s detected an improper usage! \nHint:%s ", __FUNCDNAME__,
        "It is not allowed to make a copy of propertytype.\nDo not call it from derived class or change access !");
    return bCPropertyTypeBase::CopyFrom(a_Source);
}

template <typename OBJECTCLASS, typename CLASS>
bTPropertyType<OBJECTCLASS, CLASS>::~bTPropertyType()
{
    this->Destroy();
}

template <typename OBJECTCLASS, typename CLASS>
void bTPropertyType<OBJECTCLASS, CLASS>::PropertySetter(bCPropertyObjectBase *a_pPropertyObject, CLASS const &a_pValue)
{
    if (a_pPropertyObject)
    {
        if (a_pPropertyObject->GetObject())
            a_pPropertyObject->GetObject()->NotifyPropertyValueChangedEnterEx(GetPropertyName(), GEFalse);

        *PropertyAccessor(a_pPropertyObject) = a_pValue;

        if (a_pPropertyObject->GetObject())
            a_pPropertyObject->GetObject()->NotifyPropertyValueChangedExitEx(GetPropertyName(), GEFalse);
    }
}

template <typename OBJECTCLASS, typename CLASS>
CLASS const *bTPropertyType<OBJECTCLASS, CLASS>::PropertyGetter(bCPropertyObjectBase const *a_pPropertyObject)
{
    if (!a_pPropertyObject)
        GE_FATAL_ERROR_EX(__FUNCDNAME__ " - Propertyobject is NULL, can¦t get propertyvalue from NULLobject ! ",
                          "GEFalse == (NULL != a_pPropertyObject)");

    return reinterpret_cast<CLASS const *>(PropertyGet(a_pPropertyObject));
}

template <typename OBJECTCLASS, typename CLASS>
CLASS *bTPropertyType<OBJECTCLASS, CLASS>::PropertyAccessor(bCPropertyObjectBase *a_pPropertyObject)
{
    if (!a_pPropertyObject)
        GE_FATAL_ERROR_EX(__FUNCDNAME__ " - Propertyobject is NULL, can¦t access propertyvalue from NULobject ! ",
                          "GEFalse == (NULL != a_pPropertyObject)");

    return reinterpret_cast<CLASS *>(PropertyAccess(a_pPropertyObject));
}

template <typename OBJECTCLASS, typename CLASS>
bTPropertyType<OBJECTCLASS, CLASS>::bTPropertyType(bCPropertyObjectTypeBase &a_pPropertyObjectType,
                                                   GEU32 a_u32MemberOffset, bCString const &a_strPropertyName,
                                                   bCString const &a_strPropertyCategory,
                                                   bCString const &a_strPropertyDescription,
                                                   bEPropertyType a_enuPropertyType, GEBool a_bReadOnly)
    : bTPropertyTypeOnly<CLASS>(a_strPropertyName, a_strPropertyCategory, a_strPropertyDescription, a_enuPropertyType,
                                a_bReadOnly),
      m_pPropertyObjectType(&a_pPropertyObjectType), m_u32MemberOffset(a_u32MemberOffset), m_pArrEnumWrappers(0)
{
    Create();
}

template <typename OBJECTCLASS, typename CLASS>
bTPropertyType<OBJECTCLASS, CLASS>::bTPropertyType(bCPropertyObjectTypeBase &a_pPropertyObjectType,
                                                   GEU32 a_u32MemberOffset, bCString const &a_strPropertyName,
                                                   bCString const &a_strPropertyCategory,
                                                   bEPropertyType a_enuPropertyType, GEBool a_bReadOnly)
    : bTPropertyTypeOnly<CLASS>(a_strPropertyName, a_strPropertyCategory, a_enuPropertyType, a_bReadOnly),
      m_pPropertyObjectType(&a_pPropertyObjectType), m_u32MemberOffset(a_u32MemberOffset), m_pArrEnumWrappers(0)
{
    Create();
}

template <typename OBJECTCLASS, typename CLASS>
bTPropertyType<OBJECTCLASS, CLASS>::bTPropertyType(bCPropertyObjectTypeBase &a_pPropertyObjectType,
                                                   GEU32 a_u32MemberOffset, bCString const &a_strPropertyName,
                                                   bEPropertyType a_enuPropertyType)
    : bTPropertyTypeOnly<CLASS>(a_strPropertyName, a_enuPropertyType), m_pPropertyObjectType(&a_pPropertyObjectType),
      m_u32MemberOffset(a_u32MemberOffset), m_pArrEnumWrappers(0)
{
    Create();
}

template <typename OBJECTCLASS, typename CLASS>
void bTPropertyType<OBJECTCLASS, CLASS>::AddEnumValue(bTEnumWrapper<CLASS> *a_pEnumValue)
{
    if (!m_pArrEnumWrappers)
        m_pArrEnumWrappers = GE_NEW(bTPtrArray<bCEnumWrapper *>);
    m_pArrEnumWrappers->Add(a_pEnumValue);
}

template <typename OBJECTCLASS, typename CLASS>
void bTPropertyType<OBJECTCLASS, CLASS>::AddDefaultEnumValue(bTEnumWrapper<CLASS> *a_pEnumValue)
{
    *reinterpret_cast<GEU32 *>(&CLASS::s_DefaultValue) = a_pEnumValue->GetValue();
    AddEnumValue(a_pEnumValue);
}

/*#pragma warning ( push )
#pragma warning ( disable : 4640 ) // 's_PropertyObjectType' : construction of local static object is not thread safe
template< typename CLASS, typename BASECLASS >
bTPropertyObject<CLASS, BASECLASS>::bTPropertyObject()
{
    static bTPropertyObjectType<CLASS, BASECLASS> s_PropertyObjectType;
    m_u32Bitfield &= 0xFFFFFFFB;
    m_pPropertyObjectType = &s_PropertyObjectType;
    m_pObject = 0;
    CreateInternal(GEFalse);

}
#pragma warning ( pop )*/
