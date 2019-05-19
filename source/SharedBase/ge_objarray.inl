template< typename T >
void bTObjArray< T >::Add( T const & _e )
{
    GEInt const _i = this->GetCount();
    this->SetCount( _i + 1 );
    this->SetAt( _i, _e );
}

template< typename T >
T & bTObjArray< T >::AddNew( void )
{
    GEInt const _i = this->GetCount();
    this->SetCount( _i + 1 );
    return this->AccessAt( _i );
}

template< typename T >
void bTObjArray< T >::Clear( void )
{
    if( this->m_pArray )
    {
        bTArrayBase< T >::Delete( this->m_pArray, this->GetCapacity() );
        GE_FREE( this->m_pArray );
    }
    this->Init();
}

template< typename T >
void bTObjArray< T >::CopyFrom( bTObjArray< T > const & _s )
{
    if( this != &_s )
    {
        this->SetCount( _s.GetCount() );
        for( GEInt i = 0; i < this->GetCount(); i++ )
            this->SetAt( i, _s.GetAt( i ) );
    }
}

template< typename T >
void bTObjArray< T >::CopyTo( bTObjArray< T > & _d ) const
{
    _d.CopyFrom( *this );
}

template< class T >
void bTObjArray< T >::InsertAt( GEInt _i, T const & _e )
{
    GEInt const _c = this->GetCount();
    if( _c == _i )
    {
        this->Add( _e );
    }
    else
    {
        this->SetCount( _c + 1 );
        bTArrayBase< T >::Delete( this->m_pArray + _c, 1 );
        bTArrayBase< T >::Move( this->m_pArray + _i + 1, this->m_pArray + _i, _c - _i );
        bTArrayBase< T >::New( this->m_pArray + _i, 1 );
        this->SetAt( _i, _e );
    }
}

template< typename T >
T & bTObjArray< T >::InsertNewAt( GEInt _i )
{
    GEInt const _c = this->GetCount();
    if( _c == _i )
    {
        return this->AddNew();
    }
    else
    {
        this->SetCount( _c + 1 );
        bTArrayBase< T >::Delete( this->m_pArray + _c, 1 );
        bTArrayBase< T >::Move( this->m_pArray + _i + 1, this->m_pArray + _i, _c - _i );
        bTArrayBase< T >::New( this->m_pArray + _i, 1 );
        return this->AccessAt( _i );
    }
}

template< typename T >
void bTObjArray< T >::Remove( T const & _e )
{
    this->RemoveAt( this->IndexOf( _e ) );
}

template< typename T >
void bTObjArray< T >::RemoveAll( void )
{
    this->Clear();
}

template< typename T >
void bTObjArray< T >::RemoveAt( GEInt _i )
{
    GEInt const _u = this->GetCount() - 1;
    if( (0 <= _i) && (_i <= _u) )
    {
        bTArrayBase< T >::Delete( this->m_pArray + _i, 1 );
        bTArrayBase< T >::Move( this->m_pArray + _i, this->m_pArray + _i + 1, _u - _i );
        bTArrayBase< T >::New( this->m_pArray + _u, 1 );
        this->m_u32Count--;
    }
}

template< typename T >
void bTObjArray< T >::Reserve( GEInt _n )
{
    if( _n > this->GetCapacity() )
    {
        this->m_pArray = static_cast< T * >( GE_REALLOC( this->m_pArray, _n * sizeof( T ) ) );
        bTArrayBase< T >::New( this->m_pArray + this->GetCapacity(), _n - this->GetCapacity() );
        this->m_u32Capacity = static_cast< GEU32 >( _n );
    }
}

template< typename T >
void bTObjArray< T >::SetAt( GEInt _i, T const & _e )
{
    T * _x = this->AccessArray() + _i;
    bTArrayBase< T >::Delete( _x, 1 );
    bTArrayBase< T >::New( _x, 1 );
    bTArrayBase< T >::Copy( _x, &_e, 1 );
}

template< typename T >
void bTObjArray< T >::SetCount( GEInt _n )
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
            bTArrayBase< T >::Delete( this->m_pArray + _n, _c - _n );
            bTArrayBase< T >::New( this->m_pArray + _n, _c - _n );
            this->m_u32Count = static_cast< GEU32 >( _n );
        }
    }
}

template< typename T >
bTObjArray< T > & bTObjArray< T >::operator = ( bTObjArray< T > const & _s )
{
    this->CopyFrom( _s );
    return *this;
}

template< typename T >
bTObjArray< T >::bTObjArray( bTObjArray< T > const & _s ) :
    bTArrayBase< T >()
{
    this->CopyFrom( _s );
}

template< typename T >
bTObjArray< T >::bTObjArray( GEInt _n ) :
    bTArrayBase< T >()
{
    this->Reserve( _n );
}

template< typename T >
bTObjArray< T >::bTObjArray( void ) :
    bTArrayBase< T >()
{
}

template< typename T >
bTObjArray< T >::~bTObjArray( void )
{
    this->Clear();
}
