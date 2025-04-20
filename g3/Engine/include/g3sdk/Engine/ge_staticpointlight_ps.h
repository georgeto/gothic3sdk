#pragma once

#include <Engine/ge_staticlight_ps.h>

#include <SharedBase.h>

class eCPrimitivePointLightCenter
{
    GE_UNIMPL_STRUCT(eCPrimitivePointLightCenter)
};

class eCPrimitivePointLightRadius
{
    GE_UNIMPL_STRUCT(eCPrimitivePointLightRadius)
};

class GE_DLLIMPORT eCStaticPointLight_PS : public eCStaticLight_PS
{
    // clang-format off
    protected: virtual GEInt CollectEntitiesInRange(bTValArray<eCEntity *> &) const;
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCStaticPointLight_PS() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    protected: GEBool IsVisual() const override;
    public: GEBool SupportsRenderDebugOutput() const override;
    protected: void OnRenderDebug() override;
    public: void OnUpdatedWorldMatrix() override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    public: void OnPostRead() override;
    protected: GEBool IntersectsRay(eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc **) const override;
    protected: GEBool IntersectsVolume(bCVolume &, bCMatrix const &, bTValArray<bCTriangle> *, GEBool) const override;
    public: GEFloat GetWight(bCSphere const &) override;
    public: GEFloat GetWight(bCVector const &) override;
    public: GEBool IsBoxInRange(bCBox const &) override;
    public: GEBool CalculateStaticSHLighting(eCEntity *, bTSphericalHarmonics2<bCVector4> &) override;
    public: GEBool CalculateDynamicSHLighting(bCVector const &, bTSphericalHarmonics2<bCVector4> &) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCStaticPointLight_PS, eCStaticLight_PS)
    GE_PROPERTY(bCFloatColor, Color, m_Color)
    GE_PROPERTY(GEFloat, Range, m_fRange)
    GE_PROPERTY(GEBool, CastShadows, m_bCastShadows)
    GE_PADDING(3)
    GE_PROPERTY(bCVector, Offset, m_vecOffset)

  public:
    GEBool CalculateLight(bCMatrix const &, bCMatrix const &, bCFloatColor &, bCVector const &, bCVector const &,
                          GEBool) const;
    GEFloat GetIntensity(GEFloat, GEFloat) const;
    bCVector const &GetPosition() const;

  protected:
    static eCPrimitivePointLightCenter ms_CenterPrimitive;
    static eCPrimitivePointLightRadius ms_RadiusPrimitive;

  protected:
    void Invalidate();
    void UpdatePosition();

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(eCStaticPointLight_PS, 0x44)

GE_ASSERT_PROPERTY(eCStaticPointLight_PS, m_Color, 0x14, 16)
GE_ASSERT_PROPERTY(eCStaticPointLight_PS, m_fRange, 0x24, 4)
GE_ASSERT_PROPERTY(eCStaticPointLight_PS, m_bCastShadows, 0x28, 1)
GE_ASSERT_PROPERTY(eCStaticPointLight_PS, m_vecOffset, 0x2c, 12)
