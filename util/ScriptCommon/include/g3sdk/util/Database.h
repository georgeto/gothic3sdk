#pragma once

#include <g3sdk/Script.h>
#include <g3sdk/util/Logging.h>

class mCDatabase
{
  public:
    mCDatabase(mCLoggerBase &a_Logger);
    mCDatabase(GELPCChar a_strFile, mCLoggerBase &a_Logger);
    ~mCDatabase();

  public:
    void Open(GELPCChar a_strFile);
    void Close();
    GEBool NextLine();
    bCString const &GetLine();
    void SetLine(bCString const &a_strLine);
    GEUInt GetEntryCount() const;
    bCString const &GetEntry(GEInt a_iIndex) const;
    GEBool IsTemplate(GEInt a_iIndex) const;
    GEBool IsTemplate(GEInt a_iIndex, GELPCChar a_strDescription) const;
    void Log(GELPCChar a_strDescription, GELPCChar a_strValue) const;
    void LogIncorrectLine() const;
    void LogIncorrectLine(GELPCChar a_strDescription) const;

  public:
    bCString const &operator[](GEInt a_iIndex) const;

  private:
    mCLoggerBase &m_Logger;
    eCVirtualFile m_File;
    bCString m_strFile;
    bCString m_strLine;
    GEUInt m_uLineNumber;
    bTObjArray<bCString> m_arrLineEntries;

  private:
    mCDatabase(mCDatabase const &);

  private:
    mCDatabase &operator=(mCDatabase const &);
};
