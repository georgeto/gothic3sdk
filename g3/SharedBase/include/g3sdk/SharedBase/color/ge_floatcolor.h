#pragma once

#include <SharedBase/color/ge_colorbase.h>
#include <SharedBase/types/ge_types.h>

class bCByteAlphaColor;
class bCByteColor;
class bCFloatAlphaColor;
class bCFloatColorHSV;

class GE_DLLIMPORT bCFloatColor : public bCColorBase
{
    // clang-format off
    public: void Clear() override;
    public: bCIStream & operator<<(bCIStream &) override;
    public: bCOStream & operator>>(bCOStream &) const override;
    // clang-format on

  public:
    bCFloatColor(bCFloatColor const &);
    explicit bCFloatColor(bCByteAlphaColor const &);
    explicit bCFloatColor(bCByteColor const &);
    explicit bCFloatColor(bCFloatAlphaColor const &);
    explicit bCFloatColor(bCFloatColorHSV const &);
    bCFloatColor(GEFloat, GEFloat, GEFloat);
    explicit bCFloatColor(bCColorBase::bEColor);
    bCFloatColor();
    ~bCFloatColor();

  public:
    bCFloatColor &operator=(bCFloatColor const &);
    GEBool operator==(bCFloatColor const &) const;
    GEBool operator!=(bCFloatColor const &) const;
    bCFloatColor operator*(bCFloatColor const &) const;
    bCFloatColor operator*(GEFloat) const;
    bCFloatColor operator-(bCFloatColor const &) const;
    bCFloatColor operator-() const;
    bCFloatColor operator+(bCFloatColor const &) const;
    bCFloatColor operator/(GEFloat) const;
    bCFloatColor operator~() const;
    bCFloatColor &operator*=(bCFloatColor const &);
    bCFloatColor &operator*=(GEFloat);
    bCFloatColor &operator+=(bCFloatColor const &);
    bCFloatColor &operator-=(bCFloatColor const &);
    bCFloatColor &operator/=(GEFloat);

  public:
    GEFloat &AccessBlue();
    GEFloat &AccessGreen();
    GEFloat &AccessRed();
    void Add(bCFloatColor const &);
    void AddClamped(bCFloatColor const &);
    void Clamp();
    GEFloat GetBlue() const;
    void GetBlue(GEFloat &) const;
    bCFloatColor GetClamped() const;
    void GetClamped(bCFloatColor &) const;
    bCFloatColor GetDifference(bCFloatColor const &) const;
    void GetDifference(bCFloatColor &, bCFloatColor const &) const;
    GEFloat GetGreen() const;
    void GetGreen(GEFloat &) const;
    bCFloatColor GetInverted() const;
    void GetInverted(bCFloatColor &) const;
    bCFloatColor GetNormalized() const;
    void GetNormalized(bCFloatColor &) const;
    bCFloatColor GetProduct(bCFloatColor const &) const;
    bCFloatColor GetProduct(GEFloat) const;
    void GetProduct(bCFloatColor &, bCFloatColor const &) const;
    void GetProduct(bCFloatColor &, GEFloat) const;
    GEFloat GetRed() const;
    void GetRed(GEFloat &) const;
    bCFloatColor GetSum(bCFloatColor const &) const;
    void GetSum(bCFloatColor &, bCFloatColor const &) const;
    void Invert();
    GEBool IsEqual(bCFloatColor const &) const;
    void Multiply(bCFloatColor const &);
    void Multiply(GEFloat);
    void Normalize();
    void SetBlue(GEFloat);
    void SetColor(bCFloatColor const &);
    void SetColor(bCByteAlphaColor const &);
    void SetColor(bCByteColor const &);
    void SetColor(bCFloatAlphaColor const &);
    void SetColor(bCFloatColorHSV const &);
    void SetColor(GEFloat, GEFloat, GEFloat);
    void SetGreen(GEFloat);
    void SetRed(GEFloat);
    void Sub(bCFloatColor const &);
    void SubClamped(bCFloatColor const &);

  private:
    GEFloat m_fRed;
    GEFloat m_fGreen;
    GEFloat m_fBlue;
};
