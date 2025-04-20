#pragma once

#include <SharedBase.h>

class eCUnicodeConfigFile_KeyObject;

class GE_DLLIMPORT eCUnicodeConfigFile_SectionObject
{
  public:
    eCUnicodeConfigFile_SectionObject(eCUnicodeConfigFile_SectionObject &);
    eCUnicodeConfigFile_SectionObject();
    ~eCUnicodeConfigFile_SectionObject();

  public:
    eCUnicodeConfigFile_SectionObject const &operator=(eCUnicodeConfigFile_SectionObject const &);
    bCUnicodeString &operator[](bCUnicodeString const &);
    bCUnicodeString const &operator[](bCUnicodeString const &) const;

  public:
    void Clear();
    void CopyFrom(eCUnicodeConfigFile_SectionObject const &);
    void Create();
    void Destroy();
    GEInt GetKeyCount() const;
    eCUnicodeConfigFile_KeyObject const *GetKeyObject(GEInt) const;
    bCUnicodeString const &GetSectionName() const;
    bCUnicodeString const &GetValue(bCUnicodeString const &) const;
    GEBool GetValue(bCUnicodeString const &, bCUnicodeString &) const;
    void Invalidate();
    GEBool IsValidKey(GEInt) const;
    GEBool RemoveKey(bCUnicodeString const &);
    GEBool RemoveValue(bCUnicodeString const &);
    void Write(bCOStream &);

  protected:
    GEInt GetKeyIndex(bCUnicodeString const &) const;
    eCUnicodeConfigFile_KeyObject &InsertNewEmptyKey();
    GEBool IsValidKey(bCUnicodeString const &) const;
    GEBool SetKey(bCUnicodeString const &, bCUnicodeString const &);
    GEBool SetKey(bCUnicodeString const &);
    void SetSectionName(bCUnicodeString const &);
    void SetWhitespaces(GEU16);
};
