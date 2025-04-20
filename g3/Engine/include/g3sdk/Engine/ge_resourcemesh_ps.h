#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_resourcebase_ps.h>

#include <SharedBase.h>

class eCVertexStructArrayBase;

class eCVertexStructArray_bCVector2
{
    GE_UNIMPL_STRUCT(eCVertexStructArray_bCVector2)
};

class GE_DLLIMPORT eCResourceMesh_PS : public eCResourceBase_PS
{
  public:
    struct eSIndexSpatialInfo
    {
        GE_UNIMPL_STRUCT(eSIndexSpatialInfo)
    };

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCResourceMesh_PS() override;
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
    GE_PROPERTY_SET(eCResourceMesh_PS, eCResourceBase_PS)
    GE_PROPERTY(GEU32, FVF, m_FVF)
    GE_PROPERTY(bCBox, BoundingBox, m_BoundingBox)
    GE_PROPERTY(bCString, MaterialFileName, m_strMaterialFileName)

  public:
    static void GE_STDCALL GetProprietaryFileExt(bCString &);
    static GEBool GE_STDCALL IsNativeFileType(bCString const &);
    static GEBool GE_STDCALL IsProprietaryFileType(bCString const &);

  public:
    eCVertexStructArrayBase *AccessStreamArray(GEU32);
    eCVertexStructArrayBase *AccessStreamArray(eEVertexStreamArrayType);
    eCVertexStructArrayBase *CreateStreamArray(eEVertexStreamArrayType);
    void DeleteAllLightmapSlots();
    GEBool DeleteStreamArray(eEVertexStreamArrayType);
    eCVertexStructArray_bCVector2 const *GetLightmapSlot(GEInt) const;
    eSIndexSpatialInfo const &GetSpatialInfo(GEU16);
    GEU16 GetSpatialInfoCount() const;
    eCVertexStructArrayBase const *GetStreamArray(GEU32) const;
    eCVertexStructArrayBase const *GetStreamArray(eEVertexStreamArrayType) const;
    GEBool HasLightmaps() const;
    GEBool HasStreamArray(eEVertexStreamArrayType);
    GEBool SetLightmapSlot(GEInt, eCVertexStructArray_bCVector2 const *);
    GEBool SetMaterialFile(bCString const &);
    GEBool SetStreamArray(eCVertexStructArrayBase const &);
    GEBool SetStreamArrays(GEU32);

  protected:
    void DeleteResources();
    GEBool DoSetLightmapSlot(GEInt, eCVertexStructArray_bCVector2 const *);
    GEBool DoSetStreamArray(eCVertexStructArrayBase const &);
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(28)
};

GE_ASSERT_SIZEOF(eCResourceMesh_PS, 0x68)

GE_ASSERT_PROPERTY(eCResourceMesh_PS, m_FVF, 0x2c, 4)
GE_ASSERT_PROPERTY(eCResourceMesh_PS, m_BoundingBox, 0x30, 24)
GE_ASSERT_PROPERTY(eCResourceMesh_PS, m_strMaterialFileName, 0x48, 4)
