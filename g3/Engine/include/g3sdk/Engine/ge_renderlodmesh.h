#pragma once

#include <Engine/ge_rendercontextmesh.h>

#include <SharedBase.h>

class eCVisualMeshBase_PS;

class GE_DLLIMPORT eCRenderLoDMesh
{
  public:
    eCRenderLoDMesh();

  public:
    eCRenderLoDMesh &operator=(eCRenderLoDMesh const &);

  public:
    GEU8 GetLoDCount() const;
    GEBool Prefetch(eCVisualMeshBase_PS &);
    GEBool Release(eCVisualMeshBase_PS &);
    void SetBufferList(bTObjArray<eCRenderContextMesh::eSVertexbufferPoolMainDesc> &);
};
