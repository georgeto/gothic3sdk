#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCNPC_PS : public eCEntityPropertySet
{
    // clang-format off
    public: virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCNPC_PS() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    public: GEBool IsProcessable() const override;
    public: GEBool SupportsRenderDebugOutput() const override;
    public: bEResult ReadSaveGame(bCIStream &) override;
    public: bEResult WriteSaveGame(bCOStream &) override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void OnSaveGameEntityPostRead() override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    protected: void OnTouch(eCEntity *, eCContactIterator &) override;
    public: void OnEnterProcessingRange() override;
    public: void OnExitProcessingRange() override;
    public: void GetOnScreenDebugLines(GEU32, bTObjArray<eSPropertySetDebugLine> &) const override;
    public: void OnProcess() override;
    public: void OnPreProcess() override;
    public: void OnPostRead() override;
    public: void OnPostCopy(eCEntityPropertySet const &) override;
    public: void OnPropertySetRemoved() override;
    public: void OnCustomPatch(eCEntityPropertySet const *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCNPC_PS, eCEntityPropertySet)
    GE_PROPERTY(bCString, Description, m_strDescription)
    GE_PROPERTY(bCString, Voice, m_strVoice)
    GE_PROPERTY(bCString, RoleDescription, m_strRoleDescription)
    GE_PROPERTY(GEU32, Level, m_u32Level)
    GE_PROPERTY(GEU32, LevelMax, m_u32LevelMax)
    GE_ENUMPROP(gEGender, Gender, m_enuGender)
    GE_ENUMPROP(gESpecies, Species, m_enuSpecies)
    GE_ENUMPROP(gEPoliticalAlignment, PoliticalAlignment, m_enuPoliticalAlignment)
    GE_ENUMPROP(gEClass, Class, m_enuClass)
    GE_ENUMPROP(gENPCType, Type, m_enuType)
    GE_PROPERTY(bCPropertyID, Enclave, m_Enclave)
    GE_ENUMPROP(gEAttitude, AttitudeToPlayer2, m_enuAttitudeToPlayer2)
    GE_ENUMPROP(gEPlayerCrime, LastPlayerCrime, m_enuLastPlayerCrime)
    GE_ENUMPROP(gEAttackReason, AttackReason, m_enuAttackReason)
    GE_ENUMPROP(gEAttackReason, LastPlayerAR, m_enuLastPlayerAR)
    GE_ENUMPROP(gELastFightAgainstPlayer, LastFightAgainstPlayer, m_enuLastFightAgainstPlayer)
    GE_PROPERTY(GEFloat, LastFightTimestamp, m_fLastFightTimestamp)
    GE_PROPERTY(GEU32, LastHitTimestamp, m_u32LastHitTimestamp)
    GE_PROPERTY(GEU32, LastCastTimestamp, m_u32LastCastTimestamp)
    GE_PROPERTY(GEBool, Immortal, m_bImmortal)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, LastDistToTarget, m_fLastDistToTarget)
    GE_PROPERTY(GEFloat, DistToNearestMist, m_fDistToNearestMist)
    GE_PROPERTY(GEBool, DefeatedByPlayer, m_bDefeatedByPlayer)
    GE_PROPERTY(GEBool, Ransacked, m_bRansacked)
    GE_PROPERTY(GEBool, Discovered, m_bDiscovered)
    GE_PROPERTY(GEBool, LastFightComment, m_bLastFightComment)
    GE_PROPERTY(eCEntityProxy, CurrentTargetEntity, m_CurrentTarget)
    GE_PROPERTY(eCEntityProxy, CurrentAttackerEntity, m_CurrentAttacker)
    GE_PROPERTY(eCEntityProxy, AlternativeTargetEntity, m_AlternativeTarget)
    GE_PROPERTY(eCEntityProxy, LastAttackerEntity, m_LastAttacker)
    GE_PROPERTY(GEU32, CombatState, m_iCombatState)
    GE_PROPERTY(eCEntityProxy, GuardPoint, m_guardPoint)
    GE_ENUMPROP(gEGuardStatus, GuardStatus, m_enuGuardStatus)
    GE_PROPERTY(GEFloat, LastDistToGuardPoint, m_lastDistToGuardPoint)
    GE_ENUMPROP(gEBearing, Bearing, m_enuBearing)
    GE_PROPERTY(bTObjArray<bCString>, TeachAttribs, m_arrTeachAttribs)
    GE_PROPERTY(bTObjArray<eCTemplateEntityProxy>, TeachSkills, m_arrTeachSkills)
    GE_PROPERTY(GEInt, ManaUsed, m_iManaUsed)                           // Read only
    GE_PROPERTY(eCEntityProxy, SpellTarget, m_entSpellTarget)           // Read only
    GE_PROPERTY(bCString, LastSpell, m_strLastSpell)                    // Read only
    GE_PROPERTY(GEU32, StatusEffects, m_u32StatusEffects)               // Read only
    GE_PROPERTY(GEU32, TimeStampFrozen, m_u32TimeStampFrozen)           // Read only
    GE_PROPERTY(GEU32, TimeStampBurning, m_u32TimeStampBurning)         // Read only
    GE_PROPERTY(GEU32, TimeStampPoisoned, m_u32TimeStampPoisoned)       // Read only
    GE_PROPERTY(GEU32, TimeStampDiseased, m_u32TimeStampDiseased)       // Read only
    GE_PROPERTY(GEU32, TimeStampTransformed, m_u32TimeStampTransformed) // Read only

  public:
    void EnableStatusEffect(gEStatusEffect, GEBool);
    GEBool ForceNextPose(gEPose);
    eCEntityProxy &GetAreaProxy();
    bCString const &GetCurrentMovementAni() const;
    eCEntityProxy &GetEnclaveProxy();
    GEFloat GetPoseWeighting() const;
    gEPose GetPrimaryPose() const;
    gEPose GetPrimaryPoseExt(gEAction, bCString);
    gEPose GetPrimaryPoseExt(gEAction, gEPhase);
    gEPose GetSecondaryPose() const;
    eCEntityProxy &GetSpawnPointProxy();
    GEBool HasStatusEffect(gEStatusEffect) const;
    void SetCurrentMovementAni(bCString const &);
    void SetPoseWeighting(GEFloat);
    void SetPrimaryPose(gEPose);
    void SetSecondaryPose(gEPose);

  protected:
    void GameReset();
    void Invalidate();
    void TrackCurrentPose();

  private:
    GE_UNIMPL_MEMBERS(104)
};

