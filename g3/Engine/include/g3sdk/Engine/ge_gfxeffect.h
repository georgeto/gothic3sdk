#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCGfxImageData;

class GE_DLLIMPORT eCGfxEffect : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult Create(GELPVoid, GEUInt);
    public: virtual bEResult CopyFrom(eCGfxEffect const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxEffect() override;
    // clang-format on

  public:
    eCGfxEffect(eCGfxEffect const &);
    eCGfxEffect();

  public:
    eCGfxEffect &operator=(eCGfxEffect const &);

  public:
    bEResult AttachImmImageData(GELPVoid const, eCGfxImageData *);
    bEResult BeginEffectApplication();
    bEResult DeAttachImmImageData(GELPVoid const, eCGfxImageData *&) const;
    bEResult EndEffectApplication();
    bEResult Execute();
    bEResult GetCurrentPassNumber(GEUInt &) const;
    bEResult GetCurrentTechnique(GELPVoid &) const;
    bEResult GetEffectDescription(eCGfxShared::eSGfxEffectDesc &) const;
    bEResult GetImmBoolArray(GELPVoid const, GELPVoid const, GEUInt) const;
    bEResult GetImmFloatArray(GELPVoid const, GELPVoid const, GEUInt) const;
    bEResult GetImmIntArray(GELPVoid const, GELPVoid const, GEUInt) const;
    bEResult GetImmMatrixArray(GELPVoid const, GELPVoid const, GEUInt) const;
    bEResult GetImmMatrixTransposeArray(GELPVoid const, GELPVoid const, GEUInt) const;
    bEResult GetImmParameter(GELPVoid const, GELPVoid const, GEUInt) const;
    bEResult GetImmVectorArray(GELPVoid const, GELPVoid const, GEUInt) const;
    bEResult GetParameterDescription(GEUInt, eCGfxShared::eSGfxParameterDesc &) const;
    bEResult GetTechniqueDescription(GEUInt, eCGfxShared::eSGfxTechniqueDesc &) const;
    void Invalidate();
    bEResult IsParameterUsed(GELPVoid const, GELPVoid const, GEBool &) const;
    bEResult OnLostDevice() const;
    bEResult OnResetDevice() const;
    bEResult SetCurrentPassNumber(GEUInt);
    bEResult SetCurrentTechnique(GELPVoid const);
    bEResult SetImmBoolArray(GELPVoid const, GELPVoid const, GEUInt);
    bEResult SetImmFloatArray(GELPVoid const, GELPVoid const, GEUInt);
    bEResult SetImmIntArray(GELPVoid const, GELPVoid const, GEUInt);
    bEResult SetImmMatrixArray(GELPVoid const, GELPVoid const, GEUInt);
    bEResult SetImmMatrixTransposeArray(GELPVoid const, GELPVoid const, GEUInt);
    bEResult SetImmParameter(GELPVoid const, GELPVoid const, GEUInt);
    bEResult SetImmVectorArray(GELPVoid const, GELPVoid const, GEUInt);

  protected:
    static GEBool ms_bOptimize;
    static GEBool ms_bReset;
    static eCGfxEffect *ms_pActiveEffect;
    static eCGfxEffect *ms_pMasterEffect;
    static void(GE_STDCALL *ms_pRegisterEffectExecuteCall)();

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static eCGfxEffect *GE_STDCALL sGetActiveEffect();
    static eCGfxEffect *GE_STDCALL sGetMasterEffect();
    static void GE_STDCALL sResetCachedStates();
    static void GE_STDCALL sSetEffectExecuteCallback(void(GE_STDCALL *)());
    static void GE_STDCALL sSetMasterEffect(eCGfxEffect *);

  protected:
    bEResult CreateEffect(GELPVoid, GEUInt);
    bEResult DestroyEffect();
};
