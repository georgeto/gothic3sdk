#ifndef GE_SCRIPTPROCESSINGUNIT_H_INCLUDED
#define GE_SCRIPTPROCESSINGUNIT_H_INCLUDED

class gCScriptAdmin;

enum gEAIInstruction;
class gScrArgument;

struct gScriptRunTimeSingleState {
    GEU32         m_iBreakBlock; //-24
    bCString      m_strScriptName; //-20
    GEBool        m_bIsScriptState; //-16 Interpretation of m_strScriptName as ScriptState (true) or ScriptFunction (false)
    GE_PADDING ( 3 );
    gScrArgument* m_pArguments; //-12
    bCString      m_strLocalCallback; //-8
    GEFloat       __FIXME_0014; //-4

    gScriptRunTimeSingleState() : m_iBreakBlock( 0 ), m_bIsScriptState( 1 ), m_pArguments( 0 ), __FIXME_0014( 1000.0f ) {
        m_strScriptName.Clear();
        m_strLocalCallback.Clear();
    }
};
GE_ASSERT_SIZEOF( gScriptRunTimeSingleState, 0x0018 )

/*
    Every NPC, to be exact its gCScriptRoutine_PS property set, has its own ScriptProcessingUnit (SPU).
    The execution of ScriptStates and ScriptFunctions is backed by a stack of gScriptRunTimeSingleState items.

    ScriptStates and ScriptFunctions are split up into multiple blocks of execution, so called break blocks, through which they advance during their execution.
    When execution reaches the end of a break block, and there is no delayed action (eg. animation) in progress, the following break block is executed instantly.
    Otherwise false is returned by the function and later when the delayed action has finished, the execution is continued with the following break block.
    If the processed break block is the last one, true is returned and the execution of the function ends.

    Typical stack layout:
        _AI_TransferItem (triggers delayed action gCScriptProcessingUnit::sAIPlayAniInstr)
        _AI_HoldInventoryItems
        _AI_HoldItems
        ZS_Cook

    When a ScriptFunction has finished execution it is removed from the stack.
    A ScriptState does not get removed, but instead execution starts again from the first break block.

    SetState
        Clears the state stack, resets state position and break block

    SetTask(TaskName,JustSetIfCaughtTask)
        A task is a broader concept than a state. States are the parts that form a task.
        Sets the current task and state to TaskName.

    Example:
        Task: PS_Interact
        State: PS_Interact_Chest

    AIContinueRoutine -> DetectDailyRoutineTask(this, 0)
*/
class GE_DLLIMPORT gCScriptProcessingUnit
{
    public: virtual ~gCScriptProcessingUnit( void );

    protected:
        static GEU32 s_u32CalledStateCallbacks;
        static GEU32 s_u32CalledTaskCallbacks;
        static GEU32 s_u32CurrentStateCallbacks;
        static GEU32 s_u32CurrentTaskCallbacks;
        static GEU32 s_u32CurrentTimeStamp;
        static GEU32 s_u32MaxStateCallbacks;
        static GEU32 s_u32MaxTaskCallbacks;

    public:
        struct sAIPlayAniInstr_Args
        {
            eCEntity *SelfEntity;
            eCEntity *InteractEntity;
            bCString  AniName;
            GEInt     iUnk1_0;
            GEU8      u8Unk2_0;
            GE_PADDING( 3 );
            GEFloat AniSpeedScale;
            GEU8    u8Unk4_0;
            GEU8    u8Unk5_0;
            GE_PADDING( 2 );

            sAIPlayAniInstr_Args( eCEntity * a_SelfEntity, eCEntity *a_InteractEntity, bCString a_AniName, GEFloat a_AniSpeedScale = 1.0f )
                : SelfEntity( a_SelfEntity ), InteractEntity( a_InteractEntity ), AniName( a_AniName ), iUnk1_0( 0 ), u8Unk2_0( 0 ), AniSpeedScale( a_AniSpeedScale ), u8Unk4_0( 0 ), u8Unk5_0( 0 )
            {
            }
        };

