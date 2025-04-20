#pragma once

#include "propertyset/gs_psaizone.h"
#include "propertyset/gs_psanchor.h"
#include "propertyset/gs_psanimation.h"
#include "propertyset/gs_psarena.h"
#include "propertyset/gs_psbook.h"
#include "propertyset/gs_pscamera.h"
#include "propertyset/gs_pscharactercontrol.h"
#include "propertyset/gs_pscharactermovement.h"
#include "propertyset/gs_psclock.h"
#include "propertyset/gs_pscollisionshape.h"
#include "propertyset/gs_psdamage.h"
#include "propertyset/gs_psdamagereceiver.h"
#include "propertyset/gs_psdialog.h"
#include "propertyset/gs_psdoor.h"
#include "propertyset/gs_pseffect.h"
#include "propertyset/gs_psenclave.h"
#include "propertyset/gs_psfocus.h"
#include "propertyset/gs_psinfomanager.h"
#include "propertyset/gs_psinteraction.h"
#include "propertyset/gs_psinventory.h"
#include "propertyset/gs_psitem.h"
#include "propertyset/gs_psletter.h"
#include "propertyset/gs_pslock.h"
#include "propertyset/gs_psmagic.h"
#include "propertyset/gs_psmap.h"
#include "propertyset/gs_psmover.h"
#include "propertyset/gs_psnavigation.h"
#include "propertyset/gs_psnpc.h"
#include "propertyset/gs_psparticle.h"
#include "propertyset/gs_psparty.h"
#include "propertyset/gs_psplayermemory.h"
#include "propertyset/gs_psprojectile.h"
#include "propertyset/gs_psquestmanager.h"
#include "propertyset/gs_psrecipe.h"
#include "propertyset/gs_psrigidbody.h"
#include "propertyset/gs_psroutine.h"
#include "propertyset/gs_psskill.h"
#include "propertyset/gs_psstrip.h"
#include "propertyset/gs_pstouchdamage.h"
#include "propertyset/gs_pstreasureset.h"
#include "propertyset/gs_pstrigger.h"

#include <Script/ScriptEnum.h>
#include <Script/gs_template.h>

#include <Game.h>

class GE_DLLIMPORT Entity
{
  protected:
    eCEntity *m_pEngineEntity;

  public:
    PSRoutine Routine;               // 1
    PSAnimation Animation;           // 2
    PSCollisionShape CollisionShape; // 3
    PSClock Clock;                   // 4
    PSDoor Door;                     // 5
    PSFocus Focus;                   // 6
    PSInteraction Interaction;       // 7
    PSInfoManager InfoManager;       // 8
    PSInventory Inventory;           // 9
    PSItem Item;                     // 10
    PSLock Lock;                     // 11
    PSNavigation Navigation;         // 12
    PSNpc NPC;                       // 13
    PSPlayerMemory PlayerMemory;
    PSRigidBody RigidBody;
    PSCharacterControl CharacterControl;
    PSCharacterMovement CharacterMovement;
    PSDamage Damage;
    PSDamageReceiver DamageReceiver;
    PSTouchDamage TouchDamage;
    PSDialog Dialog;
    PSParty Party;
    PSAnchor Anchor;
    PSLetter Letter;
    PSBook Book;
    PSMap Map;
    PSRecipe Recipe;
    PSProjectile Projectile;
    PSQuestManager QuestManager;
    PSStrip Strip;
    PSParticle Particle;
    PSCamera Camera;
    PSEnclave Enclave;
    PSArena Arena;
    PSAIZone AIZone;
    PSEffect Effect;
    PSMagic Magic;
    PSSkill Skill;
    PSMover Mover;
    PSTrigger Triggerr;
    PSTreasureSet TreasureSet;

  public:
    static Entity ms_Player;
    static bTObjArray<Entity> ms_arrEntities;
    static bTObjArray<Entity> ms_arrNPCs;
    static GEU32 ms_u32LastFrame;

