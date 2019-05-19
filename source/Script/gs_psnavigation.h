#ifndef GS_PSNAVIGATION_H_INCLUDED
#define GS_PSNAVIGATION_H_INCLUDED

class gCNavigation_PS;
enum gEGotoStatus;
enum gEWalkMode;

GS_DECLARE_PROPERTYSET( PSNavigation, gCNavigation_PS )
public:
    GS_DECLARE_PROPERTY( CurrentAniDirection,      gEDirection )
    GS_DECLARE_PROPERTY( IsOnDestination,          GEBool )
    GS_DECLARE_PROPERTY( IsOnDestinationTimeStamp, GEU32 )
    GS_DECLARE_PROPERTY( StartPosition,            bCVector )

public:
    Entity       GetAIGotoDestination( void ) const;
    gEDirection  GetAniDirection( void ) const;
    Entity       GetCurrentDestinationPoint( void ) const;
    Entity       GetCurrentZone( void ) const;
    GEBool       GetDCCEnabled( void ) const;
    GEFloat      GetDCCRadius( void ) const;
    gEGotoStatus GetGotoStatus( void ) const;
    Entity       GetLastZone( void ) const;
    Entity       GetRelaxingPoint( void ) const;
    Entity       GetSleepingPoint( void ) const;
    Entity       GetWorkingPoint( void ) const;
    GEBool       HasAnyDestination( void ) const;
    GEBool       IsInProcessingRange( void ) const;
    GEBool       IsTravelling( void ) const;
    GEBool       IsValid( void ) const;
    void         Reset( void ) const;
    void         ResetAll( void ) const;
    GEBool       SetCurrentDestinationPoint( Entity & );
    void         SetDCCEnabled( GEBool );
    void         SetDCCRadius( GEFloat );
    GEBool       SetRelaxingPoint( Entity & );
    GEBool       SetRoutine( bCString const & );
    GEBool       SetSleepingPoint( Entity & );
    GEBool       SetWorkingPoint( Entity & );
    GEBool       StartGoto( Entity &, Entity &, gEWalkMode );
    GEBool       StartGoto( Entity &, bCVector const &, gEWalkMode );

};

#endif