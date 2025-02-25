#ifndef GAMEENUM_H_INCLUDED
#define GAMEENUM_H_INCLUDED

// gCArmorSet_PS.ModAttrib1
// gCArmorSet_PS.ModAttrib2
// gCArmorSet_PS.ModAttrib3
// gCArmorSet_PS.ModAttrib4
// gCItem_PS.ModAttrib1
// gCItem_PS.ModAttrib2
// gCItem_PS.ModAttrib3
// gCItem_PS.ModAttrib4
// gCItem_PS.ModAttrib5
// gCItem_PS.ModAttrib6
enum EAttribModOperation {
    EAttribModOperation_AddToVal           = 0,
    EAttribModOperation_AddToMax           = 1,
    EAttribModOperation_AddPercentageToVal = 2,
    EAttribModOperation_AddPercentageToMax = 3,
    EAttribModOperation_SetVal             = 4,
    EAttribModOperation_SetMax             = 5,
    EAttribModOperation_SetValToPercentage = 6,
    EAttribModOperation_SetMaxToPercentage = 7,
    EAttribModOperation_SetValToMax        = 8
};

// gCItem_PS.ReqAttrib1
// gCItem_PS.ReqAttrib2
// gCItem_PS.ReqAttrib3
// gCItem_PS.ReqAttrib4

enum EAttribReqOperation {
    EAttribReqOperation_ValGreaterEqual = 0,
    EAttribReqOperation_MaxGreaterEqual = 1
};

// gCScriptRoutine_PS.AIMode

enum gEAIMode {
    gEAIMode_Routine  = 0,
    gEAIMode_Reaction = 1,
    // gEAIMode_??? = 2,
    gEAIMode_Combat = 3,
    gEAIMode_Flee   = 4,
    gEAIMode_Arena  = 5,
    gEAIMode_Talk   = 6,
    // gEAIMode_??? = 7,
    gEAIMode_Down        = 8,
    gEAIMode_Dead        = 9,
    gEAIMode_Abandoned   = 10,
    gEAIMode_PlayerParty = 11
};

// gCScriptRoutine_PS.Action

enum gEAction {
    gEAction_None               = 0,
    gEAction_Attack             = 1,
    gEAction_PowerAttack        = 2,
    gEAction_QuickAttack        = 3,
    gEAction_QuickAttackR       = 4,
    gEAction_QuickAttackL       = 5,
    gEAction_SimpleWhirl        = 6,
    gEAction_TurnLeft           = 7,
    gEAction_TurnRight          = 8,
    gEAction_SprintAttack       = 9,
    gEAction_WhirlAttack        = 10,
    gEAction_PierceAttack       = 11,
    gEAction_JumpAttack         = 12,
    gEAction_RamAttack          = 13,
    gEAction_HackAttack         = 14,
    gEAction_FinishingAttack    = 15,
    gEAction_Parade             = 16,
    gEAction_ParadeR            = 17,
    gEAction_ParadeL            = 18,
    gEAction_ExitParade         = 19,
    gEAction_QuickParadeStumble = 20,
    gEAction_ParadeStumble      = 21,
    gEAction_ParadeStumbleR     = 22,
    gEAction_ParadeStumbleL     = 23,
    gEAction_HeavyParadeStumble = 24,
    gEAction_QuickStumble       = 25,
    gEAction_Stumble            = 26,
    gEAction_StumbleR           = 27,
    gEAction_StumbleL           = 28,
    gEAction_SitKnockDown       = 29,
    gEAction_GetUpAttack        = 30,
    gEAction_GetUpParade        = 31,
    gEAction_LieKnockDown       = 32,
    gEAction_LieKnockOut        = 33,
    gEAction_PierceStumble      = 34,
    gEAction_Die                = 35,
    gEAction_LieDead            = 36,
    gEAction_LiePiercedKO       = 37,
    gEAction_LiePiercedDead     = 38,
    gEAction_AbortAttack        = 39,
    gEAction_Aim                = 40,
    gEAction_Shoot              = 41,
    gEAction_Reload             = 42,
    gEAction_Cock               = 43,
    gEAction_Cast               = 44,
    gEAction_PowerCast          = 45,
    gEAction_MagicParade        = 46,
    gEAction_QuickCast          = 47,
    gEAction_Summon             = 48,
    gEAction_Heal               = 49,
    gEAction_Wait               = 50,
    gEAction_JumpBack           = 51,
    gEAction_Fwd                = 52,
    gEAction_Back               = 53,
    gEAction_Left               = 54,
    gEAction_Right              = 55,
    gEAction_Move               = 56,
    gEAction_Jump               = 57,
    gEAction_Evade              = 58,
    gEAction_Slide              = 59,
    gEAction_Fall               = 60,
    gEAction_Dive               = 61,
    gEAction_COMBATACTIONS_END  = 62,
    gEAction_Use                = 63,
    gEAction_Equip              = 64,
    gEAction_Reach              = 65,
    gEAction_Take               = 66,
    gEAction_Drop               = 67,
    gEAction_Hold               = 68,
    gEAction_HoldLeft           = 69,
    gEAction_HoldRight          = 70,
    gEAction_Transfer           = 71,
    gEAction_FlameSword         = 72,
    gEAction_Fry                = 73,
    gEAction_Eat                = 74,
    gEAction_Drink              = 75,
    gEAction_Stand              = 76,
    gEAction_Sneak              = 77,
    gEAction_Kneel              = 78,
    gEAction_SitGround          = 79,
    gEAction_SitStool           = 80,
    gEAction_SitBench           = 81,
    gEAction_SitThrone          = 82,
    gEAction_SleepBed           = 83,
    gEAction_SleepGround        = 84,
    gEAction_OrcDrum            = 85,
    gEAction_Waterpipe          = 86,
    gEAction_Anvil              = 87,
    gEAction_OrcAnvil           = 88,
    gEAction_Forge              = 89,
    gEAction_CoolWeapon         = 90,
    gEAction_DrinkWaterBarrel   = 91,
    gEAction_GrindStone         = 92,
    gEAction_Cauldron           = 93,
    gEAction_Barbecue           = 94,
    gEAction_Alchemy            = 95,
    gEAction_Bookstand          = 96,
    gEAction_Stoneplate         = 97,
    gEAction_PickOre            = 98,
    gEAction_OpenChest          = 99,
    gEAction_Lockpick           = 100,
    gEAction_OpenDoor           = 101,
    gEAction_ExitInteract       = 102,
    gEAction_PickGround         = 103,
    gEAction_DigGround          = 104,
    gEAction_Repair             = 105,
    gEAction_SawLog             = 106,
    gEAction_Lumberjack         = 107,
    gEAction_RakeField          = 108,
    gEAction_CleanFloor         = 109,
    gEAction_TiltOrcBoulder     = 110,
    gEAction_HoldOrcBoulder     = 111,
    gEAction_LiftOrcBoulder     = 112,
    gEAction_Fan                = 113,
    gEAction_Dance              = 114,
    gEAction_OrcDance           = 115,
    gEAction_FieldWork          = 116,
    gEAction_EatGround          = 117,
    gEAction_DrinkWater         = 118,
    gEAction_ArmsCrossed        = 119,
    gEAction_HandsOnHips        = 120,
    gEAction_Warn               = 121,
    gEAction_Ambient            = 122,
    gEAction_Think              = 123,
    gEAction_Pee                = 124,
    gEAction_Say                = 125,
    gEAction_Listen             = 126,
    gEAction_WatchFight         = 127,
    gEAction_Cheer              = 128,
    gEAction_SuperCheer         = 129,
    gEAction_Applaud            = 130,
    gEAction_QuickUse0          = 131,
    gEAction_QuickUse1          = 132,
    gEAction_QuickUse2          = 133,
    gEAction_QuickUse3          = 134,
    gEAction_QuickUse4          = 135,
    gEAction_QuickUse5          = 136,
    gEAction_QuickUse6          = 137,
    gEAction_QuickUse7          = 138,
    gEAction_QuickUse8          = 139,
    gEAction_QuickUse9          = 140,
    gEAction_QuickUseH          = 141,
    gEAction_QuickUseM          = 142,
    gEAction_QuickUseS          = 143,
    gEAction_Count              = 145
};

// gCScriptRoutine_PS.AmbientAction

enum gEAmbientAction {
    gEAmbientAction_Ambient = 0,
    gEAmbientAction_Listen  = 1,
    gEAmbientAction_Count   = 2
};

// gCAnchor_PS.AnchorType

enum gEAnchorType {
    gEAnchorType_Local  = 0,
    gEAnchorType_Roam   = 1,
    gEAnchorType_Patrol = 2,
    gEAnchorType_Event  = 3
};

// gCScriptRoutine_PS.AniState

enum gEAniState {
    gEAniState_Dummy0          = 0,
    gEAniState_Dummy1          = 1,
    gEAniState_Stand           = 2,
    gEAniState_Sneak           = 3,
    gEAniState_Parade          = 4,
    gEAniState_Kneel           = 5,
    gEAniState_SitGround       = 6,
    gEAniState_SitStool        = 7,
    gEAniState_SitBench        = 8,
    gEAniState_SitThrone       = 9,
    gEAniState_SleepBed        = 10,
    gEAniState_SleepGround     = 11,
    gEAniState_TiltOrcBoulder  = 12,
    gEAniState_HoldOrcBoulder  = 13,
    gEAniState_LiftOrcBoulder  = 14,
    gEAniState_SitKnockDown    = 15,
    gEAniState_LieKnockDown    = 16,
    gEAniState_LieKnockOut     = 17,
    gEAniState_LieStraightDead = 18,
    gEAniState_LieDead         = 19,
    gEAniState_LiePiercedKO    = 20,
    gEAniState_LiePiercedDead  = 21,
    gEAniState_TalkStand       = 22,
    gEAniState_TalkSitGround   = 23,
    gEAniState_TalkSitStool    = 24,
    gEAniState_TalkSitBench    = 25,
    gEAniState_TalkSitThrone   = 26,
    gEAniState_Wade            = 27,
    gEAniState_Swim            = 28,
    gEAniState_Dive            = 29,
    gEAniState_Count           = 30
};

// gCArena_PS.Status

enum gEArenaStatus {
    gEArenaStatus_None    = 0,
    gEArenaStatus_Running = 1
};

// gCNPC_PS.AttackReason
// gCNPC_PS.LastPlayerAR

enum gEAttackReason {
    gEAttackReason_None              = 0,
    gEAttackReason_LeaveZone         = 1,
    gEAttackReason_Livestock         = 2,
    gEAttackReason_StopThief         = 3,
    gEAttackReason_Theft             = 4,
    gEAttackReason_UseInteractObject = 5,
    gEAttackReason_ReactToWeapon     = 6,
    gEAttackReason_Angry             = 7,
    gEAttackReason_StopFight         = 8,
    gEAttackReason_ReactToDamage     = 9,
    gEAttackReason_GateGuard         = 10,
    gEAttackReason_Intruder          = 11,
    gEAttackReason_Enemy             = 12,
    gEAttackReason_Murder            = 13,
    gEAttackReason_Prey              = 14,
    gEAttackReason_DriveAway         = 15,
    gEAttackReason_PlayerCommand     = 16,
    gEAttackReason_Duel              = 17,
    gEAttackReason_Arena             = 18,
    gEAttackReason_Revolution        = 19,
    gEAttackReason_Kill              = 20, // According to CP modder manual, 1.2.22 Attack reason "ReactToWeapon"
    gEAttackReason_Die               = 21
};

