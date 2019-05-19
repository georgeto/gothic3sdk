#include "Debug.h"
#include "Logging.h"

#include <stdlib.h>

void assertionFailed(const char* exp, const char* file, int line) {
    GetDefaultLogger().LogFormat("Assertion failed: %s\n, file %s, line %d\n", exp, file, line);
    abort();
}