#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCJointLimitPairDesc : public bCObjectRefBase
{
    // clang-format off
    public: virtual void SetToDefault();
    public: GEBool IsValid() const override;
    public: ~eCJointLimitPairDesc() override;
    public: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCJointLimitPairDesc, bCObjectRefBase)
    GE_PROPERTY(GEFloat, Low, m_fLow)
    GE_PROPERTY(GEFloat, High, m_fHigh)
};

GE_ASSERT_SIZEOF(eCJointLimitPairDesc, 0x14)

GE_ASSERT_PROPERTY(eCJointLimitPairDesc, m_fLow, 0xc, 4)
GE_ASSERT_PROPERTY(eCJointLimitPairDesc, m_fHigh, 0x10, 4)
