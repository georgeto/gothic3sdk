#pragma once

#include <SharedBase.h>

class GE_DLLIMPORT eCCanvas : public bCObjectRefBase
{
    // clang-format off
    public: virtual void GetPlacement(bCRect &) const;
    public: virtual bCRect const & GetPlacement() const;
    protected: virtual bCRect & AccessPlacement();
    public: virtual void SetPlacement(bCRect const &);
    public: virtual void Process();
    public: virtual GEBool GetRenderingEnabled() const;
    public: virtual void SetRenderingEnabled(GEBool);
    public: virtual void Render() = 0;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    protected: void Destroy() override;
    public: ~eCCanvas() override;
    // clang-format on

  public:
    eCCanvas(eCCanvas const &);
    eCCanvas();

  public:
    eCCanvas &operator=(eCCanvas const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCCanvas const &);
    void CopyTo(eCCanvas &) const;

  protected:
    void Invalidate();
};
