#include "Script.h"

#define PICOJSON_USE_INT64

#include "picojson.h"
#include <fstream>

extern "C" __declspec( dllexport )
gSScriptInit const * GE_STDCALL ScriptInit( void )
{
    static gSScriptInit s_ScriptInit;

    using namespace picojson;
    value::array Types;

    bCPropertyObjectSingleton & TypeSystem = bCPropertyObjectSingleton::GetInstance();
    for(bTPtrMap<bCString, bCPropertyObjectSingleton::bCPOTypeListItem *>::bCConstIterator Iter = TypeSystem.BeginIterator(); Iter != TypeSystem.EndIterator(); Iter++)
    {
        bCPropertyObjectTypeBase const * pPropertyObjectType = (*Iter)->GetObjectType();

        value::object Type;
        Type["key"] = value(Iter.GetKey());
        Type["name"] = value(pPropertyObjectType->GetClassNameA());
        Type["base"] = value(pPropertyObjectType->GetBaseClassName());
        Type["description"] = value(pPropertyObjectType->GetDescription());
        Type["persistable"] = value(pPropertyObjectType->IsPersistable());

        value::array Properties;
        for(bTArrayBase<bCPropertyTypeBase *>::bCConstIterator PropertyIter = pPropertyObjectType->BeginIterator(); PropertyIter != pPropertyObjectType->EndIterator(); PropertyIter++)
        {
            bCPropertyTypeBase * pPropertyType = *PropertyIter;
            value::object Property;
            Property["name"] = value(pPropertyType->GetPropertyName());
            Property["class"] = value(pPropertyType->GetPropertyClassName());
            Property["category"] = value(pPropertyType->GetPropertyCategory());
            Property["description"] = value(pPropertyType->GetPropertyDescription());
            Property["type"] = value(static_cast<__int64>(pPropertyType->GetPropertyType()));
            Property["readonly"] = value(pPropertyType->IsReadOnly());
            Property["member_offset"] = value(static_cast<__int64>(pPropertyType->GetMemberOffset()));
            Property["data_size"] = value(static_cast<__int64>(pPropertyType->GetDataSize()));
            if(pPropertyType->GetID().IsValid())
                Property["id"] = value(pPropertyType->GetID().GetText());
            if(pPropertyType->HasEnumValues())
            {
                value::array EnumValues;
                for(GEInt i = 0; i < pPropertyType->GetEnumValueCount(); i++)
                {
                    value::object EnumValue;
                    EnumValue["name"] = value(pPropertyType->GetEnumValue(i)->GetValueString());
                    EnumValue["value"] = value(static_cast<__int64>(pPropertyType->GetEnumValue(i)->GetValue()));
                    EnumValues.push_back(value(EnumValue));
                }
                Property["enum_values"] = value(EnumValues);
            }

            Properties.push_back(value(Property));
        }

        Type["properties"] = value(Properties);
        Types.push_back(value(Type));
    }

    std::ofstream out;
    out.open("properties_dump.json", std::ofstream::trunc);
    out << value(Types) << std::endl;


    return &s_ScriptInit;
}

//
// Entry Point
//

BOOL APIENTRY DllMain( HMODULE hModule, DWORD dwReason, LPVOID )
{
    switch( dwReason )
    {
    case DLL_PROCESS_ATTACH:
        ::DisableThreadLibraryCalls( hModule );
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
};