// gCNPC_PS.AttitudeToPlayer2

enum gEAttitude {
    gEAttitude_None     = 0,
    gEAttitude_Friendly = 1,
    gEAttitude_Neutral  = 2,
    gEAttitude_Angry    = 3,
    gEAttitude_Hostile  = 4,
    gEAttitude_Predator = 5,
    gEAttitude_Panic    = 6
};

// gCNPC_PS.Bearing

enum gEBearing {
    gEBearing_None   = 0,
    gEBearing_Babe   = 1,
    gEBearing_Zombie = 2
};

// gCMagic_PS.CastType

enum gECastType {
    gECastType_Immediate = 0,
    gECastType_Power     = 1,
    gECastType_Regular   = 2
};

// gCCharacterControl_PS.ControlFOR

enum gECharacterControlFOR {
    gECharacterControlFOR_Camera = 0,
    gECharacterControlFOR_Target = 1
};

// gCNPC_PS.Class

enum gEClass {
    gEClass_None    = 0,
    gEClass_Mage    = 1,
    gEClass_Paladin = 2,
    gEClass_Warrior = 3,
    gEClass_Ranger  = 4,
    gEClass_EMPTY_A = 5,
    gEClass_EMPTY_B = 6,
    gEClass_EMPTY_C = 7,
    gEClass_EMPTY_D = 8,
    gEClass_EMPTY_E = 9,
    gEClass_EMPTY_F = 10,
    gEClass_EMPTY_G = 11
};

// gCDamageReceiver_PS.DamageType
// gCDamage_PS.DamageType

enum gEDamageType {
    gEDamageType_None      = 0,
    gEDamageType_Impact    = 1,
    gEDamageType_Blade     = 2,
    gEDamageType_Missile   = 3,
    gEDamageType_Fire      = 4,
    gEDamageType_Ice       = 5,
    gEDamageType_Lightning = 6,
    gEDamageType_Physics   = 7
};

// eCParticleSystemBase_PS.DirectionMode

enum gEDirectionMode {
    // gEDirectionMode_None = ???,
    // gEDirectionMode_Direction = ???,
    // gEDirectionMode_Target = ???
};

enum gEDirection {
    gEDirection_None      = 0,
    gEDirection_Fwd       = 1,
    gEDirection_Back      = 2,
    gEDirection_Left      = 3,
    gEDirection_Right     = 4,
    gEDirection_FwdLeft   = 5,
    gEDirection_FwdRight  = 6,
    gEDirection_BackLeft  = 7,
    gEDirection_BackRight = 8
};

// gCDoor_PS.Status

enum gEDoorStatus {
    gEDoorStatus_Open   = 0,
    gEDoorStatus_Closed = 1
};

// gCEffectCommandSpawnEntity.Link

enum gEEffectLink {
    gEEffectLink_Independent  = 0,
    gEEffectLink_TargetEntity = 1,
    gEEffectLink_TargetBone   = 2
};

// eCParticleSystemBase_PS.EmitterType

enum gEEmitterType {
    // gEEmitterType_Point = ???,
    // gEEmitterType_Line = ???,
    // gEEmitterType_Box = ???,
    // gEEmitterType_Circle = ???,
    // gEEmitterType_Sphere = ???,
    // gEEmitterType_Mesh = ???
};

// gCEnclave_PS.Status

enum gEEnclaveStatus {
    gEEnclaveStatus_Routine = 0,
    gEEnclaveStatus_Attack  = 1,
    gEEnclaveStatus_Flee    = 2
};

// gCDynamicLayer.EntityType

enum gEEntityType {
    gEEntityType_Game      = 0,
    gEEntityType_Temporary = 1
};

// eCParticleSystemBase_PS.FOR
// eCParticleSystemBase_PS.TFOR

enum gEFOR {
    // gEFOR_World = ???,
    // gEFOR_Object = ???
};

// gCFocus_PS.CurrentMode

enum gEFocus {
    gEFocus_None  = 0,
    gEFocus_Hard  = 1,
    gEFocus_Soft  = 2,
    gEFocus_Shape = 3
};

// gCFocus_PS.FocusLookAtMode

enum gEFocusLookAt {
    gEFocusLookAt_Camera = 0,
    gEFocusLookAt_Entity = 1,
    gEFocusLookAt_Keys   = 2
};

// gCFocus_PS.FocusLookAtKeysFOR

enum gEFocusLookAtKeysFOR {
    gEFocusLookAtKeysFOR_Camera = 0,
    gEFocusLookAtKeysFOR_Entity = 1
};

// gCInteraction_PS.FocusNameType

enum gEFocusNameType {
    gEFocusNameType_Skeleton = 0,
    gEFocusNameType_Entity   = 1,
    gEFocusNameType_Bone     = 2,
    gEFocusNameType_Disable  = 3
};

// gCInteraction_PS.FocusPri

enum gEFocusPriority {
    gEFocusPriority_None   = 0,
    gEFocusPriority_Normal = 1,
    gEFocusPriority_High   = 2
};

// gCNPC_PS.Gender

enum gEGender {
    gEGender_Male   = 0,
    gEGender_Female = 1
};

// gCGeometryLayer.GeometryType

enum gEGeometryType {
    gEGeometryType_Spatial = 0,
    gEGeometryType_Culling = 1
};

// gCNPC_PS.GuardStatus

enum gEGuardStatus {
    gEGuardStatus_Active          = 0,
    gEGuardStatus_FirstWarnGiven  = 1,
    gEGuardStatus_SecondWarnGiven = 2,
    gEGuardStatus_Inactive        = 3,
    gEGuardStatus_Behind          = 4
};

// gCScriptRoutine_PS.HitDirection

enum gEHitDirection {
    gEHitDirection_Left  = 0,
    gEHitDirection_Right = 1
};

// gCInfo_PS.CondType

enum gEInfoCondType {
    gEInfoCondType_Crime            = 0,
    gEInfoCondType_Fight            = 1,
    gEInfoCondType_Hello            = 2,
    gEInfoCondType_General          = 3,
    gEInfoCondType_Overtime         = 4,
    gEInfoCondType_Open             = 5,
    gEInfoCondType_Activator        = 6,
    gEInfoCondType_Running          = 7,
    gEInfoCondType_Delivery         = 8,
    gEInfoCondType_PartDelivery     = 9,
    gEInfoCondType_Success          = 10,
    gEInfoCondType_DoCancel         = 11,
    gEInfoCondType_Failed           = 12,
    gEInfoCondType_Cancelled        = 13,
    gEInfoCondType_Join             = 14,
    gEInfoCondType_Dismiss          = 15,
    gEInfoCondType_Teach            = 16,
    gEInfoCondType_Trade            = 17,
    gEInfoCondType_PickPocket       = 18,
    gEInfoCondType_Ready            = 19,
    gEInfoCondType_Lost             = 20,
    gEInfoCondType_Reactivator      = 21,
    gEInfoCondType_Won              = 22,
    gEInfoCondType_MasterThief      = 23,
    gEInfoCondType_EnclaveFriend    = 24,
    gEInfoCondType_PoliticalFriend  = 25,
    gEInfoCondType_FirstWarn        = 26,
    gEInfoCondType_SecondWarn       = 27,
    gEInfoCondType_MobJoin          = 28,
    gEInfoCondType_SlaveJoin        = 29,
    gEInfoCondType_LongTimeNoSee    = 30,
    gEInfoCondType_EnclaveCrime     = 31,
    gEInfoCondType_PoliticalCrime   = 32,
    gEInfoCondType_MobDismiss       = 33,
    gEInfoCondType_Wait             = 34,
    gEInfoCondType_Heal             = 35,
    gEInfoCondType_Animal           = 36,
    gEInfoCondType_Companion        = 37,
    gEInfoCondType_NotFriend        = 38,
    gEInfoCondType_NotFriendOrThief = 39,
    gEInfoCondType_NothingToSay     = 50,
    gEInfoCondType_End              = 51,
    gEInfoCondType_Back             = 52,
    gEInfoCondType_BackPrevLevel    = 53
};

// NOTE: the enum member names are guesswork!
// (used the strings from NPCStatusToString)

enum gEInfoNPCStatus {
    gEInfoNPCStatus_Alive                   = 0,
    gEInfoNPCStatus_NotDefeated             = 1,
    gEInfoNPCStatus_Defeated                = 2,
    gEInfoNPCStatus_Dead                    = 3,
    gEInfoNPCStatus_TalkedToPlayer          = 4,
    gEInfoNPCStatus_NotTalkedToPlayer       = 5,
    gEInfoNPCStatus_WonLastFight            = 6,
    gEInfoNPCStatus_CancelledLastFight      = 7,
    gEInfoNPCStatus_FightRunning            = 8,
    gEInfoNPCStatus_WonOrCancelledLastFight = 9
};

// gCInfo_PS.Type

enum gEInfoType {
    gEInfoType_Refuse       = 0,
    gEInfoType_Important    = 1,
    gEInfoType_News         = 2,
    gEInfoType_Info         = 3,
    gEInfoType_Parent       = 4,
    gEInfoType_Comment      = 5,
    gEInfoType_QuestRunning = 7 // Also known as Push
};

// gCItem_PS.Category

enum gEItemCategory {
    gEItemCategory_None      = 0,
    gEItemCategory_Weapon    = 1,
    gEItemCategory_Armor     = 2,
    gEItemCategory_Artefact  = 3,
    gEItemCategory_Alchemy   = 4,
    gEItemCategory_Empty_A   = 5,
    gEItemCategory_Misc      = 6,
    gEItemCategory_Written   = 7,
    gEItemCategory_Empty_B   = 8,
    gEItemCategory_Spellbook = 9,
    gEItemCategory_Skill     = 10,
    gEItemCategory_Count     = 11
};

enum gEItemQuality {
    gEItemQuality_None = 0,
    gEItemQuality_Diseased = 2,
    gEItemQuality_Poisoned = 4,
    gEItemQuality_Burning  = 8,
    gEItemQuality_Frozen   = 16,
    gEItemQuality_Sharp    = 32,
    gEItemQuality_Blessed  = 64,
    gEItemQuality_Forged   = 128,
    gEItemQuality_Worn     = 256
};

// gCNPC_PS.LastFightAgainstPlayer

enum gELastFightAgainstPlayer {
    gELastFightAgainstPlayer_None     = 0,
    gELastFightAgainstPlayer_Lost     = 1,
    gELastFightAgainstPlayer_Won      = 2,
    gELastFightAgainstPlayer_Cancel   = 3,
    gELastFightAgainstPlayer_Running  = 4,
    gELastFightAgainstPlayer_Friendly = 5
};

// gCLock_PS.Status

enum gELockStatus {
    gELockStatus_Locked   = 0,
    gELockStatus_Unlocked = 1
};

// gCMagicBarrier_PS.Shape

enum gEMagicBarrierShape {
    gEMagicBarrierShape_EntitySphere = 0,
    gEMagicBarrierShape_EntityBox    = 1,
    gEMagicBarrierShape_Mesh         = 2
};

// eCParticleSystemBase_PS.AlphaDestination
// eCParticleSystemBase_PS.AlphaSource

