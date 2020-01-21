#ifndef MODULE_H_INCLUDED
#define MODULE_H_INCLUDED

#include "SharedBase.h"

class mCModuleRegistry
{
    public:
        static mCModuleRegistry & GetInstance();

        typedef void (*mFModuleMain)();
        GEBool RegisterModule(mFModuleMain a_pModuleMain, GELPCChar a_strModuleName, bTObjArray<bCString> const & a_arrDepends);

        GEBool Apply();

    private:
        struct mCModule
        {
            mFModuleMain m_pMain;
            bCString m_strName;
            bTObjArray<bCString> m_arrDepends;
        };

    private:
        bTStringObjMap< mCModule > m_Modules;
};

#define ME_MODULE( NAME ) \
    static void __ModuleMain_ ## NAME(); \
    GE_STATIC_BLOCK \
    { \
        mCModuleRegistry::GetInstance().RegisterModule( &__ModuleMain_ ## NAME, #NAME, bTObjArray<bCString>() ); \
    } \
    void __ModuleMain_ ## NAME()

#define ME_MODULE_DEPENDS( NAME, ... ) \
    static void __ModuleMain_ ## NAME(); \
    GE_STATIC_BLOCK \
    { \
        GELPCChar Depends[] = __VA_ARGS__; \
        GEInt iDependsCount = sizeof(Depends) / sizeof(Depends[0]); \
        bTObjArray<bCString> arrDepends(iDependsCount); \
        for(GEInt i = 0; i < iDependsCount; i++) \
            arrDepends.Add(Depends[i]); \
        mCModuleRegistry::GetInstance().RegisterModule( &__ModuleMain_ ## NAME, #NAME, arrDepends ); \
    } \
    void __ModuleMain_ ## NAME()

#endif
