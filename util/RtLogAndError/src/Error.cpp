#include <g3sdk/util/Error.h>
#include <g3sdk/util/Logging.h>

#include <stdlib.h>

void assertionFailed(const char *exp, const char *file, int line)
{
    GetDefaultLogger().LogFormat("Assertion failed: %s\n, file %s, line %d\n", exp, file, line);
    CallFatalError("Assertion failed!", exp, file, line);
}

void CallFatalError(const char *a_strModule, const char *a_strDescription, const char *a_strFile, int a_iLine)
{
    // NOTE: This does not work if bCErrorAdmin has not yet been initialized (in early start phase).
    bCErrorAdmin::GetInstance().CallFatalError(a_strModule, a_strDescription, a_strFile, a_iLine);
}
