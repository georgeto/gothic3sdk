#include "Common.h"

#include "console/m_commandhandler.h"

namespace
{
    bCCriticalSectionWin32 * g_PrefetcherHierarchyLock;
    bTSmallArray<eCEntity *> g_arrEntitiesToCollect;
    bTPtrArray<eCEntity *> g_arrPinnedEntities;
    GEBool g_bPinNavigationEntities = GEFalse;

    GEBool g_bEnableLogOnce = GEFalse;
    GELPCChar const g_strLogFile = "logs\\DummyCollector.log";

    bCString EnableLogOnce( bTObjArray< bCString > a_arrParams )
    {
        g_bEnableLogOnce = GETrue;
        return "Enabled Logging for next execution.";
    }

    bCString PinEntity( bTObjArray< bCString > a_arrParams )
    {
        if (a_arrParams[0].CompareNoCaseFast("Navigation"))
        {
            g_bPinNavigationEntities = GETrue;
            return "Pinned all navigation entities.";
        }

        eCSceneAdmin & s_SceneAdmin = *FindModule<eCSceneAdmin>();
        eCEntity * pEntity = dynamic_cast<eCEntity *>(s_SceneAdmin.GetEntity(bCPropertyID(bCGuid(a_arrParams[0])), eEGetEntityTypeHint_Entity));
        if(!pEntity)
            return "$Unable to find entity specified entity.";

        if(g_arrPinnedEntities.IndexOf(pEntity) != -1)
            return "Entity was already pinned.";

        g_arrPinnedEntities.Add(pEntity);

        return "Pinned entity.";
    }

    bCString UnpinEntity( bTObjArray< bCString > a_arrParams )
    {
        if (a_arrParams[0].CompareNoCaseFast("Navigation"))
        {
            g_bPinNavigationEntities = GEFalse;
            return "Unpinned all navigation entities.";
        }

        eCSceneAdmin & s_SceneAdmin = *FindModule<eCSceneAdmin>();
        eCEntity * pEntity = dynamic_cast<eCEntity *>(s_SceneAdmin.GetEntity(bCPropertyID(bCGuid(a_arrParams[0])), eEGetEntityTypeHint_Entity));
        if(!pEntity)
            return "$Unable to find entity specified entity.";

        if(g_arrPinnedEntities.IndexOf(pEntity) == -1)
            return "Entity was not pinned.";

        g_arrPinnedEntities.Remove(pEntity);

        return "Unpinned entity.";
    }

    void LogProcessingRangeRegions(eCSceneAdmin & a_SceneAdmin)
    {
        mCFileLogger & Logger = mCLoggingAdmin<mCFileLogger>::GetLogger(g_strLogFile);
        GELPChar pEntityAdmin = reinterpret_cast<GELPChar>(&a_SceneAdmin.GetAccessToEntityAdmin());

        Logger.LogFormat("ProcessingRangeRegion: %s\n", BoxToString(*reinterpret_cast<bCBox*>(pEntityAdmin + 0x64)));
        Logger.LogFormat("OldProcessingRangeRegion: %s\n", BoxToString(*reinterpret_cast<bCBox*>(pEntityAdmin + 0x7C)));
        Logger.LogFormat("StaticProcessingRangeRegion: %s\n", BoxToString(*reinterpret_cast<bCBox*>(pEntityAdmin + 0x94)));
    }

    void LogStaticEntity(eCSceneAdmin & a_SceneAdmin, eCEntity const & a_Entity)
    {
        mCFileLogger & Logger = mCLoggingAdmin<mCFileLogger>::GetLogger(g_strLogFile);
        Logger.LogFormat("%s | %s | %s | %s\n", a_Entity.GetName(), a_Entity.GetID().GetText(), VectorToString(a_Entity.GetWorldPosition(), GEFalse), BoxToString(a_Entity.GetWorldNodeBoundary()));

        GEBool bIntersectsProcessingRangeRegion = a_SceneAdmin.GetAccessToEntityAdmin().IntersectsProcessingRangeRegion(a_Entity.GetWorldNodeBoundary());
        Logger.LogFormat("IntersectsProcessingRange: %d | WorldNodeBoundaryValid: %d | CachedIn: %d\n", bIntersectsProcessingRangeRegion, a_Entity.GetEntityFlags().m_WorldNodeBoundaryValid, a_Entity.GetEntityFlags().m_CachedIn);
    }

