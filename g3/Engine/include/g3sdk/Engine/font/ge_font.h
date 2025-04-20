#pragma once

#include <SharedBase.h>

class eCFontResource
{
    GE_UNIMPL_STRUCT(eCFontResource)
};

class GE_DLLIMPORT eCFont : public bCObjectRefBase
{
    // clang-format off
    protected: virtual bCUnicodeString & AccessUnicodeText();
    protected: virtual bCByteAlphaColor & AccessTextColor();
    protected: virtual bCByteAlphaColor & AccessBackgroundColor();
    protected: virtual bCRect & AccessClipRect();
    public: virtual bCString GetAnsiText() const;
    public: virtual bCUnicodeString const & GetUnicodeText() const;
    public: virtual bCRect const & GetClipRect() const;
    public: virtual void GetClipRect(bCRect &) const;
    public: virtual bCByteAlphaColor const & GetTextColor() const;
    public: virtual void GetTextColor(bCByteAlphaColor &) const;
    public: virtual bCByteAlphaColor const & GetBackgroundColor() const;
    public: virtual void GetBackgroundColor(bCByteAlphaColor &) const;
    public: virtual void GetText(bCString &) const;
    public: virtual void GetText(bCUnicodeString &) const;
    public: virtual void SetText(bCString const &);
    public: virtual void SetText(bCUnicodeString const &);
    public: virtual void SetClipRect(bCRect const &);
    public: virtual void SetTextColor(bCByteAlphaColor const &);
    public: virtual void SetBackgroundColor(bCByteAlphaColor const &);
    public: virtual void AddTextToRenderList();
    public: virtual GEInt GetLetterHeight() const = 0;
    public: virtual GEInt GetLetterWidth(GEChar) const = 0;
    public: virtual GEInt GetLetterWidth(GEUnicodeChar) const;
    public: virtual GEInt GetTextWidth(bCString const &) const = 0;
    public: virtual GEInt GetTextWidth(bCUnicodeString const &) const;
    public: virtual void Process();
    public: virtual void Render();
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    protected: void Destroy() override;
    protected: bEResult Create() override;
    public: ~eCFont() override;
    // clang-format on

  public:
    eCFont(eCFont const &);
    eCFont();

  public:
    eCFont &operator=(eCFont const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCFont const &);
    void CopyTo(eCFont &) const;

  protected:
    void Invalidate();

  private:
    bCUnicodeString m_Text;
    bCRect m_ClipRect;
    bCByteAlphaColor m_TextColor;
    bCByteAlphaColor m_BackgroundColor;
};

GE_ASSERT_SIZEOF(eCFont, 0x38)
