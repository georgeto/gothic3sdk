#pragma once

#include <Engine.h>

class gCScriptProcessingUnit;
struct gScriptRunTimeSingleState;

using gFScript = GEInt(GE_STDCALL *)(gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt);
using gFScriptAIRoutine = GEBool(GE_STDCALL *)(gCScriptProcessingUnit *);
using gFScriptAICallback = GEBool(GE_STDCALL *)(gCScriptProcessingUnit *);
using gFScriptAIFunction = GEBool(GE_STDCALL *)(bTObjStack<gScriptRunTimeSingleState> &, gCScriptProcessingUnit *);
using gFScriptAIState = GEBool(GE_STDCALL *)(bTObjStack<gScriptRunTimeSingleState> &, gCScriptProcessingUnit *);

struct gSScript
{
    bCString m_strName;
    gFScript m_funcScript;
    bCString m_strSource;

    gSScript(GELPCChar a_pcName, GELPCChar a_pcSource, gFScript a_funcScript);
    gSScript();

    GEBool operator==(gSScript const &script) const
    {
        return this->m_strName == script.m_strName;
    };
};

struct gSScriptAIRoutine
{
    bCString m_strName;
    gFScriptAIRoutine m_funcScriptAIRoutine;
    bCString m_strSource;

    gSScriptAIRoutine(GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAIRoutine a_funcScriptAIState);
    gSScriptAIRoutine();

    GEBool operator==(gSScriptAIRoutine const &routine) const
    {
        return this->m_strName == routine.m_strName;
    };
};

struct gSScriptAICallback
{
    bCString m_strName;
    gFScriptAICallback m_funcScriptAICallback;
    bCString m_strSource;

    gSScriptAICallback(GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAICallback a_funcScriptAICallback);
    gSScriptAICallback();

    GEBool operator==(gSScriptAICallback const &callback) const
    {
        return this->m_strName == callback.m_strName;
    };
};

struct gSScriptAIFunction
{
    bCString m_strName;
    gFScriptAIFunction m_funcScriptAIFunction;
    bCString m_strSource;

    gSScriptAIFunction(GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAIFunction a_funcScriptAIFunction);
    gSScriptAIFunction();

    GEBool operator==(gSScriptAIFunction const &function) const
    {
        return this->m_strName == function.m_strName;
    };
};

struct gSScriptAIState
{
    bCString m_strName;
    gFScriptAIState m_funcScriptAIState;
    bCString m_strSource;

    gSScriptAIState(GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAIState a_funcScriptAIState);
    gSScriptAIState();

    GEBool operator==(gSScriptAIState const &state) const
    {
        return this->m_strName == state.m_strName;
    };
};

struct gSScriptInit
{
    bTObjArray<gSScriptAIState> m_arrScriptAIStates;
    bTObjArray<gSScriptAIFunction> m_arrScriptAIFunctions;
    bTObjArray<gSScriptAICallback> m_arrScriptAICallbacks;
    bTObjArray<gSScriptAIRoutine> m_arrScriptAIRoutines;
    bTObjArray<gSScript> m_arrScripts;
    gSScriptInit();
    ~gSScriptInit();
};

using gFScriptInit = gSScriptInit const *(GE_STDCALL *)();
