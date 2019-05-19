#ifndef GE_OBJSTACK_H_INCLUDED
#define GE_OBJSTACK_H_INCLUDED

template< typename T >
class bTObjStack :
    public bTObjArray< T >
{
    public:
        T const & Peek() const;
        T &       Peek();
};

#include "ge_objstack.inl"

#endif
