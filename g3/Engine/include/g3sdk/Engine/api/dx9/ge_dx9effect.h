#pragma once

#include <Engine/api/ge_apieffect.h>

struct ID3DXEffectPool;
struct IDirect3DDevice9;

class GE_DLLIMPORT eCDX9Effect : public eCAPIEffect
{
    // clang-format off
    public: bEResult OnResetDevice() override;
    public: bEResult OnLostDevice() override;
    public: bEResult SetTexture(GELPVoid const, eCAPITexture *) override;
    public: bEResult SetCubeMap(GELPVoid const, eCAPICubeMap *) override;
    public: bEResult SetVolume(GELPVoid const, eCAPIVolume *) override;
    public: bEResult SetParameter(GELPVoid const, GELPVoid const, GEUInt) override;
    public: bEResult GetParameter(GELPVoid const, GELPVoid const, GEUInt) override;
    public: bEResult SetBoolArray(GELPVoid const, GELPVoid const, GEUInt) override;
    public: bEResult GetBoolArray(GELPVoid const, GELPVoid const, GEUInt) override;
    public: bEResult SetFloatArray(GELPVoid const, GELPVoid const, GEUInt) override;
    public: bEResult GetFloatArray(GELPVoid const, GELPVoid const, GEUInt) override;
    public: bEResult SetIntArray(GELPVoid const, GELPVoid const, GEUInt) override;
    public: bEResult GetIntArray(GELPVoid const, GELPVoid const, GEUInt) override;
    public: bEResult SetMatrixArray(GELPVoid const, GELPVoid const, GEUInt) override;
    public: bEResult GetMatrixArray(GELPVoid const, GELPVoid const, GEUInt) override;
    public: bEResult SetMatrixTransposeArray(GELPVoid const, GELPVoid const, GEUInt) override;
    public: bEResult GetMatrixTransposeArray(GELPVoid const, GELPVoid const, GEUInt) override;
    public: bEResult SetVectorArray(GELPVoid const, GELPVoid const, GEUInt) override;
    public: bEResult GetVectorArray(GELPVoid const, GELPVoid const, GEUInt) override;
    public: bEResult GetEffectDescription(eCGfxShared::eSGfxEffectDesc &) override;
    public: bEResult GetParameterDescription(GEUInt, eCGfxShared::eSGfxParameterDesc &) override;
    public: bEResult GetTechniqueDescription(GEUInt, eCGfxShared::eSGfxTechniqueDesc &) override;
    public: bEResult IsParameterUsed(GELPVoid const, GELPVoid const, GEBool &) override;
    public: bEResult SetTechnique(GELPVoid const) override;
    public: bEResult SetPassNumber(GEUInt) override;
    public: bEResult BeginTechnique() override;
    public: bEResult EndTechnique() override;
    public: ~eCDX9Effect() override;
    // clang-format on

  public:
    eCDX9Effect(eCDX9Effect const &);

  public:
    eCDX9Effect &operator=(eCDX9Effect const &);

  protected:
    static GEBool ms_bOptimize;
    static void(GE_STDCALL *ms_pRegEffectSwitch)();

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static void GE_STDCALL sSetEffectActCallback(void(GE_STDCALL *)());

  protected:
    eCDX9Effect(GELPVoid, GEUInt, IDirect3DDevice9 *, ID3DXEffectPool *, GEBool &);
};
