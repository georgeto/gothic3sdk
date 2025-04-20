#pragma once

#include <Game/GameEnum.h>
#include <Game/world/ge_world.h>

#include <Engine.h>

class gCDynamicLayer;
class gCGeometryLayer;

class gCGeometryLayerProcessStrategy
{
    GE_UNIMPL_STRUCT(gCGeometryLayerProcessStrategy)
};

class GE_DLLIMPORT gCSector : public eCProcessibleElement
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~gCSector() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: GEBool IsDataAvailable() const override;
    public: bCString GetFileExt() const override;
    public: bCString GetFileType() const override;
    public: bCString GetDataFileExt() const override;
    public: bCString GetDataFileType() const override;
    public: GEU16 GetFileVersion() const override;
    protected: eCProcessibleElement::eEResult DoLoadData(bCIStream &) override;
    protected: eCProcessibleElement::eEResult DoSaveData(bCOStream &, bCString const &) override;
    protected: void OnModify() override;
    protected: void OnActivate() override;
    protected: GEBool CanGotoState(eCProcessibleElement::eEState) override;
    protected: void UpdateState() override;
    protected: eCProcessibleElement::eEResult ReleaseData() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCSector, eCProcessibleElement)
    GE_PROPERTY(bTRefPtrArray<bCPropertyObjectBase *>, GeometryLayers, m_arrGeometryLayers)
    GE_PROPERTY(bTRefPtrArray<bCPropertyObjectBase *>, EntityLayers, m_arrEntityLayers)
    GE_PROPERTY(bTPOSmartPtr<gCWorld>, WorldPtr, m_pWorld)
    GE_PROPERTY(GEBool, Marked, m_bMarked)
    GE_PROPERTY(GEBool, Freezed, m_bFreezed)
    GE_PROPERTY(GEBool, Locked, m_bLocked)
    GE_PADDING(1)
    GE_PROPERTY(GEFloat, VisualLoDFactor, m_fVisualLoDFactor)
    GE_PROPERTY(GEFloat, ObjectCullFactor, m_fObjectCullFactor)

  public:
    static void GE_STDCALL EnableSectorActivation(GEBool);
    static void GE_STDCALL EnableSectorSpeedup(GEBool);
    static void GE_STDCALL GetFileExt(bCString &);

  public:
    gCDynamicLayer *AccessDynamicLayer(bCString const &);
    gCGeometryLayer *AccessGeometryLayer(bCString const &);
    gCGeometryLayerProcessStrategy *&AccessGeometryLayerProcessStrategy();
    gCWorld &AccessWorld();
    GEBool BackupFiles(bCString const &, GEInt, GEBool, GEBool, bTObjArray<bCString> &);
    GEBool BackupFilesExists(bCString const &, GEInt);
    void CollectContexts(bTSmallArray<eCContextBase *> &) const;
    GEBool ContainsEntity(eCEntity const &) const;
    eCProcessibleElement::eEResult Create(gCWorld &, bCString const &, bCString const &);
    GEBool Enable(GEBool);
    gCDynamicLayer const *GetDynamicLayer(bCString const &) const;
    gCDynamicLayer *GetDynamicLayerAt(GEInt);
    gCDynamicLayer const *GetDynamicLayerAt(GEInt) const;
    GEInt GetDynamicLayerCount() const;
    GEInt GetDynamicLayerIndex(bCString const &) const;
    gCGeometryLayer const *GetGeometryLayer(bCString const &) const;
    gCGeometryLayer *GetGeometryLayerAt(GEInt);
    gCGeometryLayer const *GetGeometryLayerAt(GEInt) const;
    GEInt GetGeometryLayerCount() const;
    GEInt GetGeometryLayerIndex(bCString const &) const;
    gCGeometryLayerProcessStrategy *GetGeometryLayerProcessStrategy() const;
    gCWorld const &GetWorld() const;
    gCDynamicLayer *ImportDynamicLayer(eCArchiveFile &);
    gCDynamicLayer *ImportDynamicLayer(bCString const &);
    gCGeometryLayer *ImportGeometryLayer(eCArchiveFile &);
    gCGeometryLayer *ImportGeometryLayer(bCString const &);
    eCProcessibleElement::eEResult InsertDynamicLayer(gCDynamicLayer *);
    eCProcessibleElement::eEResult InsertGeometryLayer(gCGeometryLayer *);
    gCDynamicLayer *InsertNewDynamicLayer(bCString const &, gEEntityType);
    gCGeometryLayer *InsertNewGeometryLayer(bCString const &, gEGeometryType);
    GEBool IsEnabled() const;
    GEBool IsReadOnly() const;
    GEBool IsSysSector() const;
    GEFloat QueryProgress();
    GEBool RemoveAll();
    eCProcessibleElement::eEResult RemoveDynamicLayer(gCDynamicLayer *);
    eCProcessibleElement::eEResult RemoveGeometryLayer(gCGeometryLayer *);
    GEBool RestoreFiles(bCString const &);
    void SetGeometryLayerProcessStrategy(gCGeometryLayerProcessStrategy *);
    void UnloadCaches();

  protected:
    static GEBool ms_bEnableLayerActivation;
    static GEBool ms_bStaticLayerSpeedUp;
    static bCString const ms_strDynamicEntitySector;

  protected:
    static void GE_STDCALL CopyFileToBackup(bCString const &, bCString const &, bTObjArray<bCString> &);

  protected:
    GEBool ContainsEntity(eCEntity const *, eCEntity const &) const;
    void Invalidate();
    GEBool OnEnable(GEBool);
    eCProcessibleElement::eEResult RemoveDynamicLayerInternal(gCDynamicLayer *);
    void SetWorld(bCPropertyObjectBase const *);
    void SetWorld(gCWorld const *);

  private:
    GE_UNIMPL_MEMBERS(20)
};

GE_ASSERT_SIZEOF(gCSector, 0x5c)

GE_ASSERT_PROPERTY(gCSector, m_arrGeometryLayers, 0x1c, 12)
GE_ASSERT_PROPERTY(gCSector, m_arrEntityLayers, 0x28, 12)
GE_ASSERT_PROPERTY(gCSector, m_pWorld, 0x34, 8)
GE_ASSERT_PROPERTY(gCSector, m_bMarked, 0x3c, 1)
GE_ASSERT_PROPERTY(gCSector, m_bFreezed, 0x3d, 1)
GE_ASSERT_PROPERTY(gCSector, m_bLocked, 0x3e, 1)
GE_ASSERT_PROPERTY(gCSector, m_fVisualLoDFactor, 0x40, 4)
GE_ASSERT_PROPERTY(gCSector, m_fObjectCullFactor, 0x44, 4)
