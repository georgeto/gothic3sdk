template< typename T >
void bTValArray< T >::Add( T const & _e )
{
    GEInt const _i = this->GetCount();
    this->SetCount( _i + 1 );
    this->SetAt( _i, _e );
}

template< typename T >
T & bTValArray< T >::AddNew( void )
{
    GEInt const _i = this->GetCount();
    this->SetCount( _i + 1 );
    return this->AccessAt( _i );
}

template< typename T >
void bTValArray< T >::Clear( void )
{
    if( this->m_pArray )
        GE_FREE( this->m_pArray );
    this->Init();
}

template< typename T >
void bTValArray< T >::CopyFrom( bTValArray< T > const & _s )
{
    if( this != &_s )
    {
        this->SetCount( _s.GetCount() );
        for( GEInt i = 0; i < this->GetCount(); i++ )
            this->SetAt( i, _s.GetAt( i ) );
    }
}

template< typename T >
void bTValArray< T >::CopyTo( bTValArray< T > & _d ) const
{
    _d.CopyFrom( *this );
}

template< class T >
void bTValArray< T >::InsertAt( GEInt _i, T const & _e )
{
    GEInt const _c = this->GetCount();
    if( _c == _i )
    {
        this->Add( _e );
    }
    else
    {
        this->SetCount( _c + 1 );
        bTArrayBase< T >::Move( this->m_pArray + _i + 1, this->m_pArray + _i, _c - _i );
        this->SetAt( _i, _e );
    }
}

template< typename T >
T & bTValArray< T >::InsertNewAt( GEInt _i )
{
    GEInt const _c = this->GetCount();
    if( _c == _i )
    {
        return this->AddNew();
    }
    else
    {
        this->SetCount( _c + 1 );
        bTArrayBase< T >::Move( this->m_pArray + _i + 1, this->m_pArray + _i, _c - _i );
        return this->AccessAt( _i );
    }
}

template< typename T >
void bTValArray< T >::Remove( T const & _e )
{
    this->RemoveAt( this->IndexOf( _e ) );
}

template< typename T >
void bTValArray< T >::RemoveAll( void )
{
    this->Clear();
}

template< typename T >
void bTValArray< T >::RemoveAt( GEInt _i )
{
    GEInt const _u = this->GetCount() - 1;
    if( (0 <= _i) && (_i <= _u) )
    {
        bTArrayBase< T >::Move( this->m_pArray + _i, this->m_pArray + _i + 1, _u - _i );
        this->m_u32Count--;
    }
}

template< typename T >
void bTValArray< T >::Reserve( GEInt _n )
{
    if( _n > this->GetCapacity() )
    {
        this->m_pArray = static_cast< T * >( GE_REALLOC( this->m_pArray, _n * sizeof( T ) ) );
        //g_ZeroMemory( this->m_pArray + this->GetCapacity(), sizeof( T ) * static_cast< GEU32 >( _n - this->GetCapacity() ) );
        memset( this->m_pArray + this->GetCapacity(), 0, sizeof( T ) * static_cast< GEU32 >( _n - this->GetCapacity() ) );
        this->m_u32Capacity = static_cast< GEU32 >( _n );
    }
}

template< typename T >
void bTValArray< T >::SetAt( GEInt _i, T const & _e )
{
    T * _x = this->AccessArray() + _i;
    bTArrayBase< T >::Copy( _x, &_e, 1 );
}

template< typename T >
void bTValArray< T >::SetCount( GEInt _n )
{
    if( 0 == _n )
        this->Clear();
    else
    {
        GEInt const _c = this->GetCount();
        if( _n > _c )
        {
            this->Reserve( _n );
            this->m_u32Count = static_cast< GEU32 >( _n );
        }
        else if( _n < _c )
        {
            //g_ZeroMemory( this->m_pArray + _n, static_cast< GEU32 >( _c - _n ) );
            memset( this->m_pArray + _n, 0, static_cast< GEU32 >( _c - _n ) );
            this->m_u32Count = static_cast< GEU32 >( _n );
        }
    }
}

template< typename T >
bTValArray< T > & bTValArray< T >::operator = ( bTValArray< T > const & _s )
{
    this->CopyFrom( _s );
    return *this;
}

template< typename T >
bTValArray< T >::bTValArray( bTValArray< T > const & _s ) :
    bTArrayBase< T >()
{
    this->CopyFrom( _s );
}

template< typename T >
bTValArray< T >::bTValArray( GEInt _n ) :
    bTArrayBase< T >()
{
    this->Reserve( _n );
}

template< typename T >
bTValArray< T >::bTValArray( void ) :
    bTArrayBase< T >()
{
}

template< typename T >
bTValArray< T >::~bTValArray( void )
{
    this->Clear();
}
