#include "Script_AniName_Adp.h"

#include "util/Memory.h"
#include "util/Hook.h"
#include "util/Util.h"

namespace
{
    static mCFunctionHook Hook_UndeadAddon_GetAniName;
    void GE_STDCALL UndeadAddon_GetAniName(bCString& p_RetString, eCEntity* p_Entity, gEAction p_Action, bCString p_Str1, bCString& p_Str2, GEBool p_Bool)
    {
        Hook_UndeadAddon_GetAniName.GetOriginalFunction(&UndeadAddon_GetAniName)(p_RetString, p_Entity, p_Action, p_Str1, p_Str2, p_Bool);
        gCNPC_PS const* ptr_NPC = p_Entity->IsValid() ? GetPropertySet<gCNPC_PS>(p_Entity, eEPropertySetType_NPC) : nullptr;
        if (!ptr_NPC)
            return;
        switch (ptr_NPC->GetSpecies())
        {
        case gESpecies_Skeleton:
            p_RetString.Replace("Hero", "Skeleton");
            break;
        case gESpecies_Zombie:
            p_RetString.Replace("Hero", "Zombie");
            break;
        }
    }

    static mCFunctionHook Hook_PSAnimation_GetSkeletonName;
    GEBool GE_STDCALL PSAnimation_GetSkeletonName(PSAnimation const& This, bCString& o_SkeletonName)
    {
        gCNPC_PS const* NPC = This.IsValid() ? GetPropertySet<gCNPC_PS>(This->GetEntity(), eEPropertySetType_NPC) : nullptr;
        if (NPC)
        {
            switch (NPC->GetSpecies().GetValue())
            {
            case gESpecies_Skeleton:
                o_SkeletonName = "Skeleton";
                return GETrue;
            case gESpecies_Zombie:
                o_SkeletonName = "Zombie";
                return GETrue;
            }
        }

        return Hook_PSAnimation_GetSkeletonName.GetOriginalFunction(PSAnimation_GetSkeletonName)(This, o_SkeletonName);
    }

}

void ApplyHooks()
{
    // Load first Animation Script Hook if found! 
    GetScriptAdmin().LoadScriptDLL("Script_Animation.dll");

    Hook_UndeadAddon_GetAniName
        .Hook(RVA_Game(0x16f840), &UndeadAddon_GetAniName, mCBaseHook::mEHookType_ThisCall);

    Hook_PSAnimation_GetSkeletonName
        .Prepare(PROC_Script("?GetSkeletonName@PSAnimation@@QBE_NAAVbCString@@@Z"), &PSAnimation_GetSkeletonName)
        .ThisCall().Hook();
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
