#pragma once

#include <Game.h>

#define DECLARE_SCRIPT(N)                                                                                              \
    GEInt GE_STDCALL N(gCScriptProcessingUnit *a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iArgs)

#define INIT_SCRIPT()                                                                                                  \
    UNREFERENCED_PARAMETER(a_iArgs);                                                                                   \
    INIT_SCRIPT_EXT(SelfEntity, OtherEntity)

#define INIT_SCRIPT_EXT(S, O)                                                                                          \
    Entity S;                                                                                                          \
    if (a_pSelfEntity)                                                                                                 \
        S = *static_cast<Entity *>(a_pSelfEntity);                                                                     \
    else                                                                                                               \
        S.AttachTo(a_pSPU->GetSelfEntity());                                                                           \
    Entity O;                                                                                                          \
    if (a_pOtherEntity)                                                                                                \
        O = *static_cast<Entity *>(a_pOtherEntity);                                                                    \
    else                                                                                                               \
        O.AttachTo(a_pSPU->GetOtherEntity());

#define DECLARE_SCRIPT_STATE(N)                                                                                        \
    GEBool GE_STDCALL N(bTObjStack<gScriptRunTimeSingleState> &a_rRunTimeStack, gCScriptProcessingUnit *a_pSPU)

#define INIT_SCRIPT_STATE()                                                                                            \
    UNREFERENCED_PARAMETER(a_rRunTimeStack);                                                                           \
    UNREFERENCED_PARAMETER(a_pSPU);                                                                                    \
    BREAK_BLOCK_BASE();                                                                                                \
    Entity SelfEntity = Entity(a_pSPU->GetSelfEntity());                                                               \
    Entity TargetEntity = Entity(a_pSPU->GetTargetEntity());

#define DECLARE_SCRIPT_FUNCTION(N) DECLARE_SCRIPT_STATE(N)

#define DECLARE_SCRIPT_CALLBACK(N) GEBool GE_STDCALL N(gCScriptProcessingUnit *a_pSPU)

#define INIT_SCRIPT_CALLBACK()                                                                                         \
    Entity SelfEntity = Entity(a_pSPU->GetSelfEntity());                                                               \
    Entity TargetEntity = Entity(a_pSPU->GetTargetEntity());

#define DECLARE_SCRIPT_ROUTINE(N) INIT_SCRIPT_CALLBACK(N)

#define BREAK_BLOCK_BASE() static GEU32 __breakBlockCounter = 0;

#define __BREAK_BLOCK(N)                                                                                               \
    static GEU32 GE_PASTE_TOKENS(__breakBlock, N) = __breakBlockCounter++;                                             \
    if (__CondIncrementCounter(&a_rRunTimeStack.AccessAt(a_rRunTimeStack.GetCount() - 1).m_iBreakBlock,                \
                               GE_PASTE_TOKENS(__breakBlock, N)))

#define BREAK_BLOCK __BREAK_BLOCK(__COUNTER__)

GEBool inline __CondIncrementCounter(GEU32 *a_u32Counter, GEU32 a_u32CurValue, GEU32 a_u32Increment = 1)
{
    if (*a_u32Counter <= a_u32CurValue)
    {
        *a_u32Counter = a_u32CurValue + a_u32Increment;
        return GETrue;
    }
    return GEFalse;
}

#define SKIP_BREAK_BLOCKS(COUNT) a_rRunTimeStack.AccessAt(a_rRunTimeStack.GetCount() - 1).m_iBreakBlock += COUNT;
#define SKIP_BREAK_BLOCK() SKIP_BREAK_BLOCKS(1)

GEU32 inline __PostIncrement(GEU32 &a_u32Value, GEU32 a_u32Increment)
{
    GEU32 u32PreValue = a_u32Value;
    a_u32Value += a_u32Increment;
    return u32PreValue;
}

GEBool inline __CondIncrementCounterEquals(GEU32 *a_u32Counter, GEU32 a_u32CurValue, GEU32 a_u32Increment = 1)
{
    if (*a_u32Counter == a_u32CurValue)
    {
        *a_u32Counter = a_u32CurValue + a_u32Increment;
        return GETrue;
    }
    return GEFalse;
}