enum gEMasterBlending {
    // gEMasterBlending_InvSrcAlpha = ???,
    // gEMasterBlending_SrcAlpha = ???
};

// eCParticleSystemBase_PS.AlphaCompareFunction

enum gEMasterCmpFunc {
    // gEMasterCmpFunc_Less = ???
};

// gCDistanceTrigger_PS.MaxDistType

enum gEMaxDistType {
    gEMaxDistType_Manual         = 0,
    gEMaxDistType_NavZone        = 1,
    gEMaxDistType_CollisionShape = 2
};

// gCMover_PS.MoverBehavior

enum gEMoverBehavior {
    gEMoverBehavior_1STATE_PLAYONCE        = 0,
    gEMoverBehavior_2STATE_TOGGLE          = 1,
    gEMoverBehavior_2STATE_TRIGGER_CONTROL = 2
};

// gCMover_PS.MoverState

enum gEMoverState {
    gEMoverState_OPEN    = 0,
    gEMoverState_OPENING = 1,
    gEMoverState_CLOSED  = 2,
    gEMoverState_CLOSING = 3
};

// gCMover_PS.MoverTouchBehavior

enum gEMoverTouchBehavior {
    gEMoverTouchBehavior_NONE   = 0,
    gEMoverTouchBehavior_TOGGLE = 1,
    gEMoverTouchBehavior_WAIT   = 2
};

// gCEffectCommandMusicTrigger.Entrance
// gCMusicTrigger.Entrance

enum gEMusicFragmentPosition {
    gEMusicFragmentPosition_Begin          = 0,
    gEMusicFragmentPosition_Current        = 1,
    gEMusicFragmentPosition_LoopEntrance   = 2,
    gEMusicFragmentPosition_RandomEntrance = 3
};

// gCMusicLink.Type

enum gEMusicLink {
    gEMusicLink_Exit     = 0,
    gEMusicLink_Entrance = 1,
    gEMusicLink_Loop     = 2,
    gEMusicLink_Generic  = 3
};

// gCMusicSequencer.FragmentSequence
// gCMusicSequencer.TransitionSequence

enum gEMusicSequence {
    // gEMusicSequence_Sequential = ???,
    // gEMusicSequence_Shuffle = ???,
    // gEMusicSequence_Random = ???
};

// gCEffectCommandMusicTrigger.Transition
// gCMusicTrigger.Transition

enum gEMusicTransition {
    gEMusicTransition_None                = 0,
    gEMusicTransition_MatchingConnector   = 1,
    gEMusicTransition_SpecifiedConnector  = 2,
    gEMusicTransition_SpecifiedTransition = 3
};

// gCMusicTransition.Timing

enum gEMusicTransitionTiming {
    gEMusicTransitionTiming_Centered        = 0,
    gEMusicTransitionTiming_OverCurrent     = 1,
    gEMusicTransitionTiming_OverNext        = 2,
    gEMusicTransitionTiming_SpecifiedOffset = 3
};

// gCEffectCommandMusicTrigger.Exit
// gCMusicTrigger.Exit

enum gEMusicTriggerTime {
    gEMusicTriggerTime_Immediately      = 0,
    gEMusicTriggerTime_NextExit         = 1,
    gEMusicTriggerTime_NextPriorityExit = 2,
    gEMusicTriggerTime_EndOfFragment    = 3
};

// gCNPC_PS.Type

enum gENPCType {
    gENPCType_Personal  = 0,
    gENPCType_Enclave   = 1,
    gENPCType_Political = 2,
    gENPCType_Friend    = 3
};

// gCCollisionCircle_PS.Type

enum gENavObstacleType {
    gENavObstacleType_Obstacle  = 0,
    gENavObstacleType_Climbable = 1
};

// gCParty_PS.PartyMemberType

enum gEPartyMemberType {
    gEPartyMemberType_None       = 0,
    gEPartyMemberType_Party      = 1,
    gEPartyMemberType_Mob        = 2,
    gEPartyMemberType_Slave      = 3,
    gEPartyMemberType_Controlled = 4,
    gEPartyMemberType_Summoned   = 5
};

// gCEnclave_PS.KnownPlayerCrime
// gCNPC_PS.LastPlayerCrime

enum gEPlayerCrime {
    gEPlayerCrime_None      = 0,
    gEPlayerCrime_Livestock = 1,
    gEPlayerCrime_Attack    = 2,
    gEPlayerCrime_Theft     = 3,
    gEPlayerCrime_Murder    = 4,
    gEPlayerCrime_Count     = 5
};

// gCEnclave_PS.PoliticalAlignment
// gCNPC_PS.PoliticalAlignment
// gCQuest_PS.PoliticalSuccess

enum gEPoliticalAlignment {
    gEPoliticalAlignment_None   = 0,
    gEPoliticalAlignment_Orc    = 1,
    gEPoliticalAlignment_Nrd    = 2,
    gEPoliticalAlignment_Reb    = 3,
    gEPoliticalAlignment_Mid    = 4,
    gEPoliticalAlignment_Ass    = 5,
    gEPoliticalAlignment_Nom    = 6,
    gEPoliticalAlignment_Out    = 7,
    gEPoliticalAlignment_Slave  = 8,
    gEPoliticalAlignment_Pirate = 9,
    gEPoliticalAlignment_Citizen = 10,
    gEPoliticalAlignment_Mid_Torn = 11,
    gEPoliticalAlignment_Partisan = 12,
    gEPoliticalAlignment_Bakaresh = 13,
    gEPoliticalAlignment_Gonzalez = 14,
    gEPoliticalAlignment_Count
};

// gCProjectile_PS.PathStyle

enum gEProjectilePath {
    gEProjectilePath_Line    = 0,
    gEProjectilePath_Curve   = 1,
    gEProjectilePath_Physics = 2,
    gEProjectilePath_Missile = 3
};

// gCProjectile_PS.TouchBehavior

enum gEProjectileTouchBehavior {
    gEProjectileTouchBehavior_KillSelf          = 0,
    gEProjectileTouchBehavior_Reflect           = 1,
    gEProjectileTouchBehavior_Stop              = 2,
    gEProjectileTouchBehavior_MaterialDependant = 3
};

// gCQuest_PS.status

enum gEQuestStatus {
    gEQuestStatus_Open      = 0,
    gEQuestStatus_Running   = 1,
    gEQuestStatus_Success   = 2,
    gEQuestStatus_Failed    = 3,
    gEQuestStatus_Obsolete  = 4,
    gEQuestStatus_Cancelled = 5,
    gEQuestStatus_Lost      = 6,
    gEQuestStatus_Won       = 7
};

// gCQuest_PS.Type

enum gEQuestType {
    gEQuestType_HasItems  = 0,
    gEQuestType_Report    = 1,
    gEQuestType_Kill      = 2,
    gEQuestType_Defeat    = 3,
    gEQuestType_DriveAway = 4,
    gEQuestType_Arena     = 5,
    gEQuestType_BringNpc  = 6,
    gEQuestType_FollowNpc = 7,
    gEQuestType_EnterArea = 8,
    // gEQuestType_??? = 9,
    gEQuestType_FreeEnclave = 10,
    gEQuestType_Plunder     = 11,
    gEQuestType_Sparring    = 12,
    gEQuestType_SpellCast   = 13
};

// gCAIZone_PS.SecurityLevel

enum gESecurityLevel {
    gESecurityLevel_None      = 0,
    gESecurityLevel_Public    = 1,
    gESecurityLevel_Enclave   = 2,
    gESecurityLevel_Political = 3
};

// gCSessionEditor.State

enum gESessionEditorState {
    gESessionEditorState_None            = 0,
    gESessionEditorState_FreeFly         = 1,
    gESessionEditorState_Steering        = 2,
    gESessionEditorState_SteeringWithCam = 3,
    gESessionEditorState_Navigation      = 4,
    gESessionEditorState_Physics         = 5,
    gESessionEditorState_Property        = 6
};

// gCCharacterControl_PS.PressedKey

enum gESessionKey {
    gESessionKey_None                  = 0,
    gESessionKey_Forward               = 1,
    gESessionKey_Backward              = 2,
    gESessionKey_StrafeLeft            = 3,
    gESessionKey_StrafeRight           = 4,
    gESessionKey_TurnPlayerRight       = 5,
    gESessionKey_TurnPlayerLeft        = 6,
    gESessionKey_TurnUp                = 7,
    gESessionKey_TurnDown              = 8,
    gESessionKey_RotateCamRight        = 9,
    gESessionKey_RotateCamLeft         = 10,
    gESessionKey_Walk                  = 11,
    gESessionKey_WalkToggle            = 12,
    gESessionKey_Up                    = 13,
    gESessionKey_Down                  = 14,
    gESessionKey_Use1                  = 15,
    gESessionKey_Use2                  = 16,
    gESessionKey_Plus                  = 17,
    gESessionKey_Minus                 = 18,
    gESessionKey_QuickUse0             = 19,
    gESessionKey_QuickUse1             = 20,
    gESessionKey_QuickUse2             = 21,
    gESessionKey_QuickUse3             = 22,
    gESessionKey_QuickUse4             = 23,
    gESessionKey_QuickUse5             = 24,
    gESessionKey_QuickUse6             = 25,
    gESessionKey_QuickUse7             = 26,
    gESessionKey_QuickUse8             = 27,
    gESessionKey_QuickUse9             = 28,
    gESessionKey_Confirm               = 29,
    gESessionKey_Cancel                = 30,
    gESessionKey_InventoryMode         = 31,
    gESessionKey_JournalModeLog        = 32,
    gESessionKey_JournalModeCharScreen = 33,
    gESessionKey_JournalModeMagBook    = 34,
    gESessionKey_JournalModeMap        = 35,
    gESessionKey_QuickLoad             = 36,
    gESessionKey_QuickSave             = 37,
    gESessionKey_WeaponMode            = 38,
    gESessionKey_Lock                  = 39,
    gESessionKey_Look                  = 40,
    gESessionKey_FirstPerson           = 41,
    gESessionKey_ResetCamera           = 42,

    gESessionKey_MAX = 45
};

// gCInfoManager_PS.lastSessionState
// gCSession.State

enum gESession_State {
    gESession_State_None          = 0,
    gESession_State_Movement      = 1,
    gESession_State_Fight         = 2,
    gESession_State_Ride_Movement = 3,
    gESession_State_Ride_Fight    = 4,
    gESession_State_ItemUse       = 5,
    gESession_State_Inventory     = 6,
    gESession_State_Dialog        = 7,
    gESession_State_Trade         = 8,
    gESession_State_InteractObj   = 9,
    gESession_State_Journal       = 10,
    gESession_State_Editor        = 11
};

// gCSession.Start

enum gESession_StartMode
{
    gESession_StartMode_NewGame  = 0,
    gESession_StartMode_LoadGame = 1
};

// gCRecipe_PS.Craft
// gCSkill_PS.Category

enum gESkillCategory {
    gESkillCategory_Combat   = 0,
    gESkillCategory_Hunting  = 1,
    gESkillCategory_Magic    = 2,
    gESkillCategory_Smithing = 3,
    gESkillCategory_Theft    = 4,
    gESkillCategory_Alchemy  = 5,
    gESkillCategory_Misc     = 6,
    gESkillCategory_Cooking  = 7
};

// gCInventorySlot.Slot

