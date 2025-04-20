#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCDamageReceiver_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCDamageReceiver_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: bEResult ReadSaveGame(bCIStream &) override;
    public: bEResult WriteSaveGame(bCOStream &) override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void OnProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCDamageReceiver_PS, eCEntityPropertySet)
    GE_PROPERTY(GEI32, HitPoints, m_iHitPoints)
    GE_PROPERTY(GEI32, HitPointsMax, m_iHitPointsMax)
    GE_PROPERTY(GEI32, StaminaPoints, m_iStaminaPoints)
    GE_PROPERTY(GEI32, StaminaPointsMax, m_iStaminaPointsMax)
    GE_PROPERTY(GEI32, ManaPoints, m_iManaPoints)
    GE_PROPERTY(GEI32, ManaPointsMax, m_iManaPointsMax)
    GE_ENUMPROP(gEDamageType, DamageType, m_enuDamageType)
    GE_PROPERTY(GEI32, DamageAmount, m_i32DamageAmount)
    GE_PROPERTY(eCEntityProxy, LastInflictor, m_LastInflictor)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCDamageReceiver_PS, 0x54)

GE_ASSERT_PROPERTY(gCDamageReceiver_PS, m_iHitPoints, 0x14, 4)
GE_ASSERT_PROPERTY(gCDamageReceiver_PS, m_iHitPointsMax, 0x18, 4)
GE_ASSERT_PROPERTY(gCDamageReceiver_PS, m_iStaminaPoints, 0x1c, 4)
GE_ASSERT_PROPERTY(gCDamageReceiver_PS, m_iStaminaPointsMax, 0x20, 4)
GE_ASSERT_PROPERTY(gCDamageReceiver_PS, m_iManaPoints, 0x24, 4)
GE_ASSERT_PROPERTY(gCDamageReceiver_PS, m_iManaPointsMax, 0x28, 4)
GE_ASSERT_PROPERTY(gCDamageReceiver_PS, m_enuDamageType, 0x2c, 8)
GE_ASSERT_PROPERTY(gCDamageReceiver_PS, m_i32DamageAmount, 0x34, 4)
GE_ASSERT_PROPERTY(gCDamageReceiver_PS, m_LastInflictor, 0x38, 28)
