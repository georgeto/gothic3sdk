#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCMotorDesc : public bCObjectRefBase
{
    // clang-format off
    public: virtual void SetToDefault();
    public: GEBool IsValid() const override;
    public: ~eCMotorDesc() override;
    public: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCMotorDesc, bCObjectRefBase)
};

GE_ASSERT_SIZEOF(eCMotorDesc, 0xc)
