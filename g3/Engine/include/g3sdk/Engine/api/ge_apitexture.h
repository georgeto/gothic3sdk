#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCAPITexture
{
    // clang-format off
    public: virtual bEResult LockImageLayer(GEUInt, GEU32, GEInt *, GELPVoid*) = 0;
    public: virtual bEResult UnlockImageLayer(GEUInt) = 0;
    public: virtual bEResult GetRenderTargetHandle(GELPVoid*) = 0;
    public: virtual bEResult SetTexture(GEU32) = 0;
    public: virtual bEResult ComputeNormalMap(eCAPITexture *, eCGfxShared::eENormalMapGen, eCGfxShared::eEChannel, GEFloat) = 0;
    public: virtual bEResult ConvertFrom(eCAPITexture *, eCGfxShared::eECopyFilter, GEBool) = 0;
    public: virtual bEResult GenerateTextureMipMaps(GEUInt, eCGfxShared::eECopyFilter) = 0;
    public: virtual bEResult SaveTextureToFile(GELPChar const) = 0;
    public: virtual bEResult SaveTextureToMemory(bCMemoryStream &) = 0;
    public: virtual bEResult CopyCurrentRTToImage(eCGfxShared::eETexFilter, bCRect *, bCRect *) = 0;
    public: virtual bEResult CopyImageToCurrentRT(eCGfxShared::eETexFilter, bCRect *, bCRect *) = 0;
    public: virtual bEResult CopySurface(eCAPITexture *) = 0;
    public: virtual bEResult LoadSurfaceFromSurface(GEUInt, GELPCVoid, bCRect const *, eCAPITexture *, GEUInt, GELPCVoid, bCRect const *, GEU32, GEU32) = 0;
    public: virtual bEResult GetRenderTargetData(eCAPITexture *) = 0;
    public: virtual ~eCAPITexture();
    // clang-format on

  public:
    eCAPITexture(eCAPITexture const &);

  public:
    eCAPITexture &operator=(eCAPITexture const &);

  public:
    GEU32 AddRef();
    GEU32 Release();

  protected:
    eCAPITexture();

  private:
    GEU32 m_u32ReferenceCount;
};