enum gESlot {
    gESlot_None          = 0,
    gESlot_RightHand     = 1,
    gESlot_LeftHand      = 2,
    gESlot_EquipLeftHand = 3,
    gESlot_Beard         = 4,
    gESlot_BackLeft      = 5,
    gESlot_BackRight     = 6,
    gESlot_Bow           = 7,
    gESlot_Crossbow      = 8,
    gESlot_Armor         = 9,
    gESlot_Belt          = 10,
    gESlot_Amulet        = 11,
    gESlot_Ring1         = 12,
    gESlot_Ring2         = 13,
    gESlot_Ammo          = 14,
    gESlot_Hair          = 15,
    gESlot_Head          = 16,
    gESlot_Body          = 17,
    gESlot_Helmet        = 18
};

// gCNPC_PS.Species

enum gESpecies {
    gESpecies_Human        = 0,
    gESpecies_Skeleton     = 1,
    gESpecies_Zombie       = 2,
    gESpecies_Golem        = 3,
    gESpecies_Demon        = 4,
    gESpecies_Orc          = 5,
    gESpecies_Goblin       = 6,
    gESpecies_Troll        = 7,
    gESpecies_Minecrawler  = 8,
    gESpecies_Scavenger    = 9,
    gESpecies_Wolf         = 10,
    gESpecies_Boar         = 11,
    gESpecies_Sabertooth   = 12,
    gESpecies_Shadowbeast  = 13,
    gESpecies_Bison        = 14,
    gESpecies_Rhino        = 15,
    gESpecies_Ripper       = 16,
    gESpecies_Lurker       = 17,
    gESpecies_Varan        = 18,
    gESpecies_Snapper      = 19,
    gESpecies_Alligator    = 20,
    gESpecies_Trex         = 21,
    gESpecies_FireVaran    = 22,
    gESpecies_Bloodfly     = 23,
    gESpecies_Lizard       = 24,
    gESpecies_Fish         = 25,
    gESpecies_Meatbug      = 26,
    gESpecies_Vulture      = 27,
    gESpecies_Rabbit       = 28,
    gESpecies_Deer         = 29,
    gESpecies_Chicken      = 30,
    gESpecies_Molerat      = 31,
    gESpecies_Snake        = 32,
    gESpecies_Pig          = 33,
    gESpecies_Cow          = 34,
    gESpecies_Spider       = 35,
    gESpecies_Turtle       = 36,
    gESpecies_Bird         = 37,
    gESpecies_Gargoyle     = 38,
    gESpecies_SwampLurker  = 39,
    gESpecies_EMPTY_B      = 40,
    gESpecies_Ogre         = 41,
    gESpecies_Ray          = 42,
    gESpecies_Scorpion     = 43,
    gESpecies_Seagull      = 44,
    gESpecies_Walrus       = 45,
    gESpecies_Whale        = 46,
    gESpecies_Eagle        = 47,
    gESpecies_FireGolem    = 48,
    gESpecies_IceGolem     = 49,
    gESpecies_ScorpionKing = 50,
    gESpecies_Stalker      = 51,
    gESpecies_Dragon       = 52
};

// gCMagic_PS.SpellDeity

enum gESpellDeity {
    gESpellDeity_Adanos = 0,
    gESpellDeity_Beliar = 1,
    gESpellDeity_Innos  = 2,
    gESpellDeity_None   = 3
};

// gCMagic_PS.SpellTarget

enum gESpellTarget {
    gESpellTarget_Caster = 0,
    gESpellTarget_Focus  = 1
};

// gCMagic_PS.SpellType

enum gESpellType {
    gESpellType_Projectile = 0,
    gESpellType_Target     = 1,
    gESpellType_Summon     = 2
};

// gCInventoryStack.Type

enum gEStackType {
    gEStackType_Normal      = 0,
    gEStackType_Treasure    = 1,
    gEStackType_Merchandise = 2
};

// gCDialog_PS.TradeCategory

enum gETradeCategory {
    gETradeCategory_None     = 0,
    gETradeCategory_Valuable = 1,
    gETradeCategory_Trophy   = 2,
    gETradeCategory_Empty_A  = 3,
    gETradeCategory_Empty_B  = 4
};

// gCTreasureSet_PS.TreasureDistribution

enum gETreasureDistribution {
    gETreasureDistribution_Plunder        = 0,
    gETreasureDistribution_Unique         = 1,
    gETreasureDistribution_Trophy         = 2,
    gETreasureDistribution_Weaponry       = 3,
    gETreasureDistribution_Trade_Generate = 4,
    gETreasureDistribution_Trade_Refresh  = 5,
    gETreasureDistribution_Mining         = 6,
    gETreasureDistribution_Pickpocket     = 7,
    gETreasureDistribution_NotRandom      = 8,
    gETreasureDistribution_Guard          = 9,
    gETreasureDistribution_Ammunition     = 10
};

// gCInteraction_PS.UseType

enum gEUseType {
    gEUseType_None           = 0,
    gEUseType_Action         = 1,
    gEUseType_1H             = 2,
    gEUseType_2H             = 3,
    gEUseType_Arrow          = 4,
    gEUseType_Bow            = 5,
    gEUseType_CrossBow       = 6,
    gEUseType_Bolt           = 7,
    gEUseType_Fist           = 8,
    gEUseType_Shield         = 9,
    gEUseType_Armor          = 10,
    gEUseType_Helmet         = 11,
    gEUseType_Staff          = 12,
    gEUseType_Amulet         = 13,
    gEUseType_Ring           = 14,
    gEUseType_Cast           = 15,
    gEUseType_Potion         = 16,
    gEUseType_Plant          = 17,
    gEUseType_Meat           = 18,
    gEUseType_Fruit          = 19,
    gEUseType_Bread          = 20,
    gEUseType_Bottle         = 21,
    gEUseType_Cup            = 22,
    gEUseType_Bowl           = 23,
    gEUseType_Torch          = 24,
    gEUseType_Alarmhorn      = 25,
    gEUseType_Broom          = 26,
    gEUseType_Brush          = 27,
    gEUseType_Lute           = 28,
    gEUseType_Rake           = 29,
    gEUseType_TrophyTeeth    = 30,
    gEUseType_Valuable       = 31,
    gEUseType_Smoke          = 32,
    gEUseType_OrcPipe        = 33,
    gEUseType_Scoop          = 34,
    gEUseType_Stick          = 35,
    gEUseType_Shovel         = 36,
    gEUseType_Hammer         = 37,
    gEUseType_Fan            = 38,
    gEUseType_Pan            = 39,
    gEUseType_Saw            = 40,
    gEUseType_TrophySkin     = 41,
    gEUseType_Map            = 42,
    gEUseType_Book           = 43,
    gEUseType_Letter         = 44,
    gEUseType_Key            = 45,
    gEUseType_Lockpick       = 46,
    gEUseType_CarryFront     = 47,
    gEUseType_CarryShoulder  = 48,
    gEUseType_Pickaxe        = 49,
    gEUseType_TrophyFur      = 50,
    gEUseType_Halberd        = 51,
    gEUseType_Axe            = 52,
    gEUseType_ITEM_E         = 53,
    gEUseType_Modify         = 54,
    gEUseType_PhysicalFist   = 55,
    gEUseType_ITEM_H         = 56,
    gEUseType_Anvil          = 57,
    gEUseType_Forge          = 58,
    gEUseType_GrindStone     = 59,
    gEUseType_Cauldron       = 60,
    gEUseType_Barbecue       = 61,
    gEUseType_Alchemy        = 62,
    gEUseType_Bookshelf      = 63,
    gEUseType_Bookstand      = 64,
    gEUseType_TakeStone      = 65,
    gEUseType_DropStone      = 66,
    gEUseType_PickOre        = 67,
    gEUseType_PickGround     = 68,
    gEUseType_DigGround      = 69,
    gEUseType_Field          = 70,
    gEUseType_Repair         = 71,
    gEUseType_SawLog         = 72,
    gEUseType_Lumberjack     = 73,
    gEUseType_Bed            = 74,
    gEUseType_SleepGround    = 75,
    gEUseType_CleanFloor     = 76,
    gEUseType_Dance          = 77,
    gEUseType_FanBoss        = 78,
    gEUseType_Boss           = 79,
    gEUseType_Throne         = 80,
    gEUseType_Pace           = 81,
    gEUseType_Bard           = 82,
    gEUseType_Stool          = 83,
    gEUseType_Bench          = 84,
    gEUseType_Waterpipe      = 85,
    gEUseType_WaterBarrel    = 86,
    gEUseType_PirateTreasure = 87,
    gEUseType_Campfire       = 88,
    gEUseType_SitCampfire    = 89,
    gEUseType_SitGround      = 90,
    gEUseType_Smalltalk      = 91,
    gEUseType_Preach         = 92,
    gEUseType_Spectator      = 93,
    gEUseType_Stand          = 94,
    gEUseType_Guard          = 95,
    gEUseType_Trader         = 96,
    gEUseType_Listener       = 97,
    gEUseType_OrcDance       = 98,
    gEUseType_Stoneplate     = 99,
    gEUseType_OrcDrum        = 100,
    gEUseType_Door           = 101,
    gEUseType_OrcBoulder     = 102,
    gEUseType_EatGround      = 103,
    gEUseType_DrinkWater     = 104,
    gEUseType_Pee            = 105,
    gEUseType_Chest          = 106,
    gEUseType_Shrine         = 107,
    gEUseType_AttackPoint    = 108,
    gEUseType_Roam           = 109,
    gEUseType_BODY_A         = 110,
    gEUseType_Beard          = 111,
    gEUseType_Hair           = 112,
    gEUseType_Head           = 113,
    gEUseType_Body           = 114,
    gEUseType_Flee           = 115,
    gEUseType_Talk           = 116
};

// eCParticleSystemBase_PS.VisualOrientation

enum gEVisualOrientation {
    // gEVisualOrientation_None = ???,
    // gEVisualOrientation_Velo = ???,
    // gEVisualOrientation_Velo3D = ???
};

// gCPlayerMemory_PS.LastWeaponConfig

enum gEWeaponConfig {
    gEWeaponConfig_Melee  = 0,
    gEWeaponConfig_Ranged = 1,
    gEWeaponConfig_Magic  = 2
};

// gCAIZone_PS.ZoneType

enum gEZoneType {
    gEZoneType_Outdoor = 0,
    gEZoneType_Indoor  = 1
};

enum gEGameMessageType
{
    gEGameMessageType_Yellow   = 0,
    gEGameMessageType_Yellow_1 = 1,
    gEGameMessageType_ItemGiven = 2,
    gEGameMessageType_ItemTaken = 3,
    gEGameMessageType_Yellow_2 = 4,
    gEGameMessageType_Learned  = 5,
    gEGameMessageType_White_3  = 6,
    gEGameMessageType_Yellow_3 = 7,
    gEGameMessageType_Success  = 8,
    gEGameMessageType_Green_2  = 9,
    gEGameMessageType_Yellow_4 = 10,
    gEGameMessageType_Yellow_5 = 11,
    gEGameMessageType_Orange   = 12,
    gEGameMessageType_Failure  = 13,
    gEGameMessageType_Yellow_6 = 14,
    gEGameMessageType_Yellow_7 = 15,
    gEGameMessageType_White_4  = 16,
    gEGameMessageType_EnclaveReputation = 17,
    gEGameMessageType_PoliticalReputation = 18
};

