#include "ScriptUtil.h"

#include "Memory.h"
#include "Hook.h"
#include "Util.h"
#include "Logging.h"

mCScriptHookRegistry::~mCScriptHookRegistry()
{
    m_arrHooks.DeleteAll();
}

GEBool mCScriptHookRegistry::ReplaceScriptAIState(gSScriptAIState const & a_ScriptState)
{
    if (m_arrScriptAIStates.IndexOf(a_ScriptState) != -1)
    {
        GetDefaultLogger().LogFormat("[mCScriptHookRegistry] Unable to replace ScriptAIState %s, because it already has another replacement registered.\n", a_ScriptState.m_strName);
        return GEFalse;
    }
    else
    {
        m_arrScriptAIStates.Add(a_ScriptState);
        return GETrue;
    }
}

GEBool mCScriptHookRegistry::ReplaceScriptAIFunction(gSScriptAIFunction const & a_ScriptFunction)
{
    if (m_arrScriptAIFunctions.IndexOf(a_ScriptFunction) != -1)
    {
        GetDefaultLogger().LogFormat("[mCScriptHookRegistry] Unable to replace ScriptAIFunction %s, because it already has another replacement registered.\n", a_ScriptFunction.m_strName);
        return GEFalse;
    }
    else
    {
        m_arrScriptAIFunctions.Add(a_ScriptFunction);
        return GETrue;
    }
}

GEBool mCScriptHookRegistry::ReplaceScriptAICallback(gSScriptAICallback const & a_ScriptCallback)
{
    if (m_arrScriptAICallbacks.IndexOf(a_ScriptCallback) != -1)
    {
        GetDefaultLogger().LogFormat("[mCScriptHookRegistry] Unable to replace ScriptAICallback %s, because it already has another replacement registered.\n", a_ScriptCallback.m_strName);
        return GEFalse;
    }
    else
    {
        m_arrScriptAICallbacks.Add(a_ScriptCallback);
        return GETrue;
    }
}

GEBool mCScriptHookRegistry::ReplaceScriptAIRoutine(gSScriptAIRoutine const & a_ScriptRoutine)
{
    if (m_arrScriptAIRoutines.IndexOf(a_ScriptRoutine) != -1)
    {
        GetDefaultLogger().LogFormat("[mCScriptHookRegistry] Unable to replace ScriptAIRoutine %s, because it already has another replacement registered.\n", a_ScriptRoutine.m_strName);
        return GEFalse;
    }
    else
    {
        m_arrScriptAIRoutines.Add(a_ScriptRoutine);
        return GETrue;
    }
}

GEBool mCScriptHookRegistry::ReplaceScript(gSScript const & a_Script)
{
    if (m_arrScripts.IndexOf(a_Script) != -1)
    {
        GetDefaultLogger().LogFormat("[mCScriptHookRegistry] Unable to register hook for Script %s, because it already has another hook registered.\n", a_Script.m_strName);
        return GEFalse;
    }
    else
    {
        m_arrScripts.Add(a_Script);
        return GETrue;
    }
}

void mCScriptHookRegistry::Hook()
{
    GE_ARRAY_FOR_EACH_CONST(gSScriptAIState, ScriptState, m_arrScriptAIStates)
    {
        ME_REPLACE_SCRIPT_AI_STATE(ScriptState->m_strName, ScriptState->m_funcScriptAIState);
    }

    GE_ARRAY_FOR_EACH_CONST(gSScriptAIFunction, ScriptFunction, m_arrScriptAIFunctions)
    {
        ME_REPLACE_SCRIPT_AI_FUNCTION(ScriptFunction->m_strName, ScriptFunction->m_funcScriptAIFunction);
    }

    GE_ARRAY_FOR_EACH_CONST(gSScriptAICallback, ScriptCallback, m_arrScriptAICallbacks)
    {
        ME_REPLACE_SCRIPT_AI_CALLBACK(ScriptCallback->m_strName, ScriptCallback->m_funcScriptAICallback);
    }

    GE_ARRAY_FOR_EACH_CONST(gSScriptAIRoutine, ScriptRoutine, m_arrScriptAIRoutines)
    {
        ME_REPLACE_SCRIPT_AI_ROUTINE(ScriptRoutine->m_strName, ScriptRoutine->m_funcScriptAIRoutine);
    }

    GE_ARRAY_FOR_EACH_CONST(gSScript, Script, m_arrScripts)
    {
        gSScript const * pOriginalScript = GetScriptAdminExt().GetScript(Script->m_strName);
        if (pOriginalScript)
        {
            mCFunctionHook * pHook = GE_NEW(mCFunctionHook);
            pHook->Hook(pOriginalScript->m_funcScript, Script->m_funcScript, mCBaseHook::mEHookType_OnlyStack);
            m_arrHooks.Add(pHook);
        }
        else
            GetDefaultLogger().LogFormat("[mCScriptHookRegistry] Unable to find original script with name %s.\n", Script->m_strName);

        ME_REPLACE_SCRIPT(Script->m_strName, Script->m_funcScript);
    }
}

Entity GetTreasureSet(PSInventory const & a_Inventory, gETreasureDistribution a_enuTreasureDistribution)
{
    for(GEInt i = 1; i <= 5; i++ )
    {
        Entity TreasureSet;
        switch(i)
        {
            case 1:
                TreasureSet = a_Inventory.GetTreasureSet1();
                break;
            case 2:
                TreasureSet = a_Inventory.GetTreasureSet2();
                break;
            case 3:
                TreasureSet = a_Inventory.GetTreasureSet3();
                break;
            case 4:
                TreasureSet = a_Inventory.GetTreasureSet4();
                break;
            case 5:
                TreasureSet = a_Inventory.GetTreasureSet5();
                break;
        }
        if(TreasureSet.TreasureSet.GetProperty<PSTreasureSet::PropertyTreasureDistribution>() == a_enuTreasureDistribution)
            return TreasureSet;
    }
    return None;
}

