#pragma once

#include <Engine/ge_shadermaterialadmin.h>

#include <SharedBase.h>

class eCEntity;
class eCEntityPropertySet;
class eCFrustumFilter;
class eCIterator;
class eCStaticPointLight_PS;
class eCStaticSpotLight_PS;

class GE_DLLIMPORT eCStaticLightPreprocessor : public bCObjectRefBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCStaticLightPreprocessor() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCStaticLightPreprocessor, bCObjectRefBase)

  public:
    static GEBool GE_STDCALL ComputeAmbientOcclusionRay(bCVector const &, bCVector const &, GEFloat &);
    static void GE_STDCALL SHTextureDebugOut(bTSphericalHarmonics2<bCVector4> const &, GEInt, bCString const &, GEBool);

  public:
    GEBool ComputeAmbientOcclusion(eCEntity *, GEBool);
    GEBool ComputeAmbientOcclusionRay(eCEntity *, bCVector const &, GEFloat &);
    GEFloat ComputeAmbientOcclusionRays(eCEntity *);
    GEBool ComputeAmbientOcclusionVolume(eCEntity *, GEFloat &);
    GEBool ComputeStaticLightData(eCEntity *, GEBool);
    GEBool ComputeStaticLighting(bCBox const &, GEBool);
    GEBool ComputeStaticLighting(eCEntity *, GEBool, GEBool, GEBool, GEBool);
    GEBool ComputeStaticLighting(GEBool);

  protected:
    static GEBool GE_STDCALL FindStaticLights(eCEntity *, bTValArray<eCStaticPointLight_PS *> &,
                                              bTValArray<eCStaticSpotLight_PS *> &, GEBool);
    static GEBool GE_STDCALL ItStaticAOPropertySetCallback(eCEntityPropertySet *, eCIterator &);
    static GEBool GE_STDCALL ShadowFrustumFilterEntities(eCFrustumFilter *, eCEntity *);
    static GEBool GE_STDCALL ShadowIteratorEntityCallback(eCEntity *, eCIterator &);
    static GEInt GE_CCALL SortPointLightsByWight(GELPCVoid, GELPCVoid);
    static GEInt GE_CCALL SortShadowedPointLightsByWight(GELPCVoid, GELPCVoid);
    static GEInt GE_CCALL SortSpotLightsByWight(GELPCVoid, GELPCVoid);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(36)
};

GE_ASSERT_SIZEOF(eCStaticLightPreprocessor, 0x30)