enum gEStatusEffect {
    gEStatusEffect_Burning          = 1,
    gEStatusEffect_Frozen           = 2,
    gEStatusEffect_Poisoned         = 4,
    gEStatusEffect_Diseased         = 8,
    gEStatusEffect_Transformed      = 16,
    gEStatusEffect_IsImNebel        = 64,
    gEStatusEffect_IsGhost          = 128,
    gEStatusEffect_IsInMagicBarrier = 256,
    gEStatusEffect_SoultravelActive = 512
};

enum gEFaceAni {
    gEFaceAni_None    = 0,
    gEFaceAni_Neutral = 1,
    gEFaceAni_Angry   = 2
};

enum gEPose {
    gEPose_None= 0,
    gEPose_P0  = 1,
    gEPose_P1  = 2,
    gEPose_P2  = 3,
    gEPose_P3  = 4,
    gEPose_P00 = 5,
    gEPose_P01 = 6,
    gEPose_P02 = 7,
    gEPose_P03 = 8,
    gEPose_P10 = 9,
    gEPose_P11 = 10,
    gEPose_P12 = 11,
    gEPose_P13 = 12,
    gEPose_P20 = 13,
    gEPose_P21 = 14,
    gEPose_P22 = 15,
    gEPose_P23 = 16,
    gEPose_P30 = 17,
    gEPose_P31 = 18,
    gEPose_P32 = 19,
    gEPose_P33 = 20,
    gEPose_P40 = 21,
    gEPose_P50 = 22,
    gEPose_P60 = 23,
    gEPose_P70 = 24
};

enum gEPhase {
    gEPhase_Raise      = 0,
    gEPhase_Hit        = 1,
    gEPhase_Aim        = 2,
    gEPhase_Recover    = 3,
    gEPhase_Begin      = 4,
    gEPhase_Loop       = 5,
    gEPhase_End        = 6,
    gEPhase_Full       = 7,
    gEPhase_Walk       = 8,
    gEPhase_Run        = 9,
    gEPhase_Sprint     = 10,
    gEPhase_Far        = 11,
    gEPhase_Stand      = 12,
    gEPhase_StrafeL    = 13,
    gEPhase_StrafeR    = 14,
    gEPhase_Turn90     = 15,
    gEPhase_Ambient    = 16,
    gEPhase_Proud      = 17,
    gEPhase_Approve    = 18,
    gEPhase_Thoughtful = 19,
    gEPhase_Angry      = 20,
    gEPhase_Threaten   = 21,
    gEPhase_Nervous    = 22,
    gEPhase_Point      = 23,
    gEPhase_Preach     = 24,
    gEPhase_Beg        = 25,
    gEPhase_Sad        = 26,
    gEPhase_None       = 27
};

enum IDD
{
    IDD_MENU_OPTIONS_GAMEPLAY_2           = 30108,
    IDD_PAGE_SLIDESHOW_2                  = 30107,
    IDD_MENU_OPTIONS_CONTROLS_2           = 30105,
    IDD_MENU_OPTIONS_CONTROLS_CUSTOM_2    = 30106,
    IDD_MENU_INTRO_2                      = 30101,
    IDD_MENU_CONFIRM_2                    = 30099,
    IDD_MENU_LOADING_2                    = 30100,
    IDD_MENU_MAIN_2                       = 30089,
    IDD_MENU_OPTIONS_2                    = 30090,
    IDD_MENU_OPTIONS_AUDIO_2              = 30091,
    IDD_MENU_OPTIONS_VIDEO_2              = 30092,
    IDD_MENU_OPTIONS_PERFORMANCE_2        = 30093,
    IDD_MENU_OPTIONS_PERFORMANCE_CUSTOM_2 = 30094,
    IDD_MENU_FILES_2                      = 30095,
    IDD_MENU_CREDITS_2                    = 30096,
    IDD_MENU_DIFFICULTY_2                 = 30097,
    IDD_MENU_OPTIONS_DIFFICULTY_CUSTOM_2  = 30109,
    IDD_PAGE_TRANSFORM_2                  = 30085,
    IDD_PAGE_TUTORIAL_2                   = 30086,
    IDD_VIEW_TRANSFORM_INVENTORY_2        = 30087,
    IDD_VIEW_TUTORIAL_2                   = 30088,
    IDD_VIEW_BAR_SYNTH_PAGES_2            = 30084,
    IDD_VIEW_LOOT_INVENTORY_2             = 30082,
    IDD_VIEW_LOOT_POOL_2                  = 30081,
    IDD_PAGE_LOOT_2                       = 30080,
    IDD_VIEW_TRADE_TRANSACTION_2          = 30077,
    IDD_VIEW_TRADE_INVENTORY_2            = 30078,
    IDD_VIEW_TRADE_VENDOR_2               = 30079,
    IDD_VIEW_LOCATION_2                   = 30076,
    IDD_PAGE_SYNTH_2                      = 30073,
    IDD_VIEW_SYNTH_RECIPE_2               = 30074,
    IDD_VIEW_SYNTH_INVENTORY_2            = 30075,
    IDD_VIEW_AMOUNT_2                     = 30072,
    IDD_PAGE_DIALOG_2                     = 30070,
    IDD_VIEW_DIALOG_2                     = 30071,
    IDD_VIEW_TALK_2                       = 30069,
    IDD_VIEW_SKILL_2                      = 30067,
    IDD_VIEW_RECIPE_2                     = 30066,
    IDD_VIEW_SPELL_2                      = 30065,
    IDD_PAGE_TRADE_2                      = 30063,
    IDD_VIEW_MAP_2                        = 30060,
    IDD_VIEW_BOOK_2                       = 30061,
    IDD_VIEW_LETTER_2                     = 30062,
    IDD_PAGE_SPELLS_2                     = 30059,
    IDD_VIEW_ITEM_2                       = 30058,
    IDD_PAGE_QUESTS_2                     = 30054,
    IDD_PAGE_DOCUMENTS_2                  = 30051,
    IDD_PAGE_INVENTORY_2                  = 30052,
    IDD_PAGE_SKILLS_2                     = 30053,
    IDD_VIEW_BAR_HEALTH_2                 = 30047,
    IDD_VIEW_BAR_MANA_2                   = 30048,
    IDD_VIEW_BAR_ENDURANCE_2              = 30049,
    IDD_VIEW_BAR_FOCUS_2                  = 30050,
    IDD_VIEW_BAR_QUICKSLOTS_2             = 30045,
    IDD_PAGE_MAIN_2                       = 30044,
    IDD_VIEW_DOCUMENT_2                   = 30043,
    IDD_VIEW_BAR_PAGES_2                  = 30042,
    IDD_VIEW_WORLD_2                      = 30041,
    IDD_VIEW_QUESTS_2                     = 30040,
    IDD_VIEW_DOCUMENTS_2                  = 30039,
    IDD_VIEW_SKILLS_2                     = 30038,
    IDD_VIEW_SPELLS_2                     = 30037,
    IDD_VIEW_INVENTORY_2                  = 30036,
    IDD_VIEW_CHARACTER_2                  = 30035
};

