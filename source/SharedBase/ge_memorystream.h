#ifndef GE_MEMORYSTREAM_H_INCLUDED
#define GE_MEMORYSTREAM_H_INCLUDED

class GE_DLLIMPORT bCMemoryStream :
    public bCIOStream
{
    public: virtual GEI64  GetSize( void ) const;
    public: virtual GEBool GetPosition( GEI64 & ) const;
    public: virtual GEBool SetPosition( GEI64, bEStreamSeekMode );
    public: using bCIStream::Read;
    public: virtual GEU32  Read( GELPVoid, GEU32 );
    public: virtual       ~bCMemoryStream( void );
    public: virtual GEI64  GetPosition( void ) const;
    public: virtual GEBool Seek( GEI64, bEStreamSeekMode );
    public: using bCOStream::Write;
    public: virtual GEU32  Write( GELPCVoid, GEU32 );

    private:
        GELPByte  m_bBuffer;
        GEInt     m_iPosition;
        GEInt     m_iSize;

    public:
        bCMemoryStream( bCMemoryStream const & );
        bCMemoryStream( void );

    public:
        bCMemoryStream & operator = ( bCMemoryStream const & );

    public:
        GELPByte  AccessBuffer( GEU32 );
        GEBool    Decrypt( void );
        void      Destroy( void );
        GEBool    Encrypt( void );
        GELPCByte GetBuffer( GEU32 ) const;
        void      SetCount( GEU32 );

    protected:
        static GEBool GE_STDCALL Decrypt( GELPVoid, GEU32 );
        static GEBool GE_STDCALL Encrypt( GELPVoid, GEU32 );

    protected:
        void Invalidate( void );

};
GE_ASSERT_SIZEOF( bCMemoryStream, 0x14 )

#endif
