#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_stringwrapper.h>
#include <Engine/ge_vegetation_gridnode.h>

#include <SharedBase.h>

class eCResourceDataEntity;
class eCResourceImage_PS;

class GE_DLLIMPORT eCVegetation_Mesh : public bCObjectRefBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCVegetation_Mesh() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCVegetation_Mesh, bCObjectRefBase)
    GE_PROPERTY(bCMeshResourceString, MeshFilePath, m_strMeshFilePath)
    GE_ENUMPROP(eEVegetationMeshShading, MeshShading, m_eMeshShading)
    GE_PROPERTY(GEFloat, MinSpacing, m_fMinSpacing)
    GE_PROPERTY(GEFloat, WindStrength, m_fWindStrength)
    GE_PROPERTY(GEBool, DoubleSided, m_bDoubleSided)
    GE_PADDING(1)

  public:
    void CheckResourceTimeStamp();
    bCBox const &GetBoundingBox() const;
    eCResourceImage_PS *GetDiffuseTexture() const;
    bTValArray<GEU32> const &GetIndices() const;
    eSVegetationMeshID GetMeshID() const;
    bTValArray<bCVector> const &GetNormals() const;
    bTValArray<bCVector> const &GetPositions() const;
    GEU16 GetTypeID() const;
    bCString const &GetTypeName() const;
    bTValArray<bCVector2> const &GetUVs() const;
    void SetTypeID(GEU16);
    void SetTypeName(bCString const &);

  protected:
    eSVegetationMeshID &AccessMeshID();
    void Invalidate();
    void SetResourceMesh(eCResourceDataEntity *);

  private:
    GE_UNIMPL_MEMBERS(108)
};

GE_ASSERT_SIZEOF(eCVegetation_Mesh, 0x90)

GE_ASSERT_PROPERTY(eCVegetation_Mesh, m_strMeshFilePath, 0xc, 4)
GE_ASSERT_PROPERTY(eCVegetation_Mesh, m_eMeshShading, 0x10, 8)
GE_ASSERT_PROPERTY(eCVegetation_Mesh, m_fMinSpacing, 0x18, 4)
GE_ASSERT_PROPERTY(eCVegetation_Mesh, m_fWindStrength, 0x1c, 4)
GE_ASSERT_PROPERTY(eCVegetation_Mesh, m_bDoubleSided, 0x20, 1)
