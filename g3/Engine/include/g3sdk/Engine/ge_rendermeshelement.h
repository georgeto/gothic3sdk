#pragma once

#include <Engine/ge_rendercontextmesh.h>
#include <Engine/ge_vertexprocessoradditional.h>
#include <Engine/ge_vertexprocessorindex.h>
#include <Engine/ge_vertexprocessormain.h>

#include <SharedBase.h>

class eCLightmap;
class eCMeshElement;

class GE_DLLIMPORT eCRenderMeshElement
{
  public:
    eCRenderMeshElement();
    ~eCRenderMeshElement();

  public:
    eCRenderMeshElement &operator=(eCRenderMeshElement const &);

  public:
    GEBool CreateBuffers(bTSmallArray<eCVertexProcessorMain::eSVertexInfoDesc> const &,
                         bTSmallArray<eCVertexProcessorAdditional::eSVertexInfoDesc> const &,
                         bTValArray<GEU32> const &);
    void FillDescriptor(bTSmallArray<eCVertexProcessorMain::eSVertexInfoDesc> &,
                        bTSmallArray<eCVertexProcessorAdditional::eSVertexInfoDesc> &,
                        bTSmallArray<eCVertexProcessorIndex::eSIndexInfoDesc> &, bTValArray<GEU32> &, GEU32);
    eCMeshElement *GetMeshElement();
    GEBool IsSolid() const;
    GEBool PrefetchBegin(eCMeshElement *, eCLightmap *, GEU8, GEInt);
    GEBool PrefetchEnd();
    GEBool Release(eCMeshElement *, eCLightmap *);
    void SetBufferList(bTObjArray<eCRenderContextMesh::eSVertexbufferPoolMainDesc> &);
};
