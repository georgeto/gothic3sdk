#ifndef GE_SESSIONCHEATS_H_INCLUDED
#define GE_SESSIONCHEATS_H_INCLUDED

class GE_DLLIMPORT gCSessionCheats :
    public bCObjectRefBase
{
    public: using bCObjectBase::CopyFrom;
    public: virtual void     CopyFrom( gCSessionCheats const & );
    public: using bCObjectBase::Write;
    public: virtual bEResult Write( bCOStream & );
    public: virtual bEResult Read( bCIStream & );
    public: virtual void     Destroy( void );
    public: virtual bEResult Create( void );
    public: virtual         ~gCSessionCheats( void );
    public: virtual bEResult PostInitializeProperties( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCSessionCheats( gCSessionCheats const & );
        gCSessionCheats( void );

    public:
        gCSessionCheats const & operator =  ( gCSessionCheats const & );
        bCOStream &             operator >> ( bCOStream & );
        bCIStream &             operator << ( bCIStream & );

    public:
        GEBool &       AccessCheatGodEnabled( void );
        GEBool &       AccessCheatInvisibleEnabled( void );
        GEBool const & GetCheatGodEnabled( void ) const;
        GEBool const & GetCheatInvisibleEnabled( void ) const;
        void           Invalidate( void );
        void           Process( void );
        void           SetCheatGodEnabled( GEBool const & );
        void           SetCheatInvisibleEnabled( GEBool const & );

};

#endif
