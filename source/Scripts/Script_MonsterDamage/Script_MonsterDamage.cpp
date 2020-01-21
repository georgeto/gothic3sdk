#include "Script_MonsterDamage.h"

#include "util/Memory.h"
#include "util/Logging.h"
#include "util/Hook.h"

#include "Script.h"

gSScriptInit & GetScriptInit()
{
    static gSScriptInit s_ScriptInit;
    return s_ScriptInit;
}

GEFloat fMonsterDamageMultiplicator = 0.1f;

void LoadSettings() {
    eCConfigFile config = eCConfigFile();
    if(config.ReadFile(bCString("monsterdamage.ini"))) {
        fMonsterDamageMultiplicator = config.GetFloat(bCString("Game"), bCString("Game.MonsterDamageMultiplicator"), GEFalse);
    }
}

mCCallHook Hook_CalculateMonsterDamage;
GEInt GE_STDCALL CalculateMonsterDamage( /* GEInt a_iDamage@<esi> */ )
{
    GEInt iDamage = Hook_CalculateMonsterDamage.GetImmEsi<GEInt>();
    return static_cast<GEInt>(iDamage * fMonsterDamageMultiplicator);
}

extern "C" __declspec( dllexport )
gSScriptInit const * GE_STDCALL ScriptInit( void )
{
    // Ensure that that Script_Game.dll is loaded.
    GetScriptAdmin().LoadScriptDLL("Script_Game.dll");

    LoadSettings();
    Hook_CalculateMonsterDamage
        .Prepare(RVA_ScriptGame(0x2C06D), &CalculateMonsterDamage, mCBaseHook::mEHookType_Mixed, mCRegisterBase::mERegisterType_Esi)
        .ReplaceSize(0x11).Hook();

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