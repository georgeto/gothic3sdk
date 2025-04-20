#pragma once

#include <Engine/animation/ge_rendercontext.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCRenderContextMesh : public eCRenderContext
{
  public:
    struct eSVertexbufferPoolMainDesc
    {
        GE_UNIMPL_STRUCT(eSVertexbufferPoolMainDesc)
    };

    // clang-format off
    public: void Destroy() override;
    protected: bEResult Create() override;
    public: ~eCRenderContextMesh() override;
    public: GEBool IsDynamicOCEnabled() const override;
    public: GEBool IsPrefetching() const override;
    public: eCResourceShaderMaterial_PS * GetMaterial(GEU32) const override;
    public: void UpdateDepthSortValue(bCVector4 const &) override;
    public: void UpdateLoD(eSEntityLoDInfoDesc const *) override;
    public: void FillSolidRenderOps(eCFrustumDatabase const &, GEFloat, bTValArray<eCRenderOp2> &, bTValArray<eCRenderOp2> &) override;
    public: void FillAlphaRenderOps(eCFrustumDatabase const &, GEFloat, bTValArray<eCRenderOp2> &, bTValArray<eCRenderOp2> &) override;
    public: void FillRefractedRenderOps(eCFrustumDatabase const &, GEFloat, bTValArray<eCRenderOp2> &) override;
    public: GEBool RenderZPass(GEBool) override;
    public: GEBool Render(eCRenderOp2 const &) override;
    public: GEBool RenderRefrationMask(eCRenderOp2 const &) override;
    protected: GEBool Prefetch() override;
    // clang-format on

  public:
    eCRenderContextMesh(eCRenderContextMesh const &);
    eCRenderContextMesh();

  public:
    eCRenderContextMesh &operator=(eCRenderContextMesh const &);

  public:
    void Invalidate();
    void SetMaterialSwitch(GEInt);

  protected:
    GEU8 CalculateLoDStage(eSEntityLoDInfoDesc const *) const;
};
