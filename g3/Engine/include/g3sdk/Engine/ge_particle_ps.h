#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/entity/ge_entitypropertyset.h>
#include <Engine/entity/proxy/ge_entityproxy.h>
#include <Engine/ge_particlesound.h>
#include <Engine/ge_stringwrapper.h>

#include <SharedBase.h>

class eCAudioChannel;
class eCIlluminated_PS;

class eCParticle2
{
  public:
    bCVector StartLocationOffse2;
    bCVector StartLocationOffset1;
    bCVector Velocity;
    bCVector VelocityFactor;
    bCVector RevolutionCenterOffset;
    bCVector RevolutionsPerSecond;
    bCVector StartSpin;
    bCVector SpinsPerSecond;
    bCVector StartSize;
    bCVector SizeFactor;
    bCFloatAlphaColor Color;
    bCFloatAlphaColor ColorFactor;
    GEFloat SpawnAge;
    GEFloat DieAge;
    GEFloat Frame;
    GEInt CollisionThreshold;
    GEU32 Flags_1_VelocityAboveMinVelocity_1_CollisionThresholdAboveRandom_ISDEAD;
};

GE_ASSERT_SIZEOF(eCParticle2, 0xb4)

struct eSFloatScaleItem
{
    float scale;
    float value;
};
struct eSVectorScaleItem
{
    float scale;
    bCVector value;
};
struct eSColorScaleItem
{
    float scale;
    bCFloatAlphaColor value;
};

