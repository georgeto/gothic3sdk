#include "me_ipcadmin.h"

#include "util/Util.h"

#include "handler/me_rh_heartbeat.h"
#include "handler/me_rh_entity.h"
#include "handler/me_rh_goto.h"
#include "handler/me_rh_spawn.h"
#include "handler/me_rh_property.h"

using namespace g3rc;


template<>
GEU32 GE_STDCALL g_GetHashValue<RequestContainer::RequestCase >( RequestContainer::RequestCase const & a_RequestCase )
{
    return a_RequestCase;
}

// Receive 0MQ string from socket and convert into string
static bCString s_recv ( zmq::socket_t & socket )
{

    zmq::message_t message;
    socket.recv( &message );

    return bCString( static_cast<GELPChar>( message.data() ), message.size() );
}

// Convert string to 0MQ string and send to socket
static bool s_send ( zmq::socket_t & socket, bCString const & string )
{

    zmq::message_t message( string.GetLength() );
    memcpy ( message.data(), const_cast<bCString &>( string ).GetBuffer( 0 ), string.GetLength() );

    bool rc = socket.send ( message );
    return ( rc );
}

// Sends string as 0MQ string, as multipart non-terminal
static bool s_sendmore ( zmq::socket_t & socket, bCString const & string )
{

    zmq::message_t message( string.GetLength() );
    memcpy ( message.data(), const_cast<bCString &>( string ).GetBuffer( 0 ), string.GetLength() );

    bool rc = socket.send ( message, ZMQ_SNDMORE );
    return ( rc );
}

bTPropertyObject<mCIpcAdmin, eCEngineComponentBase> mCIpcAdmin::ms_PropertyObjectInstance_mCIpcAdmin( GETrue );

bEResult mCIpcAdmin::PostInitialize( void )
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    // Prepare our context and socket
    m_RouterSocket.setsockopt( ZMQ_RCVTIMEO, 0 );
    m_RouterSocket.bind( "tcp://127.0.0.1:5555" );
    return bEResult_Ok;
}

bEResult mCIpcAdmin::PreShutdown( void )
{
    m_RouterSocket.close();
    m_Context.close();
    google::protobuf::ShutdownProtobufLibrary();
    UnregisterModule( this );
    return bEResult_Ok;
}

void mCIpcAdmin::Process( void )
{
    for( bTValMap<RequestContainer::RequestCase, mCRequestHandler *>::bCIterator Iter = m_RequestHandlers.Begin(); Iter != m_RequestHandlers.End(); Iter++ )
    {
        ( *Iter )->Process();
    }

    zmq::message_t Identity;
    while( m_RouterSocket.recv( &Identity ) )
    {
        zmq::message_t Data;
        m_RouterSocket.recv( &Data );

        RequestContainer RequestContainer;
        RequestContainer.ParseFromArray( Data.data(), Data.size() );

        ResponseContainer ResponseContainer;
        ResponseContainer.set_request_number( RequestContainer.request_number() );

        if( m_RequestHandlers.IsValidKey( RequestContainer.request_case() ) )
        {
            mCRequestHandler * RequestHandler = m_RequestHandlers.AccessAt( RequestContainer.request_case() );
            RequestHandler->SetRequestContainer( RequestContainer );
            RequestHandler->SetResponseContainer( ResponseContainer );
            RequestHandler->HandleRequest();
            if( ResponseContainer.response_case() == ResponseContainer.RESPONSE_NOT_SET )
                ResponseContainer.mutable_void_response();
        }

        m_RouterSocket.send( Identity, ZMQ_SNDMORE );
        zmq::message_t ResponseData( ResponseContainer.ByteSize() );
        ResponseContainer.SerializeToArray( ResponseData.data(), ResponseData.size() );
        m_RouterSocket.send( ResponseData );
    }
}

mCIpcAdmin::~mCIpcAdmin( void )
{
    CleanupRequestHandlers();
}
mCIpcAdmin::mCIpcAdmin( void ) :
    m_Context( 1 ), m_RouterSocket( m_Context, ZMQ_ROUTER )
{
    SetupRequestHandlers();
    PostInitialize();

    eCModuleAdmin::GetInstance().RegisterModule( *this );
}

void mCIpcAdmin::CleanupRequestHandlers( void )
{
    for( bTValMap<RequestContainer::RequestCase, mCRequestHandler *>::bCIterator Iter = m_RequestHandlers.Begin(); Iter != m_RequestHandlers.End(); Iter++ )
    {
        GE_DELETE( *Iter );
    }
    m_RequestHandlers.Clear();
}

void mCIpcAdmin::SetupRequestHandlers( void )
{
    m_RequestHandlers.SetAt( RequestContainer::kHeartbeatRequest, GE_NEW( mCHeartbeatRequestHandler ) );
    m_RequestHandlers.SetAt( RequestContainer::kEntityRequest, GE_NEW( mCEntityRequestHandler ) );
    m_RequestHandlers.SetAt( RequestContainer::kGotoRequest, GE_NEW( mCGotoRequestHandler ) );
    m_RequestHandlers.SetAt( RequestContainer::kSpawnRequest, GE_NEW( mCSpawnRequestHandler ) );
    m_RequestHandlers.SetAt( RequestContainer::kPropertyRequest, GE_NEW( mCPropertyRequestHandler ) );
}
