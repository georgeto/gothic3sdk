template <typename T>
mCLoggingAdmin<T> &mCLoggingAdmin<T>::GetLoggingAdmin()
{
    static mCLoggingAdmin<T> s_LoggingAdmin;
    return s_LoggingAdmin;
}

template <typename T>
T &mCLoggingAdmin<T>::GetLogger(GELPCChar a_strPath, GEBool a_bEnabled)
{
    mCLoggingAdmin<T> &LoggingAdmin = GetLoggingAdmin();
    if (!LoggingAdmin.m_Loggers.IsValidKey(a_strPath))
    {
        T *pLogger = new T(a_strPath);
        pLogger->SetEnabled(a_bEnabled);
        LoggingAdmin.m_Loggers.SetAt(a_strPath, pLogger);
    }

    return *LoggingAdmin.m_Loggers.AccessAt(a_strPath);
}

template <typename T>
GEBool mCLoggingAdmin<T>::FreeLogger(T &a_Logger)
{
    mCLoggingAdmin<T> &LoggingAdmin = GetLoggingAdmin();

    bCString strName;
    GE_MAP_FOR_EACH (Name, pLogger, LoggingAdmin.m_Loggers)
    {
        if (pLogger == &a_Logger)
        {
            strName = Name;
            break;
        }
    }

    if (strName.IsEmpty())
        return GEFalse;

    LoggingAdmin.m_Loggers.RemoveAt(strName);
    delete &a_Logger;

    return GETrue;
}

template <typename T>
mCLoggingAdmin<T>::~mCLoggingAdmin()
{
    GE_MAP_FOR_EACH_VAL (pLogger, m_Loggers)
    {
        delete pLogger;
    }
    m_Loggers.Clear();
}
