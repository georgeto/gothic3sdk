#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCGfxVertexProgram : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCGfxVertexProgram const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxVertexProgram() override;
    // clang-format on

  public:
    eCGfxVertexProgram(eCGfxVertexProgram const &);
    eCGfxVertexProgram();

  public:
    eCGfxVertexProgram &operator=(eCGfxVertexProgram const &);

  public:
    bEResult ClearProgramRegister(GEU32, GEU32);
    bEResult Create(GELPVoid, GEBool);
    bEResult CreateDeclarationBuffer(GEU32);
    bEResult DestroyDeclarationBuffer();
    bEResult Execute();
    bEResult GetDeclarationBuffer(GELPVoid *, GEU32 &) const;
    bEResult GetProgramRegister(GEU32, GEFloat *, GEU32) const;
    void Invalidate();
    bEResult SetProgramRegister(GEU32, GEFloat const *, GEU32);

  protected:
    static GEBool ms_bOptimize;
    static GEBool ms_bReset;
    static eCGfxVertexProgram *ms_pActiveVertexProgram;
    static eCGfxVertexProgram *ms_pMasterVertexProgram;
    static void(GE_STDCALL *ms_pRegisterVertexProgramExecuteCall)();

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static eCGfxVertexProgram *GE_STDCALL sGetActiveVertexProgram();
    static eCGfxVertexProgram *GE_STDCALL sGetMasterVertexProgram();
    static void GE_STDCALL sResetCachedStates();
    static void GE_STDCALL sSetMasterVertexProgram(eCGfxVertexProgram *);
    static void GE_STDCALL sSetVertexProgramExecuteCallback(void(GE_STDCALL *)());

  protected:
    bEResult CreateProgram(GELPVoid, GEBool);
    bEResult DestroyProgram();
};
