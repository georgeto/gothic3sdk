#ifndef GE_AUTOPTRARRAY_H_INCLUDED
#define GE_AUTOPTRARRAY_H_INCLUDED

template< typename T >
class bTAutoPtrArray :
    public bTPtrArray< T >
{
    private:
        bTAutoPtrArray<T > & operator = ( bTAutoPtrArray< T > const & _s );  // not defined
    private:
        bTAutoPtrArray( bTAutoPtrArray< T > const & _s );
    public:
        explicit bTAutoPtrArray( GEInt _n );
                 bTAutoPtrArray( void );
                ~bTAutoPtrArray( void );
};

#include "ge_autoptrarray.inl"

#endif
