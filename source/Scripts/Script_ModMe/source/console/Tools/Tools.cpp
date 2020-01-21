#include "Tools.h"
#include "Tools_SetStringtable.h"
#include "Tools_GameEvent.h"
#include "Tools_DumpGameState.h"
#include "Tools_Quest.h"
#include "../m_commandhandler.h"


void RegisterToolsCommands(void)
{
    mCCommandHandler & CommandHandler = mCCommandHandler::GetInstance();
    CommandHandler.RegisterCommand( "Tools", "A collection of general commands." );

    mCCommandHandler::mSSubCommandDesc Desc;

    Desc.m_strName = "ClearGameEvent";
    Desc.m_iMinArgs = 1;
    Desc.m_iMaxArgs = 1;
    Desc.m_strHelpText = "Clears the specified gameevent.\n" \
        "Usage:\n" \
        "  Tools ClearGameEvent <GameEvent>";
    Desc.m_pfuncExecute = &CMD_Tools_Sub::ClearGameEvent;
    Desc.m_pfuncAutoComplete = &CMD_Tools_Sub::GameEventAC;
    CommandHandler.RegisterSubCommand( "Tools", Desc );

    Desc.m_strName = "IsSetGameEvent";
    Desc.m_iMinArgs = 1;
    Desc.m_iMaxArgs = 1;
    Desc.m_strHelpText = "Checks whether the specified gameevent is set.\n" \
        "Usage:\n" \
        "  Tools IsSetGameEvent <GameEvent>";
    Desc.m_pfuncExecute = &CMD_Tools_Sub::IsSetGameEvent;
    Desc.m_pfuncAutoComplete = &CMD_Tools_Sub::GameEventAC;
    CommandHandler.RegisterSubCommand( "Tools", Desc );

    Desc.m_strName = "SetGameEvent";
    Desc.m_iMinArgs = 1;
    Desc.m_iMaxArgs = 1;
    Desc.m_strHelpText = "Sets the specified gameevent.\n" \
        "Usage:\n" \
        "  Tools SetGameEvent <GameEvent>";
    Desc.m_pfuncExecute = &CMD_Tools_Sub::SetGameEvent;
    Desc.m_pfuncAutoComplete = 0;
    CommandHandler.RegisterSubCommand( "Tools", Desc );

    Desc.m_strName = "SetStringtable";
    Desc.m_iMinArgs = 2;
    Desc.m_iMaxArgs = -1;
    Desc.m_strHelpText = "Sets the specified stringtable entry to the specified value.\n" \
        "Usage:\n" \
        "  Tools SetStringtable <Entry> <Value>";
    Desc.m_pfuncExecute = &CMD_Tools_Sub::SetStringtable;
    Desc.m_pfuncAutoComplete = 0;
    CommandHandler.RegisterSubCommand( "Tools", Desc );

    Desc.m_strName = "SetQuestStatus";
    Desc.m_iMinArgs = 2;
    Desc.m_iMaxArgs = 2;
    Desc.m_strHelpText = "Sets the status of the specified quest to the specified value.\n" \
        "Usage:\n" \
        "  Tools SetQuestStatus <Quest> <Status>";
    Desc.m_pfuncExecute = &CMD_Tools_Sub::SetQuestStatus;
    Desc.m_pfuncAutoComplete = &CMD_Tools_Sub::QuestAC;
    CommandHandler.RegisterSubCommand( "Tools", Desc );

    Desc.m_strName = "DumpGameState";
    Desc.m_iMinArgs = 0;
    Desc.m_iMaxArgs = 0;
    Desc.m_strHelpText = "Dumps the current game state as a text file.\n" \
        "Usage:\n" \
        "  Tools DumpGameState";
    Desc.m_pfuncExecute = &CMD_Tools_Sub::DumpGameState;
    Desc.m_pfuncAutoComplete = 0;
    CommandHandler.RegisterSubCommand( "Tools", Desc );
}
