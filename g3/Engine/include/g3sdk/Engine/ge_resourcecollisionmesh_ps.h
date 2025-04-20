#pragma once

#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class NxConvexMesh;
class NxTriangleMesh;

struct eSPhysicMaterialInfos
{
    GE_UNIMPL_STRUCT(eSPhysicMaterialInfos)
};

class GE_DLLIMPORT eCResourceCollisionMesh_PS : public eCResourceBase_PS
{
  public:
    struct eSVertexPosition
    {
        GE_UNIMPL_STRUCT(eSVertexPosition)
    };

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceCollisionMesh_PS() override;
    public: bCString const & GetProprietaryFileExt() const override;
    public: bCString const & GetNativeFileExt() const override;
    public: eCResourceBase_PS::eECacheType GetCacheType() const override;
    public: bEResult DoLoad() override;
    public: bEResult DoUnload() override;
    public: bEResult DoReload() override;
    public: bEResult DoConvert() override;
    public: bEResult DoSave() override;
    protected: void CalculateSize() override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnUpdateInternals() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCResourceCollisionMesh_PS, eCResourceBase_PS)

  public:
    static void GE_STDCALL GetProprietaryFileExt(bCString &);
    static GEBool GE_STDCALL IsNativeFileType(bCString const &);
    static GEBool GE_STDCALL IsProprietaryFileType(bCString const &);

  public:
    bTValArray<GEU32> &AccessIndexArray();
    eSVertexPosition &AccessVertexPosition(GEInt);
    GEBool Compute(eCResourceDataEntity *, GEBool a_bConvex, GEBool a_bAutoResolveMaterialInfos = GEFalse,
                   bTObjArray<eSPhysicMaterialInfos> *a_pArrMaterialInfos = nullptr,
                   GEFloat a_fNovodexScale = 1.0f); // a_pArrMaterialInfos ist optional, a_bAutoResolveMaterialInfos
                                                    // wird nur wirksam wenn a_pArrMaterialInfos == 0
    GEBool ComputeNovodexMesh(GEBool a_bConvex, GEBool a_bNotFlipNormals);
    void CopyWithScaling(eCResourceCollisionMesh_PS &, GEFloat);
    void CopyWithScaling(eCResourceCollisionMesh_PS &, GEFloat, GEFloat, GEFloat);
    GEU32 GetIndex(GEInt) const;
    bTValArray<GEU32> const &GetIndexArray() const;
    GEInt GetIndexDataCount() const;
    void GetIndexedBoundary(bCBox &, GEU16);
    GEBool GetIndexedMaterial(eSPhysicMaterialInfos &, GEU16);
    GEU32 GetNumConvexMeshes() const;
    GEU32 GetNumMeshes() const;
    NxConvexMesh *GetProprietaryConvexMesh(GEInt) const;
    NxTriangleMesh *GetProprietaryMesh(GEInt) const;
    bCDateTime GetUnscaledResourceModTime();
    GEInt GetVertexDataCount() const;
    eSVertexPosition const &GetVertexPosition(GEInt) const;
    bTValArray<eSVertexPosition> const &GetVertexPositionArray() const;
    GEBool HasConvexResource() const;

  protected:
    GEBool ComputeMesh(GEBool);
    void DeleteResources();
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(132)
};

GE_ASSERT_SIZEOF(eCResourceCollisionMesh_PS, 0xb0)

GE_DLLIMPORT_EXTC bCString const g_strResourceMeshCollisionFileExt;
