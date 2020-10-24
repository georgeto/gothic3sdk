#ifndef GS_PSROUTINE_H_INCLUDED
#define GS_PSROUTINE_H_INCLUDED

class gCScriptRoutine_PS;

GS_DECLARE_PROPERTYSET( PSRoutine, gCScriptRoutine_PS )
public:
    GS_DECLARE_PROPERTY( AIMode,        gEAIMode )
    GS_DECLARE_PROPERTY( Action,        gEAction )
    GS_DECLARE_PROPERTY( AmbientAction, gEAmbientAction )
    GS_DECLARE_PROPERTY( AniState,      gEAniState )
    GS_DECLARE_PROPERTY( CommandTime,   GEI32 )
    GS_DECLARE_PROPERTY( HitDirection,  gEHitDirection )
    GS_DECLARE_PROPERTY( StatePosition, GEU32 )
    GS_DECLARE_PROPERTY( TaskPosition,  GEU32 )

public:
    // Effectively calls gCScriptProcessingUnit::DetectDailyRoutineTask
    void     ContinueRoutine( void );
    // Stop the currently executed AI instruction
    void     FullStop( void );
    bCString GetCurrentRoutineTask( void ) const;
    bCString GetCurrentState( void ) const;
    bCString GetCurrentTask( void ) const;
    bCString GetLastTask( void ) const;
    // Unit is seconds, advanced by gCScriptProcessingUnit::ProcessScript
    GEFloat  GetStateTime( void ) const;
    GEFloat  GetTaskTime( void ) const;
    GEBool   IsValid( void ) const;
    // Callback local to the current state (per RunTimeStack entry)
    void     SetLocalCallback( bCString );
    void     SetState( bCString );
    void     SetStateTime( GEFloat );
    void     SetTask( bCString );
    // Task callback, is reset when SetTask() is called
    void     SetTaskCallback( bCString );
    void     SetTaskTime( GEFloat );
    void     SetTimeScale( GEFloat );
    void     StartOutput( bCString );
    void     StopAICombatMove( void );
    void     StopAIGoto( void );
    void     StopAIOutput( void );
    void     StopAIPlayAnimation( void );
    void     StopAIWait( void );

};

#endif