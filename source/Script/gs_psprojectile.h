#ifndef GS_PSPROJECTILE_H_INCLUDED
#define GS_PSPROJECTILE_H_INCLUDED

class gCProjectile_PS;

GS_DECLARE_PROPERTYSET( PSProjectile, gCProjectile_PS )
public:
    GS_DECLARE_PROPERTY( DecayDuration,    GEFloat )
    GS_DECLARE_PROPERTY( PathStyle,        gEProjectilePath )
    GS_DECLARE_PROPERTY( ShootVelocity,    GEFloat )
    GS_DECLARE_PROPERTY( TargetDirection,  bCVector )
    GS_DECLARE_PROPERTY( TargetEntity,     eCEntityProxy )
    GS_DECLARE_PROPERTY( TargetPosition,   bCVector )
    GS_DECLARE_PROPERTY( TargetUpdateMSec, GEU32 )
    GS_DECLARE_PROPERTY( TouchBehavior,    gEProjectileTouchBehavior )

public:
    Entity GetTarget( void ) const;
    GEBool IsFlying( void ) const;
    GEBool IsValid( void ) const;
    void   SetTarget( Entity const & );
    void   Shoot( void );

};

#endif