  public:
    static PSCamera GE_STDCALL GetCamera();
    static Entity GE_STDCALL GetCameraEntity();
    static EDifficulty GE_STDCALL GetCurrentDifficulty();
    static bTObjArray<Entity> GE_STDCALL GetEntities();
    static Entity GE_STDCALL GetEntity(bCString);
    static bCString GE_STDCALL GetMaterialName(eEShapeMaterial);
    static bTObjArray<Entity> GE_STDCALL GetNPCs();
    static Entity GE_STDCALL GetNextPatrolPoint(Entity const &);
    static Entity GE_STDCALL GetPlayer();
    // PlayingTime = 0.0001 + Minute * 0.01 + Hour + Day * 24 + Year * 24 * 365
    static GEFloat GE_STDCALL GetPlayingTime();
    static GEInt GE_STDCALL GetRandomNumber(GEInt);
    static bTValArray<eCEntity *> GE_STDCALL GetRoamingPointsByName(bCString);
    static GEU32 GE_STDCALL GetTimeStampInSeconds();
    static Entity GE_STDCALL GetWorldEntity();
    static GEFloat GE_STDCALL GetWorldTime();
    static GEBool GE_STDCALL HasCopyCheckFailed();
    static GEBool GE_STDCALL IsAlternateCameraEnabled();
    static GEBool GE_STDCALL IsCheatGodEnabled();
    static GEBool GE_STDCALL IsCheatInvisibleEnabled();
    static GEBool GE_STDCALL IsTestModeEnabled();
    static void GE_STDCALL SetPlayingTime(GEFloat);
    static void GE_STDCALL SetWorldTime(GEFloat);
    static void GE_STDCALL SortEntityListByDistanceTo(bTObjArray<Entity> &, Entity const &);
    static Entity GE_STDCALL Spawn(Template, bCMatrix const &);
    static GEBool GE_STDCALL TriggerFrustum(bCString &, bCString &, eEPropertySetType);
    static GEBool GE_STDCALL TriggerProcessingRange(bCString &, bCString &, eEPropertySetType);
    static GEBool GE_STDCALL TriggerWorld(bCString &, bCString &, eEPropertySetType);

  public:
    Entity(Entity const &);
    explicit Entity(bCPropertyID const &);
    explicit Entity(eCEntityProxy const &);
    explicit Entity(eCEntity const *);
    Entity();
    ~Entity();

  public:
    explicit operator eCEntity *() const;
    Entity &operator=(Entity const &);
    GEBool operator==(Entity const &) const;
    GEBool operator!=(Entity const &) const;

