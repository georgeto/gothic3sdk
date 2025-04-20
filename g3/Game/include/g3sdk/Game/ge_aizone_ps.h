#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCAIZone_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCAIZone_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCAIZone_PS, eCEntityPropertySet)
    GE_ENUMPROP(gEZoneType, Type, m_enuZoneType)
    GE_ENUMPROP(gESecurityLevel, SecurityLevel, m_enuSecurityLevel)
    GE_PROPERTY(eCEntityProxy, Owner, m_owner)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCAIZone_PS, 0x40)

GE_ASSERT_PROPERTY(gCAIZone_PS, m_enuZoneType, 0x14, 8)
GE_ASSERT_PROPERTY(gCAIZone_PS, m_enuSecurityLevel, 0x1c, 8)
GE_ASSERT_PROPERTY(gCAIZone_PS, m_owner, 0x24, 28)
