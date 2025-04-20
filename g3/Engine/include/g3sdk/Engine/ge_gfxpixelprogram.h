#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCGfxPixelProgram : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCGfxPixelProgram const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxPixelProgram() override;
    // clang-format on

  public:
    eCGfxPixelProgram(eCGfxPixelProgram const &);
    eCGfxPixelProgram();

  public:
    eCGfxPixelProgram &operator=(eCGfxPixelProgram const &);

  public:
    bEResult ClearProgramRegister(GEU32, GEU32);
    bEResult Creates(GELPVoid);
    bEResult Execute();
    bEResult GetProgramRegister(GEU32, GEFloat *, GEU32) const;
    void Invalidate();
    bEResult SetProgramRegister(GEU32, GEFloat const *, GEU32);

  protected:
    static GEBool ms_bOptimize;
    static GEBool ms_bReset;
    static eCGfxPixelProgram *ms_pActivePixelProgram;
    static eCGfxPixelProgram *ms_pMasterPixelProgram;
    static void(GE_STDCALL *ms_pRegisterPixelProgramExecuteCall)();

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static eCGfxPixelProgram *GE_STDCALL sGetActivePixelProgram();
    static eCGfxPixelProgram *GE_STDCALL sGetMasterPixelProgram();
    static void GE_STDCALL sResetCachedStates();
    static void GE_STDCALL sSetMasterPixelProgram(eCGfxPixelProgram *);
    static void GE_STDCALL sSetPixelProgramExecuteCallback(void(GE_STDCALL *)());

  protected:
    bEResult CreateProgram(GELPVoid);
    bEResult DestroyProgram();
};
