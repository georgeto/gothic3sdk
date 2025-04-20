#pragma once

#include <SharedBase.h>

class eCEntity;
class eCResourceDataEntity;
class eCResourceImage_PS;
class eCResourceShaderMaterial_PS;

class GE_DLLIMPORT eCDecal
{
  public:
    struct eSDecalVertex
    {
        GE_UNIMPL_STRUCT(eSDecalVertex)
    };

  public:
    eCDecal(eCDecal const &);
    ~eCDecal();

  public:
    eCDecal &operator=(eCDecal const &);

  public:
    GEBool Create(bCMatrix const &, eCEntity *);
    GEBool Create(bCVector const &, bCVector const &, bCVector const &, bCVector const &, eCEntity *);
    GEFloat GetAlpha() const;
    bTValArray<GEU16> const &GetIndices() const;
    eCResourceShaderMaterial_PS *GetMaterial() const;
    eCResourceDataEntity *GetMaterialOrTexture() const;
    eCEntity *GetOwner() const;
    eCResourceImage_PS *GetTexture() const;
    bTValArray<eSDecalVertex> const &GetVertices() const;
    GEBool IsDynamic() const;
    void SetAlpha(GEFloat);
    void SetMaterial(eCResourceShaderMaterial_PS *);
    void SetMaterialOrTexture(eCResourceDataEntity *);
    void SetTexture(eCResourceImage_PS *);

  protected:
    eCDecal();

  protected:
    GEBool AddPolygon(GEU32, bCVector const *, bCVector const *, bCVector const *);
    void ClipMesh(bCFrustum const &, GEU32 const *, GEU32, bCVector const *, bCVector const *, bCVector const *);
    GEU32 ClipPolygon(bCFrustum const &, GEU32, bCVector const *, bCVector const *, bCVector const *, bCVector *,
                      bCVector *, bCVector *);
    GEU32 ClipPolygonAgainstPlane(bCPlane const &, GEU32, bCVector const *, bCVector const *, bCVector const *,
                                  bCVector *, bCVector *, bCVector *);
    GEBool Create(bCFrustum const &, eCEntity *);
    void Destroy();
    void Invalidate();
};
