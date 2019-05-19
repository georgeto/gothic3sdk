#include "Logging.h"

#include <cstdio>
#include "Util.h"

mCLoggerBase::mCLoggerBase() : m_uCurrentIndent(0), m_bEnabled(GETrue)
{
}

void mCLoggerBase::PushIndent()
{
    m_uCurrentIndent++;
}

void mCLoggerBase::PopIndent()
{
    if(m_uCurrentIndent > 0)
        m_uCurrentIndent--;
}

void mCLoggerBase::SetEnabled(GEBool a_bEnabled)
{
    m_bEnabled = a_bEnabled;
}

bCString mCLoggerBase::Indent(GELPCChar a_strText)
{
    bCString strIndent('\t', m_uCurrentIndent);
    bTObjArray<bCString> Splitted = SplitString(a_strText, "\n", GEFalse, GEFalse);
    for(GEInt i = 0; i < Splitted.GetCount(); i++)
    {
        if(!Splitted[i].IsEmpty())
            Splitted[i] = strIndent + Splitted[i];
    }

    return JoinString(Splitted, 0, "\n");
}

mCFileLogger & mCFileLogger::GetInstance(GELPCChar a_strName)
{
    return mCLoggingAdmin<mCFileLogger>::GetLogger(bCString("logs\\") + a_strName + ".log", GETrue);
}

mCFileLogger::mCFileLogger()
    : m_pFile(0)
{
}

mCFileLogger::mCFileLogger( GELPCChar a_strFile )
{
    m_pFile = fopen(a_strFile, "w");
}

void mCFileLogger::LogString(GELPCChar a_strMessage)
{
    if(!m_pFile || !m_bEnabled)
        return;
    bCString strMessage = Indent(a_strMessage);
    fwrite(strMessage, 1, strlen(strMessage), m_pFile);
    if(ferror(m_pFile))
        perror ("The following error occurred");
    fflush(m_pFile);
}

void mCFileLogger::LogFormat(GELPCChar a_strFormat, ...)
{
    if(!m_pFile || !m_bEnabled)
        return;

    bCString strFormat = Indent(a_strFormat);
    va_list Arguments;
    va_start(Arguments, a_strFormat);
    vfprintf(m_pFile, strFormat, Arguments);
    va_end(Arguments);
    fflush(m_pFile);
}

void mCFileLogger::LogFormatPrefix(GELPCChar a_strPrefix, GELPCChar a_strFormat, ...)
{
    if(!m_pFile || !m_bEnabled)
        return;

    bCString strFormat = a_strPrefix + Indent(a_strFormat);
    va_list Arguments;
    va_start(Arguments, a_strFormat);
    vfprintf(m_pFile, strFormat, Arguments);
    va_end(Arguments);
    fflush(m_pFile);
}

void mCFileLogger::Free()
{
    if(m_pFile)
        fclose(m_pFile);
}

FILE * mCFileLogger::GetFile()
{
    return m_pFile;
}

mCStdLogger::mCStdLogger()
{
}

mCStdLogger::mCStdLogger(GELPCChar)
{

}

void mCStdLogger::LogString(GELPCChar a_strMessage)
{
    if (!m_bEnabled)
        return;

    std::printf("%s", Indent(a_strMessage).GetText());
}

void mCStdLogger::LogFormat(GELPCChar a_strFormat, ...)
{
    if (!m_bEnabled)
        return;

    va_list Arguments;
    va_start(Arguments, a_strFormat);
    std::vprintf(Indent(a_strFormat).GetText(), Arguments);
    va_end(Arguments);
}

void mCStdLogger::Free()
{
}

static mCLoggerBase * g_pDefaultLogger = &mCLoggingAdmin<mCStdLogger>::GetLogger("Default");

void SetDefaultLogger(mCLoggerBase & a_Logger)
{
    g_pDefaultLogger = &a_Logger;
}

mCLoggerBase & GetDefaultLogger()
{
    return *g_pDefaultLogger;
}