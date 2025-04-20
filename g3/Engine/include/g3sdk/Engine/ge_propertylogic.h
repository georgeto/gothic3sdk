#pragma once

#include <Engine/ge_propertyproxy.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCPropertyLogic : public bCObjectRefBase
{
    // clang-format off
    public: ~eCPropertyLogic() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCPropertyLogic, bCObjectRefBase)
    GE_PROPERTY(eCPropertyProxy, TargetEntityProperty, m_TargetEntityProperty)
    GE_PROPERTY(eCPropertyProxy, TargetProperty, m_TargetProperty)
    GE_PROPERTY(GEFloat, ValueLowerBound, m_fValueLowerBound)
    GE_PROPERTY(GEFloat, ValueUpperBound, m_fValueUpperBound)
    GE_PROPERTY(eCPropertyProxy, PropertyValue, m_fPropertyValue)
    GE_PROPERTY(eCPropertyProxy, PropertyValueLowerBound, m_fPropertyValueLowerBound)
    GE_PROPERTY(eCPropertyProxy, PropertyValueUpperBound, m_fPropertyValueUpperBound)
    GE_PROPERTY(bCString, ConditionOperator, m_strConditionOperator)
    GE_PROPERTY(GEFloat, ConditionValue, m_fConditionValue)
    GE_PROPERTY(eCPropertyProxy, ConditionValueProperty, m_ConditionValueProperty)
};

GE_ASSERT_SIZEOF(eCPropertyLogic, 0x124)

GE_ASSERT_PROPERTY(eCPropertyLogic, m_TargetEntityProperty, 0xc, 44)
GE_ASSERT_PROPERTY(eCPropertyLogic, m_TargetProperty, 0x38, 44)
GE_ASSERT_PROPERTY(eCPropertyLogic, m_fValueLowerBound, 0x64, 4)
GE_ASSERT_PROPERTY(eCPropertyLogic, m_fValueUpperBound, 0x68, 4)
GE_ASSERT_PROPERTY(eCPropertyLogic, m_fPropertyValue, 0x6c, 44)
GE_ASSERT_PROPERTY(eCPropertyLogic, m_fPropertyValueLowerBound, 0x98, 44)
GE_ASSERT_PROPERTY(eCPropertyLogic, m_fPropertyValueUpperBound, 0xc4, 44)
GE_ASSERT_PROPERTY(eCPropertyLogic, m_strConditionOperator, 0xf0, 4)
GE_ASSERT_PROPERTY(eCPropertyLogic, m_fConditionValue, 0xf4, 4)
GE_ASSERT_PROPERTY(eCPropertyLogic, m_ConditionValueProperty, 0xf8, 44)
