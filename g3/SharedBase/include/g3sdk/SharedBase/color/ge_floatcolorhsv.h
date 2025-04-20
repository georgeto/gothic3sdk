#pragma once

#include <SharedBase/color/ge_colorbase.h>
#include <SharedBase/types/ge_types.h>

class bCByteAlphaColor;
class bCByteColor;
class bCFloatAlphaColor;
class bCFloatColor;

class GE_DLLIMPORT bCFloatColorHSV : public bCColorBase
{
    // clang-format off
    public: void Clear() override;
    public: bCIStream & operator<<(bCIStream &) override;
    public: bCOStream & operator>>(bCOStream &) const override;
    // clang-format on

  public:
    bCFloatColorHSV(bCFloatColorHSV const &);
    explicit bCFloatColorHSV(bCByteAlphaColor const &);
    explicit bCFloatColorHSV(bCByteColor const &);
    explicit bCFloatColorHSV(bCFloatAlphaColor const &);
    explicit bCFloatColorHSV(bCFloatColor const &);
    bCFloatColorHSV(GEFloat, GEFloat, GEFloat);
    explicit bCFloatColorHSV(bCColorBase::bEColor);
    bCFloatColorHSV();
    ~bCFloatColorHSV();

  public:
    bCFloatColorHSV &operator=(bCFloatColorHSV const &);
    GEBool operator==(bCFloatColorHSV const &) const;
    GEBool operator!=(bCFloatColorHSV const &) const;
    bCFloatColorHSV operator*(bCFloatColorHSV const &) const;
    bCFloatColorHSV operator*(GEFloat) const;
    bCFloatColorHSV operator-(bCFloatColorHSV const &) const;
    bCFloatColorHSV operator-() const;
    bCFloatColorHSV operator+(bCFloatColorHSV const &) const;
    bCFloatColorHSV operator/(GEFloat) const;
    bCFloatColorHSV operator~() const;
    bCFloatColorHSV &operator*=(bCFloatColorHSV const &);
    bCFloatColorHSV &operator*=(GEFloat);
    bCFloatColorHSV &operator+=(bCFloatColorHSV const &);
    bCFloatColorHSV &operator-=(bCFloatColorHSV const &);
    bCFloatColorHSV &operator/=(GEFloat);

  public:
    GEFloat &AccessHue();
    GEFloat &AccessSaturation();
    void Add(bCFloatColorHSV const &);
    void AddClamped(bCFloatColorHSV const &);
    void Clamp();
    bCFloatColorHSV GetClamped() const;
    void GetClamped(bCFloatColorHSV &) const;
    bCFloatColorHSV GetDifference(bCFloatColorHSV const &) const;
    void GetDifference(bCFloatColorHSV &, bCFloatColorHSV const &) const;
    GEFloat GetHue() const;
    void GetHue(GEFloat &) const;
    bCFloatColorHSV GetInverted() const;
    void GetInverted(bCFloatColorHSV &) const;
    bCFloatColorHSV GetProduct(bCFloatColorHSV const &) const;
    bCFloatColorHSV GetProduct(GEFloat) const;
    void GetProduct(bCFloatColorHSV &, bCFloatColorHSV const &) const;
    void GetProduct(bCFloatColorHSV &, GEFloat) const;
    GEFloat GetSaturation() const;
    void GetSaturation(GEFloat &) const;
    bCFloatColorHSV GetSum(bCFloatColorHSV const &) const;
    void GetSum(bCFloatColorHSV &, bCFloatColorHSV const &) const;
    GEFloat &GetValue();
    GEFloat GetValue() const;
    void GetValue(GEFloat &) const;
    void Invert();
    GEBool IsEqual(bCFloatColorHSV const &) const;
    void Multiply(bCFloatColorHSV const &);
    void Multiply(GEFloat);
    void SetColor(bCFloatColorHSV const &);
    void SetColor(bCByteAlphaColor const &);
    void SetColor(bCByteColor const &);
    void SetColor(bCFloatAlphaColor const &);
    void SetColor(bCFloatColor const &);
    void SetColor(GEFloat, GEFloat, GEFloat);
    void SetHue(GEFloat);
    void SetSaturation(GEFloat);
    void SetValue(GEFloat);
    void Sub(bCFloatColorHSV const &);
    void SubClamped(bCFloatColorHSV const &);
};
