#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCGfxFog : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCGfxFog const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxFog() override;
    // clang-format on

  public:
    eCGfxFog(eCGfxFog const &);
    eCGfxFog();

  public:
    eCGfxFog &operator=(eCGfxFog const &);

  public:
    bEResult Execute();
    bEResult GetFog(eCGfxShared::eSGfxFogData &) const;
    void Invalidate();
    bEResult SetFog(eCGfxShared::eSGfxFogData const &);

  protected:
    static GEBool ms_bOptimize;
    static GEBool ms_bReset;
    static eCGfxFog *ms_pActiveFog;
    static eCGfxFog *ms_pMasterFog;
    static void(GE_STDCALL *ms_pRegisterFogExecuteCall)();

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static eCGfxFog *GE_STDCALL sGetActiveFog();
    static eCGfxFog *GE_STDCALL sGetMasterFog();
    static void GE_STDCALL sResetCachedStates();
    static void GE_STDCALL sSetFogExecuteCallback(void(GE_STDCALL *)());
    static void GE_STDCALL sSetMasterFog(eCGfxFog *);
};
