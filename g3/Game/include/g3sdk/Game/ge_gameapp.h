#pragma once

#include <Engine.h>

class gCWorkspace;

class GE_DLLIMPORT gCGameApp : public eCApplication
{
    // clang-format off
    public: virtual GEBool IsInOutputStage();
    public: void Destroy() override;
    protected: bEResult Create() override;
    public: ~gCGameApp() override;
    public: eCEntity * GetEditorEntity() const override;
    public: GEBool IsGameRunning() const override;
    public: bCString GetCompiledMeshPath() const override;
    public: bCString GetCompiledMaterialLibPath() const override;
    public: bCString GetCompiledAnimationPath() const override;
    public: bCString GetCompiledImagePath() const override;
    public: bCString GetCompiledPhysicPath() const override;
    protected: void OnEngineCreated() override;
    protected: void OnDestroyEngine() override;
    protected: void OnDestroyWorkspace() override;
    protected: bEResult OnInitializeEngine(eSSetupEngine &) override;
    protected: bEResult CreateWorkspace() override;
    protected: GEBool OnHandleMessage(GEUInt, GEUInt, GEI32, GEI32 *) override;
    // clang-format on

  public:
    gCGameApp();

  public:
    gCGameApp &operator=(gCGameApp const &);

  public:
    gCWorkspace &GetAccessToWorkspace();
    bCString const &GetBackupFolder() const;
    bCString const &GetSaveGameFolder() const;
    GEBool const GetScriptAutoLoading() const;
    bCString const &GetScriptFolder() const;
    void GE_STDCALL OnChangeSectorStatus(bCObjectRefBase *, eCConsoleEventArg *);
    void GE_STDCALL OnMenuDebugToggleCameraInfos(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuNPCInformation(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuProfileAI(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuProfileNavigation(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuShowQuestLog(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnToggleGameKeys(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL PauseSession(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL StartSession(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL StopSession(bCObjectRefBase *, bCEvent *);

  protected:
    bEResult AutoDetection(eSSetupEngine &);
    bEResult BuildUserOptions(GEU32, eSSetupEngine &);
    void Invalidate();
};
