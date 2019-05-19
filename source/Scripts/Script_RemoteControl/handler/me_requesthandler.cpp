#include "me_requesthandler.h"

#include "util/Util.h"

using namespace g3rc;

mCRequestHandler::mCRequestHandler()
    : m_RequestContainer( 0 ), m_ResponseContainer( 0 )
{}

void mCRequestHandler::SetRequestContainer( g3rc::RequestContainer const & a_RequestContainer )
{
    m_RequestContainer = &a_RequestContainer;
}

void mCRequestHandler::SetResponseContainer( g3rc::ResponseContainer & a_ResponseContainer )
{
    m_ResponseContainer = &a_ResponseContainer;
}

void mCRequestHandler::Success()
{
    m_ResponseContainer->set_status( ResponseContainer_Status_SUCCESSFUL );
}

void mCRequestHandler::Fail( bCString const & a_strMessage )
{
    m_ResponseContainer->set_status( ResponseContainer_Status_FAILED );
    m_ResponseContainer->set_message( ToUTF8( a_strMessage ) );
}

void mCRequestHandler::FailAndPrintMessage( bCString const & a_strMessage )
{
    Fail( a_strMessage );
    gCSession::GetSession().GetGUIManager()->PrintGameMessage( L"[RemoteControl] " + a_strMessage.GetUnicodeText(), gEGameMessageType_Failure );
}

bCString mCRequestHandler::FromUTF8( ::std::string const & a_Source )
{
    int wchars_num = MultiByteToWideChar( CP_UTF8, 0, a_Source.c_str(), a_Source.length(), NULL, 0 );
    wchar_t* wstr = new wchar_t[wchars_num + 1];
    wstr[wchars_num] = 0;
    MultiByteToWideChar( CP_UTF8, 0, a_Source.c_str(), a_Source.length(), wstr, wchars_num );
    bCString Result( bCUnicodeString( wstr, wchars_num ) );
    delete[] wstr;
    return Result;
}

::std::string mCRequestHandler::ToUTF8( bCString const & a_Source )
{
    bCUnicodeString a_WideSource = a_Source.GetUnicodeText();
    int chars_num = WideCharToMultiByte( CP_UTF8, 0, a_WideSource, a_WideSource.GetLength(), NULL, 0, NULL, NULL );
    char* str = new char[chars_num];
    WideCharToMultiByte( CP_UTF8, 0, a_WideSource, a_WideSource.GetLength(), str, chars_num, NULL, NULL );
    ::std::string Result( str, chars_num );
    delete[] str;
    return Result;
}

eCEntity * mCRequestHandler::GetEntityByName( ::std::string const & a_Name, eEGetEntityTypeHint a_Type )
{
    eCSceneAdmin & SceneAdmin = *FindModule<eCSceneAdmin>();
    eCEntity * pEntity = SceneAdmin.GetEntityByName( FromUTF8( a_Name ) );
    if( !pEntity )
        pEntity = SceneAdmin.GetEntityByPartName( FromUTF8( a_Name ), a_Type );
    return pEntity;
}

eCEntity * mCRequestHandler::GetTemplateEntityByName( ::std::string const & a_Name )
{
    eCSceneAdmin & SceneAdmin = *FindModule<eCSceneAdmin>();
    return SceneAdmin.GetTemplateEntityByName( FromUTF8 ( a_Name ) );
}

eCEntity * mCRequestHandler::GetEntityByGuid( ::std::string const & a_Guid, eEGetEntityTypeHint a_Type )
{
    eCSceneAdmin & SceneAdmin = *FindModule<eCSceneAdmin>();
    return dynamic_cast<eCEntity *>( SceneAdmin.GetEntity( bCPropertyID( bCGuid( FromUTF8( a_Guid ) ) ), a_Type ) );
}

void mCRequestHandler::SetEntityResponse( g3rc::EntityResponse & a_Response, eCEntity & a_Entity )
{
    bCVector const & Translation = a_Entity.GetWorldPosition();
    Vector * pTranslation = a_Response.mutable_position()->mutable_translation();
    pTranslation->set_x( Translation.GetX() );
    pTranslation->set_y( Translation.GetY() );
    pTranslation->set_z( Translation.GetZ() );

    bCVector const & Scaling = a_Entity.GetWorldMatrix().GetPureScaling();
    Vector * pScale = a_Response.mutable_position()->mutable_scale();
    pScale->set_x( Scaling.GetX() );
    pScale->set_y( Scaling.GetY() );
    pScale->set_z( Scaling.GetZ() );

    bCEulerAngles Rotation( a_Entity.GetWorldMatrix().GetPureRotation() );
    EulerAngles * pRotation = a_Response.mutable_position()->mutable_rotation();
    pRotation->set_yaw( Rotation.GetYaw() );
    pRotation->set_pitch( Rotation.GetPitch() );
    pRotation->set_roll( Rotation.GetRoll() );

    a_Response.set_name( ToUTF8( a_Entity.GetName() ) );
    a_Response.set_guid( ToUTF8( a_Entity.GetID().GetText() ) );

}
