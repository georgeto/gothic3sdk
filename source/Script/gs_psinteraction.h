#ifndef GS_PSINTERACTION_H_INCLUDED
#define GS_PSINTERACTION_H_INCLUDED

class gCInteraction_PS;

GS_DECLARE_PROPERTYSET( PSInteraction, gCInteraction_PS )
public:
    GS_DECLARE_PROPERTY( EnterROIScript, bCString )
    GS_DECLARE_PROPERTY( ExitROIScript,  bCString )
    GS_DECLARE_PROPERTY( UseFunc,        bCString )
    GS_DECLARE_PROPERTY( UseType,        gEUseType )
    GS_DECLARE_PROPERTY( UsedByPlayer,   GEBool )

public:
    Entity    GetAnchorPoint( void ) const;
    Entity    GetOwner( void ) const;
    Entity    GetSpell( void ) const;
    gEUseType GetUseType( void ) const;
    Entity    GetUser( void ) const;
    Entity    GetZone( void ) const;
    GEBool    IsValid( void ) const;
    GEBool    IsZoneValid( void ) const;
    GEBool    SetAnchorPoint( Entity const & );
    GEBool    SetOwner( Entity const & );
    void      SetSpell( Entity const & );
    GEBool    SetUser( Entity const & );

};

#endif
