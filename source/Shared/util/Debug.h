#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#define G3SCRIPT_DEBUG

#if defined(G3SCRIPT_DEBUG)
#define G3SCRIPT_ASSERT(_Exp_) \
    __pragma(warning (push)) \
    __pragma(warning(disable : 4127)) \
    do { \
    if (!(_Exp_)) ::assertionFailed(#_Exp_, __FILE__, __LINE__); \
    } while (0) \
    __pragma(warning (pop))
#else
#define G3SCRIPT_ASSERT(_Exp_) _Exp_
#endif // DEBUG

void assertionFailed(const char* exp, const char* file, int line);


#endif