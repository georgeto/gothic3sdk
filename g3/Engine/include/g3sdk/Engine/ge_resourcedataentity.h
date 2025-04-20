#pragma once

#include <Engine/ge_node.h>
#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

struct eSResourceEntry;

class GE_DLLIMPORT eCResourceDataEntity : public eCNode
{
    // clang-format off
    public: virtual GEBool AddPropertySet(eCResourceBase_PS *);
    public: GEU16 GetVersion() const override;
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: GEU32 AddReference() override;
    public: GEU32 ReleaseReference() override;
    protected: ~eCResourceDataEntity() override;
    public: eCResourceDataEntity * DoClone() const override;
    // clang-format on

  public:
    explicit operator eCResourceBase_PS *();
    explicit operator eCResourceBase_PS const *() const;
    eCResourceDataEntity const &operator=(eCResourceDataEntity const &);

  public:
    bEResult Convert(eEResourceCacheBehavior);
    GEBool CreateResourceFromFile(bCString const &);
    GEBool CreateResourceFromType(bCString const &);
    GEU32 GetCacheTimeStamp() const;
    GEU32 GetCurrentResourceSize() const;
    bCString GetFileName() const;
    bCString GetFilePath() const;
    bCObjectRefBase *GetRenderBufferHook() const;
    GEBool IsLocked() const;
    bEResult Load(eEResourceCacheBehavior);
    GEU16 Lock();
    bEResult Reload(eEResourceCacheBehavior);
    bEResult Save(bCString const &, eEResourceCacheBehavior);
    eCResourceBase_PS *SearchResourcePropertySet() const;
    void SetCacheTimeStamp(GEU32);
    void SetRenderBufferHook(bCObjectRefBase *);
    bEResult Unload(eEResourceCacheBehavior);
    GEU16 Unlock();

  protected:
    eCResourceDataEntity(eCResourceDataEntity const &);
    eCResourceDataEntity();

  protected:
    void Invalidate();

  public:
    GEU16 m_LockCount;
    GE_PADDING(2)
    eSResourceEntry *pCacheEntry;
    GEU16 field_38;
    GE_PADDING(2)
    GEUInt field_3C;
    GEUInt field_40;
    bCObjectRefBase *RenderBufferHook;
    eCResourceBase_PS *m_pResource;
    GEUInt LastUpdateTimeStamp;
};

GE_ASSERT_SIZEOF(eCResourceDataEntity, 0x50)