        struct sAIWaitInstr_Args
        {
            eCEntity *SelfEntity;
            GEU32     Duration;

            sAIWaitInstr_Args( eCEntity * a_SelfEntity, GEU32 a_Duration )
                : SelfEntity( a_SelfEntity ), Duration( a_Duration )
            {
            }
        };

        struct sAICombatMoveInstr_Args
        {
            eCEntity *SelfEntity;
            eCEntity *TargetEntity;
            gEAction Action;
            bCString PhaseName;
            GEFloat AniSpeedScale;

            sAICombatMoveInstr_Args(eCEntity * a_SelfEntity, eCEntity* a_TargetEntity, gEAction a_Action, bCString a_Phase, GEFloat a_AniSpeedScale = 1.0f)
                : SelfEntity(a_SelfEntity), TargetEntity(a_TargetEntity), Action(a_Action), PhaseName(a_Phase), AniSpeedScale(a_AniSpeedScale)
            {
            }
        };

        struct sAIGotoInstr_Args
        {
            GEU32       Unk1;
            eCEntity*   SelfEntity;
            eCEntity*   Destination;
            GEFloat     Unk2;
            GEFloat     Unk3;
            GEFloat     Unk4;
            gEWalkMode  WalkMode;
            gEDirection Direction;

            sAIGotoInstr_Args(eCEntity* a_pSelfEntity, eCEntity* a_pDestination, gEWalkMode a_WalkMode, gEDirection a_Direction)
                : Unk1(0), SelfEntity(a_pSelfEntity), Destination(a_pDestination), Unk2(0), Unk3(0), Unk4(0), WalkMode(a_WalkMode), Direction(a_Direction)
            {
            }
        };

    public:
        static GEBool GE_STDCALL sAICombatMoveInstr( GELPVoid a_pArgs, gCScriptProcessingUnit * a_pSPU, GEBool a_bFullStop );
        static GEBool GE_STDCALL sAIGotoInstr( GELPVoid a_pArgs, gCScriptProcessingUnit * a_pSPU, GEBool a_bFullStop );
        static GEBool GE_STDCALL sAIHUDWaitInstr( GELPVoid a_pArgs, gCScriptProcessingUnit * a_pSPU, GEBool a_bFullStop );
        static GEBool GE_STDCALL sAIOutputInstr( GELPVoid a_pArgs, gCScriptProcessingUnit * a_pSPU, GEBool a_bFullStop );
        static GEBool GE_STDCALL sAIPlayAimInstr( GELPVoid a_pArgs, gCScriptProcessingUnit * a_pSPU, GEBool a_bFullStop );
        static GEBool GE_STDCALL sAIPlayAniInstr( GELPVoid a_pArgs, gCScriptProcessingUnit * a_pSPU, GEBool a_bFullStop );
        static GEBool GE_STDCALL sAIPrepareAimInstr( GELPVoid a_pArgs, gCScriptProcessingUnit * a_pSPU, GEBool a_bFullStop );
        static GEBool GE_STDCALL sAIWaitInstr( GELPVoid a_pArgs, gCScriptProcessingUnit * a_pSPU, GEBool a_bFullStop );
        static void GE_STDCALL   sSetNewFrame( GEU32 );

    public:
        gCScriptProcessingUnit( void );

