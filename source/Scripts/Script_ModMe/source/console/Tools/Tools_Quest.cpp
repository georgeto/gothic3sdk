#include "Tools_Quest.h"

#include "Script.h"
#include "util/Util.h"

bCString CMD_Tools_Sub::QuestAC( bTObjArray< bCString > a_arrParams )
{
    static bTObjArray<bCString> s_arrQuestStatus = GetEnumStringValues(gCQuest_PS::ms_PropertyMember_m_status);

    if(a_arrParams.GetCount() == 1)
    {
        if( gCQuestManager_PS * pQuestManager = gCQuestManager_PS::GetInstance() )
        {
            bTObjArray<bCString> arrQuests;
            GE_ARRAY_FOR_EACH(pQuest, pQuestManager->GetQuests())
            {
                arrQuests.Add((**pQuest).GetName());
            }
            AutoCompleteString( arrQuests, a_arrParams[0], mCCommandHandler::GetInstance().IsAutoCompleteBackward() );
        }
    }
    else if(a_arrParams.GetCount() == 2)
    {
        AutoCompleteString( s_arrQuestStatus, a_arrParams[1], mCCommandHandler::GetInstance().IsAutoCompleteBackward() );
    }

    return JoinString( a_arrParams );
}

bCString CMD_Tools_Sub::SetQuestStatus( bTObjArray< bCString > a_arrParams )
{
    bCString strQuest = a_arrParams[0];
    bCString strStatus = a_arrParams[1];

    gCQuestManager_PS * pQuestManager = gCQuestManager_PS::GetInstance();
    gCQuest_PS * pQuest = pQuestManager->GetQuest( strQuest );

    if( !pQuest )
        return bCString::GetFormattedString( "$Could not find quest %s.", strQuest );

    gEQuestStatus QuestStatus;
    if( !StringToEnum( QuestStatus, gCQuest_PS::ms_PropertyMember_m_status, strStatus ) )
        return bCString::GetFormattedString( "$'%s' is not a valid quest status.", strStatus );

    if( pQuest->GetStatus() != QuestStatus )
    {
        if( pQuest->SetStatus( QuestStatus ) )
            return bCString::GetFormattedString( "Set status of %s to %s.", strQuest, strStatus );
        else
            return bCString::GetFormattedString( "$Failed to set status of %s to %s.", strQuest, strStatus );
    }
    else
        return bCString::GetFormattedString( "Status of %s was already set to %s.", strQuest, strStatus );
}
