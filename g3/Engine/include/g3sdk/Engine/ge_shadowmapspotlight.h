#pragma once

#include <Engine/ge_shadowmapbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCShadowMapSpotLight : public eCShadowMapBase
{
    // clang-format off
    public: virtual bEResult Create(GEInt, eEDepthMapFormat);
    public: GEU16 GetVersion() const override;
    public: ~eCShadowMapSpotLight() override;
    public: GEFloat GetLightRange() const override;
    protected: GEBool UpdateCamera(eCGfxShared::eECubeMapFace) override;
    // clang-format on

  public:
    eCShadowMapSpotLight(eCShadowMapSpotLight const &);
    eCShadowMapSpotLight();

  public:
    eCShadowMapSpotLight &operator=(eCShadowMapSpotLight const &);

  public:
    GEFloat GetLightConeAngle() const;
    bCMatrix const &GetLightWorldTransform() const;
    void SetLightConeAngle(GEFloat);
    void SetLightRange(GEFloat);
    void SetLightWorldTransform(bCMatrix const &);

  protected:
    void Invalidate();
};
