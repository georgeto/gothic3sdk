#pragma once

#include <Engine/entity/ge_entitypropertyset.h>
#include <Engine/ge_frustumdatabase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCEngineCaps_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCEngineCaps_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsEditorRelevant() const override;
    public: void OnProcess() override;
    public: void OnPreProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCEngineCaps_PS, eCEntityPropertySet)
    GE_PROPERTY(GEBool, StaticVisualsRendering, m_bEnableStaticVisualsRendering)
    GE_PROPERTY(GEBool, DynamicVisualsRendering, m_bEnableDynamicVisualsRendering)
    GE_PROPERTY(GEBool, ZPass, m_bEnableZPass)
    GE_PROPERTY(GEBool, AlphaPass, m_bEnableAlphaPass)
    GE_PROPERTY(GEBool, MaterialPass, m_bEnableMaterialPass)
    GE_PROPERTY(GEBool, DrawBoundingVolumes, m_bEnableDrawBoundingVolumes)
    GE_PROPERTY(GEBool, PVSPrefetcherWorkerThread, m_bEnablePVSPrefetcherWorkerThread)
    GE_PROPERTY(GEBool, EnableObjectVPTHCCulling, m_bEnableObjectVPTHCCulling)
    GE_PROPERTY(GEBool, ChildDependenciesRendering, m_bEnableChildDependenciesRendering)
    GE_PROPERTY(GEBool, DrawEntityNames, m_bEnableDrawEntityNames)
    GE_PROPERTY(GEBool, DrawEntityAxes, m_bEnableDrawEntityAxes)
    GE_PADDING(1)
    GE_PROPERTY(GEFloat, FarClippingPlane, m_fFarClippingPlane)
    GE_PROPERTY(GEFloat, ScreenObjectDistanceCulling, m_fScreenObjectDistanceCulling)
    GE_PROPERTY(GEFloat, GlobalVisualLoDFactor, m_fGlobalVisualLoDFactor)

  public:
    void SetFromCaps(eCFrustumDatabase::eSCaps const &);
    void UpdateFromFrustumDatabase();

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(eCEngineCaps_PS, 0x30)

GE_ASSERT_PROPERTY(eCEngineCaps_PS, m_bEnableStaticVisualsRendering, 0x14, 1)
GE_ASSERT_PROPERTY(eCEngineCaps_PS, m_bEnableDynamicVisualsRendering, 0x15, 1)
GE_ASSERT_PROPERTY(eCEngineCaps_PS, m_bEnableZPass, 0x16, 1)
GE_ASSERT_PROPERTY(eCEngineCaps_PS, m_bEnableAlphaPass, 0x17, 1)
GE_ASSERT_PROPERTY(eCEngineCaps_PS, m_bEnableMaterialPass, 0x18, 1)
GE_ASSERT_PROPERTY(eCEngineCaps_PS, m_bEnableDrawBoundingVolumes, 0x19, 1)
GE_ASSERT_PROPERTY(eCEngineCaps_PS, m_bEnablePVSPrefetcherWorkerThread, 0x1a, 1)
GE_ASSERT_PROPERTY(eCEngineCaps_PS, m_bEnableObjectVPTHCCulling, 0x1b, 1)
GE_ASSERT_PROPERTY(eCEngineCaps_PS, m_bEnableChildDependenciesRendering, 0x1c, 1)
GE_ASSERT_PROPERTY(eCEngineCaps_PS, m_bEnableDrawEntityNames, 0x1d, 1)
GE_ASSERT_PROPERTY(eCEngineCaps_PS, m_bEnableDrawEntityAxes, 0x1e, 1)
GE_ASSERT_PROPERTY(eCEngineCaps_PS, m_fFarClippingPlane, 0x20, 4)
GE_ASSERT_PROPERTY(eCEngineCaps_PS, m_fScreenObjectDistanceCulling, 0x24, 4)
GE_ASSERT_PROPERTY(eCEngineCaps_PS, m_fGlobalVisualLoDFactor, 0x28, 4)
