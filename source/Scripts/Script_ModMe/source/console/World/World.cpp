#include "World.h"
#include "World_CompileLightmaps.h"
#include "World_SaveLayer.h"
#include "World_SaveSector.h"
#include "../m_commandhandler.h"

void RegisterWorldCommands(void)
{
    mCCommandHandler & CommandHandler = mCCommandHandler::GetInstance();
    CommandHandler.RegisterCommand( "World", "Commands to deal with world data." );

    mCCommandHandler::mSSubCommandDesc Desc;

    Desc.m_strName = "CompileLightmaps";
    Desc.m_iMinArgs = 0;
    Desc.m_iMaxArgs = 4;
    Desc.m_strHelpText = "Recompiles lightmaps for the whole world or just for the specified area.\n" \
        "Usage:\n" \
        "  World CompileLightmaps <minX> <maxX> <minZ> <maxZ>\n" \
        "  World CompileLightmaps <entity> <square edge>\n" \
        "  World CompileLightmaps <entity> <square edge> <y offset>";
    Desc.m_pfuncExecute = &CMD_World_Sub::CompileLightmaps;
    Desc.m_pfuncAutoComplete = 0;
    CommandHandler.RegisterSubCommand( "World", Desc );

    Desc.m_strName = "SaveLayer";
    Desc.m_iMinArgs = Desc.m_iMaxArgs = 1;
    Desc.m_pfuncExecute = CMD_World_Sub::SaveLayer;
    Desc.m_pfuncAutoComplete = 0;
    Desc.m_strHelpText = "Saves the specified dynamic layer (*.lrent) including all modifications that have been made on it's entities.\n" \
        "Usage:\n" \
        "  World SaveLayer <Layer name>";
    CommandHandler.RegisterSubCommand( "World", Desc );

    Desc.m_strName = "SaveSector";
    Desc.m_iMinArgs = Desc.m_iMaxArgs = 1;
    Desc.m_pfuncExecute = CMD_World_Sub::SaveSector;
    Desc.m_pfuncAutoComplete = 0;
    Desc.m_strHelpText = "Saves the specified sector (*.sec) together with all of it's dynamic layers.\n" \
        "Usage:\n" \
        "  World SaveSector <Sector name>";
    CommandHandler.RegisterSubCommand( "World", Desc );
}
