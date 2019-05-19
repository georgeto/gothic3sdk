#ifndef GE_SCRIPTINIT_H_INCLUDED
#define GE_SCRIPTINIT_H_INCLUDED

class gCScriptProcessingUnit;
struct gScriptRunTimeSingleState;

typedef GEInt (GE_STDCALL * gFScript)( gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt );
typedef GEBool (GE_STDCALL * gFScriptAIRoutine)( gCScriptProcessingUnit * );
typedef GEBool (GE_STDCALL * gFScriptAICallback)( gCScriptProcessingUnit * );
typedef GEBool (GE_STDCALL * gFScriptAIFunction)( bTObjStack< gScriptRunTimeSingleState > &, gCScriptProcessingUnit * );
typedef GEBool (GE_STDCALL * gFScriptAIState)( bTObjStack< gScriptRunTimeSingleState > &, gCScriptProcessingUnit * );

struct gSScript
{
    bCString m_strName;
    gFScript m_funcScript;
    bCString m_strSource;

    gSScript( GELPCChar a_pcName, GELPCChar a_pcSource, gFScript a_funcScript );
    gSScript( void );

    GEBool operator == ( gSScript const & script ) const {
        return this->m_strName == script.m_strName;
    };
};

struct gSScriptAIRoutine
{
    bCString          m_strName;
    gFScriptAIRoutine m_funcScriptAIRoutine;
    bCString          m_strSource;

    gSScriptAIRoutine( GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAIRoutine a_funcScriptAIState );
    gSScriptAIRoutine( void );

    GEBool operator == ( gSScriptAIRoutine const & routine ) const {
        return this->m_strName == routine.m_strName;
    };
};

struct gSScriptAICallback
{
    bCString           m_strName;
    gFScriptAICallback m_funcScriptAICallback;
    bCString           m_strSource;

    gSScriptAICallback( GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAICallback a_funcScriptAICallback );
    gSScriptAICallback( void );

    GEBool operator == ( gSScriptAICallback const & callback ) const {
        return this->m_strName == callback.m_strName;
    };
};

struct gSScriptAIFunction
{
    bCString           m_strName;
    gFScriptAIFunction m_funcScriptAIFunction;
    bCString           m_strSource;

    gSScriptAIFunction( GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAIFunction a_funcScriptAIFunction );
    gSScriptAIFunction( void );

    GEBool operator == ( gSScriptAIFunction const & function ) const {
        return this->m_strName == function.m_strName;
    };
};

struct gSScriptAIState
{
    bCString        m_strName;
    gFScriptAIState m_funcScriptAIState;
    bCString        m_strSource;

    gSScriptAIState( GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAIState a_funcScriptAIState );
    gSScriptAIState( void );

    GEBool operator == ( gSScriptAIState const & state ) const {
        return this->m_strName == state.m_strName;
    };
};


struct gSScriptInit
{
    bTObjArray< gSScriptAIState >    m_arrScriptAIStates;
    bTObjArray< gSScriptAIFunction > m_arrScriptAIFunctions;
    bTObjArray< gSScriptAICallback > m_arrScriptAICallbacks;
    bTObjArray< gSScriptAIRoutine >  m_arrScriptAIRoutines;
    bTObjArray< gSScript >           m_arrScripts;
                                     gSScriptInit( void );
                                    ~gSScriptInit( void );
};

typedef gSScriptInit const * (GE_STDCALL * gFScriptInit)( void );

#endif
