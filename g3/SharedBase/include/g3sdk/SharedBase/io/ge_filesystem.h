#pragma once

#include <SharedBase/container/array/ge_objarray.h>
#include <SharedBase/kernel/system/ge_datetime.h>
#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_string.h>
#include <SharedBase/types/ge_types.h>

class GE_DLLIMPORT bCFileSystem
{
    // clang-format off
    public: virtual GEInt GetResult() const;
    public: virtual bCString GetCurrentDirPath() const;
    public: virtual GEBool DeleteFileA(bCString const &);
    public: virtual GEBool CopyFileA(bCString const &, bCString const &);
    public: virtual GEBool RenameFile(bCString const &, bCString const &);
    public: virtual GEBool ExistsFile(bCString const &) const;
    public: virtual GEI64 GetFileSize(bCString const &) const;
    public: virtual bCDateTime GetFileTime(bCString const &) const;
    public: virtual GEBool MakeAbsolutePath(bCString &, bCString const &);
    public: virtual GEBool MakePath(bCString &, bCString const &, bCString const &, bCString const &, bCString const &);
    public: virtual GEBool SplitPath(bCString const &, bCString &, bCString &, bCString &, bCString &);
    public: virtual GEBool MakePathDir(bCString &);
    public: virtual GEBool ChangeDir(bCString const &);
    public: virtual GEBool MakeDir(bCString const &);
    public: virtual GEBool DeleteDir(bCString const &);
    public: virtual GEBool FindFiles(bCString, bTObjArray<bCString> &);
    public: virtual GEBool FindDirectories(bCString, bTObjArray<bCString> &);
    public: virtual ~bCFileSystem();
    // clang-format on

  public:
    bCFileSystem(bCFileSystem const &);
    bCFileSystem();

  public:
    bCFileSystem &operator=(bCFileSystem const &);

  public:
    void MakeCommonFilename(bCString &);
};
