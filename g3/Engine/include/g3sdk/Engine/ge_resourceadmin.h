#pragma once

#include <Engine/ge_basecache.h>
#include <Engine/ge_enginecomponentbase.h>
#include <Engine/ge_maincache.h>
#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class eCResourceDataEntity;
class eCResourceStorageContext;

struct eSResourceStatistics
{
    GEUInt AlwaysZero;
    GEUInt PressureThresholdMabye;
    GEUInt Image_CurrentCacheSize;
    GEUInt Image_CacheSize;
    GEUInt Image_NumOfJobsInQueue;
    GEUInt Material_CurrentCacheSize;
    GEUInt Material_CacheSize;
    GEUInt Material_NumOfJobsInQueue;
    GEUInt Mesh_CurrentCacheSize;
    GEUInt Mesh_CacheSize;
    GEUInt Mesh_NumOfJobsInQueue;
    GEUInt Sound_CurrentCacheSize;
    GEUInt Sound_CacheSize;
    GEUInt Sound_NumOfJobsInQueue;
    GEUInt CollisionMesh_CurrentCacheSize;
    GEUInt CollisionMesh_CacheSize;
    GEUInt CollisionMesh_NumOfJobsInQueue;
    GEUInt Animation_NumOfJobsInQueue;
    GEUInt SpeedTree_NumOfJobsInQueue;
    GEUInt Image_NumEntries;
    GEUInt Mesh_NumEntries;
    GEUInt CollisionMesh_NumEntries;
    GEUInt Material_NumEntries;
    GEUInt Sound_NumEntries;
    GEUInt Animation_CacheSize;
    GEUInt Animation_NumEntries;
    GEUInt Animation_CurrentCacheSize;
    GEUInt SpeedTree_NumEntries;
    GEUInt SpeedTree_CurrentCacheSize;
    GEUInt SpeedTree_CacheSize;
};
GE_ASSERT_SIZEOF(eSResourceStatistics, 0x78)

class GE_DLLIMPORT eCResourceAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceAdmin() override;
    public: bCGuid const & GetID() const override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCResourceAdmin, eCEngineComponentBase)
    GE_OBJECTPROP(eCMainCache, bCObjectRefBase, MainCache, m_MainCache)

  public:
    static eCBaseCache::eELoDQualityStage GE_STDCALL GetEnumLoDQualityValue(bCString const &);

  public:
    eCMainCache &GetMainCache();
    eSResourceStatistics const &GetResourceStatistics();
    eCResourceStorageContext &GetStorageContext();
    eCResourceStorageContext const &GetStorageContext() const;
    GEBool IsEditorModeEnabled() const;
    eCResourceDataEntity *QueryNewResourceDataEntity();
    eCResourceDataEntity *QueryResourceDataEntity(bCString const &, eEResourceCacheBehavior);

  protected:
    void EnableEditorMode(GEBool);
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(156)
};

GE_ASSERT_SIZEOF(eCResourceAdmin, 0xc0)

GE_ASSERT_PROPERTY(eCResourceAdmin, m_MainCache, 0x14, 16)
