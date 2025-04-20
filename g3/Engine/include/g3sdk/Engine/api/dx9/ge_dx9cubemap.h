#pragma once

#include <Engine/api/ge_apicubemap.h>
#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

struct IDirect3DDevice9;

class GE_DLLIMPORT eCDX9CubeMap : public eCAPICubeMap
{
    // clang-format off
    public: bEResult LockCubeMapLayer(GEUInt, eCGfxShared::eECubeMapFace, GEU32, GEInt *, GELPVoid*) override;
    public: bEResult UnlockCubeMapLayer(eCGfxShared::eECubeMapFace, GEUInt) override;
    public: bEResult GetRenderTargetHandle(eCGfxShared::eECubeMapFace, GELPVoid*) override;
    public: bEResult SetCubeMap(GEU32) override;
    public: bEResult GenerateCubeMapMipMaps(GEUInt, eCGfxShared::eECopyFilter) override;
    public: bEResult GetRenderTargetData(eCGfxShared::eECubeMapFace, eCAPITexture *) override;
    public: bEResult SaveTextureToFile(GELPChar const) override;
    public: bEResult SaveTextureToMemory(bCMemoryStream &) override;
    public: ~eCDX9CubeMap() override;
    // clang-format on

  public:
    eCDX9CubeMap(eCDX9CubeMap const &);

  public:
    eCDX9CubeMap &operator=(eCDX9CubeMap const &);

  protected:
    static GEBool ms_bOptimize;
    static void(GE_STDCALL *ms_pRegCubemapLock)();
    static void(GE_STDCALL *ms_pRegCubemapSwitch)();

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static void GE_STDCALL sSetCubemapActCallback(void(GE_STDCALL *)());
    static void GE_STDCALL sSetCubemapLockCallback(void(GE_STDCALL *)());

  protected:
    eCDX9CubeMap(eCGfxShared::eSGfxLayersDesc &, GELPVoid, GEUInt, IDirect3DDevice9 *, GEBool &);
    eCDX9CubeMap(eCGfxShared::eSGfxLayersDesc &, GELPChar const, IDirect3DDevice9 *, GEBool &);
    eCDX9CubeMap(eCGfxShared::eSGfxLayersDesc const &, IDirect3DDevice9 *, GEBool &);

  private:
    void Count();
    GEU32 GetSize();
};
