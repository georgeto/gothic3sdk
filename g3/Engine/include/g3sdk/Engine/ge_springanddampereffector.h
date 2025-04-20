#pragma once

#include <Engine/ge_effector.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCSpringAndDamperEffector : public eCEffector
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCSpringAndDamperEffector() override;
    public: bEResult PostInitializeProperties() override;
    public: eEEffectorType GetType() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCSpringAndDamperEffector, eCEffector)
    GE_PROPERTY(GEFloat, SpringDistCompressSaturate, m_fSpringDistCompressSaturate)
    GE_PROPERTY(GEFloat, SpringDistRelaxed, m_fSpringDistRelaxed)
    GE_PROPERTY(GEFloat, SpringDistStretchSaturate, m_fSpringDistStretchSaturate)
    GE_PROPERTY(GEFloat, SpringMaxCompressForce, m_fSpringMaxCompressForce)
    GE_PROPERTY(GEFloat, SpringMaxStretchForce, m_fSpringMaxStretchForce)
    GE_PROPERTY(GEFloat, DamperVelCompressSaturate, m_fDamperVelCompressSaturate)
    GE_PROPERTY(GEFloat, DamperVelStretchSaturate, m_fDamperVelStretchSaturate)
    GE_PROPERTY(GEFloat, DamperMaxCompressForce, m_fDamperMaxCompressForce)
    GE_PROPERTY(GEFloat, DamperMaxStretchForce, m_fDamperMaxStretchForce)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCSpringAndDamperEffector, 0x80)

GE_ASSERT_PROPERTY(eCSpringAndDamperEffector, m_fSpringDistCompressSaturate, 0x5c, 4)
GE_ASSERT_PROPERTY(eCSpringAndDamperEffector, m_fSpringDistRelaxed, 0x60, 4)
GE_ASSERT_PROPERTY(eCSpringAndDamperEffector, m_fSpringDistStretchSaturate, 0x64, 4)
GE_ASSERT_PROPERTY(eCSpringAndDamperEffector, m_fSpringMaxCompressForce, 0x68, 4)
GE_ASSERT_PROPERTY(eCSpringAndDamperEffector, m_fSpringMaxStretchForce, 0x6c, 4)
GE_ASSERT_PROPERTY(eCSpringAndDamperEffector, m_fDamperVelCompressSaturate, 0x70, 4)
GE_ASSERT_PROPERTY(eCSpringAndDamperEffector, m_fDamperVelStretchSaturate, 0x74, 4)
GE_ASSERT_PROPERTY(eCSpringAndDamperEffector, m_fDamperMaxCompressForce, 0x78, 4)
GE_ASSERT_PROPERTY(eCSpringAndDamperEffector, m_fDamperMaxStretchForce, 0x7c, 4)
