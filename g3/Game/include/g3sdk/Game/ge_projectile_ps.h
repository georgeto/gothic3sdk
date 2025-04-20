#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCProjectile_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCProjectile_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    protected: GEBool IsProcessable() const override;
    protected: void OnTrigger(eCEntity *, eCEntity *) override;
    protected: void OnTouch(eCEntity *, eCContactIterator &) override;
    protected: void OnExitProcessingRange() override;
    public: void Decay() override;
    protected: void OnProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCProjectile_PS, eCEntityPropertySet)
    GE_PROPERTY(eCEntityProxy, TargetEntity, m_TargetEntity)
    GE_PROPERTY(bCVector, TargetPosition, m_vecTargetPos)
    GE_PROPERTY(bCVector, TargetDirection, m_vecTargetDirection)
    GE_PROPERTY(GEU32, TargetUpdateMSec, m_u32TargetUpdateMSec)
    GE_ENUMPROP(gEProjectilePath, PathStyle, m_enuPathStyle)
    GE_ENUMPROP(gEProjectileTouchBehavior, TouchBehavior, m_enuTouchBehavior)
    GE_PROPERTY(GEFloat, ShootVelocity, m_fShootVelocity)
    GE_PROPERTY(GEFloat, TouchAngleTreshold, m_fTouchAngleTreshold)
    GE_PROPERTY(GEBool, LinkToBones, m_bLinkToBones)
    GE_PROPERTY(GEBool, FadeOnDecay, m_bFadeOnDecay)
    GE_PADDING(2)
    GE_PROPERTY(GEFloat, DecayDuration, m_fDecayDuration)
    GE_PROPERTY(bCString, EffectPointImpact, m_strEffectPointImpact)
    GE_PROPERTY(bCString, EffectTargetHit, m_strEffectTargetHit)
    GE_PROPERTY(bCString, FuncOnTargetHit, m_strScriptOnTargetHit)

  public:
    GEBool HasCollided() const;
    GEBool IsFlying() const;
    void Shoot();

  protected:
    bCVector GetDirection() const;
    void Invalidate();
    void ShootIteration();

  private:
    GE_UNIMPL_MEMBERS(36)
};

GE_ASSERT_SIZEOF(gCProjectile_PS, 0x9c)

GE_ASSERT_PROPERTY(gCProjectile_PS, m_TargetEntity, 0x14, 28)
GE_ASSERT_PROPERTY(gCProjectile_PS, m_vecTargetPos, 0x30, 12)
GE_ASSERT_PROPERTY(gCProjectile_PS, m_vecTargetDirection, 0x3c, 12)
GE_ASSERT_PROPERTY(gCProjectile_PS, m_u32TargetUpdateMSec, 0x48, 4)
GE_ASSERT_PROPERTY(gCProjectile_PS, m_enuPathStyle, 0x4c, 8)
GE_ASSERT_PROPERTY(gCProjectile_PS, m_enuTouchBehavior, 0x54, 8)
GE_ASSERT_PROPERTY(gCProjectile_PS, m_fShootVelocity, 0x5c, 4)
GE_ASSERT_PROPERTY(gCProjectile_PS, m_fTouchAngleTreshold, 0x60, 4)
GE_ASSERT_PROPERTY(gCProjectile_PS, m_bLinkToBones, 0x64, 1)
GE_ASSERT_PROPERTY(gCProjectile_PS, m_bFadeOnDecay, 0x65, 1)
GE_ASSERT_PROPERTY(gCProjectile_PS, m_fDecayDuration, 0x68, 4)
GE_ASSERT_PROPERTY(gCProjectile_PS, m_strEffectPointImpact, 0x6c, 4)
GE_ASSERT_PROPERTY(gCProjectile_PS, m_strEffectTargetHit, 0x70, 4)
GE_ASSERT_PROPERTY(gCProjectile_PS, m_strScriptOnTargetHit, 0x74, 4)
