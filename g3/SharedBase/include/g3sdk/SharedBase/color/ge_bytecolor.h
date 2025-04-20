#pragma once

#include <SharedBase/color/ge_colorbase.h>
#include <SharedBase/types/ge_types.h>

class bCByteAlphaColor;
class bCFloatAlphaColor;
class bCFloatColor;
class bCFloatColorHSV;

class GE_DLLIMPORT bCByteColor : public bCColorBase
{
    // clang-format off
    public: void Clear() override;
    public: bCIStream & operator<<(bCIStream &) override;
    public: bCOStream & operator>>(bCOStream &) const override;
    // clang-format on

  public:
    bCByteColor(bCByteColor const &);
    explicit bCByteColor(bCByteAlphaColor const &);
    explicit bCByteColor(bCFloatAlphaColor const &);
    explicit bCByteColor(bCFloatColor const &);
    explicit bCByteColor(bCFloatColorHSV const &);
    bCByteColor(GEU8, GEU8, GEU8);
    explicit bCByteColor(bCColorBase::bEColor);
    bCByteColor();
    ~bCByteColor();

  public:
    bCByteColor &operator=(bCByteColor const &);
    GEBool operator==(bCByteColor const &) const;
    GEBool operator!=(bCByteColor const &) const;
    bCByteColor operator*(bCByteColor const &) const;
    bCByteColor operator*(GEU8) const;
    bCByteColor operator-(bCByteColor const &) const;
    bCByteColor operator-() const;
    bCByteColor operator+(bCByteColor const &) const;
    bCByteColor operator/(GEU8) const;
    bCByteColor operator~() const;
    bCByteColor &operator*=(bCByteColor const &);
    bCByteColor &operator*=(GEU8);
    bCByteColor &operator+=(bCByteColor const &);
    bCByteColor &operator-=(bCByteColor const &);
    bCByteColor &operator/=(GEU8);

  public:
    GEU8 &AccessBlue();
    GEU8 &AccessGreen();
    GEU8 &AccessRed();
    void Add(bCByteColor const &);
    void AddClamped(bCByteColor const &);
    void Clamp();
    GEU8 GetBlue() const;
    void GetBlue(GEU8 &) const;
    bCByteColor GetClamped() const;
    void GetClamped(bCByteColor &) const;
    GEU16 GetColor_RGB_555() const;
    void GetColor_RGB_555(GEU16 &) const;
    GEU16 GetColor_RGB_565() const;
    void GetColor_RGB_565(GEU16 &) const;
    bCByteColor GetDifference(bCByteColor const &) const;
    void GetDifference(bCByteColor &, bCByteColor const &) const;
    GEU8 GetGreen() const;
    void GetGreen(GEU8 &) const;
    bCByteColor GetInverted() const;
    void GetInverted(bCByteColor &) const;
    bCByteColor GetProduct(bCByteColor const &) const;
    bCByteColor GetProduct(GEU8) const;
    void GetProduct(bCByteColor &, bCByteColor const &) const;
    void GetProduct(bCByteColor &, GEU8) const;
    GEU8 GetRed() const;
    void GetRed(GEU8 &) const;
    bCByteColor GetSum(bCByteColor const &) const;
    void GetSum(bCByteColor &, bCByteColor const &) const;
    void Invert();
    GEBool IsEqual(bCByteColor const &) const;
    void Multiply(bCByteColor const &);
    void Multiply(GEU8);
    void SetBlend(bCByteColor const &, bCByteColor const &, GEInt, GEInt);
    void SetBlue(GEU8);
    void SetColor(bCByteColor const &);
    void SetColor(bCByteAlphaColor const &);
    void SetColor(bCFloatAlphaColor const &);
    void SetColor(bCFloatColor const &);
    void SetColor(bCFloatColorHSV const &);
    void SetColor(GEU8, GEU8, GEU8);
    void SetColor_RGB_555(GEU16);
    void SetColor_RGB_565(GEU16);
    void SetGreen(GEU8);
    void SetRed(GEU8);
    void Sub(bCByteColor const &);
    void SubClamped(bCByteColor const &);

  private:
    GEU8 m_u8Red;
    GEU8 m_u8Green;
    GEU8 m_u8Blue;
    GE_PADDING(0x1)
};
