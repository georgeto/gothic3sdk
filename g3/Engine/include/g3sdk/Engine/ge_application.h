#pragma once

#include <Engine/ge_gfxshared.h>
#include <Engine/io/ge_window.h>

#include <SharedBase.h>

class eCCameraBase;
class eCConfigFile;
class eCConsole;
class eCConsoleEventArg;
class eCEntity;
class eCKeyboard;
class eCMenu;
class eCModuleAdmin;
class eCMouse;
class eCSplash;

struct eSSetupEngine
{
    struct SPhysicalKeys
    {
        GE_UNIMPL_STRUCT(SPhysicalKeys)
    };

    GEU8 f0[4];
    GEInt SoundMasterVolume;
    GEInt SoundMusicVolume;
    GEInt SoundVoiceVolume;
    GEInt SoundEffectVolume;
    GEInt SoundAmbientVolume;
    GEU8 f18[4];
    GEBool bNoSound;
    GEU8 f1D[3];
    GEU32 DebugFilter;
    GEU32 Width;
    GEU32 Height;
    GEU32 RefreshRate;
    GEU8 AdapterNumber[4];
    GEU8 FullScreen;
    GEU8 SetToTrueIfWindowMode3;
    GEU8 byte36;
    GEU8 f37;
    GEFloat float38;
    GEU8 f3C[4];
    GEFloat m_fFarClippingPlane;
    GEU8 gap_44[4];
    GEUInt m_iCacheSizeImage;
    GEUInt m_iCacheSizeMesh;
    GEUInt m_iCacheSizeSound;
    GEUInt m_iCacheSizeMaterial;
    GEUInt m_iCacheSizeCollisionMesh;
    GEUInt m_iCacheSizeAnimation;
    GEUInt m_iCacheSizeSpeedTree;
    GEInt m_uVertexpoolThreadCount;
    GEInt m_uImageThreadCount;
    GEInt m_uMaterialThreadCount;
    GEInt m_uMeshThreadCount;
    GEInt m_uSoundThreadCount;
    GEInt m_uPVSPrefetcherCountThreadCount;
    GEInt m_uCollisionMeshThreadCount;
    GEInt m_uAnimationThreadCount;
    GEBool m_bThreadingEnabled;
    GEU8 f85[19];
    GEInt Entity_ROI;
    GEInt dword9C;
    GEInt dwordA0;
    GEInt dwordA4;
    GEU8 fA8[5];
    GEU8 byteAD;
    GEU8 fAE[2];
    GEInt PhysicsThreads;
    GEU8 fB4[5];
    GEU8 byteB9;
    GEU8 byteBA;
    GEU8 fBB;
    GEInt dwordBC;
    GEU8 Debug_MemoryCorruptionMonitor;
    GEU8 Debug_HeapProfiler;
    GEU8 Debug_DumpHeapProfiling;
    GEU8 Debug_ShowWindowForHeap;
    GEU8 Debug_WriteMiniDump;
    GEU8 Debug_WriteReadMe;
    GEU8 Debug_LogFileMsg;
    GEU8 byteC7;
    GEU8 fC8;
    GEU8 byteC9;
    GEU8 Debug_ExceptionHandlerEnable;
    GEU8 fCB;
    GEInt dwordCC;
    GEU8 fD0[8];
    GEInt dwordD8;
    GEInt dwordDC;
    GEU8 fE0[16];
    GEInt dwordF0;
    GEU8 byteF4;
    GEU8 fF5[3];
    GEFloat m_fFarClippingPlaneLowPolyMesh;
    GEInt dwordFC;
    GEInt dword100;
    GEInt dword104;
    GEU8 f108[8];
    GEU8 byte110;
    GEU8 byte111;
    GEU8 byte112;
    GEU8 byte113;
    GEU8 byte114;
    GEU8 byte115;
    GEU8 f116[2];
    GEU8 byte118;
    GEU8 f119[15];
    GEInt dword128;
    GEInt dword12C;
    GEInt dword130;
    GEInt dword134;
    GEInt dword138;
    GEU8 f13C[4];
    GEU8 byte140;
    GEU8 f141[3];
    GEInt dword144;
    GEInt dword148;
    GEInt dword14C;
    GEInt dword150;
    GEInt dword154;
    GEInt dword158;
    GEInt dword15C;
    GEInt dword160;
    GEInt dword164;
    GEInt dword168;
    GEInt dword16C;
    GEU8 byte170;
    GEU8 f171[3];
    GEInt dword174;
    GEInt dword178;
    GEInt dword17C;
    GEInt dword180;
    GEU8 byte184;
    GEU8 f185[3];
    GEInt Render_FeedbackHPThreshold;
    GEInt dword18C;
    GEInt dword190;
    GEInt dword194;
    GEU8 byte198;
    GEU8 f199;
    GEU8 Render_DisableHWShadowMap;
    GEU8 Render_DisableShaderCache;
    GEInt Render_Nvidia3DVisionFix;
    GEU8 byte1A0;
    GEU8 byte1A1;
    GEU8 byte1A2;
    GEU8 f1A3;
    GEInt dword1A4;
    GEInt dword1A8;
    GEU8 ColorsSetup;
    GEU8 byte1AD;
    GEU8 byte1AE;
    GEU8 byte1AF;
    GEBool CaptureCursor;
    GEU8 gap_1B1[3];
    bCString CurrentAudioLanguage;
    bCString CurrentLanguage;
    GEU8 ShowSubtitle;
    GEU8 VsyncEnabled;
    GEU8 gap1BE[34];
    bCString Difficulty;
    bCString m_DefaultFont;
    GEBool m_bDefaultFontBold;
    GEBool m_bAutoAspect;
    GEBool AlternativeBalancing;
    GEBool AlternativeAI;
    GEInt MinHitDuration;
    GEInt XPModifier;
    GEU8 QuickLoot;
    GEU8 gap1F5[25];
    GEU8 Debug_ShowMemStat;
    GEU8 Debug_SaveMemStat;
};