enum IDC
{
    IDC_BUTTON_MENU_OPTIONS_GAMEPLAY_2                = 20870,
    IDC_BUTTON_MENU_OPTIONS_GAMEPLAY_BACK_2           = 20871,
    IDC_LABEL_GAMEPLAY_TUTORIAL_2                     = 20872,
    IDC_VALUE_GAMEPLAY_TUTORIAL_2                     = 20873,
    IDC_SLIDER_GAMEPLAY_TUTORIAL_2                    = 20874,
    IDC_LABEL_GAMEPLAY_LOCKPICKING_2                  = 20875,
    IDC_SLIDER_GAMEPLAY_LOCKPICKING_2                 = 20876,
    IDC_VALUE_GAMEPLAY_LOCKPICKING_2                  = 20877,
    IDC_LABEL_GAMEPLAY_UNOBSERVED_CRIMES_2            = 20895,
    IDC_SLIDER_GAMEPLAY_UNOBSERVED_CRIMES_2           = 20896,
    IDC_VALUE_GAMEPLAY_UNOBSERVED_CRIMES_2            = 20897,
    IDC_STATIC_SLIDESHOW_SUBTITLE_2                   = 20757,
    IDC_STATIC_SLIDESHOW_HEADER_2                     = 20756,
    IDC_STATIC_SLIDESHOW_PICTURE_2                    = 20755,
    IDC_VALUE_CONTROLS_CAMLOOKAROUNDINVERSE_2         = 20795,
    IDC_SLIDER_CONTROLS_CAMLOOKAROUNDINVERSE_2        = 20794,
    IDC_LABEL_CONTROLS_CAMLOOKAROUNDINVERSE_2         = 20793,
    IDC_VALUE_CONTROLS_ALT_CAMERA_2                   = 20751,
    IDC_SLIDER_CONTROLS_ALT_CAMERA_2                  = 20750,
    IDC_LABEL_CONTROLS_ALT_CAMERA_2                   = 20749,
    IDC_VALUE_CONTROLS_SMOOTHING_YAXIS_2              = 20745,
    IDC_VALUE_CONTROLS_SMOOTHING_XAXIS_2              = 20744,
    IDC_SLIDER_CONTROLS_SMOOTHING_YAXIS_2             = 20743,
    IDC_SLIDER_CONTROLS_SMOOTHING_XAXIS_2             = 20742,
    IDC_LABEL_CONTROLS_SMOOTHING_YAXIS_2              = 20741,
    IDC_LABEL_CONTROLS_SMOOTHING_XAXIS_2              = 20740,
    IDC_LABEL_CONTROLS_KEYBOARD_2                     = 20738,
    IDC_LABEL_CONTROLS_MOUSE_2                        = 20737,
    IDC_RADIOBUTTON_CONTROLS_STANDARD_2               = 20736,
    IDC_RADIOBUTTON_CONTROLS_CUSTOM_2                 = 20735,
    IDC_LABEL_CONTROLS_INVERT_XAXIS_2                 = 20734,
    IDC_LABEL_CONTROLS_INVERT_YAXIS_2                 = 20733,
    IDC_SLIDER_CONTROLS_INVERT_XAXIS_2                = 20732,
    IDC_SLIDER_CONTROLS_INVERT_YAXIS_2                = 20731,
    IDC_VALUE_CONTROLS_INVERT_XAXIS_2                 = 20730,
    IDC_VALUE_CONTROLS_INVERT_YAXIS_2                 = 20729,
    IDC_LABEL_CONTROLS_SENSITIVITY_XAXIS_2            = 20728,
    IDC_LABEL_CONTROLS_SENSITIVITY_YAXIS_2            = 20727,
    IDC_SLIDER_CONTROLS_SENSITIVITY_XAXIS_2           = 20726,
    IDC_SLIDER_CONTROLS_SENSITIVITY_YAXIS_2           = 20725,
    IDC_VALUE_CONTROLS_SENSITIVITY_XAXIS_2            = 20724,
    IDC_VALUE_CONTROLS_SENSITIVITY_YAXIS_2            = 20723,
    IDC_BUTTON_MENU_OPTIONS_CONTROLS_BACK_2           = 20722,
    IDC_VIEW_MENU_CONTROLS_CUSTOM_REQUEST_2           = 20783,
    IDC_STATIC_CONTROLS_CUSTOM_KEYMAPPING_2           = 20782,
    IDC_LISTCTRL_CONTROLS_CUSTOM_KEYMAPPING_2         = 20781,
    IDC_BUTTON_MENU_OPTIONS_CONTROLS_CUSTOM_BACK_2    = 20739,
    IDC_ANIMATECTRL_INTRO_2                           = 20719,
    IDC_BUTTON_MENU_REQUEST_IGNORE_2                  = 20712,
    IDC_BUTTON_MENU_REQUEST_YES_2                     = 20711,
    IDC_BUTTON_MENU_REQUEST_NO_2                      = 20710,
    IDC_LABEL_MENU_REQUEST_2                          = 20709,
    IDC_STATIC_MENU_LOADING_2                         = 20717,
    IDC_STATIC_MENU_LOADING_SLIDE_2                   = 20715,
    IDC_PROGRESSBAR_MENU_LOADING_2                    = 20716,
    IDC_BUTTON_MENU_ALTERNATIVE_BALANCING_OFF_2       = 20827,
    IDC_BUTTON_MENU_ALTERNATIVE_BALANCING_ON_2        = 20826,
    IDC_STATIC_MENU_ALTERNATIVE_BALANCING_IMAGE_OFF_2 = 20825,
    IDC_STATIC_MENU_ALTERNATIVE_BALANCING_IMAGE_ON_2  = 20824,
    IDC_STATIC_MENU_ALTERNATIVE_BALANCING_OFF_2       = 20820,
    IDC_STATIC_MENU_ALTERNATIVE_BALANCING_ON_2        = 20819,
    IDC_STATIC_MENU_ALTERNATIVE_BALANCING_2           = 20816,
    IDC_STATIC_APP_VERSION2                           = 20812,
    IDC_BUTTON_MENU_QUIT_2                            = 20720,
    IDC_VIEW_MENU_MAIN_REQUEST_2                      = 20714,
    IDC_BUTTON_MENU_DEBUG_2                           = 20683,
    IDC_BUTTON_MENU_MAIN_BACK_2                       = 20578,
    IDC_BUTTON_MENU_CREDITS_2                         = 20576,
    IDC_BUTTON_MENU_OPTIONS_2                         = 20575,
    IDC_BUTTON_MENU_SAVE_GAME_2                       = 20574,
    IDC_BUTTON_MENU_LOAD_GAME_2                       = 20573,
    IDC_BUTTON_MENU_NEW_GAME_2                        = 20571,
    IDC_VIEW_MENU_OPTIONS_REQUEST_2                   = 20718,
    IDC_BUTTON_MENU_OPTIONS_BACK_2                    = 20694,
    IDC_BUTTON_MENU_OPTIONS_DIFFICULTY_2              = 20583,
    IDC_BUTTON_MENU_OPTIONS_CONTROLS_2                = 20582,
    IDC_BUTTON_MENU_OPTIONS_AUDIO_2                   = 20581,
    IDC_BUTTON_MENU_OPTIONS_VIDEO_2                   = 20580,
    IDC_BUTTON_MENU_OPTIONS_PERFORMANCE_2             = 20579,
    IDC_LABEL_AUDIO_RESET_WARNING_2                   = 20784,
    IDC_LABEL_AUDIO_SUBTITLES_ONOFF_2                 = 20754,
    IDC_SLIDER_AUDIO_SUBTITLES_ONOFF_2                = 20753,
    IDC_VALUE_AUDIO_SUBTITLES_ONOFF_2                 = 20752,
    IDC_BUTTON_MENU_OPTIONS_AUDIO_BACK_2              = 20695,
    IDC_VALUE_AUDIO_LANGUAGE_SUBTITLES_2              = 20619,
    IDC_VALUE_AUDIO_SPEAKER_SETUP_2                   = 20617,
    IDC_VALUE_AUDIO_VOLUME_AMBIENT_2                  = 20616,
    IDC_VALUE_AUDIO_VOLUME_EFFECTS_2                  = 20615,
    IDC_VALUE_AUDIO_VOLUME_MUSIC_2                    = 20614,
    IDC_VALUE_AUDIO_VOLUME_VOICE_2                    = 20613,
    IDC_VALUE_AUDIO_VOLUME_MASTER_2                   = 20612,
    IDC_SLIDER_AUDIO_SPEAKER_SETUP_2                  = 20610,
    IDC_SLIDER_AUDIO_LANGUAGE_SUBTITLES_2             = 20609,
    IDC_SLIDER_AUDIO_VOLUME_AMBIENT_2                 = 20607,
    IDC_SLIDER_AUDIO_VOLUME_EFFECTS_2                 = 20606,
    IDC_SLIDER_AUDIO_VOLUME_MUSIC_2                   = 20605,
    IDC_SLIDER_AUDIO_VOLUME_VOICE_2                   = 20604,
    IDC_SLIDER_AUDIO_VOLUME_MASTER_2                  = 20603,
    IDC_LABEL_AUDIO_LANGUAGE_SUBTITLES_2              = 20601,
    IDC_LABEL_AUDIO_SPEAKER_SETUP_2                   = 20599,
    IDC_LABEL_AUDIO_VOLUME_AMBIENT_2                  = 20598,
    IDC_LABEL_AUDIO_VOLUME_EFFECTS_2                  = 20597,
    IDC_LABEL_AUDIO_VOLUME_MUSIC_2                    = 20596,
    IDC_LABEL_AUDIO_VOLUME_VOICE_2                    = 20595,
    IDC_LABEL_AUDIO_VOLUME_MASTER_2                   = 20594,
    IDC_LABEL_VIDEO_VSYNC_2                           = 20799,
    IDC_VALUE_VIDEO_VSYNC_2                           = 20798,
    IDC_SLIDER_VIDEO_VSYNC_2                          = 20797,
    IDC_LABEL_VIDEO_RESET_WARNING_2                   = 20778,
    IDC_BUTTON_MENU_OPTIONS_VIDEO_BACK_2              = 20698,
    IDC_VALUE_VIDEO_GAMMA_BLUE_2                      = 20637,
    IDC_VALUE_VIDEO_GAMMA_GREEN_2                     = 20636,
    IDC_VALUE_VIDEO_GAMMA_RED_2                       = 20635,
    IDC_VALUE_VIDEO_CONTRAST_2                        = 20634,
    IDC_VALUE_VIDEO_BRIGHTNESS_2                      = 20633,
    IDC_SLIDER_VIDEO_GAMMA_BLUE_2                     = 20632,
    IDC_SLIDER_VIDEO_GAMMA_GREEN_2                    = 20631,
    IDC_SLIDER_VIDEO_GAMMA_RED_2                      = 20630,
    IDC_SLIDER_VIDEO_CONTRAST_2                       = 20629,
    IDC_SLIDER_VIDEO_BRIGHTNESS_2                     = 20628,
    IDC_LABEL_VIDEO_GAMMA_BLUE_2                      = 20627,
    IDC_LABEL_VIDEO_GAMMA_GREEN_2                     = 20626,
    IDC_LABEL_VIDEO_GAMMA_RED_2                       = 20625,
    IDC_LABEL_VIDEO_CONTRAST_2                        = 20624,
    IDC_LABEL_VIDEO_BRIGHTNESS_2                      = 20623,
    IDC_LABEL_VIDEO_RESOLUTION_2                      = 20622,
    IDC_SLIDER_VIDEO_RESOLUTION_2                     = 20621,
    IDC_VALUE_VIDEO_RESOLUTION_2                      = 20620,
    IDC_RADIOBUTTON_PERFORMANCE_VERYHIGH_2            = 20792,
    IDC_RADIOBUTTON_PERFORMANCE_CUSTOM_2              = 20704,
    IDC_RADIOBUTTON_PERFORMANCE_LOW_2                 = 20703,
    IDC_RADIOBUTTON_PERFORMANCE_MEDIUM_2              = 20702,
    IDC_RADIOBUTTON_PERFORMANCE_HIGH_2                = 20701,
    IDC_BUTTON_MENU_OPTIONS_PERFORMANCE_BACK_2        = 20696,
    IDC_SLIDER_PERFORMANCE_COLORGRADING_2             = 20841,
    IDC_VALUE_PERFORMANCE_COLORGRADING_2              = 20840,
    IDC_LABEL_PERFORMANCE_COLORGRADING_2              = 20839,
    IDC_VALUE_PERFORMANCE_FEEDBACK_2                  = 20838,
    IDC_SLIDER_PERFORMANCE_FEEDBACK_2                 = 20837,
    IDC_LABEL_PERFORMANCE_FEEDBACK_2                  = 20834,
    IDC_VALUE_PERFORMANCE_NOISE_2                     = 20833,
    IDC_SLIDER_PERFORMANCE_NOISE_2                    = 20832,
    IDC_LABEL_PERFORMANCE_NOISE_2                     = 20831,
    IDC_VALUE_PERFORMANCE_VEGETATION_VIEW_RANGE_2     = 20815,
    IDC_SLIDER_PERFORMANCE_VEGETATION_VIEW_RANGE_2    = 20814,
    IDC_LABEL_PERFORMANCE_VEGETATION_VIEW_RANGE_2     = 20813,
    IDC_VALUE_PERFORMANCE_EDGEBLUR_2                  = 20811,
    IDC_SLIDER_PERFORMANCE_EDGEBLUR_2                 = 20810,
    IDC_LABEL_PERFORMANCE_EDGEBLUR_2                  = 20809,
    IDC_VALUE_PERFORMANCE_BLOOM_2                     = 20808,
    IDC_SLIDER_PERFORMANCE_BLOOM_2                    = 20807,
    IDC_LABEL_PERFORMANCE_BLOOM_2                     = 20806,
    IDC_VALUE_PERFORMANCE_DEPTH_OF_FIELD_2            = 20805,
    IDC_SLIDER_PERFORMANCE_DEPTH_OF_FIELD_2           = 20804,
    IDC_LABEL_PERFORMANCE_DEPTH_OF_FIELD_2            = 20803,
    IDC_VALUE_PERFORMANCE_LENSFLARE_2                 = 20790,
    IDC_SLIDER_PERFORMANCE_LENSFLARE_2                = 20789,
    IDC_LABEL_PERFORMANCE_LENSFLARE_2                 = 20788,
    IDC_SLIDER_PERFORMANCE_TEXTURE_QUALITY_2          = 20661,
    IDC_SLIDER_PERFORMANCE_TEXTURE_FILTERING_2        = 20662,
    IDC_LABEL_PERFORMANCE_RESET_WARNING_2             = 20777,
    IDC_BUTTON_MENU_OPTIONS_PERFORMANCE_CUSTOM_BACK_2 = 20697,
    IDC_VALUE_PERFORMANCE_SHADOWS_DETAIL_2            = 20680,
    IDC_VALUE_PERFORMANCE_VEGETATION_QUALITY_2        = 20677,
    IDC_VALUE_PERFORMANCE_TEXTURE_FILTERING_2         = 20676,
    IDC_VALUE_PERFORMANCE_TEXTURE_QUALITY_2           = 20675,
    IDC_VALUE_PERFORMANCE_OBJECT_DETAIL_2             = 20672,
    IDC_VALUE_PERFORMANCE_LOW_DETAL_DISTANCE_2        = 20670,
    IDC_VALUE_PERFORMANCE_HIGH_DETAL_DISTANCE_2       = 20669,
    IDC_SLIDER_PERFORMANCE_SHADOWS_DETAIL_2           = 20666,
    IDC_SLIDER_PERFORMANCE_VEGETATION_QUALITY_2       = 20663,
    IDC_SLIDER_PERFORMANCE_OBJECT_DETAIL_2            = 20658,
    IDC_SLIDER_PERFORMANCE_LOW_DETAL_DISTANCE_2       = 20656,
    IDC_SLIDER_PERFORMANCE_HIGH_DETAL_DISTANCE_2      = 20655,
    IDC_LABEL_PERFORMANCE_TEXTURE_FILTERING_2         = 20652,
    IDC_LABEL_PERFORMANCE_OBJECT_DETAIL_2             = 20649,
    IDC_LABEL_PERFORMANCE_TEXTURE_QUALITY_2           = 20648,
    IDC_LABEL_PERFORMANCE_VEGETATION_QUALITY_2        = 20646,
    IDC_LABEL_PERFORMANCE_SHADOWS_DETAIL_2            = 20645,
    IDC_LABEL_PERFORMANCE_LOW_DETAL_DISTANCE_2        = 20640,
    IDC_LABEL_PERFORMANCE_HIGH_DETAL_DISTANCE_2       = 20639,
    IDC_VIEW_MENU_FILES_REQUEST_2                     = 20713,
    IDC_BUTTON_MENU_FILES_DELETE_2                    = 20708,
    IDC_BUTTON_MENU_FILES_LOAD_SAVE_2                 = 20707,
    IDC_LISTCTRL_MENU_FILES_2                         = 20706,
    IDC_BUTTON_MENU_FILES_BACK_2                      = 20693,
    IDC_ANIMATECTRL_CREDITS_2                         = 20762,
    IDC_BUTTON_MENU_CREDITS_BACK_2                    = 20691,
    IDC_RADIOBUTTON_MENU_DIFFICULTY_CUSTOM_2          = 20878,
    IDC_CHECKBOX_MENU_DIFFICULTY_AIMODE_2             = 20796,
    IDC_BUTTON_MENU_DIFFICULTY_BACK_2                 = 20692,
    IDC_RADIOBUTTON_MENU_DIFFICULTY_HARD_2            = 20592,
    IDC_RADIOBUTTON_MENU_DIFFICULTY_MEDIUM_2          = 20591,
    IDC_RADIOBUTTON_MENU_DIFFICULTY_EASY_2            = 20590,
    IDC_VIEW_TRANSFORM_ITEM_2                         = 20558,
    IDC_VIEW_TRANSFORM_PAGES_2                        = 20550,
    IDC_VIEW_TRANSFORM_INVENTORY_2                    = 20549,
    IDC_VIEW_TRANSFORM_AMOUNT_2                       = 20548,
    IDC_VIEW_TUTORIAL_2                               = 20551,
    IDC_LISTCTRL_TRANSFORM_2                          = 20557,
    IDC_LABEL_TRANSFORM_2                             = 20556,
    IDC_BUTTON_TUTORIAL_OK_2                          = 20555,
    IDC_CHECKBOX_TUTORIAL_2                           = 20554,
    IDC_LABEL_TUTORIAL_MESSAGE_2                      = 20553,
    IDC_LABEL_TUTORIAL_2                              = 20552,
    IDC_BUTTON_SYNTH_CLOSE_2                          = 20547,
    IDC_TABCTRL_LOOT_INVENTORY_2                      = 20530,
    IDC_LISTCTRL_LOOT_INVENTORY_2                     = 20529,
    IDC_LABEL_LOOT_PLAYER_GOLD_2                      = 20527,
    IDC_VALUE_LOOT_PLAYER_GOLD_2                      = 20526,
    IDC_LABEL_LOOT_INVENTORY_2                        = 20525,
    IDC_LISTCTRL_LOOT_2                               = 20521,
    IDC_LABEL_LOOT_GOLD_2                             = 20520,
    IDC_VALUE_LOOT_GOLD_2                             = 20519,
    IDC_BUTTON_LOOT_CLOSE_2                           = 20518,
    IDC_BUTTON_LOOT_TAKE_ALL_2                        = 20517,
    IDC_LABEL_LOOT_2                                  = 20516,
    IDC_VIEW_LOOT_ITEM_2                              = 20515,
    IDC_VIEW_LOOT_POOL_2                              = 20514,
    IDC_VIEW_LOOT_INVENTORY_2                         = 20513,
    IDC_LISTCTRL_TRADE_POOL_PLAYER_2                  = 20511,
    IDC_LISTCTRL_TRADE_POOL_VENDOR_2                  = 20510,
    IDC_BUTTON_TRADE_POOL_PLAYER_CLEAR_2              = 20508,
    IDC_BUTTON_TRADE_GOLD_EXCHANGE_2                  = 20505,
    IDC_BUTTON_TRADE_ACCEPT_2                         = 20506,
    IDC_BUTTON_TRADE_CANCEL_2                         = 20507,
    IDC_BUTTON_TRADE_POOL_VENDOR_CLEAR_2              = 20504,
    IDC_VALUE_TRADE_POOL_PLAYER_GOLD_2                = 20503,
    IDC_LABEL_TRADE_POOL_PLAYER_GOLD_2                = 20502,
    IDC_VALUE_TRADE_POOL_VENDOR_GOLD_2                = 20501,
    IDC_LABEL_TRADE_POOL_VENDOR_GOLD_2                = 20500,
    IDC_LISTCTRL_TRADE_PLAYER_INVENTORY_2             = 20499,
    IDC_TABCTRL_TRADE_PLAYER_CATEGORY_2               = 20498,
    IDC_LABEL_TRADE_PLAYER_CATEGORY_2                 = 20497,
    IDC_VALUE_TRADE_PLAYER_2                          = 20496,
    IDC_LABEL_TRADE_PLAYER_GOLD_2                     = 20495,
    IDC_VALUE_TRADE_VENDOR_GOLD_2                     = 20494,
    IDC_LABEL_TRADE_VENDOR_GOLD_2                     = 20493,
    IDC_LISTCTRL_TRADE_VENDOR_2                       = 20490,
    IDC_LABEL_VENDOR_2                                = 20487,
    IDC_VALUE_FAME_2                                  = 20482,
    IDC_LABEL_FAME_2                                  = 20481,
    IDC_LABEL_LOCATION_2                              = 20480,
    IDC_STATIC_ICON_LOCATION_2                        = 20479,
    IDC_VIEW_SYNTH_PAGES_2                            = 20546,
    IDC_VIEW_SYNTH_AMOUNT_2                           = 20461,
    IDC_VIEW_SYNTH_RECIPE_2                           = 20460,
    IDC_VIEW_SYNTH_INVENTORY_2                        = 20459,
    IDC_VIEW_SYNTH_RECIPE_INNER_2                     = 20462,
    IDC_LABEL_SYNTH_2                                 = 20464,
    IDC_LISTCTRL_SYNTH_INVENTORY_2                    = 20463,
    IDC_BUTTON_AMOUNT_OK_2                            = 20454,
    IDC_SLIDER_AMOUNT_2                               = 20458,
    IDC_BUTTON_AMOUNT_CANCEL_2                        = 20455,
    IDC_VALUE_AMOUNT_2                                = 20457,
    IDC_LABEL_AMOUNT_2                                = 20456,
    IDC_VIEW_DIALOG_2                                 = 20453,
    IDC_LISTCTRL_DIALOG_2                             = 20452,
    IDC_LABEL_TALK_2                                  = 20451,
    IDC_LABEL_SKILL_REQ_2                             = 20450,
    IDC_LABEL_SKILL_DESC_2                            = 20449,
    IDC_LABEL_SKILL_2                                 = 20448,
    IDC_STATIC_RECIPE_REQ_SKILLS_2                    = 20445,
    IDC_STATIC_INGREDIENTS_2                          = 20444,
    IDC_LABEL_RECIPE_REQ_SKILLS_2                     = 20443,
    IDC_LABEL_INGREDIENTS_2                           = 20442,
    IDC_STATIC_RECIPE_ITEM_STATS_2                    = 20441,
    IDC_STATIC_RECIPE_DESC_2                          = 20440,
    IDC_STATIC_RECIPE_ICON_2                          = 20439,
    IDC_LABEL_RECIPE_2                                = 20438,
    IDC_LABEL_SPELL_REQ_2                             = 20437,
    IDC_LABEL_SPELL_DESC_2                            = 20436,
    IDC_LABEL_SPELL_2                                 = 20435,
    IDC_VIEW_TRADE_AMOUNT_2                           = 20485,
    IDC_VIEW_TRADE_TRANSACTION_2                      = 20486,
    IDC_VIEW_TRADE_INVENTORY_2                        = 20484,
    IDC_VIEW_TRADE_VENDOR_2                           = 20483,
    IDC_VIEW_TRADE_ITEM_2                             = 20512,
    IDC_STATIC_MAP_2                                  = 20543,
    IDC_LABEL_BOOK_RIGHT_2                            = 20540,
    IDC_LABEL_BOOK_LEFT_2                             = 20539,
    IDC_LABEL_BOOK_HEADER_2                           = 20538,
    IDC_LABEL_LETTER_TEXT_2                           = 20536,
    IDC_LABEL_LETTER_HEADER_2                         = 20535,
    IDC_STATIC_VIEW_SPELLS_2                          = 20433,
    IDC_TABLE_ITEM_STATS_2                            = 20531,
    IDC_LABEL_ITEM_DESC_2                             = 20430,
    IDC_STATIC_ITEM_ICON_2                            = 20429,
    IDC_LABEL_ITEM_2                                  = 20428,
    IDC_VIEW_QUESTS_2                                 = 20398,
    IDC_VIEW_DOCUMENT_LIST_2                          = 20392,
    IDC_VIEW_DOCUMENT_2                               = 20391,
    IDC_STATIC_VIEW_ITEM_2                            = 20434,
    IDC_VIEW_INVENTORY_2                              = 20394,
    IDC_VIEW_INVENTORY_CHARACTER_2                    = 20393,
    IDC_VIEW_SKILLS_2                                 = 20396,
    IDC_VIEW_CHARACTER_2                              = 20395,
    IDC_PROGRESSBAR_HEALTH_2                          = 20384,
    IDC_PROGRESSBAR_MANA_2                            = 20383,
    IDC_PROGRESSBAR_ENDURANCE_2                       = 20382,
    IDC_PROGRESSBAR_FOCUS_2                           = 20381,
    IDC_LISTCTRL_QUICKSLOTS_2                         = 20380,
    IDC_STATIC_COMPASS_2                              = 20545,
    IDC_STATIC_GAME_MESSAGES_2                        = 20533,
    IDC_VIEW_TALK_2                                   = 20524,
    IDC_VIEW_BAR_MANA_2                               = 20389,
    IDC_VIEW_BAR_ENDURANCE_2                          = 20388,
    IDC_VIEW_BAR_HEALTH_2                             = 20387,
    IDC_VIEW_BAR_FOCUS_2                              = 20386,
    IDC_VIEW_LOG_2                                    = 20385,
    IDC_VIEW_BAR_QUICKSLOTS_2                         = 20379,
    IDC_VIEW_BAR_PAGES_2                              = 20378,
    IDC_VIEW_MAP_2                                    = 20542,
    IDC_VIEW_LETTER_2                                 = 20534,
    IDC_VIEW_BOOK_2                                   = 20537,
    IDC_VIEW_RECIPE_2                                 = 20541,
    IDC_TABCTRL_PAGES_2                               = 20399,
    IDC_BUTTON_CLOSE_2                                = 20400,
    IDC_LABEL_LOCATION_MAIN_2                         = 20523,
    IDC_LABEL_LOCATION_WORLD_2                        = 20522,
    IDC_LABEL_LOCATION_WILDERNESS_2                   = 20863,
    IDC_BUTTON_LOCATION_MAIN                          = 20427,
    IDC_BUTTON_LOCATION_WORLD                         = 20426,
    IDC_BUTTON_LOCATION_FARING                        = 20407,
    IDC_BUTTON_LOCATION_GOTHA                         = 20410,
    IDC_BUTTON_LOCATION_WOLF_CLAN                     = 20425,
    IDC_BUTTON_LOCATION_VANGARD                       = 20424,
    IDC_BUTTON_LOCATION_TRELIS                        = 20422,
    IDC_BUTTON_LOCATION_SILDEN                        = 20421,
    IDC_BUTTON_LOCATION_REDDOCK                       = 20420,
    IDC_BUTTON_LOCATION_OKARA                         = 20419,
    IDC_BUTTON_LOCATION_NEMORA                        = 20418,
    IDC_BUTTON_LOCATION_MORA_SUL                      = 20417,
    IDC_BUTTON_LOCATION_MONTERA                       = 20416,
    IDC_BUTTON_LOCATION_LAGO                          = 20415,
    IDC_BUTTON_LOCATION_KAP_DUN                       = 20414,
    IDC_BUTTON_LOCATION_ISHTAR                        = 20413,
    IDC_BUTTON_LOCATION_INNOS_MONASTERY               = 20412,
    IDC_BUTTON_LOCATION_HAMMER_CLAN                   = 20411,
    IDC_BUTTON_LOCATION_GELDERN                       = 20409,
    IDC_BUTTON_LOCATION_FIRE_CLAN                     = 20408,
    IDC_BUTTON_LOCATION_BRAGA                         = 20406,
    IDC_BUTTON_LOCATION_BEN_SALA                      = 20405,
    IDC_BUTTON_LOCATION_BEN_ERAI                      = 20404,
    IDC_BUTTON_LOCATION_BAKARESH                      = 20403,
    IDC_BUTTON_LOCATION_ARDEA                         = 20402,
    IDC_BUTTON_LOCATION_ORTEGA                        = 20846,
    IDC_BUTTON_LOCATION_WILDERNESS                    = 20862,
    IDC_BUTTON_LOCATION_ALSHEDIM                      = 20864,
    IDC_BUTTON_LOCATION_PIRATES                       = 20865,
    IDC_BUTTON_LOCATION_KLAMMHAYN                     = 20866,
    IDC_STATIC_INGAMETIME                             = 20786,
    IDC_VALUE_INGAMETIME                              = 20785,
    IDC_TABCTRL_QUESTS_2                              = 20374,
    IDC_VIEW_LOCATION_2                               = 20478,
    IDC_VALUE_FAME_NOMADS_2                           = 20477,
    IDC_VALUE_FAME_ASSASSINS_2                        = 20476,
    IDC_VALUE_FAME_DRUIDS_2                           = 20475,
    IDC_VALUE_FAME_REBELS_2                           = 20474,
    IDC_VALUE_FAME_ORCS_2                             = 20473,
    IDC_VALUE_FAME_NORDMAR_2                          = 20472,
    IDC_LABEL_FAME_NOMADS_2                           = 20470,
    IDC_LABEL_FAME_ASSASSINS_2                        = 20469,
    IDC_LABEL_FAME_DRUIDS_2                           = 20468,
    IDC_LABEL_FAME_REBELS_2                           = 20467,
    IDC_LABEL_FAME_ORCS_2                             = 20466,
    IDC_LABEL_FAME_NORDMAR_2                          = 20465,
    IDC_VIEW_WORLD_2                                  = 20401,
    IDC_STATIC_INFOS_2                                = 20377,
    IDC_LISTCTRL_QUESTS_2                             = 20376,
    IDC_LABEL_QUESTS_2                                = 20372,
    IDC_LISTCTRL_DOCUMENTS_2                          = 20371,
    IDC_TABCTRL_DOCUMENTS_2                           = 20370,
    IDC_LABEL_DOCUMENTS_2                             = 20368,
    IDC_VIEW_SKILL_2                                  = 20447,
    IDC_LISTCTRL_MISC_2                               = 20366,
    IDC_LISTCTRL_ALCHEMY_2                            = 20365,
    IDC_LISTCTRL_THEFT_2                              = 20364,
    IDC_LISTCTRL_SMITHING_2                           = 20363,
    IDC_LABEL_SMITHING_2                              = 20362,
    IDC_LISTCTRL_MAGIC_2                              = 20361,
    IDC_LISTCTRL_HUNT_2                               = 20360,
    IDC_LISTCTRL_COMBAT_2                             = 20359,
    IDC_LABEL_MISC_2                                  = 20358,
    IDC_LABEL_ALCHEMY_2                               = 20357,
    IDC_LABEL_THEFT_2                                 = 20356,
    IDC_LABEL_MAGIC_2                                 = 20355,
    IDC_LABEL_HUNT_2                                  = 20354,
    IDC_LABEL_COMBAT_2                                = 20353,
    IDC_LABEL_INNOS_2                                 = 20352,
    IDC_LABEL_ADANOS_2                                = 20351,
    IDC_LISTCTRL_ADANOS_2                             = 20350,
    IDC_LABEL_BELIAR_2                                = 20349,
    IDC_LISTCTRL_BELIAR_2                             = 20348,
    IDC_VIEW_SPELL_2                                  = 20347,
    IDC_LISTCTRL_INNOS_2                              = 20346,
    IDC_LABEL_INVENTORY_2                             = 20345,
    IDC_VALUE_GOLD_2                                  = 20344,
    IDC_LABEL_GOLD_2                                  = 20343,
    IDC_TABCTRL_INVENTORY_2                           = 20342,
    IDC_LISTCTRL_INVENTORY_2                          = 20340,
    IDC_VALUE_PRO_LTG_2                               = 20339,
    IDC_VALUE_PRO_ICE_2                               = 20338,
    IDC_VALUE_PRO_FIR_2                               = 20337,
    IDC_VALUE_PRO_MIS_2                               = 20336,
    IDC_VALUE_PRO_IMP_2                               = 20335,
    IDC_VALUE_PRO_BLD_2                               = 20334,
    IDC_LABEL_PRO_LTG_2                               = 20333,
    IDC_LABEL_PRO_ICE_2                               = 20332,
    IDC_LABEL_PRO_FIR_2                               = 20331,
    IDC_LABEL_PRO_MIS_2                               = 20330,
    IDC_LABEL_PRO_IMP_2                               = 20329,
    IDC_LABEL_PRO_BLD_2                               = 20328,
    IDC_VALUE_MP_2                                    = 20327,
    IDC_VALUE_SP_2                                    = 20326,
    IDC_VALUE_HP_2                                    = 20325,
    IDC_VALUE_ALC_2                                   = 20324,
    IDC_VALUE_THF_2                                   = 20323,
    IDC_VALUE_SMT_2                                   = 20318,
    IDC_VALUE_INT_2                                   = 20317,
    IDC_VALUE_HNT_2                                   = 20316,
    IDC_VALUE_STR_2                                   = 20315,
    IDC_LABEL_MP_2                                    = 20314,
    IDC_LABEL_SP_2                                    = 20313,
    IDC_LABEL_HP_2                                    = 20312,
    IDC_LABEL_ALC_2                                   = 20311,
    IDC_LABEL_THF_2                                   = 20310,
    IDC_LABEL_SMT_2                                   = 20305,
    IDC_LABEL_INT_2                                   = 20304,
    IDC_LABEL_HNT_2                                   = 20303,
    IDC_LABEL_STR_2                                   = 20302,
    IDC_VALUE_LP_2                                    = 20301,
    IDC_VALUE_TNL_2                                   = 20300,
    IDC_VALUE_XP_2                                    = 20299,
    IDC_VALUE_LEVEL_2                                 = 20298,
    IDC_VALUE_GUILD_2                                 = 20843,
    IDC_VALUE_RANK_2                                  = 20845,
    IDC_LABEL_LP_2                                    = 20296,
    IDC_LABEL_TNL_2                                   = 20295,
    IDC_LABEL_XP_2                                    = 20294,
    IDC_LABEL_LEVEL_2                                 = 20293,
    IDC_LABEL_GUILD_2                                 = 20842,
    IDC_LABEL_RANK_2                                  = 20844,
    IDC_LABEL_PROTECTIONS_2                           = 20291,
    IDC_LABEL_ATTRIBUTES_2                            = 20290,
    IDC_LABEL_PROGRESS_2                              = 20289,
    IDC_LABEL_AUDIO_SUBTITLES_DISPLAY_TIME_2          = 20867,
    IDC_VALUE_AUDIO_SUBTITLES_DISPLAY_TIME_2          = 20868,
    IDC_SLIDER_AUDIO_SUBTITLES_DISPLAY_TIME_2         = 20869,
    IDC_BUTTON_MENU_OPTIONS_DIFFICULTY_CUSTOM_BACK_2  = 20879,
    IDC_LABEL_DIFFICULTY_LEVEL_2                      = 20880,
    IDC_SLIDER_DIFFICULTY_LEVEL_2                     = 20881,
    IDC_VALUE_DIFFICULTY_LEVEL_2                      = 20882,
    IDC_LABEL_DIFFICULTY_CONCURRENT_ATTACKERS_2       = 20883,
    IDC_SLIDER_DIFFICULTY_CONCURRENT_ATTACKERS_2      = 20884,
    IDC_VALUE_DIFFICULTY_CONCURRENT_ATTACKERS_2       = 20885,
    IDC_LABEL_DIFFICULTY_ARENA_ATTACK_SPEED_2         = 20886,
    IDC_SLIDER_DIFFICULTY_ARENA_ATTACK_SPEED_2        = 20887,
    IDC_VALUE_DIFFICULTY_ARENA_ATTACK_SPEED_2         = 20888,
    IDC_LABEL_DIFFICULTY_PLAYER_SPAWN_PROTECTION_2    = 20889,
    IDC_SLIDER_DIFFICULTY_PLAYER_SPAWN_PROTECTION_2   = 20890,
    IDC_VALUE_DIFFICULTY_PLAYER_SPAWN_PROTECTION_2    = 20891,
    IDC_LABEL_DIFFICULTY_PLAYER_RANGED_DAMAGE_2       = 20892,
    IDC_SLIDER_DIFFICULTY_PLAYER_RANGED_DAMAGE_2      = 20893,
    IDC_VALUE_DIFFICULTY_PLAYER_RANGED_DAMAGE_2       = 20894,
};

enum gEWeaponCategory {
    gEWeaponCategory_None   = 0,
    gEWeaponCategory_Melee  = 1,
    gEWeaponCategory_Ranged = 2,
    gEWeaponCategory_Magic  = 3,
};

enum gEWalkMode {
    gEWalkMode_Sneak = 0,
    gEWalkMode_Walk = 1,
    gEWalkMode_Run = 2,
    gEWalkMode_Sprint = 3
};

#endif
