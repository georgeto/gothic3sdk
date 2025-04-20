#pragma once

#include <Engine.h>

class GE_DLLIMPORT iCTextureBaker
{
  public:
    struct iSBakeTexture
    {
        GE_UNIMPL_STRUCT(iSBakeTexture)
    };

    // clang-format off
    public: virtual ~iCTextureBaker();
    // clang-format on

  public:
    iCTextureBaker(iCTextureBaker const &);
    iCTextureBaker();

  public:
    iCTextureBaker &operator=(iCTextureBaker const &);

  public:
    GEBool Process();

  protected:
    static GEDouble (*ms_arrSamples)[2];
    static GEInt ms_iPixelBatchCount;
    static GEInt ms_iSampleCount;
    static eCGfxVertexDecl *ms_pVertexDecl;

  protected:
    void CollectBakeTextures(eCEntity *);
    void CollectBakeTextures(eCResourceMeshComplex_PS *, bCMatrix const &);
    GEBool CollectBakeTextures(eCMeshElement *, bCMatrix const &);
    bEResult Create();
    void Destroy();
    void FillTextureEdges();
    void FindBestHighPolyFace(eCEntity *);
    GEBool FindBestHighPolyFace(bCVector const &, bCVector const &);
    void Invalidate();
    GEBool ProcessBakeTexture(iSBakeTexture const &);
    GEBool RenderBakeTexture(iSBakeTexture const &);
};
