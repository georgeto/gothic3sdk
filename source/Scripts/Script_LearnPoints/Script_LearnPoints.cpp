#include "Script_LearnPoints.h"

#include "util/Memory.h"
#include "util/Logging.h"
#include "util/Hook.h"

#include "Script.h"

gSScriptInit & GetScriptInit()
{
    static gSScriptInit s_ScriptInit;
    return s_ScriptInit;
}

GEInt g_iLearnPointsOnLevelUp = 10;
GEInt g_iHealthPointsOnLevelUp = 0;
GEInt g_iStaminaPointsOnLevelUp = 0;
GEInt g_iManaPointsOnLevelUp = 0;

void LoadSettings() {
    eCConfigFile config = eCConfigFile();
    if(config.ReadFile(bCString("learnpoints.ini"))) {
        g_iLearnPointsOnLevelUp = config.GetInt(bCString("Game"), bCString("Game.LearnPointsOnLevelUp"), g_iLearnPointsOnLevelUp);
        g_iHealthPointsOnLevelUp = config.GetInt(bCString("Game"), bCString("Game.HealthPointsOnLevelUp"), g_iHealthPointsOnLevelUp);
        g_iStaminaPointsOnLevelUp = config.GetInt(bCString("Game"), bCString("Game.StaminaPointsOnLevelUp"), g_iStaminaPointsOnLevelUp);
        g_iManaPointsOnLevelUp = config.GetInt(bCString("Game"), bCString("Game.ManaPointsOnLevelUp"), g_iManaPointsOnLevelUp);
    }
}

GEI32 GE_STDCALL GetIncrementedLearnPoints()
{
    PSPlayerMemory * pPlayerMemory = mCCallHook::GetLastSelf<PSPlayerMemory *>();

    if(g_iHealthPointsOnLevelUp != 0)
        pPlayerMemory->AddHitPointsMax(g_iHealthPointsOnLevelUp);

    if(g_iStaminaPointsOnLevelUp != 0)
        pPlayerMemory->AddStaminaPointsMax(g_iStaminaPointsOnLevelUp);

    if(g_iManaPointsOnLevelUp != 0)
        pPlayerMemory->AddManaPointsMax(g_iManaPointsOnLevelUp);

    return pPlayerMemory->LPAttribs + g_iLearnPointsOnLevelUp;
}

extern "C" __declspec( dllexport )
gSScriptInit const * GE_STDCALL ScriptInit( void )
{
    // Ensure that that Script_Game.dll is loaded.
    GetScriptAdmin().LoadScriptDLL("Script_Game.dll");

    LoadSettings();

    static mCCallHook Hook_GetIncrementedLearnPoints1;
    Hook_GetIncrementedLearnPoints1
        .Prepare(RVA_ScriptGame(0x4E659), &GetIncrementedLearnPoints, mCBaseHook::mEHookType_ThisCall)
        .ReplaceSize(0x09).Hook();

    static mCCallHook Hook_GetIncrementedLearnPoints2;
    Hook_GetIncrementedLearnPoints2.Hook(RVA_ScriptGame(0x4E76E), &GetIncrementedLearnPoints, mCBaseHook::mEHookType_ThisCall);
    WriteNops(RVA_ScriptGame(0x4E77A), 0x03); // add eax, 0x0A

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
