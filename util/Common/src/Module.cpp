#include "Module.h"

#include <g3sdk/util/Error.h>
#include <g3sdk/util/Logging.h>
#include <g3sdk/util/Util.h>

mCModuleRegistry &mCModuleRegistry::GetInstance()
{
    static mCModuleRegistry s_ModuleRegistry;
    return s_ModuleRegistry;
}

GEBool mCModuleRegistry::RegisterModule(mFModuleMain a_pModuleMain, GELPCChar a_strModuleName, GEUInt a_uPriority,
                                        bTObjArray<bCString> const &a_arrDepends)
{
    if (m_Modules.IsValidKey(a_strModuleName))
    {
        bCString strMessage = bCString::GetFormattedString(
            "Unable to register module %s, because there is already a module registered for this name.",
            a_strModuleName);
        GetDefaultLogger().LogFormat("[mCModuleRegistry] %s\n", strMessage.GetText());
        CallFatalError("mCModuleRegistry", strMessage);
        return GEFalse;
    }

    m_Modules.SetAt(a_strModuleName, {a_pModuleMain, a_strModuleName, a_uPriority, a_arrDepends});
    return GETrue;
}

GEBool mCModuleRegistry::Apply()
{
    // 1. Verify dependencies
    bTObjArray<bCString> arrMissingDepends;
    bTPtrArraySort<mCModule *> arrSortedModules(m_Modules.GetCount(), &mCModuleRegistry::CompareModule);
    GE_MAP_FOR_EACH_VAL (Module, m_Modules)
    {
        GE_ARRAY_FOR_EACH (RequiredModule, Module.m_arrDepends)
        {
            if (!m_Modules.IsValidKey(RequiredModule))
            {
                bCString strMessage =
                    bCString::GetFormattedString("Module %s depends on non existing module %s.",
                                                 Module.m_strName.GetText(), RequiredModule.GetText());
                GetDefaultLogger().LogFormat("[mCModuleRegistry] %s.\n", strMessage.GetText());
                arrMissingDepends.Add(strMessage);
            }
        }
        arrSortedModules.InsertSort(&Module);
    }

    if (!arrMissingDepends.IsEmpty())
    {
        GetDefaultLogger().LogString("[mCModuleRegistry] Aborting due to unmet dependencies.");
        CallFatalError("mCModuleRegistry", "Aborting due to unmet dependencies:\n"
                                               + JoinString<bCString, GELPCChar>(arrMissingDepends, "  - %s", 0, "\n"));
    }

    // 2. Apply modules
    GE_ARRAY_FOR_EACH (Module, arrSortedModules)
    {
        GetDefaultLogger().LogFormat("[mCModuleRegistry] Applying module %s...\n", Module->m_strName.GetText());
        Module->m_pMain();
    }

    return GETrue;
}

GEInt GE_CCALL mCModuleRegistry::CompareModule(GELPCVoid a_Module1, GELPCVoid a_Module2)
{
    mCModule const *pModule1 = *static_cast<mCModule *const *>(a_Module1);
    mCModule const *pModule2 = *static_cast<mCModule *const *>(a_Module2);
    if (pModule1->m_uPriority != pModule2->m_uPriority)
        return pModule1->m_uPriority < pModule2->m_uPriority;
    return pModule1->m_strName.Compare(pModule2->m_strName);
}
