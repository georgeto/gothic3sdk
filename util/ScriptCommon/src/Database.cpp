#include "Database.h"

#include <g3sdk/util/Util.h>

mCDatabase::mCDatabase(mCLoggerBase &a_Logger) : m_File(0), m_Logger(a_Logger), m_uLineNumber(0)
{}

mCDatabase::mCDatabase(GELPCChar a_strFile, mCLoggerBase &a_Logger) : m_File(0), m_Logger(a_Logger), m_uLineNumber(0)
{
    Open(a_strFile);
}

mCDatabase::~mCDatabase()
{
    Close();
}

void mCDatabase::Open(GELPCChar a_strFile)
{
    Close();
    m_strFile = a_strFile;
    m_File.Open(a_strFile, bEFileCreationMode_OpenExisting, 1);
    m_uLineNumber = 0;
}

void mCDatabase::Close()
{
    m_File.Close();
}

GEBool mCDatabase::NextLine()
{
    while (m_File.ReadLine(m_strLine))
    {
        m_uLineNumber++;
        m_strLine.Trim();
        if (m_strLine.IsEmpty() || m_strLine.Contains('#', 0))
            continue;

        m_arrLineEntries = SplitString(m_strLine, ":");
        return GETrue;
    }

    return GEFalse;
}

bCString const &mCDatabase::GetLine()
{
    return m_strLine;
}

void mCDatabase::SetLine(bCString const &a_strLine)
{
    if (a_strLine.IsEmpty() || a_strLine.Contains('#', 0))
    {
        m_strLine = "";
        m_arrLineEntries.Clear();
    }
    else
    {
        m_strLine = a_strLine;
        m_arrLineEntries = SplitString(m_strLine, ":");
    }
}

GEUInt mCDatabase::GetEntryCount() const
{
    return m_arrLineEntries.GetCount();
}

bCString const &mCDatabase::GetEntry(GEInt a_iIndex) const
{
    return m_arrLineEntries.GetAt(a_iIndex);
}

GEBool mCDatabase::IsTemplate(GEInt a_iIndex) const
{
    return IsTemplate(a_iIndex, "Unbekanntes Item");
}

GEBool mCDatabase::IsTemplate(GEInt a_iIndex, GELPCChar a_strDescription) const
{
    bCString strTemplate = GetEntry(a_iIndex);
    if (!Template(strTemplate).IsValid())
    {
        GetDefaultLogger().LogFormat("%s in %s(%d): %s\n", a_strDescription, m_strFile.GetText(), m_uLineNumber,
                                     strTemplate.GetText());
        return GEFalse;
    }

    return GETrue;
}

void mCDatabase::Log(GELPCChar a_strDescription, GELPCChar a_strValue) const
{
    m_Logger.LogFormat("%s in %s(%d): %s\n", a_strDescription, m_strFile.GetText(), m_uLineNumber, a_strValue);
}

void mCDatabase::LogIncorrectLine() const
{
    m_Logger.LogFormat("Fehlerhafte Zeile in %s(%d): %s\n", m_strFile.GetText(), m_uLineNumber, m_strLine.GetText());
}

void mCDatabase::LogIncorrectLine(GELPCChar a_strDescription) const
{
    m_Logger.LogFormat("%s in %s(%d): %s\n", a_strDescription, m_strFile.GetText(), m_uLineNumber, m_strLine.GetText());
}

bCString const &mCDatabase::operator[](GEInt a_iIndex) const
{
    return GetEntry(a_iIndex);
}
