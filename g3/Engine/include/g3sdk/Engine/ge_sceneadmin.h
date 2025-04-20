#pragma once

#include <Engine/ge_enginecomponentbase.h>
#include <Engine/ge_entityadmin.h>

#include <SharedBase.h>

class eCEntity;
class eCEntityAdmin;
class eCEntityDynamicContext;
class eCGeometrySpatialContext;
class eCNode;
class eCResourceDataEntity;
class eCTemplateEntity;

enum eEGetEntityTypeHint
{
    eEGetEntityTypeHint_Entity = 0,
    eEGetEntityTypeHint_ResourceDataEntity = 1,
    eEGetEntityTypeHint_TemplateEntity = 2
};

struct eSTriggerConfig
{
    GE_UNIMPL_STRUCT(eSTriggerConfig)
};

class GE_DLLIMPORT eCSceneAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCSceneAdmin() override;
    public: bCGuid const & GetID() const override;
    public: bEResult Shutdown() override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCSceneAdmin, eCEngineComponentBase)

  public:
    GEBool CheckIfEntityNameExists(bCString const &) const;
    void ClearRegisteredEntities();
    eCEntityAdmin &GetAccessToEntityAdmin();
    eCEntityDynamicContext *GetDynamicEntityContext(GEInt) const;
    GEInt GetDynamicEntityContextCount() const;
    GEBool GetEntitiesByName(bCString const &, bTPtrArray<eCEntity *> &);
    GEBool GetEntitiesByName(bCString const &, bTPtrArray<eCEntity *> &) const;
    eCNode *GetEntity(bCPropertyID const &, eEGetEntityTypeHint);
    eCNode const *GetEntity(bCPropertyID const &, eEGetEntityTypeHint) const;
    eCEntity *GetEntityByName(bCString const &);
    eCEntity const *GetEntityByName(bCString const &) const;
    eCEntity *GetEntityByPartName(bCString const &, eEGetEntityTypeHint, GEInt = -1);
    GEInt GetEntityCountByPartName(bCString const &, eEGetEntityTypeHint);
    GEInt GetNumEntitiesByName(bCString const &) const;
    GEU32 GetNumberOfDynamicEntities() const;
    GEU32 GetNumberOfStaticEntities() const;
    eCGeometrySpatialContext *GetSpatialContext(GEInt) const;
    GEInt GetSpatialContextCount() const;
    GEInt GetTemplateEntitiesByName(bCString const &, bTPtrArray<eCTemplateEntity *> &);
    eCTemplateEntity *GetTemplateEntityByName(bCString const &);
    GEBool GetUniqueEntityByName(bCString const &, eCEntity *&) const;
    bCBox const &GetWorldBox() const;
    GEBool IsEditorModeEnabled() const;
    GEBool RegisterNameInfo(bCString const &, eCEntity const &);
    GEBool RegisterNameInfo(bCString const &, eCTemplateEntity const &);
    bTValMap<bCPropertyID, eCTemplateEntity *>::bCConstIterator TemplateEntitiesBegin() const;
    bTValMap<bCPropertyID, eCTemplateEntity *>::bCConstIterator TemplateEntitiesEnd() const;
    GEBool Trigger(bCString &, eSTriggerConfig &);
    GEBool UnregisterNameInfo(bCString const &, eCEntity const &);
    GEBool UnregisterNameInfo(bCString const &, eCTemplateEntity const &);

  protected:
    static GEInt GE_CCALL S_CompareEntityNames(GELPCVoid, GELPCVoid);

  protected:
    GEBool CanBeTriggered(eCEntity &, eSTriggerConfig &) const;
    void EnableEditorMode(GEBool);
    void Invalidate();
    GEBool RegisterDynamicEntityContext(eCEntityDynamicContext &);
    GEBool RegisterEntity(eCEntity *);
    GEBool RegisterResourceDataEntity(eCResourceDataEntity *);
    GEBool RegisterSpatialContext(eCGeometrySpatialContext &);
    GEBool RegisterTemplateEntity(eCTemplateEntity *);
    GEBool UnregisterDynamicEntityContext(eCEntityDynamicContext &);
    GEBool UnregisterEntity(eCEntity *);
    GEBool UnregisterResourceDataEntity(eCResourceDataEntity *);
    GEBool UnregisterSpatialContext(eCGeometrySpatialContext &);
    GEBool UnregisterTemplateEntity(eCTemplateEntity *);

  public:
    bTPtrMap<bCPropertyID, eCEntity *> m_mapEntities;
    bTPtrMap<bCPropertyID, eCResourceDataEntity *> m_mapResourceDataEntities;
    bTPtrMap<bCPropertyID, eCTemplateEntity *> m_mapTemplateEntities;
    bTPtrMap<bCString, bTPtrArray<eCEntity *>> m_mapNameInfoEntities;
    bTPtrMap<bCString, bTPtrArray<eCTemplateEntity *>> m_mapNameInfoTemplateEntities;
    GEBool m_bIsEditorModeEnabled;
    GE_PADDING(3)
    eCEntityAdmin m_EntityAdmin;
    GEU32 m_uNumberOfStaticEntities;
    GEU32 m_uNumberOfDynamicEntities;
    bTPtrArray<eCGeometrySpatialContext *> m_arrGeometrySpatialContexts;
    bCBox m_WorldBox;
};

GE_ASSERT_SIZEOF(eCSceneAdmin, 0x194)

GE_DLLIMPORT_EXTC eSTriggerConfig const g_DefaultTriggerConfig;
