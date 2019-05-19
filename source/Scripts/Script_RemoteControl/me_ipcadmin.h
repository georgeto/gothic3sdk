#ifndef ME_IPCADMIN_H_INCLUDED
#define ME_IPCADMIN_H_INCLUDED

#include "Game.h"

#pragma warning( push )
#pragma warning( disable : 4127 )
#include "zmq.hpp"
#pragma warning( pop )

#include "handler/me_requesthandler.h"

class mCIpcAdmin :
    public eCEngineComponentBase
{
    public: virtual bEResult PostInitialize( void );
    public: virtual bEResult PreShutdown( void );
    public: virtual void     Process( void );
    public: virtual         ~mCIpcAdmin( void );

    private:
        static bTPropertyObject<mCIpcAdmin, eCEngineComponentBase> ms_PropertyObjectInstance_mCIpcAdmin;

    public:
        mCIpcAdmin( void );

    private:
                           mCIpcAdmin( mCIpcAdmin const & );
        mCIpcAdmin const & operator = ( mCIpcAdmin const & );

    private:
        void CleanupRequestHandlers( void );
        void SetupRequestHandlers( void );

    private:
        bTPtrMap<g3rc::RequestContainer::RequestCase, mCRequestHandler *> m_RequestHandlers;
        zmq::context_t                                                    m_Context;
        zmq::socket_t                                                     m_RouterSocket;
};

template<>
GEU32 GE_STDCALL g_GetHashValue<g3rc::RequestContainer::RequestCase >( g3rc::RequestContainer::RequestCase const & a_RequestCase );

#endif
