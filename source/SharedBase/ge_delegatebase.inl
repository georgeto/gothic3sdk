template< typename CLASS, typename ARG >
bTDelegate<CLASS, ARG>::bTDelegate( bFDelegateFunction a_pDelegateFunction, CLASS * a_pClassThisPointer )
    : m_pDelegateFunction( a_pDelegateFunction ), m_pClassThisPointer( a_pClassThisPointer )
{}

template< typename CLASS, typename ARG >
bCObjectRefBase * bTDelegate<CLASS, ARG>::GetThisPointer()
{
    return m_pClassThisPointer;
}

template< typename CLASS, typename ARG >
bCDelegateBase * bTDelegate<CLASS, ARG>::Clone()
{
    return GE_NEW( ( bTDelegate<CLASS, ARG>) )( m_pDelegateFunction, m_pClassThisPointer );
}
