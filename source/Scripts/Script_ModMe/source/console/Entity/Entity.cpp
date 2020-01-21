#include "Entity.h"
#include "Entity_Equip.h"
#include "Entity_Goto.h"
#include "Entity_LogInventory.h"
#include "Entity_Enable.h"
#include "../m_commandhandler.h"

void RegisterEntityCommands(void)
{
    mCCommandHandler & CommandHandler = mCCommandHandler::GetInstance();
    CommandHandler.RegisterCommand( "Entity", "Commands to deal with entities." );

    mCCommandHandler::mSSubCommandDesc Desc;

    Desc.m_strName = "Equip";
    Desc.m_iMinArgs = 1;
    Desc.m_iMaxArgs = 1;
    Desc.m_strHelpText = "Equips the focused Entity with the specified Item.\n" \
        "Usage:\n" \
        "  Entity Equip <Item>";
    Desc.m_pfuncExecute = &CMD_Entity_Sub::Equip;
    Desc.m_pfuncAutoComplete = 0;
    CommandHandler.RegisterSubCommand( "Entity", Desc );

    Desc.m_strName = "Goto";
    Desc.m_iMinArgs = 3;
    Desc.m_iMaxArgs = 3;
    Desc.m_strHelpText = "The Player goes to the specified position.\n" \
        "Usage:\n" \
        "  Entity Goto <X> <Y> <Z>";
    Desc.m_pfuncExecute = &CMD_Entity_Sub::Goto;
    Desc.m_pfuncAutoComplete = 0;
    CommandHandler.RegisterSubCommand( "Entity", Desc );

    Desc.m_strName = "LogInventory";
    Desc.m_iMinArgs = 0;
    Desc.m_iMaxArgs = 0;
    Desc.m_strHelpText = "Writes the inventory of the focused Entity into 'logs/Inventory.log'.\n" \
        "Usage:\n" \
        "  Entity LogInventory";
    Desc.m_pfuncExecute = &CMD_Entity_Sub::LogInventory;
    Desc.m_pfuncAutoComplete = 0;
    CommandHandler.RegisterSubCommand( "Entity", Desc );

    Desc.m_strName = "Enable";
    Desc.m_iMinArgs = 2;
    Desc.m_iMaxArgs = 2;
    Desc.m_strHelpText = "Enables/Disables the specified entity.\n" \
        "Usage:\n" \
        "  Entity Enable <entity name> <true/false>";
    Desc.m_pfuncExecute = &CMD_Entity_Sub::Enable;
    Desc.m_pfuncAutoComplete = 0;
    CommandHandler.RegisterSubCommand( "Entity", Desc );
}
