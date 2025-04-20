#pragma once

#include <Engine/entity/ge_entitypropertyset.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCSpeedTreeWind_PS : public eCEntityPropertySet
{
    // clang-format off
    public: virtual GEBool IsResourceLoaded() const;
    public: virtual GEBool ConvertFrom(eCSpeedTreeWind_PS const &);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCSpeedTreeWind_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: eCSpeedTreeWind_PS * Clone(eCEntity *) const override;
    protected: void OnUpdateInternals() override;
    protected: void OnCacheIn() override;
    protected: void OnCacheOut() override;
    public: void GetBoundary(bCBox &, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCSpeedTreeWind_PS, eCEntityPropertySet)
    GE_PROPERTY(GEFloat, WindStrange, m_fWindStrange)
    GE_PROPERTY(bCVector, BendLow, m_vecBendLow)
    GE_PROPERTY(bCVector, BendHigh, m_vecBendHigh)
    GE_PROPERTY(bCVector, VibrationLow, m_vecVibrationLow)
    GE_PROPERTY(bCVector, VibrationHigh, m_vecVibrationHigh)
    GE_PROPERTY(bCVector2, VibrationFrequency, m_vecVibrationFrequency)
    GE_PROPERTY(bCVector2, VibrationAngles, m_vecVibrationAngles)
    GE_PROPERTY(GEFloat, MaxBendAngle, m_fMaxBendAngle)
    GE_PROPERTY(GEFloat, StrengthAdjustmentExponent, m_fStrengthAdjustmentExponent)
    GE_PROPERTY(bCVector2, GustStrength, m_vecGustStrength)
    GE_PROPERTY(bCVector2, GustDuration, m_vecGustDuration)
    GE_PROPERTY(GEFloat, GustFrequency, m_fGustFrequency)
    GE_PROPERTY(bCVector, GustControl, m_vecGustControl)
    GE_PROPERTY(GEFloat, LeafStrengthExponent, m_fLeafStrengthExponent)
    GE_PROPERTY(bCVector, LeafRocking, m_vecLeafRockingLow)
    GE_PROPERTY(bCVector, LeafRockingHigh, m_vecLeafRockingHigh)
    GE_PROPERTY(bCVector2, LeafRockingFrequency, m_vecLeafRockingFrequency)
    GE_PROPERTY(bCVector2, LeafRockingAngles, m_vecLeafRockingAngles)
    GE_PROPERTY(bCVector, LeafRustling, m_vecLeafRustlingLow)
    GE_PROPERTY(bCVector, LeafRustlingHigh, m_vecLeafRustlingHigh)
    GE_PROPERTY(bCVector2, LeafRustlingFrequency, m_vecLeafRustlingFrequency)
    GE_PROPERTY(bCVector2, LeafRustlingAngles, m_vecLeafRustlingAngles)

  public:
    GEBool Advance(GEFloat, bCVector const *);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(eCSpeedTreeWind_PS, 0xe0)

GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_fWindStrange, 0x14, 4)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_vecBendLow, 0x18, 12)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_vecBendHigh, 0x24, 12)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_vecVibrationLow, 0x30, 12)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_vecVibrationHigh, 0x3c, 12)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_vecVibrationFrequency, 0x48, 8)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_vecVibrationAngles, 0x50, 8)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_fMaxBendAngle, 0x58, 4)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_fStrengthAdjustmentExponent, 0x5c, 4)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_vecGustStrength, 0x60, 8)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_vecGustDuration, 0x68, 8)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_fGustFrequency, 0x70, 4)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_vecGustControl, 0x74, 12)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_fLeafStrengthExponent, 0x80, 4)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_vecLeafRockingLow, 0x84, 12)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_vecLeafRockingHigh, 0x90, 12)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_vecLeafRockingFrequency, 0x9c, 8)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_vecLeafRockingAngles, 0xa4, 8)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_vecLeafRustlingLow, 0xac, 12)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_vecLeafRustlingHigh, 0xb8, 12)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_vecLeafRustlingFrequency, 0xc4, 8)
GE_ASSERT_PROPERTY(eCSpeedTreeWind_PS, m_vecLeafRustlingAngles, 0xcc, 8)
