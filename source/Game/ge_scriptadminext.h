#ifndef GE_SCRIPTADMINEXT_H_INCLUDED
#define GE_SCRIPTADMINEXT_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4625 ) // copy constructor could not be generated because a base class copy constructor is inaccessible

class gCScriptAdminExt :
    public gCScriptAdmin
{
    public: using gCScriptAdmin::GetScriptDLL;

    public:
        bTPtrArray< gSScriptDLL* >&                GetLoadedDLLs();
        bTValMap< bCString, gSScriptAIState* >&    GetScriptAIStates();
        bTValMap< bCString, gSScriptAIFunction* >& GetScriptAIFunctions();
        bTValMap< bCString, gSScriptAICallback* >& GetScriptAICallbacks();
        bTValMap< bCString, gSScriptAIRoutine* >&  GetScriptAIRoutines();
        bTValMap< bCString, gSScript* >&           GetScripts();

        gSScriptAIState const *    GetScriptAIState( bCString const & name ) const;
        gSScriptAIFunction const * GetScriptAIFunction( bCString const & name ) const;
        gSScriptAICallback const * GetScriptAICallback( bCString const & name ) const;
        gSScriptAIRoutine const *  GetScriptAIRoutine( bCString const & name ) const;
        gSScript const *           GetScript( bCString const & name ) const;
        gSScriptDLL const *        GetScriptDLL( bCString const & name ) const;
        gSScriptDLL const *        GetScriptDLLAt( GEInt ) const;
        GEInt                      GetScriptDLLCount( void ) const;

        GEBool UnRegisterScriptAIState( gSScriptAIState * state );
        GEBool UnRegisterScriptAIFunction( gSScriptAIFunction * function );
        GEBool UnRegisterScriptAICallback( gSScriptAICallback * callback );
        GEBool UnRegisterScriptAIRoutine( gSScriptAIRoutine * routine );
        GEBool UnRegisterScript( gSScript * script );
};

#pragma warning( pop )

gCScriptAdminExt& GetScriptAdminExt();

#endif
