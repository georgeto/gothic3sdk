#include "ScriptUtil.h"

#include <g3sdk/util/Hook.h>
#include <g3sdk/util/Logging.h>
#include <g3sdk/util/Memory.h>
#include <g3sdk/util/Util.h>

mCScriptHookRegistry::~mCScriptHookRegistry()
{
    m_arrHooks.DeleteAll();
}

GEBool mCScriptHookRegistry::ReplaceScriptAIState(gSScriptAIState const &a_ScriptState,
                                                  gFScriptAIState *o_pOriginalScript)
{
    mTOriginalWrapper<gSScriptAIState, gFScriptAIState> ScriptState{a_ScriptState, o_pOriginalScript};
    if (m_arrScriptAIStates.IndexOf(ScriptState) != -1)
    {
        GetDefaultLogger().LogFormat("[mCScriptHookRegistry] Unable to replace ScriptAIState %s, because it already "
                                     "has another replacement registered.\n",
                                     a_ScriptState.m_strName.GetText());
        return GEFalse;
    }
    else
    {
        m_arrScriptAIStates.Add(ScriptState);
        return GETrue;
    }
}

GEBool mCScriptHookRegistry::ReplaceScriptAIFunction(gSScriptAIFunction const &a_ScriptFunction,
                                                     gFScriptAIFunction *o_pOriginalScript)
{
    mTOriginalWrapper<gSScriptAIFunction, gFScriptAIFunction> ScriptFunction{a_ScriptFunction, o_pOriginalScript};
    if (m_arrScriptAIFunctions.IndexOf(ScriptFunction) != -1)
    {
        GetDefaultLogger().LogFormat("[mCScriptHookRegistry] Unable to replace ScriptAIFunction %s, because it already "
                                     "has another replacement registered.\n",
                                     a_ScriptFunction.m_strName.GetText());
        return GEFalse;
    }
    else
    {
        m_arrScriptAIFunctions.Add(ScriptFunction);
        return GETrue;
    }
}

GEBool mCScriptHookRegistry::ReplaceScriptAICallback(gSScriptAICallback const &a_ScriptCallback,
                                                     gFScriptAICallback *o_pOriginalScript)
{
    mTOriginalWrapper<gSScriptAICallback, gFScriptAICallback> ScriptCallback{a_ScriptCallback, o_pOriginalScript};
    if (m_arrScriptAICallbacks.IndexOf(ScriptCallback) != -1)
    {
        GetDefaultLogger().LogFormat("[mCScriptHookRegistry] Unable to replace ScriptAICallback %s, because it already "
                                     "has another replacement registered.\n",
                                     a_ScriptCallback.m_strName.GetText());
        return GEFalse;
    }
    else
    {
        m_arrScriptAICallbacks.Add(ScriptCallback);
        return GETrue;
    }
}

GEBool mCScriptHookRegistry::ReplaceScriptAIRoutine(gSScriptAIRoutine const &a_ScriptRoutine,
                                                    gFScriptAIRoutine *o_pOriginalScript)
{
    mTOriginalWrapper<gSScriptAIRoutine, gFScriptAIRoutine> ScriptRoutine{a_ScriptRoutine, o_pOriginalScript};
    if (m_arrScriptAIRoutines.IndexOf(ScriptRoutine) != -1)
    {
        GetDefaultLogger().LogFormat("[mCScriptHookRegistry] Unable to replace ScriptAIRoutine %s, because it already "
                                     "has another replacement registered.\n",
                                     a_ScriptRoutine.m_strName.GetText());
        return GEFalse;
    }
    else
    {
        m_arrScriptAIRoutines.Add(ScriptRoutine);
        return GETrue;
    }
}

GEBool mCScriptHookRegistry::ReplaceScript(gSScript const &a_Script, gFScript *o_pOriginalScript)
{
    mTOriginalWrapper<gSScript, gFScript> Script{a_Script, o_pOriginalScript};
    if (m_arrScripts.IndexOf(Script) != -1)
    {
        GetDefaultLogger().LogFormat("[mCScriptHookRegistry] Unable to register hook for Script %s, because it already "
                                     "has another hook registered.\n",
                                     a_Script.m_strName.GetText());
        return GEFalse;
    }
    else
    {
        m_arrScripts.Add(Script);
        return GETrue;
    }
}

