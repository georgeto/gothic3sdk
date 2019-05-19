#include "Memory.h"

GELPVoid LoadModule(GELPCChar a_strModule) {
    return reinterpret_cast<GELPVoid>(GetModuleHandle(a_strModule));
}

GELPVoid GetProcAddress(GELPCChar a_strModule, GELPCChar a_strProc) {
    return reinterpret_cast<GELPVoid>(GetProcAddress(GetModuleHandle(a_strModule), a_strProc));
}