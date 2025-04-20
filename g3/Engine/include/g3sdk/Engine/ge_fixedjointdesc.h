#pragma once

#include <Engine/ge_jointdesc.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCFixedJointDesc : public eCJointDesc
{
    // clang-format off
    public: GEBool IsValid() const override;
    public: ~eCFixedJointDesc() override;
    public: void SetToDefault() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCFixedJointDesc, eCJointDesc)
};

GE_ASSERT_SIZEOF(eCFixedJointDesc, 0x68)