typedef GEBool ( GE_STDCALL *mFStartSaySVM )( Entity a_Speaker, Entity a_Target, bCString a_strSVM );
GEBool StartSaySVM( Entity a_Speaker, Entity a_Target, bCString a_strSVM, GEU32 a_u32Type )
{
    static mCCaller CallStartSaySVM(mCCaller::GetCallerParams(RVA_ScriptGame(0xBAF0), mCRegisterBase::mERegisterType_Eax));

    CallStartSaySVM.SetImmEax(a_u32Type);
    return CallStartSaySVM.GetFunction<mFStartSaySVM>()(a_Speaker, a_Target, a_strSVM);
}

typedef GEInt ( GE_CCALL *mFGetDuration )( void );
GEInt GetShortActionDuration(void)
{
    static mFGetDuration s_fGetShortActionDuration = force_cast<mFGetDuration>(RVA_ScriptGame(0x7690));
    return s_fGetShortActionDuration();
}

GEInt GetLongActionDuration(void)
{
    static mFGetDuration s_fGetLongActionDuration = force_cast<mFGetDuration>(RVA_ScriptGame(0x76B0));
    return s_fGetLongActionDuration();
}

Entity * GetEntity(EntityPropertySet * a_pPropertySet, mEPropertySetOffset a_PropertySetOffset)
{
    return reinterpret_cast<Entity *>(a_pPropertySet - a_PropertySetOffset);
}

Entity const * GetEntity(EntityPropertySet const * a_pPropertySet, mEPropertySetOffset a_PropertySetOffset)
{
    return reinterpret_cast<Entity const *>(a_pPropertySet - a_PropertySetOffset);
}

Entity GetCurrentRoutinePoint(Entity & a_Entity)
{
    GEInt iRoutineTime = GetScriptAdmin().CallScriptFromScript("GetRoutineTime", &a_Entity, &None, 0);
    switch(iRoutineTime)
    {
        case 0:
            return a_Entity.Navigation.GetSleepingPoint();
        case 1:
            return a_Entity.Navigation.GetWorkingPoint();
        case 2:
            return a_Entity.Navigation.GetRelaxingPoint();
        default:
            return None;
    }
}

PSInfoManager & GetCurrentInfoManager( void )
{
    static PSInfoManager & s_CurrentInfoManger = *reinterpret_cast<PSInfoManager *>(RVA_ScriptGame(0x119A1C));
    return s_CurrentInfoManger;
}

PSInfoScriptCommand & GetCurrentInfoScriptCommand( void )
{
    return *reinterpret_cast<PSInfoScriptCommand *>(RVA_ScriptGame(0x119C48));
}

gEPhase GetPhaseFromGesture(Entity const & a_Speaker, bCString const & a_strGesture)
{
    typedef gEPhase ( GE_STDCALL *mFGetPhaseFromGesture)(Entity a_Speaker, bCString a_strGesture);
    static mFGetPhaseFromGesture s_fGetPhaseFromGesture = force_cast<mFGetPhaseFromGesture>(RVA_ScriptGame(0xBD30));

    return s_fGetPhaseFromGesture(a_Speaker, a_strGesture);
}

static bTObjArray<Entity> * g_arrFoundFreepointsByUseType = reinterpret_cast<bTObjArray<Entity> *>(RVA_ScriptGame(0x118ACC));
bTObjArray<Entity> & FindInteractObjects(Entity const & a_Entity)
{
    typedef void ( GE_STDCALL *mFFindInteractObjects )( Entity );
    static mFFindInteractObjects s_fFindInteractObjects = force_cast<mFFindInteractObjects>(RVA_ScriptGame(0x7C90));

    s_fFindInteractObjects(a_Entity);
    return *g_arrFoundFreepointsByUseType;
}

Entity FindInteractObjectWithUseType(Entity const & a_Entity, gEUseType a_enuUseType)
{
    return FindInteractObjects(a_Entity)[a_enuUseType];
}

static bTObjArray<Entity> * g_arrFoundFreepointsRefined = reinterpret_cast<bTObjArray<Entity> *>(RVA_ScriptGame(0x118AD8));
void RefineFoundFreepoints(gEUseType a_enuUseType)
{
    if(g_arrFoundFreepointsByUseType->GetAt(a_enuUseType) != None)
        g_arrFoundFreepointsRefined->Add(g_arrFoundFreepointsByUseType->GetAt(a_enuUseType));
}

Entity GetFirstFoundRefinedFreepoint()
{
    for(GEInt i = 0; i < g_arrFoundFreepointsRefined->GetCount(); i++)
    {
        if(g_arrFoundFreepointsRefined->GetAt(i) != None)
            return g_arrFoundFreepointsRefined->GetAt(i);
    }

    return None;
}

Entity GetRandomFoundRefinedFreepoint()
{
    if(g_arrFoundFreepointsRefined->GetCount() <= 0)
        return None;

    return g_arrFoundFreepointsRefined->GetAt(Entity::GetRandomNumber(g_arrFoundFreepointsRefined->GetCount()));
}

GEU32 GetItemQuality(bCString const & a_ItemName) {
    eCSceneAdmin * pSceneAdmin = FindModule<eCSceneAdmin>();
    if(!pSceneAdmin)
        return 0;

    gCItem_PS const * pItem = GetPropertySet<gCItem_PS>(pSceneAdmin->GetTemplateEntityByName(a_ItemName), eEPropertySetType_Item);
    return pItem ? pItem->GetQuality() : 0;
}

