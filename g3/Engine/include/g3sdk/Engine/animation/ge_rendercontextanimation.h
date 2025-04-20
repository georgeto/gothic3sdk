#pragma once

#include <Engine/animation/ge_rendercontext.h>

class eCVisualAnimation_PS;

class GE_DLLIMPORT eCRenderContextAnimation : public eCRenderContext
{
    // clang-format off
    public: void Destroy() override;
    protected: bEResult Create() override;
    public: ~eCRenderContextAnimation() override;
    public: GEBool IsDynamicOCEnabled() const override;
    public: GEBool SupportsOccluderZPass() const override;
    public: GEBool IsPrefetching() const override;
    public: eCResourceShaderMaterial_PS * GetMaterial(GEU32) const override;
    public: void UpdateLoD(eSEntityLoDInfoDesc const *) override;
    public: void FillSolidRenderOps(eCFrustumDatabase const &, GEFloat, bTValArray<eCRenderOp2> &, bTValArray<eCRenderOp2> &) override;
    public: void FillAlphaRenderOps(eCFrustumDatabase const &, GEFloat, bTValArray<eCRenderOp2> &, bTValArray<eCRenderOp2> &) override;
    public: GEBool RenderZPass(GEBool) override;
    public: GEBool Render(eCRenderOp2 const &) override;
    protected: GEBool Prefetch() override;
    // clang-format on

  public:
    eCRenderContextAnimation(eCRenderContextAnimation const &);
    eCRenderContextAnimation();

  public:
    eCRenderContextAnimation &operator=(eCRenderContextAnimation const &);

  protected:
    void Invalidate();

  public:
    GEBool m_bIsPrefetching;
    eCVisualAnimation_PS *m_VisualAnimationPS;
};

GE_ASSERT_SIZEOF(eCRenderContextAnimation, 0x24)
