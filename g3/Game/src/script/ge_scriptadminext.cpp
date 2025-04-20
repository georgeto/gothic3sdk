#include "Game.h"

bTPtrArray<gSScriptDLL *> &gCScriptAdminExt::GetLoadedDLLs()
{
    return m_arrDLLs;
}

bTValMap<bCString, gSScriptAIState *> &gCScriptAdminExt::GetScriptAIStates()
{
    return m_ScriptAIStates;
}

bTValMap<bCString, gSScriptAIFunction *> &gCScriptAdminExt::GetScriptAIFunctions()
{
    return m_ScriptAIFunctions;
}

bTValMap<bCString, gSScriptAICallback *> &gCScriptAdminExt::GetScriptAICallbacks()
{
    return m_ScriptAICallbacks;
}

bTValMap<bCString, gSScriptAIRoutine *> &gCScriptAdminExt::GetScriptAIRoutines()
{
    return m_ScriptAIRoutines;
}

bTValMap<bCString, gSScript *> &gCScriptAdminExt::GetScripts()
{
    return m_Scripts;
}

gSScriptAIState const *gCScriptAdminExt::GetScriptAIState(bCString const &name) const
{
    return m_ScriptAIStates.GetAt(name);
}

gSScriptAIFunction const *gCScriptAdminExt::GetScriptAIFunction(bCString const &name) const
{
    return m_ScriptAIFunctions.GetAt(name);
}

gSScriptAICallback const *gCScriptAdminExt::GetScriptAICallback(bCString const &name) const
{
    return m_ScriptAICallbacks.GetAt(name);
}

gSScriptAIRoutine const *gCScriptAdminExt::GetScriptAIRoutine(bCString const &name) const
{
    return m_ScriptAIRoutines.GetAt(name);
}

gSScript const *gCScriptAdminExt::GetScript(bCString const &name) const
{
    return m_Scripts.GetAt(name);
}

gSScriptDLL const *gCScriptAdminExt::GetScriptDLL(bCString const &name) const
{
    GE_ARRAY_FOR_EACH (pDll, m_arrDLLs)
    {
        if (name == pDll->m_strFileName)
            return pDll;
    }
    return 0;
}

gSScriptDLL const *gCScriptAdminExt::GetScriptDLLAt(GEInt pos) const
{
    return m_arrDLLs.GetAt(pos);
}

GEInt gCScriptAdminExt::GetScriptDLLCount() const
{
    return m_arrDLLs.GetCount();
}

GEBool gCScriptAdminExt::UnRegisterScriptAIState(gSScriptAIState *state)
{
    if (this->GetScriptAIStates().RemoveAt(state->m_strName))
    {
        /*bCString dllName;
        this->GetScriptDLLWithState(state->m_strName, dllName);

        if(!dllName.IsEmpty()) {
            gSScriptDLL* scriptDLL = const_cast<gSScriptDLL*>(this->GetScriptDLL(dllName));
            if(scriptDLL != 0) {
                scriptDLL->m_arrScriptAIStates.Remove(*state);
            }
        }*/
        state->m_strName.Clear();

        return true;
    }
    return false;
}

GEBool gCScriptAdminExt::UnRegisterScriptAIFunction(gSScriptAIFunction *function)
{
    if (this->GetScriptAIFunctions().RemoveAt(function->m_strName))
    {
        /*bCString dllName;
        this->GetScriptDLLWithFunction(function->m_strName, dllName);

        if(!dllName.IsEmpty()) {
            gSScriptDLL* scriptDLL = const_cast<gSScriptDLL*>(this->GetScriptDLL(dllName));
            if(scriptDLL != 0) {
                scriptDLL->m_arrScriptAIFunctions.Remove(*function);
            }
        }*/
        function->m_strName.Clear();

        return true;
    }
    return false;
}

GEBool gCScriptAdminExt::UnRegisterScriptAICallback(gSScriptAICallback *callback)
{
    if (this->GetScriptAICallbacks().RemoveAt(callback->m_strName))
    {
        /*bCString dllName;
        this->GetScriptDLLWithCallback(callback->m_strName, dllName);

        if(!dllName.IsEmpty()) {
            gSScriptDLL* scriptDLL = const_cast<gSScriptDLL*>(this->GetScriptDLL(dllName));
            if(scriptDLL != 0) {
                scriptDLL->m_arrScriptAICallbacks.Remove(*callback);
            }
        }*/
        callback->m_strName.Clear();

        return true;
    }
    return false;
}

GEBool gCScriptAdminExt::UnRegisterScriptAIRoutine(gSScriptAIRoutine *routine)
{
    if (this->GetScriptAIRoutines().RemoveAt(routine->m_strName))
    {
        /*bCString dllName;
        this->GetScriptDLLWithRoutine(routine->m_strName, dllName);

        if(!dllName.IsEmpty()) {
            gSScriptDLL* scriptDLL = const_cast<gSScriptDLL*>(this->GetScriptDLL(dllName));
            if(scriptDLL != 0) {
                scriptDLL->m_arrScriptAIRoutines.Remove(*routine);
            }
        }*/
        routine->m_strName.Clear();

        return true;
    }
    return false;
}

GEBool gCScriptAdminExt::UnRegisterScript(gSScript *script)
{
    if (this->GetScripts().RemoveAt(script->m_strName))
    {
        script->m_strName.Clear();

        return true;
    }
    return false;
}

gCScriptAdminExt &GetScriptAdminExt()
{
    return *static_cast<gCScriptAdminExt *>(eCModuleAdmin::GetInstance().FindModule("gCScriptAdmin"));
}
