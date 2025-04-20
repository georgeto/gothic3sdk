#pragma once

#include <SharedBase.h>

class eCGfxImageData;
class eCSpeedTree_PS;

class GE_DLLIMPORT eCTerrainShadowMap
{
  public:
    eCTerrainShadowMap(eCTerrainShadowMap const &);
    eCTerrainShadowMap();
    ~eCTerrainShadowMap();

  public:
    eCTerrainShadowMap &operator=(eCTerrainShadowMap const &);

  public:
    void AddTreeShadow(eCSpeedTree_PS *);
    bEResult Create(GEInt);
    GEBool CreateRenderTarget(GEBool);
    void Destroy();
    GEBool DestroyRenderTarget();
    eCGfxImageData *GetImage() const;
    GEInt GetSize() const;
    GEBool IsEmtpty() const;
    void RemoveTreeShadow(eCSpeedTree_PS *);
    void SetSize(GEInt);
    GEBool Update();

  protected:
    void Invalidate();
};
