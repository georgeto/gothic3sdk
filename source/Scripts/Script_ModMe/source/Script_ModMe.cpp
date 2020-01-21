#include "Common.h"

void LoadSettings(mSModSettings & a_ModSettings)
{
    eCConfigFile Config = eCConfigFile();
    if(!ReadPhysConfigFile("Ini\\scriptmodme.ini", Config))
    {
        GetDefaultLogger().LogString("Failed to load scriptmodme.ini.\n");
    }

    a_ModSettings.Game_AutoStart = Config.GetBool(bCString("Game"), bCString("Game.AutoStart"), GEFalse);
    a_ModSettings.Game_HideTips = Config.GetBool(bCString("Game"), bCString("Game.HideTips"), GEFalse);

    a_ModSettings.Logging_ModMe = Config.GetBool(bCString("Logging"), bCString("Logging.ModMe"), GEFalse);
    a_ModSettings.Logging_Gothic = Config.GetBool(bCString("Logging"), bCString("Logging.Gothic"), GEFalse);

    DestroyPhysConfigFile(Config);
}

mSModSettings const & GetModSettings()
{
    static GEBool s_bSettingsLoaded = GEFalse;
    static mSModSettings s_ModSettings;

    if(!s_bSettingsLoaded)
    {
        s_bSettingsLoaded = GETrue;
        LoadSettings(s_ModSettings);
    }

    return s_ModSettings;
}

gSScriptInit & GetScriptInit()
{
    static gSScriptInit s_ScriptInit;
    return s_ScriptInit;
}

extern "C" __declspec( dllexport )
gSScriptInit const * GE_STDCALL ScriptInit( void )
{
    // Ensure that that Script_Game.dll is loaded.
    GetScriptAdmin().LoadScriptDLL("Script_Game.dll");

    // Logging
    CreateDirectory("logs", NULL);

    mCFileLogger & Logger = mCLoggingAdmin<mCFileLogger>::GetLogger("logs\\Script_ModMe.log", GetModSettings().Logging_ModMe);
    SetDefaultLogger(Logger);
    InitAsmjitLogger(Logger.GetFile());

    // Apply modules
    mCModuleRegistry::GetInstance().Apply();

    return &GetScriptInit();
}

//
// Entry Point
//

BOOL APIENTRY DllMain( HMODULE hModule, DWORD dwReason, LPVOID )
{
    switch( dwReason )
    {
    case DLL_PROCESS_ATTACH:
        ::DisableThreadLibraryCalls( hModule );
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}