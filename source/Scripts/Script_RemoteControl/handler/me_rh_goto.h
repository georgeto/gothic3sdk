#ifndef ME_RH_GOTO_H_INCLUDED
#define ME_RH_GOTO_H_INCLUDED

#include "me_requesthandler.h"

class mCGotoRequestHandler :
    public mCRequestHandler
{
    public:
        mCGotoRequestHandler();
        virtual void HandleRequest();
        virtual void Process();

    private:
        bCVector m_PutToGroundLocation;
        GEUInt m_uPutToGroundTries;
};

#endif