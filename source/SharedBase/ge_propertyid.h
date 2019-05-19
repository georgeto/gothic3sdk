#ifndef GE_PROPERTYID_H_INCLUDED
#define GE_PROPERTYID_H_INCLUDED

class GE_DLLIMPORT bCPropertyID
{
    public:
        struct bSCore {
            GEU32 Data1;
            GEU16 Data2;
            GEU16 Data3;
            GEU8  Data4[8];
        };

    private:
        bSCore mCore;
        GEU32  mCount;

    public:
         bCPropertyID( bCPropertyID const & );
         bCPropertyID( bCGuid const & );
         bCPropertyID( void );
        ~bCPropertyID( void );

    public:
        bCPropertyID & operator =  ( bCPropertyID const & );
        bCOStream &    operator >> ( bCOStream & );
        bCIStream &    operator << ( bCIStream & );
        GEBool         operator == ( bCPropertyID const & ) const;
        GEBool         operator != ( bCPropertyID const & ) const;

    public:
        void           CopyFrom( bCPropertyID const & );
        void           CopyTo( bCPropertyID & ) const;
        GEBool         CreateFromMd5( bCMd5 const & );
        void           CreateFromString( bCString const & );
        GEBool         CreateRandom( void );
        void           Destroy( void );
        void           ExtractGuid( bCGuid & );
        bSCore const & GetCore( void ) const;
        GEU32 const &  GetCount( void ) const;
        bCString       GetShortText( void ) const;
        bCString       GetText( void ) const;
        bCString       GetTextEx( void ) const;
        GEBool         IsValid( void ) const;
        GEBool         Read( bCIStream & );
        GEBool         SetGuid( bCGuid const & );
        GEBool         SetText( bCString const & );
        GEBool         SetTextEx( bCString const & );
        void           Write( bCOStream & );

    protected:
        static void GE_STDCALL DestroyHashList( void );

    private:
        bSCore & AccessCore( void );
        GEU32 &  AccessCount( void );
        GEBool   Create( void );
        void     Invalidate( void );
        void     SetCore( bSCore const & );
        void     SetCount( GEU32 const & );

};

GE_ASSERT_SIZEOF( bCPropertyID, 20 );

bCIStream & GE_STDCALL operator >>( bCIStream &, bCPropertyID & );
bCOStream & GE_STDCALL operator <<( bCOStream &, bCPropertyID & );

template<>
GE_DLLIMPORT GEU32 GE_STDCALL g_GetHashValue< bCPropertyID >( bCPropertyID const & );

#endif
