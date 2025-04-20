#pragma once

#include <Engine/entity/ge_entitypropertyset.h>
#include <Engine/ge_vegetation_gridnode.h>

#include <SharedBase.h>

class eCVegetation_Grid;
class eCVegetation_Mesh;

class GE_DLLIMPORT eCVegetation_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCVegetation_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool NotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsVisual() const override;
    protected: GEBool IsProcessable() const override;
    public: GEBool IsEditorRelevant() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    protected: void OnRender(GEI16) override;
    public: void OnUpdateInternals() override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCVegetation_PS, eCEntityPropertySet)
    GE_PROPERTY(GEBool, UseDefaultViewRange, m_bUseDefaultViewRange)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, ViewRange, m_fViewRange)
    GE_PROPERTY(GEFloat, FadeOutStart, m_fFadeOutStart)
    GE_PROPERTY(GEFloat, GridNodeSize, m_fGridNodeSize)
    GE_PROPERTY(GEBool, UseQuality, m_bUseQuality)
    GE_PADDING(1)

  public:
    GEU16 AddType(bCString const &);
    eCVegetation_Mesh *CreateMesh();
    eCVegetation_Grid *GetGrid() const;
    eCVegetation_Mesh *GetMesh(GEU16) const;
    eCVegetation_Mesh *GetMesh(eSVegetationMeshID) const;
    eCVegetation_Mesh *GetMeshAt(GEInt) const;
    GEInt GetMeshCount() const;
    GEInt GetMeshIDCount() const;
    bCString const &GetType(GEU16) const;
    bCString const &GetType(eSVegetationMeshID) const;
    bCString const &GetTypeAt(GEInt) const;
    GEInt GetTypeCount() const;
    GEU16 GetTypeID(bCString const &);
    GEBool IsIDValid(eSVegetationMeshID) const;
    void RemapMeshID(eSVegetationMeshID, eSVegetationMeshID);
    void RemoveMesh(eCVegetation_Mesh *);
    void RemoveMesh(eSVegetationMeshID);
    void RemoveType(GEU16, GEU16);
    void SetType(GEU16, bCString const &);
    void SetType(eSVegetationMeshID, bCString const &);
    void SetTypeAt(GEInt, bCString const &);
    void UpdateBounds();

  protected:
    eSVegetationMeshID AddMesh(eCVegetation_Mesh *);
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(56)
};

GE_ASSERT_SIZEOF(eCVegetation_PS, 0x60)

GE_ASSERT_PROPERTY(eCVegetation_PS, m_bUseDefaultViewRange, 0x14, 1)
GE_ASSERT_PROPERTY(eCVegetation_PS, m_fViewRange, 0x18, 4)
GE_ASSERT_PROPERTY(eCVegetation_PS, m_fFadeOutStart, 0x1c, 4)
GE_ASSERT_PROPERTY(eCVegetation_PS, m_fGridNodeSize, 0x20, 4)
GE_ASSERT_PROPERTY(eCVegetation_PS, m_bUseQuality, 0x24, 1)
