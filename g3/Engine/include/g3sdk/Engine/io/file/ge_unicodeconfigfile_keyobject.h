#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCUnicodeConfigFile_KeyObject
{
  public:
    eCUnicodeConfigFile_KeyObject(eCUnicodeConfigFile_KeyObject &);
    eCUnicodeConfigFile_KeyObject(bCUnicodeString const &, bCUnicodeString const &, bCUnicodeString const &);
    eCUnicodeConfigFile_KeyObject(bCUnicodeString const &, bCUnicodeString const &);
    explicit eCUnicodeConfigFile_KeyObject(bCUnicodeString const &);
    eCUnicodeConfigFile_KeyObject();
    ~eCUnicodeConfigFile_KeyObject();

  public:
    eCUnicodeConfigFile_KeyObject const &operator=(eCUnicodeConfigFile_KeyObject const &);

  public:
    void Clear();
    void CopyFrom(eCUnicodeConfigFile_KeyObject const &);
    void Create();
    void Destroy();
    bCUnicodeString const &GetComment() const;
    bCUnicodeString const &GetKey() const;
    bCUnicodeString &GetValue();
    bCUnicodeString const &GetValue() const;
    GEBool HasKeyOnly() const;
    void Invalidate();
    GEBool IsComment() const;
    GEBool IsEmpty() const;
    void SetComment(bCUnicodeString const &);
    void SetKey(bCUnicodeString const &);
    void SetValue(bCUnicodeString const &);
    void Write(bCOStream &);
};
