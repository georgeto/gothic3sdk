#pragma once

#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCAPIVolume
{
    // clang-format off
    public: virtual bEResult LockVolumeBox(GEUInt, GEU32, GEInt *, GEInt *, GELPVoid*) = 0;
    public: virtual bEResult UnlockVolumeBox(GEUInt) = 0;
    public: virtual bEResult SetVolume(GEU32) = 0;
    public: virtual bEResult GenerateVolumeMipMaps(GEUInt, eCGfxShared::eECopyFilter) = 0;
    public: virtual ~eCAPIVolume();
    // clang-format on

  public:
    eCAPIVolume(eCAPIVolume const &);

  public:
    eCAPIVolume &operator=(eCAPIVolume const &);

  public:
    GEU32 AddRef();
    GEU32 Release();

  protected:
    eCAPIVolume();

  private:
    GEU32 m_u32ReferenceCount;
};
