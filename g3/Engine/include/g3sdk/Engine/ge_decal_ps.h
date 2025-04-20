#pragma once

#include <Engine/entity/ge_entitypropertyset.h>
#include <Engine/ge_stringwrapper.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCDecal_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCDecal_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool NotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsVisual() const override;
    public: GEBool IsProcessable() const override;
    public: GEBool IsEditorRelevant() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: void OnEnterProcessingRange() override;
    public: void OnExitProcessingRange() override;
    public: void Decay() override;
    public: void OnUpdatedWorldMatrix() override;
    public: void OnCacheIn() override;
    public: void OnCacheOut() override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnProcess() override;
    public: GEBool IntersectsRay(eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc **) const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCDecal_PS, eCEntityPropertySet)
    GE_PROPERTY(bCImageOrMaterialResourceString, ImageOrMaterial, m_strImageOrMaterial)
    GE_PROPERTY(GEFloat, LifeTime, m_fLifeTime)
    GE_PROPERTY(bCVector, Size, m_vecSize)
    GE_PROPERTY(bCVector, Offset, m_vecOffset)
    GE_PROPERTY(GEBool, UseEntityDirection, m_bUseEntityDirection)
    GE_PADDING(3)
    GE_PROPERTY(bCEulerAngles, DirectionOffset, m_eulDirectionOffset)
    GE_PROPERTY(GEFloat, FadeInTime, m_fFadeInTime)
    GE_PROPERTY(GEFloat, FadeOutTime, m_fFadeOutTime)
    GE_PROPERTY(GEBool, CreateOnDynamicEntities, m_bCreateOnDynamicEntities)
    GE_PROPERTY(GEBool, AutoKill, m_bAutoKill)
    GE_PADDING(1)

  protected:
    GEBool CreateDecals();
    void DestroyDecals(GEBool);
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(20)
};

GE_ASSERT_SIZEOF(eCDecal_PS, 0x64)

GE_ASSERT_PROPERTY(eCDecal_PS, m_strImageOrMaterial, 0x14, 4)
GE_ASSERT_PROPERTY(eCDecal_PS, m_fLifeTime, 0x18, 4)
GE_ASSERT_PROPERTY(eCDecal_PS, m_vecSize, 0x1c, 12)
GE_ASSERT_PROPERTY(eCDecal_PS, m_vecOffset, 0x28, 12)
GE_ASSERT_PROPERTY(eCDecal_PS, m_bUseEntityDirection, 0x34, 1)
GE_ASSERT_PROPERTY(eCDecal_PS, m_eulDirectionOffset, 0x38, 12)
GE_ASSERT_PROPERTY(eCDecal_PS, m_fFadeInTime, 0x44, 4)
GE_ASSERT_PROPERTY(eCDecal_PS, m_fFadeOutTime, 0x48, 4)
GE_ASSERT_PROPERTY(eCDecal_PS, m_bCreateOnDynamicEntities, 0x4c, 1)
GE_ASSERT_PROPERTY(eCDecal_PS, m_bAutoKill, 0x4d, 1)
