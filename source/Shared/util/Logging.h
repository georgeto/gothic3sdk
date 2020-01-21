#ifndef LOGGING_H_INCLUDED
#define LOGGING_H_INCLUDED

#include <stdio.h>
#include "SharedBase.h"

class mCLoggerBase
{
    public:
                 mCLoggerBase();
        virtual ~mCLoggerBase() = 0;

    public:
        mCLoggerBase( mCLoggerBase const & ) = delete;
        mCLoggerBase & operator = ( mCLoggerBase const & ) = delete;

    public:
        virtual void LogString( GELPCChar a_strMessage )     = 0;
        virtual void LogFormat( GELPCChar a_strFormat, ... ) = 0;
        virtual void PushIndent();
        virtual void PopIndent();
        void SetEnabled(GEBool a_bEnabled);

    protected:
        bCString Indent( GELPCChar a_strText );

    protected:
        GEBool m_bEnabled;

    private:
        GEUInt m_uCurrentIndent;
};

class mCFileLogger : public mCLoggerBase
{
    public:
        static mCFileLogger & GetInstance( GELPCChar a_strName );

    public:
                 mCFileLogger( GELPCChar a_strFile );
        virtual ~mCFileLogger();

    public:
        virtual void LogString( GELPCChar a_strMessage );
        virtual void LogFormat( GELPCChar a_strFormat, ... );
        virtual void LogFormatPrefix( GELPCChar a_strPrefix, GELPCChar a_strFormat, ... );
        FILE *       GetFile();

    private:
        FILE * m_pFile;
};

class mCStdLogger : public mCLoggerBase
{
    public:
                 mCStdLogger( GELPCChar a_strName );
        virtual ~mCStdLogger();

        virtual void LogString( GELPCChar a_strMessage );
        virtual void LogFormat( GELPCChar a_strFormat, ... );
};

template< typename T >
class mCLoggingAdmin
{
    public:
        static T &    GetLogger( GELPCChar a_strPath, GEBool a_bActive = true );
        static GEBool FreeLogger( T & a_Logger );

    private:
        static mCLoggingAdmin & GetLoggingAdmin();

    private:
        ~mCLoggingAdmin();

    private:
        bTPtrMap< bCString, T * > m_Loggers;
};

void           SetDefaultLogger( mCLoggerBase & a_Logger );
mCLoggerBase & GetDefaultLogger();

#include "Logging.inl"

#endif