#define __PREPEND_BREAK_BLOCK(N, INCREMENT)                                                                            \
    static GEU32 GE_PASTE_TOKENS(__breakBlock, N) = __PostIncrement(__breakBlockCounter, INCREMENT);                   \
    if (__CondIncrementCounterEquals(&a_rRunTimeStack.AccessAt(a_rRunTimeStack.GetCount() - 1).m_iBreakBlock,          \
                                     GE_PASTE_TOKENS(__breakBlock, N), INCREMENT))

#define PREPEND_BREAK_BLOCK_BEGIN __PREPEND_BREAK_BLOCK(__COUNTER__, 100)

#define PREPEND_BREAK_BLOCK_END                                                                                        \
    __PREPEND_BREAK_BLOCK(__COUNTER__, 1)                                                                              \
    {                                                                                                                  \
        a_rRunTimeStack.AccessAt(a_rRunTimeStack.GetCount() - 1).m_iBreakBlock = 0;                                    \
    }

#define RUN_SCRIPT(SCRIPT, SELF_ENTITY, OTHER_ENTIY, ARGS)                                                             \
    GetScriptAdmin().RunScriptFromScript(SCRIPT, a_pSPU, SELF_ENTITY, OTHER_ENTIY, ARGS)

#define PUSH_STATE(N)                                                                                                  \
    gScriptRunTimeSingleState &runTimeState = a_rRunTimeStack.AddNew();                                                \
    runTimeState.m_strScriptName = N;                                                                                  \
    runTimeState.m_bIsScriptState = GEFalse;                                                                           \
    runTimeState.m_strLocalCallback = a_rRunTimeStack.GetAt(a_rRunTimeStack.GetCount() - 2).m_strLocalCallback;

#define ALLOC_STATE_ARGS(N)                                                                                            \
    N *args = GE_NEW(N);                                                                                               \
    runTimeState.m_pArguments = args;

