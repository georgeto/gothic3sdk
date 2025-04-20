#pragma once

#include <Engine/api/ge_apidevice.h>
#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCAPIInstance
{
    // clang-format off
    public: virtual bEResult Init(eCGfxShared::eEAPIType) = 0;
    public: virtual bEResult Finit() = 0;
    public: virtual bEResult GetAdapterCount(GEU32 *) = 0;
    public: virtual bEResult GetModeCount(GEU32, GEU32 *) = 0;
    public: virtual bEResult GetAdapterDisplayMode(GEU32, eCGfxShared::eSGfxModeDesc *) = 0;
    public: virtual bEResult GetAdapterDesc(GEU32, eCGfxShared::eSGfxAdapterDesc *) = 0;
    public: virtual bEResult GetModeDesc(GEU32, GEU32, eCGfxShared::eSGfxModeDesc *) = 0;
    public: virtual bEResult CreateDevice(GEU32, eCAPIDevice::eSAPIStartParameters const &, eCAPIDevice **) = 0;
    public: virtual ~eCAPIInstance();
    // clang-format on

  public:
    eCAPIInstance(eCAPIInstance const &);

  public:
    eCAPIInstance &operator=(eCAPIInstance const &);

  public:
    GEU32 AddRef();
    GEU32 Release();

  protected:
    eCAPIInstance();

  private:
    GEU32 m_u32ReferenceCount;
};