GE_ASSERT_SIZEOF(gCNPC_PS, 0x208)

GE_ASSERT_PROPERTY(gCNPC_PS, m_strDescription, 0x14, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_strVoice, 0x18, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_strRoleDescription, 0x1c, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_u32Level, 0x20, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_u32LevelMax, 0x24, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_enuGender, 0x28, 8)
GE_ASSERT_PROPERTY(gCNPC_PS, m_enuSpecies, 0x30, 8)
GE_ASSERT_PROPERTY(gCNPC_PS, m_enuPoliticalAlignment, 0x38, 8)
GE_ASSERT_PROPERTY(gCNPC_PS, m_enuClass, 0x40, 8)
GE_ASSERT_PROPERTY(gCNPC_PS, m_enuType, 0x48, 8)
GE_ASSERT_PROPERTY(gCNPC_PS, m_Enclave, 0x50, 20)
GE_ASSERT_PROPERTY(gCNPC_PS, m_enuAttitudeToPlayer2, 0x64, 8)
GE_ASSERT_PROPERTY(gCNPC_PS, m_enuLastPlayerCrime, 0x6c, 8)
GE_ASSERT_PROPERTY(gCNPC_PS, m_enuAttackReason, 0x74, 8)
GE_ASSERT_PROPERTY(gCNPC_PS, m_enuLastPlayerAR, 0x7c, 8)
GE_ASSERT_PROPERTY(gCNPC_PS, m_enuLastFightAgainstPlayer, 0x84, 8)
GE_ASSERT_PROPERTY(gCNPC_PS, m_fLastFightTimestamp, 0x8c, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_u32LastHitTimestamp, 0x90, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_u32LastCastTimestamp, 0x94, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_bImmortal, 0x98, 1)
GE_ASSERT_PROPERTY(gCNPC_PS, m_fLastDistToTarget, 0x9c, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_fDistToNearestMist, 0xa0, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_bDefeatedByPlayer, 0xa4, 1)
GE_ASSERT_PROPERTY(gCNPC_PS, m_bRansacked, 0xa5, 1)
GE_ASSERT_PROPERTY(gCNPC_PS, m_bDiscovered, 0xa6, 1)
GE_ASSERT_PROPERTY(gCNPC_PS, m_bLastFightComment, 0xa7, 1)
GE_ASSERT_PROPERTY(gCNPC_PS, m_CurrentTarget, 0xa8, 28)
GE_ASSERT_PROPERTY(gCNPC_PS, m_CurrentAttacker, 0xc4, 28)
GE_ASSERT_PROPERTY(gCNPC_PS, m_AlternativeTarget, 0xe0, 28)
GE_ASSERT_PROPERTY(gCNPC_PS, m_LastAttacker, 0xfc, 28)
GE_ASSERT_PROPERTY(gCNPC_PS, m_iCombatState, 0x118, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_guardPoint, 0x11c, 28)
GE_ASSERT_PROPERTY(gCNPC_PS, m_enuGuardStatus, 0x138, 8)
GE_ASSERT_PROPERTY(gCNPC_PS, m_lastDistToGuardPoint, 0x140, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_enuBearing, 0x144, 8)
GE_ASSERT_PROPERTY(gCNPC_PS, m_arrTeachAttribs, 0x14c, 12)
GE_ASSERT_PROPERTY(gCNPC_PS, m_arrTeachSkills, 0x158, 12)
GE_ASSERT_PROPERTY(gCNPC_PS, m_iManaUsed, 0x164, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_entSpellTarget, 0x168, 28)
GE_ASSERT_PROPERTY(gCNPC_PS, m_strLastSpell, 0x184, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_u32StatusEffects, 0x188, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_u32TimeStampFrozen, 0x18c, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_u32TimeStampBurning, 0x190, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_u32TimeStampPoisoned, 0x194, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_u32TimeStampDiseased, 0x198, 4)
GE_ASSERT_PROPERTY(gCNPC_PS, m_u32TimeStampTransformed, 0x19c, 4)
