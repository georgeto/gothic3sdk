#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCGfxImageAVIData : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCGfxImageAVIData const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxImageAVIData() override;
    // clang-format on

  public:
    eCGfxImageAVIData(eCGfxImageAVIData const &);
    eCGfxImageAVIData();

  public:
    eCGfxImageAVIData &operator=(eCGfxImageAVIData const &);

  public:
    bEResult Create(eCGfxShared::eSGfxLayersDesc const &);
    bEResult Execute();
    bEResult GetLayersDescription(eCGfxShared::eSGfxLayersDesc &) const;
    void Invalidate();

  protected:
    static GEBool ms_bOptimize;
    static GEBool ms_bReset;
    static eCGfxImageAVIData **ms_pActiveImageAVIData;
    static eCGfxImageAVIData **ms_pMasterImageAVIData;
    static void(GE_STDCALL *ms_pRegisterImageAVIDataExecuteCall)();

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static eCGfxImageAVIData *GE_STDCALL sGetActiveImageAVIData(GEU32);
    static eCGfxImageAVIData *GE_STDCALL sGetMasterImageAVIData(GEU32);
    static void GE_STDCALL sResetCachedStates();
    static void GE_STDCALL sSetImageAVIDataExecuteCallback(void(GE_STDCALL *)());
    static void GE_STDCALL sSetMasterImageAVIData(GEU32, eCGfxImageAVIData *);
};
