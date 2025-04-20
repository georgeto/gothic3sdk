#pragma once

#include <SharedBase.h>

class eCEntity;
class eCFrustumDatabase;
class eCFrustumElementItem;
class eCShaderDefault;
class eCSpatialEntity;

class GE_DLLIMPORT eCOcclusionProcessor : public bCObjectRefBase
{
    // clang-format off
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCOcclusionProcessor() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCOcclusionProcessor, bCObjectRefBase)

  public:
    void BeginOcclusionMaterial(GEBool, GEBool);
    void CreateOccludeeGfxResources();
    void DestroyOccludeeGfxResources();
    bEResult EndOCQuery(GELPVoid);
    void EndOcclusionMaterial();
    void FreeOCQuery(GELPVoid);
    GEFloat GetOccluderObjectSizeThreshold();
    eCShaderDefault *GetShader();
    GEBool Process(eCFrustumDatabase &);
    void RenderDynamicOccludees(bTPtrArray<eCFrustumElementItem *> &);
    void RenderOccludee(eCEntity *);
    void RenderOccludees(eCSpatialEntity **, GEInt);
    void RenderShadowMapOccludees(bTValArray<eCEntity *> const &);
    GEU32 ResolveOCQuery(GELPVoid, GEBool);
    void SetOccluderObjectSizeThreshold(GEFloat);
    GELPVoid StartOCQuery();

  protected:
    void ClearOcclusionList();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(92)
};

GE_ASSERT_SIZEOF(eCOcclusionProcessor, 0x68)
