#ifndef GE_NULLSTREAM_H_INCLUDED
#define GE_NULLSTREAM_H_INCLUDED

class GE_DLLIMPORT bCNullStream :
    public bCIOStream
{
    protected: using bCIStream::Read;
    protected: virtual GEU32  Read( GELPVoid, GEU32 );
    public:    virtual       ~bCNullStream( void );
    public:    virtual GEI64  GetPosition( void ) const;
    public:    virtual GEBool Seek( GEI64, bEStreamSeekMode );
    protected: using bCOStream::Write;
    protected: virtual GEU32  Write( GELPCVoid, GEU32 );

    public:
        bCNullStream( bCNullStream const & );
        bCNullStream( void );

    public:
        bCNullStream & operator = ( bCNullStream const & );

    public:
        void  Clear( void );
        GEU32 GetBytesWritten( void );

    protected:
        void ReallocBuffer( GEU32 );

};

#endif
