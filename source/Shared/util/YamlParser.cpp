#include "YamlParser.h"

#include <yaml.h>

#include <stdlib.h>
#include <stdio.h>

#include "Util.h"
#include "TypeUtil.h"
#include "property/me_defaultproperty.h"

namespace
{
    class mCYamlValueConverterBase
    {
        public:
            virtual bEResult Read(bCString const & a_strYamlValue, GELPVoid a_oValue) const = 0;
            virtual GELPVoid Array_AddNew(bCString const & a_strClassName, GELPVoid a_pArray) const = 0;
            virtual GELPVoid ValArray_AddNew(GELPVoid a_pArray) const = 0;
            virtual GELPVoid ObjArray_AddNew(GELPVoid a_pArray) const = 0;
            virtual GELPVoid PtrArray_AddNew(GELPVoid a_pArray) const = 0;
    };

    template<typename T>
    class mCYamlValueConverter
        : public mCYamlValueConverterBase
    {
        public:
            virtual bEResult Read(bCString const & a_strYamlValue, GELPVoid a_oValue) const
            {
                return ReadTyped(a_strYamlValue, static_cast<T *>(a_oValue));
            }

            bEResult ReadTyped(bCString const & a_strYamlValue, T * a_oValue) const;

            virtual GELPVoid Array_AddNew(bCString const & a_strClassName, GELPVoid a_pArray) const
            {
                bCString strArrayType = GetTemplateRawType(a_strClassName);
                if(strArrayType == "bTValArray")
                    return ValArray_AddNew(a_pArray);

                if(strArrayType == "bTObjArray")
                    return ObjArray_AddNew(a_pArray);

                if(strArrayType == "bTPtrArray")
                    return PtrArray_AddNew(a_pArray);

                return 0;
            }

            virtual GELPVoid ValArray_AddNew(GELPVoid a_pArray) const
            {
                return &static_cast<bTValArray<T> *>(a_pArray)->AddNew();
            }


            virtual GELPVoid ObjArray_AddNew(GELPVoid a_pArray) const
            {
                return &static_cast<bTObjArray<T> *>(a_pArray)->AddNew();
            }


            virtual GELPVoid PtrArray_AddNew(GELPVoid a_pArray) const
            {
                bTPtrArray<T> * pArray = static_cast<bTPtrArray<T> *>(a_pArray);
                pArray->Add(0);
                return &pArray->AccessAt(pArray->GetCount() - 1);
            }

    };

    static bTPtrMap<bCString, mCYamlValueConverterBase *> s_arrValueConverters;

    #define SPECIALIZE_CONVERTER( TYPE, EXP )                                                   \
    template<>                                                                             \
    bEResult mCYamlValueConverter<TYPE>::ReadTyped( bCString const & a_strYamlValue, TYPE * a_oValue ) const \
    {                                                                                           \
        *a_oValue = EXP;                                                                        \
        return bEResult_Ok;                                                                     \
    }                                                                                           \
    GE_STATIC_BLOCK { s_arrValueConverters.SetAt( bTClassName<TYPE>::GetUnmangled(), GE_NEW( mCYamlValueConverter<TYPE>) ); }

