#ifndef SCRIPT_UTIL_H_INCLUDED
#define SCRIPT_UTIL_H_INCLUDED

#include "Script.h"

gSScriptInit & GetScriptInit();

class mCFunctionHook;
class mCScriptHookRegistry : public gSScriptInit
{
    public:
        ~mCScriptHookRegistry();
        GEBool ReplaceScriptAIState(gSScriptAIState const & a_ScriptState);
        GEBool ReplaceScriptAIFunction(gSScriptAIFunction const & a_ScriptFunction);
        GEBool ReplaceScriptAICallback(gSScriptAICallback const & a_ScriptCallback);
        GEBool ReplaceScriptAIRoutine(gSScriptAIRoutine const & a_ScriptRoutine);
        GEBool ReplaceScript(gSScript const & a_Script);
        void Hook();

    private:
        bTObjArray< gSScriptAIState >    m_arrScriptAIStates;
        bTObjArray< gSScriptAIFunction > m_arrScriptAIFunctions;
        bTObjArray< gSScriptAICallback > m_arrScriptAICallbacks;
        bTObjArray< gSScriptAIRoutine >  m_arrScriptAIRoutines;
        bTObjArray< gSScript >           m_arrScripts;
        bTPtrArray< mCFunctionHook * >   m_arrHooks;
};
mCScriptHookRegistry & GetScriptHookRegistry();


#define __ME_REGISTER_GENERIC_SCRIPT( TYPE, NAME, FUNC ) \
    GetScriptInit().m_arr ## TYPE ## s.Add( gS ## TYPE ( NAME, __FILE__, FUNC ) );

#define __ME_UNREGISTER_GENERIC_SCRIPT( TYPE, NAME ) \
    GetScriptAdminExt().UnRegister ## TYPE( const_cast<gS ## TYPE *>( GetScriptAdminExt().Get ## TYPE( NAME ) ) );

#define __ME_REGISTER_GENERIC_SCRIPT_REPLACE( TYPE, NAME, FUNC ) \
    GetScriptHookRegistry().Replace ## TYPE( gS ## TYPE ( NAME, __FILE__, FUNC ) );

#define __ME_REPLACE_GENERIC_SCRIPT( TYPE, NAME, FUNC ) \
    __ME_UNREGISTER_GENERIC_SCRIPT( TYPE, NAME )            \
    __ME_REGISTER_GENERIC_SCRIPT( TYPE, NAME, FUNC )

#define ME_REGISTER_SCRIPT_AI_STATE( NAME, FUNC ) __ME_REGISTER_GENERIC_SCRIPT( ScriptAIState, NAME, FUNC )
#define ME_UNREGISTER_SCRIPT_AI_STATE( NAME ) __ME_UNREGISTER_GENERIC_SCRIPT( ScriptAIState, NAME )
#define ME_REPLACE_SCRIPT_AI_STATE( NAME, FUNC ) __ME_REPLACE_GENERIC_SCRIPT( ScriptAIState, NAME, FUNC )

#define ME_REGISTER_SCRIPT_AI_FUNCTION( NAME, FUNC ) __ME_REGISTER_GENERIC_SCRIPT( ScriptAIFunction, NAME, FUNC )
#define ME_UNREGISTER_SCRIPT_AI_FUNCTION( NAME ) __ME_UNREGISTER_GENERIC_SCRIPT( ScriptAIFunction, NAME )
#define ME_REPLACE_SCRIPT_AI_FUNCTION( NAME, FUNC ) __ME_REPLACE_GENERIC_SCRIPT( ScriptAIFunction, NAME, FUNC )

#define ME_REGISTER_SCRIPT_AI_CALLBACK( NAME, FUNC ) __ME_REGISTER_GENERIC_SCRIPT( ScriptAICallback, NAME, FUNC )
#define ME_UNREGISTER_SCRIPT_AI_CALLBACK( NAME ) __ME_UNREGISTER_GENERIC_SCRIPT( ScriptAICallback, NAME )
#define ME_REPLACE_SCRIPT_AI_CALLBACK( NAME, FUNC ) __ME_REPLACE_GENERIC_SCRIPT( ScriptAICallback, NAME, FUNC )

#define ME_REGISTER_SCRIPT_AI_ROUTINE( NAME, FUNC ) __ME_REGISTER_GENERIC_SCRIPT( ScriptAIRoutine, NAME, FUNC )
#define ME_UNREGISTER_SCRIPT_AI_ROUTINE( NAME ) __ME_UNREGISTER_GENERIC_SCRIPT( ScriptAIRoutine, NAME )
#define ME_REPLACE_SCRIPT_AI_ROUTINE( NAME, FUNC ) __ME_REPLACE_GENERIC_SCRIPT( ScriptAIRoutine, NAME, FUNC )

#define ME_REGISTER_SCRIPT( NAME, FUNC ) __ME_REGISTER_GENERIC_SCRIPT( Script, NAME, FUNC )
#define ME_UNREGISTER_SCRIPT( NAME ) __ME_UNREGISTER_GENERIC_SCRIPT( Script, NAME )
#define ME_REPLACE_SCRIPT( NAME, FUNC ) __ME_REPLACE_GENERIC_SCRIPT( Script, NAME, FUNC )
#define ME_HOOK_SCRIPT( NAME, FUNC ) __ME_REGISTER_GENERIC_SCRIPT_REPLACE( Script, NAME, FUNC )

