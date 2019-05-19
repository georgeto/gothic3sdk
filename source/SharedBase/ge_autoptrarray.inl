template< typename T >
bTAutoPtrArray< T >::bTAutoPtrArray( bTAutoPtrArray< T > const & _s ) :
    bTPtrArray< T >( _s )
{
}

template< typename T >
bTAutoPtrArray< T >::bTAutoPtrArray( GEInt _n ) :
    bTPtrArray< T >( _n )
{
}

template< typename T >
bTAutoPtrArray< T >::bTAutoPtrArray( void ) :
    bTPtrArray< T >()
{
}

template< typename T >
bTAutoPtrArray< T >::~bTAutoPtrArray( void )
{
    this->DeleteAll();
}