    // TODO: Make more robust, e.g by using cyaml implementations.
    SPECIALIZE_CONVERTER( bCString, a_strYamlValue )
    SPECIALIZE_CONVERTER( GEInt, static_cast<GEUInt>(a_strYamlValue.GetInteger()) );
    SPECIALIZE_CONVERTER( GEI8, static_cast<GEI8>(a_strYamlValue.GetInteger()) );
    SPECIALIZE_CONVERTER( GEI16, static_cast<GEI16>(a_strYamlValue.GetInteger()) );
    SPECIALIZE_CONVERTER( GEI32, static_cast<GEI32>(a_strYamlValue.GetInteger()) );
    SPECIALIZE_CONVERTER( GEI64, a_strYamlValue.GetI64() );
    SPECIALIZE_CONVERTER( GEUInt, static_cast<GEUInt>(a_strYamlValue.GetInteger()) );
    SPECIALIZE_CONVERTER( GEU8, static_cast<GEU8>(a_strYamlValue.GetInteger()) );
    SPECIALIZE_CONVERTER( GEU16, static_cast<GEU16>(a_strYamlValue.GetInteger()) );
    SPECIALIZE_CONVERTER( GEU32, static_cast<GEU32>(a_strYamlValue.GetInteger()) );
    SPECIALIZE_CONVERTER( GEU64, static_cast<GEU64>(a_strYamlValue.GetI64()) );
    SPECIALIZE_CONVERTER( GEBool, a_strYamlValue.GetBool() );
    SPECIALIZE_CONVERTER( GEFloat, a_strYamlValue.GetFloat() );
    SPECIALIZE_CONVERTER( GEDouble, a_strYamlValue.GetDouble() );

    bCString GetScalarValue(yaml_node_t const * a_pNode)
    {
        return FromUTF8(a_pNode->data.scalar.value, a_pNode->data.scalar.length);
    }
}

mCYamlParser::mCYamlParser( mCLoggerBase & a_Logger )
    : m_Logger(a_Logger)
{
}

GELPVoid mCYamlParser::LoadYaml(bCString const & a_strFile, bCString const & a_strTargetType, bTObjArray<bCString> const * a_arrClassPrefixes)
{
    m_strFile = a_strFile;
    eCVirtualFile File(0);
    if(!File.Open(a_strFile, bEFileCreationMode_OpenExisting, 1))
    {
        LogError("Failed to open file!\n");
        return 0;
    }

    GELPVoid pResult = 0;
    yaml_parser_t Parser;
    if(yaml_parser_initialize(&Parser))
    {
        yaml_parser_set_input(&Parser, &YamlFileReadHandler, &File);

        yaml_document_t Document;
        if (yaml_parser_load(&Parser, &Document))
        {
            yaml_node_t * RootNode = yaml_document_get_root_node(&Document);
            if(RootNode && RootNode->type != YAML_NO_NODE)
            {
                mSReadContext Context;
                Context.m_pDocument = & Document;
                Context.InitClassPrefixes(a_arrClassPrefixes);
                Context.PushState(mSReadState(RootNode, 0, a_strTargetType));
                if(ReadNode(Context, RootNode) == bEResult_Ok)
                {
                    pResult = Context.PeekState().m_pData;
                }
                else
                {
                    PrintBacktrace(Context);
                    pResult = 0;
                }

            }
            else
            {
                LogError("Document has no root node!\n");
                pResult = 0;
            }
        }
        else
        {
            LogError("Failed to parse YAML: %s (line: %d, column: %d)\n", Parser.problem, Parser.problem_mark.line + 1, Parser.problem_mark.column + 1);
            pResult = 0;
        }

        yaml_document_delete(&Document);
    }
    else
    {
        LogError("Failed to initialize YAML parser!\n");
        pResult = 0;
    }

    yaml_parser_delete(&Parser);
    return pResult;
}

GELPVoid mCYamlParser::LoadYaml(bCString const & a_strFile, bCPropertyObjectTypeBase const & a_Type, bTObjArray<bCString> const * a_arrClassPrefixes)
{
    return LoadYaml(a_strFile, a_Type.GetClassName(), a_arrClassPrefixes);
}

int mCYamlParser::YamlFileReadHandler( void *data, unsigned char *buffer, size_t size, size_t *size_read )
{
    eCVirtualFile * pFile = static_cast<eCVirtualFile *>(data);
    *size_read = pFile->Read(buffer, size);
    return 1;
}

