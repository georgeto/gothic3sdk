#ifndef GE_HUDSTATICQUEST_PS_H_INCLUDED
#define GE_HUDSTATICQUEST_PS_H_INCLUDED

#include "Game.h"

class gCHUDStaticQuest : public CFFGFCStatic
{
    public:
        gCQuest_PS * m_pSelectedQuest;

};

GE_ASSERT_SIZEOF(gCHUDStaticQuest, 0x14)

#endif