void mCScriptHookRegistry::Hook()
{
    gCScriptAdminExt &ScriptAdmin = GetScriptAdminExt();
    GE_ARRAY_FOR_EACH (ScriptState, m_arrScriptAIStates)
    {
        ME_REPLACE_SCRIPT_AI_STATE(ScriptState.Script.m_strName, ScriptState.Script.m_funcScriptAIState,
                                   ScriptState.pOriginalScript);
    }

    GE_ARRAY_FOR_EACH (ScriptFunction, m_arrScriptAIFunctions)
    {
        ME_REPLACE_SCRIPT_AI_FUNCTION(ScriptFunction.Script.m_strName, ScriptFunction.Script.m_funcScriptAIFunction,
                                      ScriptFunction.pOriginalScript);
    }

    GE_ARRAY_FOR_EACH (ScriptCallback, m_arrScriptAICallbacks)
    {
        ME_REPLACE_SCRIPT_AI_CALLBACK(ScriptCallback.Script.m_strName, ScriptCallback.Script.m_funcScriptAICallback,
                                      ScriptCallback.pOriginalScript);
    }

    GE_ARRAY_FOR_EACH (ScriptRoutine, m_arrScriptAIRoutines)
    {
        ME_REPLACE_SCRIPT_AI_ROUTINE(ScriptRoutine.Script.m_strName, ScriptRoutine.Script.m_funcScriptAIRoutine,
                                     ScriptRoutine.pOriginalScript);
    }

    GE_ARRAY_FOR_EACH (Script, m_arrScripts)
    {
        gSScript const *pOriginalScript = ScriptAdmin.GetScript(Script.Script.m_strName);
        if (pOriginalScript)
        {
            mCFunctionHook *pHook = GE_NEW(mCFunctionHook);
            pHook->Hook(pOriginalScript->m_funcScript, Script.Script.m_funcScript);
            m_arrHooks.Add(pHook);

            if (Script.pOriginalScript)
                *Script.pOriginalScript = pHook->GetOriginalFunction<gFScript>();
        }
        else
            GetDefaultLogger().LogFormat("[mCScriptHookRegistry] Unable to find original script with name %s.\n",
                                         Script.Script.m_strName.GetText());

        __ME_REPLACE_SCRIPT(Script.Script.m_strName, Script.Script.m_funcScript);
    }
}

Entity GetTreasureSet(PSInventory const &a_Inventory, gETreasureDistribution a_enuTreasureDistribution)
{
    for (GEInt i = 1; i <= 5; i++)
    {
        Entity TreasureSet;
        switch (i)
        {
        case 1: TreasureSet = a_Inventory.GetTreasureSet1(); break;
        case 2: TreasureSet = a_Inventory.GetTreasureSet2(); break;
        case 3: TreasureSet = a_Inventory.GetTreasureSet3(); break;
        case 4: TreasureSet = a_Inventory.GetTreasureSet4(); break;
        case 5: TreasureSet = a_Inventory.GetTreasureSet5(); break;
        }
        if (TreasureSet.TreasureSet.TreasureDistribution == a_enuTreasureDistribution)
            return TreasureSet;
    }
    return None;
}

using mFStartSaySVM = GEBool(GE_STDCALL *)(Entity a_Speaker, Entity a_Target, bCString a_strSVM);
GEBool StartSaySVM(Entity a_Speaker, Entity a_Target, bCString a_strSVM, GEU32 a_u32Type)
{
    static mCCaller CallStartSaySVM(mCCaller::GetCallerParams(RVA_ScriptGame(0xBAF0), mERegisterType_Eax));

    CallStartSaySVM.SetImmEax(a_u32Type);
    return CallStartSaySVM.GetFunction<mFStartSaySVM>()(a_Speaker, a_Target, a_strSVM);
}

using mFGetDuration = GEInt(GE_CCALL *)();
GEInt GetShortActionDuration()
{
    static mFGetDuration s_fGetShortActionDuration = force_cast<mFGetDuration>(RVA_ScriptGame(0x7690));
    return s_fGetShortActionDuration();
}

GEInt GetLongActionDuration()
{
    static mFGetDuration s_fGetLongActionDuration = force_cast<mFGetDuration>(RVA_ScriptGame(0x76B0));
    return s_fGetLongActionDuration();
}

