#pragma once

#include <Engine/ge_ipsourcebase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCIPSourceContainer : public eCIPSourceBase
{
    // clang-format off
    public: virtual void SetImage(eCGfxImageData *);
    public: virtual bEResult Create(eCGfxImageData *);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCIPSourceContainer() override;
    public: eCGfxImageData * GetImage() const override;
    public: void GetImageRect(bCRect &) const override;
    public: void GetImageSize(GEInt &, GEInt &) const override;
    public: bEResult Update() override;
    // clang-format on

  public:
    eCIPSourceContainer(eCIPSourceContainer const &);
    eCIPSourceContainer();

  protected:
    eCIPSourceContainer const &operator=(eCIPSourceContainer const &);

  protected:
    void DestroyLocal();
    void Invalidate();
};
