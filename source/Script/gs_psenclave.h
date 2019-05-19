#ifndef GS_PSENCLAVE_H_INCLUDED
#define GS_PSENCLAVE_H_INCLUDED

class gCEnclave_PS;

GS_DECLARE_PROPERTYSET( PSEnclave, gCEnclave_PS )
public:
    GS_DECLARE_PROPERTY( CrimeCount,         bTValArray<GEI32>)
    GS_DECLARE_PROPERTY( KnownPlayerCrime,   gEPlayerCrime )
    GS_DECLARE_PROPERTY( MusicPlayed,        GEBool )
    GS_DECLARE_PROPERTY( PlayerFame,         GEI32 )
    GS_DECLARE_PROPERTY( PoliticalAlignment, gEPoliticalAlignment )
    GS_DECLARE_PROPERTY( Raid,               GEBool )
    GS_DECLARE_PROPERTY( Revolution,         GEBool )
    GS_DECLARE_PROPERTY( Status,             gEEnclaveStatus )
    GS_DECLARE_PROPERTY( SuspectComment,     bTValArray<GEI32>)
    GS_DECLARE_PROPERTY( Switched,           GEBool )

public:
    static Entity GE_STDCALL GetEnclave( bCString const & );
    static Entity GE_STDCALL GetEnclaveAt( GEInt );
    static GEInt GE_STDCALL  GetEnclaveCount( void );

public:
    GEI32                        GetCrimeCount( gEPlayerCrime );
    bCUnicodeString              GetDisplayName( void );
    bTValArray<eCEntity *> const GetMembers( void ) const;
    GEI32                        GetSuspectComment( gEPlayerCrime );
    GEBool                       IsValid( void ) const;
    void                         SetCrimeCount( gEPlayerCrime, GEI32 );
    void                         SetSuspectComment( gEPlayerCrime, GEI32 );

};

#endif