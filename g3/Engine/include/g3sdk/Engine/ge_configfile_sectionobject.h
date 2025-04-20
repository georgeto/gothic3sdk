#pragma once

#include <Engine/ge_configfile_keyobject.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCConfigFile_SectionObject
{
  public:
    eCConfigFile_SectionObject(eCConfigFile_SectionObject &);
    eCConfigFile_SectionObject();
    ~eCConfigFile_SectionObject();

  public:
    eCConfigFile_SectionObject const &operator=(eCConfigFile_SectionObject const &);
    bCString &operator[](bCString const &);
    bCString const &operator[](bCString const &) const;

  public:
    void Clear();
    void CopyFrom(eCConfigFile_SectionObject const &);
    void Create();
    void Destroy();
    GEInt GetKeyCount() const;
    eCConfigFile_KeyObject const *GetKeyObject(GEInt) const;
    bCString const &GetSectionName() const;
    bCString const &GetValue(bCString const &) const;
    GEBool GetValue(bCString const &, bCString &) const;
    void Invalidate();
    GEBool IsValidKey(GEInt) const;
    GEBool RemoveKey(bCString const &);
    GEBool RemoveValue(bCString const &);
    void Write(bCOStream &);

  protected:
    GEInt GetKeyIndex(bCString const &) const;
    eCConfigFile_KeyObject &InsertNewEmptyKey();
    GEBool IsValidKey(bCString const &) const;
    GEBool SetKey(bCString const &, bCString const &);
    GEBool SetKey(bCString const &);
    void SetSectionName(bCString const &);
    void SetWhitespaces(GEU16);
};
