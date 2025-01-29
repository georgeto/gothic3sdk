#include "Script_AniName.h"

#include "util/Memory.h"
#include "util/Hook.h"
#include "util/Util.h"

namespace
{
    void GE_STDCALL GetAniName_GetActorName(eCEntity const * Actor, bCString & ActorName)
    {
        if (gCNPC_PS const * NPC = GetPropertySet<gCNPC_PS>(Actor, eEPropertySetType_NPC))
        {
            switch (NPC->GetSpecies().GetValue())
            {
                case gESpecies_Skeleton:
                    ActorName = "Skeleton";
                    break;
                case gESpecies_Zombie:
                    ActorName = "Zombie";
                    break;
            }
        }
    }
}

void ApplyHooks()
{
    // Override actor names
    static mCCallHook Hook_GetAniName_GetActorName;
    Hook_GetAniName_GetActorName
        .Prepare(RVA_Game(0x16F8B9), &GetAniName_GetActorName)
        .AddRegArg(mCRegisterBase::mERegisterType_Ebx) // eCEntity const * Actor
        .AddRegArg(mCRegisterBase::mERegisterType_Esi) // bCString & ActorName
        .InsertCall().Hook();
}


gSScriptInit & GetScriptInit()
{
    static gSScriptInit s_ScriptInit;
    return s_ScriptInit;
}

extern "C" __declspec( dllexport )
gSScriptInit const * GE_STDCALL ScriptInit( void )
{
    ApplyHooks();

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
