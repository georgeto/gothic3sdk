#pragma once

#include <Engine/ge_gfxshared.h>
#include <Engine/ge_ipsourcebase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCIPSourceBackBuffer : public eCIPSourceBase
{
    // clang-format off
    public: virtual bEResult CreateImageData();
    public: virtual bEResult DestroyImageData();
    public: virtual bEResult Create(eCGfxShared::eEColorFormat);
    public: virtual bEResult Create(GEInt, GEInt, eCGfxShared::eEColorFormat);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCIPSourceBackBuffer() override;
    public: eCGfxImageData * GetImage() const override;
    public: void GetImageRect(bCRect &) const override;
    public: void GetImageSize(GEInt &, GEInt &) const override;
    public: bEResult OnResetResources(GEBool) override;
    public: bEResult OnRestoreResources(GEBool) override;
    public: bEResult Update() override;
    // clang-format on

  public:
    eCIPSourceBackBuffer(eCIPSourceBackBuffer const &);
    eCIPSourceBackBuffer();

  protected:
    eCIPSourceBackBuffer const &operator=(eCIPSourceBackBuffer const &);

  protected:
    void DestroyLocal();
    void Invalidate();
};
