#ifndef GE_PTRMAP_H_INCLUDED
#define GE_PTRMAP_H_INCLUDED

template< typename K, typename T >
class bTPtrMap :
    public bTValMap< K, T >
{
    GE_DECLARE_MAP_ITERATORS()
};

#endif
