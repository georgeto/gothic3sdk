template< typename T >
void bTObjArraySort<T>::CopyFrom(bTObjArraySort< T > const & _s)
{
    bTObjArray< T >::CopyFrom( _s );
    this->m_fComparator = _s.m_fComparator;
    this->m_bSorted =_s.m_bSorted;
}

template< typename T >
GEInt bTObjArraySort<T>::InsertSort(T const & _e)
{
    this->Sort();

    GEInt iLeft = 0;
    GEInt iRight = this->m_u32Count - 1;
    GEInt i = iRight / 2;
    for( i; iRight > iLeft; i = ( iRight + iLeft ) / 2 )
    {
        if( this->m_fComparator( &_e, &this->m_pArray[i] ) <= 0 )
            iRight = i - 1;
         else
            iLeft = i + 1;
    }

    if( i < static_cast<GEInt>(this->m_u32Count) )
    {
        if( this->m_fComparator( &_e, &this->m_pArray[i] ) > 0 )
            i++;
    }

    bTObjArray< T >::InsertAt( i, _e );
    return i;
}

template< typename T >
void bTObjArraySort<T>::Sort(void)
{
    if(!m_bSorted)
    {
        g_ArrayInsertionSort(this->m_pArray, this->m_u32Count, sizeof( T ), this->m_fComparator, GETrue );
        m_bSorted = GETrue;
    }
}

template< typename T >
GEInt bTObjArraySort<T>::Search(T const & _e)
{
    this->Sort();

    if( this->m_u32Count <= 0 )
        return -1;

    GEInt iLeft = 0;
    GEInt iRight = this->m_u32Count - 1;
    GEInt iIndex = iRight / 2;
    GEInt i = this->m_fComparator( &_e, &this->m_pArray[iIndex] );
    for( i; iRight > iLeft; i = this->m_fComparator( &_e, &this->m_pArray[iIndex] )  )
    {
        if( i <= 0 )
        {
            if( i >= 0 )
                break;
            iRight = iIndex - 1;

        }
        else
        {
            iLeft = iIndex + 1;
        }
        iIndex = (iRight + iLeft) / 2;
    }

    if( i )
        return -1;

    return iIndex;
}

template< typename T >
bTObjArraySort< T > & bTObjArraySort< T >::operator = ( bTObjArraySort< T > const & _s )
{
    this->CopyFrom( _s );
    return *this;
}

template< typename T >
bTObjArraySort< T >::bTObjArraySort( bTObjArraySort< T > const & _s ) :
    bTObjArray< T >( _s ),
    m_fComparator(_s.m_fComparator),
    m_bSorted(_s.m_bSorted)
{
}

template< typename T >
bTObjArraySort< T >::bTObjArraySort( GEInt _n ) :
    bTObjArray< T >( _n ),
    m_fComparator(&g_ArraySortDefaultCompare),
    m_bSorted(GETrue)
{
}

template< typename T >
bTObjArraySort< T >::bTObjArraySort( void ) :
    bTObjArray< T >(),
    m_fComparator(&g_ArraySortDefaultCompare),
    m_bSorted(GETrue)
{
}

template< typename T >
bTObjArraySort< T >::~bTObjArraySort( void )
{
    bTObjArray< T >::~bTObjArray();
}
