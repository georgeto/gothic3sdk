#ifndef GE_VIRTUALFILE_H_INCLUDED
#define GE_VIRTUALFILE_H_INCLUDED

class IFFVirtualFile;

class GE_DLLIMPORT eCVirtualFile :
    public bCFile
{
    public: virtual GEBool   IsEof( void ) const;
    public: virtual bCString GetFileName( void ) const;
    public: virtual GEBool   IsReadOnly( void ) const;
    public: virtual void     SetReadOnly( GEBool );
    public: using bCFile::Open;
    public: virtual GEBool   Open( bCString const &, bEFileCreationMode, GEU8 a_u8ReadOnly );
    public: using bCIStream::Read;
    public: virtual GEU32    Read( GELPVoid, GEU32 );
    public: virtual         ~eCVirtualFile( void );
    public: virtual GEI64    GetPosition( void ) const;
    public: using bCFile::Seek;
    public: virtual GEBool   Seek( GEI64, bEStreamSeekMode );
    public: virtual GEBool   IsValid( void ) const;
    public: virtual GEBool   IsOpen( void ) const;
    public: virtual GEI64    GetLength( void ) const;
    public: virtual GEBool   Close( void );
    public: using bCOStream::Write;
    public: virtual GEU32    Write( GELPCVoid, GEU32 );

    private:
        // 0000 // eCVirtualFile::`vftable'{for `bCIStream'}
        // 0004 // eCVirtualFile::`vftable'{for `bCOStream'}
        /* 0008 */ IFFVirtualFile * m_pFile;

    public:
        eCVirtualFile( eCVirtualFile const & );
        eCVirtualFile( IFFVirtualFile * );

    public:
        eCVirtualFile & operator = ( eCVirtualFile const & );
        eCVirtualFile & operator = ( IFFVirtualFile * );

    public:
        GEBool GetPhysicalPath( bCString & ) const;

    protected:
        void Destroy( void );
        void Invalidate( void );
        void SetFile( IFFVirtualFile * );

};

GE_ASSERT_SIZEOF( eCVirtualFile, 0x0C );

#endif
