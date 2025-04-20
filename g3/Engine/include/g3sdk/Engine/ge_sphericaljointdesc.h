#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_jointdesc.h>
#include <Engine/ge_jointlimitdesc.h>
#include <Engine/ge_jointlimitpairdesc.h>
#include <Engine/ge_springdesc.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCSphericalJointDesc : public eCJointDesc
{
    // clang-format off
    public: GEBool IsValid() const override;
    public: ~eCSphericalJointDesc() override;
    public: bEResult PostInitializeProperties() override;
    public: void SetToDefault() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCSphericalJointDesc, eCJointDesc)
    GE_PROPERTY(bCVector, SwingAxis, m_vecSwingAxis)
    GE_PROPERTY(GEFloat, ProjectionDistance, m_fProjectionDistance)
    GE_PROPERTY(GEBool, EnableTwistLimit, m_bEnableTwistLimit)
    GE_PROPERTY(GEBool, EnableSwingLimit, m_bEnableSwingLimit)
    GE_PROPERTY(GEBool, EnableTwistSpring, m_bEnableTwistSpring)
    GE_PROPERTY(GEBool, EnableSwingSpring, m_bEnableSwingSpring)
    GE_PROPERTY(GEBool, EnableJointSpring, m_bEnableJointSpring)
    GE_PADDING(3)
    GE_ENUMPROP(eEJointProjectionMode, JointProjectionMode, m_enuJointProjectionMode)
    GE_OBJECTPROP(eCSpringDesc, bCObjectRefBase, TwistSpring, m_poTwistSpring)
    GE_OBJECTPROP(eCSpringDesc, bCObjectRefBase, SwingSpring, m_poSwingSpring)
    GE_OBJECTPROP(eCSpringDesc, bCObjectRefBase, JointSpring, m_poJointSpring)
    GE_OBJECTPROP(eCJointLimitPairDesc, bCObjectRefBase, TwistLimit, m_poTwistLimit)
    GE_OBJECTPROP(eCJointLimitDesc, bCObjectRefBase, SwingLimit, m_poSwingLimit)
};

GE_ASSERT_SIZEOF(eCSphericalJointDesc, 0xd8)

GE_ASSERT_PROPERTY(eCSphericalJointDesc, m_vecSwingAxis, 0x68, 12)
GE_ASSERT_PROPERTY(eCSphericalJointDesc, m_fProjectionDistance, 0x74, 4)
GE_ASSERT_PROPERTY(eCSphericalJointDesc, m_bEnableTwistLimit, 0x78, 1)
GE_ASSERT_PROPERTY(eCSphericalJointDesc, m_bEnableSwingLimit, 0x79, 1)
GE_ASSERT_PROPERTY(eCSphericalJointDesc, m_bEnableTwistSpring, 0x7a, 1)
GE_ASSERT_PROPERTY(eCSphericalJointDesc, m_bEnableSwingSpring, 0x7b, 1)
GE_ASSERT_PROPERTY(eCSphericalJointDesc, m_bEnableJointSpring, 0x7c, 1)
GE_ASSERT_PROPERTY(eCSphericalJointDesc, m_enuJointProjectionMode, 0x80, 8)
GE_ASSERT_PROPERTY(eCSphericalJointDesc, m_poTwistSpring, 0x88, 16)
GE_ASSERT_PROPERTY(eCSphericalJointDesc, m_poSwingSpring, 0x98, 16)
GE_ASSERT_PROPERTY(eCSphericalJointDesc, m_poJointSpring, 0xa8, 16)
GE_ASSERT_PROPERTY(eCSphericalJointDesc, m_poTwistLimit, 0xb8, 16)
GE_ASSERT_PROPERTY(eCSphericalJointDesc, m_poSwingLimit, 0xc8, 16)
