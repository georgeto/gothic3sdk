#pragma once

#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class eCSpeedTreeRenderBuffer;
class eCSpeedTree_PS;
class eCWraper_SpeedTreeRT;

class GE_DLLIMPORT eCResourceSpeedTree_PS : public eCResourceBase_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceSpeedTree_PS() override;
    public: bCString const & GetProprietaryFileExt() const override;
    public: bCString const & GetNativeFileExt() const override;
    public: eCResourceBase_PS::eECacheType GetCacheType() const override;
    public: void SetResourceFilePath(bCString const &) override;
    public: bEResult DoLoad() override;
    public: bEResult DoUnload() override;
    public: bEResult DoReload() override;
    public: bEResult DoConvert() override;
    public: bEResult DoSave() override;
    protected: void CalculateSize() override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnUpdateInternals() override;
    public: GEBool IntersectsRay(eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc **) const override;
    public: GEBool IntersectsVolume(bCVolume &, bCMatrix const &, bTValArray<bCTriangle> *, GEBool) const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCResourceSpeedTree_PS, eCResourceBase_PS)

  public:
    static GEBool GE_STDCALL IsNativeFileType(bCString const &);
    static GEBool GE_STDCALL IsProprietaryFileType(bCString const &);

  public:
    eCWraper_SpeedTreeRT *GetAccessToSpeedTreeData() const;
    eCSpeedTreeRenderBuffer *GetRenderBuffer() const;
    bEResult LoadAndGetSpeedTreeData(eCWraper_SpeedTreeRT *&);
    void Render(eCSpeedTree_PS *);
    void RenderTerrainShadows(eCSpeedTree_PS *);
    void SetRenderBuffer(eCSpeedTreeRenderBuffer *);

  protected:
    void DeleteResources();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(eCResourceSpeedTree_PS, 0x38)
