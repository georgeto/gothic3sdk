#include "Logging.h"

#include <cstdio>

#include <Shlobj.h>

mCLoggerBase::mCLoggerBase() : m_uCurrentIndent(0), m_bEnabled(GETrue)
{}

mCLoggerBase::~mCLoggerBase()
{}

void mCLoggerBase::PushIndent()
{
    m_uCurrentIndent++;
}

void mCLoggerBase::PopIndent()
{
    if (m_uCurrentIndent > 0)
        m_uCurrentIndent--;
}

void mCLoggerBase::SetEnabled(GEBool a_bEnabled)
{
    m_bEnabled = a_bEnabled;
}

bCString mCLoggerBase::Indent(GELPCChar a_strText)
{
    if (m_uCurrentIndent == 0)
        return a_strText;

    bCString strText(a_strText);
    bCString strResult;
    bCString strIndent('\t', m_uCurrentIndent);
    GEInt iWordCount = strText.CountWords("\n");
    for (GEInt i = 0; i < iWordCount; i++)
    {
        if (i > 0)
            strResult += "\n";

        bCString SplitPart;
        strText.GetWord(i, "\n", SplitPart, GEFalse, GEFalse);
        if (!SplitPart.IsEmpty())
            strResult += strIndent;

        strResult += SplitPart;
    }

    return strResult;
}

mCFileLogger &mCFileLogger::GetInstance(GELPCChar a_strName)
{
    return mCLoggingAdmin<mCFileLogger>::GetLogger(bCString("logs\\") + a_strName + ".log", GETrue);
}

mCFileLogger::mCFileLogger(GELPCChar a_strFile)
{
    m_pFile = fopen(a_strFile, "w");
}

mCFileLogger::~mCFileLogger()
{
    if (m_pFile)
    {
        fclose(m_pFile);
        m_pFile = nullptr;
    }
}

void mCFileLogger::LogString(GELPCChar a_strMessage)
{
    if (!m_pFile || !m_bEnabled)
        return;
    bCString strMessage = Indent(a_strMessage);
    fwrite(strMessage, 1, strlen(strMessage), m_pFile);
    if (ferror(m_pFile))
        perror("The following error occurred");
    fflush(m_pFile);
}

void mCFileLogger::LogFormat(GELPCChar a_strFormat, ...)
{
    if (!m_pFile || !m_bEnabled)
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
    if (!m_pFile || !m_bEnabled)
        return;

    bCString strFormat = a_strPrefix + Indent(a_strFormat);
    va_list Arguments;
    va_start(Arguments, a_strFormat);
    vfprintf(m_pFile, strFormat, Arguments);
    va_end(Arguments);
    fflush(m_pFile);
}

FILE *mCFileLogger::GetFile()
{
    return m_pFile;
}

mCStdLogger::mCStdLogger(GELPCChar)
{}

mCStdLogger::~mCStdLogger()
{}

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

FILE *mCStdLogger::GetFile()
{
    return stdout;
}

static mCLoggerBase *g_pDefaultLogger = &mCLoggingAdmin<mCStdLogger>::GetLogger("Default");

void SetDefaultLogger(mCLoggerBase &a_Logger)
{
    g_pDefaultLogger = &a_Logger;
}

mCLoggerBase &GetDefaultLogger()
{
    return *g_pDefaultLogger;
}

bCString GetAndCreateLogFilePath(GELPCChar a_strRelativeLogDir, GELPCChar a_strName)
{
    CHAR szPath[MAX_PATH];
    if (SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, 0, szPath) != S_OK)
        return "";

    bCString GothicUserDir = bCString(szPath) + "\\Gothic3\\";
    CreateDirectory(GothicUserDir, NULL);
    bCString LogDir = GothicUserDir + a_strRelativeLogDir + "\\";
    CreateDirectory(LogDir, NULL);

    return LogDir + a_strName;
}
