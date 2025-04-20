#include "Memory.h"

#define NOMINMAX
#include <windows.h>

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
