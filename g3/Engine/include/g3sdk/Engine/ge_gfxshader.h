#pragma once

#include <SharedBase.h>

class eCGfxEffect;
class eCGfxMaterial;
class eCGfxPixelProgram;
class eCGfxVertexProgram;

class GE_DLLIMPORT eCGfxShader : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCGfxShader const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxShader() override;
    // clang-format on

  public:
    eCGfxShader(eCGfxShader const &);
    eCGfxShader();

  public:
    eCGfxShader &operator=(eCGfxShader const &);

  public:
    bEResult AttachFirstEffect(eCGfxEffect *);
    bEResult AttachMaterial(eCGfxMaterial *);
    bEResult AttachPixelProgram(eCGfxPixelProgram *);
    bEResult AttachSecondEffect(eCGfxEffect *);
    bEResult AttachVertexProgram(eCGfxVertexProgram *);
    bEResult Execute();
    bEResult GetAttachedFirstEffect(eCGfxEffect *&) const;
    bEResult GetAttachedMaterial(eCGfxMaterial *&) const;
    bEResult GetAttachedPixelProgram(eCGfxPixelProgram *&) const;
    bEResult GetAttachedSecondEffect(eCGfxEffect *&) const;
    bEResult GetAttachedVertexProgram(eCGfxVertexProgram *&) const;
    void Invalidate();

  protected:
    static GEBool ms_bOptimize;
    static GEBool ms_bReset;
    static eCGfxShader *ms_pActiveShader;
    static eCGfxShader *ms_pMasterShader;
    static void(GE_STDCALL *ms_pRegisterShaderExecuteCall)();

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static eCGfxShader *GE_STDCALL sGetActiveShader();
    static eCGfxShader *GE_STDCALL sGetMasterShader();
    static void GE_STDCALL sResetCachedStates();
    static void GE_STDCALL sSetMasterShader(eCGfxShader *);
    static void GE_STDCALL sSetShaderExecuteCallback(void(GE_STDCALL *)());
};
