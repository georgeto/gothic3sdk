#pragma once

#include <Engine/ge_frustumfilter.h>

#include <SharedBase.h>

class eCEntity;
class eCEntityPropertySet;
class eCFrustumDatabase;
class eCIlluminated_PS;
class eCRenderContext;
struct eSEntityFlags;
struct eSEntityLoDInfoDesc;

struct eSDatabaseSet
{
    GE_UNIMPL_STRUCT(eSDatabaseSet)
};

class GE_DLLIMPORT eCFrustumElementItem
{
  public:
    eCFrustumElementItem();
    ~eCFrustumElementItem();

  public:
    eCFrustumElementItem const &operator=(eCFrustumElementItem const &);

  public:
    void CacheIn();
    void CacheOut();
    void CalculateLoDArea(eCFrustumDatabase &);
    GEBool CheckIfOccluder() const;
    void CopyFrom(eCFrustumElementItem const &);
    GEBool CouldByOccluder() const;
    GEFloat CullSmallObject(eCFrustumDatabase &, GEBool);
    eCFrustumFilter::eECullStatus CullTreeHC(eCFrustumDatabase &);
    GEBool CullVPTHC(eCFrustumDatabase &);
    void Destroy();
    void EndOCTest();
    GEU32 GetCurrentTimeStamp() const;
    eSDatabaseSet &GetDatabaseSet();
    GEFloat GetDistanceToCamera() const;
    GELPVoid GetDynamicQuery() const;
    GEU32 GetDynamicQueryResult() const;
    eCEntity *GetEntity();
    GEFloat GetFadeOutValue() const;
    eCIlluminated_PS *GetIlluminationPS() const;
    eSEntityLoDInfoDesc &GetLoDInfoDesc();
    eSEntityLoDInfoDesc const &GetLoDInfoDesc() const;
    eCRenderContext const *GetRenderContextAt(GEInt) const;
    GEInt GetRenderContextCount() const;
    GEU8 GetVPTEdge() const;
    GEBool HasRenderContexts() const;
    GEBool HasVisual() const;
    GEBool IsDynamic() const;
    GEBool IsDynamicOcclusionCullingEnabled() const;
    void RenderZPass();
    GEBool Request(eCFrustumDatabase &, GEU8, bCVector4 const &);
    void ResetDynamicQuery();
    void ResolveDynamicQuery();
    void SetEntity(eCEntity *);
    void SetIlluminationPS(eCIlluminated_PS *);
    GEBool StartOCTest();
    void UpdateNodeData(eCFrustumDatabase &, eSEntityFlags const &);
    void UpdateTimeStamp(GEU32);
    GEBool WasVisibleLastFrame(eCFrustumDatabase &) const;

  protected:
    eCFrustumElementItem(eCFrustumElementItem const &);

  protected:
    GEBool Create();
    void Invalidate();
    eCRenderContext *QueryLegacyRenderContext(eCEntityPropertySet *);

  private:
    GE_UNIMPL_MEMBERS(0x40)
};

GE_ASSERT_SIZEOF(eCFrustumElementItem, 0x40)
