#include "../Game.h"

gSScriptAIState::gSScriptAIState( GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAIState a_funcScriptAIState ) :
    m_strName( a_pcName ), m_strSource( a_pcSource ), m_funcScriptAIState( a_funcScriptAIState )
{
}

gSScriptAIState::gSScriptAIState( void )
{
}

gSScriptAIFunction::gSScriptAIFunction( GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAIFunction a_funcScriptAIFunction ) :
    m_strName( a_pcName ), m_strSource( a_pcSource ), m_funcScriptAIFunction( a_funcScriptAIFunction )
{
}

gSScriptAIFunction::gSScriptAIFunction( void )
{
}

gSScriptAICallback::gSScriptAICallback( GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAICallback a_funcScriptAICallback ) :
    m_strName( a_pcName ), m_strSource( a_pcSource ), m_funcScriptAICallback( a_funcScriptAICallback )
{
}

gSScriptAICallback::gSScriptAICallback( void )
{
}

gSScriptAIRoutine::gSScriptAIRoutine( GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAIRoutine a_funcScriptAIRoutine ) :
    m_strName( a_pcName ), m_strSource( a_pcSource ), m_funcScriptAIRoutine( a_funcScriptAIRoutine )
{
}

gSScriptAIRoutine::gSScriptAIRoutine( void )
{
}

gSScript::gSScript( GELPCChar a_pcName, GELPCChar a_pcSource, gFScript a_funcScript ) :
    m_strName( a_pcName ), m_strSource( a_pcSource ), m_funcScript( a_funcScript )
{
}

gSScript::gSScript( void )
{
}

gSScriptInit::gSScriptInit( void )
{
    m_arrScriptAIStates.Clear();
    m_arrScriptAIFunctions.Clear();
    m_arrScriptAICallbacks.Clear();
    m_arrScriptAIRoutines.Clear();
    m_arrScripts.Clear();
}

gSScriptInit::~gSScriptInit( void )
{
}

