#pragma once

#include <Engine/api/ge_apidevice.h>
#include <Engine/ge_d3d.h>
#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCDX9Font;
class eCDX9Sprite;
struct IDirect3DSurface9;
struct IDirect3DVertexDeclaration9;
struct _D3DVERTEXELEMENT9;

class GE_DLLIMPORT eCDX9Device : public eCAPIDevice
{
  public:
    struct bSStateCache
    {
        GE_UNIMPL_STRUCT(bSStateCache)
    };

    struct eSCachedVertexDeclaration
    {
        IDirect3DVertexDeclaration9 *m_pHandle;
        GEUInt ElementCount;
        const struct _D3DVERTEXELEMENT9 *arrElements;
    };
    GE_ASSERT_SIZEOF(eSCachedVertexDeclaration, 0xc)

    // clang-format off
    public: virtual void SetFontCreateCallback(void (GE_STDCALL *)());
    public: virtual void SetSpriteCreateCallback(void (GE_STDCALL *)());
    public: bEResult CreatePrimititve(eCAPIPrimitive **) override;
    public: bEResult CreateIndexData(eCGfxShared::eSGfxIndexBufDesc const &, eCAPIIndexData **) override;
    public: bEResult CreateVertexData(eCGfxShared::eSGfxVertexBufDesc const &, eCAPIVertexData **) override;
    public: bEResult CreateEffect(GELPVoid, GEUInt, eCAPIEffect **) override;
    public: bEResult PreprocessShader(eCGfxShared::eSGfxHLSLShaderSrc const &, bCString &) override;
    public: bEResult CreateHLSLShader(eCAPIHLSLShader **) override;
    public: bEResult CreateTexture(eCGfxShared::eSGfxLayersDesc const &, eCAPITexture **) override;
    public: bEResult CreateTextureFromFile(eCGfxShared::eSGfxLayersDesc &, GELPChar const, eCAPITexture **) override;
    public: bEResult CreateCubeMapFromFile(eCGfxShared::eSGfxLayersDesc &, GELPChar const, eCAPICubeMap **) override;
    public: bEResult CreateTextureFromMemory(eCGfxShared::eSGfxLayersDesc &, GELPVoid, GEUInt, eCAPITexture **) override;
    public: bEResult CreateCubeMapFromMemory(eCGfxShared::eSGfxLayersDesc &, GELPVoid, GEUInt, eCAPICubeMap **) override;
    public: bEResult CreateCubeMap(eCGfxShared::eSGfxLayersDesc const &, eCAPICubeMap **) override;
    public: bEResult CreateVolume(eCGfxShared::eSGfxLayersDesc const &, eCAPIVolume **) override;
    public: bEResult CreateFontA(eCGfxShared::eSFontDesc &, eCAPIFont **) override;
    public: bEResult CreateSprite(eCGfxShared::eSSpriteDesc &, eCAPISprite **) override;
    public: bEResult GetImageInfoFromFile(bCString const &, eCAPIDevice::eSImageInfo &) override;
    public: bEResult CheckDeviceFormat(eCGfxShared::eSGfxLayersDesc const &, GEBool) override;
    public: bEResult ToggleNewMode(eCAPIDevice::eSAPIModeParameters const &) override;
    public: bEResult IsResetNecessary(GEBool *) override;
    public: bEResult IsResetNeeded(GEBool *) override;
    public: bEResult Reset() override;
    public: bEResult EnableClipping(GEBool) override;
    public: bEResult GetClippingEnables(GEBool &) override;
    public: bEResult SetScissor(bCRect const &) override;
    public: bEResult GetScissor(bCRect &) override;
    public: bEResult EnableScissor(GEBool) override;
    public: GEBool IsScissorEnabled() override;
    public: bEResult SetViewport(eCGfxShared::eSGfxViewport const &) override;
    public: bEResult GetViewport(eCGfxShared::eSGfxViewport &) override;
    public: bEResult ClearViewport(eCGfxShared::eEViewportClear, GEU32, GEFloat, GEU32) override;
    public: bEResult SwapScreen(HWND, bCRect const *, bCRect const *) override;
    public: bEResult BeginScene() override;
    public: bEResult EndScene() override;
    public: bEResult SetMasterRenderMode(eCGfxShared::eEMasterRenderMode) override;
    public: bEResult GetMasterRenderMode(eCGfxShared::eEMasterRenderMode *) override;
    public: bEResult SetMasterShadeMode(eCGfxShared::eEMasterShadeMode) override;
    public: bEResult GetMasterShadeMode(eCGfxShared::eEMasterShadeMode *) override;
    public: bEResult SetMasterCullingMode(eCGfxShared::eEMasterCullingMode) override;
    public: bEResult GetMasterCullingMode(eCGfxShared::eEMasterCullingMode *) override;
    public: bEResult SetMasterDepthTesting(eCGfxShared::eEMasterCmpFunc) override;
    public: bEResult GetMasterDepthTesting(eCGfxShared::eEMasterCmpFunc *) override;
    public: bEResult SetMasterDepthWrite(eCGfxShared::eEMasterWrite) override;
    public: bEResult GetMasterDepthWrite(eCGfxShared::eEMasterWrite *) override;
    public: bEResult SetMasterDepthBias(GEBool, GEFloat, GEFloat) override;
    public: bEResult GetMasterDepthBias(GEBool *, GEFloat *, GEFloat *) override;
    public: bEResult SetMasterZBias(GEBool, GEU32) override;
    public: bEResult GetMasterZBias(GEBool *, GEU32 *) override;
    public: bEResult SetMasterStencilTesting(eCGfxShared::eEMasterStencil, eCGfxShared::eSGfxStencilData const &) override;
    public: bEResult GetMasterStencilTesting(eCGfxShared::eEMasterStencil *, eCGfxShared::eSGfxStencilData *) override;
    public: bEResult SetMasterBlending(eCGfxShared::eEMasterBlending, eCGfxShared::eEMasterBlending) override;
    public: bEResult GetMasterBlending(eCGfxShared::eEMasterBlending *, eCGfxShared::eEMasterBlending *) override;
    public: bEResult SetMasterAlphaTesting(eCGfxShared::eEMasterAlphaTest, eCGfxShared::eSGfxAlphaTestData const &) override;
    public: bEResult GetMasterAlphaTesting(eCGfxShared::eEMasterAlphaTest *, eCGfxShared::eSGfxAlphaTestData *) override;
    public: bEResult SetMasterFogging(eCGfxShared::eEMasterFogging) override;
    public: bEResult GetMasterFogging(eCGfxShared::eEMasterFogging *) override;
    public: bEResult SetLighting(GEBool) override;
    public: bEResult GetLighting(GEBool *) override;
    public: bEResult SetAlphaBlending(GEBool) override;
    public: bEResult GetAlphaBlending(GEBool *) override;
    public: bEResult SetColorWriting(GEBool) override;
    public: bEResult GetColorWriting(GEBool *) override;
    public: bEResult SetAlphaWriting(GEBool) override;
    public: bEResult GetAlphaWriting(GEBool *) override;
    public: bEResult SetSpecularEffect(GEBool) override;
    public: bEResult GetSpecularEffect(GEBool *) override;
    public: bEResult SetGammaRamp(GEBool, eCGfxShared::eSGfxGammaRamp const *) override;
    public: bEResult GetGammaRamp(eCGfxShared::eSGfxGammaRamp *) override;
    public: bEResult SetRenderMode(eCGfxShared::eERenderMode) override;
    public: bEResult SetShadeMode(eCGfxShared::eEShadeMode) override;
    public: bEResult SetCullingMode(eCGfxShared::eECullingMode) override;
    public: bEResult SetDepthTesting(eCGfxShared::eECmpFunc) override;
    public: bEResult SetDepthWrite(eCGfxShared::eEWrite) override;
    public: bEResult SetDepthBias(GEFloat, GEFloat) override;
    public: bEResult SetZBias(GEU32) override;
    public: bEResult SetStencilTesting(eCGfxShared::eEStencil, eCGfxShared::eSGfxStencilData const &) override;
    public: bEResult SetViewAndProjectionMatrices(bCMatrix const *, bCMatrix const *) override;
    public: bEResult SetWorldMatrix(bCMatrix const *) override;
    public: bEResult GetWorldMatrix(bCMatrix *) override;
    public: bEResult SetViewMatrix(bCMatrix const *) override;
    public: bEResult GetViewMatrix(bCMatrix *) override;
    public: bEResult Draw(eCGfxShared::eSGfxDrawCallDesc const &) override;
    public: bEResult DrawUP(eCGfxShared::eEPrimitiveType, GEUInt, GELPVoid const, GEUInt) override;
    public: bEResult SetLights(GEU32, GEU32, GEBool const *, eCGfxShared::eSGfxLightData const *) override;
    public: bEResult SetFog(eCGfxShared::eSGfxFogData &) override;
    public: bEResult SetMaterial(eCAPIDevice::eSAPIMaterial const *) override;
    public: bEResult SetColorFactor(GEU32) override;
    public: bEResult SetBlending(eCGfxShared::eEBlending, eCGfxShared::eEBlending) override;
    public: bEResult SetAlphaTesting(eCGfxShared::eEAlphaTest, eCGfxShared::eSGfxAlphaTestData const &) override;
    public: bEResult SetAmbientMaterialSource(eCGfxShared::eEMaterialColorSrc) override;
    public: bEResult SetDiffuseMaterialSource(eCGfxShared::eEMaterialColorSrc) override;
    public: bEResult SetSpecularMaterialSource(eCGfxShared::eEMaterialColorSrc) override;
    public: bEResult SetEmissiveMaterialSource(eCGfxShared::eEMaterialColorSrc) override;
    public: bEResult CreateVertexDeclaration(eCGfxShared::eSGfxDclElement const *, GELPVoid*) override;
    public: bEResult DestroyVertexDeclaration(GELPVoid) override;
    public: bEResult GetVertexDeclarationData(GELPVoid, eCGfxShared::eSGfxDclElement *, GEUInt *) override;
    public: bEResult SetVertexDeclaration(GELPVoid) override;
    public: bEResult CreateVertexProgram(GELPVoid, GELPVoid, GEU32 *, GEBool) override;
    public: bEResult DestroyVertexProgram(GEU32) override;
    public: bEResult GetVertexProgramData(GEU32, GELPVoid, GEUInt *) override;
    public: bEResult SetVertexProgramRegisterF(GEU32, GEFloat const *, GEU32) override;
    public: bEResult SetVertexProgramRegisterI(GEU32, GEInt const *, GEU32) override;
    public: bEResult GetVertexProgramRegisterB(GEU32, GEInt *, GEU32) override;
    public: bEResult GetVertexProgramRegisterF(GEU32, GEFloat *, GEU32) override;
    public: bEResult GetVertexProgramRegisterI(GEU32, GEInt *, GEU32) override;
    public: bEResult SetVertexProgramRegisterB(GEU32, GEInt const *, GEU32) override;
    public: bEResult SetVertexProgram(GEU32, GEBool, GEBool) override;
    public: bEResult CreatePixelProgram(GELPVoid, GEU32 *) override;
    public: bEResult DestroyPixelProgram(GEU32) override;
    public: bEResult GetPixelProgramData(GEU32, GELPVoid, GEUInt *) override;
    public: bEResult SetPixelProgramRegisterF(GEU32, GEFloat const *, GEU32) override;
    public: bEResult SetPixelProgramRegisterI(GEU32, GEInt const *, GEU32) override;
    public: bEResult SetPixelProgramRegisterB(GEU32, GEInt const *, GEU32) override;
    public: bEResult GetPixelProgramRegisterF(GEU32, GEFloat *, GEU32) override;
    public: bEResult GetPixelProgramRegisterI(GEU32, GEInt *, GEU32) override;
    public: bEResult GetPixelProgramRegisterB(GEU32, GEInt *, GEU32) override;
    public: bEResult SetPixelProgram(GEU32) override;
    public: bEResult AssembleShaderProgram(GELPChar const, GEU32, eCGfxShared::eSGfxMacro *, GELPVoid*, GELPVoid*) override;
    public: bEResult AssembleShaderProgramFromFile(GELPCChar const, eCGfxShared::eSGfxMacro *, GELPVoid*, GELPVoid*) override;
    public: bEResult CompileEffect(eCGfxShared::eSGfxEffectSource const &, GELPVoid*, GELPVoid*) override;
    public: bEResult CompileEffectFromFile(eCGfxShared::eSGfxEffectFileSource const &, GELPVoid*, GELPVoid*) override;
    public: bEResult CreateAuxBuffer(GEU32, GELPVoid*) override;
    public: bEResult DestroyAuxBuffer(GELPVoid) override;
    public: bEResult GetAuxBuffer(GELPVoid, GELPVoid*, GEU32 *) override;
    public: bEResult SetTextureAdressing(GEU32, eCGfxShared::eETexAddress, eCGfxShared::eETexAddress, eCGfxShared::eETexAddress) override;
    public: bEResult SetTextureFiltering(GEU32, eCGfxShared::eETexFilter, eCGfxShared::eETexFilter, eCGfxShared::eETexFilter) override;
    public: bEResult SetTextureCoordinateIndexAndCalc(GEU32, GEU32, eCGfxShared::eETexCoordCalc) override;
    public: bEResult SetSamplerState(GEU32, eCGfxShared::eESamplerState, GEU32) override;
    public: bEResult SetTextureCoordinateTransform(GEU32, GEU32) override;
    public: bEResult SetTextureMatrix(GEU32, bCMatrix const *) override;
    public: bEResult SetResultArgument(GEU32, eCGfxShared::eETexArgument) override;
    public: bEResult SetColorCalc(GEU32, eCGfxShared::eETexOperation, eCGfxShared::eETexArgument, eCGfxShared::eETexArgument) override;
    public: bEResult SetAlphaCalc(GEU32, eCGfxShared::eETexOperation, eCGfxShared::eETexArgument, eCGfxShared::eETexArgument) override;
    public: bEResult CreateDepthBuffer(GEU32, GEU32, eCGfxShared::eEDepthFormat, GELPVoid*) override;
    public: bEResult DestroyDepthBuffer(GELPVoid) override;
    public: bEResult SetRenderTarget(GELPVoid, GELPVoid, GELPVoid) override;
    public: bEResult GetRenderTarget(GELPVoid*, GELPVoid*) override;
    public: bEResult GetFVFSize(GEU32, GEU32 *) override;
    public: bEResult SetClipPlane(GEU32) override;
    public: bEResult SetClipPlaneData(GEU32, eCGfxShared::eSGfxPlaneData &) override;
    public: bEResult GetClipPlaneData(GEU32, eCGfxShared::eSGfxPlaneData &) override;
    public: bEResult SetTextureNULL(GEU32) override;
    public: bEResult SetIndexDataNULL() override;
    public: bEResult SetVertexDataNULL(GEU32) override;
    public: bEResult GetMethodSupport(eCGfxShared::eSGfxAssistantMethods *) override;
    public: bEResult GenerateLODMesh(eCAPIVertexData *, eCAPIIndexData *, eCGfxShared::eSGfxAttributeWeigths const &, bTValArray<GEFloat> const *, GEU32, eCAPIVertexData **, eCAPIIndexData **, GEBool) override;
    public: bEResult CreateBox(eCGfxShared::eSGfxBoxData const &, eCAPIVertexData **, eCAPIIndexData **) override;
    public: bEResult CreateCylinder(eCGfxShared::eSGfxCylinderData const &, eCAPIVertexData **, eCAPIIndexData **) override;
    public: bEResult CreatePolygon(eCGfxShared::eSGfxPolygonData const &, eCAPIVertexData **, eCAPIIndexData **) override;
    public: bEResult CreateSphere(eCGfxShared::eSGfxSphereData const &, eCAPIVertexData **, eCAPIIndexData **) override;
    public: bEResult CreateTeapot(eCAPIVertexData **, eCAPIIndexData **) override;
    public: bEResult CreateText(eCGfxShared::eSGfxTextData const &, eCAPIVertexData **, eCAPIIndexData **) override;
    public: bEResult CreateTorus(eCGfxShared::eSGfxTorusData const &, eCAPIVertexData **, eCAPIIndexData **) override;
    public: bEResult SaveBackbufferToFile(GELPChar const) override;
    public: bEResult SaveBackbufferToMemory(bCMemoryStream &) override;
    public: bEResult DrawTextA(GELPCChar const, GEU32, bCRect const &) override;
    public: bEResult CreateOcclusionQuery(GELPVoid&) override;
    public: bEResult DestroyOcclusionQuery(GELPVoid const) override;
    public: bEResult BeginOcclusionTest(GELPVoid const) override;
    public: bEResult EndOcclusionTest(GELPVoid const) override;
    public: bEResult GetOcclusionTestInfo(GELPVoid const, GEU32 &, GEBool) override;
    public: void EnableOptimization() override;
    public: void DisableOptimization() override;
    public: void SetForceLowestMipMapLevel(GEBool) override;
    public: GEBool GetForceLowestMipMapLevel() override;
    public: bEResult BeginSpriteList(eCGfxShared::eESpriteRenderOpt) override;
    public: bEResult EndSpriteList() override;
    public: bEResult FlushSpriteList() override;
    public: bEResult SetSpriteListTransform(bCMatrix const &) override;
    public: bEResult GetSpriteListTransform(bCMatrix &) override;
    public: bEResult AddSpriteToSpriteList(eCAPITexture *, bCRect const *, bCVector const *, bCVector const *, GEU32) override;
    public: GEInt CalcTextRect(eCAPIFont *, GELPCChar, GEInt, bCRect &, GEU32) override;
    public: GEInt CalcTextRect(eCAPIFont *, GELPCUnicodeChar, GEInt, bCRect &, GEU32) override;
    public: GEInt DrawTextViaSpriteList(eCAPIFont *, bCString const &, GEInt, bCRect const *, GEU32, GEU32) override;
    public: GEInt DrawTextViaSpriteList(eCAPIFont *, bCUnicodeString const &, GEInt, bCRect const *, GEU32, GEU32) override;
    public: void SetEffectCreateCallback(void (GE_STDCALL *)()) override;
    public: void SetTextureCreateCallback(void (GE_STDCALL *)()) override;
    public: void SetCubemapCreateCallback(void (GE_STDCALL *)()) override;
    public: void SetVolumeCreateCallback(void (GE_STDCALL *)()) override;
    public: void SetVertexBufferCreateCallback(void (GE_STDCALL *)()) override;
    public: void SetIndexBufferCreateCallback(void (GE_STDCALL *)()) override;
    public: void SetVertexShaderCreateCallback(void (GE_STDCALL *)()) override;
    public: void SetPixelShaderCreateCallback(void (GE_STDCALL *)()) override;
    public: void SetTextureLockCallback(void (GE_STDCALL *)()) override;
    public: void SetCubemapLockCallback(void (GE_STDCALL *)()) override;
    public: void SetVolumeLockCallback(void (GE_STDCALL *)()) override;
    public: void SetVertexBufferLockCallback(void (GE_STDCALL *)()) override;
    public: void SetIndexBufferLockCallback(void (GE_STDCALL *)()) override;
    public: void SetRenderStateActCallback(void (GE_STDCALL *)()) override;
    public: void SetTextureStageStateActCallback(void (GE_STDCALL *)()) override;
    public: void SetSamplerStateActCallback(void (GE_STDCALL *)()) override;
    public: void SetEffectActCallback(void (GE_STDCALL *)()) override;
    public: void SetTextureActCallback(void (GE_STDCALL *)()) override;
    public: void SetCubemapActCallback(void (GE_STDCALL *)()) override;
    public: void SetVolumeActCallback(void (GE_STDCALL *)()) override;
    public: void SetVertexShaderActCallback(void (GE_STDCALL *)()) override;
    public: void SetPixelShaderActCallback(void (GE_STDCALL *)()) override;
    public: void SetRenderTargetActCallback(void (GE_STDCALL *)()) override;
    public: void SetDrawCallback(void (GE_STDCALL *)()) override;
    public: GEU32 GetDrawnVisualVertices() const override;
    public: GEU32 GetDrawnVisualIndices() const override;
    public: GEU32 GetNumDrawCalls() const override;
    public: bEResult CreateUVAtlas(bTValArray<bCVector> const &, bTValArray<GEU32> &, bTValArray<bCVector2> &, bTValArray<GEU32> &, bTValArray<GEU32> &, GEFloat) override;
    public: ~eCDX9Device() override;
    // clang-format on

