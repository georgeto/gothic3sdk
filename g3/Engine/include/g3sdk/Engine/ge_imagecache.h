#pragma once

#include <Engine/ge_basecache.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCImageCache : public eCBaseCache
{
  public:
    struct eSMipMapStageMap1
    {
        GE_UNIMPL_MEMBERS(32)
    };
    GE_ASSERT_SIZEOF(eSMipMapStageMap1, 32)

    struct eSMipMapStageMap2
    {
        GE_UNIMPL_MEMBERS(24)
    };
    GE_ASSERT_SIZEOF(eSMipMapStageMap2, 24)

    // clang-format off
    public: virtual bEResult PostInitialize();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCImageCache() override;
    public: void SetLoDQualityStage(eCBaseCache::eELoDQualityStage) override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCImageCache, eCBaseCache)

  public:
    bCString GetCompilePartFilePath(bCString const &);
    GEBool IsMipmapStageAllowed(bCString const &, GEU32, GEU32, GEInt, GEBool &);

  protected:
    void Invalidate();

  private:
    bTObjArray<eSMipMapStageMap1> m_arrMipMapStageMap1;
    bTObjArray<eSMipMapStageMap2> m_arrMipMapStageMap2;
};

GE_ASSERT_SIZEOF(eCImageCache, 0xc0)
