#pragma once

#include <Engine/ge_rendercontextmesh.h>

#include <SharedBase.h>

class eCResourceDataEntity;
class eCResourceLightmap_PS;
class eCResourceMeshComplex_PS;
class eCVisualMeshBase_PS;

class GE_DLLIMPORT eCRenderComplexMesh
{
  public:
    eCRenderComplexMesh();

  public:
    eCRenderComplexMesh &operator=(eCRenderComplexMesh const &);

  public:
    GEBool Prefetch(eCVisualMeshBase_PS &);
    GEBool Prefetch(eCResourceDataEntity *, eCResourceLightmap_PS *, GEU8, GEInt);
    GEBool Release(eCVisualMeshBase_PS &);
    GEBool Release(eCResourceDataEntity *, eCResourceLightmap_PS *);
    void SetBufferList(bTObjArray<eCRenderContextMesh::eSVertexbufferPoolMainDesc> &);

  protected:
    GEBool Prefetch(eCResourceMeshComplex_PS &, eCResourceLightmap_PS *, GEInt);
    GEBool Release(eCResourceMeshComplex_PS &, eCResourceLightmap_PS *);
};
