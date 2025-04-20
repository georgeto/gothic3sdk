#pragma once

#include <Engine/ge_shadowmapdirectionallightbase.h>

#include <SharedBase.h>

class eCFrustumFilter;

class GE_DLLIMPORT eCShadowMapDirectionalLightLsPSM : public eCShadowMapDirectionalLightBase
{
    // clang-format off
    public: virtual bEResult Create(GEInt, eEDepthMapFormat);
    public: GEU16 GetVersion() const override;
    public: void Destroy() override;
    public: ~eCShadowMapDirectionalLightLsPSM() override;
    public: GEFloat GetLightRange() const override;
    public: GEBool IsShadowCusterCullingEnabled() const override;
    protected: GEBool UpdateCamera(eCGfxShared::eECubeMapFace) override;
    protected: GEBool RenderShadowScene() override;
    public: GEBool OnPostExtraction() override;
    public: bCMatrix const & GetShadowMapMatrix() const override;
    // clang-format on

  public:
    eCShadowMapDirectionalLightLsPSM(eCShadowMapDirectionalLightLsPSM const &);
    eCShadowMapDirectionalLightLsPSM();

  public:
    eCShadowMapDirectionalLightLsPSM &operator=(eCShadowMapDirectionalLightLsPSM const &);

  public:
    bCVector2 GetShadowFadeOut() const;
    GEBool Update();

  protected:
    static GEFloat ms_fDetailShadowRadius;

  protected:
    static GEBool GE_STDCALL CullEntityCallback(eCFrustumFilter *, eCEntity *);

  protected:
    void CalculateFocusedShadowPoints(bCMatrix const &, bCBox const &, bTValArray<bCVector> &);
    void Invalidate();
    GEBool UpdateShadowMatrix();
};
