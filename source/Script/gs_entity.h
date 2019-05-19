#ifndef GS_ENTITY_H_INCLUDED
#define GS_ENTITY_H_INCLUDED

#include "gs_psroutine.h"
#include "gs_psanimation.h"
#include "gs_pscollisionshape.h"
#include "gs_psclock.h"
#include "gs_psdoor.h"
#include "gs_psfocus.h"
#include "gs_psinteraction.h"
#include "gs_psinfomanager.h"
#include "gs_psinventory.h"
#include "gs_psitem.h"
#include "gs_pslock.h"
#include "gs_psnavigation.h"
#include "gs_psnpc.h"
#include "gs_psplayermemory.h"
#include "gs_psrigidbody.h"
#include "gs_pscharactercontrol.h"
#include "gs_pscharactermovement.h"
#include "gs_psdamagereceiver.h"
#include "gs_psdamage.h"
#include "gs_pstouchdamage.h"
#include "gs_psdialog.h"
#include "gs_psparty.h"
#include "gs_psanchor.h"
#include "gs_psletter.h"
#include "gs_psbook.h"
#include "gs_psmap.h"
#include "gs_psrecipe.h"
#include "gs_psprojectile.h"
#include "gs_psquestmanager.h"
#include "gs_psstrip.h"
#include "gs_psparticle.h"
#include "gs_pseffect.h"
#include "gs_psmagic.h"
#include "gs_psskill.h"
#include "gs_pscamera.h"
#include "gs_psenclave.h"
#include "gs_psarena.h"
#include "gs_psaizone.h"
#include "gs_psmover.h"
#include "gs_pstrigger.h"
#include "gs_pstreasureset.h"

class gCEntity;

#pragma warning( push )
#pragma warning( disable : 4251 )// class 'bTObjArray<>' needs to have dll-interface to be used by clients of class 'Entity'

class GE_DLLIMPORT Entity
{
    public:
        static Entity             ms_Player;
        static bTObjArray<Entity> ms_arrEntities;
        static bTObjArray<Entity> ms_arrNPCs;
        static GEU32              ms_u32LastFrame;

    protected:
        eCEntity * m_pEngineEntity;

    public:
        PSRoutine           Routine; //1
        PSAnimation         Animation; //2
        PSCollisionShape    CollisionShape; //3
        PSClock             Clock; //4
        PSDoor              Door; //5
        PSFocus             Focus; //6
        PSInteraction       Interaction; //7
        PSInfoManager       InfoManager; //8
        PSInventory         Inventory; //9
        PSItem              Item; //10
        PSLock              Lock; //11
        PSNavigation        Navigation; //12
        PSNpc               NPC; //13
        PSPlayerMemory      PlayerMemory;
        PSRigidBody         RigidBody;
        PSCharacterControl  CharacterControl;
        PSCharacterMovement CharacterMovement;
        PSDamage            Damage;
        PSDamageReceiver    DamageReceiver;
        PSTouchDamage       TouchDamage;
        PSDialog            Dialog;
        PSParty             Party;
        PSAnchor            Anchor;
        PSLetter            Letter;
        PSBook              Book;
        PSMap               Map;
        PSRecipe            Recipe;
        PSProjectile        Projectile;
        PSQuestManager      QuestManager;
        PSStrip             Strip;
        PSParticle          Particle;
        PSCamera            Camera;
        PSEnclave           Enclave;
        PSArena             Arena;
        PSAIZone            AIZone;
        PSEffect            Effect;
        PSMagic             Magic;
        PSSkill             Skill;
        PSMover             Mover;
        PSTrigger           Triggerr;
        PSTreasureSet       TreasureSet;

