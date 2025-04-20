#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCDamage_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCDamage_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCDamage_PS, eCEntityPropertySet)
    GE_ENUMPROP(gEDamageType, DamageType, m_enuDamageType)
    GE_PROPERTY(GEI32, DamageAmount, m_iDamageAmount)
    GE_PROPERTY(GEFloat, DamageManaMultiplier, m_fDamageManaMultiplier)
    GE_PROPERTY(GEFloat, DamageHitMultiplier, m_fDamageHitMultiplier)
    GE_PROPERTY(GEInt, ManaUsed, m_iManaUsed) // Read only

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCDamage_PS, 0x2c)

GE_ASSERT_PROPERTY(gCDamage_PS, m_enuDamageType, 0x14, 8)
GE_ASSERT_PROPERTY(gCDamage_PS, m_iDamageAmount, 0x1c, 4)
GE_ASSERT_PROPERTY(gCDamage_PS, m_fDamageManaMultiplier, 0x20, 4)
GE_ASSERT_PROPERTY(gCDamage_PS, m_fDamageHitMultiplier, 0x24, 4)
GE_ASSERT_PROPERTY(gCDamage_PS, m_iManaUsed, 0x28, 4)
