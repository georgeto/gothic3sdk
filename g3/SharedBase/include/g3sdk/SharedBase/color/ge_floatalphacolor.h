#pragma once

#include <SharedBase/color/ge_floatcolor.h>

class bCVector4;

class GE_DLLIMPORT bCFloatAlphaColor : public bCFloatColor
{
    // clang-format off
    public: void Clear() override;
    public: bCIStream & operator<<(bCIStream &) override;
    public: bCOStream & operator>>(bCOStream &) const override;
    // clang-format on

  public:
    bCFloatAlphaColor(bCFloatAlphaColor const &);
    explicit bCFloatAlphaColor(bCByteAlphaColor const &);
    bCFloatAlphaColor(bCByteColor const &, GEFloat);
    bCFloatAlphaColor(bCFloatColor const &, GEFloat);
    bCFloatAlphaColor(bCFloatColorHSV const &, GEFloat);
    explicit bCFloatAlphaColor(bCVector4 const &);
    bCFloatAlphaColor(GEFloat, GEFloat, GEFloat, GEFloat);
    explicit bCFloatAlphaColor(bCColorBase::bEColor);
    bCFloatAlphaColor();
    ~bCFloatAlphaColor();

  public:
    bCFloatAlphaColor &operator=(bCFloatAlphaColor const &);
    GEBool operator==(bCFloatAlphaColor const &) const;
    GEBool operator!=(bCFloatAlphaColor const &) const;
    bCFloatAlphaColor operator*(bCFloatAlphaColor const &) const;
    bCFloatAlphaColor operator*(GEFloat) const;
    bCFloatAlphaColor operator-(bCFloatAlphaColor const &) const;
    bCFloatAlphaColor operator-() const;
    bCFloatAlphaColor operator+(bCFloatAlphaColor const &) const;
    bCFloatAlphaColor operator/(GEFloat) const;
    bCFloatAlphaColor operator~() const;
    bCFloatAlphaColor &operator*=(bCFloatAlphaColor const &);
    bCFloatAlphaColor &operator*=(GEFloat);
    bCFloatAlphaColor &operator+=(bCFloatAlphaColor const &);
    bCFloatAlphaColor &operator-=(bCFloatAlphaColor const &);
    bCFloatAlphaColor &operator/=(GEFloat);

  public:
    GEFloat &AccessAlpha();
    void Add(bCFloatAlphaColor const &);
    void AddClamped(bCFloatAlphaColor const &);
    void Clamp();
    GEFloat GetAlpha() const;
    void GetAlpha(GEFloat &) const;
    bCFloatAlphaColor GetClamped() const;
    void GetClamped(bCFloatAlphaColor &) const;
    bCFloatAlphaColor GetDifference(bCFloatAlphaColor const &) const;
    void GetDifference(bCFloatAlphaColor &, bCFloatAlphaColor const &) const;
    bCFloatAlphaColor GetInverted() const;
    void GetInverted(bCFloatAlphaColor &) const;
    bCFloatAlphaColor GetNormalized() const;
    void GetNormalized(bCFloatAlphaColor &) const;
    bCFloatAlphaColor GetProduct(bCFloatAlphaColor const &) const;
    bCFloatAlphaColor GetProduct(GEFloat) const;
    void GetProduct(bCFloatAlphaColor &, bCFloatAlphaColor const &) const;
    void GetProduct(bCFloatAlphaColor &, GEFloat) const;
    bCFloatAlphaColor GetSum(bCFloatAlphaColor const &) const;
    void GetSum(bCFloatAlphaColor &, bCFloatAlphaColor const &) const;
    void Invert();
    GEBool IsEqual(bCFloatAlphaColor const &) const;
    void Multiply(bCFloatAlphaColor const &);
    void Multiply(GEFloat);
    void Normalize();
    void SetAlpha(GEFloat);
    void SetColor(bCFloatAlphaColor const &);
    void SetColor(bCByteAlphaColor const &);
    void SetColor(bCByteColor const &, GEFloat);
    void SetColor(bCFloatColor const &, GEFloat);
    void SetColor(bCFloatColorHSV const &, GEFloat);
    void SetColor(bCVector4 const &);
    void SetColor(GEFloat, GEFloat, GEFloat, GEFloat);
    void Sub(bCFloatAlphaColor const &);
    void SubClamped(bCFloatAlphaColor const &);

  public:
    GEFloat m_fAlpha;
};
