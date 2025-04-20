#pragma once

#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCResourceMeshLoD_PS : public eCResourceBase_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceMeshLoD_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: bCString const & GetProprietaryFileExt() const override;
    public: bCString const & GetNativeFileExt() const override;
    public: eCResourceBase_PS::eECacheType GetCacheType() const override;
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
    GE_PROPERTY_SET(eCResourceMeshLoD_PS, eCResourceBase_PS)
    GE_PROPERTY(GEFloat, LoDScale, m_fLoDScale)
    GE_PROPERTY(bCBox, BoundingBox, m_BoundingBox)

  public:
    static void GE_STDCALL GetProprietaryFileExt(bCString &);
    static GEBool GE_STDCALL IsNativeFileType(bCString const &);
    static GEBool GE_STDCALL IsProprietaryFileType(bCString const &);

  public:
    GEBool AddLoDMesh(bCString const &, GEInt);
    GEBool AddLoDMeshComplexFile(bCString const &, GEInt);
    GEInt ContainsResourceFile(bCString const &) const;
    eCResourceDataEntity *GetMeshResource(GEInt);
    GEInt GetMeshResourceCount() const;
    GEBool RemoveAllLoDMeshFiles();
    GEBool RemoveLoDMeshFile(bCPropertyID const &);
    GEBool RemoveLoDMeshFile(bCString const &);

  protected:
    void DeleteResources();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(16)
};

GE_ASSERT_SIZEOF(eCResourceMeshLoD_PS, 0x58)

GE_ASSERT_PROPERTY(eCResourceMeshLoD_PS, m_fLoDScale, 0x2c, 4)
GE_ASSERT_PROPERTY(eCResourceMeshLoD_PS, m_BoundingBox, 0x30, 24)
