#ifndef ME_RH_SPAWN_H_INCLUDED
#define ME_RH_SPAWN_H_INCLUDED

#include "me_requesthandler.h"

class mCSpawnRequestHandler :
    public mCRequestHandler
{
    public:
        virtual void HandleRequest();
};

#endif