#ifndef GE_POSTREAM_H_INCLUDED
#define GE_POSTREAM_H_INCLUDED

class GE_DLLIMPORT bCPOStream :
    public bCMemoryStream
{
    public: virtual GEU32 Read( GELPVoid, GEU32 );
    public: virtual GEU32 Read( bCString & );
    public: virtual      ~bCPOStream( void );
    public: virtual GEU32 Write( GELPCVoid, GEU32 );
    public: virtual GEU32 Write( bCString const & );

    protected:
        static GEBool                  ms_bLegacyMode;
        static bCPOStream *            ms_pMainPOStream;
        static bTObjArray<bCString> *  ms_parrStringList;
        static bTStringValMap<GEI32> * ms_pmapStringSaveHashmap;

    private:
        GEBool  m_bUnk;
        GEBool  m_bForcedLegacyMode;
        GE_PADDING(2)

    public:
        static void GE_STDCALL   DisableLegacyMode( void );
        static void GE_STDCALL   GetStringList( bTObjArray<bCString> * &, bTStringValMap<GEI32> * & );
        static GEBool GE_STDCALL IsInLegacyMode( void );
        static void GE_STDCALL   SetStringList( bTObjArray<bCString> *, bTStringValMap<GEI32> * );

    public:
        bCPOStream( bCPOStream const & );
        bCPOStream( void );

    public:
        bCPOStream & operator = ( bCPOStream const & );

    public:
        void   ClearStringHeaderMap( void );
        void   Create( void );
        void   Destroy( void );
        void   FakeMainPOStream( GEBool );
        void   ForceLegacyMode( void );
        GEBool IsForcedLegacyMode( void ) const;
        GEBool IsMain( void ) const;
        GEBool ReadFile( bCIStream & );
        GEBool WriteFile( bCOStream & );

    protected:
        void Invalidate( void );

};

GE_ASSERT_SIZEOF( bCPOStream, 0x18 )

#endif