Entity *GetEntity(EntityPropertySet *a_pPropertySet, mEPropertySetOffset a_PropertySetOffset)
{
    return reinterpret_cast<Entity *>(a_pPropertySet - a_PropertySetOffset);
}

Entity const *GetEntity(EntityPropertySet const *a_pPropertySet, mEPropertySetOffset a_PropertySetOffset)
{
    return reinterpret_cast<Entity const *>(a_pPropertySet - a_PropertySetOffset);
}

Entity GetCurrentRoutinePoint(Entity &a_Entity)
{
    GEInt iRoutineTime = GetScriptAdmin().CallScriptFromScript("GetRoutineTime", &a_Entity, &None, 0);
    switch (iRoutineTime)
    {
    case 0:  return a_Entity.Navigation.GetSleepingPoint();
    case 1:  return a_Entity.Navigation.GetWorkingPoint();
    case 2:  return a_Entity.Navigation.GetRelaxingPoint();
    default: return None;
    }
}

PSInfoManager &GetCurrentInfoManager()
{
    static PSInfoManager &s_CurrentInfoManger = *reinterpret_cast<PSInfoManager *>(RVA_ScriptGame(0x119A1C));
    return s_CurrentInfoManger;
}

PSInfoScriptCommand &GetCurrentInfoScriptCommand()
{
    return *reinterpret_cast<PSInfoScriptCommand *>(RVA_ScriptGame(0x119C48));
}

gEPhase GetPhaseFromGesture(Entity const &a_Speaker, bCString const &a_strGesture)
{
    using mFGetPhaseFromGesture = gEPhase(GE_STDCALL *)(Entity a_Speaker, bCString a_strGesture);
    static mFGetPhaseFromGesture s_fGetPhaseFromGesture = force_cast<mFGetPhaseFromGesture>(RVA_ScriptGame(0xBD30));

    return s_fGetPhaseFromGesture(a_Speaker, a_strGesture);
}

static bTObjArray<Entity> *g_arrFoundFreepointsByUseType =
    reinterpret_cast<bTObjArray<Entity> *>(RVA_ScriptGame(0x118ACC));
bTObjArray<Entity> &FindInteractObjects(Entity const &a_Entity)
{
    using mFFindInteractObjects = void(GE_STDCALL *)(Entity);
    static mFFindInteractObjects s_fFindInteractObjects = force_cast<mFFindInteractObjects>(RVA_ScriptGame(0x7C90));

    s_fFindInteractObjects(a_Entity);
    return *g_arrFoundFreepointsByUseType;
}

Entity FindInteractObjectWithUseType(Entity const &a_Entity, gEUseType a_enuUseType)
{
    return FindInteractObjects(a_Entity)[a_enuUseType];
}

static bTObjArray<Entity> *g_arrFoundFreepointsRefined =
    reinterpret_cast<bTObjArray<Entity> *>(RVA_ScriptGame(0x118AD8));
void RefineFoundFreepoints(gEUseType a_enuUseType)
{
    if (g_arrFoundFreepointsByUseType->GetAt(a_enuUseType) != None)
        g_arrFoundFreepointsRefined->Add(g_arrFoundFreepointsByUseType->GetAt(a_enuUseType));
}

Entity GetFirstFoundRefinedFreepoint()
{
    GE_ARRAY_FOR_EACH (FoundFreepoint, *g_arrFoundFreepointsRefined)
    {
        if (FoundFreepoint != None)
            return FoundFreepoint;
    }

    return None;
}

Entity GetRandomFoundRefinedFreepoint()
{
    if (g_arrFoundFreepointsRefined->GetCount() <= 0)
        return None;

    return g_arrFoundFreepointsRefined->GetAt(Entity::GetRandomNumber(g_arrFoundFreepointsRefined->GetCount()));
}

void FreeDestinationPointsOfEnclaveMembers(Entity const &a_Enclave)
{
    using mFFreeDestinationPointsOfEnclaveMembers = void(GE_STDCALL *)(Entity);
    static mFFreeDestinationPointsOfEnclaveMembers s_fFreeDestinationPointsOfEnclaveMembers =
        force_cast<mFFreeDestinationPointsOfEnclaveMembers>(RVA_ScriptGame(0xB0B10));

    s_fFreeDestinationPointsOfEnclaveMembers(a_Enclave);
}

