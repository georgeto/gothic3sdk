#pragma once

#include <g3sdk/Script.h>
#include <g3sdk/util/Logging.h>

gSScriptInit &GetScriptInit();

class mCFunctionHook;
class mCScriptHookRegistry : public gSScriptInit
{
  public:
    ~mCScriptHookRegistry();
    GEBool ReplaceScriptAIState(gSScriptAIState const &a_ScriptState, gFScriptAIState *o_pOriginalScript = nullptr);
    GEBool ReplaceScriptAIFunction(gSScriptAIFunction const &a_ScriptFunction,
                                   gFScriptAIFunction *o_pOriginalScript = nullptr);
    GEBool ReplaceScriptAICallback(gSScriptAICallback const &a_ScriptCallback,
                                   gFScriptAICallback *o_pOriginalScript = nullptr);
    GEBool ReplaceScriptAIRoutine(gSScriptAIRoutine const &a_ScriptRoutine,
                                  gFScriptAIRoutine *o_pOriginalScript = nullptr);
    GEBool ReplaceScript(gSScript const &a_Script, gFScript *o_pOriginalScript = nullptr);
    void Hook();

  private:
    template <typename S, typename F>
    struct mTOriginalWrapper
    {
        S Script;
        F *pOriginalScript;

        GEBool operator==(mTOriginalWrapper const &script) const
        {
            return Script == script.Script;
        };
    };

  private:
    bTObjArray<mTOriginalWrapper<gSScriptAIState, gFScriptAIState>> m_arrScriptAIStates;
    bTObjArray<mTOriginalWrapper<gSScriptAIFunction, gFScriptAIFunction>> m_arrScriptAIFunctions;
    bTObjArray<mTOriginalWrapper<gSScriptAICallback, gFScriptAICallback>> m_arrScriptAICallbacks;
    bTObjArray<mTOriginalWrapper<gSScriptAIRoutine, gFScriptAIRoutine>> m_arrScriptAIRoutines;
    bTObjArray<mTOriginalWrapper<gSScript, gFScript>> m_arrScripts;
    bTPtrArray<mCFunctionHook *> m_arrHooks;
};
mCScriptHookRegistry &GetScriptHookRegistry();

#define __ME_REGISTER_GENERIC_SCRIPT(TYPE, NAME, FUNC)                                                                 \
    GetScriptInit().m_arr##TYPE##s.Add(gS##TYPE(NAME, __FILE__, FUNC));

template <typename F>
void __set_if_present(F a_Value, F *o_pOptional = nullptr)
{
    if (o_pOptional)
        *o_pOptional = a_Value;
}

