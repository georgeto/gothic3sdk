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

template< typename T >
bCOStream & bTSet<T>::operator >> ( bCOStream & _os ) const
{
    _os << static_cast<GEU8>(1) << GetCount();
    GE_MAP_FOR_EACH(_e, _ignore, m_Map)
        *_e >> _os;
    return _os;
}

template< typename T >
bCIStream & bTSet<T>::operator << ( bCIStream & _is )
{
    m_Map.Clear();
    GEU8 _v;
    _v << _is;
    GEU32 _c;
    _c << _is;
    for (GEU32 i = 0; i < _c; i++)
    {
        T _e;
        _e << _is;
        Add(_e);
    }
    return _is;
}
