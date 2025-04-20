#pragma once

#include <SharedBase.h>

class eCEntity;
class eCFrustumDatabase;
class eCRenderContext;
class eCResourceShaderMaterial_PS;

class GE_DLLIMPORT eCRenderOp2
{
  public:
    eCRenderOp2();
    ~eCRenderOp2();

  public:
    eCRenderOp2 &operator=(eCRenderOp2 const &);

  public:
    bEResult Create(eCEntity *, eCResourceShaderMaterial_PS *, eCRenderContext *, GEU32);
    void Destroy();
    eCEntity const *GetEntity() const;
    GEFloat GetFadeOutValue() const;
    eCResourceShaderMaterial_PS *GetMaterial() const;
    eCRenderContext *GetRenderContext() const;
    GEU32 GetRenderContextDesc() const;
    GEBool IsAlreadyRendered() const;
    GEBool IsPrefetching() const;
    GEBool IsRenderedImmediately() const;
    void Render(eCFrustumDatabase const &, GEBool);
    void RenderRefractionMask(eCFrustumDatabase const &);
    void SetFadeOutValue(GEFloat);
    GEBool SupportsZPass() const;

  protected:
    bEResult Create();
    void Invalidate();
};
