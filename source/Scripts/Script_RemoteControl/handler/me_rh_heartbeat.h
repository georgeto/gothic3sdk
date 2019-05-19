#ifndef ME_RH_HEARTBEAT_H_INCLUDED
#define ME_RH_HEARTBEAT_H_INCLUDED

#include "me_requesthandler.h"

class mCHeartbeatRequestHandler :
    public mCRequestHandler
{
    public:
        virtual void HandleRequest();
};

#endif