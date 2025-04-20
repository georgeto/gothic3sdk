#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCAPIDevice;
class eCAPITexture;

class eCVideoPlayer
{
    GE_UNIMPL_STRUCT(eCVideoPlayer)
};

class GE_DLLIMPORT eCGfxImageData : public bCObjectRefBase
{
    // clang-format off
    public: virtual bEResult CopyFrom(eCGfxImageData const &);
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    protected: ~eCGfxImageData() override;
    // clang-format on

  public:
    static void GE_STDCALL SetImageLoadMaxMipmapCallback(GEBool(GE_STDCALL *)(GEU32, GEU32, GEU32, GEBool &), GEU32);

  public:
    eCGfxImageData(eCGfxImageData const &);
    eCGfxImageData();

  public:
    eCGfxImageData &operator=(eCGfxImageData const &);

  public:
    bEResult ConvertFrom(eCGfxImageData &, eCGfxShared::eECopyFilter, GEBool);
    bEResult ConvertInPlace(eCGfxShared::eEColorFormat);
    bEResult Create(eCGfxShared::eSGfxLayersDesc const &);
    bEResult Create(eCGfxShared::eEColorFormat);
    bEResult CreateImageFromMemory(eCGfxShared::eEPoolType, GEUInt, GELPVoid, GEUInt);
    bEResult Execute();
    bEResult GetLayersDescription(eCGfxShared::eSGfxLayersDesc &);
    bEResult GetMipMapCountForRead(GEU32 &) const;
    bEResult GetRenderTargetData(eCGfxShared::eECubeMapFace, eCGfxImageData *);
    bEResult GetRenderTargetHandle(eCGfxShared::eECubeMapFace, GELPVoid &) const;
    bEResult GetUnitNumber(GEU32 &) const;
    eCVideoPlayer *GetVideoPlayer();
    bEResult Import(bCString const &, GEBool);
    void Invalidate();
    bEResult LoadSurfaceFromSurface(GEUInt, GELPCVoid, bCRect const *, eCGfxImageData *, GEUInt, GELPCVoid,
                                    bCRect const *, GEU32, GEU32);
    bEResult LockLayer(GEUInt, eCGfxShared::eECubeMapFace, GEU32, GEInt &, GEInt &, GELPVoid *);
    bEResult SetMipMapCountForRead(GEU32);
    bEResult SetUnitNumber(GEU32);
    bEResult UnlockLayer(eCGfxShared::eECubeMapFace, GEUInt);
    bEResult UseDefaultPoolForRead(GEBool);

  protected:
    static GEBool ms_bOptimize;
    static GEBool ms_bReset;
    static eCGfxImageData **ms_pActiveImageData;
    static eCGfxImageData **ms_pMasterImageData;
    static void(GE_STDCALL *ms_pRegisterImageDataExecuteCall)();
    static GEBool(GE_STDCALL *ms_pfuncLoadMaxMipmapCallback)(GEU32, GEU32, GEU32, GEBool &);
    static GEU32 ms_u32UserData;

  protected:
    static void GE_STDCALL sDisableOptimization();
    static void GE_STDCALL sEnableOptimization();
    static eCGfxImageData *GE_STDCALL sGetActiveImageData(GEU32);
    static eCGfxImageData *GE_STDCALL sGetMasterImageData(GEU32);
    static void GE_STDCALL sResetCachedStates();
    static void GE_STDCALL sSetImageDataExecuteCallback(void(GE_STDCALL *)());
    static void GE_STDCALL sSetMasterImageData(GEU32, eCGfxImageData *);

  protected:
    bEResult CompressNormalMapToDXT5InPlace();
    bEResult ComputeNormalMap(eCGfxImageData &, eCGfxShared::eENormalMapGen, eCGfxShared::eEChannel, GEFloat);
    bEResult ComputeNormalMapInPlace(eCGfxShared::eENormalMapGen, eCGfxShared::eEChannel, GEFloat);
    bEResult ConvertCubeMap(eCGfxImageData &, eCGfxShared::eECopyFilter, GEBool);
    bEResult ConvertCubeMapInPlace(eCGfxShared::eEColorFormat);
    bEResult ConvertTexture(eCGfxImageData &, eCGfxShared::eECopyFilter, GEBool);
    bEResult ConvertTextureInPlace(eCGfxShared::eEColorFormat);
    bEResult ConvertVolume(eCGfxImageData &, eCGfxShared::eECopyFilter, GEBool);
    bEResult ConvertVolumeInPlace(eCGfxShared::eEColorFormat);
    bEResult CopyCurrentRTToImage(eCGfxShared::eETexFilter, bCRect *, bCRect *);
    bEResult CopyImageToCurrentRT(eCGfxShared::eETexFilter, bCRect *, bCRect *);
    bEResult CreateImageFromFile(eCGfxShared::eEPoolType, GEUInt, GELPChar const);
    bEResult CreateLayers(eCGfxShared::eSGfxLayersDesc const &);
    bEResult DestroyLayers();
    bEResult FillImageFromFile(eCGfxShared::eSGfxLayersDesc &, GELPChar const);
    bEResult FillImageFromMemory(eCGfxShared::eSGfxLayersDesc &, GELPVoid, GEUInt);
    bEResult GenerateMipMaps(GEUInt, eCGfxShared::eECopyFilter);
    bEResult GetTextureHandle(eCAPITexture **);
    GEBool HasAlphaLayer(bCString const &);
    bEResult SaveImageToFile(GELPChar const);
    bEResult SaveImageToMemory(bCMemoryStream &);
    bEResult UpdateCompleteSize();
    bEResult WrapAPITexture(eCAPITexture *, eCGfxShared::eSGfxLayersDesc &);

  public:
    eCAPIDevice *m_pAPIDevice;
    eCGfxShared::eSGfxLayersDesc m_GfxLayersDesc;
    GEUInt CompleteSize;
    GEUInt m_DesiredColorFormat;
    GEUInt m_uTextureUnitNumber;
    GEBool m_bIsLocked;
    GE_PADDING(3)
    GEUInt m_uMipMapCountForRead;
    GEBool m_UseDefaultPoolForRead;
    GE_PADDING(3)
    eCAPITexture *m_pAPITexture;
    GEBool m_bMipMapCountForRead;
    GE_PADDING(3)
    GEUInt field_50;
};

GE_ASSERT_SIZEOF(eCGfxImageData, 0x54)
