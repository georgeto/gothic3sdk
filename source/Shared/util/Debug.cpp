#include "Debug.h"
#include "Logging.h"

#include <stdlib.h>

void assertionFailed(const char* exp, const char* file, int line) {
    GetDefaultLogger().LogFormat("Assertion failed: %s\n, file %s, line %d\n", exp, file, line);
    CallFatalError("Assertion failed!", exp, file, line);
}

void CallFatalError(const char * a_strModule, const char * a_strDescription, const char * a_strFile, int a_iLine)
{
    bCErrorAdmin::GetInstance().CallFatalError(a_strModule, a_strDescription, a_strFile, a_iLine);
}
