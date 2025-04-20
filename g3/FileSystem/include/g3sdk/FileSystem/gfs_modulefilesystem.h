#pragma once

#include <SharedBase.h>

enum EFFMoveMethod
{
    EFFMoveMethod_Begin = 0,
    EFFMoveMethod_Current = 1,
    EFFMoveMethod_End = 2,
};

class IFFVirtualStream : public virtual IFFUnknown
{
  public:
    virtual GEI64 GetStreamSize() = 0;
    // If the function fails, the return value is false. To get extended error information, call GetLastError.
    virtual GEBool GetStreamPosition(GEI64 *o_pStreamPosition) = 0;
    // If the function fails, the return value is false. To get extended error information, call GetLastError.
    virtual GEBool SetStreamPosition(GEI64 a_StreamPosition, EFFMoveMethod a_MoveMethod) = 0;
    // Return the number of read bytes.
    virtual GEU32 Read(GELPVoid o_pBuffer, GEU32 a_NumOfBytesToRead) = 0;
    // Return the number of written bytes.
    virtual GEU32 Write(GELPCVoid a_pBuffer, GEU32 a_NumOfBytesToWrite) = 0;
};

class IFFVirtualFile : public virtual IFFVirtualStream
{
  public:
    // https://docs.microsoft.com/en-us/windows/win32/fileio/file-attribute-constants
    // FILE_ATTRIBUTE_*
    virtual GEU32 GetFileAttributes() = 0;
    // Returns true for physical file, but false for virtual file. So maybe GetPhysicalFileName/Path?
    virtual GEBool GetFileName(bCString &o_strFileName) = 0;         // Called from eCVirtualFile::GetFileName
    virtual GEBool GetPhysicalFilePath(bCString &o_strFileName) = 0; // Called from eCVirtualFile::GetPhysicalFilePath
    virtual GEBool GetCreationTime(bCDateTime &o_CreationTime) = 0;
    virtual GEBool GetLastWriteTime(bCDateTime &o_CreationTime) = 0;
    virtual GEBool GetLastAccessTime(bCDateTime &o_CreationTime) = 0;
    virtual GEBool SetFileAttributes(GEU32 a_FileAttributes) = 0;
};

class IFFPackFile : public virtual IFFUnknown
{
  public:
    virtual void __purecall_1() = 0;
    virtual void __purecall_2() = 0;
    virtual void __purecall_3() = 0;
    virtual void __purecall_4() = 0;
};

enum EFFFileCreate
{
    EFFFileCreate_CreateAlways = 1,
    EFFFileCreate_CreateNew = 2,
    EFFFileCreate_OpenAlways = 3,
    EFFFileCreate_OpenExisiting = 4,
    EFFFileCreate_TruncateExisiting = 5,
};

enum EFFFileAccess
{
    EFFFileAccess_Read = 1,
    EFFFileAccess_Write = 2,
    EFFFileAccess_ReadWrite = 3,
};

struct SFFFileTime
{
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
};

