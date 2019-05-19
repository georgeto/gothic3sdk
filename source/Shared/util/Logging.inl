template< typename T >
T & mCLoggingAdmin<T>::GetLogger( GELPCChar a_strPath, GEBool a_bEnabled )
{
    static mCLoggingAdmin<T> s_LoggingAdmin;

    if( !s_LoggingAdmin.m_Loggers.IsValidKey( a_strPath ) )
    {
        T Logger = T(a_strPath);
        Logger.SetEnabled(a_bEnabled);
        s_LoggingAdmin.m_Loggers.SetAt( a_strPath, Logger );
    }

    return s_LoggingAdmin.m_Loggers.AccessAt( a_strPath );
}


template< typename T >
mCLoggingAdmin<T>::~mCLoggingAdmin()
{
   for(bTValMap< bCString, T >::bCIterator NodeIterator = m_Loggers.Begin(); NodeIterator != m_Loggers.End(); ++NodeIterator)
    {
        NodeIterator->Free();
    }
    m_Loggers.Clear();
}
