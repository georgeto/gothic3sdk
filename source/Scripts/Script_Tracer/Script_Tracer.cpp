#include "Script_Tracer.h"

#include "util/Memory.h"
#include "util/Logging.h"
#include "util/Hook.h"
#include "util/Util.h"
#include "util/ScriptUtil.h"

#include "Script.h"

gSScriptInit & GetScriptInit()
{
    static gSScriptInit s_ScriptInit;
    return s_ScriptInit;
}

class mCHookContext
{
    public:
        template< typename T >
        T GetOriginalFunction( void ) const
        {
            GE_ASSERT_SIZEOF(T, sizeof(GELPVoid));
            return reinterpret_cast< T >(GetUntypedOriginalFunction());
        }

    private:
        virtual GELPVoid GetUntypedOriginalFunction( void ) const = 0;

    public:
        bCString m_strFuncName;
};

class mCFunctionHookContext : public mCHookContext
{
    private:
        virtual GELPVoid GetUntypedOriginalFunction( void ) const
        {
            return m_Hook.GetOriginalFunction<GELPVoid>();
        }

    public:
        mCFunctionHook m_Hook;
};

class mCFunctionPointerHookContext : public mCHookContext
{
    private:
        virtual GELPVoid GetUntypedOriginalFunction( void ) const
        {
            return m_OriginalFunc;
        }

    public:
        GELPVoid m_OriginalFunc;
};

class mCPropertySetHookContext : public mCFunctionHookContext
{
    private:
        virtual GELPVoid GetUntypedOriginalFunction( void ) const
        {
            return m_Hook.GetOriginalFunction<GELPVoid>();
        }

    public:
        GELPCChar m_strPropertySet;
        mEPropertySetOffset m_Offset;
};

class mCSetterHookContext : public mCPropertySetHookContext
{
    private:
        virtual GELPVoid GetUntypedOriginalFunction( void ) const
        {
            return m_Hook.GetOriginalFunction<GELPVoid>();
        }

    public:
        GELPCChar m_strFormat;
};

GELPVoid CreateHookTrampoline(GELPVoid a_pTarget, mCHookContext * a_pContext)
{
    USE_X86_ASSEMBLER_N(Asm, a_pContext->m_strFuncName.GetText());

    // Save eax
    Asm.mov(dword_ptr(esp, -8), eax);

    // Move return address to make space for context arg
    Asm.mov(eax, dword_ptr(esp));
    Asm.push(eax);

    // Insert context arg
    Asm.mov(dword_ptr(esp, 4), imm_ptr(a_pContext));

    // Restore eax
    Asm.mov(eax, dword_ptr(esp, -4));

    // Jump to target
    Asm.jmp(imm_ptr(a_pTarget));

    return JitRuntimeAdd(Asm);
}

mCFileLogger * g_Logger;

GEBool IsTracingEnabled(Entity const & a_Entity)
{
    return GETrue;
}

GEInt GE_STDCALL TraceScript( mCHookContext const & a_Context, gCScriptProcessingUnit* a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iArgs )
{
    INIT_SCRIPT();
    GEBool bEnabled = IsTracingEnabled(SelfEntity);
    if(bEnabled)
    {
        g_Logger->LogFormatPrefix("[%s]", " -> [Script] %s(SPU=%p, SelfEntity=%s, OtherEntity=%s, Args=%d)\n", GetSystemTimeString().GetText(), a_Context.m_strFuncName.GetText(), a_pSPU, SelfEntity.GetName().GetText(), OtherEntity.GetName().GetText(), a_iArgs);
        g_Logger->PushIndent();
    }
    GEInt Result = a_Context.GetOriginalFunction<gFScript>()(a_pSPU, a_pSelfEntity, a_pOtherEntity, a_iArgs);
    if(bEnabled)
    {
        g_Logger->PopIndent();
        g_Logger->LogFormatPrefix("[%s]", " <- [Script] %s: %d\n", GetSystemTimeString().GetText(), a_Context.m_strFuncName, Result);
    }
    return Result;
}

