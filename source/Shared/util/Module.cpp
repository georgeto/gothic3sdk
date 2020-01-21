#include "Module.h"

#include "Util.h"
#include "Logging.h"

mCModuleRegistry & mCModuleRegistry::GetInstance()
{
    static mCModuleRegistry s_ModuleRegistry;
    return s_ModuleRegistry;
}

GEBool mCModuleRegistry::RegisterModule(mFModuleMain a_pModuleMain, GELPCChar a_strModuleName, bTObjArray<bCString> const & a_arrDepends)
{
    if(m_Modules.IsValidKey(a_strModuleName))
    {
        GetDefaultLogger().LogFormat("[mCModuleRegistry] Unable to register module %s, because there is already a module registered for this name.\n", a_strModuleName);
        return GEFalse;
    }

    m_Modules.SetAt(a_strModuleName, {a_pModuleMain, a_strModuleName, a_arrDepends});
    return GETrue;
}

GEBool mCModuleRegistry::Apply()
{
    // 1. Verify dependencies
    GEBool bMissingDepends = GEFalse;
    GE_MAP_FOR_EACH(ModuleName, Module, m_Modules)
    {
        GE_ARRAY_FOR_EACH(RequiredModule, Module->m_arrDepends)
        {
            if(!m_Modules.IsValidKey(*RequiredModule))
            {
                GetDefaultLogger().LogFormat("[mCModuleRegistry] Module %s depends on non existing module %s.\n", Module->m_strName, *RequiredModule);
                bMissingDepends = GETrue;
            }
        }
    }

    if(bMissingDepends)
    {
        GetDefaultLogger().LogString("[mCModuleRegistry] Aborting due to unmet dependencies.\n");
        abort();
    }

    // 2. Apply modules
    GE_MAP_FOR_EACH(ModuleName, Module, m_Modules)
    {
        GetDefaultLogger().LogFormat("[mCModuleRegistry] Applying module %s...\n", Module->m_strName);
        Module->m_pMain();
    }

    return GETrue;
}
