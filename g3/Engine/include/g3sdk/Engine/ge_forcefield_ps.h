#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_trigger_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCForceField_PS : public eCTrigger_PS
{
    // clang-format off
    protected: virtual void ApplyForce(eCEntity *, eCContactIterator &);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCForceField_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    protected: void TriggerTarget(eCEntity *, eCEntity *, eCContactIterator &) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCForceField_PS, eCTrigger_PS)
    GE_ENUMPROP(eEForceFieldType, Type, m_enuType)
    GE_ENUMPROP(eEForceFieldDirMode, DirMode, m_enuDirMode)
    GE_ENUMPROP(eEForceFieldDistanceScale, DistanceScaleType, m_enuDistanceScale)
    GE_PROPERTY(GEFloat, Force, m_fForce)
    GE_PROPERTY(GEFloat, InnerRadius, m_fInnerRadius)
    GE_PADDING(1)
    GE_PROPERTY(GEBool, ApplyToNPCs, m_bApplyToNPCs)
    GE_PROPERTY(GEBool, ApplyToPlayers, m_bApplyToPlayers)
    GE_PROPERTY(GEBool, ApplyToObjects, m_bApplyToObjects)

  public:
    GEBool &AccessApplyToTouchingEntities();
    GEBool const &GetApplyToTouchingEntities() const;
    void SetApplyToTouchingEntities(GEBool const &);

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCForceField_PS, 0x108)

GE_ASSERT_PROPERTY(eCForceField_PS, m_enuType, 0xe4, 8)
GE_ASSERT_PROPERTY(eCForceField_PS, m_enuDirMode, 0xec, 8)
GE_ASSERT_PROPERTY(eCForceField_PS, m_enuDistanceScale, 0xf4, 8)
GE_ASSERT_PROPERTY(eCForceField_PS, m_fForce, 0xfc, 4)
GE_ASSERT_PROPERTY(eCForceField_PS, m_fInnerRadius, 0x100, 4)
GE_ASSERT_PROPERTY(eCForceField_PS, m_bApplyToNPCs, 0x105, 1)
GE_ASSERT_PROPERTY(eCForceField_PS, m_bApplyToPlayers, 0x106, 1)
GE_ASSERT_PROPERTY(eCForceField_PS, m_bApplyToObjects, 0x107, 1)
