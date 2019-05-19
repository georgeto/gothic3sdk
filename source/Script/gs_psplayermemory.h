#ifndef GS_PSPLAYERMEMORY_H_INCLUDED
#define GS_PSPLAYERMEMORY_H_INCLUDED

class gCPlayerMemory_PS;
enum gETutorialFlag;

GS_DECLARE_PROPERTYSET( PSPlayerMemory, gCPlayerMemory_PS )
public:
    GS_DECLARE_PROPERTY( BookOfFlood,            GEI32 )
    GS_DECLARE_PROPERTY( BookOfRhobar,           GEI32 )
    GS_DECLARE_PROPERTY( BookOfZuben,            GEI32 )
    GS_DECLARE_PROPERTY( Chapter,                GEI32 )
    GS_DECLARE_PROPERTY( DuskToDawnStartHour,    GEI32 )
    GS_DECLARE_PROPERTY( IsConsumingItem,        GEBool )
    GS_DECLARE_PROPERTY( LPAttribs,              GEI32 )
    GS_DECLARE_PROPERTY( LPPerks,                GEI32 )
    GS_DECLARE_PROPERTY( LastSpell,              bCPropertyID )
    GS_DECLARE_PROPERTY( LastWeaponConfig,       gEWeaponConfig )
    GS_DECLARE_PROPERTY( SecondsMistRemain,      GEFloat )
    GS_DECLARE_PROPERTY( SecondsTransformRemain, GEFloat )
    GS_DECLARE_PROPERTY( TalkedToDiego,          GEBool )
    GS_DECLARE_PROPERTY( TalkedToGorn,           GEBool )
    GS_DECLARE_PROPERTY( TalkedToLester,         GEBool )
    GS_DECLARE_PROPERTY( TalkedToMilten,         GEBool )
    GS_DECLARE_PROPERTY( TimeStampStart,         GEFloat )
    GS_DECLARE_PROPERTY( XP,                     GEI32 )

public:
    void    AddAlchemy( GEInt );
    void    AddBaseValue( bCString const &, GEInt );
    void    AddDexterity( GEInt );
    void    AddHitPoints( int );
    void    AddHitPointsMax( int );
    void    AddIntelligence( GEInt );
    void    AddManaPoints( int );
    void    AddManaPointsMax( int );
    void    AddMaximum( bCString const &, GEInt );
    void    AddModifier( bCString const &, GEInt );
    void    AddProtectionBlades( GEInt );
    void    AddProtectionFire( GEInt );
    void    AddProtectionIce( GEInt );
    void    AddProtectionImpact( GEInt );
    void    AddProtectionLightning( GEInt );
    void    AddProtectionMissile( GEInt );
    void    AddSmithing( GEInt );
    void    AddStaminaPoints( int );
    void    AddStaminaPointsMax( int );
    void    AddStrength( GEInt );
    void    AddTheft( GEInt );
    void    AddValue( bCString const &, GEInt );
    GEBool  ClearGameEvent( bCString const & );
    void    EnableTutorial( gETutorialFlag, GEBool );
    GEInt   GetAlchemy( void ) const;
    GEInt   GetBaseValue( bCString const & ) const;
    GEInt   GetDexterity( void ) const;
    GEInt   GetHitPoints( void ) const;
    GEInt   GetHitPointsMax( void ) const;
    GEFloat GetHitPointsPercent( void ) const;
    GEInt   GetIntelligence( void ) const;
    GEInt   GetManaPoints( void ) const;
    GEInt   GetManaPointsMax( void ) const;
    GEFloat GetManaPointsPercent( void ) const;
    GEInt   GetMaximum( bCString const & ) const;
    GEInt   GetModifier( bCString const & ) const;
    GEI32   GetPoliticalCrimeCount( gEPoliticalAlignment );
    GEI32   GetPoliticalFame( gEPoliticalAlignment );
    GEBool  GetPoliticalPlayerCrime( gEPoliticalAlignment );
    GEI32   GetPoliticalSuspectComment( gEPoliticalAlignment );
    GEInt   GetProtectionBlades( void ) const;
    GEInt   GetProtectionFire( void ) const;
    GEInt   GetProtectionIce( void ) const;
    GEInt   GetProtectionImpact( void ) const;
    GEInt   GetProtectionLightning( void ) const;
    GEInt   GetProtectionMissile( void ) const;
    GEInt   GetSmithing( void ) const;
    GEInt   GetStaminaPoints( void ) const;
    GEInt   GetStaminaPointsMax( void ) const;
    GEFloat GetStaminaPointsPercent( void ) const;
    GEInt   GetStrength( void ) const;
    GEInt   GetTheft( void ) const;
    GEInt   GetValue( bCString const & ) const;
    GEBool  IsSetGameEvent( bCString const & );
    GEBool  IsTutorialEnabled( gETutorialFlag ) const;
    GEBool  IsValid( void ) const;
    void    PrintAddMaximum( bCString const &, int );
    void    PrintAddValue( bCString const &, int );
    void    SetAlchemy( GEInt );
    void    SetBaseValue( bCString const &, GEInt );
    void    SetDexterity( GEInt );
    GEBool  SetGameEvent( bCString const & );
    void    SetHitPoints( int );
    void    SetHitPointsMax( int );
    void    SetIntelligence( GEInt );
    void    SetManaPoints( int );
    void    SetManaPointsMax( int );
    void    SetMaximum( bCString const &, GEInt );
    void    SetModifier( bCString const &, GEInt );
    void    SetPoliticalCrimeCount( gEPoliticalAlignment, GEI32 );
    void    SetPoliticalFame( gEPoliticalAlignment, GEI32 );
    void    SetPoliticalPlayerCrime( gEPoliticalAlignment, GEBool );
    void    SetPoliticalSuspectComment( gEPoliticalAlignment, GEI32 );
    void    SetProtectionBlades( GEInt );
    void    SetProtectionFire( GEInt );
    void    SetProtectionIce( GEInt );
    void    SetProtectionImpact( GEInt );
    void    SetProtectionLightning( GEInt );
    void    SetProtectionMissile( GEInt );
    void    SetSmithing( GEInt );
    void    SetStaminaPoints( int );
    void    SetStaminaPointsMax( int );
    void    SetStrength( GEInt );
    void    SetTheft( GEInt );
    void    SetValue( bCString const &, GEInt );

};

#endif
