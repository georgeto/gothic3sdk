#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCGfxCameraStates : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCGfxCameraStates const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxCameraStates() override;
    // clang-format on

  public:
    eCGfxCameraStates(eCGfxCameraStates const &);
    eCGfxCameraStates();

  public:
    eCGfxCameraStates &operator=(eCGfxCameraStates const &);

  public:
    bEResult Execute();
    bEResult GetFullLighting(GEBool &) const;
    bEResult GetShadeMode(eCGfxShared::eEShadeMode &) const;
    bEResult GetStencilTesting(eCGfxShared::eEStencil &, eCGfxShared::eSGfxStencilData &) const;
    void Invalidate();
    bEResult SetFullLighting(GEBool);
    bEResult SetShadeMode(eCGfxShared::eEShadeMode);
    bEResult SetStencilTesting(eCGfxShared::eEStencil, eCGfxShared::eSGfxStencilData const &);

  protected:
    static GEBool ms_bOptimize;
    static GEBool ms_bReset;
    static eCGfxCameraStates *ms_pActiveCameraStates;
    static eCGfxCameraStates *ms_pMasterCameraStates;
    static void(GE_STDCALL *ms_pRegisterCameraStatesExecuteCall)();

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static eCGfxCameraStates *GE_STDCALL sGetActiveCameraStates();
    static eCGfxCameraStates *GE_STDCALL sGetMasterCameraStates();
    static void GE_STDCALL sResetCachedStates();
    static void GE_STDCALL sSetCameraStatesExecuteCallback(void(GE_STDCALL *)());
    static void GE_STDCALL sSetMasterCameraStates(eCGfxCameraStates *);
};