#define __ME_UNREGISTER_GENERIC_SCRIPT(TYPE, NAME, ...)                                                                \
    {                                                                                                                  \
        if (gS##TYPE const *pScript = GetScriptAdminExt().Get##TYPE(NAME))                                             \
        {                                                                                                              \
            __set_if_present(pScript->m_func##TYPE, ##__VA_ARGS__);                                                    \
            GetScriptAdminExt().UnRegister##TYPE(const_cast<gS##TYPE *>(pScript));                                     \
        }                                                                                                              \
        else                                                                                                           \
            GetDefaultLogger().LogFormat("Unable to find original " #TYPE " with name %s.\n",                          \
                                         static_cast<GELPCChar>(NAME));                                                \
    }

#define __ME_REGISTER_GENERIC_SCRIPT_REPLACE(TYPE, NAME, FUNC, ...)                                                    \
    GetScriptHookRegistry().Replace##TYPE(gS##TYPE(NAME, __FILE__, FUNC), ##__VA_ARGS__);

#define __ME_REPLACE_GENERIC_SCRIPT(TYPE, NAME, FUNC, ...)                                                             \
    __ME_UNREGISTER_GENERIC_SCRIPT(TYPE, NAME, ##__VA_ARGS__)                                                          \
    __ME_REGISTER_GENERIC_SCRIPT(TYPE, NAME, FUNC)

#define ME_REGISTER_SCRIPT_AI_STATE(NAME, FUNC) __ME_REGISTER_GENERIC_SCRIPT(ScriptAIState, NAME, FUNC)
#define ME_UNREGISTER_SCRIPT_AI_STATE(NAME) __ME_UNREGISTER_GENERIC_SCRIPT(ScriptAIState, NAME)
#define ME_REPLACE_SCRIPT_AI_STATE(NAME, FUNC, ...)                                                                    \
    __ME_REPLACE_GENERIC_SCRIPT(ScriptAIState, NAME, FUNC, ##__VA_ARGS__)

#define ME_REGISTER_SCRIPT_AI_FUNCTION(NAME, FUNC) __ME_REGISTER_GENERIC_SCRIPT(ScriptAIFunction, NAME, FUNC)
#define ME_UNREGISTER_SCRIPT_AI_FUNCTION(NAME) __ME_UNREGISTER_GENERIC_SCRIPT(ScriptAIFunction, NAME)
#define ME_REPLACE_SCRIPT_AI_FUNCTION(NAME, FUNC, ...)                                                                 \
    __ME_REPLACE_GENERIC_SCRIPT(ScriptAIFunction, NAME, FUNC, ##__VA_ARGS__)

#define ME_REGISTER_SCRIPT_AI_CALLBACK(NAME, FUNC) __ME_REGISTER_GENERIC_SCRIPT(ScriptAICallback, NAME, FUNC)
#define ME_UNREGISTER_SCRIPT_AI_CALLBACK(NAME) __ME_UNREGISTER_GENERIC_SCRIPT(ScriptAICallback, NAME)
#define ME_REPLACE_SCRIPT_AI_CALLBACK(NAME, FUNC, ...)                                                                 \
    __ME_REPLACE_GENERIC_SCRIPT(ScriptAICallback, NAME, FUNC, ##__VA_ARGS__)

#define ME_REGISTER_SCRIPT_AI_ROUTINE(NAME, FUNC) __ME_REGISTER_GENERIC_SCRIPT(ScriptAIRoutine, NAME, FUNC)
#define ME_UNREGISTER_SCRIPT_AI_ROUTINE(NAME) __ME_UNREGISTER_GENERIC_SCRIPT(ScriptAIRoutine, NAME)
#define ME_REPLACE_SCRIPT_AI_ROUTINE(NAME, FUNC, ...)                                                                  \
    __ME_REPLACE_GENERIC_SCRIPT(ScriptAIRoutine, NAME, FUNC, ##__VA_ARGS__)

#define ME_REGISTER_SCRIPT(NAME, FUNC) __ME_REGISTER_GENERIC_SCRIPT(Script, NAME, FUNC)
#define ME_UNREGISTER_SCRIPT(NAME) __ME_UNREGISTER_GENERIC_SCRIPT(Script, NAME)
// Shouldn't be used, as Script_paru calls most of its scripts directly (bypassing CallScriptXXX), use ME_HOOK_SCRIPT
// instead.
#define __ME_REPLACE_SCRIPT(NAME, FUNC, ...) __ME_REPLACE_GENERIC_SCRIPT(Script, NAME, FUNC, ##__VA_ARGS__)
#define ME_HOOK_SCRIPT(NAME, FUNC, ...) __ME_REGISTER_GENERIC_SCRIPT_REPLACE(Script, NAME, FUNC, ##__VA_ARGS__)

#define __ME_DEFINE_AND_REGISTER_GENERIC_SCRIPT(NAME, FUNC, DECL)                                                      \
    DECL;                                                                                                              \
    GE_STATIC_BLOCK                                                                                                    \
    {                                                                                                                  \
        __ME_REGISTER_GENERIC_SCRIPT(FUNC, #NAME, NAME);                                                               \
    }                                                                                                                  \
    DECL

#define __ME_DEFINE_AND_REPLACE_GENERIC_SCRIPT(NAME, FUNC, DECL)                                                       \
    DECL;                                                                                                              \
    gF##FUNC NAME##_Original;                                                                                          \
    GE_STATIC_BLOCK                                                                                                    \
    {                                                                                                                  \
        __ME_REGISTER_GENERIC_SCRIPT_REPLACE(FUNC, #NAME, NAME, &NAME##_Original);                                     \
    }                                                                                                                  \
    DECL

#define ME_DEFINE_AND_REGISTER_SCRIPT_AI_STATE(NAME)                                                                   \
    __ME_DEFINE_AND_REGISTER_GENERIC_SCRIPT(NAME, ScriptAIState, DECLARE_SCRIPT_STATE(NAME))
#define ME_DEFINE_AND_REPLACE_SCRIPT_AI_STATE(NAME)                                                                    \
    __ME_DEFINE_AND_REPLACE_GENERIC_SCRIPT(NAME, ScriptAIState, DECLARE_SCRIPT_STATE(NAME))

#define ME_DEFINE_AND_REGISTER_SCRIPT_AI_FUNCTION(NAME)                                                                \
    __ME_DEFINE_AND_REGISTER_GENERIC_SCRIPT(NAME, ScriptAIFunction, DECLARE_SCRIPT_FUNCTION(NAME))
#define ME_DEFINE_AND_REPLACE_SCRIPT_AI_FUNCTION(NAME)                                                                 \
    __ME_DEFINE_AND_REPLACE_GENERIC_SCRIPT(NAME, ScriptAIFunction, DECLARE_SCRIPT_FUNCTION(NAME))

#define ME_DEFINE_AND_REGISTER_SCRIPT_AI_CALLBACK(NAME)                                                                \
    __ME_DEFINE_AND_REGISTER_GENERIC_SCRIPT(NAME, ScriptAICallback, DECLARE_SCRIPT_CALLBACK(NAME))
#define ME_DEFINE_AND_REPLACE_SCRIPT_AI_CALLBACK(NAME)                                                                 \
    __ME_DEFINE_AND_REPLACE_GENERIC_SCRIPT(NAME, ScriptAICallback, DECLARE_SCRIPT_CALLBACK(NAME))

#define ME_DEFINE_AND_REGISTER_SCRIPT_AI_ROUTINE(NAME)                                                                 \
    __ME_DEFINE_AND_REGISTER_GENERIC_SCRIPT(NAME, ScriptAIRoutine, DECLARE_SCRIPT_ROUTINE(NAME))
#define ME_DEFINE_AND_REPLACE_SCRIPT_AI_ROUTINE(NAME)                                                                  \
    __ME_DEFINE_AND_REPLACE_GENERIC_SCRIPT(NAME, ScriptAIRoutine, DECLARE_SCRIPT_ROUTINE(NAME))

#define ME_DEFINE_AND_REGISTER_SCRIPT(NAME) __ME_DEFINE_AND_REGISTER_GENERIC_SCRIPT(NAME, Script, DECLARE_SCRIPT(NAME))
#define ME_DEFINE_AND_HOOK_SCRIPT(NAME)                                                                                \
    DECLARE_SCRIPT(NAME);                                                                                              \
    gFScript NAME##_Original;                                                                                          \
    GE_STATIC_BLOCK                                                                                                    \
    {                                                                                                                  \
        ME_HOOK_SCRIPT(#NAME, NAME, &NAME##_Original);                                                                 \
    }                                                                                                                  \
    DECLARE_SCRIPT(NAME)

enum mEPropertySetOffset
{
    mEPropertySetOffset_Routine = 1,
    mEPropertySetOffset_Animation = 2,
    mEPropertySetOffset_CollisionShape = 3,
    mEPropertySetOffset_Clock = 4,
    mEPropertySetOffset_Door = 5,
    mEPropertySetOffset_Focus = 6,
    mEPropertySetOffset_Interaction = 7,
    mEPropertySetOffset_InfoManager = 8,
    mEPropertySetOffset_Inventory = 9,
    mEPropertySetOffset_Item = 10,
    mEPropertySetOffset_Lock = 11,
    mEPropertySetOffset_Navigation = 12,
    mEPropertySetOffset_Npc = 13,
    mEPropertySetOffset_PlayerMemory = 14,
    mEPropertySetOffset_RigidBody = 15,
    mEPropertySetOffset_CharacterControl = 16,
    mEPropertySetOffset_CharacterMovement = 17,
    mEPropertySetOffset_Damage = 18,
    mEPropertySetOffset_DamageReceiver = 19,
    mEPropertySetOffset_TouchDamage = 20,
    mEPropertySetOffset_Dialog = 21,
    mEPropertySetOffset_Party = 22,
    mEPropertySetOffset_Anchor = 23,
    mEPropertySetOffset_Letter = 24,
    mEPropertySetOffset_Book = 25,
    mEPropertySetOffset_Map = 26,
    mEPropertySetOffset_Recipe = 27,
    mEPropertySetOffset_Projectile = 28,
    mEPropertySetOffset_QuestManager = 29,
    mEPropertySetOffset_Strip = 30,
    mEPropertySetOffset_Particle = 31,
    mEPropertySetOffset_Camera = 32,
    mEPropertySetOffset_Enclave = 33,
    mEPropertySetOffset_Arena = 34,
    mEPropertySetOffset_AIZone = 35,
    mEPropertySetOffset_Effect = 36,
    mEPropertySetOffset_Magic = 37,
    mEPropertySetOffset_Skill = 38,
    mEPropertySetOffset_Mover = 39,
    mEPropertySetOffset_Trigger = 40,
    mEPropertySetOffset_TreasureSet = 41
};

Entity *GetEntity(EntityPropertySet *a_pPropertySet, mEPropertySetOffset a_PropertySetOffset);
Entity const *GetEntity(EntityPropertySet const *a_pPropertySet, mEPropertySetOffset a_PropertySetOffset);
Entity GetTreasureSet(PSInventory const &a_Inventory, gETreasureDistribution a_enuTreasureDistribution);
GEBool StartSaySVM(Entity a_Speaker, Entity a_Target, bCString a_strSVM, GEU32 a_u32Type);
GEInt GetShortActionDuration();
GEInt GetLongActionDuration();
Entity GetCurrentRoutinePoint(Entity &a_Entity);
PSInfoManager &GetCurrentInfoManager();
PSInfoScriptCommand &GetCurrentInfoScriptCommand();
gEPhase GetPhaseFromGesture(Entity const &a_Speaker, bCString const &a_strGesture);

bTObjArray<Entity> &FindInteractObjects(Entity const &a_Entity);
Entity FindInteractObjectWithUseType(Entity const &a_Entity, gEUseType a_enuUseType);
void RefineFoundFreepoints(gEUseType a_enuUseType);
Entity GetFirstFoundRefinedFreepoint();
Entity GetRandomFoundRefinedFreepoint();
void FreeDestinationPointsOfEnclaveMembers(Entity const &a_Enclave);

void ClearNextActionsIfPlayer(Entity const &a_Entity);
void PopCurrentActionIfPlayer(Entity const &a_Entity);

// Item that the player shall hold in the left hand.
// Set to the index of the item stack, as long as the player holds the item.
GEInt GetPlayerIntendedLeftHandWeaponIndex();
// Item that the player shall hold in the right hand.
// Set to the index of the item stack, as long as the player holds the item.
GEInt GetPlayerIntendedRightHandWeaponIndex();
// Item that the player should use next (e.g. in PS_QuickUse or PS_MagicPotion).
void SetUseItemIndexIfPlayer(Entity const &a_Entity, GEInt a_iItemIndex);

// The enum names are pure guesswork.
enum gEItemComboCategory
{
    gEItemComboCategory_Deny = 0,
    gEItemComboCategory_Utility = 1,
    gEItemComboCategory_CombatItem = 2, // Unconventional weapon? Don't remove in RemoveNonCombatItems? Ahhh... Can be
                                        // equipped kept while the HUD is shown (e.g. Shovel or Staff, see PS_HUD).
    gEItemComboCategory_Carry_Smithing = 3,
    gEItemComboCategory_Melee = 4,
    gEItemComboCategory_Ranged = 5, // (Bow / CrossBow)
    gEItemComboCategory_Cast = 6,
    gEItemComboCategory_EquipSlotAmmo = 7, // SlotAmmo, Left = None, Right = Arrow / Bolt
    gEItemComboCategory_EmptyHands = 8,
};

struct gSItemComboCategorization
{
    gEUseType m_enuUseTypeLeft;
    gEUseType m_enuUseTypeRight;
    gEItemComboCategory m_enuCategory;
};
bTObjArray<gSItemComboCategorization> &GetItemComboCategorization();

gEItemComboCategory GetItemComboCategory(gEUseType a_enuUseTypeLeft, gEUseType a_enuUseTypeRight);

gEItemComboCategory GetItemComboCategory(Entity const &a_Holder, GEInt a_iLeftItem, GEInt a_iRightItem);

// Updates PlayerIntendedLeftHandWeaponIndex and PlayerIntendedRightHandWeaponIndex.
gEItemComboCategory EvaluateUseWeaponStack(Entity const &a_Player, GEInt a_iWeaponIndex);

template <typename T>
typename T::INSTANCE_CLASS *ToInstance(T &a_pPropertySet)
{
    return *reinterpret_cast<typename T::INSTANCE_CLASS **>(static_cast<EntityPropertySet *>(&a_pPropertySet));
}

template <typename T>
typename T::INSTANCE_CLASS const *ToInstance(T const &a_pPropertySet)
{
    return *reinterpret_cast<typename T::INSTANCE_CLASS *const *>(
        static_cast<EntityPropertySet const *>(&a_pPropertySet));
}

GEU32 GetItemQuality(bCString const &a_ItemName);

gEWeaponCategory GetHeldWeaponCategory(Entity const &a_Entity);