  public:
    eCDX9Device(eCDX9Device const &);

  public:
    eCDX9Device &operator=(eCDX9Device const &);

  protected:
    static bSStateCache ms_ActiveStates;
    static bSStateCache ms_CachedStates;
    static _D3DPRESENT_PARAMETERS_ ms_PresentationParameters;
    static IDirect3D9 *ms_p3DBase;
    static void(GE_STDCALL *ms_pRegCubemapCreate)();
    static void(GE_STDCALL *ms_pRegDrawCall)();
    static void(GE_STDCALL *ms_pRegEffectCreate)();
    static void(GE_STDCALL *ms_pRegFontCreate)();
    static void(GE_STDCALL *ms_pRegIndexBufferCreate)();
    static void(GE_STDCALL *ms_pRegPixelShaderCreate)();
    static void(GE_STDCALL *ms_pRegPixelShaderSwitch)();
    static void(GE_STDCALL *ms_pRegRenderStateSwitch)();
    static void(GE_STDCALL *ms_pRegRenderTargetSwitch)();
    static void(GE_STDCALL *ms_pRegSamplerStateSwitch)();
    static void(GE_STDCALL *ms_pRegSpriteCreate)();
    static void(GE_STDCALL *ms_pRegTextureCreate)();
    static void(GE_STDCALL *ms_pRegTextureStageStateSwitch)();
    static void(GE_STDCALL *ms_pRegVertexBufferCreate)();
    static void(GE_STDCALL *ms_pRegVertexShaderCreate)();
    static void(GE_STDCALL *ms_pRegVertexShaderSwitch)();
    static void(GE_STDCALL *ms_pRegVolumeCreate)();
    static GEU32 ms_u32DrawnVisualIndices;
    static GEU32 ms_u32DrawnVisualVertices;
    static GEU32 ms_u32NumDrawCalls;

