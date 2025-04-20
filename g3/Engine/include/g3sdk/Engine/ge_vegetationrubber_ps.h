#pragma once

#include <Engine/entity/ge_entitypropertyset.h>
#include <Engine/ge_vegetation_gridnode.h>

#include <SharedBase.h>

class eCVegetation_PS;

class GE_DLLIMPORT eCVegetationRubber_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCVegetationRubber_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsVisual() const override;
    public: GEBool IsEditorRelevant() const override;
    protected: void OnRender(GEI16) override;
    protected: void OnUpdatedWorldMatrix() override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCVegetationRubber_PS, eCEntityPropertySet)
    GE_PROPERTY(GEFloat, Radius, m_fRadius)

  public:
    void Enable(GEBool);
    eCVegetation_PS *GetCurrentVegetationPS() const;
    bTObjArray<eSVegetationMeshID> &GetVegetationIDs();
    GEBool IsEnabled() const;
    void SetCurrentVegetationPS(eCVegetation_PS *);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(44)
};

GE_ASSERT_SIZEOF(eCVegetationRubber_PS, 0x44)

GE_ASSERT_PROPERTY(eCVegetationRubber_PS, m_fRadius, 0x14, 4)
