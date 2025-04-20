#pragma once

#include <Engine/animation/ge_rendercontext.h>

class GE_DLLIMPORT eCRenderContextLegacy : public eCRenderContext
{
    // clang-format off
    public: void Destroy() override;
    public: ~eCRenderContextLegacy() override;
    public: GEBool IsDynamicOCEnabled() const override;
    public: GEBool IsPrefetching() const override;
    public: eCResourceShaderMaterial_PS * GetMaterial(GEU32) const override;
    public: void UpdateLoD(eSEntityLoDInfoDesc const *) override;
    public: void FillSolidRenderOps(eCFrustumDatabase const &, GEFloat, bTValArray<eCRenderOp2> &, bTValArray<eCRenderOp2> &) override;
    public: void FillAlphaRenderOps(eCFrustumDatabase const &, GEFloat, bTValArray<eCRenderOp2> &, bTValArray<eCRenderOp2> &) override;
    public: void FillRefractedRenderOps(eCFrustumDatabase const &, GEFloat, bTValArray<eCRenderOp2> &) override;
    public: GEBool RenderZPass(GEBool) override;
    public: GEBool Render(eCRenderOp2 const &) override;
    public: GEBool Prefetch() override;
    // clang-format on

  public:
    eCRenderContextLegacy(eCRenderContextLegacy const &);
    eCRenderContextLegacy();

  public:
    eCRenderContextLegacy &operator=(eCRenderContextLegacy const &);

  public:
    bEResult Create(eCEntity *, eCEntityPropertySet *, GEBool);

  protected:
    void Invalidate();
};
