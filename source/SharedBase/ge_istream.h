#ifndef GE_ISTREAM_H_INCLUDED
#define GE_ISTREAM_H_INCLUDED

class GE_DLLIMPORT bCIStream
{
    public: virtual GEU32 Read( GELPVoid, GEU32 );
    public: virtual GEU32 Read( bCString & );
    public: virtual      ~bCIStream( void );

    public:
        bCIStream( bCIStream const & );
        bCIStream( void );

    public:
        bCIStream & operator =  ( bCIStream const & );
        bCIStream & operator >> ( GEI8 & );
        bCIStream & operator >> ( GEChar & );
        bCIStream & operator >> ( GEU8 & );
        bCIStream & operator >> ( GEI16 & );
        bCIStream & operator >> ( GEU16 & );
        bCIStream & operator >> ( GEInt & );
        bCIStream & operator >> ( GEUInt & );
        bCIStream & operator >> ( GEI32 & );
        bCIStream & operator >> ( GEU32 & );
        bCIStream & operator >> ( GEFloat & );
        bCIStream & operator >> ( GEDouble & );
        bCIStream & operator >> ( bCDateTime & );
        bCIStream & operator >> ( bCGuid & );
        bCIStream & operator >> ( bCString & );
        bCIStream & operator >> ( bCUnicodeString & );
        bCIStream & operator >> ( bCVariant & );
        bCIStream & operator >> ( GEI64 & );
        bCIStream & operator >> ( GEU64 & );
        bCIStream & operator >> ( GEBool & );

    public:
        GEU32 Read( GEI8 & );
        GEU32 Read( GEChar & );
        GEU32 Read( GEU8 & );
        GEU32 Read( GEI16 & );
        GEU32 Read( GEU16 & );
        GEU32 Read( GEInt & );
        GEU32 Read( GEUInt & );
        GEU32 Read( GEI32 & );
        GEU32 Read( GEU32 & );
        GEU32 Read( GEFloat & );
        GEU32 Read( GEDouble & );
        GEU32 Read( bCDateTime & );
        GEU32 Read( bCGuid & );
        GEU32 Read( bCUnicodeString & );
        GEU32 Read( bCVariant & );
        GEU32 Read( GEI64 & );
        GEU32 Read( GEU64 & );
        GEU32 Read( GEBool & );
        GEU32 ReadLine( bCString & );
        GEU32 ReadLine( bCUnicodeString & );
        GEU32 SkipBytes( GEU32 );

};

bCIStream & GE_STDCALL operator <<( GEI8 &, bCIStream & );
bCIStream & GE_STDCALL operator <<( GEChar &, bCIStream & );
bCIStream & GE_STDCALL operator <<( GEU8 &, bCIStream & );
bCIStream & GE_STDCALL operator <<( GEI16 &, bCIStream & );
bCIStream & GE_STDCALL operator <<( GEU16 &, bCIStream & );
bCIStream & GE_STDCALL operator <<( GEInt &, bCIStream & );
bCIStream & GE_STDCALL operator <<( GEUInt &, bCIStream & );
bCIStream & GE_STDCALL operator <<( GEI32 &, bCIStream & );
bCIStream & GE_STDCALL operator <<( GEU32 &, bCIStream & );
bCIStream & GE_STDCALL operator <<( GEFloat &, bCIStream & );
bCIStream & GE_STDCALL operator <<( GEDouble &, bCIStream & );
bCIStream & GE_STDCALL operator <<( bCDateTime &, bCIStream & );
bCIStream & GE_STDCALL operator <<( bCGuid &, bCIStream & );
bCIStream & GE_STDCALL operator <<( bCString &, bCIStream & );
bCIStream & GE_STDCALL operator <<( bCUnicodeString &, bCIStream & );
bCIStream & GE_STDCALL operator <<( bCVariant &, bCIStream & );
bCIStream & GE_STDCALL operator <<( GEI64 &, bCIStream & );
bCIStream & GE_STDCALL operator <<( GEU64 &, bCIStream & );
bCIStream & GE_STDCALL operator <<( GEBool &, bCIStream & );

#endif
