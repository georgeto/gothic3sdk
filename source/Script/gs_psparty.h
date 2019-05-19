#ifndef GS_PSPARTY_H_INCLUDED
#define GS_PSPARTY_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSParty, gCParty_PS )
public:
    GS_DECLARE_PROPERTY( PartyMemberType, gEPartyMemberType )
    GS_DECLARE_PROPERTY( Waiting,         GEBool )

public:
    GEBool                 Add( Entity );
    void                   CleanUp( void );
    bTValArray<eCEntity *> GetMembers( GEBool a_bIncludeSelf ) const;
    Entity                 GetPartyLeader( void ) const;
    GEBool                 IsValid( void ) const;
    GEBool                 Remove( Entity );
    GEBool                 SetPartyLeader( Entity );

};

#endif
