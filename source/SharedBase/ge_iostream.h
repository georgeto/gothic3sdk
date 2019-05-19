#ifndef GE_IOSTREAM_H_INCLUDED
#define GE_IOSTREAM_H_INCLUDED

enum bEStreamSeekMode
{
    bEStreamSeekMode_Begin,
    bEStreamSeekMode_Current,
    bEStreamSeekMode_End,
    bEStreamSeekMode_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT bCIOStream :
    public bCIStream,
    public bCOStream
{
    public: virtual GEI64  GetPosition( void ) const = 0;
    public: virtual GEBool Seek( GEI64, bEStreamSeekMode ) = 0;
    public: virtual       ~bCIOStream( void );

    public:
        bCIOStream( bCIOStream const & );
        bCIOStream( void );

    public:
        bCIOStream & operator = ( bCIOStream const & );

};

#endif
