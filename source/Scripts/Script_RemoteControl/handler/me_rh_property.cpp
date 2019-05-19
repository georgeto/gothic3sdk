#include "me_rh_property.h"

#include "Game.h"

#include "util/Util.h"

using namespace g3rc;

void mCPropertyRequestHandler::HandleRequest()
{
    PropertyRequest const & Request = m_RequestContainer->property_request();

    eCEntity * pEntity = 0;
    if( Request.has_entity_name() )
    {
        pEntity = GetEntityByName( Request.entity_name() );
    }
    else if( Request.has_entity_guid() )
    {
        pEntity = GetEntityByGuid( Request.entity_guid() );
    }

    if( !pEntity )
        return FailAndPrintMessage( "Ziel-Entity nicht gefunden." );

    PropertyResponse & Response = *m_ResponseContainer->mutable_property_response();
    for(GEInt i = 0; i < Request.properties_get_size(); i++)
    {
        GetProperty(pEntity, Request.properties_get(i), *Response.add_properties_get());
    }

    for(GEInt i = 0; i < Request.properties_set_size(); i++)
    {
        PropertySerialized const & Property = Request.properties_set(i);
        SetProperty(pEntity, Property);
        GetProperty(pEntity, Property.identifier(), *Response.add_properties_set());
    }

    /*
    bCString strPropertySetName;
    eCEntityPropertySet * pPropertySet =  pEntity->GetPropertySet(strPropertySetName);
    if( !pPropertySet )
        return FailAndPrintMessage( "Ziel-Entity enthält das PropertySet nicht." );

    bCAccessorProperty AccessorProperty(pPropertySet);
    while(AccessorProperty.IsValid() || AccessorProperty.GetAccessorPropertyObject().HasBaseClass())
    {
        if(AccessorProperty.IsValid())
        {
            bCPropertyTypeBase * pProperty = AccessorProperty.GetPropertyTypeObject();
            if(!dynamic_cast<bTPropertyTypeOnly<bCObsoleteClass> *>(pProperty))
            {
                bCMemoryStream a_OStream;
                a_OStream << pProperty->GetPropertyName();
                a_OStream << pProperty->GetPropertyClassName();
                pProperty->PropertyWrite(a_OStream, pPropertySet->GetPropertyObject());

                a_OStream.SetPosition( 0, bEStreamSeekMode_Begin );

            }
        }

        AccessorProperty++;
    }
    */

    // Write PropertySet
    //  bCOStream::operator<<(a_pOut, v7);      // Write Version
    //  bCAccessorPropertyObject::bCAccessorPropertyObject(&v12, v8);
    //  operator<<(a_pOut, &v12);
    //  bCOStream::operator<<(a_pOut, 0xDEADC0DE);

    // Read PropertySet
    // Read via bCAccessorPropertyObject, see ReadV83

    // Entity
    // Write(EntityType) where EntityType oneof Dynamic, Spatial, Template
    // pEntity->Write()

    return Success();
}

void mCPropertyRequestHandler::GetProperty(eCEntity * a_pEntity, PropertyIdentifier const & a_Identifier, PropertySerialized & a_ResponseProperty)
{
    bCMemoryStream a_OStream;
    if(a_Identifier.has_property_set())
    {
        eCEntityPropertySet * pPropertySet =  a_pEntity->GetPropertySet(FromUTF8(a_Identifier.property_set()));
        if(pPropertySet && a_Identifier.has_property())
        {
            bCAccessorProperty AccessorProperty(pPropertySet, FromUTF8(a_Identifier.property()));
            if(AccessorProperty.IsValid())
            {
                bCPropertyTypeBase * pProperty = AccessorProperty.GetPropertyTypeObject();
                if(!dynamic_cast<bTPropertyTypeOnly<bCObsoleteClass> *>(pProperty))
                {
                    a_OStream << pProperty->GetPropertyName();
                    a_OStream << pProperty->GetPropertyClassName();
                    pProperty->PropertyWrite(a_OStream, pPropertySet->GetPropertyObject());
                }
            }
        }
        else if(pPropertySet)
        {
            bCAccessorPropertyObject Accessor(pPropertySet);
            a_OStream << Accessor;
        }
    }
    else
    {
        if(dynamic_cast<eCDynamicEntity *>(a_pEntity))
        {
            a_OStream << bCString("Dynamic");
        }
        else if(dynamic_cast<eCSpatialEntity *>(a_pEntity))
        {
            a_OStream << bCString("Spatial");
        }
        else if(dynamic_cast<eCTemplateEntity *>(a_pEntity))
        {
            a_OStream << bCString("Template");
        }
        a_pEntity->Write(a_OStream);
    }

    a_ResponseProperty.mutable_identifier()->CopyFrom(a_Identifier);
    if(a_OStream.GetSize() > 0)
    {
        a_OStream.SetPosition( 0, bEStreamSeekMode_Begin );
        a_ResponseProperty.set_data(a_OStream.GetBuffer(0), static_cast<size_t>(a_OStream.GetSize()));
    }
}

void mCPropertyRequestHandler::SetProperty(eCEntity * a_pEntity, PropertySerialized const & a_Property)
{
    bCMemoryStream Stream;
    Stream.Write(a_Property.data().c_str(), a_Property.data().length());
    Stream.SetPosition( 0, bEStreamSeekMode_Begin );

    if(a_Property.identifier().has_property_set())
    {
        eCEntityPropertySet * pPropertySet =  a_pEntity->GetPropertySet(FromUTF8(a_Property.identifier().property_set()));
        if(pPropertySet && a_Property.identifier().has_property())
        {
            bCAccessorProperty AccessorProperty(pPropertySet, FromUTF8(a_Property.identifier().property()));
            if(AccessorProperty.IsValid())
            {
                bCPropertyTypeBase * pPropertyType = AccessorProperty.GetPropertyTypeObject();
                if(!dynamic_cast<bTPropertyTypeOnly<bCObsoleteClass> *>(pPropertyType))
                {
                    // unsigned long can not be set...
                    bCString strPropertyName;
                    strPropertyName << Stream;
                    bCString strPropertyClassName;
                    strPropertyClassName << Stream;

                    if(pPropertyType->GetPropertyName() == strPropertyName && pPropertyType->GetPropertyClassName() == strPropertyClassName)
                    {
                        pPropertyType->PropertyRead(Stream, *pPropertySet->GetPropertyObject());
                    }
                }
            }
        }
        else if(pPropertySet)
        {
            bCAccessorPropertyObject Accessor(pPropertySet);
            Accessor << Stream;
        }
    }
    else
    {
        bCString strEntityType;
        strEntityType << Stream;

        if((dynamic_cast<eCDynamicEntity *>(a_pEntity) && strEntityType == "Dynamic")
        || (dynamic_cast<eCSpatialEntity *>(a_pEntity) && strEntityType == "Spatial")
        || (dynamic_cast<eCTemplateEntity *>(a_pEntity) && strEntityType == "Template"))
        {
            a_pEntity->Read(Stream);
        }
    }
}
