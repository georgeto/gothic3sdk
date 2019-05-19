#ifndef GS_SCRIPTMACROS_H_INCLUDED
#define GS_SCRIPTMACROS_H_INCLUDED

#define DECLARE_SCRIPT( N ) \
    GEInt GE_STDCALL N( gCScriptProcessingUnit* a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iArgs )

#define INIT_SCRIPT()                  \
    UNREFERENCED_PARAMETER( a_iArgs ); \
    INIT_SCRIPT_EXT( SelfEntity, OtherEntity )

#define INIT_SCRIPT_EXT( S, O )                     \
    Entity S;                                       \
    if(a_pSelfEntity)                               \
        S = *static_cast<Entity *>(a_pSelfEntity);  \
    else                                            \
        S.AttachTo( a_pSPU->GetSelfEntity());       \
    Entity O;                                       \
    if(a_pOtherEntity)                              \
        O = *static_cast<Entity *>(a_pOtherEntity); \
    else                                            \
        O.AttachTo( a_pSPU->GetOtherEntity());


#define DECLARE_SCRIPT_STATE( N ) \
    GEBool GE_STDCALL N( bTObjStack<gScriptRunTimeSingleState>&a_rRunTimeStack, gCScriptProcessingUnit* a_pSPU )

#define INIT_SCRIPT_STATE()                                  \
    UNREFERENCED_PARAMETER( a_rRunTimeStack );               \
    UNREFERENCED_PARAMETER( a_pSPU );                        \
    BREAK_BLOCK_BASE();                                      \
    Entity SelfEntity   = Entity( a_pSPU->GetSelfEntity());  \
    Entity TargetEntity = Entity( a_pSPU->GetTargetEntity());

#define DECLARE_SCRIPT_CALLBACK( N ) \
    GEBool GE_STDCALL N( gCScriptProcessingUnit* a_pSPU )

#define INIT_SCRIPT_CALLBACK()                               \
    Entity SelfEntity   = Entity( a_pSPU->GetSelfEntity());  \
    Entity TargetEntity = Entity( a_pSPU->GetTargetEntity());

#define BREAK_BLOCK_BASE() \
    static GEU32 __breakBlockCounter = 0;

#define __BREAK_BLOCK( N )                                                 \
    static GEU32 GE_PASTE_TOKENS(__breakBlock, N) = __breakBlockCounter++; \
    if(CondIncrementCounter( &a_rRunTimeStack.AccessAt( a_rRunTimeStack.GetCount() - 1 ).m_iBreakBlock, GE_PASTE_TOKENS(__breakBlock, N) ))

#define BREAK_BLOCK __BREAK_BLOCK( __COUNTER__ )

GEBool inline CondIncrementCounter( GEU32* a_u32Counter, GEU32 a_u32CurValue )
{
    if(*a_u32Counter <= a_u32CurValue)
    {
        *a_u32Counter = a_u32CurValue + 1;
        return GETrue;
    }
    return GEFalse;
}

#define RUN_SCRIPT( SCRIPT, SELF_ENTITY, OTHER_ENTIY, ARGS ) \
    GetScriptAdmin().RunScriptFromScript( SCRIPT, a_pSPU, SELF_ENTITY, OTHER_ENTIY, ARGS )

#define PUSH_STATE( N )                                                 \
    gScriptRunTimeSingleState& runTimeState = a_rRunTimeStack.AddNew(); \
    runTimeState.m_strScriptName            = N;                        \
    runTimeState.m_bIsScriptState           = GEFalse;                  \
    runTimeState.m_strLocalCallback        = a_rRunTimeStack.GetAt( a_rRunTimeStack.GetCount() - 2 ).m_strLocalCallback;

#define ALLOC_STATE_ARGS( N )                \
    N* args                   = GE_NEW( N ); \
    runTimeState.m_pArguments = args;

#define RUN_SCRIPT_FUNCTION()                                                                        \
    if(!GetScriptAdmin().RunScriptFunction( runTimeState.m_strScriptName, a_rRunTimeStack, a_pSPU )) \
        return GEFalse;

#define RUN_AI_STANDUP()                       \
    PUSH_STATE( "_AI_StandUp" );               \
    ALLOC_STATE_ARGS( gSArgsFor__AI_StandUp ); \
    args->m_Entity = SelfEntity;               \
    RUN_SCRIPT_FUNCTION()

#define RUN_AI_GOTO_EXT( DESTINATION, WALK_MODE, DIRECTION ) \
    SelfEntity.Routine.SetTaskCallback( "OnGoto" );          \
    PUSH_STATE( "_AI_Goto_Ext" );                            \
    ALLOC_STATE_ARGS( gSArgsFor__AI_Goto_Ext );              \
    args->m_Entity       = SelfEntity;                       \
    args->m_Destination  = DESTINATION;                      \
    args->m_enuWalkMode  = WALK_MODE;                        \
    args->m_enuDirection = DIRECTION;                        \
    RUN_SCRIPT_FUNCTION()

