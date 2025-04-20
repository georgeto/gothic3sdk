#pragma once

#include <g3sdk/SharedBase.h>

#include <stdio.h>

class mCLoggerBase
{
  public:
    mCLoggerBase();
    virtual ~mCLoggerBase() = 0;

  public:
    mCLoggerBase(mCLoggerBase const &) = delete;
    mCLoggerBase &operator=(mCLoggerBase const &) = delete;

  public:
    virtual void LogString(GELPCChar a_strMessage) = 0;
    virtual void LogFormat(GELPCChar a_strFormat, ...) = 0;
    virtual void PushIndent();
    virtual void PopIndent();
    void SetEnabled(GEBool a_bEnabled);

  protected:
    bCString Indent(GELPCChar a_strText);

  protected:
    GEBool m_bEnabled;

  private:
    GEUInt m_uCurrentIndent;
};

class mCFileLoggerBase : public mCLoggerBase
{
  public:
    virtual FILE *GetFile() = 0;
};

class mCFileLogger : public mCFileLoggerBase
{
  public:
    static mCFileLogger &GetInstance(GELPCChar a_strName);

  public:
    mCFileLogger(GELPCChar a_strFile);
    virtual ~mCFileLogger();

  public:
    virtual void LogString(GELPCChar a_strMessage);
    virtual void LogFormat(GELPCChar a_strFormat, ...);
    virtual void LogFormatPrefix(GELPCChar a_strPrefix, GELPCChar a_strFormat, ...);
    virtual FILE *GetFile();

  private:
    FILE *m_pFile;
};

class mCStdLogger : public mCFileLoggerBase
{
  public:
    mCStdLogger(GELPCChar a_strName);
    virtual ~mCStdLogger();

    virtual void LogString(GELPCChar a_strMessage);
    virtual void LogFormat(GELPCChar a_strFormat, ...);
    virtual FILE *GetFile();
};

template <typename T>
class mCLoggingAdmin
{
  public:
    static T &GetLogger(GELPCChar a_strPath, GEBool a_bActive = true);
    static GEBool FreeLogger(T &a_Logger);

  private:
    static mCLoggingAdmin &GetLoggingAdmin();

  private:
    ~mCLoggingAdmin();

  private:
    bTPtrMap<bCString, T *> m_Loggers;
};

void SetDefaultLogger(mCLoggerBase &a_Logger);
mCLoggerBase &GetDefaultLogger();
bCString GetAndCreateLogFilePath(GELPCChar a_strRelativeLogDir, GELPCChar a_strName);

#include "Logging.inl"
