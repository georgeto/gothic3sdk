#include "m_commandhandler.h"

#include "Common.h"

#include "Tools/Tools.h"
#include "File/File.h"
#include "Entity/Entity.h"
#include "World/World.h"
#include "Vars/Vars.h"

mCFunctionHook HookOnExecute;
mCFunctionHook HookOnComplete;
mCFunctionHook HookPrintChoices;
mCFunctionHook HookPrintOutput;

mCCommandHandler mCCommandHandler::s_CommandHandler;

mCCommandHandler & mCCommandHandler::GetInstance()
{
    return s_CommandHandler;
}

void mCCommandHandler::Initialize()
{
    HookOnExecute.Hook(GetProcAddress("Engine.dll", "?OnExecute@eCConsole@@MAE_NABVbCString@@AAV2@@Z"), &OnExecuteHook, mCFunctionHook::mEHookType_ThisCall);
    HookOnComplete.Hook(GetProcAddress("Engine.dll", "?OnComplete@eCConsole@@MAE_NAAVbCString@@@Z"), &OnCompleteHook, mCFunctionHook::mEHookType_ThisCall);
    HookPrintChoices.Hook(GetProcAddress("Engine.dll", "?PrintChoices@eCConsole@@UAEXABVbCString@@@Z"), &PrintChoicesHook, mCFunctionHook::mEHookType_ThisCall);
    HookPrintOutput.Hook(GetProcAddress("Engine.dll", "?PrintOutput@eCConsole@@QAEXABVbCString@@ABVbCByteAlphaColor@@@Z"), &PrintOutputHook, mCFunctionHook::mEHookType_ThisCall);


    // On command execution failure console now doesn't appends ': <command>' to the error message
    WriteNops( RVA_Engine( 0xDB0A4 ), 0xDB0EF - 0xDB0A4 );
}

GEBool mCCommandHandler::OnExecuteHook( bCString const & a_rCommand, bCString & a_rStrResult )
{
    // eCKeyboard & keyboard = eCApplication::GetInstance().GetKeyboard();
    // Logging::scriptModLogger.logFormat("OnExecute: '%s', '%s' mit SHIFT(%i), STRG(%i), ALT(%i) und TAB(%i)\n", a_rCommand.GetText(), a_rStrResult.GetText(), keyboard.KeyPressed((eCInpShared::eEKeyboardStateOffset)42), keyboard.KeyPressed((eCInpShared::eEKeyboardStateOffset)29), keyboard.KeyPressed((eCInpShared::eEKeyboardStateOffset)56), keyboard.KeyPressed((eCInpShared::eEKeyboardStateOffset)15));

    mEResult Result = mCCommandHandler::GetInstance().OnExecute( a_rCommand, a_rStrResult );
    if( Result == NotResponsible )
        return ( *HookOnExecute.GetOriginalFunction( &OnExecuteHook ) )(a_rCommand, a_rStrResult);
    return Result == Successful ? GETrue : GEFalse;
}

GEBool mCCommandHandler::OnCompleteHook( bCString & a_rCommand )
{
    // eCKeyboard & keyboard = eCApplication::GetInstance().GetKeyboard();
    // Logging::scriptModLogger.logFormat("OnComplete: '%s' mit SHIFT(%i), STRG(%i), ALT(%i) und TAB(%i)\n", a_rCommand.GetText(), keyboard.KeyPressed((eCInpShared::eEKeyboardStateOffset)42), keyboard.KeyPressed((eCInpShared::eEKeyboardStateOffset)29), keyboard.KeyPressed((eCInpShared::eEKeyboardStateOffset)56), keyboard.KeyPressed((eCInpShared::eEKeyboardStateOffset)15));

    mEResult Result = mCCommandHandler::GetInstance().OnComplete( a_rCommand );
    if( Result == NotResponsible )
        return ( *HookOnComplete.GetOriginalFunction( &OnCompleteHook ) )( a_rCommand );
    return Result == Successful ? GETrue : GEFalse;
}

void mCCommandHandler::PrintChoicesHook( bCString const & a_rCommand )
{
    // eCKeyboard & keyboard = eCApplication::GetInstance().GetKeyboard();
    // Logging::scriptModLogger.logFormat("PrintChoices: '%s' mit SHIFT(%i), STRG(%i), ALT(%i) und TAB(%i)\n", a_rCommand.GetText(), keyboard.KeyPressed((eCInpShared::eEKeyboardStateOffset)42), keyboard.KeyPressed((eCInpShared::eEKeyboardStateOffset)29), keyboard.KeyPressed((eCInpShared::eEKeyboardStateOffset)56), keyboard.KeyPressed((eCInpShared::eEKeyboardStateOffset)15));

    mEResult Result = mCCommandHandler::GetInstance().PrintChoices( a_rCommand );
    if( Result == NotResponsible )
        ( *HookPrintChoices.GetOriginalFunction( &PrintChoicesHook ) )( a_rCommand );
}


