#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCSpringDesc : public bCObjectRefBase
{
    // clang-format off
    public: virtual void SetToDefault();
    public: GEBool IsValid() const override;
    public: ~eCSpringDesc() override;
    public: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCSpringDesc, bCObjectRefBase)
    GE_PROPERTY(GEFloat, Spring, m_fSpring)
    GE_PROPERTY(GEFloat, Damper, m_fDamper)
    GE_PROPERTY(GEFloat, TargetValue, m_fTargetValue)
};

GE_ASSERT_SIZEOF(eCSpringDesc, 0x18)

GE_ASSERT_PROPERTY(eCSpringDesc, m_fSpring, 0xc, 4)
GE_ASSERT_PROPERTY(eCSpringDesc, m_fDamper, 0x10, 4)
GE_ASSERT_PROPERTY(eCSpringDesc, m_fTargetValue, 0x14, 4)