// TODO: Maybe remove some of these, see eCVirtualFileFind for the known/used values!
enum EFFFileAttributes
{
    /*
    A file or directory that is an archive file or directory. Applications typically use this attribute to mark files
    for backup or removal .
    */
    EFFFileAttributes_Archive = 0x20,
    /*
    A file or directory that is compressed. For a file, all of the data in the file is compressed. For a directory,
    compression is the default for newly created files and subdirectories.
    */
    EFFFileAttributes_Compressed = 0x800,
    /*
    This value is reserved for system use.
    */
    EFFFileAttributes_Device = 0x40,
    /*
    The handle that identifies a directory.
    */
    EFFFileAttributes_Directory = 0x10,
    /*
    A file or directory that is encrypted. For a file, all data streams in the file are encrypted. For a directory,
    encryption is the default for newly created files and subdirectories.
    */
    EFFFileAttributes_Encrypted = 0x4000,
    /*
    The file or directory is hidden. It is not included in an ordinary directory listing.
    */
    EFFFileAttributes_Hidden = 0x2,
    /*
    A file that does not have other attributes set. This attribute is valid only when used alone.
    */
    EFFFileAttributes_Normal = 0x80,
    /*
    The file or directory is not to be indexed by the content indexing service.
    */
    EFFFileAttributes_Not_content_indexed = 0x2000,
    /*
    The data of a file is not available immediately. This attribute indicates that the file data is physically moved to
    offline storage. This attribute is used by Remote Storage, which is the hierarchical storage management software.
    Applications should not arbitrarily change this attribute.
    */
    EFFFileAttributes_Offline = 0x1000,
    /*
    A file that is read-only. Applications can read the file, but cannot write to it or delete it. This attribute is not
    honored on directories. For more information, see You cannot view or change the Read-only or the System attributes
    of folders in Windows Server 2003, in Windows XP, in Windows Vista or in Windows 7.
    */
    EFFFileAttributes_Readonly = 0x1,
    /*
    When this attribute is set, it means that the file or directory is not fully present locally. For a file that means
    that not all of its data is on local storage (e.g. it may be sparse with some data still in remote storage). For a
    directory it means that some of the directory contents are being virtualized from another location. Reading the file
    / enumerating the directory will be more expensive than normal, e.g. it will cause at least some of the
    file/directory content to be fetched from a remote store. Only kernel-mode callers can set this bit.
    */
    EFFFileAttributes_Recall_on_data_access = 0x400000,
    /*
    This attribute only appears in directory enumeration classes (FILE_DIRECTORY_INFORMATION, FILE_BOTH_DIR_INFORMATION,
    etc.). When this attribute is set, it means that the file or directory has no physical representation on the local
    system; the item is virtual. Opening the item will be more expensive than normal, e.g. it will cause at least some
    of it to be fetched from a remote store.
    */
    EFFFileAttributes_Recall_on_open = 0x40000,
    /*
    A file or directory that has an associated reparse point, or a file that is a symbolic link.
    */
    EFFFileAttributes_Reparse_point = 0x400,
    /*
    A file that is a sparse file.
    */
    EFFFileAttributes_Sparse_file = 0x200,
    /*
    A file or directory that the operating system uses a part of, or uses exclusively.
    */
    EFFFileAttributes_System = 0x4,
    /*
    A file that is being used for temporary storage. File systems avoid writing data back to mass storage if sufficient
    cache memory is available, because typically, an application deletes a temporary file after the handle is closed. In
    that scenario, the system can entirely avoid writing the data. Otherwise, the data is written after the handle is
    closed.
    */
    EFFFileAttributes_Temporary = 0x100,
    /*
    This value is reserved for system use.
    */
    EFFFileAttributes_Virtual = 0x10000,

    EFFFileAttributes_Deleted = 0x8000,
    EFFFileAttributes_Packed = 0x20000,
};

struct SFFFileFind
{
    SFFFileTime TimeCreated;
    SFFFileTime TimeLastAccessed;
    SFFFileTime TimeLastModified;
    // Directly copied from Win32 FindFile data
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    // See https://docs.microsoft.com/en-us/windows/win32/fileio/file-attribute-constants
    EFFFileAttributes dwFileAttributes;
    bCString cFileName;
    // ---
    bCString PhysicalFilePath;
};

struct SFFMountInfo;

class GE_DLLIMPORT IFFModuleFileSystem : public virtual IFFUnknown
{
    // clang-format off
    public: virtual GEInt GetVolumeCount() const = 0;
    public: virtual GEBool GetVolumeRootPath(GEInt, bCString &) const = 0;
    public: virtual GEBool CreateVolume(bCString const &) = 0;
    public: virtual GEBool GetMountInformation(bCString const &, SFFMountInfo &) const = 0;
    public: virtual GEBool GetCurrentDirectoryA(bCString &) const = 0;
    public: virtual GEBool SetCurrentDirectoryA(bCString const &) = 0;
    public: virtual GEBool CreateDirectoryA(bCString const &) = 0;
    public: virtual GEBool RemoveDirectoryA(bCString const &) = 0;
    public: virtual GEBool MountDirectory(bCString const &, bCString const &) = 0;
    public: virtual GEBool UnmountDirectory(bCString const &) = 0;
    public: virtual IFFPackFile * CreatePackFile() = 0;
    public: virtual GEBool MountPackFile(bCString const &, bCString const &) = 0;
    public: virtual GEBool UnmountPackFiles(bCString const &) = 0;
    public: virtual GEU32 GetFileAttributesA(bCString const &) const = 0;
    public: virtual GEBool SetFileAttributesA(bCString const &, GEU32) = 0;
    public: virtual IFFVirtualFile * CreateFileA(bCString const &, EFFFileCreate, EFFFileAccess, GEU32) = 0;
    public: virtual GEBool CopyFileA(bCString const &, bCString const &, GEBool) = 0;
    public: virtual GEBool MoveFileA(bCString const &, bCString const &, GEBool) = 0;
    public: virtual GEBool DeleteFileA(bCString const &) = 0;
    public: virtual GELPVoid FindFirstFileA(bCString const &, SFFFileFind &) = 0;
    public: virtual GEBool FindNextFileA(GELPVoid, SFFFileFind &) const = 0;
    public: virtual GEBool FindClose(GELPVoid) const = 0;
    // clang-format on
};