GEBool GE_STDCALL TraceScriptAIRoutine( mCHookContext const & a_Context, gCScriptProcessingUnit* a_pSPU )
{
    Entity SelfEntity(a_pSPU->GetSelfEntity());
    GEBool bEnabled = IsTracingEnabled(SelfEntity);
    if(bEnabled)
    {
        g_Logger->LogFormatPrefix("[%s]", " -> [Routine] %s(SPU=%p, SelfEntity=%s, TargetEntity=%s)\n", GetSystemTimeString().GetText(), a_Context.m_strFuncName.GetText(), a_pSPU, SelfEntity.GetName().GetText(), Entity( a_pSPU->GetTargetEntity()).GetName().GetText());
        g_Logger->PushIndent();
    }
    GEBool bResult = a_Context.GetOriginalFunction<gFScriptAIRoutine>()(a_pSPU);
    if(bEnabled)
    {
        g_Logger->PopIndent();
        g_Logger->LogFormatPrefix("[%s]", " <- [Routine] %s: %s\n", GetSystemTimeString().GetText(), a_Context.m_strFuncName, BoolToString(bResult));
    }
    return bResult;
}

GEBool GE_STDCALL TraceScriptAICallback( mCHookContext const & a_Context, gCScriptProcessingUnit* a_pSPU )
{
    Entity SelfEntity(a_pSPU->GetSelfEntity());
    GEBool bEnabled = IsTracingEnabled(SelfEntity);
    if(bEnabled)
    {
        g_Logger->LogFormatPrefix("[%s]", " -> [Callback] %s(SPU=%p, SelfEntity=%s, TargetEntity=%s)\n", GetSystemTimeString().GetText(), a_Context.m_strFuncName.GetText(), a_pSPU, SelfEntity.GetName().GetText(), Entity( a_pSPU->GetTargetEntity()).GetName().GetText());
        g_Logger->PushIndent();
    }
    GEBool bResult = a_Context.GetOriginalFunction<gFScriptAICallback>()(a_pSPU);
    if(bEnabled)
    {
        g_Logger->PopIndent();
        g_Logger->LogFormatPrefix("[%s]", " <- [Callback] %s: %s\n", GetSystemTimeString().GetText(), a_Context.m_strFuncName, BoolToString(bResult));
    }
    return bResult;
}

GEBool GE_STDCALL TraceScriptAIFunction( mCHookContext const & a_Context, bTObjStack<gScriptRunTimeSingleState> & a_rRunTimeStack, gCScriptProcessingUnit* a_pSPU )
{
    Entity SelfEntity(a_pSPU->GetSelfEntity());
    GEBool bEnabled = IsTracingEnabled(SelfEntity);
    if(bEnabled)
    {
        g_Logger->LogFormatPrefix("[%s]", " -> [Function] %s(SPU=%p, SelfEntity=%s, TargetEntity=%s)\n", GetSystemTimeString().GetText(), a_Context.m_strFuncName.GetText(), a_pSPU, SelfEntity.GetName().GetText(), Entity( a_pSPU->GetTargetEntity()).GetName().GetText());
        g_Logger->PushIndent();
    }
    GEBool bResult = a_Context.GetOriginalFunction<gFScriptAIFunction>()(a_rRunTimeStack, a_pSPU);
    if(bEnabled)
    {
        g_Logger->PopIndent();
        g_Logger->LogFormatPrefix("[%s]", " <- [Function] %s: %s\n", GetSystemTimeString().GetText(), a_Context.m_strFuncName, BoolToString(bResult));
    }
    return bResult;
}

GEBool GE_STDCALL TraceScriptAIState( mCHookContext const & a_Context, bTObjStack<gScriptRunTimeSingleState> & a_rRunTimeStack, gCScriptProcessingUnit* a_pSPU )
{
    Entity SelfEntity(a_pSPU->GetSelfEntity());
    GEBool bEnabled = IsTracingEnabled(SelfEntity);
    if(bEnabled)
    {
        g_Logger->LogFormatPrefix("[%s]", " -> [State] %s(SPU=%p, SelfEntity=%s, TargetEntity=%s)\n", GetSystemTimeString().GetText(), a_Context.m_strFuncName.GetText(), a_pSPU, SelfEntity.GetName().GetText(), Entity( a_pSPU->GetTargetEntity()).GetName().GetText());
        g_Logger->PushIndent();
    }
    GEBool bResult = a_Context.GetOriginalFunction<gFScriptAIState>()(a_rRunTimeStack, a_pSPU);
    if(bEnabled)
    {
        g_Logger->PopIndent();
        g_Logger->LogFormatPrefix("[%s]", " <- [State] %s: %s\n", GetSystemTimeString().GetText(), a_Context.m_strFuncName, BoolToString(bResult));
    }
    return bResult;
}