void mCCommandHandler::PrintOutputHook(bCString const & a_strText, bCByteAlphaColor const & a_rColor)
{
    bTObjArray< bCString > arrLines = SplitString( a_strText, "\n", GEFalse, GEFalse );
    for( GEInt i = 0; i < arrLines.GetCount(); i++ )
        ( *HookPrintOutput.GetOriginalFunction( &PrintOutputHook ) )( arrLines[i], a_rColor );
}


GEBool mCCommandHandler::RegisterCommand( bCString const & a_strName, bCString const & a_strDescription )
{
    if( GetCommand( a_strName ) != 0 )
        return GEFalse;

    mSCommandDesc CommandDesc;
    CommandDesc.m_strName = a_strName;
    CommandDesc.m_strDescription = a_strDescription;
    m_arrCommands.Add(CommandDesc);

    eCApplication::GetInstance().GetConsole().AddCommand(CommandDesc.m_strName, CommandDesc.m_strDescription, 0, 0xFFFFFFFFFFFFFFFF, g_strDefault);

    return GETrue;
}

GEBool mCCommandHandler::RegisterSubCommand( bCString const & a_strParentName, mSSubCommandDesc const a_SubCommandDesc )
{
    mSCommandDesc * CommandDesc = GetCommand( a_strParentName );
    if( CommandDesc == 0 )
        return GEFalse;

    if( GetSubCommand( *CommandDesc, a_SubCommandDesc.m_strName ) != 0 )
        return GEFalse;

    CommandDesc->m_arrSubCommands.Add(a_SubCommandDesc);
    return GETrue;
}

mCCommandHandler::mSCommandDesc * mCCommandHandler::GetCommand( bCString const & a_strName )
{
    for(GEInt i = 0; i < m_arrCommands.GetCount(); i++ )
    {
        if(m_arrCommands[i].m_strName.CompareNoCaseFast( a_strName ))
            return &m_arrCommands[i];
    }
    return 0;
}

mCCommandHandler::mSSubCommandDesc * mCCommandHandler::GetSubCommand( mSCommandDesc & a_CommandDesc, bCString const & a_strName )
{
    for(GEInt i = 0; i < a_CommandDesc.m_arrSubCommands.GetCount(); i++ )
    {
        if(a_CommandDesc.m_arrSubCommands[i].m_strName.CompareNoCaseFast( a_strName ))
            return &a_CommandDesc.m_arrSubCommands[i];
    }
    return 0;
}

GEInt mCCommandHandler::GetSubCommandIndex( mSCommandDesc & a_CommandDesc, bCString const & a_strName )
{
    for(GEInt i = 0; i < a_CommandDesc.m_arrSubCommands.GetCount(); i++ )
    {
        if(a_CommandDesc.m_arrSubCommands[i].m_strName.CompareNoCaseFast( a_strName ))
            return i;
    }
    return -1;
}

bCString mCCommandHandler::GetCommandHelpText( bCString const & a_strCommand )
{
    mSCommandDesc const * Desc = GetCommand( a_strCommand );
    if( Desc == 0)
        return "Unknown command.";

    bCString strResult = Desc->m_strDescription + "\n";
    strResult += "Usage:\n";
    strResult += "  " + Desc->m_strName  + " <Command> <Arguments>\n";
    strResult += "Commands:\n";
    for( GEInt i = 0; i < Desc->m_arrSubCommands.GetCount(); i++ )
        strResult += "  " + Desc->m_arrSubCommands[i].m_strName + "\n";
    strResult += "Additional help is available for all commands. You can skip through them using autocompletion (TAB).";
    return strResult;
}

bCString mCCommandHandler::GetSubCommandHelpText( mSCommandDesc & a_rCommandDesc, bCString const & a_strSubCommand )
{
    mSSubCommandDesc const * Desc = GetSubCommand( a_rCommandDesc, a_strSubCommand );
    if( Desc == 0 )
        return "Unknown command.";

    return Desc->m_strHelpText;
}


