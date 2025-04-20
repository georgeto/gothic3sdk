#pragma once

#include <SharedBase/color/ge_bytecolor.h>

class GE_DLLIMPORT bCByteAlphaColor : public bCByteColor
{
    // clang-format off
    public: void Clear() override;
    public: bCIStream & operator<<(bCIStream &) override;
    public: bCOStream & operator>>(bCOStream &) const override;
    // clang-format on

  public:
    bCByteAlphaColor(bCByteAlphaColor const &);
    bCByteAlphaColor(bCByteColor const &, GEU8);
    explicit bCByteAlphaColor(bCFloatAlphaColor const &);
    bCByteAlphaColor(bCFloatColor const &, GEU8);
    bCByteAlphaColor(bCFloatColorHSV const &, GEU8);
    bCByteAlphaColor(GEU8, GEU8, GEU8, GEU8);
    explicit bCByteAlphaColor(bCColorBase::bEColor);
    bCByteAlphaColor();
    ~bCByteAlphaColor();

  public:
    bCByteAlphaColor &operator=(bCByteAlphaColor const &);
    GEBool operator==(bCByteAlphaColor const &) const;
    GEBool operator!=(bCByteAlphaColor const &) const;
    bCByteAlphaColor operator*(bCByteAlphaColor const &) const;
    bCByteAlphaColor operator*(GEU8) const;
    bCByteAlphaColor operator-(bCByteAlphaColor const &) const;
    bCByteAlphaColor operator-() const;
    bCByteAlphaColor operator+(bCByteAlphaColor const &) const;
    bCByteAlphaColor operator/(GEU8) const;
    bCByteAlphaColor operator~() const;
    bCByteAlphaColor &operator*=(bCByteAlphaColor const &);
    bCByteAlphaColor &operator*=(GEU8);
    bCByteAlphaColor &operator+=(bCByteAlphaColor const &);
    bCByteAlphaColor &operator-=(bCByteAlphaColor const &);
    bCByteAlphaColor &operator/=(GEU8);

  public:
    GEU8 &AccessAlpha();
    void Add(bCByteAlphaColor const &);
    void AddClamped(bCByteAlphaColor const &);
    void Clamp();
    GEU8 GetAlpha() const;
    void GetAlpha(GEU8 &) const;
    bCByteAlphaColor GetClamped() const;
    void GetClamped(bCByteAlphaColor &) const;
    GEU16 GetColor_ARGB_1555() const;
    void GetColor_ARGB_1555(GEU16 &) const;
    GEU32 GetColor_ARGB_8888() const;
    void GetColor_ARGB_8888(GEU32 &) const;
    GEU16 GetColor_RGBA_4444() const;
    void GetColor_RGBA_4444(GEU16 &) const;
    GEU32 GetColor_RGBA_8888() const;
    void GetColor_RGBA_8888(GEU32 &) const;
    bCByteColor GetColor_RGB_888() const;
    void GetColor_RGB_888(bCByteColor &) const;
    bCByteAlphaColor GetDifference(bCByteAlphaColor const &) const;
    void GetDifference(bCByteAlphaColor &, bCByteAlphaColor const &) const;
    bCByteAlphaColor GetInverted() const;
    void GetInverted(bCByteAlphaColor &) const;
    bCByteAlphaColor GetProduct(bCByteAlphaColor const &) const;
    bCByteAlphaColor GetProduct(GEU8) const;
    void GetProduct(bCByteAlphaColor &, bCByteAlphaColor const &) const;
    void GetProduct(bCByteAlphaColor &, GEU8) const;
    bCByteAlphaColor GetSum(bCByteAlphaColor const &) const;
    void GetSum(bCByteAlphaColor &, bCByteAlphaColor const &) const;
    void Invert();
    GEBool IsEqual(bCByteAlphaColor const &) const;
    void Multiply(bCByteAlphaColor const &);
    void Multiply(GEU8);
    void ReadPixel(bEPixelFormat, GELPCVoid);
    void SetAlpha(GEU8);
    void SetColor(bCByteAlphaColor const &);
    void SetColor(bCByteColor const &, GEU8);
    void SetColor(bCFloatAlphaColor const &);
    void SetColor(bCFloatColor const &, GEU8);
    void SetColor(bCFloatColorHSV const &, GEU8);
    void SetColor(GEU8, GEU8, GEU8, GEU8);
    void SetColor_ARGB_1555(GEU16);
    void SetColor_ARGB_8888(GEU32);
    void SetColor_RGBA_4444(GEU16);
    void SetColor_RGBA_8888(GEU32);
    void SetColor_RGB_555(GEU16);
    void SetColor_RGB_565(GEU16);
    void SetColor_RGB_888(bCByteColor const &);
    void Sub(bCByteAlphaColor const &);
    void SubClamped(bCByteAlphaColor const &);
    void WritePixel(bEPixelFormat, GELPVoid);

  private:
    GEU8 m_u8Alpha;
    GE_PADDING(0x3)
};
