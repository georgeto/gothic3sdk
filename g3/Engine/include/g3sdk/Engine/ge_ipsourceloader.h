#pragma once

#include <Engine/ge_ipsourcebase.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCIPSourceLoader : public eCIPSourceBase
{
    // clang-format off
    public: virtual void SetImageFileName(bCString const &);
    public: virtual bCString const & GetImageFileName() const;
    public: virtual bEResult Create(bCString const &);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCIPSourceLoader() override;
    public: eCGfxImageData * GetImage() const override;
    public: void GetImageRect(bCRect &) const override;
    public: void GetImageSize(GEInt &, GEInt &) const override;
    // clang-format on

  public:
    eCIPSourceLoader(eCIPSourceLoader const &);
    eCIPSourceLoader();

  protected:
    eCIPSourceLoader const &operator=(eCIPSourceLoader const &);

  protected:
    void DestroyLocal();
    void Invalidate();
};
