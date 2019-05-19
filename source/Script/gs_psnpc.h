#ifndef GS_PSNPC_H_INCLUDED
#define GS_PSNPC_H_INCLUDED

class gCNPC_PS;

GS_DECLARE_PROPERTYSET( PSNpc, gCNPC_PS )
public:
    GS_DECLARE_PROPERTY( AttackReason,           gEAttackReason )
    GS_DECLARE_PROPERTY( AttitudeToPlayer2,      gEAttitude )
    GS_DECLARE_PROPERTY( Bearing,                gEBearing )
    GS_DECLARE_PROPERTY( Class,                  gEClass )
    GS_DECLARE_PROPERTY( CombatState,            GEU32 )
    GS_DECLARE_PROPERTY( DefeatedByPlayer,       GEBool )
    GS_DECLARE_PROPERTY( Discovered,             GEBool )
    GS_DECLARE_PROPERTY( DistToNearestMist,      GEFloat )
    GS_DECLARE_PROPERTY( Gender,                 gEGender )
    GS_DECLARE_PROPERTY( GuardStatus,            gEGuardStatus )
    GS_DECLARE_PROPERTY( Immortal,               GEBool )
    GS_DECLARE_PROPERTY( LastCastTimestamp,      GEU32 )
    GS_DECLARE_PROPERTY( LastDistToGuardPoint,   GEFloat )
    GS_DECLARE_PROPERTY( LastDistToTarget,       GEFloat )
    GS_DECLARE_PROPERTY( LastFightAgainstPlayer, gELastFightAgainstPlayer )
    GS_DECLARE_PROPERTY( LastFightComment,       GEBool )
    GS_DECLARE_PROPERTY( LastFightTimestamp,     GEFloat )
    GS_DECLARE_PROPERTY( LastHitTimestamp,       GEU32 )
    GS_DECLARE_PROPERTY( LastPlayerAR,           gEAttackReason )
    GS_DECLARE_PROPERTY( LastPlayerCrime,        gEPlayerCrime )
    GS_DECLARE_PROPERTY( LastSpell,              bCString )
    GS_DECLARE_PROPERTY( Level,                  GEU32 )
    GS_DECLARE_PROPERTY( LevelMax,               GEU32 )
    GS_DECLARE_PROPERTY( ManaUsed,               GEInt )
    GS_DECLARE_PROPERTY( PoliticalAlignment,     gEPoliticalAlignment )
    GS_DECLARE_PROPERTY( Ransacked,              GEBool )
    GS_DECLARE_PROPERTY( Species,                gESpecies )
    GS_DECLARE_PROPERTY( StatusEffects,          GEU32 )
    GS_DECLARE_PROPERTY( TimeStampBurning,       GEU32 )
    GS_DECLARE_PROPERTY( TimeStampDiseased,      GEU32 )
    GS_DECLARE_PROPERTY( TimeStampFrozen,        GEU32 )
    GS_DECLARE_PROPERTY( TimeStampPoisoned,      GEU32 )
    GS_DECLARE_PROPERTY( TimeStampTransformed,   GEU32 )
    GS_DECLARE_PROPERTY( Type,                   gENPCType )
    GS_DECLARE_PROPERTY( Voice,                  bCString )

public:
    GEBool   CanCast( GEU32 );
    GEBool   CanHit( GEU32 );
    void     EnableBurning( GEBool );
    void     EnableDiseased( GEBool );
    void     EnableFrozen( GEBool );
    void     EnableInMagicBarrier( GEBool );
    void     EnablePoisoned( GEBool );
    void     EnableStatusEffects( GEInt, GEBool );
    GEBool   ForceNextPose( gEPose );
    Entity   GetAlternativeTarget( void ) const;
    Entity   GetCurrentAttacker( void ) const;
    bCString GetCurrentMovementAni( void ) const;
    Entity   GetCurrentTarget( void ) const;
    Entity   GetEnclave( void ) const;
    Entity   GetGuardPoint( void ) const;
    Entity   GetLastAttacker( void ) const;
    GEU32    GetLastCastTimestamp( void );
    GEU32    GetLastHitTimestamp( void );
    gEPose   GetPrimaryPose( void ) const;
    gEPose   GetPrimaryPoseExt( gEAction, gEPhase ) const;
    GEBool   GetPrimaryPoseExt( gEAction, gEPhase, gEPose & ) const;
    Entity   GetSpellTarget( void ) const;
    GEBool   HasStatusEffects( GEInt ) const;
    GEBool   IsBurning( void ) const;
    GEBool   IsDiseased( void ) const;
    GEBool   IsFrozen( void ) const;
    GEBool   IsInMagicBarrier( void ) const;
    GEBool   IsPoisoned( void ) const;
    GEBool   IsTransformed( void ) const;
    GEBool   IsValid( void ) const;
    void     SetAlternativeTarget( Entity const & );
    void     SetCurrentAttacker( Entity const & );
    void     SetCurrentTarget( Entity const & );
    GEBool   SetEnclave( Entity const & ) const;
    GEBool   SetGuardPoint( Entity const & ) const;
    void     SetLastAttacker( Entity const & );
    void     SetLastCast( void );
    void     SetLastCastTimestamp( GEU32 );
    void     SetLastHit( void );
    void     SetLastHitTimestamp( GEU32 );
    void     SetSpellTarget( Entity const & );

};

#endif