#pragma once

#include <Engine/ge_basecache.h>
#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class eCAnimationCache;
class eCCollisionMeshCache;
class eCImageCache;
class eCMaterialCache;
class eCMeshCache;
class eCResourceDataEntity;
class eCSoundCache;
class eCSpeedTreeCache;

class GE_DLLIMPORT eCMainCache : public bCObjectRefBase
{
    // clang-format off
    public: virtual void UpdateResourceInfo(eCResourceDataEntity const &, eCBaseCache::eEUpdateCacheInfoOperation);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCMainCache() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCMainCache, bCObjectRefBase)
    GE_PROPERTY(GEBool, DisableThreading, m_bDisableThreading)
    GE_PADDING(1)

  public:
    eCAnimationCache &AccessAnimationCache();
    eCCollisionMeshCache &AccessCollisionMeshCache();
    eCImageCache &AccessImageCache();
    eCMaterialCache &AccessMaterialCache();
    eCMeshCache &AccessMeshCache();
    eCSoundCache &AccessSoundCache();
    eCSpeedTreeCache &AccessSpeedTreeCache();
    GEBool CacheInResource(eCResourceDataEntity &);
    GEBool CacheOutResource(eCResourceDataEntity &, eEResourceCacheBehavior);
    GEBool ConvertResource(eCResourceDataEntity &);
    void GetCacheSizes(GEU32 &, GEU32 &, GEU32 &, GEU32 &, GEU32 &, GEU32 &, GEU32 &);
    void Process();
    void PurgeCaches(GEBool);
    void PurgeImageCache(GEBool);
    GEBool ReleaseMemory(GEU32, eCResourceBase_PS::eECacheType);
    GEU32 RequestMemory(GEU32, eCResourceBase_PS::eECacheType);
    GEBool SaveResource(eCResourceDataEntity &);
    void SetCacheSizes(GEU32, GEU32, GEU32, GEU32, GEU32, GEU32, GEU32);
    void WaitForEmptyThreadQues();

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(76)
};

GE_ASSERT_SIZEOF(eCMainCache, 0x5c)

GE_ASSERT_PROPERTY(eCMainCache, m_bDisableThreading, 0xc, 1)
