#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCAPICubeMap;
class eCAPIEffect;
class eCAPIFont;
class eCAPIHLSLShader;
class eCAPIIndexData;
class eCAPIPrimitive;
class eCAPISprite;
class eCAPITexture;
class eCAPIVertexData;
class eCAPIVolume;

using D3DMULTISAMPLE_TYPE = enum _D3DMULTISAMPLE_TYPE;

class GE_DLLIMPORT eCAPIDevice
{
  public:
    struct eSAPIMaterial
    {
        GE_UNIMPL_STRUCT(eSAPIMaterial)
    };

    struct eSAPIModeParameters
    {
        GEBool bWindowedMode;
        GEBool bEnableVsync;
        GE_PADDING(2)
        eCGfxShared::eEMultiSample MultiSampleType;
        UINT BackBufferWidth;
        UINT BackBufferHeight;
        UINT RefreshRateInHz;
        D3DFORMAT BackBufferFormat;
        eCGfxShared::eEDepthFormat AutoDepthStencilFormat;
    };

    struct eSAPIStartParameters
    {
        HWND hFocusWindow;
        DWORD BehaivorFlags;
        GEBool bWindowedMode;
        GEBool bEnableVsync;
        GE_PADDING(2)
        eCGfxShared::eEMultiSample MultiSampleType;
        UINT BackBufferWidth;
        UINT BackBufferHeight;
        UINT RefreshRateInHz;
        D3DFORMAT BackBufferFormat;
        eCGfxShared::eEDepthFormat AutoDepthStencilFormat;
    };

    struct eSImageInfo
    {
        GE_UNIMPL_STRUCT(eSImageInfo)
    };

