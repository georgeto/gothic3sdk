#pragma once

#include <Engine/api/ge_apivolume.h>
#include <Engine/ge_gfxshared.h>

struct IDirect3DDevice9;

class GE_DLLIMPORT eCDX9Volume : public eCAPIVolume
{
    // clang-format off
    public: bEResult LockVolumeBox(GEUInt, GEU32, GEInt *, GEInt *, GELPVoid*) override;
    public: bEResult UnlockVolumeBox(GEUInt) override;
    public: bEResult SetVolume(GEU32) override;
    public: bEResult GenerateVolumeMipMaps(GEUInt, eCGfxShared::eECopyFilter) override;
    public: ~eCDX9Volume() override;
    // clang-format on

  public:
    eCDX9Volume(eCDX9Volume const &);

  public:
    eCDX9Volume &operator=(eCDX9Volume const &);

  protected:
    static GEBool ms_bOptimize;
    static void(GE_STDCALL *ms_pRegVolumeLock)();
    static void(GE_STDCALL *ms_pRegVolumeSwitch)();

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static void GE_STDCALL sSetVolumeActCallback(void(GE_STDCALL *)());
    static void GE_STDCALL sSetVolumeLockCallback(void(GE_STDCALL *)());

  protected:
    eCDX9Volume(eCGfxShared::eSGfxLayersDesc const &, IDirect3DDevice9 *, GEBool &);

  private:
    void Count();
    GEU32 GetSize();
};
