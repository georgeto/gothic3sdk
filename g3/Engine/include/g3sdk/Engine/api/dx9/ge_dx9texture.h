#pragma once

#include <Engine/api/ge_apitexture.h>
#include <Engine/ge_d3d.h>
#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCDX9Texture : public eCAPITexture
{
    // clang-format off
    public: bEResult LockImageLayer(GEUInt, GEU32, GEInt *, GELPVoid*) override;
    public: bEResult UnlockImageLayer(GEUInt) override;
    public: bEResult GetRenderTargetHandle(GELPVoid*) override;
    public: bEResult SetTexture(GEU32) override;
    public: bEResult ComputeNormalMap(eCAPITexture *, eCGfxShared::eENormalMapGen, eCGfxShared::eEChannel, GEFloat) override;
    public: bEResult ConvertFrom(eCAPITexture *, eCGfxShared::eECopyFilter, GEBool) override;
    public: bEResult GenerateTextureMipMaps(GEUInt, eCGfxShared::eECopyFilter) override;
    public: bEResult SaveTextureToFile(GELPChar const) override;
    public: bEResult SaveTextureToMemory(bCMemoryStream &) override;
    public: bEResult CopyCurrentRTToImage(eCGfxShared::eETexFilter, bCRect *, bCRect *) override;
    public: bEResult CopyImageToCurrentRT(eCGfxShared::eETexFilter, bCRect *, bCRect *) override;
    public: bEResult CopySurface(eCAPITexture *) override;
    public: bEResult LoadSurfaceFromSurface(GEUInt, GELPCVoid, bCRect const *, eCAPITexture *, GEUInt, GELPCVoid, bCRect const *, GEU32, GEU32) override;
    public: bEResult GetRenderTargetData(eCAPITexture *) override;
    public: ~eCDX9Texture() override;
    // clang-format on

  public:
    static GEU32 s_u32CountManaged;
    static GEU32 s_u32CountMemManaged;
    static GEU32 s_u32CountMemNonManaged;
    static GEU32 s_u32CountNonManaged;
    static GEU32 s_u32ErrorCorrected;
    static GEU32 s_u32ErrorNotCorrected;
    static GEU32 s_u32PeekManaged;
    static GEU32 s_u32PeekMemManaged;
    static GEU32 s_u32PeekMemNonManaged;
    static GEU32 s_u32PeekNonManaged;

  public:
    eCDX9Texture(eCDX9Texture const &);

  public:
    eCDX9Texture &operator=(eCDX9Texture const &);

  protected:
    static GEBool ms_bForceLowestMipMapLevel;
    static GEBool ms_bOptimize;
    static void(GE_STDCALL *ms_pRegTextureLock)();
    static void(GE_STDCALL *ms_pRegTextureSwitch)();

  protected:
    static GEFloat GE_STDCALL FormatSize(_D3DFORMAT);
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static void GE_STDCALL sForceLowestMipMapLevel(GEBool);
    static GEBool GE_STDCALL sGetForceLowestMipMapLevel();
    static void GE_STDCALL sSetTextureActCallback(void(GE_STDCALL *)());
    static void GE_STDCALL sSetTextureLockCallback(void(GE_STDCALL *)());

  protected:
    eCDX9Texture(eCGfxShared::eSGfxLayersDesc &, GELPVoid, GEUInt, IDirect3DDevice9 *, GEBool &);
    eCDX9Texture(eCGfxShared::eSGfxLayersDesc &, GELPChar const, IDirect3DDevice9 *, GEBool &);
    eCDX9Texture(eCGfxShared::eSGfxLayersDesc const &, IDirect3DDevice9 *, GEBool &);
    eCDX9Texture(IDirect3DTexture9 *, IDirect3DDevice9 *, eCGfxShared::eSGfxLayersDesc &);

  protected:
    bEResult GetTextureHandle(IDirect3DTexture9 **);

  private:
    void Count();
    GEU32 GetSize();

  public:
    IDirect3DDevice9 *m_pDirect3DDevice;
    IDirect3DTexture9 *m_pTexture;
    GEBool bForceLowestMipMapLevel;
    GE_PADDING(3)
    D3DPOOL Pool;
    GEU32 m_TextureSize;
};

GE_ASSERT_SIZEOF(eCDX9Texture, 0x1c)
