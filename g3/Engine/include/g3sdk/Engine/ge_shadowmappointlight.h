#pragma once

#include <Engine/ge_shadowmapbase.h>

#include <SharedBase.h>

class eCPointLight_PS;

class GE_DLLIMPORT eCShadowMapPointLight : public eCShadowMapBase
{
    // clang-format off
    public: virtual bEResult Create(GEInt, eEDepthMapFormat);
    public: virtual GEBool RenderShadowMap(bTValArray<eCEntity *> *);
    public: GEU16 GetVersion() const override;
    public: ~eCShadowMapPointLight() override;
    public: GEFloat GetLightRange() const override;
    public: bTValArray<eCEntity *> const * GetShadowCaster() const override;
    public: GEBool IsShadowCusterCullingEnabled() const override;
    protected: GEBool UpdateCamera(eCGfxShared::eECubeMapFace) override;
    // clang-format on

  public:
    eCShadowMapPointLight(eCShadowMapPointLight const &);
    eCShadowMapPointLight();

  public:
    eCShadowMapPointLight &operator=(eCShadowMapPointLight const &);

  public:
    bCVector const &GetLightPos() const;
    eCPointLight_PS *GetPointLight() const;
    void SetLightPos(bCVector const &);
    void SetLightRange(GEFloat);
    void SetPointLight(eCPointLight_PS *);

  protected:
    void Invalidate();
};
