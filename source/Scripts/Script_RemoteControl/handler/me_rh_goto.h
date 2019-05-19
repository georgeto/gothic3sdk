#ifndef ME_RH_GOTO_H_INCLUDED
#define ME_RH_GOTO_H_INCLUDED

#include "me_requesthandler.h"

class mCGotoRequestHandler :
    public mCRequestHandler
{
    public:
        virtual void HandleRequest();
};

#endif