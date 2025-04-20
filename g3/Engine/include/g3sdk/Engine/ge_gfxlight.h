#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCGfxLight : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCGfxLight const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxLight() override;
    // clang-format on

  public:
    eCGfxLight(eCGfxLight const &);
    eCGfxLight();

  public:
    eCGfxLight &operator=(eCGfxLight const &);

  public:
    bEResult Execute();
    bEResult GetAmbientLighting(GEU32 &) const;
    bEResult GetVertexLighting(GEU32, GEBool &) const;
    bEResult GetVertexLightingData(GEU32, eCGfxShared::eSGfxLightData &) const;
    void Invalidate();
    bEResult SetAmbientLighting(GEU32);
    bEResult SetVertexLighting(GEU32, GEBool);
    bEResult SetVertexLightingData(GEU32, eCGfxShared::eSGfxLightData const &);

  protected:
    static GEBool ms_bOptimize;
    static GEBool ms_bReset;
    static eCGfxLight *ms_pActiveLight;
    static eCGfxLight *ms_pMasterLight;
    static void(GE_STDCALL *ms_pRegisterLightExecuteCall)();

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static eCGfxLight *GE_STDCALL sGetActiveLight();
    static eCGfxLight *GE_STDCALL sGetMasterLight();
    static void GE_STDCALL sResetCachedStates();
    static void GE_STDCALL sSetLightExecuteCallback(void(GE_STDCALL *)());
    static void GE_STDCALL sSetMasterLight(eCGfxLight *);
};