void GE_STDCALL TracePropertySetVoid( mCPropertySetHookContext const & a_Context )
{
    EntityPropertySet const * pPropertySet = a_Context.m_Hook.GetSelf<EntityPropertySet const *>();
    Entity SelfEntity(*GetEntity(pPropertySet, a_Context.m_Offset));
    GEBool bEnabled = IsTracingEnabled(SelfEntity);
    if(bEnabled)
    {
        g_Logger->LogFormatPrefix("[%s]", " -> [%s] %s(SelfEntity=%s)\n", GetSystemTimeString().GetText(), a_Context.m_strPropertySet, a_Context.m_strFuncName.GetText(), SelfEntity.GetName().GetText());
        g_Logger->PushIndent();
    }
    a_Context.GetOriginalFunction<void (*)()>()();
    if(bEnabled)
    {
        g_Logger->PopIndent();
        g_Logger->LogFormatPrefix("[%s]", " <- [%s] %s\n", GetSystemTimeString().GetText(), a_Context.m_strPropertySet, a_Context.m_strFuncName);
    }
}

template<typename V>
void GE_STDCALL TracePropertySetSetter( mCSetterHookContext const & a_Context, V a_Value )
{
    EntityPropertySet const * pPropertySet = a_Context.m_Hook.GetSelf<EntityPropertySet const *>();
    Entity SelfEntity(*GetEntity(pPropertySet, a_Context.m_Offset));
    GEBool bEnabled = IsTracingEnabled(SelfEntity);
    if(bEnabled)
    {
        g_Logger->LogFormatPrefix("[%s]", " -> [%s] %s(SelfEntity=%s, Value=" + bCString(a_Context.m_strFormat) + ")\n", GetSystemTimeString().GetText(), a_Context.m_strPropertySet, a_Context.m_strFuncName.GetText(), SelfEntity.GetName().GetText(), a_Value);
        g_Logger->PushIndent();
    }
    a_Context.GetOriginalFunction<void (*)(V)>()(a_Value);
    if(bEnabled)
    {
        g_Logger->PopIndent();
        g_Logger->LogFormatPrefix("[%s]", " <- [%s] %s\n", GetSystemTimeString().GetText(), a_Context.m_strPropertySet, a_Context.m_strFuncName);
    }
}

