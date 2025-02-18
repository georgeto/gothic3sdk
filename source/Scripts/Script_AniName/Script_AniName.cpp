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

    static mCFunctionHook Hook_PSAnimation_GetSkeletonName;
    GEBool GE_STDCALL PSAnimation_GetSkeletonName(PSAnimation const & This, bCString & o_SkeletonName)
    {
        gCNPC_PS const * NPC = This.IsValid() ? GetPropertySet<gCNPC_PS>(This->GetEntity(), eEPropertySetType_NPC) : nullptr;
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

    gEUseType GE_STDCALL AI_HoldInventoryItems_Effect_Whitelist(PSInteraction const& ItemInteraction)
    {
        gEUseType UseType = ItemInteraction.UseType;
        switch (UseType)
        {
        case gEUseType_Bow:
        case gEUseType_CrossBow:
        case gEUseType_Staff:
        case gEUseType_Torch:
            // Whitelisted
            return gEUseType_Staff;
        default:
            return UseType;
        }
    }

    gEDamageType GE_STDCALL AI_HoldInventoryItems_Undraw_Effect(PSDamage const & ItemDamage, gSArgsFor__AI_HoldInventoryItems const & Args)
    {
        Entity Item(ItemDamage.IsValid() ? ItemDamage.m_pEngineEntityPropertySet->GetEntity() : nullptr);

        bCString EffectName;
        switch (Item.Interaction.UseType)
        {
        case gEUseType_Bow:
            EffectName= "eff_ani_fight_undraw_bow_01";
            break;
        case gEUseType_CrossBow:
            EffectName = "eff_ani_fight_undraw_cross_bow_01";
            break;
        case gEUseType_Staff:
            EffectName = "eff_ani_fight_undraw_staff_01";
            break;
        case gEUseType_Torch:
            EffectName = "eff_ani_fight_undraw_torch_01";
            break;
        }

        if (!EffectName.IsEmpty())
        {
            EffectSystem::StartEffect(EffectName, Args.m_Holder);
            return gEDamageType_None;
        }
        else
        {
            gEDamageType DamageType = ItemDamage.DamageType;
            return DamageType;
        }
    }

    gEDamageType GE_STDCALL AI_HoldInventoryItems_Draw_Effect(PSDamage const & ItemDamage, gSArgsFor__AI_HoldInventoryItems const & Args)
    {
        Entity Item(ItemDamage.IsValid() ? ItemDamage.m_pEngineEntityPropertySet->GetEntity() : nullptr);

        bCString EffectName;
        switch (Item.Interaction.UseType)
        {
        case gEUseType_Bow:
            EffectName = "eff_ani_fight_draw_bow_01";
            break;
        case gEUseType_CrossBow:
            EffectName = "eff_ani_fight_draw_cross_bow_01";
            break;
        case gEUseType_Staff:
            EffectName = "eff_ani_fight_draw_staff_01";
            break;
        case gEUseType_Torch:
            EffectName = "eff_ani_fight_draw_torch_01";
            break;
        }

        if (!EffectName.IsEmpty())
        {
            EffectSystem::StartEffect(EffectName, Args.m_Holder);
            return gEDamageType_None;
        }
        else
        {
            gEDamageType DamageType = ItemDamage.DamageType;
            return DamageType;
        }
    }
}

void ApplyHooks()
{
    // Ensure Script_Game.dll is loaded first, we want to hook functions in it!
    GetScriptAdmin().LoadScriptDLL("Script_Game.dll");

    // Override actor names
    static mCCallHook Hook_GetAniName_GetActorName;
    Hook_GetAniName_GetActorName
        .Prepare(RVA_Game(0x16F8B9), &GetAniName_GetActorName)
        .AddRegArg(mCRegisterBase::mERegisterType_Ebx) // eCEntity const * Actor
        .AddRegArg(mCRegisterBase::mERegisterType_Esi) // bCString & ActorName
        .InsertCall().Hook();

    Hook_PSAnimation_GetSkeletonName
        .Prepare(PROC_Script("?GetSkeletonName@PSAnimation@@QBE_NAAVbCString@@@Z"), &PSAnimation_GetSkeletonName)
        .ThisCall().Hook();

    static mCCallHook Hook_AI_HoldInventoryItems_Undraw_Effect_Whitelist;
    Hook_AI_HoldInventoryItems_Undraw_Effect_Whitelist
        .Prepare(RVA_ScriptGame(0x43D1F), &AI_HoldInventoryItems_Effect_Whitelist)
        .AddThisArg()
        .Hook();

    static mCCallHook Hook_AI_HoldInventoryItems_raw_Effect_Whitelist;
    Hook_AI_HoldInventoryItems_raw_Effect_Whitelist
        .Prepare(RVA_ScriptGame(0x44743), &AI_HoldInventoryItems_Effect_Whitelist)
        .AddThisArg()
        .Hook();

    static mCCallHook Hook_AI_HoldInventoryItems_Undraw_Effect_Right;
    Hook_AI_HoldInventoryItems_Undraw_Effect_Right
        .Prepare(RVA_ScriptGame(0x43E78), &AI_HoldInventoryItems_Undraw_Effect)
        .AddThisArg()
        .AddRegArg(mCRegisterBase::mERegisterType_Esi)
        .Hook();

    static mCCallHook Hook_AI_HoldInventoryItems_Undraw_Effect_Left;
    Hook_AI_HoldInventoryItems_Undraw_Effect_Left
        .Prepare(RVA_ScriptGame(0x43DB8), &AI_HoldInventoryItems_Undraw_Effect)
        .AddThisArg()
        .AddRegArg(mCRegisterBase::mERegisterType_Esi)
        .Hook();

    static mCCallHook Hook_AI_HoldInventoryItems_Draw_Effect_Right;
    Hook_AI_HoldInventoryItems_Draw_Effect_Right
        .Prepare(RVA_ScriptGame(0x448CD), &AI_HoldInventoryItems_Draw_Effect)
        .AddThisArg()
        .AddRegArg(mCRegisterBase::mERegisterType_Esi)
        .Hook();

    static mCCallHook Hook_AI_HoldInventoryItems_Draw_Effect_Left;
    Hook_AI_HoldInventoryItems_Draw_Effect_Left
        .Prepare(RVA_ScriptGame(0x447F3), &AI_HoldInventoryItems_Draw_Effect)
        .AddThisArg()
        .AddRegArg(mCRegisterBase::mERegisterType_Esi)
        .Hook();
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
