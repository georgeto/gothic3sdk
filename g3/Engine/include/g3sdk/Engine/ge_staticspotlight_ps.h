#pragma once

#include <Engine/ge_staticlight_ps.h>

#include <SharedBase.h>

class eCPrimitiveSpotLight
{
    GE_UNIMPL_STRUCT(eCPrimitiveSpotLight)
};

class eCPrimitiveSpotLightCone
{
    GE_UNIMPL_STRUCT(eCPrimitiveSpotLightCone)
};

class GE_DLLIMPORT eCStaticSpotLight_PS : public eCStaticLight_PS
{
    // clang-format off
    protected: virtual GEInt CollectEntitiesInRange(bTValArray<eCEntity *> &) const;
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCStaticSpotLight_PS() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    protected: GEBool IsVisual() const override;
    public: GEBool SupportsRenderDebugOutput() const override;
    protected: void OnRenderDebug() override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: GEBool IntersectsRay(eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc **) const override;
    protected: GEBool IntersectsVolume(bCVolume &, bCMatrix const &, bTValArray<bCTriangle> *, GEBool) const override;
    public: GEFloat GetWight(bCSphere const &) override;
    public: GEFloat GetWight(bCVector const &) override;
    public: GEBool IsBoxInRange(bCBox const &) override;
    public: GEBool CalculateStaticSHLighting(eCEntity *, bTSphericalHarmonics2<bCVector4> &) override;
    public: GEBool CalculateDynamicSHLighting(bCVector const &, bTSphericalHarmonics2<bCVector4> &) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCStaticSpotLight_PS, eCStaticLight_PS)
    GE_PROPERTY(bCFloatColor, Color, m_Color)
    GE_PROPERTY(GEFloat, Range, m_fRange)
    GE_PROPERTY(GEFloat, InnerAngle, m_fInnerAngle)
    GE_PROPERTY(GEFloat, OuterAngle, m_fOuterAngle)
    GE_PROPERTY(GEFloat, ConeFallOff, m_fConeFallOff)
    GE_PROPERTY(GEBool, CastShadows, m_bCastShadows)
    GE_PADDING(1)

  public:
    GEBool CalculateLight(bCMatrix const &, bCMatrix const &, bCFloatColor &, bCVector const &, bCVector const &,
                          GEBool) const;
    GEFloat GetCosPhi() const;
    GEFloat GetCosTheta() const;
    GEFloat GetIntensity(GEFloat, GEFloat) const;
    void GetOuterConeMatrix(bCMatrix &) const;

  protected:
    static eCPrimitiveSpotLightCone ms_SpotLightConePrimitive;
    static eCPrimitiveSpotLight ms_SpotLightPrimitive;

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(8)
};

GE_ASSERT_SIZEOF(eCStaticSpotLight_PS, 0x40)

GE_ASSERT_PROPERTY(eCStaticSpotLight_PS, m_Color, 0x14, 16)
GE_ASSERT_PROPERTY(eCStaticSpotLight_PS, m_fRange, 0x24, 4)
GE_ASSERT_PROPERTY(eCStaticSpotLight_PS, m_fInnerAngle, 0x28, 4)
GE_ASSERT_PROPERTY(eCStaticSpotLight_PS, m_fOuterAngle, 0x2c, 4)
GE_ASSERT_PROPERTY(eCStaticSpotLight_PS, m_fConeFallOff, 0x30, 4)
GE_ASSERT_PROPERTY(eCStaticSpotLight_PS, m_bCastShadows, 0x34, 1)
