#include "Memory.h"

#define NOMINMAX
#include <windows.h>

GELPCChar INVALID_MODULE_NAME = "<Invalid Module>";

GELPCChar GetCurrentModuleName()
{
    static CHAR ModuleFileName[MAX_PATH];

    if (ModuleFileName[0])
        return ModuleFileName;

    HMODULE Module;
    if (!GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, reinterpret_cast<LPCTSTR>(&GetCurrentModuleName),
                           &Module))
    {
        MessageBoxA(NULL, "", "Failed to resolve current module.", MB_ICONERROR);
        return INVALID_MODULE_NAME;
    }

    if (!GetModuleFileName(Module, ModuleFileName, sizeof(ModuleFileName)))
    {
        MessageBoxA(NULL, "", "Failed to resolve current module name.", MB_ICONERROR);
        return INVALID_MODULE_NAME;
    }
    return ModuleFileName;
}

GELPVoid LoadModule(GELPCChar a_strModule)
{
    GELPVoid pModule = reinterpret_cast<GELPVoid>(GetModuleHandle(a_strModule));
    if (!pModule)
        MessageBoxA(NULL, a_strModule, "Failed to resolve module address.", MB_ICONERROR);
    return pModule;
}

GELPVoid GetProcAddress(GELPCChar a_strModule, GELPCChar a_strProc)
{
    GELPVoid pProcAddress = reinterpret_cast<GELPVoid>(GetProcAddress(GetModuleHandle(a_strModule), a_strProc));
    if (!pProcAddress)
        MessageBoxA(NULL, a_strProc, "Failed to resolve function address.", MB_ICONERROR);
    return pProcAddress;
}
