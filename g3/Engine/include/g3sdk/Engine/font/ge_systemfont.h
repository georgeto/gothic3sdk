#pragma once

#include <Engine/font/ge_font.h>
#include <Engine/ge_gfxshared.h>

#include <SharedBase.h>

class eCGfxFont;
class eCGfxImageData;

class GE_DLLIMPORT eCSystemFont : public eCFont
{
    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    protected: void Destroy() override;
    protected: bEResult Create() override;
    public: ~eCSystemFont() override;
    public: void SetText(bCString const &) override;
    public: void SetText(bCUnicodeString const &) override;
    public: void SetClipRect(bCRect const &) override;
    public: void SetTextColor(bCByteAlphaColor const &) override;
    public: void SetBackgroundColor(bCByteAlphaColor const &) override;
    public: void AddTextToRenderList() override;
    public: GEInt GetLetterHeight() const override;
    public: GEInt GetLetterWidth(GEChar) const override;
    public: GEInt GetLetterWidth(GEUnicodeChar) const override;
    public: GEInt GetTextWidth(bCString const &) const override;
    public: GEInt GetTextWidth(bCUnicodeString const &) const override;
    public: void Render() override;
    // clang-format on

  public:
    eCSystemFont(eCSystemFont const &);
    eCSystemFont();

  public:
    eCSystemFont &operator=(eCSystemFont const &);
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void CopyFrom(eCSystemFont const &);
    void CopyTo(eCSystemFont &) const;
    eCGfxShared::eSFontDesc const &GetDescriptor() const;
    void SetDescriptor(eCGfxShared::eSFontDesc const &);

  protected:
    eCGfxShared::eSFontDesc &AccessDescriptor();
    eCGfxFont &AccessFont();
    GEBool CacheIn();
    void DrawLetters();
    void Invalidate();
    void Update();

  private:
    GEBool GetLetterData(GEUInt, GEInt &, GEInt &, bCVector &, bCVector &, bCVector2 &, eCGfxImageData *&);
    GEInt GetLetterDistance() const;

  private:
    eCGfxFont *m_SubsystemFont;
    eCGfxShared::eSFontDesc m_FontDesc;
    GE_UNIMPL_MEMBERS(0x38)
    GEU32 field_A4;
    GEU32 field_A8;
    GEU32 field_AC;
    GEU32 field_B0;
    GEU32 field_B4;
    GEU32 m_LetterHeight;
    GEU32 m_LetterWidth;
    GEByte m_Flags;
    GE_PADDING(0x3)
};

GE_ASSERT_SIZEOF(eCSystemFont, 0xbc)
