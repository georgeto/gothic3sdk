#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/entity/ge_entitypropertyset.h>

#include <SharedBase.h>

class eCIlluminated_PS;
class eCLightSet;

class GE_DLLIMPORT eCDynamicLight_PS : public eCEntityPropertySet
{
    // clang-format off
    protected: virtual void RemoveLightSet(eCLightSet *);
    protected: virtual void AddLightSet(eCLightSet *);
    protected: virtual void UpdateIllumination();
    public: virtual void UpdateEffectedObjects();
    public: virtual GEBool IsBoxInRange(bCBox const &);
    public: virtual GEBool IsObjectInRange(eCEntity *);
    public: virtual void UpdateShadowMaps();
    public: virtual void OnShadowSettingsChanged();
    public: virtual bEResult ResetResources(GEBool);
    public: virtual bEResult RestoreResources(GEBool);
    public: virtual void OnEffectedObjectRemoved(eCIlluminated_PS *);
    public: virtual void OnEffectedObjectAdded(eCIlluminated_PS *);
    public: virtual void OnEffectedObjectMoved(eCIlluminated_PS *);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCDynamicLight_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    protected: void OnUpdatedWorldMatrix() override;
    protected: void OnCacheIn() override;
    protected: void OnCacheOut() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCDynamicLight_PS, eCEntityPropertySet)
    GE_PROPERTY(GEBool, Enabled, m_bEnabled)
    GE_PADDING(1)

  public:
    bTValArray<eCLightSet *> const &GetLightSets() const;

  protected:
    GEFloat CalculateEffectIntensity(eEDynamicLightEffect, GEFloat, GEFloat, GEFloat) const;
    void CollectEntity(eCEntity *, bTValArray<eCIlluminated_PS *> &);
    void Invalidate();
    GEBool RemoveFromAllLightSets();

  private:
    GE_UNIMPL_MEMBERS(12)
};

GE_ASSERT_SIZEOF(eCDynamicLight_PS, 0x24)

GE_ASSERT_PROPERTY(eCDynamicLight_PS, m_bEnabled, 0x14, 1)
