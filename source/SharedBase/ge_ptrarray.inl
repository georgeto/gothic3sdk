template< typename T >
void bTPtrArray< T >::Delete( T const & _e )
{
    this->DeleteAt( this->IndexOf( _e ) );
}

template< typename T >
void bTPtrArray< T >::DeleteAll( void )
{
    for( GEInt _i = 0; _i < this->GetCount(); ++_i )
        GE_DELETE( this->AccessAt( _i ) );
    this->RemoveAll();
}

template< typename T >
void bTPtrArray< T >::DeleteAt( GEInt _i )
{
    GE_DELETE( this->RemoveAt( _i ) );
}

template< typename T >
T bTPtrArray< T >::RemoveAt( GEInt _i )
{
    if( (0 <= _i) && (_i < this->GetCount()) )
    {
        T _e = this->GetAt( _i );
        bTValArray< T >::RemoveAt( _i );
        return _e;
    }
    return 0;
}

template< typename T >
bTPtrArray< T > & bTPtrArray< T >::operator = ( bTPtrArray< T > const & _s )
{
    this->CopyFrom( _s );
    return *this;
}

template< typename T >
bTPtrArray< T >::bTPtrArray( bTPtrArray< T > const & _s ) :
    bTValArray< T >( _s )
{
}

template< typename T >
bTPtrArray< T >::bTPtrArray( GEInt _n ) :
    bTValArray< T >( _n )
{
}

template< typename T >
bTPtrArray< T >::bTPtrArray( void ) :
    bTValArray< T >()
{
}

template< typename T >
bTPtrArray< T >::~bTPtrArray( void )
{
    bTValArray< T >::~bTValArray();
}
