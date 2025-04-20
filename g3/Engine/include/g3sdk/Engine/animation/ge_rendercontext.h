#pragma once

#include <Engine/ge_renderop2.h>

#include <SharedBase.h>

class eCEntity;
class eCEntityPropertySet;
class eCFrustumDatabase;
class eCResourceShaderMaterial_PS;

struct eSEntityLoDInfoDesc
{
    GE_UNIMPL_STRUCT(eSEntityLoDInfoDesc)
};

class GE_DLLIMPORT eCRenderContext : public bCObjectRefBase
{
    // clang-format off
    public: virtual GEBool SupportsZPass() const;
    public: virtual GEBool IsDynamicOCEnabled() const;
    public: virtual GEBool SupportsOccluderZPass() const;
    public: virtual GEBool IsPrefetching() const = 0;
    public: virtual eCResourceShaderMaterial_PS * GetMaterial(GEU32) const = 0;
    public: virtual void UpdateDepthSortValue(bCVector4 const &);
    public: virtual void UpdateLoD(eSEntityLoDInfoDesc const *) = 0;
    public: virtual void FillSolidRenderOps(eCFrustumDatabase const &, GEFloat, bTValArray<eCRenderOp2> &, bTValArray<eCRenderOp2> &) = 0;
    public: virtual void FillAlphaRenderOps(eCFrustumDatabase const &, GEFloat, bTValArray<eCRenderOp2> &, bTValArray<eCRenderOp2> &) = 0;
    public: virtual void FillRefractedRenderOps(eCFrustumDatabase const &, GEFloat, bTValArray<eCRenderOp2> &);
    public: virtual GEBool RenderZPass(GEBool) = 0;
    public: virtual GEBool Render(eCRenderOp2 const &) = 0;
    public: virtual GEBool RenderRefrationMask(eCRenderOp2 const &);
    protected: virtual GEBool Prefetch() = 0;
    public: void Destroy() override;
    protected: bEResult Create() override;
    public: ~eCRenderContext() override;
    // clang-format on

  public:
    eCRenderContext(eCRenderContext const &);
    eCRenderContext();

  public:
    eCRenderContext &operator=(eCRenderContext const &);

  public:
    bEResult Create(eCEntity *, eCEntityPropertySet *);
    GEFloat GetDepthSortValue() const;
    eCEntity *GetEntity();

  protected:
    void Invalidate();

  public:
    eCEntity *m_pEntity;
    eCEntityPropertySet *m_pEntityPropertySet;
    GEU32 m_BitField;
    GEFloat m_fDepthSortValue;
};

GE_ASSERT_SIZEOF(eCRenderContext, 0x1c)
