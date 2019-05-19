#ifndef GS_PSDAMAGERECEIVER_H_INCLUDED
#define GS_PSDAMAGERECEIVER_H_INCLUDED

class gCDamageReceiver_PS;

GS_DECLARE_PROPERTYSET( PSDamageReceiver, gCDamageReceiver_PS )
public:
    GS_DECLARE_PROPERTY( DamageAmount,     GEI32 )
    GS_DECLARE_PROPERTY( DamageType,       gEDamageType )
    GS_DECLARE_PROPERTY( HitPoints,        GEI32 )
    GS_DECLARE_PROPERTY( HitPointsMax,     GEI32 )
    GS_DECLARE_PROPERTY( ManaPoints,       GEI32 )
    GS_DECLARE_PROPERTY( ManaPointsMax,    GEI32 )
    GS_DECLARE_PROPERTY( StaminaPoints,    GEI32 )
    GS_DECLARE_PROPERTY( StaminaPointsMax, GEI32 )

public:
    Entity GetLastInflictor( void );
    GEBool IsValid( void ) const;
    void   SetLastInflictor( Entity & );

};

#endif
