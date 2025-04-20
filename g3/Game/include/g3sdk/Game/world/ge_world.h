#pragma once

#include <Engine.h>

class gCDynamicLayer;
class gCGeometryLayer;
class gCProject;
class gCSector;

class GE_DLLIMPORT gCWorld : public eCProcessibleElement
{
  public:
    class gCSaveGameHeader
    {
        GE_UNIMPL_STRUCT(gCSaveGameHeader)
    };

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~gCWorld() override;
    public: bEResult PostInitializeProperties() override;
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
    public: eCProcessibleElement::eEResult Activate() override;
    protected: eCProcessibleElement::eEResult ReleaseData() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCWorld, eCProcessibleElement)

  public:
    static gCWorld *GE_STDCALL GetCurrentWorld();
    static void GE_STDCALL GetFileExt(bCString &);
    static bCString GE_STDCALL GetPlayerCameraName();
    static bCString GE_STDCALL GetPlayerName();
    static bCString GE_STDCALL GetSaveGameFolder();
    static gCSector *GE_STDCALL GetSectorForEntity(eCEntity const *);
    static GEBool GE_STDCALL ReadConfigFile(eCConfigFile &, bCString const &);
    static GEBool GE_STDCALL RenameConfigFile(bCString const &, bCString const &);
    static GEBool GE_STDCALL WriteConfigFile(eCConfigFile &, bCString const &);

  public:
    void AddToRemovedNativeEntityList(eCEntity *);
    GEBool BackupFiles(bCString const &, GEInt, GEBool, GEBool, GEBool);
    GEBool BackupFilesExists(bCString const &, GEInt, bCDateTime *);
    eCProcessibleElement::eEResult ClearSystemSector();
    eCProcessibleElement::eEResult Create(gCProject &, bCString const &);
    eCEntity *CreateChildEntity(eCEntity *);
    eCEntity *CreateChildEntityFromTemplate(eCEntity *, eCTemplateEntity *);
    eCDynamicEntity *CreateDynamicEntity(bTObjArray<bCString> const &);
    eCDynamicEntity *CreateDynamicEntity(bCString const &);
    eCDynamicEntity *CreateDynamicEntity();
    eCProcessibleElement::eEResult CreateSaveGame(bCString const &);
    eCGfxImageData *CreateSaveGameImageFromBB();
    eCDynamicEntity *CreateTempDynamicEntity(bTObjArray<bCString> const &);
    eCDynamicEntity *CreateTempDynamicEntity(bCString const &);
    eCDynamicEntity *CreateTempDynamicEntity();
    GEBool DeleteSaveGame(bCString const &);
    GEBool DestroyDynamicEntity(eCDynamicEntity *);
    GEBool DestroyTempDynamicEntity(eCDynamicEntity *);
    void DoLoadLocalConfiguration();
    void DoSaveLocalConfiguration() const;
    GEBool EnableSectorFolder(bCString const &, GEBool);
    GEBool ExistsSaveGame(bCString const &);
    bCString const &GetActiveSector() const;
    gCSaveGameHeader const &GetCurrentSaveGameHeader() const;
    void(GE_STDCALL *GetLoadingCallback() const)(GEUInt const &, GEUInt const &, GEUInt const &, GEUInt const &);
    gCProject &GetProject();
    gCProject const &GetProject() const;
    bEResult GetSaveGameHeader(bCString const &, gCSaveGameHeader &);
    void GetSaveGameList(bTObjArray<bCString> &);
    gCSector *GetSector(bCString const &);
    gCSector const *GetSector(bCString const &) const;
    gCSector *GetSectorAt(GEInt);
    gCSector const *GetSectorAt(GEInt) const;
    GEInt GetSectorCount() const;
    GEInt GetSectorIndex(bCString const &) const;
    gCDynamicLayer &GetSystemLayer();
    gCSector &GetSystemSector();
    gCDynamicLayer &GetSystemTempLayer();
    eCEntity *GetWorldEntity();
    eCEntity const *GetWorldEntity() const;
    GEBool GetWorldFiles(bTObjArray<bCString> &) const;
    void GetWorldVersion(GEU32 &, GEU32 &, GEU32 &, GEU32 &);
    GEBool HasSystemLayers() const;
    GEBool HasSystemSector() const;
    gCSector *ImportSector(eCArchiveFile &);
    gCSector *ImportSector(bCString const &);
    gCSector *InsertNewSector(bCString const &, bCString const &);
    eCProcessibleElement::eEResult InsertSector(gCSector *);
    GEBool IsSaveGameModeEnabled() const;
    GEBool IsSectorFolderEnabled(bCString const &) const;
    GEBool LoadGameWorld(bCString const &, GEBool);
    void RemoveAll();
    eCProcessibleElement::eEResult RemoveSector(gCSector *);
    GEBool RestartWorld(GEBool);
    GEBool RestoreFiles(bCString const &);
    GEBool SaveGameWorld(bCString const &, eCGfxImageData *, GELPVoid, GEU32);
    gCGeometryLayer *SearchForLayer(eCContextBase const *) const;
    void SetActiveSector(bCString const &);
    void SetLoadingCallback(void(GE_STDCALL *)(GEUInt const &, GEUInt const &, GEUInt const &, GEUInt const &));
    void UnloadCaches();

  protected:
    gCDynamicLayer *CreateSystemLayer(bCString const *);
    gCSector *CreateSystemSector();
    gCDynamicLayer *CreateSystemTempLayer();
    void DoAfterWorldActivate();
    void Invalidate();
    GEBool OnLoadDynamicContext(bCIStream &, gCDynamicLayer &, GEBool);
    eCProcessibleElement::eEResult RemoveSectorInternal(gCSector *);
    void SetProject(gCProject *);

  private:
    GE_UNIMPL_MEMBERS(180)
};

GE_ASSERT_SIZEOF(gCWorld, 0xd0)

GE_DLLIMPORT_EXTC bCString const g_strPlayerName;