    public:
        void       AIContinueRoutine( void );
        // Stops the currently running instruction
        void       AIFullStop( gEAIInstruction );
        GEInt      AIGetStatePosition( void );
        GEFloat    AIGetStateTime( void );
        GEInt      AIGetTaskPosition( void );
        GEFloat    AIGetTaskTime( void );
        void       AISetLocalCallback( bCString );
        void       AISetState( bCString );
        void       AISetStatePosition( GEInt );
        void       AISetStateTime( GEFloat );
        // Calling it with a_bJustSetIfCaughtTask = GETrue (never done in the original game), will do nothing, unless DetectDailyRoutineTask was called with a_bCatchTask beforehand.
        void       AISetTask( bCString a_strTaskName, GEBool a_bJustSetIfCaughtTask );
        void       AISetTaskCallback( bCString );
        void       AISetTaskPosition( GEInt );
        void       AISetTaskTime( GEFloat );
        // Calling it with a_bCatchTask = GETrue (never done in the original game), will break the normal functioning of AISetTask.
        bEResult   DetectDailyRoutineTask( GEBool a_bCatchTask = GEFalse );
        void       GameReset( void );
        // Returns result task of DetectDailyRoutineTask, when it was called with a_bCatchTask = GEFalse.
        bCString   GetCaughtTask( void );
        GEInt      GetIntParameter( void );
        GEFloat    GetLocalTimeScale( void ) const;
        eCEntity * GetOtherEntity( void );
        eCEntity * GetSelfEntity( void );
        eCEntity * GetTargetEntity( void );
        GEFloat    GetWorldTime( void );
        void       Invalidate( void );
        GEBool     IsOutputPlaying( void ) const;
        bEResult   ProcessScript( void );
        void       SetIntParameter( GEInt );
        void       SetLocalTimeScale( GEFloat );
        void       SetOtherEntity( eCEntity * );
        void       SetSelfEntity( eCEntity * );
        GEBool     StartOutput( bCString const & );
        GEBool     StopOutput( void );

    protected:
        static void GE_STDCALL   sAICombatMoveItlLoop( gCScriptProcessingUnit * );
        static GEBool GE_STDCALL sAICombatMoveStart( GELPVoid, gCScriptProcessingUnit * );
        static void GE_STDCALL   sAICombatMoveStartRecover( gCScriptProcessingUnit * );
        static void GE_STDCALL   sAIGotoItlLoop( gCScriptProcessingUnit * );
        static GEBool GE_STDCALL sAIGotoStart( GELPVoid, gCScriptProcessingUnit * );
        static void GE_STDCALL   sAIPlayAimItlLoop( gCScriptProcessingUnit * );
        static GEBool GE_STDCALL sAIPlayAimStart( GELPVoid, gCScriptProcessingUnit * );
        static void GE_STDCALL   sAIPlayAniItlLoop( gCScriptProcessingUnit * );
        static GEBool GE_STDCALL sAIPlayAniStart( GELPVoid, gCScriptProcessingUnit * );
        static GEBool GE_STDCALL sAIPrepareAimStart( GELPVoid, gCScriptProcessingUnit * );
        static GEBool GE_STDCALL sIsOutputPlaying( eCEntity * );
        static GEBool GE_STDCALL sStartOutput( eCEntity *, bCString const & );
        static GEBool GE_STDCALL sStopOutput( eCEntity * );

    protected:
        gCScriptProcessingUnit( gCScriptProcessingUnit const & );

    protected:
        gCScriptProcessingUnit const & operator = ( gCScriptProcessingUnit const & );

    protected:
        GEBool   CreateSoundAndChannel( void );
        void     DestroySoundAndChannel( void );
        void     GetAniName( bCString &, eCEntity *, gEAction, bCString, bCString &, GEBool );
        void     RunLocalCallback( gCScriptAdmin *, gCScriptRoutine_PS * );
        void     RunTaskCallback( gCScriptAdmin *, gCScriptRoutine_PS * );
        bEResult SetCurrentAIState( bCString & );
        void     UpdateChannel( void );
        void     UpdateStateTime( gCScriptRoutine_PS * );
        void     UpdateTaskTime( gCScriptRoutine_PS * );

    private:
        GE_PADDING( 0x188 )
};

GE_ASSERT_SIZEOF( gCScriptProcessingUnit, 0x18C )

#endif
