#ifndef LOGGING_H_INCLUDED
#define LOGGING_H_INCLUDED

#include <stdio.h>
#include "SharedBase.h"

class mCLoggerBase
{
    public:
        mCLoggerBase();

    public:
        virtual void LogString( GELPCChar a_strMessage )     = 0;
        virtual void LogFormat( GELPCChar a_strFormat, ... ) = 0;
        virtual void PushIndent();
        virtual void PopIndent();
        void SetEnabled(GEBool a_bEnabled);
        virtual void Free() = 0;

    protected:
        bCString Indent( GELPCChar a_strText );

    protected:
        GEBool m_bEnabled;

    private:
        GEUInt m_uCurrentIndent;
};

class mCFileLogger: public mCLoggerBase
{
    public:
        static mCFileLogger & GetInstance( GELPCChar a_strName );

    public:
        mCFileLogger();
        mCFileLogger( GELPCChar a_strFile );

    public:
        virtual void LogString( GELPCChar a_strMessage );
        virtual void LogFormat( GELPCChar a_strFormat, ... );
        virtual void LogFormatPrefix( GELPCChar a_strPrefix, GELPCChar a_strFormat, ... );
        virtual void Free();
        FILE *       GetFile();

    private:
        FILE * m_pFile;
};

class mCStdLogger: public mCLoggerBase
{
    public:
        mCStdLogger();
        mCStdLogger( GELPCChar a_strName );

        virtual void LogString( GELPCChar a_strMessage );
        virtual void LogFormat( GELPCChar a_strFormat, ... );
        virtual void Free();
};

template< typename T >
class mCLoggingAdmin
{
    public:
        static T & GetLogger( GELPCChar a_strPath, GEBool a_bActive = true );

    private:
        static mCLoggingAdmin s_LoggingAdmin;

    private:
        ~mCLoggingAdmin();

    private:
        bTObjMap< bCString, T > m_Loggers;
};

void           SetDefaultLogger( mCLoggerBase & a_Logger );
mCLoggerBase & GetDefaultLogger();

#include "Logging.inl"

#endif