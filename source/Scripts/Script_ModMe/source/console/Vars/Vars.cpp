#include "Vars.h"

#include "../m_commandhandler.h"

#include "util/Memory.h"

namespace {
    bCString SetDebugRoutines( bTObjArray< bCString > a_arrParams )
    {
        GEBool bValue = a_arrParams[0].GetBool();
        *reinterpret_cast<GEBool *>(RVA_ScriptGame(0x118AAA)) = bValue;
        return bCString::GetFormattedString("DebugRoutines = %s" , bValue ? "true" : "false");
    }
}

void RegisterVarsCommands(void)
{
    mCCommandHandler & CommandHandler = mCCommandHandler::GetInstance();
    CommandHandler.RegisterCommand( "Vars", "Modify value of several variables." );

    mCCommandHandler::mSSubCommandDesc Desc;

    Desc.m_strName = "DebugRoutines";
    Desc.m_iMinArgs = 1;
    Desc.m_iMaxArgs = 1;
    Desc.m_strHelpText = "Duration of routine tasks is greatly reduced. (bool)";
    Desc.m_pfuncExecute = &SetDebugRoutines;
    Desc.m_pfuncAutoComplete = 0;
    CommandHandler.RegisterSubCommand( "Vars", Desc );
}
