#ifndef GE_SESSIONINFO_H_INCLUDED
#define GE_SESSIONINFO_H_INCLUDED

class GE_DLLIMPORT gCSessionInfo :
    public bCObjectRefBase
{
    public: using bCObjectBase::CopyFrom;
    public: virtual void     CopyFrom( gCSessionInfo const & );
    public: using bCObjectBase::Write;
    public: virtual bEResult Write( bCOStream & );
    public: virtual bEResult Read( bCIStream & );
    public: virtual void     Destroy( void );
    public: virtual bEResult Create( void );
    public: virtual         ~gCSessionInfo( void );
    public: virtual bEResult PostInitializeProperties( void );

    public:
        static bCPropertyObjectBase const * GE_STDCALL GetRootObject( void );

    public:
        gCSessionInfo( gCSessionInfo const & );
        gCSessionInfo( void );

    public:
        gCSessionInfo const & operator =  ( gCSessionInfo const & );
        bCOStream &           operator >> ( bCOStream & );
        bCIStream &           operator << ( bCIStream & );

    public:
        bCString &              AccessName( void );
        GEFloat &               AccessNumHoursPlayed( void );
        GEBool &                AccessPlayerHasCheated( void );
        gCSessionCheats &       GetCheats( void );
        gCSessionCheats const & GetCheats( void ) const;
        bCString const &        GetName( void ) const;
        GEFloat const &         GetNumHoursPlayed( void ) const;
        GEBool const &          GetPlayerHasCheated( void ) const;
        void                    Invalidate( void );
        void                    Process( void );
        void                    SetName( bCString const & );
        void                    SetNumHoursPlayed( GEFloat const & );
        void                    SetPlayerHasCheated( GEBool const & );

};

#endif
