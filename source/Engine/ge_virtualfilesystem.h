#ifndef GE_VIRTUALFILESYSTEM_H_INCLUDED
#define GE_VIRTUALFILESYSTEM_H_INCLUDED

struct eSDirArchive;

class GE_DLLIMPORT eCVirtualFileSystem :
    public bCFileSystem
{
    public: virtual GEInt  GetResult( void ) const;
    public: virtual GEBool DeleteFileA( bCString const & );
    public: virtual GEBool CopyFileA( bCString const &, bCString const & );
    public: virtual GEBool RenameFile( bCString const &, bCString const & );
    public: virtual GEBool MakePath( bCString &, bCString const &, bCString const &, bCString const &, bCString const & );
    public: virtual GEBool ChangeDir( bCString const & );
    public: virtual GEBool MakeDir( bCString const & );
    public: virtual GEBool DeleteDir( bCString const & );
    // Lists all files under the specified root directory.
    public: virtual GEBool FindFiles( bCString a_SearchRoot, bTObjArray<bCString> & o_FoundFiles );
    // Lists all directories under the specified root directory.
    public: virtual GEBool FindDirectories( bCString a_SearchRoot, bTObjArray<bCString> & o_FoundDirectories );
    public: virtual       ~eCVirtualFileSystem( void );
    public: using bCFileSystem::GetCurrentDirPath;
    public: using bCFileSystem::ExistsFile;
    public: using bCFileSystem::GetFileSize;
    public: using bCFileSystem::GetFileTime;

    public:
        static eCVirtualFileSystem & GE_STDCALL GetInstance( void );

    public:
        eCVirtualFileSystem( eCVirtualFileSystem const & );
        eCVirtualFileSystem( void );

    public:
        eCVirtualFileSystem & operator = ( eCVirtualFileSystem const & );

    public:
        GEUInt           AddDirToCache( bTObjArray<eSDirArchive> const & );
        GEUInt           AddDirToCache( bCString const &, GEUInt & );
        void             Create( void );
        IFFVirtualFile * CreateFileA( bCString const &, bEFileCreationMode, GEU8 );
        void             Destroy( void );
        void             EnableSaveMoundListFile( GEBool );
        GEBool           ExistsFile( bCString const & );
        bCString         GetCurrentDirPath( void );
        bCString         GetFilePath( bCString const & );
        GEBool           GetFilePath( bCString const &, bCString & );
        GEI64            GetFileSize( bCString const & );
        bCDateTime       GetFileTime( bCString const & );
        bCString const & GetRootPath( void ) const;
        bCString const & GetVirtualRootPath( void ) const;
        void             Invalidate( void );
        GEBool           IsCompiledProjectFolder( void ) const;
        GEUInt           MountDir( bCString const & a_strMountPoint, bCString const & a_strDir, bTObjArray<bCString> & o_arrNotUniqueFiles, GEBool a_bUseFpcFiles = GEFalse );
        GEBool           MoveDir( bCString const &, bCString const & );
        GEBool           RemoveDirFromCache( bCString const & );
        void             SaveFilePathCacheDir( bCString const & );
        void             SetRootPath( bCString const & );
        GEBool           UmountDir( bCString const & );

    protected:
        void GetDirArchive( bCString const &, bTObjArray<eSDirArchive> & );
        void MakeNativeFilename( bCString & );

};

#endif