class GE_DLLIMPORT eCParticle_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCParticle_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsVisual() const override;
    public: GEBool IsProcessable() const override;
    public: GEBool IsEditorRelevant() const override;
    public: eCRenderContext * QueryRenderContext() override;
    public: GEBool SupportsRenderDebugOutput() const override;
    public: GEBool IsRefracted() const override;
    public: GEBool HasRenderAlphaComponent() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: void OnEnterProcessingRange() override;
    public: void OnExitProcessingRange() override;
    protected: void Trigger(bCString const &) override;
    public: GEBool IsAutoKillEnabled() const override;
    public: void Decay() override;
    public: void GetOnScreenDebugLines(GEU32, bTObjArray<eSPropertySetDebugLine> &) const override;
    public: void OnRender(GEI16) override;
    public: void OnRenderAlpha(GEI16) override;
    public: void OnUpdatedWorldMatrix() override;
    public: void OnCacheIn() override;
    public: void OnCacheOut() override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnProcess() override;
    public: void OnPostRead() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCParticle_PS, eCEntityPropertySet)
    GE_PROPERTY(GEInt, MaxNumParticles, m_iMaxNumParticles)
    GE_PROPERTY(GEFloat, ParticlesPerSecond, m_fParticlesPerSecond)
    GE_PROPERTY(GEBool, RespawnDeadParticles, m_bRespawnDeadParticles)
    GE_PROPERTY(GEBool, AutomaticSpawning, m_bAutomaticSpawning)
    GE_PROPERTY(GEBool, AutoReset, m_bAutoReset)
    GE_PROPERTY(GEBool, AutoKill, m_bAutoKill)
    GE_PROPERTY(GEBool, Enabled, m_bEnabled)
    GE_PADDING(3)
    GE_PROPERTY(bCRange1, Lifetime, m_rngLifetime)
    GE_PROPERTY(bCRange1, InitialAge, m_rngInitialAge)
    GE_PROPERTY(bCRange1, InitialDelay, m_rngInitialDelay)
    GE_PROPERTY(GEFloat, TicksPerSecond, m_fTicksPerSecond)
    GE_PROPERTY(GEFloat, SecondsBeforeInactive, m_fSecondsBeforeInactive)
    GE_PROPERTY(GEFloat, RelativeWarmupTime, m_fRelativeWarmupTime)
    GE_PROPERTY(GEFloat, WarmupTicksPerSecond, m_fWarmupTicksPerSecond)
    GE_ENUMPROP(eELocationShape, StartLocationShape, m_enuStartLocation)
    GE_PROPERTY(bCRange3, StartBoxLocation, m_rngBoxLocation)
    GE_PROPERTY(bCRange1, StartSphereRadius, m_rngSphereRadius)
    GE_PROPERTY(bCVector, StartLocationOffset, m_vecStartLocationOffset)
    GE_ENUMPROP(eECoordinateSystem, CoordinateSystem, m_enuCoordinateSystem)
    GE_PROPERTY(bCRange3, StartVelocity, m_rngStartVelocity)
    GE_PROPERTY(bCRange3, VelocityLoss, m_rngVelocityLoss)
    GE_PROPERTY(bCVector, Acceleration, m_vecAcceleration)
    GE_PROPERTY(bCVector, MaxAbsoluteVelocity, m_vecMaxAbsVelocity)
    GE_PROPERTY(GEBool, UseVelocityScale, m_bUseVelocityScale)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, VelocityScaleRepeats, m_fVelocityScaleRepeats)
    GE_ENUMPROP(eEVelocityDirectionFrom, VelocityDirectionFrom, m_enuVelocityDirectionFrom)
    GE_PROPERTY(GEBool, AddLocationFromTarget, m_bAddLocationFromTarget)
    GE_PADDING(3)
    GE_PROPERTY(eCEntityProxy, Target, m_entTarget)
    GE_PROPERTY(GEBool, SpinParticles, m_bSpinParticles)
    GE_PADDING(3)
    GE_PROPERTY(bCRange3, StartSpin, m_rngStartSpin)
    GE_PROPERTY(bCRange3, SpinsPerSecond, m_rngSpinsPerSecond)
    GE_PROPERTY(GEFloat, SpinDirection, m_fSpinDirection)
    GE_ENUMPROP(eEFacingDirection, FacingDirection, m_enuFacingDirection)
    GE_PROPERTY(bCVector, ProjectionNormal, m_vecProjectionNormal)
    GE_PROPERTY(bCVector, RelativeSpinPivot, m_vecRelativeSpinPivot)
    GE_ENUMPROP(eERotationFrom, UseRotationFrom, m_enuRotationFrom)
    GE_PROPERTY(GEBool, UseRevolution, m_bUseRevolution)
    GE_PADDING(3)
    GE_PROPERTY(bCRange3, RevolutionsPerSecond, m_rngRevolutionPerSecond)
    GE_PROPERTY(bCRange3, RevolutionCenterOffset, m_rngRevolutionCenterOffset)
    GE_PROPERTY(GEBool, UseRevolutionScale, m_bUseRevolutionScale)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, RevolutionScaleRepeats, m_fRevolutionScaleRepeats)
    GE_PROPERTY(GEBool, UniformSize, m_bUniformSize)
    GE_PADDING(3)
    GE_PROPERTY(bCRange3, StartSize, m_rngStartSize)
    GE_PROPERTY(GEBool, UseSizeScale, m_bUseSizeScale)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, SizeScaleRepeats, m_fSizeScaleRepeats)
    GE_PROPERTY(GEBool, StretchToEmitter, m_bStretchToEmitter)
    GE_PADDING(3)
    GE_PROPERTY(bCImageOrMaterialResourceString, Material, m_strMaterial)
    GE_PROPERTY(bCString, Texture, m_strTexture)
    GE_ENUMPROP(eETextureDrawStyle, DrawStyle, m_enuDrawStyle)
    GE_PROPERTY(GEInt, NumUSubdivisions, m_iUSubdivisions)
    GE_PROPERTY(GEInt, NumVSubdivisions, m_iVSubdivisions)
    GE_PROPERTY(GEInt, SubdivisionStart, m_iSubdivisionStart)
    GE_PROPERTY(GEInt, SubdivisionEnd, m_iSubdivisionEnd)
    GE_PROPERTY(GEBool, RandomSubdivision, m_bRandomSubdivision)
    GE_PROPERTY(GEBool, BlendBetweenSubdivisions, m_bBlendBetweenSubdivisions)
    GE_PROPERTY(GEBool, UseSubdivisionScale, m_bUseSubdivisionScale)
    GE_PROPERTY(GEBool, SubdivisionRowMajor, m_bSubdivisionRowMajor)
    GE_PROPERTY(GEFloat, SubdivisionScaleRepeats, m_fSubdivisionScaleRepeats)
    GE_PROPERTY(GEBool, FadeIn, m_bFadeIn)
    GE_PROPERTY(GEBool, FadeOut, m_bFadeOut)
    GE_PADDING(2)
    GE_PROPERTY(GEFloat, FadeInEndTime, m_fFadeInEndTime)
    GE_PROPERTY(GEFloat, FadeOutStartTime, m_fFadeOutStartTime)
    GE_PROPERTY(bCFloatAlphaColor, FaceInFactor, m_colFadeInFactor)
    GE_PROPERTY(bCFloatAlphaColor, FaceOutFactor, m_colFadeOutFactor)
    GE_PROPERTY(GEBool, UseColorScale, m_bUseColorScale)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, ColorScaleRepeats, m_fColorScaleRepeats)
    GE_PROPERTY(GEBool, DisableFogging, m_bDisableFogging)
    GE_PROPERTY(GEBool, AlphaTest, m_bAlphaTest)
    GE_PROPERTY(GEU8, AlphaReference, m_u8AlphaReference)
    GE_PROPERTY(GEBool, DepthTest, m_bDepthTest)
    GE_PROPERTY(GEBool, DepthWrite, m_bDepthWrite)
    GE_PROPERTY(GEBool, Instanced, m_bInstanced)
    GE_PADDING(2)
    GE_ENUMPROP(eELightingStyle, LightingStyle, m_enuLightingStyle)
    GE_ENUMPROP(eESpawningSound, SpawningSound, m_enuSpawningSound)
    GE_PROPERTY(bCRange1, SpawningSoundIndex, m_rngSpawningSoundIndex)
    GE_PROPERTY(bCRange1, SpawningSoundProbability, m_rngSpawningSoundProbability)
    GE_ENUMPROP(eECollisionSound, CollisionSound, m_enuCollisionSound)
    GE_PROPERTY(bCRange1, CollisionSoundIndex, m_rngCollisionSoundIndex)
    GE_PROPERTY(bCRange1, CollisionSoundProbability, m_rngCollisionSoundProbability)
    GE_PROPERTY(GEU32, MaxSimultaneousSounds, m_u32MaxSimultaneousSounds)
    GE_PROPERTY(GEU8, SoundPriority, m_u8SoundPriority)
    GE_PADDING(3)
    GE_PROPERTY(bCString, TriggerTag, m_strTriggerTag)
    GE_PROPERTY(GEBool, ResetOnTrigger, m_bResetOnTrigger)
    GE_PADDING(3)
    GE_PROPERTY(bCRange1, TriggerNumParticles, m_rngTriggerNumParticles)
    GE_PROPERTY(GEFloat, TriggerParticlesPerSecond, m_fTriggerParticlesPerSecond)
    GE_PROPERTY(GEBool, UseCollision, m_bUseCollision)
    GE_PROPERTY(GEBool, UseMaxCollisions, m_bUseMaxCollisions)
    GE_PADDING(2)
    GE_PROPERTY(bCRange1, MaxCollisions, m_rngMaxCollisions)
    GE_PROPERTY(bCRange3, DampingFactor, m_rngDampingFactor)
    GE_PROPERTY(GEBool, UseRotationDamping, m_bUseRotationDamping)
    GE_PADDING(3)
    GE_PROPERTY(bCRange3, RotationDampingFactor, m_rngRotationDampingFactor)
    GE_PROPERTY(bCVector, ExtentMulitplier, m_vecExtentMultiplier)
    GE_PROPERTY(GEFloat, MinSquaredVelocity, m_fMinSquaredVelocity)
    GE_PROPERTY(GEBool, CollideWithCharacters, m_bCollideWithCharacters)
    GE_PROPERTY(GEBool, CollideWithDynamic, m_bCollideWithDynamic)
    GE_PROPERTY(GEBool, CollideWithStatic, m_bCollideWithStatic)
    GE_PROPERTY(GEBool, CollideWithTransparent, m_bCollideWithTransparent)
    GE_PROPERTY(eCEntityProxy, SpawnFromOtherEmitter, m_entSpawnFromOtherEmitter)
    GE_PROPERTY(bCRange1, SpawnNumParticles, m_rngSpawnNumParticles)
    GE_PROPERTY(GEBool, UseSpawnedVelocityScale, m_bUseSpawnedVelocityScale)
    GE_PADDING(3)
    GE_PROPERTY(bCRange3, SpawnedVelocityScale, m_rngSpawnedVelocityScale)

  public:
    bCVector &AccessExtentMultiplier();
    eCEntityProxy &AccessTargetEntity();
    void ApplyDefaults();
    bCVector const &GetExtentMultiplier() const;
    GEFloat GetLocalTimeScale() const;
    eCEntityProxy const &GetTargetEntity() const;
    void OnDeviceReset();
    void Reset();
    void SetExtentMultiplier(bCVector const &);
    void SetLocalTimeScale(GEFloat);
    void SetTargetEntity(eCEntityProxy const &);
    void Trigger();

  protected:
    GEBool ApplyRenderStates(GEFloat);
    void CalcColor(GEFloat, bCFloatAlphaColor &) const;
    void CalcColorFactor(GEFloat, GEFloat, bCFloatAlphaColor &) const;
    void CalcExtents(bCBox &) const;
    void CalcFrame(GEFloat, GEFloat &) const;
    void CalcRevolutionFactor(GEFloat, bCVector &) const;
    void CalcSizeFactor(GEFloat, bCVector &) const;
    void CalcVelocityFactor(GEFloat, bCVector &) const;
    void CopyFromMaster(eCParticle_PS const *);
    GEBool CreateImage();
    GEBool CreateMaterial();
    GEBool CreateVertices();
    GEBool CreateVisual();
    void DepthSortParticles();
    void DoProcessV1();
    void DoProcessV2();
    void Dump() const;
    GEInt EmitParticles(GEFloat, GEFloat, GEInt);
    void GetRandomFrame(GEInt &) const;
    void GetRandomSpherePoint(bCVector &) const;
    void Initialize();
    void Invalidate();
    void OnCapacityChanged();
    void OnMaterialChanged();
    void OnTextureChanged();
    void PlayCollisionSound(eCParticle2 const &);
    eCAudioChannel *PlaySample(GEInt);
    void PlaySpawningSound(eCParticle2 const &);
    GEInt ProcessFrame(GEFloat);
    void ProcessParticles(GEFloat, GEFloat, GEFloat);
    GEInt ProcessTicks(GEInt, GEFloat);
    GEBool RenderPasses(eCIlluminated_PS *);
    GEBool RenderVertices(GEFloat, eCParticle_PS *);
    void ResetBuffers();
    void Spawn(eCParticle2 &, GEFloat);
    GEInt SpawnParticle(bCVector const &);
    GEInt TickParticles(GEFloat);
    void Update(eCParticle2 &, GEFloat);
    GEBool UpdateVertices();

  private:
    GEBool ApplyRenderStatesFF(GEFloat);
    GEBool ApplyRenderStatesFX(GEFloat);
    GEBool CreateVerticesFF();
    GEBool CreateVerticesFX();
    GEBool CreateVisualFF();
    GEBool CreateVisualFX();
    GEBool RenderPassesFF(eCIlluminated_PS *);
    GEBool RenderPassesFX(eCIlluminated_PS *);

  public:
    bTObjArray<eCParticle2> m_arrParticles;
    GEByte __UNK_0324[32];
    GEU32 __UNK_0344;
    GEU32 __UNK_0348;
    GEU32 __UNK_034C;
    GEByte __UNK_0350[68];
    GEUInt m_numAliveAndVisibleParticles;
    GEByte __UNK_0398[20];
    GEU32 __UNK_03AC;
    bTObjArray<eSFloatScaleItem> m_FloatScale1;
    bTObjArray<eSVectorScaleItem> m_VectorScale1;
    bTObjArray<eSVectorScaleItem> m_VectorScale2;
    bTObjArray<eSColorScaleItem> m_ColorScale1;
    bTObjArray<eSVectorScaleItem> m_VectorScale3;
    bTObjArray<eSParticleSound> m_arrParticleSounds;
};

