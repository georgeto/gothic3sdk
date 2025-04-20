#pragma once

#include <Engine.h>

class gCDummyCollectorBase;

class GE_DLLIMPORT gCDummyCollectorAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: virtual bEResult OnDestroyWorkspace();
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~gCDummyCollectorAdmin() override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult Shutdown() override;
    public: bEResult WorldActivate() override;
    public: bEResult WorldDeactivate() override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCDummyCollectorAdmin, eCEngineComponentBase)

  public:
    bEResult AddPropertySetMember(eEPropertySetType, eCEntity &, eCEntity *&, GEInt, GEInt, GEInt);
    void ClearAllCollections();
    bEResult DeletePropertySetMember(eEPropertySetType, eCEntity &, GEInt);
    bEResult DeletePropertySetMember(eEPropertySetType, eCEntity &, eCEntity *);
    void DisableAllPropertySets();
    void EnableApplyToTemplate(GEBool);
    void EnableApplyToTemplateInstances(GEBool);
    void EnablePropertyset(eEPropertySetType, bCBox const &, GEBool);
    void EnablePropertyset(eEPropertySetType, eCEntity const &, GEBool);
    void EnablePropertyset(eEPropertySetType, GEBool);
    void EnableRenderingForIndex(eEPropertySetType, eCEntity &, GEInt, GEBool);
    eCEntity *GetDummyEntityAtIndex(eEPropertySetType, eCEntity &, GEInt) const;
    GEInt GetEntityAndMemberIndex(eEPropertySetType, eCEntity const *, eCEntity *&);
    GEU32 GetPropertySetMemberCount(eEPropertySetType, eCEntity &) const;
    GEBool GetShowPropertyset_Attribs() const;
    GEBool GetShowPropertyset_Entities() const;
    GEBool GetShowPropertyset_Types() const;
    void Invalidate();
    GEBool IsApplyToTemplateEnabled() const;
    GEBool IsApplyToTemplateInstancesEnabled() const;
    GEBool IsCollecting() const;
    void GE_STDCALL OnViewLabels(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnViewLights(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnViewNavigation(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnViewSounds(bCObjectRefBase *, bCEvent *);
    void RemoveEntity(eCEntity &);
    void SetShowPropertyset_Attribs(GEBool);
    void SetShowPropertyset_Entities(GEBool);
    void SetShowPropertyset_Types(GEBool);

  protected:
    void AddEntitiesFromCollection(gCDummyCollectorBase *);
    void AddEntitiesFromCollections();
    void CollectEntity(eCEntity &);
    void CollectProcessingRange();
    void CreateDummyEntities();
    void DeleteAllCollections();
    void LazyCreateCollections();
    void OnUpdatedWorldMatrix(eCEntity &);

  private:
    GE_UNIMPL_MEMBERS(108)
};

GE_ASSERT_SIZEOF(gCDummyCollectorAdmin, 0x80)
