#include "Script_AttackSpeed.h"

#include "util/Memory.h"
#include "util/Logging.h"
#include "util/Hook.h"

#include "Script.h"

gSScriptInit & GetScriptInit()
{
    static gSScriptInit s_ScriptInit;
    return s_ScriptInit;
}

GEFloat g_fAttackSpeedMultiplicator = 1.0f;

void LoadSettings() {
    eCConfigFile config = eCConfigFile();
    if(config.ReadFile(bCString("attackspeed.ini"))) {
        g_fAttackSpeedMultiplicator = config.GetFloat(bCString("Game"), bCString("Game.AttackSpeedMultiplicator"), g_fAttackSpeedMultiplicator);
    }
}

mCCallHook Hook_ApplyAttackSpeedMultiplicator;
void GE_STDCALL ApplyAttackSpeedMultiplicator( GEFloat & o_fAttackSpeed )
{
    o_fAttackSpeed *= g_fAttackSpeedMultiplicator;
}

extern "C" __declspec( dllexport )
gSScriptInit const * GE_STDCALL ScriptInit( void )
{
    // Ensure that that Script_Game.dll is loaded.
    GetScriptAdmin().LoadScriptDLL("Script_Game.dll");

    LoadSettings();
    Hook_ApplyAttackSpeedMultiplicator
        .Prepare(RVA_ScriptGame(0x4D5B), &ApplyAttackSpeedMultiplicator)
        .InsertCall()
        .AddStackArg(0x10).Hook();

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