    // clang-format off
    public: virtual bEResult CreatePrimititve(eCAPIPrimitive **) = 0;
    public: virtual bEResult CreateIndexData(eCGfxShared::eSGfxIndexBufDesc const &, eCAPIIndexData **) = 0;
    public: virtual bEResult CreateVertexData(eCGfxShared::eSGfxVertexBufDesc const &, eCAPIVertexData **) = 0;
    public: virtual bEResult CreateEffect(GELPVoid, GEUInt, eCAPIEffect **) = 0;
    public: virtual bEResult PreprocessShader(eCGfxShared::eSGfxHLSLShaderSrc const &, bCString &) = 0;
    public: virtual bEResult CreateHLSLShader(eCAPIHLSLShader **) = 0;
    public: virtual bEResult CreateTexture(eCGfxShared::eSGfxLayersDesc const &, eCAPITexture **) = 0;
    public: virtual bEResult CreateTextureFromFile(eCGfxShared::eSGfxLayersDesc &, GELPChar const, eCAPITexture **) = 0;
    public: virtual bEResult CreateCubeMapFromFile(eCGfxShared::eSGfxLayersDesc &, GELPChar const, eCAPICubeMap **) = 0;
    public: virtual bEResult CreateTextureFromMemory(eCGfxShared::eSGfxLayersDesc &, GELPVoid, GEUInt, eCAPITexture **) = 0;
    public: virtual bEResult CreateCubeMapFromMemory(eCGfxShared::eSGfxLayersDesc &, GELPVoid, GEUInt, eCAPICubeMap **) = 0;
    public: virtual bEResult CreateCubeMap(eCGfxShared::eSGfxLayersDesc const &, eCAPICubeMap **) = 0;
    public: virtual bEResult CreateVolume(eCGfxShared::eSGfxLayersDesc const &, eCAPIVolume **) = 0;
    public: virtual bEResult CreateFontA(eCGfxShared::eSFontDesc &, eCAPIFont **) = 0;
    public: virtual bEResult CreateSprite(eCGfxShared::eSSpriteDesc &, eCAPISprite **) = 0;
    public: virtual bEResult GetImageInfoFromFile(bCString const &, eSImageInfo &) = 0;
    public: virtual bEResult CheckDeviceFormat(eCGfxShared::eSGfxLayersDesc const &, GEBool) = 0;
    public: virtual bEResult ToggleNewMode(eSAPIModeParameters const &) = 0;
    public: virtual bEResult IsResetNecessary(GEBool *) = 0;
    public: virtual bEResult IsResetNeeded(GEBool *) = 0;
    public: virtual bEResult Reset() = 0;
    public: virtual bEResult EnableClipping(GEBool) = 0;
    public: virtual bEResult GetClippingEnables(GEBool &) = 0;
    public: virtual bEResult SetScissor(bCRect const &) = 0;
    public: virtual bEResult GetScissor(bCRect &) = 0;
    public: virtual bEResult EnableScissor(GEBool) = 0;
    public: virtual GEBool IsScissorEnabled() = 0;
    public: virtual bEResult SetViewport(eCGfxShared::eSGfxViewport const &) = 0;
    public: virtual bEResult GetViewport(eCGfxShared::eSGfxViewport &) = 0;
    public: virtual bEResult ClearViewport(eCGfxShared::eEViewportClear, GEU32, GEFloat, GEU32) = 0;
    public: virtual bEResult SwapScreen(HWND, bCRect const *, bCRect const *) = 0;
    public: virtual bEResult BeginScene() = 0;
    public: virtual bEResult EndScene() = 0;
    public: virtual bEResult SetMasterRenderMode(eCGfxShared::eEMasterRenderMode) = 0;
    public: virtual bEResult GetMasterRenderMode(eCGfxShared::eEMasterRenderMode *) = 0;
    public: virtual bEResult SetMasterShadeMode(eCGfxShared::eEMasterShadeMode) = 0;
    public: virtual bEResult GetMasterShadeMode(eCGfxShared::eEMasterShadeMode *) = 0;
    public: virtual bEResult SetMasterCullingMode(eCGfxShared::eEMasterCullingMode) = 0;
    public: virtual bEResult GetMasterCullingMode(eCGfxShared::eEMasterCullingMode *) = 0;
    public: virtual bEResult SetMasterDepthTesting(eCGfxShared::eEMasterCmpFunc) = 0;
    public: virtual bEResult GetMasterDepthTesting(eCGfxShared::eEMasterCmpFunc *) = 0;
    public: virtual bEResult SetMasterDepthWrite(eCGfxShared::eEMasterWrite) = 0;
    public: virtual bEResult GetMasterDepthWrite(eCGfxShared::eEMasterWrite *) = 0;
    public: virtual bEResult SetMasterDepthBias(GEBool, GEFloat, GEFloat) = 0;
    public: virtual bEResult GetMasterDepthBias(GEBool *, GEFloat *, GEFloat *) = 0;
    public: virtual bEResult SetMasterZBias(GEBool, GEU32) = 0;
    public: virtual bEResult GetMasterZBias(GEBool *, GEU32 *) = 0;
    public: virtual bEResult SetMasterStencilTesting(eCGfxShared::eEMasterStencil, eCGfxShared::eSGfxStencilData const &) = 0;
    public: virtual bEResult GetMasterStencilTesting(eCGfxShared::eEMasterStencil *, eCGfxShared::eSGfxStencilData *) = 0;
    public: virtual bEResult SetMasterBlending(eCGfxShared::eEMasterBlending, eCGfxShared::eEMasterBlending) = 0;
    public: virtual bEResult GetMasterBlending(eCGfxShared::eEMasterBlending *, eCGfxShared::eEMasterBlending *) = 0;
    public: virtual bEResult SetMasterAlphaTesting(eCGfxShared::eEMasterAlphaTest, eCGfxShared::eSGfxAlphaTestData const &) = 0;
    public: virtual bEResult GetMasterAlphaTesting(eCGfxShared::eEMasterAlphaTest *, eCGfxShared::eSGfxAlphaTestData *) = 0;
    public: virtual bEResult SetMasterFogging(eCGfxShared::eEMasterFogging) = 0;
    public: virtual bEResult GetMasterFogging(eCGfxShared::eEMasterFogging *) = 0;
    public: virtual bEResult SetLighting(GEBool) = 0;
    public: virtual bEResult GetLighting(GEBool *) = 0;
    public: virtual bEResult SetAlphaBlending(GEBool) = 0;
    public: virtual bEResult GetAlphaBlending(GEBool *) = 0;
    public: virtual bEResult SetColorWriting(GEBool) = 0;
    public: virtual bEResult GetColorWriting(GEBool *) = 0;
    public: virtual bEResult SetAlphaWriting(GEBool) = 0;
    public: virtual bEResult GetAlphaWriting(GEBool *) = 0;
    public: virtual bEResult SetSpecularEffect(GEBool) = 0;
    public: virtual bEResult GetSpecularEffect(GEBool *) = 0;
    public: virtual bEResult SetGammaRamp(GEBool, eCGfxShared::eSGfxGammaRamp const *) = 0;
    public: virtual bEResult GetGammaRamp(eCGfxShared::eSGfxGammaRamp *) = 0;
    public: virtual bEResult SetRenderMode(eCGfxShared::eERenderMode) = 0;
    public: virtual bEResult SetShadeMode(eCGfxShared::eEShadeMode) = 0;
    public: virtual bEResult SetCullingMode(eCGfxShared::eECullingMode) = 0;
    public: virtual bEResult SetDepthTesting(eCGfxShared::eECmpFunc) = 0;
    public: virtual bEResult SetDepthWrite(eCGfxShared::eEWrite) = 0;
    public: virtual bEResult SetDepthBias(GEFloat, GEFloat) = 0;
    public: virtual bEResult SetZBias(GEU32) = 0;
    public: virtual bEResult SetStencilTesting(eCGfxShared::eEStencil, eCGfxShared::eSGfxStencilData const &) = 0;
    public: virtual bEResult SetViewAndProjectionMatrices(bCMatrix const *, bCMatrix const *) = 0;
    public: virtual bEResult SetWorldMatrix(bCMatrix const *) = 0;
    public: virtual bEResult GetWorldMatrix(bCMatrix *) = 0;
    public: virtual bEResult SetViewMatrix(bCMatrix const *) = 0;
    public: virtual bEResult GetViewMatrix(bCMatrix *) = 0;
    public: virtual bEResult Draw(eCGfxShared::eSGfxDrawCallDesc const &) = 0;
    public: virtual bEResult DrawUP(eCGfxShared::eEPrimitiveType, GEUInt, GELPVoid const, GEUInt) = 0;
    public: virtual bEResult SetLights(GEU32, GEU32, GEBool const *, eCGfxShared::eSGfxLightData const *) = 0;
    public: virtual bEResult SetFog(eCGfxShared::eSGfxFogData &) = 0;
    public: virtual bEResult SetMaterial(eSAPIMaterial const *) = 0;
    public: virtual bEResult SetColorFactor(GEU32) = 0;
    public: virtual bEResult SetBlending(eCGfxShared::eEBlending, eCGfxShared::eEBlending) = 0;
    public: virtual bEResult SetAlphaTesting(eCGfxShared::eEAlphaTest, eCGfxShared::eSGfxAlphaTestData const &) = 0;
    public: virtual bEResult SetAmbientMaterialSource(eCGfxShared::eEMaterialColorSrc) = 0;
    public: virtual bEResult SetDiffuseMaterialSource(eCGfxShared::eEMaterialColorSrc) = 0;
    public: virtual bEResult SetSpecularMaterialSource(eCGfxShared::eEMaterialColorSrc) = 0;
    public: virtual bEResult SetEmissiveMaterialSource(eCGfxShared::eEMaterialColorSrc) = 0;
    public: virtual bEResult CreateVertexDeclaration(eCGfxShared::eSGfxDclElement const *, GELPVoid*) = 0;
    public: virtual bEResult DestroyVertexDeclaration(GELPVoid) = 0;
    public: virtual bEResult GetVertexDeclarationData(GELPVoid, eCGfxShared::eSGfxDclElement *, GEUInt *) = 0;
    public: virtual bEResult SetVertexDeclaration(GELPVoid) = 0;
    public: virtual bEResult CreateVertexProgram(GELPVoid, GELPVoid, GEU32 *, GEBool) = 0;
    public: virtual bEResult DestroyVertexProgram(GEU32) = 0;
    public: virtual bEResult GetVertexProgramData(GEU32, GELPVoid, GEUInt *) = 0;
    public: virtual bEResult SetVertexProgramRegisterF(GEU32, GEFloat const *, GEU32) = 0;
    public: virtual bEResult SetVertexProgramRegisterI(GEU32, GEInt const *, GEU32) = 0;
    public: virtual bEResult GetVertexProgramRegisterB(GEU32, GEInt *, GEU32) = 0;
    public: virtual bEResult GetVertexProgramRegisterF(GEU32, GEFloat *, GEU32) = 0;
    public: virtual bEResult GetVertexProgramRegisterI(GEU32, GEInt *, GEU32) = 0;
    public: virtual bEResult SetVertexProgramRegisterB(GEU32, GEInt const *, GEU32) = 0;
    public: virtual bEResult SetVertexProgram(GEU32, GEBool, GEBool) = 0;
    public: virtual bEResult CreatePixelProgram(GELPVoid, GEU32 *) = 0;
    public: virtual bEResult DestroyPixelProgram(GEU32) = 0;
    public: virtual bEResult GetPixelProgramData(GEU32, GELPVoid, GEUInt *) = 0;
    public: virtual bEResult SetPixelProgramRegisterF(GEU32, GEFloat const *, GEU32) = 0;
    public: virtual bEResult SetPixelProgramRegisterI(GEU32, GEInt const *, GEU32) = 0;
    public: virtual bEResult SetPixelProgramRegisterB(GEU32, GEInt const *, GEU32) = 0;
    public: virtual bEResult GetPixelProgramRegisterF(GEU32, GEFloat *, GEU32) = 0;
    public: virtual bEResult GetPixelProgramRegisterI(GEU32, GEInt *, GEU32) = 0;
    public: virtual bEResult GetPixelProgramRegisterB(GEU32, GEInt *, GEU32) = 0;
    public: virtual bEResult SetPixelProgram(GEU32) = 0;
    public: virtual bEResult AssembleShaderProgram(GELPChar const, GEU32, eCGfxShared::eSGfxMacro *, GELPVoid*, GELPVoid*) = 0;
    public: virtual bEResult AssembleShaderProgramFromFile(GELPCChar const, eCGfxShared::eSGfxMacro *, GELPVoid*, GELPVoid*) = 0;
    public: virtual bEResult CompileEffect(eCGfxShared::eSGfxEffectSource const &, GELPVoid*, GELPVoid*) = 0;
    public: virtual bEResult CompileEffectFromFile(eCGfxShared::eSGfxEffectFileSource const &, GELPVoid*, GELPVoid*) = 0;
    public: virtual bEResult CreateAuxBuffer(GEU32, GELPVoid*) = 0;
    public: virtual bEResult DestroyAuxBuffer(GELPVoid) = 0;
    public: virtual bEResult GetAuxBuffer(GELPVoid, GELPVoid*, GEU32 *) = 0;
    public: virtual bEResult SetTextureAdressing(GEU32, eCGfxShared::eETexAddress, eCGfxShared::eETexAddress, eCGfxShared::eETexAddress) = 0;
    public: virtual bEResult SetTextureFiltering(GEU32, eCGfxShared::eETexFilter, eCGfxShared::eETexFilter, eCGfxShared::eETexFilter) = 0;
    public: virtual bEResult SetTextureCoordinateIndexAndCalc(GEU32, GEU32, eCGfxShared::eETexCoordCalc) = 0;
    public: virtual bEResult SetSamplerState(GEU32, eCGfxShared::eESamplerState, GEU32) = 0;
    public: virtual bEResult SetTextureCoordinateTransform(GEU32, GEU32) = 0;
    public: virtual bEResult SetTextureMatrix(GEU32, bCMatrix const *) = 0;
    public: virtual bEResult SetResultArgument(GEU32, eCGfxShared::eETexArgument) = 0;
    public: virtual bEResult SetColorCalc(GEU32, eCGfxShared::eETexOperation, eCGfxShared::eETexArgument, eCGfxShared::eETexArgument) = 0;
    public: virtual bEResult SetAlphaCalc(GEU32, eCGfxShared::eETexOperation, eCGfxShared::eETexArgument, eCGfxShared::eETexArgument) = 0;
    public: virtual bEResult CreateDepthBuffer(GEU32, GEU32, eCGfxShared::eEDepthFormat, GELPVoid*) = 0;
    public: virtual bEResult DestroyDepthBuffer(GELPVoid) = 0;
    public: virtual bEResult SetRenderTarget(GELPVoid, GELPVoid, GELPVoid) = 0;
    public: virtual bEResult GetRenderTarget(GELPVoid*, GELPVoid*) = 0;
    public: virtual bEResult GetFVFSize(GEU32, GEU32 *) = 0;
    public: virtual bEResult SetClipPlane(GEU32) = 0;
    public: virtual bEResult SetClipPlaneData(GEU32, eCGfxShared::eSGfxPlaneData &) = 0;
    public: virtual bEResult GetClipPlaneData(GEU32, eCGfxShared::eSGfxPlaneData &) = 0;
    public: virtual bEResult SetTextureNULL(GEU32) = 0;
    public: virtual bEResult SetIndexDataNULL() = 0;
    public: virtual bEResult SetVertexDataNULL(GEU32) = 0;
    public: virtual bEResult GetMethodSupport(eCGfxShared::eSGfxAssistantMethods *) = 0;
    public: virtual bEResult GenerateLODMesh(eCAPIVertexData *, eCAPIIndexData *, eCGfxShared::eSGfxAttributeWeigths const &, bTValArray<GEFloat> const *, GEU32, eCAPIVertexData **, eCAPIIndexData **, GEBool) = 0;
    public: virtual bEResult CreateBox(eCGfxShared::eSGfxBoxData const &, eCAPIVertexData **, eCAPIIndexData **) = 0;
    public: virtual bEResult CreateCylinder(eCGfxShared::eSGfxCylinderData const &, eCAPIVertexData **, eCAPIIndexData **) = 0;
    public: virtual bEResult CreatePolygon(eCGfxShared::eSGfxPolygonData const &, eCAPIVertexData **, eCAPIIndexData **) = 0;
    public: virtual bEResult CreateSphere(eCGfxShared::eSGfxSphereData const &, eCAPIVertexData **, eCAPIIndexData **) = 0;
    public: virtual bEResult CreateTeapot(eCAPIVertexData **, eCAPIIndexData **) = 0;
    public: virtual bEResult CreateText(eCGfxShared::eSGfxTextData const &, eCAPIVertexData **, eCAPIIndexData **) = 0;
    public: virtual bEResult CreateTorus(eCGfxShared::eSGfxTorusData const &, eCAPIVertexData **, eCAPIIndexData **) = 0;
    public: virtual bEResult SaveBackbufferToFile(GELPChar const) = 0;
    public: virtual bEResult SaveBackbufferToMemory(bCMemoryStream &) = 0;
    public: virtual bEResult DrawTextA(GELPCChar const, GEU32, bCRect const &) = 0;
    public: virtual bEResult CreateOcclusionQuery(GELPVoid&) = 0;
    public: virtual bEResult DestroyOcclusionQuery(GELPVoid const) = 0;
    public: virtual bEResult BeginOcclusionTest(GELPVoid const) = 0;
    public: virtual bEResult EndOcclusionTest(GELPVoid const) = 0;
    public: virtual bEResult GetOcclusionTestInfo(GELPVoid const, GEU32 &, GEBool) = 0;
    public: virtual void EnableOptimization() = 0;
    public: virtual void DisableOptimization() = 0;
    public: virtual void SetForceLowestMipMapLevel(GEBool) = 0;
    public: virtual GEBool GetForceLowestMipMapLevel() = 0;
    public: virtual bEResult BeginSpriteList(eCGfxShared::eESpriteRenderOpt) = 0;
    public: virtual bEResult EndSpriteList() = 0;
    public: virtual bEResult FlushSpriteList() = 0;
    public: virtual bEResult SetSpriteListTransform(bCMatrix const &) = 0;
    public: virtual bEResult GetSpriteListTransform(bCMatrix &) = 0;
    public: virtual bEResult AddSpriteToSpriteList(eCAPITexture *, bCRect const *, bCVector const *, bCVector const *, GEU32) = 0;
    public: virtual GEInt CalcTextRect(eCAPIFont *, GELPCChar, GEInt, bCRect &, GEU32) = 0;
    public: virtual GEInt CalcTextRect(eCAPIFont *, GELPCUnicodeChar, GEInt, bCRect &, GEU32) = 0;
    public: virtual GEInt DrawTextViaSpriteList(eCAPIFont *, bCString const &, GEInt, bCRect const *, GEU32, GEU32) = 0;
    public: virtual GEInt DrawTextViaSpriteList(eCAPIFont *, bCUnicodeString const &, GEInt, bCRect const *, GEU32, GEU32) = 0;
    public: virtual void SetEffectCreateCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetTextureCreateCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetCubemapCreateCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetVolumeCreateCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetVertexBufferCreateCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetIndexBufferCreateCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetVertexShaderCreateCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetPixelShaderCreateCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetTextureLockCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetCubemapLockCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetVolumeLockCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetVertexBufferLockCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetIndexBufferLockCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetRenderStateActCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetTextureStageStateActCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetSamplerStateActCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetEffectActCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetTextureActCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetCubemapActCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetVolumeActCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetVertexShaderActCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetPixelShaderActCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetRenderTargetActCallback(void (GE_STDCALL *)()) = 0;
    public: virtual void SetDrawCallback(void (GE_STDCALL *)()) = 0;
    public: virtual GEU32 GetDrawnVisualVertices() const = 0;
    public: virtual GEU32 GetDrawnVisualIndices() const = 0;
    public: virtual GEU32 GetNumDrawCalls() const = 0;
    public: virtual bEResult CreateUVAtlas(bTValArray<bCVector> const &, bTValArray<GEU32> &, bTValArray<bCVector2> &, bTValArray<GEU32> &, bTValArray<GEU32> &, GEFloat) = 0;
    public: virtual ~eCAPIDevice();
    // clang-format on

  public:
    eCAPIDevice(eCAPIDevice const &);

  public:
    eCAPIDevice &operator=(eCAPIDevice const &);

  public:
    GEU32 AddRef();
    GEU32 Release();

  protected:
    eCAPIDevice();

  private:
    GEU32 m_u32ReferenceCount;
};

GE_ASSERT_SIZEOF(eCAPIDevice, 8)
