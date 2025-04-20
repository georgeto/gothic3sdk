#pragma once

#include <Engine/ge_illuminationadmin.h>

#include <SharedBase.h>

class eCEntity;
class eCFrustumDatabase;
class eCVertexbufferPoolItemLightmap;
class eCVertexbufferPoolItemMain;

class GE_DLLIMPORT eCRenderOp
{
  public:
    eCRenderOp();
    ~eCRenderOp();

  public:
    eCRenderOp &operator=(eCRenderOp const &);

  public:
    bEResult Create(eCEntity *, eCVertexbufferPoolItemMain *, eCVertexbufferPoolItemLightmap *);
    bEResult Create();
    void Destroy();
    void Execute(eCFrustumDatabase const &, GEBool);
    void ExecuteZPass(eCFrustumDatabase const &);
    eCEntity const *GetEntity() const;
    eCIlluminationAdmin::eSIllumination *GetIllumination();
    eCVertexbufferPoolItemMain *GetVertexPoolItem();
    eCVertexbufferPoolItemLightmap *GetVertexPoolItemLightmap();
    GEBool IsAlreadyRendered() const;
    GEBool IsProcessing() const;
    void SetFadeOutValue(GEFloat);

  protected:
    void ExecuteMeshPath(eCFrustumDatabase const &, GEBool);
    void ExecuteOther(eCFrustumDatabase const &, GEBool);
    void Invalidate();
};