  protected:
    static bEResult GE_STDCALL sCreateDevice(GEU32, eCAPIDevice::eSAPIStartParameters const &, eCAPIDevice **);
    static void GE_STDCALL sFinit();
    static bEResult GE_STDCALL sGetAdapterCount(GEU32 *);
    static bEResult GE_STDCALL sGetAdapterDesc(GEU32, eCGfxShared::eSGfxAdapterDesc *);
    static bEResult GE_STDCALL sGetAdapterDisplayMode(GEU32, eCGfxShared::eSGfxModeDesc *);
    static bEResult GE_STDCALL sGetModeCount(GEU32, GEU32 *);
    static bEResult GE_STDCALL sGetModeDesc(GEU32, GEU32, eCGfxShared::eSGfxModeDesc *);
    static void GE_STDCALL sInit();
    static void GE_STDCALL sOPTSetIndices(IDirect3DIndexBuffer9 *);
    static void GE_STDCALL sOPTSetStreamSource(GEU32, IDirect3DVertexBuffer9 *, GEU32, GEU32);
    static void GE_STDCALL sOPTSetTexture(GEU32, IDirect3DBaseTexture9 *);

  protected:
    explicit eCDX9Device(IDirect3DDevice9 *);

  protected:
    bEResult ActivateAlphaTesting(eCGfxShared::eEAlphaTest, eCGfxShared::eSGfxAlphaTestData const &);
    bEResult ActivateBlending(eCGfxShared::eEBlending, eCGfxShared::eEBlending);
    bEResult ActivateCullingMode(eCGfxShared::eECullingMode);
    bEResult ActivateDepthBias(GEFloat, GEFloat);
    bEResult ActivateDepthTesting(eCGfxShared::eECmpFunc);
    bEResult ActivateDepthWrite(eCGfxShared::eEWrite);
    bEResult ActivateRenderMode(eCGfxShared::eERenderMode);
    bEResult ActivateShadeMode(eCGfxShared::eEShadeMode);
    bEResult ActivateStencilTesting(eCGfxShared::eEStencil, eCGfxShared::eSGfxStencilData const &);
    void AddFontWrapper(eCDX9Font *);
    void AddSpriteWrapper(eCDX9Sprite *);
    void CreateQuery(GELPVoid &);
    void DestroyQuery(GELPVoid const);
    void RemoveFontWrapper(eCDX9Font *);
    void RemoveSpriteWrapper(eCDX9Sprite *);
    void ResetCachedStates();

  public:
    struct IDirect3DDevice9 *m_pDevice;
    int m_pConstructorFont;
    struct D3DXSPRITE *m_pConstructorSprite;
    struct ID3DXEffectPool *m_pEffectPool;
    GE_UNIMPL_MEMBERS(9)
    GEBool m_bMasterFogDisabled;
    GE_UNIMPL_MEMBERS(2)
    IDirect3DSurface9 *m_pRenderTarget0;
    IDirect3DSurface9 *m_pDepthStencilSurface;
    IDirect3DSurface9 *m_pRenderTarget1;
    GEBool m_bOptimizationEnabled;
    GE_PADDING(3)
    bTSmallArray<eCDX9Sprite *> m_arrSpriteWrappers;
    bTSmallArray<eCDX9Font *> m_arrFontWrappers;
    GE_UNIMPL_MEMBERS(16)
    bTObjArray<eSCachedVertexDeclaration> m_arrVertexDeclarations;
    GEUInt m_uSceneBeginEndBalanceCounter;
    bool m_bCanUseTwoRenderTargets;
};

GE_ASSERT_SIZEOF(eCDX9Device, 0x68)