    public:
        static PSCamera GE_STDCALL               GetCamera( void );
        static Entity GE_STDCALL                 GetCameraEntity( void );
        static EDifficulty GE_STDCALL            GetCurrentDifficulty( void );
        static bTObjArray<Entity> GE_STDCALL     GetEntities( void );
        static Entity GE_STDCALL                 GetEntity( bCString );
        static bCString GE_STDCALL               GetMaterialName( eEShapeMaterial );
        static bTObjArray<Entity> GE_STDCALL     GetNPCs( void );
        static Entity GE_STDCALL                 GetNextPatrolPoint( Entity const & );
        static Entity GE_STDCALL                 GetPlayer( void );
        static GEFloat GE_STDCALL                GetPlayingTime( void ); // PlayingTime = 0.0001 + Minute * 0.01 + Hour + Day * 24 + Year * 24 * 365
        static GEInt GE_STDCALL                  GetRandomNumber( GEInt );
        static bTValArray<eCEntity *> GE_STDCALL GetRoamingPointsByName( bCString );
        static GEU32 GE_STDCALL                  GetTimeStampInSeconds( void );
        static Entity GE_STDCALL                 GetWorldEntity( void );
        static GEFloat GE_STDCALL                GetWorldTime( void );
        static GEBool GE_STDCALL                 HasCopyCheckFailed( void );
        static GEBool GE_STDCALL                 IsAlternateCameraEnabled( void );
        static GEBool GE_STDCALL                 IsCheatGodEnabled( void );
        static GEBool GE_STDCALL                 IsCheatInvisibleEnabled( void );
        static GEBool GE_STDCALL                 IsTestModeEnabled( void );
        static void GE_STDCALL                   SetPlayingTime( GEFloat );
        static void GE_STDCALL                   SetWorldTime( GEFloat );
        static void GE_STDCALL                   SortEntityListByDistanceTo( bTObjArray<Entity> &, Entity const & );
        static Entity GE_STDCALL                 Spawn( Template, bCMatrix const & );
        static GEBool GE_STDCALL                 TriggerFrustum( bCString &, bCString &, eEPropertySetType );
        static GEBool GE_STDCALL                 TriggerProcessingRange( bCString &, bCString &, eEPropertySetType );
        static GEBool GE_STDCALL                 TriggerWorld( bCString &, bCString &, eEPropertySetType );

    public:
         Entity( Entity const & );
         Entity( bCPropertyID const & );
         Entity( eCEntityProxy const & );
         Entity( eCEntity const * );
         Entity( void );
        ~Entity( void );

    public:
        Entity & operator =          ( Entity const & );
        GEBool   operator ==         ( Entity const & ) const;
        GEBool   operator !=         ( Entity const & ) const;
        //       operator eCEntity * ( void ) const;

