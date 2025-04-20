#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSNpc : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSNpc, gCNPC_PS)
    GS_PROPERTY(gEAttackReason, AttackReason)
    GS_PROPERTY(gEAttitude, AttitudeToPlayer2)
    GS_PROPERTY(gEBearing, Bearing)
    GS_PROPERTY(gEClass, Class)
    GS_PROPERTY(GEU32, CombatState)
    GS_PROPERTY(GEBool, DefeatedByPlayer)
    GS_PROPERTY(GEBool, Discovered)
    GS_PROPERTY(GEFloat, DistToNearestMist)
    GS_PROPERTY(gEGender, Gender)
    GS_PROPERTY(gEGuardStatus, GuardStatus)
    GS_PROPERTY(GEBool, Immortal)
    GS_PROPERTY(GEU32, LastCastTimestamp)
    GS_PROPERTY(GEFloat, LastDistToGuardPoint)
    GS_PROPERTY(GEFloat, LastDistToTarget)
    GS_PROPERTY(gELastFightAgainstPlayer, LastFightAgainstPlayer)
    GS_PROPERTY(GEBool, LastFightComment)
    GS_PROPERTY(GEFloat, LastFightTimestamp)
    GS_PROPERTY(GEU32, LastHitTimestamp)
    GS_PROPERTY(gEAttackReason, LastPlayerAR)
    GS_PROPERTY(gEPlayerCrime, LastPlayerCrime)
    GS_PROPERTY(bCString, LastSpell)
    GS_PROPERTY(GEU32, Level)
    GS_PROPERTY(GEU32, LevelMax)
    GS_PROPERTY(GEInt, ManaUsed)
    GS_PROPERTY(gEPoliticalAlignment, PoliticalAlignment)
    GS_PROPERTY(GEBool, Ransacked)
    GS_PROPERTY(gESpecies, Species)
    GS_PROPERTY(GEU32, StatusEffects)
    GS_PROPERTY(GEU32, TimeStampBurning)
    GS_PROPERTY(GEU32, TimeStampDiseased)
    GS_PROPERTY(GEU32, TimeStampFrozen)
    GS_PROPERTY(GEU32, TimeStampPoisoned)
    GS_PROPERTY(GEU32, TimeStampTransformed)
    GS_PROPERTY(gENPCType, Type)
    GS_PROPERTY(bCString, Voice)

  public:
    GEBool CanCast(GEU32);
    GEBool CanHit(GEU32);
    void EnableBurning(GEBool);
    void EnableDiseased(GEBool);
    void EnableFrozen(GEBool);
    void EnableInMagicBarrier(GEBool);
    void EnablePoisoned(GEBool);
    void EnableStatusEffects(GEInt, GEBool);
    GEBool ForceNextPose(gEPose);
    Entity GetAlternativeTarget() const;
    Entity GetCurrentAttacker() const;
    bCString GetCurrentMovementAni() const;
    Entity GetCurrentTarget() const;
    Entity GetEnclave() const;
    Entity GetGuardPoint() const;
    Entity GetLastAttacker() const;
    GEU32 GetLastCastTimestamp();
    GEU32 GetLastHitTimestamp();
    gEPose GetPrimaryPose() const;
    gEPose GetPrimaryPoseExt(gEAction, gEPhase) const;
    GEBool GetPrimaryPoseExt(gEAction, gEPhase, gEPose &) const;
    Entity GetSpellTarget() const;
    GEBool HasStatusEffects(GEInt) const;
    GEBool IsBurning() const;
    GEBool IsDiseased() const;
    GEBool IsFrozen() const;
    GEBool IsInMagicBarrier() const;
    GEBool IsPoisoned() const;
    GEBool IsTransformed() const;
    void SetAlternativeTarget(Entity const &);
    void SetCurrentAttacker(Entity const &);
    void SetCurrentTarget(Entity const &);
    GEBool SetEnclave(Entity const &) const;
    GEBool SetGuardPoint(Entity const &) const;
    void SetLastAttacker(Entity const &);
    void SetLastCast();
    void SetLastCastTimestamp(GEU32);
    void SetLastHit();
    void SetLastHitTimestamp(GEU32);
    void SetSpellTarget(Entity const &);
};
