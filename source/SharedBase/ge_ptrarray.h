#ifndef GE_PTRARRAY_H_INCLUDED
#define GE_PTRARRAY_H_INCLUDED

template< typename T >
class bTPtrArray :
    public bTValArray< T >
{
    private:
        T & AddNew( void );           // not defined
        T & InsertNewAt( GEInt _i );  // not defined
    public:
        void Delete( T const & _e );
        void DeleteAll( void );
        void DeleteAt( GEInt _i );
        T    RemoveAt( GEInt _i );
    public:
        bTPtrArray< T > & operator = ( bTPtrArray< T > const & _s );
    public:
                 bTPtrArray( bTPtrArray< T > const & _s );
        explicit bTPtrArray( GEInt _n );
                 bTPtrArray( void );
                ~bTPtrArray( void );
};

#include "ge_ptrarray.inl"

#endif