    void LogDynamicEntity(eCSceneAdmin & a_SceneAdmin, eCEntity const & a_Entity)
    {
        LogStaticEntity(a_SceneAdmin, a_Entity);
        mCFileLogger & Logger = mCLoggingAdmin<mCFileLogger>::GetLogger(g_strLogFile);
        Logger.LogFormat("Enabled: %d | Killed: %d | DeactivationEnabled: %d\n", a_Entity.GetEntityFlags().m_Enabled, a_Entity.GetEntityFlags().m_Killed, a_Entity.GetEntityFlags().m_DeactivationEnabled);
    }

    GEBool InProcessingRange(eCSceneAdmin &a_SceneAdmin, eCEntity const &a_Entity) {
        GEBool bPinnedNavigation = g_bPinNavigationEntities &&
            (  a_Entity.HasPropertySet(eEPropertySetType_NavZone)
            || a_Entity.HasPropertySet(eEPropertySetType_NavPath)
            || a_Entity.HasPropertySet(eEPropertySetType_NegZone)
            || a_Entity.HasPropertySet(eEPropertySetType_PrefPath));

        return bPinnedNavigation || a_SceneAdmin.GetAccessToEntityAdmin().IntersectsProcessingRangeRegion(a_Entity.GetWorldNodeBoundary());
    }

    GEBool CheckStaticEntity(eCSceneAdmin & a_SceneAdmin, eCEntity const & a_Entity) {
        return InProcessingRange(a_SceneAdmin, a_Entity)
            && a_Entity.GetEntityFlags().m_WorldNodeBoundaryValid
            && a_Entity.GetEntityFlags().m_CachedIn;
            //&& pEntity->GetEntityFlags().m_ProcessingRangeEntered;
    }

    GEBool CheckDynamicEntity(eCSceneAdmin & a_SceneAdmin, eCEntity const & a_Entity) {
        return a_Entity.GetEntityFlags().m_WorldNodeBoundaryValid
            && a_Entity.GetEntityFlags().m_CachedIn
            && a_Entity.GetEntityFlags().m_Enabled
            && !a_Entity.GetEntityFlags().m_Killed
            && (!a_Entity.GetEntityFlags().m_DeactivationEnabled
            || InProcessingRange(a_SceneAdmin, a_Entity));
            //&& pEntity->GetEntityFlags().m_ProcessingRangeEntered;
    }

    mCFunctionHook Hook_CollectProcessingRange;
    void GE_STDCALL CollectProcessingRange( void )
    {
        eCSceneAdmin & SceneAdmin = *FindModule<eCSceneAdmin>();

        bTSmallArray<eCPVSCellItem *> arrCellItems;
        FindModule<eCRenderSystemAdmin>()->GetPVSPrefetcher3().GetAllValidCells(arrCellItems);

        g_arrEntitiesToCollect.Clear();

        if(g_bEnableLogOnce)
            LogProcessingRangeRegions(SceneAdmin);

        for(GEU16 i = 0; i < arrCellItems.GetCount(); i++)
        {
            g_PrefetcherHierarchyLock->Acquire();

            { // Dynamic Entities
                arrCellItems[i]->GetDynamicEntities();
                bTSmallArray<eCDynamicEntity *> const & arrEntities = arrCellItems[i]->GetDynamicEntities();
                for(GEU16 iEntity = 0; iEntity < arrEntities.GetCount(); iEntity++)
                {
                    if(CheckDynamicEntity(SceneAdmin, *arrEntities[iEntity]))
                        g_arrEntitiesToCollect.Add(arrEntities[iEntity]);

                    if(g_bEnableLogOnce)
                        LogDynamicEntity(SceneAdmin, *arrEntities[iEntity]);
                }
            }

            { // Static Entities
                arrCellItems[i]->GetDynamicEntities();
                bTSmallArray<eCSpatialEntity *> const & arrEntities = arrCellItems[i]->GetStaticEntities();
                for(GEU16 iEntity = 0; iEntity < arrEntities.GetCount(); iEntity++)
                {
                    if(CheckStaticEntity(SceneAdmin, *arrEntities[iEntity]))
                        g_arrEntitiesToCollect.Add(arrEntities[iEntity]);

                    if(g_bEnableLogOnce)
                        LogStaticEntity(SceneAdmin, *arrEntities[iEntity]);
                }
            }

            for(GEU16 iEntity = 0; iEntity < g_arrPinnedEntities.GetCount(); iEntity++)
                g_arrEntitiesToCollect.Add(g_arrPinnedEntities[iEntity]);

            g_PrefetcherHierarchyLock->Release();
        }

        if(g_bEnableLogOnce)
        {
            mCLoggingAdmin<mCFileLogger>::GetLogger(g_strLogFile).LogString("---- ---- ---- ----\n\n");
            g_bEnableLogOnce = GEFalse;
        }

        // Originale Funktion aufrufen
        Hook_CollectProcessingRange.GetOriginalFunction(&CollectProcessingRange)();
    }

