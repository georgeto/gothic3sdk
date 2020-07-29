#include "Module.h"

#include "Util.h"
#include "Logging.h"
#include "Debug.h"

mCModuleRegistry & mCModuleRegistry::GetInstance()
{
    static mCModuleRegistry s_ModuleRegistry;
    return s_ModuleRegistry;
}

GEBool mCModuleRegistry::RegisterModule(mFModuleMain a_pModuleMain, GELPCChar a_strModuleName, bTObjArray<bCString> const & a_arrDepends)
{
    if(m_Modules.IsValidKey(a_strModuleName))
    {
        bCString strMessage = bCString::GetFormattedString("Unable to register module %s, because there is already a module registered for this name.", a_strModuleName);
        GetDefaultLogger().LogFormat("[mCModuleRegistry] %s\n", strMessage.GetText());
        CallFatalError("mCModuleRegistry", strMessage);
        return GEFalse;
    }

    m_Modules.SetAt(a_strModuleName, {a_pModuleMain, a_strModuleName, a_arrDepends});
    return GETrue;
}

GEBool mCModuleRegistry::Apply()
{
    // 1. Verify dependencies
    bTObjArray<bCString> arrMissingDepends;
    GE_MAP_FOR_EACH(ModuleName, Module, m_Modules)
    {
        GE_ARRAY_FOR_EACH(RequiredModule, Module->m_arrDepends)
        {
            if(!m_Modules.IsValidKey(*RequiredModule))
            {
                bCString strMessage = bCString::GetFormattedString("Module %s depends on non existing module %s.", Module->m_strName, *RequiredModule);
                GetDefaultLogger().LogFormat("[mCModuleRegistry] %s.\n", strMessage);
                arrMissingDepends.Add(strMessage);
            }
        }
    }

    if(!arrMissingDepends.IsEmpty())
    {
        GetDefaultLogger().LogString("[mCModuleRegistry] Aborting due to unmet dependencies.");
        CallFatalError("mCModuleRegistry", "Aborting due to unmet dependencies:\n" + JoinString(arrMissingDepends, "  - %s", 0, "\n"));
    }

    // 2. Apply modules
    GE_MAP_FOR_EACH(ModuleName, Module, m_Modules)
    {
        GetDefaultLogger().LogFormat("[mCModuleRegistry] Applying module %s...\n", Module->m_strName);
        Module->m_pMain();
    }

    return GETrue;
}
