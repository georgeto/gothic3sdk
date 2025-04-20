#include "Game.h"

gSScriptAIState::gSScriptAIState(GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAIState a_funcScriptAIState)
    : m_strName(a_pcName), m_funcScriptAIState(a_funcScriptAIState), m_strSource(a_pcSource)
{}

gSScriptAIState::gSScriptAIState()
{}

gSScriptAIFunction::gSScriptAIFunction(GELPCChar a_pcName, GELPCChar a_pcSource,
                                       gFScriptAIFunction a_funcScriptAIFunction)
    : m_strName(a_pcName), m_funcScriptAIFunction(a_funcScriptAIFunction), m_strSource(a_pcSource)
{}

gSScriptAIFunction::gSScriptAIFunction()
{}

gSScriptAICallback::gSScriptAICallback(GELPCChar a_pcName, GELPCChar a_pcSource,
                                       gFScriptAICallback a_funcScriptAICallback)
    : m_strName(a_pcName), m_funcScriptAICallback(a_funcScriptAICallback), m_strSource(a_pcSource)
{}

gSScriptAICallback::gSScriptAICallback()
{}

gSScriptAIRoutine::gSScriptAIRoutine(GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAIRoutine a_funcScriptAIRoutine)
    : m_strName(a_pcName), m_funcScriptAIRoutine(a_funcScriptAIRoutine), m_strSource(a_pcSource)
{}

gSScriptAIRoutine::gSScriptAIRoutine()
{}

gSScript::gSScript(GELPCChar a_pcName, GELPCChar a_pcSource, gFScript a_funcScript)
    : m_strName(a_pcName), m_funcScript(a_funcScript), m_strSource(a_pcSource)
{}

gSScript::gSScript()
{}

gSScriptInit::gSScriptInit()
{
    m_arrScriptAIStates.Clear();
    m_arrScriptAIFunctions.Clear();
    m_arrScriptAICallbacks.Clear();
    m_arrScriptAIRoutines.Clear();
    m_arrScripts.Clear();
}

gSScriptInit::~gSScriptInit()
{}
