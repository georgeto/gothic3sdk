#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCFilePathCache
{
  public:
    eCFilePathCache(eCFilePathCache const &);
    eCFilePathCache();
    ~eCFilePathCache();

  public:
    eCFilePathCache &operator=(eCFilePathCache const &);

  public:
    void Clear();
    GEBool ExistsFileName(bCString const &a_strName);
    GEBool FindDirectories(bCString, bTObjArray<bCString> &a_arrDirPatterns);
    GEBool FindFiles(bCString, bTObjArray<bCString> &a_arrFilePatterns);
    GEBool GetDir(bCString const &a_strName, GEInt &o_iDir);
    GEBool GetDirPath(GEInt a_iDir, bCString &o_strPath);
    GEBool GetFilePath(bCString const &a_strName, bCString &o_strPath);
    GEInt GetRootDir() const;
    GEInt InsertDirPath(bCString const &a_strPath);
    GEInt InsertDirPath(bCString const &a_strPath, GEInt a_iParentDir);
    GEBool InsertFileName(bCString const &a_strName, GEInt a_iParentDir);
    GEBool InsertFilePath(bCString const &a_strName);
    GEBool LoadFilePathCache(bCString const &a_strName);
    GEBool RemoveDirPath(bCString const &a_strName);
    GEBool RemoveFileName(bCString const &a_strName);
    GEBool SaveFilePathCache(bCString const &a_strName);

  protected:
    void Invalidate();
};
