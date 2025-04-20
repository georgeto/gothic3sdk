#pragma once

#include <Engine/entity/ge_entitypropertyset.h>
#include <Engine/ge_shadermaterialadmin.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCStaticLight_PS : public eCEntityPropertySet
{
    // clang-format off
    public: virtual GEFloat GetWight(bCSphere const &);
    public: virtual GEFloat GetWight(bCVector const &);
    public: virtual GEBool IsBoxInRange(bCBox const &);
    public: virtual GEBool IsObjectInRange(eCEntity *);
    public: virtual GEBool CalculateStaticSHLighting(eCEntity *, bTSphericalHarmonics2<bCVector4> &);
    public: virtual GEBool CalculateDynamicSHLighting(bCVector const &, bTSphericalHarmonics2<bCVector4> &);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCStaticLight_PS() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    protected: void OnEnterProcessingRange() override;
    protected: void OnExitProcessingRange() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCStaticLight_PS, eCEntityPropertySet)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCStaticLight_PS, 0x14)
