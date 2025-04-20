#pragma once

#include <Engine/ge_frustumfilter.h>
#include <Engine/ge_renderop2.h>

#include <SharedBase.h>

class eCCameraBase;
class eCContextBase;
class eCDynamicEntity;
class eCEntity;
class eCGfxFog;
class eCRenderContext;
class eCShadowMapBase;

class GE_DLLIMPORT eCFrustumDatabase : public bCObjectBase
{
  public:
    struct eSTraverselNode
    {
        GE_UNIMPL_STRUCT(eSTraverselNode)
    };

    struct eSZSortElement
    {
        GE_UNIMPL_STRUCT(eSZSortElement)
    };

    template <typename T>
    class eTBinaryHeap
    {
        GE_UNIMPL_STRUCT(eTBinaryHeap)
    };

    struct eSCaps
    {
        GE_UNIMPL_STRUCT(eSCaps)
    };

    struct eSNodeQuery
    {
        GE_UNIMPL_STRUCT(eSNodeQuery)
    };

    // clang-format off
    public: void Destroy() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCFrustumDatabase() override;
    // clang-format on

  public:
    eCFrustumDatabase(eCFrustumDatabase const &);
    eCFrustumDatabase();
    explicit eCFrustumDatabase(GEBool);

  public:
    eCFrustumDatabase const &operator=(eCFrustumDatabase const &);

  public:
    void AddFilterContextCallback(GEBool(GE_STDCALL *)(eCCameraBase *, eCContextBase *));
    void AddFilterEntityCullCallback(GEBool(GE_STDCALL *)(eCFrustumFilter *, eCEntity *));
    void AddFreezedContexts(bTSmallArray<eCContextBase *> const &);
    void AddMarkedContexts(bTSmallArray<eCContextBase *> const &);
    void ClearFreezedContexts();
    void ClearMarkedContexts();
    void ClearRectActiveCells();
    bEResult Create(GEBool);
    eCFrustumFilter::eECullStatus CullPoint(bCVector const &);
    void DrawBox(bCBox const &, bCMatrix const &);
    void Execute();
    void ExecuteShadowMap(eCShadowMapBase *);
    void ExtractFromEntities(eCEntity *, eCFrustumFilter::eECullStatus);
    void ExtractFromFrustum();
    void ExtractFromFrustumOC();
    void ExtractFromShadowMap(eCShadowMapBase *, eCFrustumDatabase *);
    GEBool FilterContextCallback(eCContextBase *);
    GEBool FilterEntityCullCallback(eCFrustumFilter *, eCEntity *);
    void ForcePrefetch();
    bCRect const &GetActiveCellRange() const;
    eCRenderOp2 const &GetAlphaElement(GEInt) const;
    GEInt GetAlphaElementCount() const;
    eCCameraBase *GetCamera() const;
    eSCaps &GetCaps();
    eSCaps const &GetCaps() const;
    GEU32 GetCurrentTimeStamp() const;
    bTValArray<eCRenderOp2> const &GetDebugOutputObjects() const;
    void GetDynamicEntities(bTPtrArray<eCDynamicEntity *> &);
    eCGfxFog *GetFog();
    GEU32 GetFrustumDatabaseIndex() const;
    eCFrustumFilter &GetFrustumFilter();
    eCRenderOp2 const &GetSolidElement(GEInt) const;
    GEInt GetSolidElementCount() const;
    GEBool IsCameraValid() const;
    GEBool IsInFreezedContext(eCEntity const &) const;
    GEBool IsInMarkedContext(eCEntity const &) const;
    GEBool MustBePrefetched() const;
    void RefreshFrustumData();
    GEBool RemoveFilterContextCallback(GEBool(GE_STDCALL *)(eCCameraBase *, eCContextBase *));
    GEBool RemoveFilterEntityCullCallback(GEBool(GE_STDCALL *)(eCFrustumFilter *, eCEntity *));
    void SetCamera(eCCameraBase *);
    void Update();
    void UpdateFromAppTemplate();

  protected:
    static GEInt GE_CCALL s_funcSortZElement(GELPCVoid, GELPCVoid);

  protected:
    void AddShadowCasterEntity(eCEntity &);
    void ExecuteRenderList(bTValArray<eCRenderOp2> const &, GEBool);
    void ExecuteZPassList(bTValArray<eCRenderContext *> const &);
    GEBool ExtractFromEntity(eCEntity *, eCFrustumFilter::eECullStatus);
    GEU32 GetQueryResult(eSNodeQuery &) const;
    void Invalidate();
    GEBool IsQueryResultAvailable(eSNodeQuery &) const;
    void PullUpVisiblity(eSTraverselNode &) const;
    GEBool RenderNode(eSTraverselNode &);
    void SortInverseZ(bTValArray<eCRenderOp2> &);
    void SortMaterial(bTValArray<eCRenderOp2> &);
    void SortZ(bTValArray<eCRenderOp2> &);
    void SortZElements(bTValArray<eSZSortElement> &);
    void SortZPass(bTValArray<eCRenderContext *> &);
    GEBool TraverseNode(eSTraverselNode &, eTBinaryHeap<eSTraverselNode> &);
};
