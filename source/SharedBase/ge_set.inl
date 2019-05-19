template< typename T >
void bTSet<T>::Add( T const & _e )
{
    m_Map.SetAt( _e, 0 );
}

template< typename T >
void bTSet<T>::Clear( void )
{
    return m_Map.Clear();
}

template< typename T >
GEBool bTSet<T>::Contains( T const & _e ) const
{
    return m_Map.IsValidKey( _e );
}

template< typename T >
GEInt bTSet<T>::GetCount( void ) const
{
    return m_Map.GetCount();
}

template< typename T >
void bTSet<T>::Init( GEU32 _n )
{
    m_Map.InitHashTable( _n );
}

template< typename T >
GEBool bTSet<T>::IsEmpty( void ) const
{
    return m_Map.IsEmpty();
}

template< typename T >
GEBool bTSet<T>::Remove( T const & _e )
{
    return m_Map.RemoveAt( _e );
}
