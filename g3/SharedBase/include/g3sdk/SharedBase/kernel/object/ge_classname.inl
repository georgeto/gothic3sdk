#include "ge_classnamebase.h"

#pragma warning(push)
#pragma warning(                                                                                                       \
    disable : 4820) // warning C4820: 'type_info' : '3' bytes padding added after data member 'type_info::_m_d_name'
#include <typeinfo>
#pragma warning(pop)

#pragma warning(push)
#pragma warning(                                                                                                       \
    disable : 4640) // warning C4640: 's_strClassName' : construction of local static object is not thread-safe

template <typename T>
bCString const &bTClassName<T>::GetUnmangled()
{
    static bCString s_strClassName = bCClassNameBase::UnMangle(typeid(T).name());
    return s_strClassName;
}

#pragma warning(pop)
