#pragma once

#pragma warning(push, 1)
#ifndef WINVER
#define WINVER 0x0600
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT WINVER
#endif
#define NOMINMAX
#include <windows.h>
#pragma warning(pop)

// These macros collide with function names used in Gothic 3 classes.
#undef GetClassName
#undef GetObject
#undef SendMessage
