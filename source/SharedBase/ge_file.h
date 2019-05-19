#ifndef GE_FILE_H_INCLUDED
#define GE_FILE_H_INCLUDED

enum bEFileCreationMode
{
    bEFileCreationMode_OpenExisting,
    bEFileCreationMode_OpenAlways,
    bEFileCreationMode_CreateAlways,
    bEFileCreationMode_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT bCFile :
    public bCIOStream
{
    public: virtual GEBool IsValid( void ) const;
    public: virtual GEBool IsOpen( void ) const;
    public: virtual GEI64  GetLength( void ) const;
    public: virtual GEBool Open( bCString const &, bEFileCreationMode );
    public: virtual GEBool Close( void );
    public: using bCIOStream::Seek;
    public: virtual GEBool Seek( GEI64, bEStreamSeekMode ) const;
    public: virtual       ~bCFile( void );
    public: virtual GEI64  GetPosition( void ) const;

    public:
        bCFile( bCFile const & );
        bCFile( void );

    public:
        bCFile & operator = ( bCFile const & );

    public:
        GEBool Eof( void ) const;
        GEBool SeekToBegin( void ) const;
        GEBool SeekToEnd( void ) const;

};

#endif
