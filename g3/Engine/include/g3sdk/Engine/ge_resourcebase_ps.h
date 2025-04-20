#pragma once

#include <Engine/entity/proxy/ge_templateentityproxy.h>
#include <Engine/io/file/ge_archivefile.h>

#include <SharedBase.h>

class eCCollisionDesc;
class eCResourceDataEntity;
struct eSRayIntersectionDesc;

enum eEResourceCacheBehavior
{
    eEResourceCacheBehavior_Immediate = 1,
    eEResourceCacheBehavior_Lazy = 2,
    eEResourceCacheBehavior_3 = 3
};

class GE_DLLIMPORT eCResourceBase_PS : public bCObjectRefBase
{
  public:
    enum eEResourceState
    {
        eEResourceState_0 = 0x0,
        eEResourceState_1 = 0x1,
        eEResourceState_CanBeLoaded = 0x2,
        eEResourceState_Loading = 0x3,
        eEResourceState_Unloading = 0x4,
        eEResourceState_Converting = 0x5,
        eEResourceState_Available = 0x6,
        eEResourceState_MaybeFailed_InvalidFileName_OR_Saving = 0x7,
    };

  public:
    enum eECacheType
    {
        // TODO: Enumerator values
    };

    // clang-format off
    public: virtual bCString const & GetProprietaryFileExt() const;
    public: virtual bCString const & GetNativeFileExt() const;
    public: virtual GEU32 GetSize() const;
    public: virtual eECacheType GetCacheType() const;
    public: virtual eCResourceDataEntity * GetEntity();
    public: virtual eCResourceDataEntity const * GetEntity() const;
    protected: virtual void SetResourceFilePath(bCString const &);
    public: virtual bEResult DoLoad();
    public: virtual bEResult DoUnload();
    public: virtual bEResult DoReload();
    public: virtual bEResult DoConvert();
    public: virtual bEResult DoSave();
    public: virtual GEBool IsDataAvailable() const;
    public: virtual GEBool IsResourceFileAvailable(bCString const &) const;
    protected: virtual void CalculateSize();
    protected: virtual GEBool IsLocked();
    public: virtual void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &);
    protected: virtual eCArchiveFile CreateProprietaryFile(bCString const &);
    public: virtual void GetBoundary(bCBox &, GEBool);
    public: virtual void OnUpdateInternals();
    public: virtual GEBool IntersectsRay(eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc **) const;
    public: virtual GEBool IntersectsVolume(bCVolume &, bCMatrix const &, bTValArray<bCTriangle> *, GEBool) const;
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: GEU32 AddReference() override;
    public: GEU32 ReleaseReference() override;
    public: ~eCResourceBase_PS() override;
    public: GEBool IsVirtualReferencingEnabled() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCResourceBase_PS, bCObjectRefBase)
    GE_PROPERTY(GEFloat, ResourcePriority, m_fResourcePriority)

  public:
    eEResourceCacheBehavior GetCacheBehavior() const;
    eEResourceState GetCurrentResourceState() const;
    bCString GetFileBaseName() const;
    bCDateTime GetFileTime() const;
    bCString const &GetNFOFileExt() const;
    bCString GetNFOFileName() const;
    bCString GetNativeFileName() const;
    bCString GetProprietaryFileName() const;
    GEBool IsInvalid() const;
    GEBool IsProcessing() const;
    void WaitUntilNonProcessing(GEInt);

  protected:
    void Invalidate();

  private:
    bEResult Convert(eEResourceCacheBehavior);
    bEResult Load(eEResourceCacheBehavior);
    bEResult Reload(eEResourceCacheBehavior);
    bEResult Save(eEResourceCacheBehavior);
    void SetFileBaseName(bCString const &);
    bEResult Unload(eEResourceCacheBehavior);

  public:
    GEInt m_CurrentResourceState;
    GEBool __UNK_0014;
    GE_PADDING(3)
    eEResourceCacheBehavior m_enuCacheBehavior;
    GEUInt m_uSize;
    GEU32 m_Bitfield_1_Invalid;
    eCResourceDataEntity *m_pEntity;
    bCString m_strFileBaseName;
};

GE_ASSERT_SIZEOF(eCResourceBase_PS, 0x2c)

GE_ASSERT_PROPERTY(eCResourceBase_PS, m_fResourcePriority, 0xc, 4)
