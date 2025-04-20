#pragma once

#include <Engine/ge_shadowmapdirectionallightbase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCShadowMapDirectionalLight : public eCShadowMapDirectionalLightBase
{
    // clang-format off
    public: virtual bEResult Create(GEInt, eEDepthMapFormat);
    public: GEU16 GetVersion() const override;
    public: void Destroy() override;
    public: ~eCShadowMapDirectionalLight() override;
    public: GEBool DestroyRenderTarget() override;
    public: GEFloat GetLightRange() const override;
    public: bTValArray<eCEntity *> const * GetShadowCaster() const override;
    protected: GEBool UpdateCamera(eCGfxShared::eECubeMapFace) override;
    protected: GEBool RenderShadowScene() override;
    public: GEBool OnPostExtraction() override;
    public: bCMatrix const & GetShadowMapMatrix() const override;
    public: void SetLightDirection(bCVector const &) override;
    public: void AddShadowReciver(eCEntity *) override;
    public: void RemoveShadowReciver(eCEntity *) override;
    // clang-format on

  public:
    eCShadowMapDirectionalLight(eCShadowMapDirectionalLight const &);
    eCShadowMapDirectionalLight();

  public:
    eCShadowMapDirectionalLight &operator=(eCShadowMapDirectionalLight const &);

  public:
    GEBool AddOcclusionTestItem(eCEntity *);
    eCShadowMapDirectionalLight *GetFallBack() const;
    bCBox const &GetLightPlaneBox() const;
    bCMatrix const &GetLightPlaneMatrix() const;
    GEBool GetSaveOnePixelBorder() const;
    bCBox const &GetShadowedArea() const;
    GEBool GetSupportOcclusionCulling() const;
    GEFloat GetTexelsPerUnit() const;
    GEBool IsShadowCaster(bCBox const &) const;
    GEBool RemoveOcclusionTestItem(eCEntity *);
    GEBool RenderOcclusionTests();
    void SetFallBack(eCShadowMapDirectionalLight *);
    void SetLightPlaneBox(bCBox const &);
    void SetSaveOnePixelBorder(GEBool);
    void SetShadowedArea(bCBox const &);
    void SetSupportOcclusionCulling(GEBool);
    GEBool Update();

  protected:
    void Invalidate();
    void UpdateInternals();
};
