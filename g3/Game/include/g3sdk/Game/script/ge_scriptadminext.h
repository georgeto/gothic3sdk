#pragma once

#include <Game/script/ge_scriptadmin.h>

class gCScriptAdminExt : public gCScriptAdmin
{
  public:
    using gCScriptAdmin::GetScriptDLL;

  public:
    bTPtrArray<gSScriptDLL *> &GetLoadedDLLs();
    bTValMap<bCString, gSScriptAIState *> &GetScriptAIStates();
    bTValMap<bCString, gSScriptAIFunction *> &GetScriptAIFunctions();
    bTValMap<bCString, gSScriptAICallback *> &GetScriptAICallbacks();
    bTValMap<bCString, gSScriptAIRoutine *> &GetScriptAIRoutines();
    bTValMap<bCString, gSScript *> &GetScripts();

    gSScriptAIState const *GetScriptAIState(bCString const &name) const;
    gSScriptAIFunction const *GetScriptAIFunction(bCString const &name) const;
    gSScriptAICallback const *GetScriptAICallback(bCString const &name) const;
    gSScriptAIRoutine const *GetScriptAIRoutine(bCString const &name) const;
    gSScript const *GetScript(bCString const &name) const;
    gSScriptDLL const *GetScriptDLL(bCString const &name) const;
    gSScriptDLL const *GetScriptDLLAt(GEInt) const;
    GEInt GetScriptDLLCount() const;

    GEBool UnRegisterScriptAIState(gSScriptAIState *state);
    GEBool UnRegisterScriptAIFunction(gSScriptAIFunction *function);
    GEBool UnRegisterScriptAICallback(gSScriptAICallback *callback);
    GEBool UnRegisterScriptAIRoutine(gSScriptAIRoutine *routine);
    GEBool UnRegisterScript(gSScript *script);
};

gCScriptAdminExt &GetScriptAdminExt();
