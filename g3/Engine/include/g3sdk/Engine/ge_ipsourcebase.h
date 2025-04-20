#pragma once

#include <SharedBase.h>

class eCGfxImageData;

class GE_DLLIMPORT eCIPSourceBase : public bCObjectRefBase
{
    // clang-format off
    public: virtual eCGfxImageData * GetImage() const = 0;
    public: virtual void GetImageRect(bCRect &) const = 0;
    public: virtual void GetImageSize(GEInt &, GEInt &) const = 0;
    public: virtual GEBool GetImageUVRect(bCVector2 &, bCVector2 &) const;
    public: virtual GEBool GetImageVSCoords(bCVector2 &, bCVector2 &) const;
    public: virtual GEBool IsDirty() const;
    public: virtual void SetDirty();
    public: virtual bEResult OnResetResources(GEBool);
    public: virtual bEResult OnRestoreResources(GEBool);
    public: virtual bEResult Update();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCIPSourceBase() override;
    // clang-format on

  public:
    eCIPSourceBase(eCIPSourceBase const &);
    eCIPSourceBase();

  protected:
    eCIPSourceBase const &operator=(eCIPSourceBase const &);

  protected:
    void DestroyLocal();
    void Invalidate();
};
