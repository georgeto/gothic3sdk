#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCGfxGaugeAdmin : public bCObjectRefBase
{
    // clang-format off
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxGaugeAdmin() override;
    // clang-format on

  public:
    eCGfxGaugeAdmin(eCGfxGaugeAdmin const &);

  public:
    eCGfxGaugeAdmin &operator=(eCGfxGaugeAdmin const &);

  public:
    bEResult GetValues(eCGfxShared::eSGfxGaugeValues &) const;
    void Invalidate();
    bEResult Reset();
    bEResult SetModus(eCGfxShared::eEGaugeModus);

  protected:
    static eCGfxShared::eSGfxGaugeValues ms_Values;

  protected:
    static void GE_STDCALL sAddPolys(GEU32);
    static void GE_STDCALL sRegisterCameraExecuteCall();
    static void GE_STDCALL sRegisterCameraStatesExecuteCall();
    static void GE_STDCALL sRegisterCubemapCreate();
    static void GE_STDCALL sRegisterCubemapLock();
    static void GE_STDCALL sRegisterCubemapSwitch();
    static void GE_STDCALL sRegisterDrawCall();
    static void GE_STDCALL sRegisterEffectCreate();
    static void GE_STDCALL sRegisterEffectExecuteCall();
    static void GE_STDCALL sRegisterEffectSwitch();
    static void GE_STDCALL sRegisterFogExecuteCall();
    static void GE_STDCALL sRegisterFontExecuteCall();
    static void GE_STDCALL sRegisterImageAVIDataExecuteCall();
    static void GE_STDCALL sRegisterImageDataExecuteCall();
    static void GE_STDCALL sRegisterIndexBufferCreate();
    static void GE_STDCALL sRegisterIndexBufferLock();
    static void GE_STDCALL sRegisterIndexBufferSwitch();
    static void GE_STDCALL sRegisterLightExecuteCall();
    static void GE_STDCALL sRegisterMaterialExecuteCall();
    static void GE_STDCALL sRegisterPixelProgramExecuteCall();
    static void GE_STDCALL sRegisterPixelShaderCreate();
    static void GE_STDCALL sRegisterPixelShaderSwitch();
    static void GE_STDCALL sRegisterRenderStateSwitch();
    static void GE_STDCALL sRegisterRenderTargetSwitch();
    static void GE_STDCALL sRegisterSamplerStateSwitch();
    static void GE_STDCALL sRegisterScreenSwapCall();
    static void GE_STDCALL sRegisterShaderExecuteCall();
    static void GE_STDCALL sRegisterTextureBlockExecuteCall();
    static void GE_STDCALL sRegisterTextureCreate();
    static void GE_STDCALL sRegisterTextureLock();
    static void GE_STDCALL sRegisterTextureStageStateSwitch();
    static void GE_STDCALL sRegisterTextureSwitch();
    static void GE_STDCALL sRegisterVertexBufferCreate();
    static void GE_STDCALL sRegisterVertexBufferLock();
    static void GE_STDCALL sRegisterVertexBufferSwitch();
    static void GE_STDCALL sRegisterVertexProgramExecuteCall();
    static void GE_STDCALL sRegisterVertexShaderCreate();
    static void GE_STDCALL sRegisterVertexShaderSwitch();
    static void GE_STDCALL sRegisterViewportClearCall();
    static void GE_STDCALL sRegisterVolumeCreate();
    static void GE_STDCALL sRegisterVolumeLock();
    static void GE_STDCALL sRegisterVolumeSwitch();

  protected:
    eCGfxGaugeAdmin();

  protected:
    void InitializeGauge();
};
