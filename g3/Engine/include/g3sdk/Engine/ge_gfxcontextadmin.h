#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCAPIDevice;

class GE_DLLIMPORT eCGfxContextAdmin : public bCObjectRefBase
{
    // clang-format off
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxContextAdmin() override;
    // clang-format on

  public:
    eCGfxContextAdmin(eCGfxContextAdmin const &);

  public:
    eCGfxContextAdmin &operator=(eCGfxContextAdmin const &);

  public:
    bEResult CheckDeviceFormat(eCGfxShared::eSGfxLayersDesc const &, GEBool);
    bEResult Create(eCGfxShared::eSGfxContextDesc &, HWND, eCGfxShared::eEContextCreate, GEBool, GEBool,
                    eCGfxShared::eEMultiSample, eCGfxShared::eEDepthFormat);
    bEResult GetContextDescription(eCGfxShared::eSGfxContextDesc &) const;
    bEResult GetInternalOptimization(eCGfxShared::eEITLOptimization &) const;
    void Invalidate();
    bEResult IsResetNecessary(GEBool &) const;
    bEResult IsResetNeeded(GEBool &) const;
    bEResult Reset();
    bEResult SetInternalOptimization(eCGfxShared::eEITLOptimization);
    bEResult ToggleNewMode(GEBool, GEBool, eCGfxShared::eEMultiSample, eCGfxShared::eEDepthFormat,
                           eCGfxShared::eSGfxContextDesc const &);

  protected:
    static eCAPIDevice *ms_pAPIDevice;

  protected:
    static eCAPIDevice *GE_STDCALL sGetAPIDevice();

  protected:
    eCGfxContextAdmin();
};
