#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class gCCameraAI_PS;
class gCEntity;
class gCGUIManager;
class gCScreenOutputCtrl;
class gCSessionCheats;
class gCSessionInfo;
class gCSessionKeys;

enum gESession_StartMode
{
    gESession_StartMode_NewGame = 0,
    gESession_StartMode_LoadGame = 1,
};

class GE_DLLIMPORT gCSession : public eCEngineComponentBase
{
    // clang-format off
    public: virtual GEBool HandleMessage(GEUInt, GEUInt, GEInt);
    public: virtual void CopyFrom(gCSession const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~gCSession() override;
    protected: eCInputReceiver::eEInputPriority GetInputPriority() const override;
    protected: GEInt OnAction(eCInpShared::eSGameKeyMessage const &) override;
    protected: GEInt OnKeyboard(eCInpShared::eSInputMessage const &) override;
    protected: GEInt OnMouse(eCInpShared::eSInputMessage const &) override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult WorldActivate() override;
    public: bEResult WorldDeactivate() override;
    public: void Process() override;
    public: void OnPostRender() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCSession, eCEngineComponentBase)
    GE_ENUMPROP(gESession_State, State, m_enuState)

  public:
    static gCSession &GE_STDCALL AccessSession();
    static gCSession &GE_STDCALL GetInstance();
    static gCSession const &GE_STDCALL GetSession();
    static GEBool GE_STDCALL PrefetchEntityCallback(GEInt, GEInt);

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    gCSessionKeys &AccessSessionKeys() const;
    GEBool CanPlayerMove() const;
    GEBool CopyCheckFailed() const;
    gCCameraAI_PS *GetCamera_PS();
    gCCameraAI_PS const *GetCamera_PS() const;
    gCSessionCheats const &GetCheats() const;
    eCEntity *GetEditorEntity() const;
    gCGUIManager *GetGUIManager() const;
    eCDynamicEntity *GetHero();
    eCDynamicEntity const *GetHero() const;
    eCDynamicEntity *GetPlayer();
    eCDynamicEntity const *GetPlayer() const;
    gCScreenOutputCtrl *GetScreenOutputCtrl();
    gCSessionInfo const &GetSessionInfo() const;
    gCSessionKeys const &GetSessionKeys() const;
    GEBool GiveAllItems(GEBool, GEU32, GEU32, bCString const &) const;
    GEBool GiveItems(bCString const &, GEU32, GEU32) const;
    void GotoLoadedPosition(eCEntity *, GEBool);
    void GotoStartPosition(GEBool);
    void Invalidate();
    GEBool const IsGameRunning() const;
    GEBool const IsInTestMode() const;
    GEBool IsPaused() const;
    GEBool IsSaveAllowed() const;
    void OpenMenu();
    void Pause();
    void Resume();
    GEBool SetAttrib(bCString const &, GEInt);
    void SetControlsCustomWaitForKeyCallback(GELPVoid, GELPVoid);
    void SetTestMode(GEBool);
    eCEntity *SpawnEntity(bCString const &, bCVector, GEBool);
    void Start(gESession_StartMode);
    void StartControlNPC(gCEntity *);
    void Stop();
    void StopControlNPC(GEBool);
    GEBool Teach(bCString const &) const;

  protected:
    static gCSession *ms_pCurrentSession;

  protected:
    void CreateCameraEntity();
    void CreatePlayerEntity();
    void GE_STDCALL OnBeamPlayerForward(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnChangeGameTime(bCObjectRefBase *, eCConsoleEventArg *);
    void GE_STDCALL OnCheat(bCObjectRefBase *, eCConsoleEventArg *);
    void GE_STDCALL OnConsoleCommand(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnControlEntity(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnDisposeItem(bCObjectRefBase *, eCConsoleEventArg *);
    void GE_STDCALL OnGameMenuClicked(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnGiveItem(bCObjectRefBase *, eCConsoleEventArg *);
    void GE_STDCALL OnGotoCamera(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnGotoEntity(bCObjectRefBase *, eCConsoleEventArg *);
    void GE_STDCALL OnResetCamera(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnResetPlayer(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnSingleStep(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnSpawnEntity(bCObjectRefBase *, eCConsoleEventArg *);
    void GE_STDCALL OnTeach(bCObjectRefBase *, eCConsoleEventArg *);
    void GE_STDCALL OnToggleDebugMode(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnToggleEditMode(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnToggleFixedCam(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnToggleFreeFlyCam(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnToggleShowAI(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnToggleShowNames(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnToggleShowTime(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnTriggerEntity(bCObjectRefBase *, eCConsoleEventArg *);
    void GE_STDCALL OnUntriggerEntity(bCObjectRefBase *, eCConsoleEventArg *);
    void GE_STDCALL OnViewMenuClicked(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnWatchEntity(bCObjectRefBase *, bCEvent *);
    void SetPlayer(eCDynamicEntity *);

  private:
    void DeregisterEvents();
    void RegisterEvents();
    void TransferDebugEvents(eCEntity &);

  private:
    GE_UNIMPL_MEMBERS(236)
};

GE_ASSERT_SIZEOF(gCSession, 0x108)

GE_ASSERT_PROPERTY(gCSession, m_enuState, 0x14, 8)