GE_ASSERT_SIZEOF(eCParticle_PS, 0x3f8)

GE_ASSERT_PROPERTY(eCParticle_PS, m_iMaxNumParticles, 0x14, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_fParticlesPerSecond, 0x18, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bRespawnDeadParticles, 0x1c, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bAutomaticSpawning, 0x1d, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bAutoReset, 0x1e, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bAutoKill, 0x1f, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bEnabled, 0x20, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngLifetime, 0x24, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngInitialAge, 0x2c, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngInitialDelay, 0x34, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_fTicksPerSecond, 0x3c, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_fSecondsBeforeInactive, 0x40, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_fRelativeWarmupTime, 0x44, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_fWarmupTicksPerSecond, 0x48, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_enuStartLocation, 0x4c, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngBoxLocation, 0x54, 24)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngSphereRadius, 0x6c, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_vecStartLocationOffset, 0x74, 12)
GE_ASSERT_PROPERTY(eCParticle_PS, m_enuCoordinateSystem, 0x80, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngStartVelocity, 0x88, 24)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngVelocityLoss, 0xa0, 24)
GE_ASSERT_PROPERTY(eCParticle_PS, m_vecAcceleration, 0xb8, 12)
GE_ASSERT_PROPERTY(eCParticle_PS, m_vecMaxAbsVelocity, 0xc4, 12)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bUseVelocityScale, 0xd0, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_fVelocityScaleRepeats, 0xd4, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_enuVelocityDirectionFrom, 0xd8, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bAddLocationFromTarget, 0xe0, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_entTarget, 0xe4, 28)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bSpinParticles, 0x100, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngStartSpin, 0x104, 24)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngSpinsPerSecond, 0x11c, 24)
GE_ASSERT_PROPERTY(eCParticle_PS, m_fSpinDirection, 0x134, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_enuFacingDirection, 0x138, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_vecProjectionNormal, 0x140, 12)
GE_ASSERT_PROPERTY(eCParticle_PS, m_vecRelativeSpinPivot, 0x14c, 12)
GE_ASSERT_PROPERTY(eCParticle_PS, m_enuRotationFrom, 0x158, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bUseRevolution, 0x160, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngRevolutionPerSecond, 0x164, 24)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngRevolutionCenterOffset, 0x17c, 24)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bUseRevolutionScale, 0x194, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_fRevolutionScaleRepeats, 0x198, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bUniformSize, 0x19c, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngStartSize, 0x1a0, 24)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bUseSizeScale, 0x1b8, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_fSizeScaleRepeats, 0x1bc, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bStretchToEmitter, 0x1c0, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_strMaterial, 0x1c4, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_strTexture, 0x1c8, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_enuDrawStyle, 0x1cc, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_iUSubdivisions, 0x1d4, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_iVSubdivisions, 0x1d8, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_iSubdivisionStart, 0x1dc, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_iSubdivisionEnd, 0x1e0, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bRandomSubdivision, 0x1e4, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bBlendBetweenSubdivisions, 0x1e5, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bUseSubdivisionScale, 0x1e6, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bSubdivisionRowMajor, 0x1e7, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_fSubdivisionScaleRepeats, 0x1e8, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bFadeIn, 0x1ec, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bFadeOut, 0x1ed, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_fFadeInEndTime, 0x1f0, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_fFadeOutStartTime, 0x1f4, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_colFadeInFactor, 0x1f8, 20)
GE_ASSERT_PROPERTY(eCParticle_PS, m_colFadeOutFactor, 0x20c, 20)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bUseColorScale, 0x220, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_fColorScaleRepeats, 0x224, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bDisableFogging, 0x228, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bAlphaTest, 0x229, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_u8AlphaReference, 0x22a, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bDepthTest, 0x22b, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bDepthWrite, 0x22c, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bInstanced, 0x22d, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_enuLightingStyle, 0x230, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_enuSpawningSound, 0x238, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngSpawningSoundIndex, 0x240, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngSpawningSoundProbability, 0x248, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_enuCollisionSound, 0x250, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngCollisionSoundIndex, 0x258, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngCollisionSoundProbability, 0x260, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_u32MaxSimultaneousSounds, 0x268, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_u8SoundPriority, 0x26c, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_strTriggerTag, 0x270, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bResetOnTrigger, 0x274, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngTriggerNumParticles, 0x278, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_fTriggerParticlesPerSecond, 0x280, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bUseCollision, 0x284, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bUseMaxCollisions, 0x285, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngMaxCollisions, 0x288, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngDampingFactor, 0x290, 24)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bUseRotationDamping, 0x2a8, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngRotationDampingFactor, 0x2ac, 24)
GE_ASSERT_PROPERTY(eCParticle_PS, m_vecExtentMultiplier, 0x2c4, 12)
GE_ASSERT_PROPERTY(eCParticle_PS, m_fMinSquaredVelocity, 0x2d0, 4)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bCollideWithCharacters, 0x2d4, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bCollideWithDynamic, 0x2d5, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bCollideWithStatic, 0x2d6, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bCollideWithTransparent, 0x2d7, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_entSpawnFromOtherEmitter, 0x2d8, 28)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngSpawnNumParticles, 0x2f4, 8)
GE_ASSERT_PROPERTY(eCParticle_PS, m_bUseSpawnedVelocityScale, 0x2fc, 1)
GE_ASSERT_PROPERTY(eCParticle_PS, m_rngSpawnedVelocityScale, 0x300, 24)