GEBool mCCommandHandler::AutoCompleteSubCommand( mSCommandDesc const & a_rCommandDesc, bCString & a_strSubCommand )
{
    bTObjArray< mSSubCommandDesc > const & arrSubCommands = a_rCommandDesc.m_arrSubCommands;
    bTObjArray< bCString > arrSubCommandNames( arrSubCommands.GetCount() );

    for( GEInt i = 0; i < a_rCommandDesc.m_arrSubCommands.GetCount(); i++ )
        arrSubCommandNames.Add( a_rCommandDesc.m_arrSubCommands[i].m_strName );

    return AutoCompleteString( arrSubCommandNames, a_strSubCommand, IsAutoCompleteBackward() );
}

mCCommandHandler::mEResult mCCommandHandler::OnExecute( bCString const & a_strCommand, bCString & a_strResult )
{
    bTObjArray< bCString > arrParams = SplitString( a_strCommand, " ", GEFalse, GEFalse) ;
    GEInt iParamCount = arrParams.GetCount();
    if( iParamCount == 0 )
        return NotResponsible;

    mSCommandDesc * pCommand = GetCommand( arrParams[0] );
    if( pCommand == 0 )
        return NotResponsible;

    if( iParamCount == 1 )
        return a_strResult = "Please specify a command (use \"" + pCommand->m_strName + " help\" to get a list of supported commands).", Failed;

    mSSubCommandDesc const * pSubCommand = GetSubCommand( *pCommand, arrParams[1] );
    if( pSubCommand == 0 )
        return a_strResult = "Unknown command.", Failed;

    if( pSubCommand->m_iMinArgs > iParamCount - 2 || ( pSubCommand->m_iMaxArgs != -1 && pSubCommand->m_iMaxArgs < iParamCount - 2 ) )
        return a_strResult = "Wrong argument count. You can use \"" + pCommand->m_strName + " " + pSubCommand->m_strName + " help\" to learn more about the command's usage.", Failed;

    a_strResult = ( *pSubCommand->m_pfuncExecute )( CopyRange( arrParams, 2 ) );
    if( a_strResult.Contains("$") )
        return a_strResult.Remove("$"), Failed;
    return Successful;
}

mCCommandHandler::mEResult mCCommandHandler::OnComplete( bCString & a_strCommand )
{
    bTObjArray< bCString > arrParams = SplitString( a_strCommand, " ", GEFalse, GEFalse) ;
    GEInt iParamCount = arrParams.GetCount();
    if( iParamCount == 0 )
        return NotResponsible;

    mSCommandDesc * pCommand = GetCommand( arrParams[0] );
    if( pCommand == 0 )
        return NotResponsible;

    if( iParamCount == 2 )
    {
        if( AutoCompleteSubCommand( *pCommand, arrParams[1] ) )
            return a_strCommand = JoinString( arrParams ), Successful;
        return Failed;
    }

    mSSubCommandDesc const * pSubCommand = GetSubCommand( *pCommand, arrParams[1] );
    if( pSubCommand == 0 || iParamCount < 3 || pSubCommand->m_iMaxArgs < iParamCount - 2 )
        return Failed;

    if( pSubCommand->m_pfuncAutoComplete != 0)
        return a_strCommand = JoinString( arrParams, 0, " ", 2 ) + " " + ( *pSubCommand->m_pfuncAutoComplete )( CopyRange( arrParams, 2 ) ), Successful;

    return Failed;
}

mCCommandHandler::mEResult mCCommandHandler::PrintChoices( bCString const & a_strCommand )
{
    bTObjArray< bCString > arrParams = SplitString( a_strCommand, " ", GEFalse, GEFalse) ;
    GEInt iParamCount = arrParams.GetCount();
    if( iParamCount == 0 )
        return NotResponsible;

    mSCommandDesc * pCommand = GetCommand( arrParams[0] );
    if( pCommand == 0 )
        return NotResponsible;

    GEBool bHelpType = iParamCount == 1 || ( iParamCount == 2 && arrParams[1].IsEmpty() );
    bCString strHelpText = bHelpType ? GetCommandHelpText( pCommand->m_strName ) : GetSubCommandHelpText( *pCommand, arrParams[1] );
    eCConsole::AccessConsole().PrintOutput( strHelpText , bCByteAlphaColor( bCColorBase::bEColor_14 ) );

    return Successful;
}

GEBool mCCommandHandler::IsAutoCompleteBackward()
{
    return eCApplication::GetInstance().GetKeyboard().KeyPressed( eCInpShared::eEKeyboardStateOffset_LEFT_SHIFT );
}

ME_MODULE(CommandHandler)
{
    mCCommandHandler::GetInstance().Initialize();
    RegisterToolsCommands();
    RegisterFileCommands();
    RegisterEntityCommands();
    RegisterWorldCommands();
    RegisterVarsCommands();
}