    mCCallHook Hook_GetEntitiesInProcessingRange;
    bTSmallArray<eCEntity *> const & GE_STDCALL GetEntitiesInProcessingRange()
    {
        return g_arrEntitiesToCollect;
    }

    void GE_STDCALL SetObjectCullFactor(GEFloat)
    {
        mCCallHook::GetLastSelf<eCEntity *>()->SetObjectCullFactor(1.0f);
    }

    void GE_STDCALL SetProcessingRangeOutFadingEnabled(GEBool)
    {
        mCCallHook::GetLastSelf<eCEntity *>()->SetProcessingRangeOutFadingEnabled(GEFalse);
    }
}

ME_MODULE_DEPENDS(DummyCollector, {"CommandHandler"})
{
    g_PrefetcherHierarchyLock = reinterpret_cast<bCCriticalSectionWin32 *>(RVA_Engine(0x609DF4));

    Hook_CollectProcessingRange.Hook(PROC_Game("?CollectProcessingRange@gCDummyCollectorAdmin@@IAEXXZ"), &CollectProcessingRange, mCBaseHook::mEHookType_ThisCall);
    Hook_GetEntitiesInProcessingRange.Hook(RVA_Game(0x3F664), &GetEntitiesInProcessingRange, mCBaseHook::mEHookType_ThisCall);

    mCCommandHandler & CommandHandler = mCCommandHandler::GetInstance();
    CommandHandler.RegisterCommand( "DummyCollector", "Commands to deal with the new dummy collector." );

    mCCommandHandler::mSSubCommandDesc Desc;

    Desc.m_strName = "Log";
    Desc.m_iMinArgs = 0;
    Desc.m_iMaxArgs = 0;
    Desc.m_strHelpText = "Enables logging for the next execution of the dummy collector.";
    Desc.m_pfuncExecute = &EnableLogOnce;
    Desc.m_pfuncAutoComplete = 0;
    CommandHandler.RegisterSubCommand( "DummyCollector", Desc );

    Desc.m_strName = "Pin";
    Desc.m_iMinArgs = 1;
    Desc.m_iMaxArgs = 1;
    Desc.m_strHelpText = "Force collection of specified Entity.\n" \
        "Usage:\n" \
        "  DummyCollector Pin <Guid>\n" \
        "  DummyCollector Pin Navigation";
    Desc.m_pfuncExecute = &PinEntity;
    Desc.m_pfuncAutoComplete = 0;
    CommandHandler.RegisterSubCommand( "DummyCollector", Desc );

    Desc.m_strName = "Unpin";
    Desc.m_iMinArgs = 1;
    Desc.m_iMaxArgs = 1;
    Desc.m_strHelpText = "Undo force collection of specified Entity.\n" \
        "Usage:\n" \
        "  DummyCollector Unpin <Guid>\n" \
        "  DummyCollector Unpin Navigation";
    Desc.m_pfuncExecute = &UnpinEntity;
    Desc.m_pfuncAutoComplete = 0;
    CommandHandler.RegisterSubCommand( "DummyCollector", Desc );

    // ObjectCullFactor
    // Default: 50.0f
    static mCCallHook Hook_OCF_NavZone_1(RVA_Game(0x498E1), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);
    static mCCallHook Hook_OCF_NavZone_2(RVA_Game(0x49DEA), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);
    static mCCallHook Hook_OCF_NavZone_3(RVA_Game(0x4A119), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);

    static mCCallHook Hook_OCF_NavPath_1(RVA_Game(0x4815B), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);
    static mCCallHook Hook_OCF_NavPath_2(RVA_Game(0x48519), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);
    static mCCallHook Hook_OCF_NavPath_3(RVA_Game(0x488B6), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);

    static mCCallHook Hook_OCF_NegZone_1(RVA_Game(0x4AE9B), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);
    static mCCallHook Hook_OCF_NegZone_2(RVA_Game(0x4B56B), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);

    static mCCallHook Hook_OCF_PrefPath(RVA_Game(0x4C89A), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);

    /*static mCCallHook Hook_OCF_Anchor(RVA_Game(0x43450), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);

    // 60.0f
    static mCCallHook Hook_OCF_Entity(RVA_Game(0x4201C), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);

    // 110.0f
    static mCCallHook Hook_OCF_CollisionCircle_1(RVA_Game(0x43DA8), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);
    static mCCallHook Hook_OCF_CollisionCircle_2(RVA_Game(0x4424F), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);

    static mCCallHook Hook_OCF_CollisionShape(RVA_Game(0x45B0A), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);

    // 110.0f
    static mCCallHook Hook_OCF_DynamicCollisionCircle(RVA_Game(0x462BE), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);

    static mCCallHook Hook_OCF_Freepoint_1(RVA_Game(0x46881), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);
    static mCCallHook Hook_OCF_Freepoint_2(RVA_Game(0x46AF1), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);

    static mCCallHook Hook_OCF_NavOffset_1(RVA_Game(0x474AC), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);
    static mCCallHook Hook_OCF_NavOffset_2(RVA_Game(0x4782B), &SetObjectCullFactor, mCBaseHook::mEHookType_ThisCall);*/


    // ProcessingRangeOutFading
    // Default: GETrue
    static mCCallHook Hook_PROFE_NavZone_1(RVA_Game(0x498EB), &SetProcessingRangeOutFadingEnabled, mCBaseHook::mEHookType_ThisCall);
    static mCCallHook Hook_PROFE_NavZone_2(RVA_Game(0x49DF4), &SetProcessingRangeOutFadingEnabled, mCBaseHook::mEHookType_ThisCall);
    static mCCallHook Hook_PROFE_NavZone_3(RVA_Game(0x4A12C), &SetProcessingRangeOutFadingEnabled, mCBaseHook::mEHookType_ThisCall);

    static mCCallHook Hook_PROFE_NavPath_1(RVA_Game(0x4816E), &SetProcessingRangeOutFadingEnabled, mCBaseHook::mEHookType_ThisCall);
    static mCCallHook Hook_PROFE_NavPath_2(RVA_Game(0x48523), &SetProcessingRangeOutFadingEnabled, mCBaseHook::mEHookType_ThisCall);
    static mCCallHook Hook_PROFE_NavPath_3(RVA_Game(0x488C9), &SetProcessingRangeOutFadingEnabled, mCBaseHook::mEHookType_ThisCall);

    static mCCallHook Hook_PROFE_NegZone_1(RVA_Game(0x4AEAE), &SetProcessingRangeOutFadingEnabled, mCBaseHook::mEHookType_ThisCall);
    static mCCallHook Hook_PROFE_NegZone_2(RVA_Game(0x4B57E), &SetProcessingRangeOutFadingEnabled, mCBaseHook::mEHookType_ThisCall);

    static mCCallHook Hook_PROFE_PrefPath(RVA_Game(0x4C8AD), &SetProcessingRangeOutFadingEnabled, mCBaseHook::mEHookType_ThisCall);

    /*static mCCallHook Hook_PROFE_Anchor(RVA_Game(0x43463), &SetProcessingRangeOutFadingEnabled, mCBaseHook::mEHookType_ThisCall);

    static mCCallHook Hook_PROFE_CollisionCircle_1(RVA_Game(0x43DBB), &SetProcessingRangeOutFadingEnabled, mCBaseHook::mEHookType_ThisCall);
    static mCCallHook Hook_PROFE_CollisionCircle_2(RVA_Game(0x44262), &SetProcessingRangeOutFadingEnabled, mCBaseHook::mEHookType_ThisCall);

    static mCCallHook Hook_PROFE_CollisionShape(RVA_Game(0x45B1D), &SetProcessingRangeOutFadingEnabled, mCBaseHook::mEHookType_ThisCall);

    static mCCallHook Hook_PROFE_DynamicCollisionCircle(RVA_Game(0x462D1), &SetProcessingRangeOutFadingEnabled, mCBaseHook::mEHookType_ThisCall);

    static mCCallHook Hook_PROFE_Freepoint(RVA_Game(0x46894), &SetProcessingRangeOutFadingEnabled, mCBaseHook::mEHookType_ThisCall);

    static mCCallHook Hook_PROFE_NavOffset_1(RVA_Game(0x474BF), &SetProcessingRangeOutFadingEnabled, mCBaseHook::mEHookType_ThisCall);
    static mCCallHook Hook_PROFE_NavOffset_2(RVA_Game(0x4783E), &SetProcessingRangeOutFadingEnabled, mCBaseHook::mEHookType_ThisCall);*/
}
