#ifndef GS_PSDAMAGE_H_INCLUDED
#define GS_PSDAMAGE_H_INCLUDED

class gCDamage_PS;

GS_DECLARE_PROPERTYSET( PSDamage, gCDamage_PS )
public:
    GS_DECLARE_PROPERTY( DamageAmount,         GEI32 )
    GS_DECLARE_PROPERTY( DamageHitMultiplier,  GEFloat )
    GS_DECLARE_PROPERTY( DamageManaMultiplier, GEFloat )
    GS_DECLARE_PROPERTY( DamageType,           gEDamageType )
    GS_DECLARE_PROPERTY( ManaUsed,             GEInt )

public:
    GEBool IsValid( void ) const;

};

#endif
