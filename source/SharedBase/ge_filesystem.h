#ifndef GE_FILESYSTEM_H_INCLUDED
#define GE_FILESYSTEM_H_INCLUDED

class GE_DLLIMPORT bCFileSystem
{
    public: virtual GEInt      GetResult( void ) const;
    public: virtual bCString   GetCurrentDirPath( void ) const;
    public: virtual GEBool     DeleteFileA( bCString const & );
    public: virtual GEBool     CopyFileA( bCString const &, bCString const & );
    public: virtual GEBool     RenameFile( bCString const &, bCString const & );
    public: virtual GEBool     ExistsFile( bCString const & ) const;
    public: virtual GEI64      GetFileSize( bCString const & ) const;
    public: virtual bCDateTime GetFileTime( bCString const & ) const;
    public: virtual GEBool     MakeAbsolutePath( bCString &, bCString const & );
    public: virtual GEBool     MakePath( bCString &, bCString const &, bCString const &, bCString const &, bCString const & );
    public: virtual GEBool     SplitPath( bCString const &, bCString &, bCString &, bCString &, bCString & );
    public: virtual GEBool     MakePathDir( bCString & );
    public: virtual GEBool     ChangeDir( bCString const & );
    public: virtual GEBool     MakeDir( bCString const & );
    public: virtual GEBool     DeleteDir( bCString const & );
    public: virtual GEBool     FindFiles( bCString, bTObjArray<bCString> & );
    public: virtual GEBool     FindDirectories( bCString, bTObjArray<bCString> & );
    public: virtual           ~bCFileSystem( void );

    public:
        bCFileSystem( bCFileSystem const & );
        bCFileSystem( void );

    public:
        bCFileSystem & operator = ( bCFileSystem const & );

    public:
        void MakeCommonFilename( bCString & );

};

#endif
