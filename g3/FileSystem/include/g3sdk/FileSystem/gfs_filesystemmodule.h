#pragma once

#include <FileSystem/gfs_modulefilesystem.h>

#include <SharedBase.h>

class GE_DLLIMPORT CFFFileSystemModule : public CFFUnknown, public virtual IFFModuleFileSystem
{
    // clang-format off
    protected: virtual GEU32 OnCreate();
    protected: virtual void OnDestroy();
    public: virtual GEU32 GetLastError() const;
    public: virtual void ReleasePackFile(IFFPackFile *&);
    // Overrides for CFFUnknown
    public: ~CFFFileSystemModule() override;
    // Overrides for IFFUnknown
    public: GEU32 AddRef() override;
    public: GEU32 Release() override;
    public: GEU32 QueryInterface(FFGUID const &, GELPVoid*) override;
    // Overrides for IFFModuleFileSystem
    public: GEInt GetVolumeCount() const override;
    public: GEBool GetVolumeRootPath(GEInt, bCString &) const override;
    public: GEBool CreateVolume(bCString const &) override;
    public: GEBool GetMountInformation(bCString const &, SFFMountInfo &) const override;
    public: GEBool GetCurrentDirectoryA(bCString &) const override;
    public: GEBool SetCurrentDirectoryA(bCString const &) override;
    public: GEBool CreateDirectoryA(bCString const &) override;
    public: GEBool RemoveDirectoryA(bCString const &) override;
    public: GEBool MountDirectory(bCString const &, bCString const &) override;
    public: GEBool UnmountDirectory(bCString const &) override;
    public: IFFPackFile * CreatePackFile() override;
    public: GEBool MountPackFile(bCString const &, bCString const &) override;
    public: GEBool UnmountPackFiles(bCString const &) override;
    public: GEU32 GetFileAttributesA(bCString const &) const override;
    public: GEBool SetFileAttributesA(bCString const &, GEU32) override;
    public: IFFVirtualFile * CreateFileA(bCString const &, EFFFileCreate, EFFFileAccess, GEU32) override;
    public: GEBool CopyFileA(bCString const &, bCString const &, GEBool) override;
    public: GEBool MoveFileA(bCString const &, bCString const &, GEBool) override;
    public: GEBool DeleteFileA(bCString const &) override;
    public: GELPVoid FindFirstFileA(bCString const &, SFFFileFind &) override;
    public: GEBool FindNextFileA(GELPVoid, SFFFileFind &) const override;
    public: GEBool FindClose(GELPVoid) const override;
    // clang-format on

  public:
    static CFFFileSystemModule &GE_STDCALL GetInstance();

  public:
    CFFFileSystemModule(CFFFileSystemModule const &);

  public:
    CFFFileSystemModule &operator=(CFFFileSystemModule const &);

  protected:
    CFFFileSystemModule();

  protected:
    GEBool Create();
    void Destroy();
};
