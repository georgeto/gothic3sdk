#ifndef GE_VALARRAY_H_INCLUDED
#define GE_VALARRAY_H_INCLUDED

template< typename T >
class bTValArray :
    public bTArrayBase< T >
{
    public:
        void Add( T const & _e );
        T &  AddNew( void );
        void Clear( void );
        void CopyFrom( bTValArray< T > const & _s );
        void CopyTo( bTValArray< T > & _d ) const;
        void InsertAt( GEInt _i, T const & _e );
        T &  InsertNewAt( GEInt _i );
        void Remove( T const & _e );
        void RemoveAll( void );
        void RemoveAt( GEInt _i );
        void Reserve( GEInt _n );
        void SetAt( GEInt _i, T const & _e );
        void SetCount( GEInt _n );
    public:
        bTValArray< T > & operator = ( bTValArray< T > const & _s );
    public:
                 bTValArray( bTValArray< T > const & _s );
        explicit bTValArray( GEInt _n );
                 bTValArray( void );
                ~bTValArray( void );
    GE_DECLARE_ARRAY_STREAM_OPERATORS()
};

#include "ge_valarray.inl"

#endif