void ClearNextActionsIfPlayer(Entity const &a_Entity)
{
    using mFClearNextActionsIfPlayer = void(GE_STDCALL *)(Entity);
    static mFClearNextActionsIfPlayer s_fClearNextActionsIfPlayer =
        force_cast<mFClearNextActionsIfPlayer>(RVA_ScriptGame(0x7A00));

    return s_fClearNextActionsIfPlayer(a_Entity);
}

void PopCurrentActionIfPlayer(Entity const &a_Entity)
{
    using mFPopCurrentActionIfPlayer = void(GE_STDCALL *)(Entity);
    static mFPopCurrentActionIfPlayer s_fPopCurrentActionIfPlayer =
        force_cast<mFPopCurrentActionIfPlayer>(RVA_ScriptGame(0x79A0));

    return s_fPopCurrentActionIfPlayer(a_Entity);
}

GEInt GetPlayerIntendedLeftHandWeaponIndex()
{
    return *reinterpret_cast<GEInt *>(RVA_ScriptGame(0x118AB4));
}

GEInt GetPlayerIntendedRightHandWeaponIndex()
{
    return *reinterpret_cast<GEInt *>(RVA_ScriptGame(0x118AB8));
}

void SetUseItemIndexIfPlayer(Entity const &a_Entity, GEInt a_iItemIndex)
{
    if (a_Entity.IsPlayer())
        *reinterpret_cast<GEInt *>(RVA_ScriptGame(0x118ABC)) = a_iItemIndex;
}

bTObjArray<gSItemComboCategorization> &GetItemComboCategorization()
{
    return *reinterpret_cast<bTObjArray<gSItemComboCategorization> *>(RVA_ScriptGame(0x118AC0));
}

gEItemComboCategory GetItemComboCategory(gEUseType a_enuUseTypeLeft, gEUseType a_enuUseTypeRight)
{
    bTObjArray<gSItemComboCategorization> const &ItemComboCategorization = GetItemComboCategorization();
    GE_ARRAY_FOR_EACH (Categorization, ItemComboCategorization)
    {
        if (Categorization.m_enuUseTypeLeft == a_enuUseTypeLeft
            && Categorization.m_enuUseTypeRight == a_enuUseTypeRight)
            return Categorization.m_enuCategory;
    }
    return gEItemComboCategory_Deny;
}

gEItemComboCategory GetItemComboCategory(Entity const &a_Holder, GEInt a_iLeftItem, GEInt a_iRightItem)
{
    return GetItemComboCategory(a_Holder.Inventory.GetUseType(a_iLeftItem),
                                a_Holder.Inventory.GetUseType(a_iRightItem));
}

gEItemComboCategory EvaluateUseWeaponStack(Entity const &a_Player, GEInt a_iWeaponIndex)
{
    using mFEvaluateUseWeaponStack = gEItemComboCategory(GE_STDCALL *)(Entity);
    static mCCaller CallEvaluateUseWeaponStack(mCCaller::GetCallerParams(RVA_ScriptGame(0x2550), mERegisterType_Eax));

    CallEvaluateUseWeaponStack.SetImmEax(a_iWeaponIndex);
    return CallEvaluateUseWeaponStack.GetFunction<mFEvaluateUseWeaponStack>()(a_Player);
}

GEU32 GetItemQuality(bCString const &a_ItemName)
{
    eCSceneAdmin *pSceneAdmin = FindModule<eCSceneAdmin>();
    if (!pSceneAdmin)
        return 0;

    gCItem_PS const *pItem =
        GetPropertySet<gCItem_PS>(pSceneAdmin->GetTemplateEntityByName(a_ItemName), eEPropertySetType_Item);
    return pItem ? pItem->GetQuality() : 0;
}

gEWeaponCategory GetHeldWeaponCategory(Entity const &a_Entity)
{
    using mFGetHeldWeaponCategory = gEWeaponCategory(GE_STDCALL *)(Entity);
    static mFGetHeldWeaponCategory s_fGetHeldWeaponCategory =
        force_cast<mFGetHeldWeaponCategory>(RVA_ScriptGame(0x3240));

    return s_fGetHeldWeaponCategory(a_Entity);
}