#define PUSH_STATE_AND_ARGS(N)                                                                                         \
    PUSH_STATE(#N);                                                                                                    \
    ALLOC_STATE_ARGS(gSArgsFor_##N)

#define RUN_SCRIPT_FUNCTION()                                                                                          \
    if (!GetScriptAdmin().RunScriptFunction(runTimeState.m_strScriptName, a_rRunTimeStack, a_pSPU))                    \
        return GEFalse;

#define RUN_AI_STANDUP()                                                                                               \
    PUSH_STATE_AND_ARGS(_AI_StandUp);                                                                                  \
    args->m_Entity = SelfEntity;                                                                                       \
    RUN_SCRIPT_FUNCTION()

#define RUN_AI_GOTO_EXT(DESTINATION, WALK_MODE, DIRECTION)                                                             \
    PUSH_STATE_AND_ARGS(_AI_Goto_Ext);                                                                                 \
    args->m_Entity = SelfEntity;                                                                                       \
    args->m_Destination = DESTINATION;                                                                                 \
    args->m_enuWalkMode = WALK_MODE;                                                                                   \
    args->m_enuDirection = DIRECTION;                                                                                  \
    RUN_SCRIPT_FUNCTION()

#define ASSERT_AI_GOTO_EXT_SUCCESSFUL()                                                                                \
    if (!GetScriptAdmin().RunScriptFromScript("EndGoto", a_pSPU, &SelfEntity, &None, 0))                               \
        return GETrue;

#define RUN_AI_HOLD_ITEMS(LEFT_ITEM, RIGHT_ITEM) RUN_AI_HOLD_ITEMS_EXT(SelfEntity, LEFT_ITEM, RIGHT_ITEM)

#define RUN_AI_HOLD_ITEMS_EXT(HOLDER, LEFT_ITEM, RIGHT_ITEM)                                                           \
    PUSH_STATE_AND_ARGS(_AI_HoldItems);                                                                                \
    args->m_Holder = HOLDER;                                                                                           \
    args->m_LeftItem = LEFT_ITEM;                                                                                      \
    args->m_RightItem = RIGHT_ITEM;                                                                                    \
    RUN_SCRIPT_FUNCTION();

#define RUN_AI_HOLD_INVENTORY_ITEMS(LEFT_ITEM, RIGHT_ITEM)                                                             \
    RUN_AI_HOLD_INVENTORY_ITEMS_EXT(SelfEntity, LEFT_ITEM, RIGHT_ITEM)

#define RUN_AI_HOLD_INVENTORY_ITEMS_EXT(HOLDER, LEFT_INDEX, RIGHT_INDEX)                                               \
    PUSH_STATE_AND_ARGS(_AI_HoldInventoryItems);                                                                       \
    args->m_Holder = HOLDER;                                                                                           \
    args->m_iLeftIndex = LEFT_INDEX;                                                                                   \
    args->m_iRightIndex = RIGHT_INDEX;                                                                                 \
    RUN_SCRIPT_FUNCTION();

#define RUN_AI_USE_INVENTORY_ITEM(HOLDER, ITEM_INDEX)                                                                  \
    PUSH_STATE_AND_ARGS(_AI_UseInventoryItem);                                                                         \
    args->m_Consumer = HOLDER;                                                                                         \
    args->m_iIndex = ITEM_INDEX;                                                                                       \
    RUN_SCRIPT_FUNCTION();

#define RUN_AI_ACTION(ACTION, DURATION)                                                                                \
    PUSH_STATE_AND_ARGS(_AI_Action);                                                                                   \
    args->m_Entity = SelfEntity;                                                                                       \
    args->m_enuAction = ACTION;                                                                                        \
    args->m_iDuration = DURATION;                                                                                      \
    RUN_SCRIPT_FUNCTION();

#define RUN_AI_CHANGE_ACTION(ACTION)                                                                                   \
    PUSH_STATE_AND_ARGS(_AI_ChangeAction);                                                                             \
    args->m_Entity = SelfEntity;                                                                                       \
    args->m_InteractEntity = None;                                                                                     \
    args->m_enuAction = ACTION;                                                                                        \
    RUN_SCRIPT_FUNCTION();

#define RUN_AI_SAY(SPEAKER, TARGET, UNK1, PHASE, TEXT, SHOW_TEXT)                                                      \
    PUSH_STATE_AND_ARGS(_AI_Say);                                                                                      \
    args->m_Entity1 = SPEAKER;                                                                                         \
    args->m_Entity2 = TARGET;                                                                                          \
    args->m_Unk1 = UNK1;                                                                                               \
    args->m_PhaseGesture = PHASE;                                                                                      \
    args->m_strTextID = TEXT;                                                                                          \
    args->m_bShowText = SHOW_TEXT;                                                                                     \
    RUN_SCRIPT_FUNCTION();

#define RUN_AI_SAY_SVM(SPEAKER, TARGET, UNK1, PHASE, TEXT, SHOW_TEXT)                                                  \
    PUSH_STATE_AND_ARGS(_AI_SaySVM);                                                                                   \
    args->m_Entity1 = SPEAKER;                                                                                         \
    args->m_Entity2 = TARGET;                                                                                          \
    args->m_Unk1 = UNK1;                                                                                               \
    args->m_PhaseGesture = PHASE;                                                                                      \
    args->m_strTextID = TEXT;                                                                                          \
    args->m_bShowText = SHOW_TEXT;                                                                                     \
    RUN_SCRIPT_FUNCTION();

#define RUN_AI_UNLOCK(SELF, TARGET)                                                                                    \
    PUSH_STATE_AND_ARGS(_AI_Unlock);                                                                                   \
    args->m_SelfEntity = SELF;                                                                                         \
    args->m_TargetEntity = TARGET;                                                                                     \
    RUN_SCRIPT_FUNCTION();

#define CALL_SPU_FUNCTION(NAME, ...)                                                                                   \
    (a_pSPU->sAI##NAME##Instr(                                                                                         \
        GE_NEW(gCScriptProcessingUnit::sAI##NAME##Instr##_Args)(SelfEntity.GetInstance(), ##__VA_ARGS__), a_pSPU,      \
        GEFalse))

#define EXECUTE_SPU_FUNCTION(NAME, ...)                                                                                \
    if (!CALL_SPU_FUNCTION(NAME, ##__VA_ARGS__))                                                                       \
        return GEFalse;