#define ME_DEFINE_AND_REGISTER_SCRIPT_AI_STATE( NAME ) \
    DECLARE_SCRIPT_STATE( NAME ); \
    GE_STATIC_BLOCK { ME_REGISTER_SCRIPT_AI_STATE( #NAME, NAME ); } \
    DECLARE_SCRIPT_STATE( NAME )

#define ME_DEFINE_AND_REPLACE_SCRIPT_AI_STATE( NAME ) \
    DECLARE_SCRIPT_STATE( NAME ); \
    GE_STATIC_BLOCK { __ME_REGISTER_GENERIC_SCRIPT_REPLACE( ScriptAIState, #NAME, NAME ); } \
    DECLARE_SCRIPT_STATE( NAME )

#define ME_DEFINE_AND_REGISTER_SCRIPT( NAME ) \
    DECLARE_SCRIPT( NAME ); \
    GE_STATIC_BLOCK { ME_REGISTER_SCRIPT( #NAME, NAME ); } \
    DECLARE_SCRIPT( NAME )

#define ME_DEFINE_AND_HOOK_SCRIPT( NAME ) \
    DECLARE_SCRIPT( NAME ); \
    GE_STATIC_BLOCK { ME_HOOK_SCRIPT( #NAME, NAME ); } \
    DECLARE_SCRIPT( NAME )

enum mEPropertySetOffset
{
    mEPropertySetOffset_Routine           = 1,
    mEPropertySetOffset_Animation         = 2,
    mEPropertySetOffset_CollisionShape    = 3,
    mEPropertySetOffset_Clock             = 4,
    mEPropertySetOffset_Door              = 5,
    mEPropertySetOffset_Focus             = 6,
    mEPropertySetOffset_Interaction       = 7,
    mEPropertySetOffset_InfoManager       = 8,
    mEPropertySetOffset_Inventory         = 9,
    mEPropertySetOffset_Item              = 10,
    mEPropertySetOffset_Lock              = 11,
    mEPropertySetOffset_Navigation        = 12,
    mEPropertySetOffset_Npc               = 13,
    mEPropertySetOffset_PlayerMemory      = 14,
    mEPropertySetOffset_RigidBody         = 15,
    mEPropertySetOffset_CharacterControl  = 16,
    mEPropertySetOffset_CharacterMovement = 17,
    mEPropertySetOffset_Damage            = 18,
    mEPropertySetOffset_DamageReceiver    = 19,
    mEPropertySetOffset_TouchDamage       = 20,
    mEPropertySetOffset_Dialog            = 21,
    mEPropertySetOffset_Party             = 22,
    mEPropertySetOffset_Anchor            = 23,
    mEPropertySetOffset_Letter            = 24,
    mEPropertySetOffset_Book              = 25,
    mEPropertySetOffset_Map               = 26,
    mEPropertySetOffset_Recipe            = 27,
    mEPropertySetOffset_Projectile        = 28,
    mEPropertySetOffset_QuestManager      = 29,
    mEPropertySetOffset_Strip             = 30,
    mEPropertySetOffset_Particle          = 31,
    mEPropertySetOffset_Camera            = 32,
    mEPropertySetOffset_Enclave           = 33,
    mEPropertySetOffset_Arena             = 34,
    mEPropertySetOffset_AIZone            = 35,
    mEPropertySetOffset_Effect            = 36,
    mEPropertySetOffset_Magic             = 37,
    mEPropertySetOffset_Skill             = 38,
    mEPropertySetOffset_Mover             = 39,
    mEPropertySetOffset_Trigger           = 40,
    mEPropertySetOffset_TreasureSet       = 41
};

Entity *              GetEntity( EntityPropertySet * a_pPropertySet, mEPropertySetOffset a_PropertySetOffset );
Entity const *        GetEntity( EntityPropertySet const * a_pPropertySet, mEPropertySetOffset a_PropertySetOffset );
Entity                GetTreasureSet( PSInventory const & a_Inventory, gETreasureDistribution a_enuTreasureDistribution );
GEBool                StartSaySVM( Entity a_Speaker, Entity a_Target, bCString a_strSVM, GEU32 a_u32Type );
GEInt                 GetShortActionDuration( void );
GEInt                 GetLongActionDuration( void );
Entity                GetCurrentRoutinePoint( Entity & a_Entity );
PSInfoManager &       GetCurrentInfoManager( void );
PSInfoScriptCommand & GetCurrentInfoScriptCommand( void );
gEPhase               GetPhaseFromGesture(Entity const & a_Speaker, bCString const & a_strGesture);

bTObjArray<Entity> & FindInteractObjects( Entity const & a_Entity );
Entity               FindInteractObjectWithUseType( Entity const & a_Entity, gEUseType a_enuUseType );
void                 RefineFoundFreepoints( gEUseType a_enuUseType );
Entity               GetFirstFoundRefinedFreepoint();
Entity               GetRandomFoundRefinedFreepoint();

template<typename T>
T * GetPropertySetInstance(EntityPropertySet & a_pPropertySet)
{
    return *reinterpret_cast<T **>(&a_pPropertySet);
}

GEU32 GetItemQuality(bCString const & a_ItemName);

#endif