#define INSTRUMENT_SCRIPTS(SCRIPT_TYPE) \
    GetDefaultLogger().LogString("Instrumenting " ## #SCRIPT_TYPE ## "s...\n"); \
    GE_MAP_FOR_EACH_VP(ScriptItem, pScript, GetScriptAdminExt().Get ## SCRIPT_TYPE ## s()) \
    { \
        mCFunctionHookContext * pHookContext = GE_NEW(mCFunctionHookContext); \
        pHookContext->m_strFuncName = pScript->m_strName; \
        GELPVoid pTrampoline = CreateHookTrampoline(Trace ## SCRIPT_TYPE, pHookContext); \
        pHookContext->m_Hook.Hook(pScript->m_func ## SCRIPT_TYPE, pTrampoline); \
    } \
    GetDefaultLogger().LogFormat("%d " ## #SCRIPT_TYPE ## "s instrumented...\n", GetScriptAdminExt().Get ## SCRIPT_TYPE ## s().GetCount());

#define INSTRUMENT_SCRIPTS_FUNC_PTR(SCRIPT_TYPE) \
    GetDefaultLogger().LogString("Instrumenting " ## #SCRIPT_TYPE ## "s...\n"); \
    GE_MAP_FOR_EACH_VP(ScriptItem, pScript, GetScriptAdminExt().Get ## SCRIPT_TYPE ## s()) \
    { \
        mCFunctionPointerHookContext * pHookContext = GE_NEW(mCFunctionPointerHookContext); \
        pHookContext->m_strFuncName = pScript->m_strName; \
        GELPVoid pTrampoline = CreateHookTrampoline(Trace ## SCRIPT_TYPE, pHookContext); \
        pHookContext->m_OriginalFunc = pScript->m_func ## SCRIPT_TYPE; \
        pScript->m_func ## SCRIPT_TYPE = static_cast<gF ## SCRIPT_TYPE>(pTrampoline); \
    } \
    GetDefaultLogger().LogFormat("%d " ## #SCRIPT_TYPE ## "s instrumented...\n", GetScriptAdminExt().Get ## SCRIPT_TYPE ## s().GetCount());

#define INSTRUMENT_PROPERTY_VOID(PROPERTY_SET, FUNC) \
    { \
        GetDefaultLogger().LogString("Instrumenting PS" ## #PROPERTY_SET ## "::" ## #FUNC ## "...\n"); \
        mCPropertySetHookContext * pHookContext = GE_NEW(mCPropertySetHookContext); \
        pHookContext->m_strFuncName = #FUNC; \
        pHookContext->m_strPropertySet = "PS" ## #PROPERTY_SET; \
        pHookContext->m_Offset = mEPropertySetOffset_ ## PROPERTY_SET; \
        GELPVoid pTrampoline = CreateHookTrampoline(&TracePropertySetVoid, pHookContext); \
        pHookContext->m_Hook.Hook(&PS ## PROPERTY_SET ## :: ## FUNC, pTrampoline, mCBaseHook::mEHookType_ThisCall); \
    }

#define INSTRUMENT_PROPERTY_SETTER(PROPERTY_SET, FUNC, FORMAT, VALUE_TYPE) \
    { \
        GetDefaultLogger().LogString("Instrumenting PS" ## #PROPERTY_SET ## "::" ## #FUNC ## "...\n"); \
        mCSetterHookContext * pHookContext = GE_NEW(mCSetterHookContext); \
        pHookContext->m_strFuncName = "PS" ## #PROPERTY_SET ## "::" ## #FUNC; \
        pHookContext->m_strPropertySet = "PS" ## #PROPERTY_SET; \
        pHookContext->m_Offset = mEPropertySetOffset_ ## PROPERTY_SET; \
        pHookContext->m_strFormat = FORMAT; \
        GELPVoid pTrampoline = CreateHookTrampoline(force_cast<GELPVoid>(&TracePropertySetSetter<VALUE_TYPE>), pHookContext); \
        pHookContext->m_Hook.Hook(&PS ## PROPERTY_SET ## :: ## FUNC, pTrampoline, mCBaseHook::mEHookType_ThisCall); \
    }

void EnableTracing()
{
    g_Logger = &mCFileLogger::GetInstance("Trace");

    GetDefaultLogger().LogString("Instrumenting Scripts...\n");

    INSTRUMENT_SCRIPTS(Script);
    INSTRUMENT_SCRIPTS_FUNC_PTR(ScriptAIRoutine);
    INSTRUMENT_SCRIPTS_FUNC_PTR(ScriptAICallback);
    INSTRUMENT_SCRIPTS_FUNC_PTR(ScriptAIFunction);
    INSTRUMENT_SCRIPTS_FUNC_PTR(ScriptAIState);

    INSTRUMENT_PROPERTY_VOID(Routine, ContinueRoutine);
    INSTRUMENT_PROPERTY_VOID(Routine, FullStop);
    INSTRUMENT_PROPERTY_VOID(Routine, StopAICombatMove);
    INSTRUMENT_PROPERTY_VOID(Routine, StopAIGoto);
    INSTRUMENT_PROPERTY_VOID(Routine, StopAIOutput);
    INSTRUMENT_PROPERTY_VOID(Routine, StopAIPlayAnimation);
    INSTRUMENT_PROPERTY_VOID(Routine, StopAIWait);
    INSTRUMENT_PROPERTY_SETTER(Routine, SetLocalCallback, "%s", bCString);
    INSTRUMENT_PROPERTY_SETTER(Routine, SetState, "%s", bCString);
    INSTRUMENT_PROPERTY_SETTER(Routine, SetStateTime, "%f", GEFloat);
    INSTRUMENT_PROPERTY_SETTER(Routine, SetTask, "%s", bCString);
    INSTRUMENT_PROPERTY_SETTER(Routine, SetTaskCallback, "%s", bCString);
    INSTRUMENT_PROPERTY_SETTER(Routine, SetTaskTime, "%f", GEFloat);
    INSTRUMENT_PROPERTY_SETTER(Routine, SetTimeScale, "%f", GEFloat);
    INSTRUMENT_PROPERTY_SETTER(Routine, StartOutput, "%s", bCString);
}

extern "C" __declspec( dllexport )
gSScriptInit const * GE_STDCALL ScriptInit( void )
{
    // Ensure that that Script_Game.dll is loaded.
    GetScriptAdmin().LoadScriptDLL("Script_Mod.dll");

    // Initialize logging
    CreateDirectory("logs", NULL);

    mCFileLogger & Logger = mCFileLogger::GetInstance("Script_Tracer");
    SetDefaultLogger(Logger);
    InitAsmjitLogger(Logger.GetFile());

    EnableTracing();

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