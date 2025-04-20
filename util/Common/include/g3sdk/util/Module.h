#pragma once

#include <g3sdk/SharedBase.h>

class mCModuleRegistry
{
  public:
    static mCModuleRegistry &GetInstance();

    using mFModuleMain = void (*)();
    static constexpr GEUInt DefaultPriority = 0;
    static constexpr GEUInt MaxPriority = 255;
    GEBool RegisterModule(mFModuleMain a_pModuleMain, GELPCChar a_strModuleName, GEUInt a_uPriority,
                          bTObjArray<bCString> const &a_arrDepends);

    GEBool Apply();

  private:
    struct mCModule
    {
        mFModuleMain m_pMain;
        bCString m_strName;
        GEUInt m_uPriority;
        bTObjArray<bCString> m_arrDepends;
    };

    static GEInt GE_CCALL CompareModule(GELPCVoid, GELPCVoid);

  private:
    bTStringObjMap<mCModule> m_Modules;
};

#define _ME_MODULE(NAME, PRIORITY)                                                                                     \
    static void __ModuleMain_##NAME();                                                                                 \
    GE_STATIC_BLOCK                                                                                                    \
    {                                                                                                                  \
        mCModuleRegistry::GetInstance().RegisterModule(&__ModuleMain_##NAME, #NAME, PRIORITY, bTObjArray<bCString>()); \
    }                                                                                                                  \
    void __ModuleMain_##NAME()

#define ME_MODULE(NAME) _ME_MODULE(NAME, mCModuleRegistry::DefaultPriority)
#define ME_MODULE_PRIO(NAME, PRIORITY) _ME_MODULE(NAME, PRIORITY)

#define ME_MODULE_DEPENDS(NAME, ...)                                                                                   \
    static void __ModuleMain_##NAME();                                                                                 \
    GE_STATIC_BLOCK                                                                                                    \
    {                                                                                                                  \
        GELPCChar Depends[] = __VA_ARGS__;                                                                             \
        GEInt iDependsCount = sizeof(Depends) / sizeof(Depends[0]);                                                    \
        bTObjArray<bCString> arrDepends(iDependsCount);                                                                \
        for (GEInt i = 0; i < iDependsCount; i++)                                                                      \
            arrDepends.Add(Depends[i]);                                                                                \
        mCModuleRegistry::GetInstance().RegisterModule(&__ModuleMain_##NAME, #NAME, mCModuleRegistry::DefaultPriority, \
                                                       arrDepends);                                                    \
    }                                                                                                                  \
    void __ModuleMain_##NAME()