GE_ASSERT_SIZEOF(eSSetupEngine, 0x210)

struct eSSetupApplication
{
    GE_UNIMPL_STRUCT(eSSetupApplication)
};

class GE_DLLIMPORT eCApplication : public eCWindow
{
  public:
    struct eSDescRenderTarget
    {
        GE_UNIMPL_STRUCT(eSDescRenderTarget)
    };

    struct eSHardwareEnvironmentDesc
    {
        GE_UNIMPL_STRUCT(eSHardwareEnvironmentDesc)
    };

    // clang-format off
    public: virtual eCEntity * GetEditorEntity() const;
    public: virtual GEBool IsEditorRunning() const;
    public: virtual GEBool IsGameRunning() const;
    public: virtual bCString GetCompiledMeshPath() const;
    public: virtual bCString GetCompiledMaterialLibPath() const;
    public: virtual bCString GetCompiledAnimationPath() const;
    public: virtual bCString GetCompiledImagePath() const;
    public: virtual bCString GetCompiledPhysicPath() const;
    public: virtual void Draw(HWND);
    public: virtual void ReSize();
    protected: virtual void OnEngineCreated();
    protected: virtual void OnDestroyEngine();
    protected: virtual void OnDestroyWorkspace();
    protected: virtual void OnPostInitializeModules();
    protected: virtual bEResult OnInitializeApplication(eSSetupApplication &);
    protected: virtual bEResult OnCreateWindow(eCWindow::eSCreate &);
    protected: virtual bEResult OnInitializeEngine(eSSetupEngine &);
    protected: virtual void OnPostRender();
    protected: virtual void OnPreRender();
    protected: virtual void OnKeyboard();
    protected: virtual void OnMouse();
    protected: virtual void OnRenderDraw();
    public: virtual void OnRun();
    public: virtual void OnProcess();
    public: virtual void OnWorldActivate();
    public: virtual void OnWorldDeactivate();
    protected: virtual void CreateMainMenu();
    protected: virtual bEResult CreateWorkspace();
    protected: virtual void DestroyWorkspace();
    protected: virtual void CreateInputDevices();
    protected: virtual void CopyFrom(eCApplication const &);
    protected: virtual GEBool OnHandleMessage(GEUInt, GEUInt, GEI32, GEI32 *);
    public: virtual GEBool LoadConfigFiles();
    public: virtual GEBool SaveConfigFiles();
    public: void Destroy() override;
    protected: bEResult Create() override;
    public: ~eCApplication() override;
    protected: GEInt HandleMessage(HWND, GEUInt, GEUInt, GEI32) override;
    protected: GEInt OnIdle(GEUInt, GEI32) override;
    protected: GEInt OnSize(GEUInt, GEI32) override;
    protected: GEInt OnPaint(GEUInt, GEI32) override;
    protected: GEInt OnKillFocus(GEUInt, GEI32) override;
    protected: GEInt OnSetFocus(GEUInt, GEI32) override;
    protected: GEInt OnSysCommand(GEUInt, GEI32) override;
    // clang-format on

  public:
    using eCWindow::Create;
    using eCWindow::OnQuit;

  public:
    static void GE_STDCALL CreateSplashScreen();
    static void GE_STDCALL DestroySplashScreen();
    static eCApplication &GE_STDCALL GetInstance();
    static GEBool GE_STDCALL IsEngineCreated();
    static GEBool GE_STDCALL IsInitialised();

  public:
    eCApplication(eCApplication const &);
    eCApplication();

