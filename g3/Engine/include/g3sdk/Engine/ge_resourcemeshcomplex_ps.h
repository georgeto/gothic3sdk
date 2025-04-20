#pragma once

#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class eCMeshElement;

class GE_DLLIMPORT eCResourceMeshComplex_PS : public eCResourceBase_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceMeshComplex_PS() override;
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
    GE_PROPERTY_SET(eCResourceMeshComplex_PS, eCResourceBase_PS)
    GE_PROPERTY(bCBox, BoundingBox, m_BoundingBox)

  public:
    static void GE_STDCALL GetProprietaryFileExt(bCString &);
    static GEBool GE_STDCALL IsNativeFileType(bCString const &);
    static GEBool GE_STDCALL IsProprietaryFileType(bCString const &);

  public:
    GEBool AddMeshElement(eCMeshElement *);
    GEBool AddMeshFile(bCString const &);
    eCMeshElement *GetMeshElement(GEInt) const;
    GEInt GetMeshResourceCount() const;
    eCResourceDataEntity *QueryDefaultLightmap(GEBool);
    GEBool RemoveMeshFileAt(GEInt);

  protected:
    void DeleteResources();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(16)
};

GE_ASSERT_SIZEOF(eCResourceMeshComplex_PS, 0x54)

GE_ASSERT_PROPERTY(eCResourceMeshComplex_PS, m_BoundingBox, 0x2c, 24)