    public:
        GEBool             AttachTo( eCEntity * );
        GEBool             CanEvade( Entity const &, gEDirection ) const;
        GEBool             CanGoto( Entity const & ) const;
        GEBool             CanGoto( bCVector const & ) const;
        GEBool             CanJumpToZone( Entity const & ) const;
        void               Decay( void );
        void               DoDamage( Entity const &, GEU32, gEDamageType );
        void               EnableAutoAiming( GEBool, Entity const &, bCString const & );
        void               EnableCollision( eEShapeGroup, GEBool, GEInt );
        void               EnableCollision( GEBool );
        void               EnableCollisionWith( Entity const &, GEBool );
        void               EnablePicking( GEBool );
        void               EnableProcessing( GEBool );
        void               EnableRendering( GEBool );
        void               EndTakeOver( void );
        void               EndTransform( void );
        GEBool             FindSpawnPose( bCMatrix &, Entity const &, GEBool, GEU16 ) const;
        Entity             GetAIZoneOwner( void ) const;
        gESecurityLevel    GetAIZoneSecurityLevel( void ) const;
        gEZoneType         GetAIZoneType( void ) const;
        Entity             GetAlignmentTarget( void ) const;
        bCString           GetAni( gEAction, gEPhase ) const;
        bCString           GetAni( gEAction, gEUseType, gEUseType, gEPhase ) const;
        bCString           GetAniEx( gEAction, gEPhase, bCString const &, GEBool ) const;
        bCString           GetAniEx( gEUseType, gEUseType, gEAction, gEPhase, bCString const &, GEBool ) const;
        bCVector           GetAtVector( void ) const;
        void               GetAziElev( Entity const &, GEFloat &, GEFloat & ) const;
        void               GetAziElev( bCVector const &, GEFloat &, GEFloat & ) const;
        GEFloat            GetBoundingRadius( void ) const;
        eECollisionGroup   GetCollisionGroup( void ) const;
        gEDirection        GetCurrentAniDirection( void ) const;
        gEPhase            GetCurrentAniPhase( void ) const;
        bCVector           GetDirectionTo( Entity const & ) const;
        bCString           GetDisplayName( void ) const;
        GEFloat            GetDistanceTo( Entity const & ) const;
        Entity             GetEnclave( void ) const;
        bTObjArray<Entity> GetEntitiesByDistance( void ) const;
        bCVector           GetEvadeDestination( Entity const &, gEDirection ) const;
        bCUnicodeString    GetFocusName( void ) const;
        gCEntity *         GetGameEntity( void ) const;
        Entity             GetIndoorOwnerZone( GEFloat ) const;
        eCEntity *         GetInstance( void ) const;
        bCVector           GetLinearVelocity( void ) const;
        bCVector const &   GetMotionDelta( void );
        gECharMovementMode GetMovementMode( void ) const;
        bCString           GetName( void ) const;
        Entity             GetNearestEntity( gEUseType ) const;
        Entity             GetNearestFleePoint( Entity &, GEFloat );
        bCVector           GetNearestNavigationPoint( bCVector, GEFloat );
        GEU32              GetNetIndex( void ) const;
        bCString           GetOverlayAni( gEAction, gEPhase ) const;
        bCString           GetOverlayAni( gEAction, gEUseType, gEUseType, gEPhase ) const;
        Entity             GetOwner( void ) const;
        bCMatrix           GetPose( void ) const;
        bCVector           GetPosition( void ) const;
        bCVector           GetRandomNavigationPoint( bCVector, GEFloat );
        bCString           GetSkeletonName( void ) const;
        GEFloat            GetSquareDistanceTo( Entity const & ) const;
        Template           GetTemplate( void ) const;
        bCVector           GetUnitDirectionTo( Entity const & ) const;
        Entity             GetUser( void ) const;
        bCVector           GetVelocity( void ) const;
        Entity             GetWeapon( GEBool ) const;
        Entity             GetZone( void ) const;
        GEBool             HasCommentInfo( Entity const & ) const;
        GEBool             HasImportantInfo( Entity const & ) const;
        GEBool             HasInfo( Entity const & ) const;
        GEBool             HasSVMBlock( bCString const & );
        GEBool             IsAutoAimingEnabled( void );
        GEBool             IsBraking( void ) const;
        GEBool             IsCharacter( void ) const;
        GEBool             IsDead( void ) const;
        GEBool             IsDiving( void ) const;
        GEBool             IsDown( void ) const;
        GEBool             IsFalling( void ) const;
        GEBool             IsFreeLOS( Entity const &, GEBool ) const;
        GEBool             IsFreeLOSKneeHeight( Entity const & ) const;
        GEBool             IsInFOV( Entity const & ) const;
        GEBool             IsInMovingState( void ) const;
        GEBool             IsInteractObject( void ) const;
        GEBool             IsItem( void ) const;
        GEBool             IsJumping( void ) const;
        GEBool             IsNPC( void ) const;
        GEBool             IsPlayer( void ) const;
        GEBool             IsReady( void ) const;
        GEBool             IsRunning( void ) const;
        GEBool             IsSneaking( void ) const;
        GEBool             IsSprinting( void ) const;
        GEBool             IsStanding( void ) const;
        GEBool             IsSwimming( void ) const;
        void               Kill( void );
        void               MoveTo( Entity const & );
        void               MoveTo( bCMatrix const & );
        void               ReAttach( void );
        void               ResetInteractAnimation( void );
        void               RevertPlayingAni( GEFloat );
        void               SetAIZoneOwner( Entity & );
        void               SetAIZoneSecurityLevel( gESecurityLevel );
        void               SetAIZoneType( gEZoneType );
        void               SetAlignmentTarget( Entity const & );
        void               SetAlpha( GEFloat );
        void               SetCollisionGroup( eECollisionGroup );
        void               SetCurrentAniDirection( gEDirection );
        void               SetEnclave( Entity const & );
        void               SetLinearVelocity( bCVector const & );
        void               SetLookAtTarget( Entity const & );
        void               SetMovementMode( gECharMovementMode );
        void               SetTimeScale( GEFloat );
        GEBool             StartComment( Entity const & ) const;
        void               StartFacialAni( bCString );
        GEBool             StartGoto( Entity &, gEWalkMode );
        GEBool             StartGoto( bCVector const &, gEWalkMode );
        void               StartOutput( bCString );
        void               StartPlayAni( bCString, GEInt, GEBool, GEFloat, GEBool a_bUseAniVariation );
        void               StartPlayAniEx( bCString const &, GEInt, GEBool, GEBool, GEFloat, GEBool );
        void               StartPlayOverlayAni( bCString, GEInt, GEBool, GEFloat );
        void               StartSay( Entity &, bCString, GEBool );
        void               StartSayEx( Entity &, bCString, bCString, GEBool );
        void               StartSaySVM( Entity &, bCString, GEBool );
        void               StartTakeOver( void );
        void               StartTransform( Entity &, GEFloat, GEBool );
        GEBool             StartTurnTo( Entity const & );
        void               StopFacialAni( void );
        void               StopGoto( void );
        void               StopPlayAni( void );
        void               StopPlayOverlayAni( void );
        GEBool             Teleport( Entity const & );
        GEBool             Teleport( bCString const & );
        void               Trigger( bCString & );

    protected:
        static GEInt GE_CCALL  SortEntites( GELPCVoid, GELPCVoid );
        static void GE_STDCALL UpdateEntityLists( void );

    protected:
        GEBool CopyFrom( Entity const & );
        void   Invalidate( void );
        void   StartAimAt( Entity const & );
        void   StartAimAt( bCVector const & );
        void   StopAim( void );
        void   UpdateAim( Entity const &, bCString const & );
        void   UpdateAim( bCVector const &, bCString const & );

    private:
        GEBool FixAniDirection( gEAction, gEPhase, gEDirection & ) const;
};



#pragma warning( pop )

GE_DLLIMPORT_EXTC Entity None;

#endif