#define YAML_PARSER_ASSERT(EXP) \
    if(!(EXP)) \
        return LogError("Assertion failed: %s\n, file %s, line %d\n", #EXP, __FILE__, __LINE__);

bEResult mCYamlParser::ReadNode(mSReadContext & a_Context, yaml_node_t const * a_pNode)
{
    switch(a_pNode->type)
    {
        case YAML_SCALAR_NODE:
            return ReadScalarNode(a_Context, a_pNode);
        case YAML_SEQUENCE_NODE:
            return ReadSequenceNode(a_Context,a_pNode);
        case YAML_MAPPING_NODE:
            return ReadMappingNode(a_Context,a_pNode);
        default:
            return LogError("Unexpected node type!\n");
    }
}

bEResult mCYamlParser::ReadScalarNode(mSReadContext & a_Context, yaml_node_t const * a_pNode)
{
    YAML_PARSER_ASSERT(a_Context.GetData() != 0);

    bCPropertyTypeBase * pPropertyType = a_Context.GetPropertyType();
    bCString const & ClassName = a_Context.GetClassName();
    if(!pPropertyType || pPropertyType->GetPropertyType() == bEPropertyType_Normal)
    {
        if(s_arrValueConverters.IsValidKey(ClassName))
        {
            mCYamlValueConverterBase * pConverter = s_arrValueConverters.GetAt(ClassName);
            bEResult Result = pConverter->Read(GetScalarValue(a_pNode), a_Context.GetData());
            return Result;
        }
        else
            return LogError("Type %s is not supported.\n", ClassName);
    }
    else if (pPropertyType->GetPropertyType() == bEPropertyType_PropertyContainer)
    {
        bCString InputValue = GetScalarValue(a_pNode);
        bCString EnumName = StripScope(UnMangle(GetTemplateArg(ClassName)));
        if(pPropertyType->HasEnumValues())
        {
            for(GEInt i = 0; i < pPropertyType->GetEnumValueCount(); i++)
            {
                bCEnumWrapper const * pEnumValue = pPropertyType->GetEnumValue(i);
                bCString EnumValue = StripScope(pEnumValue->GetValueString());

                if(EnumValue.CompareNoCaseFast(InputValue) || EnumValue.CompareNoCaseFast( EnumName + "_" + InputValue ))
                {
                    static_cast<bTPropertyContainer<GEU32> *>(a_Context.GetData())->AccessValue() = pEnumValue->GetValue();
                    return bEResult_Ok;
                }
            }
        }

        return LogError("Invalid value %s for enum %s.\n", InputValue, EnumName);
    }
    else
        return LogError("Expected scalar type, but got %s.\n", ClassName);
}

bEResult mCYamlParser::ReadSequenceNode(mSReadContext & a_Context, yaml_node_t const * a_pNode)
{
    bCString const & ClassName = a_Context.GetClassName();
    if(!IsArrayType(ClassName))
        return LogError("Expected %s, but got a sequence type.\n", ClassName);

    bCString ElementType = UnMangle(GetTemplateArg(ClassName));
    // Array of property objects
    if(StartsWith(ElementType, "bTAutoPOSmartPtr"))
    {
        if(!a_Context.GetData())
            // HACK: All arrays have the same internal structure, so just use a dummy type.
            a_Context.SetData(GE_NEW(bTValArray<bTAutoPOSmartPtr<bCObjectRefBase>>));

        // HACK: bTValArray zeroes the memory of new entries, so bTAutoPOSmartPtr::m_pPropertyObject will be empty.
        bTValArray<bTAutoPOSmartPtr<bCObjectRefBase>> * pArray = static_cast<bTValArray<bTAutoPOSmartPtr<bCObjectRefBase>> *>(a_Context.GetData());

        for (yaml_node_item_t * item = a_pNode->data.sequence.items.start; item < a_pNode->data.sequence.items.top; item++)
        {
            yaml_node_t * pItem = yaml_document_get_node(a_Context.m_pDocument, *item);
            YAML_PARSER_ASSERT(pItem->type == YAML_MAPPING_NODE);
            a_Context.PushState( mSReadState(pItem, 0, UnMangle(GetTemplateArg(ElementType))) );
            if(!ReadNode(a_Context, pItem))
                return bEResult_False;
            bCObjectRefBase * pObject = static_cast<bCObjectRefBase *>(a_Context.GetData());
            pArray->AddNew().SetPropertyObject(static_cast<bTPropertyObject<bCObjectRefBase, bCObjectBase> *>(pObject->GetPropertyObject()));
            a_Context.PopState();
        }

        return bEResult_Ok;
    }
    else if(StartsWith(GetTemplateRawType(ClassName), "bTPtrArray") && IsSimplePointer(ElementType))
    {
        if(!a_Context.GetData())
            // HACK: All arrays have the same internal structure, so just use a dummy type.
            a_Context.SetData(GE_NEW(bTPtrArray<bCObjectRefBase *>));

        bTPtrArray<bCObjectRefBase *> * pArray = static_cast<bTPtrArray<bCObjectRefBase *> *>(a_Context.GetData());

        for (yaml_node_item_t * item = a_pNode->data.sequence.items.start; item < a_pNode->data.sequence.items.top; item++)
        {
            yaml_node_t * pItem = yaml_document_get_node(a_Context.m_pDocument, *item);
            YAML_PARSER_ASSERT(pItem->type == YAML_MAPPING_NODE);
            a_Context.PushState( mSReadState(pItem, 0, StripPointer(ElementType)) );
            if(!ReadNode(a_Context, pItem))
                return bEResult_False;
            pArray->Add(static_cast<bCObjectRefBase *>(a_Context.GetData()));
            a_Context.PopState();
        }

        return bEResult_Ok;
    }
    else
    {
        if(s_arrValueConverters.IsValidKey(ElementType))
        {
            if(!a_Context.GetData())
                // HACK: All arrays have the same internal structure, so just use a dummy type.
                a_Context.SetData(GE_NEW(bTValArray<GEInt>));

            GELPVoid pArray = a_Context.GetData();

            for (yaml_node_item_t * item = a_pNode->data.sequence.items.start; item < a_pNode->data.sequence.items.top; item++)
            {
                yaml_node_t * pItem = yaml_document_get_node(a_Context.m_pDocument, *item);
                YAML_PARSER_ASSERT(pItem->type == YAML_SCALAR_NODE);
                mCYamlValueConverterBase * pConverter = s_arrValueConverters.GetAt(ElementType);
                a_Context.PushState( mSReadState(pItem, pConverter->Array_AddNew(ClassName, pArray), ElementType) );
                if(!ReadNode(a_Context, pItem))
                    return bEResult_False;
                a_Context.PopState();
            }

            return bEResult_Ok;
        }
        else
            return LogError("ArrayType %s is not supported.\n", ClassName);
    }
}

bEResult mCYamlParser::ReadMappingNode(mSReadContext & a_Context, yaml_node_t const * a_pNode)
{
    YAML_PARSER_ASSERT(a_Context.GetData() == 0);

    bCPropertyObjectTypeBase * pObjectType = 0;

    // Check if yaml tag refers to a child type
    bCString Tag(FromUTF8(a_pNode->tag));
    if(StartsWith(Tag, '!'))
    {
        Tag = Tag.Mid(1);
        GE_ARRAY_FOR_EACH(Prefix, a_Context.m_arrClassPrefixes)
        {
            pObjectType = bCPropertyObjectSingleton::GetInstance().FindTemplate(*Prefix + Tag);
            if(pObjectType)
            {
                // Is it a child type?
                // TODO: Allow inheritance chain.
                if(pObjectType->GetBaseClassName() != a_Context.GetClassName())
                    pObjectType = 0;
                else
                    break;
            }
        }
    } else
        pObjectType = bCPropertyObjectSingleton::GetInstance().FindTemplate(a_Context.GetClassName());

    if(!pObjectType)
        return LogError("Expected type %s or a child type, but instead got %s.\n", a_Context.GetClassName(), Tag.GetBuffer(0));

    bCPropertyObjectBase * pObject = pObjectType->GetObjectFactory()->GetRootObject()->Clone();
    if(!pObject)
        return LogError("Failed to create a object of type %s.\n", pObjectType->GetClassName());

    a_Context.SetData(pObject->GetObject());

    bTObjArray<bCString> arrPropertiesSet;
    for (yaml_node_pair_t * pair = a_pNode->data.mapping.pairs.start; pair < a_pNode->data.mapping.pairs.top; pair++)
    {
        yaml_node_t * pKey = yaml_document_get_node(a_Context.m_pDocument, pair->key);
        YAML_PARSER_ASSERT(pKey->type == YAML_SCALAR_NODE);
        yaml_node_t * pValue = yaml_document_get_node(a_Context.m_pDocument, pair->value);

        // Resolve property
        bCString PropertyName = GetScalarValue(pKey);
        bCAccessorProperty Property(bCAccessorCreator(pObject), PropertyName);

        if(!Property.IsValid())
            return LogError("Unknown property %s.\n", PropertyName);

        // Read property
        a_Context.PushState(mSReadState(pValue, Property.GetPropertyTypeObject()->PropertyAccess(pObject), Property.GetPropertyTypeObject()));
        if(!ReadNode(a_Context, pValue))
            return bEResult_False;
        a_Context.PopState();

        arrPropertiesSet.Add(PropertyName);
    }

    // Assure all properties of the object have been set
    bCAccessorProperty AccessorProperty(pObject);
    bEResult Result = bEResult_Ok;
    while(AccessorProperty.IsValid())
    {
        bCPropertyTypeBase * pPropertyType = AccessorProperty.GetPropertyTypeObject();
        if(arrPropertiesSet.IndexOf(pPropertyType->GetPropertyName()) != -1)
        {
            AccessorProperty++;
            continue;
        }

        mCDefaultPropertyTypeBase * pDefaultPropertyType = dynamic_cast<mCDefaultPropertyTypeBase *>(pPropertyType);
        if(!pDefaultPropertyType || !pDefaultPropertyType->HasDefaultValue())
        {
            LogError("For the property %s no value has been specified, and it has no default value.\n", pPropertyType->GetPropertyName());
            Result = bEResult_False;
        }
        else
        {
            pPropertyType->PropertySet(pObject, pDefaultPropertyType->GetDefaultValue());
        }

        AccessorProperty++;
    }

    return Result;
}



bEResult mCYamlParser::LogError(GELPCChar a_strFormat, ...)
{
    // TODO: Log error, set error state
    va_list Arguments;
    va_start(Arguments, a_strFormat);

    char Buffer[512];
    vsnprintf (Buffer, sizeof(Buffer) -1, a_strFormat, Arguments);
    m_Logger.LogString(bCString::GetFormattedString("YamlParser(%s): ", m_strFile) + Buffer);

    va_end(Arguments);
    // Print backtrace and line of node
    return bEResult_False;
}

void mCYamlParser::PrintBacktrace(mSReadContext const & a_Context)
{
    m_Logger.LogString("Backtrace:\n");
    GE_ARRAY_FOR_EACH_REV(State, a_Context.m_arrState)
    {
        switch(State->m_pNode->type)
        {
            case YAML_SCALAR_NODE:
                m_Logger.LogFormat("in scalar value '%s'", GetScalarValue(State->m_pNode));
                break;
            case YAML_SEQUENCE_NODE:
                // TODO: Count?
                m_Logger.LogFormat("in sequence");
                break;
            case YAML_MAPPING_NODE:
                m_Logger.LogFormat("in mapping");
                break;
            default:
                m_Logger.LogFormat("in ???");
                break;
        }
        m_Logger.LogFormat(" (index=%d, line=%d, column=%d)\n", State->m_pNode->start_mark.index, State->m_pNode->start_mark.line + 1, State->m_pNode->start_mark.column + 1 );
    }
}