  public:
    void ConfineCursor();
    bEResult Create(HINSTANCE, bCString const &, bCString const &);
    void DrawTo(HWND);
    void DrawTo(HWND, eCCameraBase const &);
    void ForceDeviceReset();
    bCString GetApplicationFileName();
    bCString GetApplicationVersionString();
    GEFloat GetAverageFrameTime() const;
    bCString const &GetCommandLineA() const;
    eCConfigFile &GetConfigFile();
    eCConsole &GetConsole();
    eCCameraBase &GetCurrentCamera();
    eSSetupEngine const &GetEngineSetup() const;
    GEFloat GetFPS() const;
    void GetFileVersion(GEU32 &, GEU32 &, GEU32 &, GEU32 &);
    GEFloat GetFrameTime() const;
    GEFloat GetFrameTimeInSeconds() const;
    eSHardwareEnvironmentDesc &GetHardwareEnvironmentDesc();
    eCKeyboard &GetKeyboard();
    GEFloat GetLastFrameTime() const;
    GEFloat GetLastFrameTimeInSeconds() const;
    GEFloat GetLastScaledFrameTime() const;
    GEFloat GetLastScaledFrameTimeInSeconds() const;
    eCConfigFile &GetLocalConfigFile();
    eCMenu &GetMainMenu();
    GEU32 GetMasterFrameCounter();
    GEFloat GetMaxFPS() const;
    GEFloat GetMaxFrameTime() const;
    eCModuleAdmin &GetModuleAdmin();
    eCMouse &GetMouse();
    GEFloat GetOOFrameTime() const;
    GEFloat GetOOFrameTimeInSeconds() const;
    GEFloat GetOOScaledFrameTime() const;
    GEFloat GetOOScaledFrameTimeInSeconds() const;
    void GetOptimalCacheSizes(GEBool, GEU32 &, GEU32 &, GEU32 &, GEU32 &, GEU32 &, GEU32 &, GEU32 &);
    eSDescRenderTarget const &GetRenderTargetDesc() const;
    GEFloat GetScaledFrameTime() const;
    GEFloat GetScaledFrameTimeInSeconds() const;
    eSSetupEngine const &GetSetupEngineDesc() const;
    GEFloat GetTimeScaling() const;
    GEU32 GetTotalTime() const;
    GEFloat GetTotalTimeFloat() const;
    GEBool IsCameraValid() const;
    GEBool IsExceptionHandlingEnabled() const;
    GEBool IsInCompilingState() const;
    GEBool IsInputDeviceEnabled();
    GEBool IsPaused(GEBool);
    void PlayVideo(bCString const &);
    void Process();
    void RenderAndDrawTo(HWND, eCCameraBase const &, GEBool);
    void RenderAndDrawTo(HWND, GEBool);
    bEResult Run();
    void SetCurrentCamera(eCCameraBase const *);
    void SetFixedFPS(GEFloat);
    void SetFixedFrameTime(GEFloat);
    void SetFixedFrameTimeSingleStep(GEFloat);
    void SetIntoCompilingState(GEBool);
    void SetMaxFPS(GEFloat);
    void SetMinFPS(GEFloat);
    void SetPaused(GEBool);
    void SetTargetWindow(HWND);
    void SetTimeScaling(GEFloat);
    void SetTimerIsSmooth(GEBool);
    void SetWarmUp(GEBool);
    void ShowSplashImage(bCString const &, GEU32);
    void GE_STDCALL Snapshot(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL ToggleFullScreen(bCObjectRefBase *, bCEvent *);
    void ToggleResolution(eCGfxShared::eSGfxContextDesc const &, GEBool Windowed);

  protected:
    static GEBool ms_bEngineCreated;
    static GEBool ms_bInitialised;
    static eCApplication *ms_pApplication;
    static eCSplash *ms_pSplash;

  protected:
    static GEBool GE_STDCALL g_ErrorApplicationCall(bEErrorType, GEU32);
    static GEBool GE_STDCALL g_TerminateApplicationCall(bEErrorType, GEU32);

  protected:
    eCApplication const &operator=(eCApplication const &);

  protected:
    void CalculateHardwareEnvironment();
    void CopyTo(eCApplication &) const;
    void CreateActionMapper();
    void CreateConsole();
    bEResult CreateEngine();
    bEResult CreateGraphicsSubsystem(eSSetupEngine &, GEBool);
    void CreateInputSubsystem();
    bEResult CreateModules();
    bEResult CreateRenderTarget();
    void CreateSoundSubsystem(eSSetupEngine &);
    void DestroyActionMapper();
    void DestroyConsole();
    void DestroyEngine();
    void DestroyGraphicsSubsystem();
    void DestroyInputSubsystem();
    void DestroyMainMenu();
    void DestroyModules();
    void DestroyRenderTarget();
    void DestroySoundSubsystem();
    void DoRender(GEBool);
    void DoSnapshot();
    void Invalidate();
    void GE_STDCALL OnCaps(bCObjectRefBase *, eCConsoleEventArg *);
    void GE_STDCALL OnMenuDLLInformation(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuDebugToggleAniInfos(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuDebugToggleBoundingBoxesClicked(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuDebugToggleEntityAxesClicked(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuDebugToggleEntityNamesClicked(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuDebugToggleModelSkeletonClicked(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuDebugToggleOcclusionCullingClicked(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnMenuDebugViewChildDependenciesClicked(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnPlayAni(bCObjectRefBase *, eCConsoleEventArg *);
    void GE_STDCALL OnQuit(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnShowPosition(bCObjectRefBase *, eCConsoleEventArg *);
    void GE_STDCALL OnSpy(bCObjectRefBase *, eCConsoleEventArg *);
    void GE_STDCALL OnToggleMemDebug(bCObjectRefBase *, eCConsoleEventArg *);
    void RelaxTick(GEFloat);
    void ResetFullscreen();
    void UpdateTick();
};
