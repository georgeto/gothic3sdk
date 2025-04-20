#pragma once

#include <Engine/ge_enginecomponentbase.h>
#include <Engine/ge_frustumdatabase.h>

#include <SharedBase.h>

class eCEntity;
class eCOcclusionProcessor;
class eCPVSPrefetcher3;
class eCShadowMapBase;
class eCVertexbufferPool;

struct eSRenderStatistics
{
    GE_UNIMPL_STRUCT(eSRenderStatistics)
};

class GE_DLLIMPORT eCRenderSystemAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: GEU32 const GetProfileLastTicksFirst() const override;
    public: GEU32 const GetProfileLastTicksSecond() const override;
    public: GEU32 const GetProfileLastTicksThird() const override;
    public: ~eCRenderSystemAdmin() override;
    public: bCGuid const & GetID() const override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult ResetResources(GEBool) override;
    public: bEResult RestoreResources(GEBool) override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCRenderSystemAdmin, eCEngineComponentBase)

  public:
    void DrawBatchLineList(bTSmallArray<bCVector> const &, GEU32, GEBool, GEBool);
    void DrawBatchLineList(bCVector const &, bCVector const &, GEU32, GEBool, GEBool);
    void DrawBatchTLLineList(bTSmallArray<bCVector4> const &, GEU32, GEBool, GEBool);
    void DrawBatchTLLineList(bCVector4 const &, bCVector4 const &, GEU32, GEBool, GEBool);
    void EnablePrefetchEntityCallback(GEBool);
    void ExecuteBatchedLineList();
    GEBool FlushThreadQueues();
    GEBool GetDontResetRenderers() const;
    eCFrustumDatabase::eSCaps &GetFrustumDatabaseCapsTemplate();
    eCOcclusionProcessor &GetOcclusionProcessor();
    eCPVSPrefetcher3 &GetPVSPrefetcher3();
    GEBool(GE_STDCALL *GetPrefetchEntityCallback() const)(GEInt, GEInt);
    eSRenderStatistics &GetRenderStatistics();
    eSRenderStatistics const &GetRenderStatistics() const;
    GEU32 GetTimeStamp();
    eCVertexbufferPool &GetVertexBufferPool();
    void GE_STDCALL OnToggleBoundingBoxes(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnToggleOcclusionCulling(bCObjectRefBase *, bCEvent *);
    GEBool RegisterDatabase(eCFrustumDatabase &);
    void Render(eCFrustumDatabase &);
    void RenderEntity(eCFrustumDatabase &, eCEntity *);
    void RenderShadowMap(eCFrustumDatabase &, eCShadowMapBase *, eCFrustumDatabase *);
    bEResult ResetRenderers();
    void SetDontResetRenderers(GEBool);
    void SetPrefetchEntityCallback(GEBool(GE_STDCALL *)(GEInt, GEInt));
    GEBool UnregisterDatabase(eCFrustumDatabase &);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(624)
};

GE_ASSERT_SIZEOF(eCRenderSystemAdmin, 0x284)
