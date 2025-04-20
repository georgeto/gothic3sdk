#pragma once

#include <FileSystem.h>

struct eSDirArchive
{
    GE_UNIMPL_STRUCT(eSDirArchive)
};

class GE_DLLIMPORT eCVirtualFileSystem : public bCFileSystem
{
    // clang-format off
    public: GEInt GetResult() const override;
    public: GEBool DeleteFileA(bCString const &) override;
    public: GEBool CopyFileA(bCString const &, bCString const &) override;
    public: GEBool RenameFile(bCString const &, bCString const &) override;
    public: GEBool MakePath(bCString &, bCString const &, bCString const &, bCString const &, bCString const &) override;
    public: GEBool ChangeDir(bCString const &) override;
    public: GEBool MakeDir(bCString const &) override;
    public: GEBool DeleteDir(bCString const &) override;
    // Lists all files under the specified root directory.
    public: GEBool FindFiles(bCString a_SearchRoot, bTObjArray<bCString> &o_FoundFiles) override;
    // Lists all directories under the specified root directory.
    public: GEBool FindDirectories(bCString a_SearchRoot, bTObjArray<bCString> &o_FoundDirectories) override;
    public: ~eCVirtualFileSystem() override;
    // clang-format on

  public:
    static eCVirtualFileSystem &GE_STDCALL GetInstance();

  public:
    eCVirtualFileSystem(eCVirtualFileSystem const &);
    eCVirtualFileSystem();

  public:
    eCVirtualFileSystem &operator=(eCVirtualFileSystem const &);

  public:
    GEUInt AddDirToCache(bTObjArray<eSDirArchive> const &);
    GEUInt AddDirToCache(bCString const &, GEUInt &);
    void Create();
    // a_Writeable: 0 -> Read, 1 -> ReadWrite
    IFFVirtualFile *CreateFileA(bCString const &, bEFileCreationMode, GEU8 a_Writeable);
    void Destroy();
    void EnableSaveMoundListFile(GEBool);
    GEBool ExistsFile(bCString const &);
    bCString GetCurrentDirPath();
    bCString GetFilePath(bCString const &);
    GEBool GetFilePath(bCString const &, bCString &);
    GEI64 GetFileSize(bCString const &);
    bCDateTime GetFileTime(bCString const &);
    bCString const &GetRootPath() const;
    bCString const &GetVirtualRootPath() const;
    void Invalidate();
    GEBool IsCompiledProjectFolder() const;
    GEUInt MountDir(bCString const &a_strMountPoint, bCString const &a_strDir,
                    bTObjArray<bCString> &o_arrNotUniqueFiles, GEBool a_bUseFpcFiles = GEFalse);
    GEBool MoveDir(bCString const &, bCString const &);
    GEBool RemoveDirFromCache(bCString const &);
    void SaveFilePathCacheDir(bCString const &);
    void SetRootPath(bCString const &);
    GEBool UmountDir(bCString const &);

  protected:
    void GetDirArchive(bCString const &, bTObjArray<eSDirArchive> &);
    void MakeNativeFilename(bCString &);
};
