#ifndef TOOLS_QUEST_H_INCLUDED
#define TOOLS_QUEST_H_INCLUDED

#include "../m_commandhandler.h"

namespace CMD_Tools_Sub
{
    bCString SetQuestStatus( bTObjArray< bCString > a_arrParams );
    bCString QuestAC( bTObjArray< bCString > a_arrParams );
}

#endif