  public:
    GEBool AttachTo(eCEntity *);
    GEBool CanEvade(Entity const &, gEDirection) const;
    GEBool CanGoto(Entity const &) const;
    GEBool CanGoto(bCVector const &) const;
    GEBool CanJumpToZone(Entity const &) const;
    void Decay();
    void DoDamage(Entity const &, GEU32, gEDamageType);
    void EnableAutoAiming(GEBool, Entity const &, bCString const &);
    void EnableCollision(eEShapeGroup, GEBool, GEInt);
    void EnableCollision(GEBool);
    void EnableCollisionWith(Entity const &, GEBool);
    void EnablePicking(GEBool);
    void EnableProcessing(GEBool);
    void EnableRendering(GEBool);
    void EndTakeOver();
    void EndTransform();
    GEBool FindSpawnPose(bCMatrix &, Entity const &, GEBool, GEU16) const;
    Entity GetAIZoneOwner() const;
    gESecurityLevel GetAIZoneSecurityLevel() const;
    gEZoneType GetAIZoneType() const;
    Entity GetAlignmentTarget() const;
    bCString GetAni(gEAction, gEPhase) const;
    bCString GetAni(gEAction, gEUseType, gEUseType, gEPhase) const;
    bCString GetAniEx(gEAction, gEPhase, bCString const &, GEBool) const;
    bCString GetAniEx(gEUseType, gEUseType, gEAction, gEPhase, bCString const &, GEBool) const;
    bCVector GetAtVector() const;
    void GetAziElev(Entity const &, GEFloat &, GEFloat &) const;
    void GetAziElev(bCVector const &, GEFloat &, GEFloat &) const;
    GEFloat GetBoundingRadius() const;
    eECollisionGroup GetCollisionGroup() const;
    gEDirection GetCurrentAniDirection() const;
    gEPhase GetCurrentAniPhase() const;
    bCVector GetDirectionTo(Entity const &) const;
    bCString GetDisplayName() const;
    GEFloat GetDistanceTo(Entity const &) const;
    Entity GetEnclave() const;
    bTObjArray<Entity> GetEntitiesByDistance() const;
    bCVector GetEvadeDestination(Entity const &, gEDirection) const;
    bCUnicodeString GetFocusName() const;
    gCEntity *GetGameEntity() const;
    Entity GetIndoorOwnerZone(GEFloat) const;
    eCEntity *GetInstance() const;
    bCVector GetLinearVelocity() const;
    bCVector const &GetMotionDelta();
    gECharMovementMode GetMovementMode() const;
    bCString GetName() const;
    Entity GetNearestEntity(gEUseType) const;
    Entity GetNearestFleePoint(Entity &, GEFloat);
    bCVector GetNearestNavigationPoint(bCVector, GEFloat);
    GEU32 GetNetIndex() const;
    bCString GetOverlayAni(gEAction, gEPhase) const;
    bCString GetOverlayAni(gEAction, gEUseType, gEUseType, gEPhase) const;
    Entity GetOwner() const;
    bCMatrix GetPose() const;
    bCVector GetPosition() const;
    bCVector GetRandomNavigationPoint(bCVector, GEFloat);
    bCString GetSkeletonName() const;
    GEFloat GetSquareDistanceTo(Entity const &) const;
    Template GetTemplate() const;
    bCVector GetUnitDirectionTo(Entity const &) const;
    Entity GetUser() const;
    bCVector GetVelocity() const;
    Entity GetWeapon(GEBool) const;
    Entity GetZone() const;
    GEBool HasCommentInfo(Entity const &) const;
    GEBool HasImportantInfo(Entity const &) const;
    GEBool HasInfo(Entity const &) const;
    GEBool HasSVMBlock(bCString const &);
    GEBool IsAutoAimingEnabled();
    GEBool IsBraking() const;
    GEBool IsCharacter() const;
    GEBool IsDead() const;
    GEBool IsDiving() const;
    GEBool IsDown() const;
    GEBool IsFalling() const;
    GEBool IsFreeLOS(Entity const &, GEBool) const;
    GEBool IsFreeLOSKneeHeight(Entity const &) const;
    GEBool IsInFOV(Entity const &) const;
    GEBool IsInMovingState() const;
    GEBool IsInteractObject() const;
    GEBool IsItem() const;
    GEBool IsJumping() const;
    GEBool IsNPC() const;
    GEBool IsPlayer() const;
    GEBool IsReady() const;
    GEBool IsRunning() const;
    GEBool IsSneaking() const;
    GEBool IsSprinting() const;
    GEBool IsStanding() const;
    GEBool IsSwimming() const;
    void Kill();
    void MoveTo(Entity const &);
    void MoveTo(bCMatrix const &);
    void ReAttach();
    void ResetInteractAnimation();
    void RevertPlayingAni(GEFloat);
    void SetAIZoneOwner(Entity &);
    void SetAIZoneSecurityLevel(gESecurityLevel);
    void SetAIZoneType(gEZoneType);
    void SetAlignmentTarget(Entity const &);
    void SetAlpha(GEFloat);
    void SetCollisionGroup(eECollisionGroup);
    void SetCurrentAniDirection(gEDirection);
    void SetEnclave(Entity const &);
    void SetLinearVelocity(bCVector const &);
    void SetLookAtTarget(Entity const &);
    void SetMovementMode(gECharMovementMode);
    void SetTimeScale(GEFloat);
    GEBool StartComment(Entity const &) const;
    void StartFacialAni(bCString);
    GEBool StartGoto(Entity &, gEWalkMode);
    GEBool StartGoto(bCVector const &, gEWalkMode);
    void StartOutput(bCString);
    void StartPlayAni(bCString, GEInt, GEBool, GEFloat, GEBool a_bUseAniVariation);
    void StartPlayAniEx(bCString const &, GEInt, GEBool, GEBool, GEFloat, GEBool);
    void StartPlayOverlayAni(bCString, GEInt, GEBool, GEFloat);
    void StartSay(Entity &, bCString, GEBool);
    void StartSayEx(Entity &, bCString, bCString, GEBool);
    void StartSaySVM(Entity &, bCString, GEBool);
    void StartTakeOver();
    void StartTransform(Entity &, GEFloat, GEBool);
    GEBool StartTurnTo(Entity const &);
    void StopFacialAni();
    void StopGoto();
    void StopPlayAni();
    void StopPlayOverlayAni();
    GEBool Teleport(Entity const &);
    GEBool Teleport(bCString const &);
    void Trigger(bCString &);

  protected:
    static GEInt GE_CCALL SortEntites(GELPCVoid, GELPCVoid);
    static void GE_STDCALL UpdateEntityLists();

  protected:
    GEBool CopyFrom(Entity const &);
    void Invalidate();
    void StartAimAt(Entity const &);
    void StartAimAt(bCVector const &);
    void StopAim();
    void UpdateAim(Entity const &, bCString const &);
    void UpdateAim(bCVector const &, bCString const &);

  private:
    GEBool FixAniDirection(gEAction, gEPhase, gEDirection &) const;
};

GE_DLLIMPORT_EXTC Entity None;
