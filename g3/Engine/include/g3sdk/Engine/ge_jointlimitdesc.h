#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCJointLimitDesc : public bCObjectRefBase
{
    // clang-format off
    public: virtual void SetToDefault();
    public: GEBool IsValid() const override;
    public: ~eCJointLimitDesc() override;
    public: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCJointLimitDesc, bCObjectRefBase)
    GE_PROPERTY(GEFloat, Value, m_fValue)
    GE_PROPERTY(GEFloat, Restitution, m_fRestitution)
    GE_PROPERTY(GEFloat, Hardness, m_fHardness)
};

GE_ASSERT_SIZEOF(eCJointLimitDesc, 0x18)

GE_ASSERT_PROPERTY(eCJointLimitDesc, m_fValue, 0xc, 4)
GE_ASSERT_PROPERTY(eCJointLimitDesc, m_fRestitution, 0x10, 4)
GE_ASSERT_PROPERTY(eCJointLimitDesc, m_fHardness, 0x14, 4)
