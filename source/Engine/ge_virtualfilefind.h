#ifndef GE_VIRTUALFILEFIND_H_INCLUDED
#define GE_VIRTUALFILEFIND_H_INCLUDED

class SFFFileTime;

class GE_DLLIMPORT eCVirtualFileFind
{
    public: virtual ~eCVirtualFileFind( void );

    public:
        eCVirtualFileFind( eCVirtualFileFind const & );
        eCVirtualFileFind( void );

    public:
        eCVirtualFileFind & operator = ( eCVirtualFileFind const & );

    public:
        void     Close( void );
        GEBool   FindFile( bCString const & );
        GEBool   FindNext( void );
        bCString GetFileName( void ) const;
        bCString GetFilePath( void ) const;
        bCString GetFileTitle( void ) const;
        bCString GetPhysicleFilePath( void ) const;
        bCString GetRoot( void ) const;
        GEBool   GetTimeCreated( SFFFileTime & ) const;
        GEBool   GetTimeLastAccessed( SFFFileTime & ) const;
        GEBool   GetTimeLastModified( SFFFileTime & ) const;
        GEBool   IsArchive( void ) const;
        GEBool   IsCompressed( void ) const;
        GEBool   IsDeleted( void ) const;
        GEBool   IsDirectory( void ) const;
        GEBool   IsDots( void ) const;
        GEBool   IsEncrypted( void ) const;
        GEBool   IsHidden( void ) const;
        GEBool   IsPacked( void ) const;
        GEBool   IsReadOnly( void ) const;
        GEBool   IsSystem( void ) const;
        GEBool   IsTemporary( void ) const;
        GEBool   IsVirtual( void ) const;
        GEBool   MatchesMask( GEU32 ) const;

    protected:
        void Invalidate( void );

};

#endif
