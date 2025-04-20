#pragma once

#include <Engine/font/ge_font.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCVertexFont : public eCFont
{
    // clang-format off
    public: virtual eCFontResource * GetFontResource();
    public: virtual GEBool SetTexture(bCString const &);
    public: virtual bCString const & GetTexture() const;
    protected: virtual void Update();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    protected: void Destroy() override;
    protected: bEResult Create() override;
    public: ~eCVertexFont() override;
    public: void SetText(bCString const &) override;
    public: void SetText(bCUnicodeString const &) override;
    public: void SetClipRect(bCRect const &) override;
    public: void SetTextColor(bCByteAlphaColor const &) override;
    public: void SetBackgroundColor(bCByteAlphaColor const &) override;
    public: GEInt GetLetterHeight() const override;
    public: GEInt GetLetterWidth(GEChar) const override;
    public: GEInt GetTextWidth(bCString const &) const override;
    public: GEInt GetTextWidth(bCUnicodeString const &) const override;
    public: void Render() override;
    // clang-format on

  public:
    eCVertexFont(eCVertexFont const &);
    eCVertexFont();

  public:
    eCVertexFont &operator=(eCVertexFont const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCVertexFont const &);
    void CopyTo(eCVertexFont &) const;
    void DrawLetters();

  protected:
    GEBool CacheIn();
    void Invalidate();
};