#define ASSERT_AI_GOTO_EXT_SUCCESSFUL()                                                   \
    if(!GetScriptAdmin().RunScriptFromScript( "EndGoto", a_pSPU, &SelfEntity, &None, 0 )) \
        return GETrue;

#define RUN_AI_HOLD_ITEMS( LEFT_ITEM, RIGHT_ITEM ) \
    PUSH_STATE( "_AI_HoldItems" );                 \
    ALLOC_STATE_ARGS( gSArgsFor__AI_HoldItems );   \
    args->m_Holder    = SelfEntity;                \
    args->m_LeftItem  = LEFT_ITEM;                 \
    args->m_RightItem = RIGHT_ITEM;                \
    RUN_SCRIPT_FUNCTION();

#define RUN_AI_HOLD_INVENTORY_ITEMS( LEFT_INDEX, RIGHT_INDEX ) \
    PUSH_STATE( "_AI_HoldInventoryItems" );                    \
    ALLOC_STATE_ARGS( gSArgsFor__AI_HoldInventoryItems );      \
    args->m_Holder      = SelfEntity;                          \
    args->m_iLeftIndex  = LEFT_INDEX;                          \
    args->m_iRightIndex = RIGHT_INDEX;                         \
    RUN_SCRIPT_FUNCTION();

#define RUN_AI_ACTION( ACTION, DURATION )     \
    PUSH_STATE( "_AI_Action" );               \
    ALLOC_STATE_ARGS( gSArgsFor__AI_Action ); \
    args->m_Entity    = SelfEntity;           \
    args->m_enuAction = ACTION;               \
    args->m_iDuration = DURATION;             \
    RUN_SCRIPT_FUNCTION();

#define RUN_AI_CHANGE_ACTION( ACTION )              \
    PUSH_STATE( "_AI_ChangeAction" );               \
    ALLOC_STATE_ARGS( gSArgsFor__AI_ChangeAction ); \
    args->m_Entity         = SelfEntity;            \
    args->m_InteractEntity = None;                  \
    args->m_enuAction      = ACTION;                \
    RUN_SCRIPT_FUNCTION();

#define RUN_AI_SAY( SPEAKER, TARGET, UNK1, PHASE, TEXT, SHOW_TEXT ) \
    PUSH_STATE( "_AI_Say" );                                                      \
    ALLOC_STATE_ARGS( gSArgsFor__AI_Say);                                         \
    args->m_Entity1      = SPEAKER;                                               \
    args->m_Entity2      = TARGET;                                                \
    args->m_Unk1         = UNK1;                                                  \
    args->m_PhaseGesture = PHASE;                                                 \
    args->m_strTextID    = TEXT;                                                  \
    args->m_bShowText    = SHOW_TEXT;                                             \
    RUN_SCRIPT_FUNCTION();

#define RUN_AI_SAY_SVM( SPEAKER, TARGET, UNK1, PHASE, TEXT, SHOW_TEXT ) \
    PUSH_STATE( "_AI_SaySVM" );                                                   \
    ALLOC_STATE_ARGS( gSArgsFor__AI_SaySVM );                                     \
    args->m_Entity1      = SPEAKER;                                               \
    args->m_Entity2      = TARGET;                                                \
    args->m_Unk1         = UNK1;                                                  \
    args->m_PhaseGesture = PHASE;                                                 \
    args->m_strTextID    = TEXT;                                                  \
    args->m_bShowText    = SHOW_TEXT;                                             \
    RUN_SCRIPT_FUNCTION();

#define RUN_AI_UNLOCK( SELF, TARGET )         \
    PUSH_STATE( "_AI_Unlock" );               \
    ALLOC_STATE_ARGS( gSArgsFor__AI_Unlock ); \
    args->m_SelfEntity    = SELF;             \
    args->m_TargetEntity  = TARGET;           \
    RUN_SCRIPT_FUNCTION();

#define CALL_SPU_FUNCTION( NAME, ... ) \
    ( a_pSPU->sAI ## NAME ## Instr( GE_NEW( gCScriptProcessingUnit::sAI ## NAME ## Instr ## _Args )( SelfEntity.GetInstance(), __VA_ARGS__ ), a_pSPU, GEFalse ) )

#define EXECUTE_SPU_FUNCTION( NAME, ... )        \
    if( !CALL_SPU_FUNCTION(NAME, __VA_ARGS__ ) ) \
        return GEFalse;

#endif
